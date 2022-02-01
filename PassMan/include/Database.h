//
// Created by KSZ on 2022-01-28.
//

#ifndef JIPP2_DATABASE_H
#define JIPP2_DATABASE_H
#include "DbCrypto.h"
#include "PasswordGenerator.h"

class Database : public DbCrypto, public PasswordGenerator {
private:
    std::string dbName;
    bool opened;
public:
    Database(const std::string &dbName, bool opened);
    Database();

    /**
     * This method is responsible for adding a record to the database.
     */
    void addRecord();

    /**
     * Tell the database that it's encrypted or not.
     * @param val - this is the value that indicates if the database is opened or not.
     *              Database is opened if val is true.
     */
    void setOpened(bool val);

    /**
     * It prints the whole opened database or specific record
     */
    void print();

    /**
     * It prints specific record from the database
     * @param recordNumber - number of the record in the database
     */
    void print(int recordNumber);

    /**
     * It prints one record from the database with masked password
     * @param line - record from the database but with plain password
     * @param recordNumber - number of the printed record in the database
     */
    void printMaskedRecord(const std::string &line, size_t recordNumber);

    /**
     * This method is used for splitting the line into columns
     * @param line - string to split
     * @param columnNumber - the number of column of the string
     * @return - string from the specified column
     */
    std::string splitLine(std::string line, int columnNumber);

    /**
     * Masking password with asterisks.
     * @param password - password in plaintext
     */
    void maskPassword(std::string& password);

    /**
     * Removes specified record from the database
     * @param recordNumber - number of record to be removed
     */
    void removeRecord(int recordNumber);
};


#endif //JIPP2_DATABASE_H
