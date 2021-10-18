//
// Created by Kamil on 18.10.2021.
//

#include <iostream>
#include "pole.h"

int main()
{
    double p = 0;
    short opcja;
    double dlugosc = 0, szerokosc = 0, wysokosc = 0, promien = 0;
    drukujMenu();
    std::cout << "Podaj opcje: ";
    std::cin >> opcja;
    switch (opcja)
    {
        case 1: {
                /* Pole prostokata */
                std::cout << "Dlugosc: ";
                std::cin >> dlugosc;
                std::cout << "Szerokosc: ";
                std::cin >> szerokosc;
                pole(dlugosc, szerokosc, p);
            }
            break;
        case 2: {
                /* Pole prostopadloscianu */
                std::cout << "Dlugosc: ";
                std::cin >> dlugosc;
                std::cout << "Szerokosc: ";
                std::cin >> szerokosc;
                std::cout << "Wysokosc: ";
                std::cin >> wysokosc;
                pole(dlugosc, szerokosc, wysokosc, p);
            }
            break;
        case 3: {
                /* Pole kola */
                std::cout << "Promien: ";
                std::cin >> promien;
                pole(promien, p);
            }
            break;
        default:
            drukujMenu();
            break;
    }
    std::cout << "Pole wybranej figury = " << p << '\n';
    return 0;
}

