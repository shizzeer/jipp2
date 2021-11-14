//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "struktury.h"

int main()
{
    samochod samochody[5] = { {"Ford", "GT", 2005, "czerwony"},
                             {"Toyota", "Supra", 1999, "czarny"},
                             {"Dodge", "Charger", 1970, "czarny"},
                             {"Bugatti", "Chiron", 2015, "granatowy"}};
    zadanie1(samochody, 4);
    zadanie2(samochody);
    return 0;
}

