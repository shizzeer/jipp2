//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include <unordered_map>
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
    samochody[4].marka = "Ferrari";
    samochody[4].model = "Enzo";
    samochody[4].rokProdukcji = 2004;
    samochody[4].kolor = "czerwony";
    zadanie1(samochody, 5);
}

void zadanie3(struct samochod samochody[], size_t n)
{
    std::unordered_map<std::string, short> iloscMarek;
    std::unordered_map<std::string, bool> czyWypisany;
    for (size_t i = 0; i < n; i++) {
        if (iloscMarek.find(samochody[i].marka) != iloscMarek.end())
            iloscMarek[samochody[i].marka]++;
        else
            iloscMarek[samochody[i].marka] = 1;
    }
    for (size_t i = 0; i < n; i++) {
        if (iloscMarek[samochody[i].marka] > 1) {
            if (czyWypisany.find(samochody[i].marka) == czyWypisany.end()) {
                std::cout << samochody[i].marka << ": " << iloscMarek[samochody[i].marka] << '\n';
                czyWypisany[samochody[i].marka] = true;
            }
        }
    }
}

size_t zadanie4(struct samochod samochody[], size_t n)
{
    size_t idx = 0;
    for (size_t i = 1; i < n; i++) {
        if (samochody[i].rokProdukcji < samochody[idx].rokProdukcji)
            idx = i;
    }
    return idx;
}

