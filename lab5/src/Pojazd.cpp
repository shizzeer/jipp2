//
// Created by KSZ on 2021-11-14.
//

#include "../include/Pojazd.h"

Pojazd::Pojazd()
    : numerRejestracyjny(123456),
    nazwa("Peugeot"),
    iloscMiejsc(6),
    model("308"),
    typ("sedan")
{
    tab = new std::string[iloscMiejsc];
    for (int i = 0; i < iloscMiejsc; i++)
        tab[i] = "Puste";
}

Pojazd::Pojazd(Pojazd& pojazd)
{
    numerRejestracyjny = pojazd.numerRejestracyjny;
    nazwa = pojazd.nazwa;
    iloscMiejsc = pojazd.iloscMiejsc;
    tab = new std::string[iloscMiejsc];
    for (int i = 0; i < iloscMiejsc; i++)
        tab[i] = pojazd.tab[i];
    model = pojazd.model;
    typ = pojazd.typ;
}

Pojazd::~Pojazd()
{
    delete[] tab;
}

void Pojazd::wyswietl() const
{
    std::cout << "==================================\n";
    std::cout << "Numer rejestracyjny: " << numerRejestracyjny << '\n';
    std::cout << "Marka: " << nazwa << '\n';
    std::cout << "Ilosc miejsc: " << iloscMiejsc << '\n';
    std::cout << "Stan miejsc w pojezdzie\n";
    for (int i = 0; i < iloscMiejsc; i++)
        std::cout << "Miejsce " << i + 1 << " zajmowane przez " << tab[i] << '\n';
    std::cout << "Model: " << model << '\n';
    std::cout << "Typ: " << typ << '\n';
    std::cout << "==================================\n";
}

void Pojazd::zaktualizujStanMiejsca(unsigned short miejsce, const std::string& pasazer)
{
    if (miejsce >= 0 && miejsce < iloscMiejsc)
        tab[miejsce] = pasazer;
}

std::string Pojazd::getNazwa() const
{
    return nazwa;
}

unsigned int Pojazd::getNumerRejestracyjny() const
{
    return numerRejestracyjny;
}

std::string Pojazd::getModel() const
{
    return model;
}

std::string Pojazd::getTyp() const
{
    return typ;
}

void Pojazd::setNazwa()
{
    std::cout << "Nowa nazwa dla pojazdu: ";
    std::cin >> nazwa;
}

void Pojazd::setNumerRejestracyjny()
{
    std::cout << "Nowy numer rejestracyjny dla pojazdu: ";
    std::cin >> numerRejestracyjny;
}




