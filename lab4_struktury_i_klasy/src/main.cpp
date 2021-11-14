//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "struktury.h"
#include "Prostopadloscian.h"
#include "Kula.h"
#include "FunkcjaKwadratowa.h"
#include "Student.h"
#include "Punkt.h"
#include "Figura.h"
#include "PrzykladDesktruktor.h"

int main()
{
    samochod samochody[5] = { {"Ford", "GT", 2005, "czerwony"},
                             {"Toyota", "Supra", 1999, "czarny"},
                             {"Ferrari", "LaFerrari", 2015, "czarny"},
                             {"Bugatti", "Chiron", 2015, "granatowy"}};

    std::cout << "===============STRUKTURY===============\n";
    std::cout << "\n\nZADANIE 1\n";
    zadanie1(samochody, 4);

    std::cout << "\n\nZADANIE 2\n";
    zadanie2(samochody);

    std::cout << "\n\nZADANIE 3\n";
    zadanie3(samochody, 5);

    std::cout << "\n\nZADANIE 4\n";
    size_t idx = zadanie4(samochody, 5);
    std::cout << "Indeks samochody o najnizszym roku produkcji: " << idx << '\n';

    std::cout << "\n\n===============KLASY===============\n";
    std::cout << "\n\nZADANIE 2.1\n";
    Prostopadloscian prostopadloscian(1, 2, 3);
    double pole = prostopadloscian.obliczPole();
    std::cout << "Pole prostopadloscianu zdefiniowanego prostopadloscianu = " << pole << '\n';

    std::cout << "\n\nZADANIE 2.2\n";
    Kula kula(5);
    double v = kula.obliczObjetosc();
    std::cout << "Objetosc zdefiniowanej kuli = " << v << '\n';

    std::cout << "\n\nZADANIE 2.3\n";
    FunkcjaKwadratowa funkcjaKwadratowa(5, 6, 7);
    funkcjaKwadratowa.wyswietl();

    /*
    std::cout << "\n\nZADANIE 2.4\n";
    Student student;
    student.wczytajDane();
    double procentPopOdp = student.obliczProcentPoprawnychOdpowiedzi();
    std::cout << procentPopOdp << "% poprawnych odpowiedzi\n"; */

    std::cout << "\n\nZADANIE 5.1\n";
    Punkt punkt(10, 5);
    double odlegloscWspolrzednych = punkt.obliczOdleglosc();
    std::cout << "Odleglosc miedzy wspolrzednymi punktu = " << odlegloscWspolrzednych << '\n';

    /*
    std::cout << "\n\nZADANIE 5.2\n";
    Figura figura; */

    std::cout << "\n\nZADANIE ODNOSNIE DESTRUKTOROW\n";
    PrzykladDesktruktor pd;
    pd.pause();

    return 0;
}

