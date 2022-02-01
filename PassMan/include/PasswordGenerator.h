//
// Created by KSZ on 2022-01-31.
//

#ifndef JIPP2_PASSWORDGENERATOR_H
#define JIPP2_PASSWORDGENERATOR_H
#include <iostream>
#include <random>

class PasswordGenerator {
private:
    int lenOfPassword;
    std::string password;
    std::string charset = R"(0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~)";
    unsigned long long charsetSize = charset.size();
public:
    /**
     * This method generates a strong password with the specified length.
     * @return - true if password is generated, false otherwise
     */
    bool generatePassword();


    /**
     * This method clears the generated password
     */
    void clearPassword();

    /**
     * This setter is responsible for setting the length of the password to generate
     * @param passLen - length of the password to be generated
     */
    void setPasswordLen(int passLen);

    /**
     * This getter returns generated password
     */
    const std::string &getPassword();
};


#endif //JIPP2_PASSWORDGENERATOR_H
