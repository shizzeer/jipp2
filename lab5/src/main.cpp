//
// Created by KSZ on 2021-11-14.
//

#include <iostream>
#include "Pojazd.h"

int main()
{
    std::cout << "ZADANIA Z PODDZIALU NUMER 1\n\n";
    std::cout << "Stworzenie pierwszego obiektu pojazdu\n";
    Pojazd pojazd1;
    Pojazd pojazd2(pojazd1);
    std::cout << "Wypisanie obiektu oryginalnego\n";
    pojazd1.wyswietl();
    std::cout << "Wypisanie obiektu bedacego kopia oryginalu\n";
    pojazd2.wyswietl();
    std::cout << "Aktualizacja stanu miejsca w obiekcie oryginalnym\n";
    pojazd1.zaktualizujStanMiejsca(0, "Jan Kowalski");
    pojazd1.wyswietl();
    pojazd2.wyswietl();
    std::cout << "Gettery i settery - test\n";
    std::cout << "Nazwa pojazdu: " << pojazd1.getNazwa() << '\n';
    std::cout << "Numer rejestracyjny: " << pojazd1.getNumerRejestracyjny() << '\n';
    std::cout << "Model: " << pojazd1.getModel() << '\n';
    std::cout << "Typ: " << pojazd1.getTyp() << '\n';
    pojazd2.setNumerRejestracyjny();
    std::cout << "Numer rejestracyjny pojazdu numer 2: " << pojazd2.getNumerRejestracyjny() << '\n';
    pojazd2.setNazwa();
    std::cout << "Nazwa pojazdu numer 2: " << pojazd2.getNazwa() << '\n';
    return 0;
}

