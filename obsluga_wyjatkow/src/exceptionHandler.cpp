//
// Created by Kamil on 20.10.2021.
//

#include <iostream>
#include <string>

void division(unsigned int a, unsigned int b)
{
    unsigned int res;
    try {
        if (b == 0)
            throw "Dzielenie przez zero nie moze byc przeprowadzone!";
        res = a / b;
        std::cout << "Wynik: " << res << '\n';
    }
    catch (const char* msg) {
        std::cout << msg << '\n';
    }
}

void convertToInt(std::string data)
{
    try {
        int converted = std::stoi(data);
        std::cout << converted << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}