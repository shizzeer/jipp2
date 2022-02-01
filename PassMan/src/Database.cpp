//
// Created by KSZ on 2022-01-28.
//

#include "Database.h"
#include <fstream>

#define DELIM "\t\t"
#define URL_COLUMN_NUMBER 0
#define USERNAME_COLUMN_NUMBER 1
#define PASSWORD_COLUMN_NUMBER 2

Database::Database(const std::string &dbName, bool opened)
{
    this->dbName = dbName;
    this->opened = opened;
   // this->key = key;
}

Database::Database()
{}

void Database::setOpened(bool val)
{
    opened = val;
}

void Database::addRecord()
{
    std::string url, username;
    int passLen;

    if (opened) {
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Username: ";
        std::getline(std::cin, username);
        std::cout << "Length of password to be generated: ";
        std::cin >> passLen;
        PasswordGenerator passwordGenerator;
        passwordGenerator.setPasswordLen(passLen);
        if (!passwordGenerator.generatePassword()) {
            std::cout << "Error: Password is not generated\n";
            return;
        }

        std::ofstream dbFile;
        std::string dbFilename = dbName + ".pmdb";
        dbFile.open(dbFilename, std::ios::out | std::ios::app);
        if (!dbFile) {
            std::cout << "Can not open or create file for database\n";
            return;
        }
        dbFile << url << "\t\t" << username << "\t\t" << passwordGenerator.getPassword() << '\n';
        std::cout << "Your database has been updated\n";
        passwordGenerator.clearPassword();
        dbFile.close();
    }
    else {
        std::cout << "There is no opened database and you can't add record to encrypted database.\n";
    }
}

std::string Database::splitLine(std::string line, int columnNumber)
{
    size_t start = 0, end = 0;
    size_t columnCounter = 0;
    std::string token, delim = "\t\t";
    while ((start = line.find_first_not_of(delim, end)) != std::string::npos) {
        end = line.find(delim, start);
        if (columnNumber == columnCounter)
            return line.substr(start, end - start);
        columnCounter++;
    }
}

void Database::maskPassword(std::string& password)
{
    for (char & passwordChar : password)
        passwordChar = '*';
}

void Database::printMaskedRecord(const std::string &line, size_t recordNumber)
{
    std::string url, username, password;
    url = splitLine(line, URL_COLUMN_NUMBER);
    username = splitLine(line, USERNAME_COLUMN_NUMBER);
    password = splitLine(line, PASSWORD_COLUMN_NUMBER);
    maskPassword(password);
    std::cout << recordNumber << ". " << url << DELIM << username << DELIM << password << '\n';
}

void Database::print()
{
    std::ifstream dbFile;
    std::string dbFilename = dbName + ".pmdb";
    dbFile.open(dbFilename, std::ios::in);
    if (!dbFile) {
        std::cout << "Can not open database file\n";
        return;
    }
    std::string line, url, username, password;
    size_t recordNumber = 1;
    while (std::getline(dbFile, line)) {
        printMaskedRecord(line, recordNumber);
        recordNumber++;
    }
    dbFile.close();
}

void Database::print(int recordNumber)
{
    if (recordNumber <= 0) {
        std::cout << "Record number has to be positive\n";
        return;
    }
    std::ifstream dbFile;
    std::string dbFilename = dbName + ".pmdb";
    dbFile.open(dbFilename, std::ios::in);
    if (!dbFile) {
        std::cout << "Can not open database file\n";
        return;
    }
    std::string line, url, username, password;
    int recordCounter = 1;
    while (std::getline(dbFile, line)) {
        if (recordCounter == recordNumber) {
            printMaskedRecord(line, recordCounter);
            return;
        }
        recordCounter++;
    }
    std::cout << "There is no record with specified number\n"
                 "Records are numbered from 1 to number of records in database\n";
    dbFile.close();
}

void Database::removeRecord(int recordNumber)
{
    std::ifstream dbFile;
    std::string dbFilename = dbName + ".pmdb";
    dbFile.open(dbFilename, std::ios::in);
    if (!dbFile) {
        std::cout << "Can not open database file\n";
        return;
    }
    std::vector<std::string> dbFileContent;
    std::string record;
    int recordCounter = 1;
    while (std::getline(dbFile, record)) {
        if (recordCounter != recordNumber)
            dbFileContent.push_back(record);
        recordCounter++;
    }
    dbFile.close();

    std::ofstream dbFileNewContent;
    dbFileNewContent.open(dbFilename, std::ios::out | std::ios::trunc);
    if (!dbFileNewContent) {
        std::cout << "Can not open database file\n";
        return;
    }
    for (auto & dbRecord : dbFileContent)
        dbFileNewContent << dbRecord << '\n';
    dbFileNewContent.close();

    std::cout << "Specified record has been removed\n";
}