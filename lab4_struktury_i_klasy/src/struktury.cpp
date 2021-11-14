//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "struktury.h"

void zadanie1(struct samochod samochody[], size_t n)
{
    std::cout << "Marka\tModel \tRok produkcji \tKolor\n";
    for (size_t i = 0; i < n; i++) {
        std::cout << samochody[i].marka << '\t' << samochody[i].model << '\t' << samochody[i].rokProdukcji
                  << "\t\t" << samochody[i].kolor << '\n';
    }
}

void zadanie2(struct samochod samochody[])
{
    samochody[5].marka = "Ferrari";
    samochody[5].model = "Enzo";
    samochody[5].rokProdukcji = 2004;
    samochody[5].kolor = "czerwony";
    zadanie1(samochody, 5);
}

