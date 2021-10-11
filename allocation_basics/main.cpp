//
// Created by Kamil on 11.10.2021.
//

#include <iostream>
#include <stdlib.h>

#define PROPER_NUMBER_OF_ARGS 4
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    /*
    int *n = new int;
    int k;
    cout << n << '\n' << *n << '\n' << &n << '\n' << &k << '\n';
    delete n;

    int *tab = new int[5];
    delete[] tab;
    int **tab2 = new int *[5];

    for (int i = 0; i < 5; ++i) {
        tab2[i] = new int[5];
    }
    for (int i = 0; i < 5; i++) {
        delete[] tab2[i];
    }
    delete[] tab2;

    int tab3[3] = {3, 2, 1};

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << '\n';
    } */
    if (argc < 4 || argc > 6 || argc == 5) {
        cout << "Simple calculator\n";
        cout << "simpleCalc [nazwa dzialania]\n";

        cout << "Dzialania:\n";
        cout << "add [a] [b]\nsubtract [a] [b]\nvolume [a] [b] [c] [d]\n";
    }
    return 0;
}