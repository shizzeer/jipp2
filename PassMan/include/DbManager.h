//
// Created by KSZ on 2022-01-27.
//

#ifndef JIPP2_DBMANAGER_H
#define JIPP2_DBMANAGER_H
#include "Database.h"
#include "DbCrypto.h"
#include <vector>
#include <unordered_map>

class DbManager : public DbCrypto {
private:
    std::unordered_map<std::string, Database*> dbList;
    bool isDbOpened = false;
    std::string openedDbName;
public:
    /**
     * This function creates the database object and updates master database file.
     */
    void dbCreate();
    /**
     * Passwords database opening.
     * @param db - pointer to the database pointer in order to get access to the database from outside
     *             the dbManager object.
     */
    void dbOpen(Database** db);

    /**
     *
     * @param name - name of the database to be checked
     * @return - true if a database is opened, false if not.
     */
    bool checkIfDbOpened(const std::string &name);

    /**
     * Checks if database file exists
     * @param filenameToFind - the name of the database to be found
     * @return - true if a database exists, false otherwise.
     */
    bool checkIfDbFileExists(const std::string &filenameToFind);

    /**
     * This method is responsible for database entry correctness.
     * @param name - the name of the database for which entry has to be corrected
     */
    void correctMastersDbEntries(const std::string &name);

    /**
     * Checks if there is entry for the searched in the masters database.
     * @param name - the name of the database to be checked
     * @return - true if entry exists, false if not
     */
    bool checkIfDbEntryExists(const std::string &nameToFind);

    /**
     * Verifies master password to the database.
     * @param name - name of the checked database.
     * @param password - password to the database to be checked.
     * @return - true if a password is valid, false otherwise.
     */
    bool verifyPassword(const std::string &name, const std::string &password);

    /**
     * Lists password databases. This function also show which database is opened at the moment
     */
    void listDatabases();

    /**
     * Closing passwords database.
     */
    void dbClose();

    /**
     * Removing passwords database.
     */
    void dbRemove();

    ~DbManager();
};


#endif //JIPP2_DBMANAGER_H
