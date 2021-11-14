//
// Created by KSZ on 2021-11-14.
//

#ifndef JIPP2_STUDENT_H
#define JIPP2_STUDENT_H
#include <iostream>

class Student {
private:
    std::string imie;
    std::string nazwisko;
    unsigned int numerAlbumu;
    double liczbaPytan;
    double poprawneOdpowiedzi;
public:
    void wczytajDane();
    double obliczProcentPoprawnychOdpowiedzi() const;
};


#endif //JIPP2_STUDENT_H
