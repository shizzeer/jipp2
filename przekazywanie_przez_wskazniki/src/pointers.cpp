//
// Created by Kamil on 19.10.2021.
//

#include <iostream>

double avg(double a, double b)
{
    return (a + b) / 2;
}

void printPositiveNumbers(int* arr, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        if (*(arr + i) > 0)
            std::cout << *(arr + i) << '\t';
    }
}

void bubbleSort(int* arr, size_t n)
{
    bool change;
    for (size_t i = 0; i < n; i++) {
        change = false;
        for (size_t j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                change = true;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        /* Dzieki sprawdzeniu czy nie nastapila zamiania elementow, uzyskujemy
         * zlozonosc liniowa algorytmu sortowania przy danych posortowanych rosnaco */
        if (!change)
            break;
    }
}

void setVarFromPtr(int x, int* w)
{
    *w = x;
}