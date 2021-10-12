//
// Created by Kamil on 12.10.2021.
//

#include <iostream>
#include "calc.h"

#define MIN_ARGS 4
#define MAX_ARGS 6

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < MIN_ARGS || argc > MAX_ARGS) {
        cerr << "Nieprawidlowa ilosc argumentow.\n";
        printHelp();
        return -1;
    }
    string cmd = argv[1];
    int res;
    if (cmd == "add") res = add(argv);
    else if (cmd == "subtract") res = subtract(argv);
    else if (cmd == "volume") {
        if (argc < MAX_ARGS)
            printHelp();
        res = volume(argv);
    }
    else printHelp();

    cout << "Wynik: " << res << '\n';
    return 0;
}
