//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "PrzykladDesktruktor.h"

PrzykladDesktruktor::PrzykladDesktruktor()
{
    std::cout << "Konstruktor wywolany\n";
    tab = new char[1024];
    std::cout << "Tablica zaalokowana\n";
}

void PrzykladDesktruktor::pause()
{
    char c;
    std::cout << "Wpisz znak aby kontynuowac\n";
    std::cin >> c;
}

PrzykladDesktruktor::~PrzykladDesktruktor()
{
    delete[] tab;
    std::cout << "Praca destruktora zostala zakonczona\n";
}