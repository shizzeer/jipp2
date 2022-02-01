//
// Created by KSZ on 2022-01-31.
//

#include "PasswordGenerator.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#define STRONG_PASSWORD_MIN_LEN 12

bool PasswordGenerator::generatePassword()
{

    if (lenOfPassword < STRONG_PASSWORD_MIN_LEN) {
        std::cout << "Password length should be equal to 12 or more characters in order to generate secure password\n";
        return false;
    }
    else {
        for (int i = 0; i < lenOfPassword; i++)
            password += charset[rand() % charset.size()];
        return true;
    }
}

void PasswordGenerator::clearPassword()
{
    password = "";
}

void PasswordGenerator::setPasswordLen(int passLen)
{
    lenOfPassword = passLen;
}

const std::string& PasswordGenerator::getPassword()
{
    return password;
}