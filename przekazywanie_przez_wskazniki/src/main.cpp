//
// Created by Kamil on 19.10.2021.
//

#include <iostream>
#include "pointers.h"

size_t allocateArrAndGetSize(int** arr)
{
    size_t n;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> n;
    *arr = new int[n];
    return n;
}

void fillArr(int* arr, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Podaj " << i + 1 << " liczbe: ";
        std::cin >> arr[i];
    }
}

void printArr(int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << "\t";
        if (i != 0 && i % 4 == 0)
            std::cout << '\n';
    }
}

void zadanie1()
{
    std::cout << "===========ZADANIE 1===========\n";
    /* Zadanie z obliczaniem sredniej na podstawie wskaznikow */
    double* a = new double;
    double* b = new double;
    std::cout << "Podaj a: ";
    std::cin >> *a;
    std::cout << "Podaj b: ";
    std::cin >> *b;
    std::cout << "Srednia podanych liczb: " << avg(*a, *b);
    delete a;
    delete b;
}

void zadanie2()
{
    std::cout << "\n===========ZADANIE 2===========\n";
    size_t n ;
    int* arr;
    n = allocateArrAndGetSize(&arr);
    fillArr(arr, n);
    std::cout << "Liczby dodatnie we wczytanej tablicy:\n";
    printPositiveNumbers(arr, n);
    delete[] arr;
}

void zadanie3()
{
    std::cout << "\n===========ZADANIE 3===========\n";
    size_t n ;
    int* arr;
    n = allocateArrAndGetSize(&arr);
    fillArr(arr, n);
    /* Nie jestem pewny czy dobrze zrozumialem tresc zadania, ale zaimplementowalem sortowanie
     * bombelkowe, ktore sortuje wczytane liczby do tablicy w kolejnosci rosnacej. */
    bubbleSort(arr, n);
    std::cout << "Tablica posortowana rosnaco:\n";
    printArr(arr, n);
}

void zadanie4()
{
    std::cout << "\n===========ZADANIE 4===========\n";
    int a = 3;
    int* w = &a;
    std::cout << "Wartosc zmiennej przed zmiana: " << a << '\n';
    setVarFromPtr(10, w);
    std::cout << "Wartosc zmiennej po zmianie: " << a << '\n';
}

int main()
{
    /* Zadanie z obliczeniem sredniej dwoch liczb przy uzyciu wskaznikow */
    zadanie1();
    /* Zadanie z wczytaniem i wyszukaniem w tablicy elementow wiekszych od 0 */
    zadanie2();
    /* Zadanie z sortowaniem danych */
    zadanie3();
    /* Zadanie ze zmiana wartosci zmiennej wskazywanej przez wskaznik */
    zadanie4();
    return 0;
}

