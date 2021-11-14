//
// Created by KSZ on 2021-11-14.
//

#include "Prostopadloscian.h"

Prostopadloscian::Prostopadloscian(double a, double b, double h)
{
    this->a = a;
    this->b = b;
    this->h = h;
}

double Prostopadloscian::obliczPole()
{
    double polePodstawy = a * b;
    double polePowierzchniBocznej = 2 * a * h + 2 * b * h;
    return 2 * polePodstawy + polePowierzchniBocznej;
}
