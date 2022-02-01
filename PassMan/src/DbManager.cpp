//
// Created by KSZ on 2022-01-27.
//

#include "DbManager.h"
#include "Database.h"
#include "main.h"
#include <fstream>
#include <cstring>
#include <vector>

#ifdef _WIN32
    #include <io.h>
    #define access    _access_s
#else
    #include <unistd.h>
#endif

#define DELIM "\t\t"

void DbManager::dbCreate()
{
    std::string name, password;
    std::cout << "Set the name for the database: ";
    std::cin >> name;
    if (checkIfDbFileExists(name)) {
        std::cout << "Database with this name already exists\n";
        return;
    }
    std::cout << "Set the password for the database: ";
    password = getMaskedPassword();

    if (!name.empty()) {
        auto *db = new Database(name, false);
        dbList[name] = db;
        if (checkIfDbEntryExists(name)) {
            /* At least one entry in masters db exist but file does not.
            * Therefore, the program has to remove all redundant entries */
            correctMastersDbEntries(name);
        }
        if (!db->addPasswordHash(name, password)) {
            std::cout << "Could not create the database.\n";
            return;
        }
        /* Creating an empty file */
        std::string filename = name + ".pmdb";
        std::ofstream dbFile (filename);
        dbFile.close();
        std::cout << "Your database has been created";
    }
    else {
        std::cout << "You can not create database with an empty name\n";
    }
}

void DbManager::correctMastersDbEntries(const std::string &databaseName)
{
    std::vector<std::string> mastersDbContent;
    std::ifstream mastersDb;
    mastersDb.open("masters.pmdb", std::ios::in);
    std::string line, name;
    while (std::getline(mastersDb, line)) {
        name = line.substr(0, line.find(DELIM));
        if (name != databaseName) {
            mastersDbContent.push_back(line);
        }
    }
    mastersDb.close();
    std::ofstream mastersDbOut;
    mastersDbOut.open("masters.pmdb", std::ios::out | std::ios::trunc);
    for (auto & record : mastersDbContent)
        mastersDbOut << record << '\n';
    mastersDbOut.close();
}

bool DbManager::checkIfDbEntryExists(const std::string &nameToFind)
{
    std::ifstream mastersDb;
    mastersDb.open("masters.pmdb", std::ios::in);
    std::string line;
    std::string name;
    while (std::getline(mastersDb, line)) {
        name = line.substr(0, line.find(DELIM));
        if (name == nameToFind) {
            mastersDb.close();
            return true;
        }
    }
    mastersDb.close();
    return false;
}

bool DbManager::checkIfDbFileExists(const std::string &filenameToFind)
{
    const std::string &filename = filenameToFind + ".pmdb";
    return access(filename.c_str(), 0) == 0;
}

bool DbManager::verifyPassword(const std::string &name, const std::string &password)
{
    std::string passwordHash;
    passwordHash = getHashOfPassword(password);

    std::ifstream mastersDb;
    mastersDb.open("masters.pmdb", std::ios::in);
    if (!mastersDb) {
        std::cout << "Masters database doesn't exist!";
        return false;
    }


    std::string line, candidate, dbFilename;
    const std::string delim = "\t\t";
    while (std::getline(mastersDb, line)) {
        try {
            dbFilename = line.substr(0, line.find(delim));
            candidate = line.substr(line.find(delim) + delim.size(), line.size() - 1);
        } catch (const std::exception& e) {
            continue;
        }
        if (dbFilename == name && candidate == passwordHash) {
            mastersDb.close();
            return true;
        }
    }
    mastersDb.close();
    return false;
}

void DbManager::dbOpen(Database** db)
{
    if (isDbOpened) {
        std::cout << "You already have one database opened. Close it before using another database.";
        return;
    }
    std::string name, password;

    std::cout << "Name of the database: ";
    std::cin >> name;
    if (!checkIfDbFileExists(name)) {
        std::cout << name << " database doesn't exist\n";
        return;
    }

    std::cout << "Password: ";
    password = getMaskedPassword();
    if (!verifyPassword(name, password)) {
        std::cout << "Incorrect password\n";
        return;
    }

    isDbOpened = true;
    deriveEncKeyFromPassword(password);

    /* =======================DECRYPTING======================= */
    if (!dbDecrypt(name)) {
        std::cout << "Database isn't opened.\n";
        memset(key, 0, AES_KEY_LEN);
        memset(iv, 0, AES_IV_LEN);
        return;
    }

    for (auto & usedDatabase : dbList) {
        if (usedDatabase.first == name) {
            *db = usedDatabase.second;
            (*db)->setOpened(true);
        }
    }
    if (*db == nullptr) {
        *db = new Database(name, true);
        dbList[name] = *db;
    }
    openedDbName = name;

    std::cout << name << " database is now opened. You should close it after work.\n";
    getchar();
}

bool DbManager::checkIfDbOpened(const std::string &name)
{
    if (name == openedDbName)
        return true;
    return false;
}

void DbManager::listDatabases()
{
    std::ifstream mastersDb;
    mastersDb.open("masters.pmdb", std::ios::in);

    std::string line;
    std::string name;
    std::string filename;
    while (std::getline(mastersDb, line)) {
        name = line.substr(0, line.find(DELIM));
        if (name.empty() || !checkIfDbFileExists(name))
            continue;
        else if (name == openedDbName)
            std::cout << name << " [OPENED]\n";
        else
            std::cout << name << '\n';
    }

    mastersDb.close();
}


void DbManager::dbClose()
{
    if (!dbEncrypt(openedDbName)) {
        std::cout << "Error while encryption!\n";
        return;
    }
    isDbOpened = false;
    openedDbName = "";
    memset(key, 0, AES_KEY_LEN);
    memset(iv, 0, AES_IV_LEN);
    std::cout << "Database has been closed\n";
}

void DbManager::dbRemove()
{
    std::string name;
    std::cout << "Which database do you want to remove: ";
    std::cin >> name;
    if (!checkIfDbFileExists(name)) {
        std::cout << "The specified database doesn't exist\n";
        return;
    }
    std::string dbFile = name + ".pmdb";
    std::remove(dbFile.c_str());
    correctMastersDbEntries(name);
    std::cout << "The specified database has been removed\n";
}

DbManager::~DbManager()
{
    for (auto & dbEntry : dbList)
        delete dbEntry.second;
}
