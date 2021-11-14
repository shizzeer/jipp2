//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "FunkcjaKwadratowa.h"

FunkcjaKwadratowa::FunkcjaKwadratowa(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void FunkcjaKwadratowa::wyswietl()
{
    std::cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << '\n';
}
