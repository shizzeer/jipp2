//
// Created by KSZ on 2021-11-14.
//

#ifndef JIPP2_POJAZD_H
#define JIPP2_POJAZD_H
#include <iostream>

class Pojazd {
private:
    unsigned int numerRejestracyjny;
    std::string nazwa;
    unsigned short iloscMiejsc;
    std::string* tab;
    std::string model;
    std::string typ;
public:
    Pojazd();
    Pojazd(Pojazd& pojazd);
    void wyswietl() const;
    void zaktualizujStanMiejsca(unsigned short miejsce, const std::string& pasazer);
    std::string getNazwa() const;
    unsigned int getNumerRejestracyjny() const;
    std::string getModel() const;
    std::string getTyp() const;
    void setNazwa();
    void setNumerRejestracyjny();
    ~Pojazd();
};


#endif //JIPP2_POJAZD_H
