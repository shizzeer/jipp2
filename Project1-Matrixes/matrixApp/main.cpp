//
// Created by Kamil on 20.10.2021.
//

#include <iostream>

#define MAX_NUMBER_OF_ARGS 4

void printHelp()
{
    /*
     * Prints help note when wrong parameters were passed or
     * there weren't any parameters.
     */
    std::cout << "=========MATRIXES CALCULATOR=========\n"
                 "usage: matrixApp [option]\n"
                 "-a - adding two matrices with the same size\n"
                 "-s - subtraction of two matrices with the same size\n"
                 "-m - multiplication of two matrices\n"
                 "-ms - matrix by scalar multiplication\n"
                 "-t - transposition of the matrix\n"
                 "-p [power] - raising the matrix to the power [power]\n"
                 "-d - calculate determinant of the matrix\n"
                 "-md - check if the matrix is diagonal\n"
                 "-sw [a] [b] - swapping number [a] with [b] inside the matrix\n"
                 "-srow - ???\n"
                 "-srows - sort each row in the matrix in the ascending order\n"
                 "help - prints helping note\n";
}

int main(int argc, char* argv[])
{
    if (argc > MAX_NUMBER_OF_ARGS || argc == 1 || argv[1] == '-h') {
        printHelp();
        return -1;
    }
    return 0;
}

