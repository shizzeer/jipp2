//
// Created by Kamil on 12.10.2021.
//
#include <iostream>

using namespace std;

void printHelp()
{
    cout << "Simple calculator\n";
    cout << "simpleCalc [nazwa dzialania]\n";
    cout << "Dzialania:\n";
    cout << "add [a] [b]\n"
            "Dodawanie dwoch liczb ([a] i [b]) calkowitych.\n";
    cout << "subtract [a] [b]\n"
            "Odejmowanie dwoch liczb ([a] i [b]) calkowitych.\n";
    cout << "volume [a] [b] [h] [H]\n"
            "Objetosc graniastoslupa prostego o podstawie trapezu gdzie\n"
            "[a] i [b] sa dlugosciami podstaw trapezu (liczby calkowite)\n"
            "[h] jest wysokoscia trapezu, natomiast [H] to wysokosc graniastoslupa\n";
    exit(0);
}

int add(char* argv[])
{
    return atoi(argv[2]) + atoi(argv[3]);
}

int subtract(char* argv[])
{
    return atoi(argv[2]) - atoi(argv[3]);
}

int volume(char* argv[])
{
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int h = atoi(argv[4]);
    int polePodstawy = (a + b) * h / 2;
    int H = atoi(argv[5]);
    return polePodstawy * H;
}

