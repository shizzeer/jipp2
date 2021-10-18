//
// Created by Kamil on 18.10.2021.
//

#include <iostream>
#include <time.h> /* time */
#include <stdlib.h> /* srand, rand */

int getRandFromRange(int a, int b)
{
    return ( rand() % (a - b + 1) ) + a;
}

int findLargestValue(int arr[], size_t n)
{
    int max = arr[0];
    for (size_t i = 0; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void fillArr(int arr[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        arr[i] = getRandFromRange(1, 100);
}

void printArr(int arr[] , size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        if (i % 4 == 0)
            std::cout << '\n';
        std::cout << arr[i] << '\t';
    }
}

void reverseArr(int arr[], int n)
{
    int start = 0, end = n - 1;
    int tmp;
    while (start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}

void printMenu()
{
    std::cout << "Trzy zadania w jednym. Wybierz numer opcji, ktora mam wykonac:\n"
                 "1. Losowanie liczby z przedzialu\n"
                 "2. Zwrocenie najwiekszej wartosci z tablicy jednowymiarowej\n"
                 "3. Odwrocenie przykladowej tablicy\n";
}

int main()
{
    short option;
    printMenu();
    std::cout << "Wybierz opcje: ";
    std::cin >> option;
    srand(time(NULL));
    switch (option)
    {
        case 1: {
            int a, b, result;
            std::cout << "=======LOSOWANIE LICZBY Z ZADANEGO PRZEDZIALU=======\n";
            std::cout << "Podaj a: ";
            std::cin >> a;
            std::cout << "Podaj b: ";
            std::cin >> b;
            result = getRandFromRange(a, b);
            std::cout << "Wylosowana liczba to: " << result << '\n';
        } break;
        case 2: {
            size_t n;
            std::cout << "=======ZNAJDOWANIE NAJWIEKSZEJ LICZBY WEWNATRZ TABLICY=======\n";
            std::cout << "Podaj rozmiar tablicy: ";
            std::cin >> n;
            int* arr = new int [n];
            fillArr(arr, n);
            int max = findLargestValue(arr, n);
            std::cout << "Tablica\n";
            printArr(arr, n);
            std::cout << "\nNajwieksza wartosc: " << max << '\n';
            delete[] arr;
        } break;
        case 3: {
            std::cout << "=======ODWROCENIE TABLICY=======\n";
            int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
            std::cout << "Tablica przed odwroceniem\n\n";
            printArr(arr, 8);
            reverseArr(arr, 8);
            std::cout << "\n\nTablica po odwroceniu\n\n";
            printArr(arr, 8);
        } break;
        default:
            printMenu();
        break;
    }
    return 0;
}
