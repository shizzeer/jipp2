//
// Created by KSZ on 2022-01-27.
//

#include "DbCrypto.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "sha.h"
#include "evp.h"
#include "ossl_typ.h"
#include <vector>

# define AES_BLOCK_SIZE 16


std::string DbCrypto::getHashOfPassword(const std::string &password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    /* At this moment we have a password hashed inside the hash buffer */
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool DbCrypto::addPasswordHash(const std::string &dbName, std::string &password)
{
    std::ofstream mastersDb;
    std::string passwordHash;
    mastersDb.open("masters.pmdb", std::ios::out | std::ios::app);
    if (!mastersDb) {
        std::cout << "Could not create the masters database\n";
        return false;
    }
    passwordHash = getHashOfPassword(password);
    mastersDb << dbName << "\t\t" << passwordHash << '\n';
    mastersDb.close();
    return true;
}

bool DbCrypto::deriveEncKeyFromPassword(const std::string &password)
{

    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    int iklen = EVP_CIPHER_key_length(cipher);
    int ivlen = EVP_CIPHER_iv_length(cipher);
    int iter = 10000;
    unsigned char keyivpair[iklen + ivlen];

    // Generate the actual key IV pair
    if(!PKCS5_PBKDF2_HMAC(password.c_str(), -1, nullptr, 0, iter, EVP_sha256(), iklen + ivlen, keyivpair)) {
        std::cout << "Error while deriving the key.\n";
        return false;
    }

    memcpy(key, keyivpair, iklen);
    memcpy(iv, keyivpair + iklen, ivlen);

    return true;
}

int DbCrypto::getDbFileSize(FILE* dbFile)
{
    int size;
    fseek(dbFile, 0, SEEK_END);
    size = ftell(dbFile);
    fseek(dbFile, 0, SEEK_SET);
    if (size != -1)
        return size;
    return 0;
}

bool DbCrypto::dbEncrypt(std::string dbName)
{
    EVP_CIPHER_CTX encryptionCtx;

    EVP_CIPHER_CTX_init(&encryptionCtx);
    /* Set the cipher context to the encryption mode */
    EVP_EncryptInit_ex(&encryptionCtx, EVP_aes_256_cbc(), nullptr, key, iv);

    std::string filename = dbName + ".pmdb";
    /* Using C-like file operations because of OpenSSL constraints */
    FILE* dbFile = fopen(filename.c_str(), "rb");
    if (dbFile == nullptr) {
        std::cout << "Could not open database file while encrypting!\n";
        return false;
    }

    int dbFileSize = getDbFileSize(dbFile);
    if (dbFileSize < 0) {
        std::cout << "Error while calculating size of the database\n";
        return false;
    }
    else if (dbFileSize == 0) {
        return true;
    }

    unsigned char* plaintext = new unsigned char[dbFileSize];
    /* Maximum length of cipher text is n + AES_BLOCK_SIZE where n is the length of plaintext */
    int ciphertextLen = dbFileSize + AES_BLOCK_SIZE;
    int remainingLen = 0;
    unsigned char* ciphertext = new unsigned char[ciphertextLen];

    fread(plaintext, 1, dbFileSize, dbFile);
    fclose(dbFile);

    /* File is ready to be encrypted */
    /* ciphertext buffer is filled with encrypted plaintext */
    /* ciphertext_len is filled with the length of ciphertext generated */
    EVP_EncryptUpdate(&encryptionCtx, ciphertext, &ciphertextLen, plaintext, dbFileSize);

    /* update ciphertext with the final remaining bytes */
    EVP_EncryptFinal_ex(&encryptionCtx, ciphertext + ciphertextLen, &remainingLen);

    ciphertextLen = ciphertextLen + remainingLen;

    /* Ciphertext is written to the database file */
    FILE* dbFileEnc = fopen(filename.c_str(), "wb");
    if (dbFileEnc == nullptr) {
        std::cout << "Could not open database file while encrypting!\n";
        return false;
    }
    fwrite(ciphertext, 1, ciphertextLen, dbFileEnc);
    fclose(dbFileEnc);

    delete[] plaintext;
    delete[] ciphertext;
    return true;
}

bool DbCrypto::dbDecrypt(std::string dbName)
{
    std::string filename = dbName + ".pmdb";
    FILE* dbFile = fopen(filename.c_str(), "rb");
    if (dbFile == nullptr) {
        std::cout << "Could not open database file while decrypting!\n";
        return false;
    }

    /* Database is encrypted at this point so the program calculates the length of ciphertext */
    int ciphertextLen = getDbFileSize(dbFile);
    if (ciphertextLen < 0) {
        std::cout << "Error while calculating size of the database\n";
        return false;
    }
    else if (ciphertextLen == 0) {
        return true; /* Database is newly created so decryption is useless */
    }

    /* Plaintext length is always equal or lesser than ciphertext length */
    int plaintextLen = ciphertextLen;
    int remainingLen = 0;
    unsigned char* ciphertext = new unsigned char[ciphertextLen];
    unsigned char* plaintext = new unsigned char[plaintextLen];

    fread(ciphertext, 1, ciphertextLen, dbFile);
    fclose(dbFile);

    EVP_CIPHER_CTX decryptionCtx;
    EVP_CIPHER_CTX_init(&decryptionCtx);

    EVP_DecryptInit_ex(&decryptionCtx, EVP_aes_256_cbc(), nullptr, key, iv);
    EVP_DecryptUpdate(&decryptionCtx, plaintext, &plaintextLen, ciphertext, ciphertextLen);
    EVP_DecryptFinal_ex(&decryptionCtx, plaintext + plaintextLen, &remainingLen);

    /* AES sometimes leaves remaining bytes of data to be properly alignment.
     * That's why I had to call EVP_DecryptFinal_ex. remainingLen is the length of that
     * remaining bytes left by AES. Therefore, final length of a plaintext has to be increased
     * by remainingLen. */
    plaintextLen = plaintextLen + remainingLen;

    FILE* dbFileDec = fopen(filename.c_str(), "wb");
    if (dbFileDec == nullptr) {
        std::cout << "Error while opening database file while decrypting!\n";
        return false;
    }
    fwrite(plaintext, 1, plaintextLen, dbFileDec);
    fclose(dbFileDec);

    delete[] ciphertext;
    delete[] plaintext;
    return true;
}
