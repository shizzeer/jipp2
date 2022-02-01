//
// Created by KSZ on 2022-01-27.
//

#include <iostream>
#include "main.h"
#include "DbManager.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <cstring>


void printHelp() {
    std::cout << "\nGENERAL COMMANDS\n";
    std::cout << "\nCreate new database -> create\n";
    std::cout << "Open database -> open\n";
    std::cout << "Remove database -> rmdb\n";
    std::cout << "List databases and check which is opened -> ls\n";
    std::cout << "Close database -> close\n";
    std::cout << "Exit -> exit\n\n";
    std::cout << "\nDATABASE COMMANDS\n";
    std::cout << "\nAdd a record to the opened database -> add\n";
    std::cout << "Remove a record from the opened database -> rm\n";
    std::cout << "Print database or specific record -> print\n";
    std::cout << "\nHOW TO ACCESS DATABASES\n";
    std::cout << "\nWhen you want to get a password, you have to open the database using"
                 " a terminal and then open the database\nfile directly. After copying your"
                 " credentials you have to close the database directly and with close command"
                 "\ninside a terminal.\n";
}

/**
 * It reads a databases record number from the user
 * @return - database record identifier
 */
template <typename T>
T getRecordNumber()
{
    T recordNumber;
    std::cout << "Record number: ";
    std::cin >> recordNumber;
    if (std::cin.fail()) {
        std::cout << "Record number has to be positive\n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        return -1;
    }
    else if (recordNumber <= 0) {
        std::cout << "Record number has to be positive\n";
        return -1;
    }
    return recordNumber;
}

#define BACKSPACE 8

// Function that accepts the password
std::string getMaskedPassword()
{
    // Stores the password
    std::string password = "";
    char passwordChar;

    // Until condition is true
    while (true) {
        passwordChar = getch();
        if (passwordChar == '\r') {
            std::cout << std::endl;
            return password;
        }
        else if (passwordChar == BACKSPACE && password.length() != 0) {
            password.pop_back();
            // This will erase previously printed character
            std::cout << "\b \b";
            continue;
        }
        // Backspace cannot be printed as the first character
        else if (passwordChar == BACKSPACE && password.length() == 0) {
            continue;
        }
        password.push_back(passwordChar);
        std::cout << '*';
    }
}

int main(int argc, char* argv[])
{
    std::cout << "\n"
                 "    ____                  __  ___          \n"
                 "   / __ \\____ ___________/  |/  /___ _____ \n"
                 "  / /_/ / __ `/ ___/ ___/ /|_/ / __ `/ __ \\\n"
                 " / ____/ /_/ (__  |__  ) /  / / /_/ / / / /\n"
                 "/_/    \\__,_/____/____/_/  /_/\\__,_/_/ /_/ \n"
                 "                                           \n";
    std::cout << "\nREMEMBER: Always use exit command when you want to close the program!\n"
                 "Otherwise, if you don't close your passwords databases using close command"
                 " those databases will be decrypted!!\n";

    if (argc >= 2) {
        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
            printHelp();
            return 0;
        }
    }
    std::string cmd;

    DbManager dbManager;
    DbCrypto dbCrypto;
    Database* db = nullptr;
    srand(time(nullptr));

    int recordNumber = 0;

    while(true) {
        std::cout << "\nPM> ";
        std::getline(std::cin, cmd);

        if (cmd == "create") {
           dbManager.dbCreate();
           getchar();
        }
        else if (cmd == "open") {
            dbManager.dbOpen(&db);
        }
        else if (cmd == "close") {
            if (db != nullptr) {
                dbManager.dbClose();
                db->setOpened(false);
                db = nullptr;
            }
        }
        else if (cmd == "add") {
            if (db != nullptr)
                db->addRecord();
            else
                std::cout << "You have to open a database when you want to modify it.\n";
        }
        else if (cmd == "print") {
            if (db == nullptr) {
                std::cout << "You have to open a database when you want to print it.\n";
                continue;
            }
            std::string decision = "N";
            std::cout << "Print record (Y/N): ";
            std::cin >> decision;
            if (decision == "y" || decision == "Y") {
                recordNumber = getRecordNumber<int>();
                if (recordNumber < 0)
                    continue;
                db->print(recordNumber);
            }
            else
                db->print();
            getchar();
        }
        else if (cmd == "rmdb") {
            dbManager.dbRemove();
        }
        else if (cmd == "rm") {
            if (db == nullptr) {
                std::cout << "You have to open a database when you want to remove a record.\n";
                continue;
            }
            recordNumber = getRecordNumber<int>();
            if (recordNumber == -1)
                continue;
            db->removeRecord(recordNumber);
        }
        else if (cmd == "ls") {
            dbManager.listDatabases();
        }
        else if (cmd == "exit") {
            if (db != nullptr)
                dbManager.dbClose();
            std::cout << "Exiting...";
            break;
        }
        else if (cmd.empty()) {
            continue;
        }
        else {
            printHelp();
        }
    }
}
