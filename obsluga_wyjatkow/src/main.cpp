//
// Created by Kamil on 20.10.2021.
//

#include <iostream>
#include "exceptionHandler.h"

void zadanie1()
{
    std::cout << "=============ZADANIE 1==============\n";
    unsigned int a, b;
    std::cout << "Podaj liczbe a: ";
    std::cin >> a;
    std::cout << "Podaj liczbe b: ";
    std::cin >> b;
    division(a, b);
}

void zadanie2()
{
    std::cout << "=============ZADANIE 2==============\n";
    std::string data;
    std::cout << "Podaj liczbe do skonwertowania: ";
    std::cin >> data;
    convertToInt(data);
}

int main()
{
    /* Zadanie, w ktorym dzielimy dwie liczby naturalne podane przez uzytkownika.
     * W przypadku wystapienia bledu, generowany i obslugiwany jest wyjatek. */
    zadanie1();
    /* Zadanie, w ktorym konwertowany jest ciag znakow na liczbe typu int */
    zadanie2();
}