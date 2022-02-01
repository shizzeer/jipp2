//
// Created by KSZ on 2022-01-27.
//

#ifndef JIPP2_DBCRYPTO_H
#define JIPP2_DBCRYPTO_H
#include <iostream>
#include <stdio.h>

#define AES_KEY_LEN 32
#define AES_IV_LEN 16

class DbCrypto {
protected:
    unsigned char key[AES_KEY_LEN];
    unsigned char iv[AES_IV_LEN];
public:
    /**
     * This method creates a hash of the key and saves it into a database.
     * @param dbName - The user\'s database name.
     * @param k - The master key in plaintext. It's the password previously set by a user.
     * @return - true if password hash was added to the database file, false otherwise
     */
    bool addPasswordHash(const std::string& dbName, std::string &password);

    /**
     * This method hashes the plaintext password with the SHA-256 algorithm.
     * @param k - Password in plaintext. It's the password previously set by a user.
     * @return - returns SHA-256 hash of the password
     */
    std::string getHashOfPassword(const std::string &password);

    /**
     * This method operates on plaintext password and derives an encryption key from it.
     * @param password - password to the database
     * @return - true if a proper key is derived, false otherwise
     */
    bool deriveEncKeyFromPassword(const std::string &password);

    /**
     * This method encrypts passwords database with AES algorithm in CBC mode. It uses 256-bit key.
     * @param dbName - it's a name of the database to encrypt
     * @return - true if encryption process succeeded, false if not
     */
    bool dbEncrypt(std::string dbName);

    /**
     * This method calculates size of a database file.
     * @param dbFile - it's a FILE* to a database file.
     * @return - it returns size of a database file or 0 in case of an internal error
     */
    int getDbFileSize(FILE* dbFile);

    /**
     * This method decrypts passwords database with AES algorithm in CBC mode. It uses 256-bit key.
     * @param dbName - it's a name of the database to decrypt
     * @return - true if decryption process succeeded, false if not
     */
    bool dbDecrypt(std::string dbName);
};


#endif //JIPP2_DBCRYPTO_H
