//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "Figura.h"

Figura::Figura()
{
    std::cout << "Ilosc wierzcholkow figury: ";
    std::cin >> liczbaWierzcholkow;
    wierzcholki = new struct wierzcholek[liczbaWierzcholkow];
    for (int i = 0; i < liczbaWierzcholkow; i++) {
        std::cout << "x wierzcholka numer " << i + 1 << " -> ";
        std::cin >> wierzcholki[i].x;
        std::cout << "y wierzcholka numer " << i + 1 << " -> ";
        std::cin >> wierzcholki[i].y;
    }
}

Figura::~Figura()
{
    delete[] wierzcholki;
}