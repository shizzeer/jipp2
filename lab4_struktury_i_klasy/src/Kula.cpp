//
// Created by KSZ on 2021-11-14.
//

#include "Kula.h"

Kula::Kula(double r)
{
    this->r = r;
}

double Kula::obliczObjetosc()
{
    return 4.0/3 * 3.14 * (r * r * r);
}