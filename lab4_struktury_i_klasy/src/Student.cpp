//
// Created by KSZ on 2021-11-14.
//

#include "Student.h"

void Student::wczytajDane()
{
    std::cout << "Imie: ";
    std::cin >> imie;
    std::cout << "Nazwisko: ";
    std::cin >> nazwisko;
    std::cout << "Numer albumu: ";
    std::cin >> numerAlbumu;
    std::cout << "Liczba pytan: ";
    std::cin >> liczbaPytan;
    std::cout << "Ilosc poprawnych odpowiedzi: ";
    std::cin >> poprawneOdpowiedzi;
}

double Student::obliczProcentPoprawnychOdpowiedzi() const
{
    return poprawneOdpowiedzi / liczbaPytan * 100;
}