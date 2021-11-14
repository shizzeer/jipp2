//
// Created by KSZ on 2021-11-14.
//

#ifndef JIPP2_STRUKTURY_H
#define JIPP2_STRUKTURY_H
#include <iostream>

struct samochod {
    std::string marka;
    std::string model;
    int rokProdukcji;
    std::string kolor;
};
void zadanie1(struct samochod samochody[], size_t n);
void zadanie2(struct samochod samochody[]);
void zadanie3(struct samochod samochody[], size_t n);
size_t zadanie4(struct samochod samochody[], size_t n);
#endif //JIPP2_STRUKTURY_H
