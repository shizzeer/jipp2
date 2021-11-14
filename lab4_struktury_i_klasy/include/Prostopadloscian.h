//
// Created by KSZ on 2021-11-14.
//

#ifndef JIPP2_PROSTOPADLOSCIAN_H
#define JIPP2_PROSTOPADLOSCIAN_H


class Prostopadloscian {
private:
    double a;
    double b;
    double h;
public:
    Prostopadloscian(double a, double b, double h);
    double obliczPole();
};


#endif //JIPP2_PROSTOPADLOSCIAN_H
