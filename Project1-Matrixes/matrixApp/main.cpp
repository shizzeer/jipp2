//
// Created by Kamil on 20.10.2021.
//

#include <iostream>
#include <string>
#include <unordered_map>

#include "matrixLib.h"

#define MAX_NUMBER_OF_ARGS 4

void setMathOperationsType(std::string& parameter, int argc, char* argv[])
{
    parameter = std::string(argv[argc - 1]);
    if (parameter == "--floating") {
        std::cout << "Mathematical operations will be done on floating point numbers "
                     "inside the matrices.\n";
    } else {
        std::cout << "Mathematical operations will be done on integers inside the matrices.\n";
    }
}


int main(int argc, char* argv[])
{
    if (argc > MAX_NUMBER_OF_ARGS || argc == 1 || std::string(argv[1]) == "help") {
        printHelp();
        return -1;
    }

    const std::string cmd = std::string(argv[1]);
    std::string parameter;
    std::unordered_map<std::string, short> numberOfParamsInCmd;

    setMathOperationsType(parameter, argc, argv);

    int** matrixAInt, **matrixBInt, **resMatrixInt;
    double** matrixADouble, **matrixBDouble, **resMatrixDouble;
    int rows, cols;

    if (cmd == "-a" || cmd == "-s") {
        while (!getSizeOfMatrix(rows, cols, false)) {
            std::cout << "Size of a matrix need to be provided as positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        if (parameter == "--floating") {
            matrixADouble = allocMatrixDouble(rows, cols);
            matrixBDouble = allocMatrixDouble(rows, cols);
            initMatrix(matrixADouble, rows, cols);
            initMatrix(matrixBDouble, rows, cols);
        } else {
            matrixAInt = allocMatrixInt(rows, cols);
            matrixBInt = allocMatrixInt(rows, cols);
            initMatrix(matrixAInt, rows, cols);
            initMatrix(matrixBInt, rows, cols);
        }
        if (parameter == "--floating") {
            if (cmd == "-a") {
                resMatrixDouble = addMatrix(matrixADouble, matrixBDouble, rows, cols);
            }
            else
                resMatrixDouble = subtractMatrix(matrixADouble, matrixBDouble, rows, cols);
            freeMatrix(matrixADouble, rows, cols);
            freeMatrix(matrixBDouble, rows, cols);
            std::cout << "Result of the operation\n";
            printMatrix(resMatrixDouble, rows, cols);
            freeMatrix(resMatrixDouble, rows, cols);
        } else {
            if (cmd == "-a")
                resMatrixInt = addMatrix(matrixAInt, matrixBInt, rows, cols);
            else
                resMatrixInt = subtractMatrix(matrixAInt, matrixBInt, rows, cols);
            std::cout << "Result of the operation" << std::endl;
            freeMatrix(matrixAInt, rows, cols);
            freeMatrix(matrixBInt, rows, cols);
            printMatrix(resMatrixInt, rows, cols);
            freeMatrix(resMatrixInt, rows, cols);
        }
    }
    else if (cmd == "-m") {
        int colsA;
        /* Najpierw wczytujemy ilosc wierszy oraz kolumn pierwszej macierzy. */
        while (!getSizeOfMatrix(rows, cols, false)) {
            std::cout << "Size of a matrix need to be provided as positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        if (parameter == "--floating") {
            matrixADouble = allocMatrixDouble(rows, cols);
            initMatrix(matrixADouble, rows, cols);
            colsA = cols;
            /* Druga macierz musi mieć tyle wierszy co pierwsza kolumn. Pobieramy
             * wiec jedynie ilosc kolumn od uzytkownika. */
            std::cout << "The number of rows of the second matrix has to be equal"
                         " to the number of columns of the first matrix."
                         "Therefore you need to specify the number of columns only.\n";
            while (!getSizeOfMatrix(rows, cols, true)) {
                std::cout << "Size of a matrix need to be provided as positive number." << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
            matrixBDouble = allocMatrixDouble(rows, cols);
            initMatrix(matrixBDouble, rows, cols);
            resMatrixDouble = multiplyMatrix(matrixADouble, matrixBDouble, rows, colsA, cols);
            std::cout << "Result of the operation" << std::endl;
            freeMatrix(matrixADouble, rows, colsA);
            freeMatrix(matrixBDouble, colsA, cols);
            printMatrix(resMatrixDouble, rows, cols);
            freeMatrix(resMatrixDouble, rows, cols);
        } else {
            matrixAInt = allocMatrixInt(rows, cols);
            initMatrix(matrixAInt, rows, cols);
            colsA = cols;
            std::cout << "The number of rows of the second matrix has to be equal"
                         " to the number of columns of the first matrix."
                         "Therefore you need to specify the number of columns only.\n";
            while (!getSizeOfMatrix(rows, cols, true)) {
                std::cout << "Size of a matrix need to be provided as positive number." << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
            matrixBInt = allocMatrixInt(rows, cols);
            initMatrix(matrixBInt, rows, cols);
            resMatrixInt = multiplyMatrix(matrixAInt, matrixBInt, rows, colsA, cols);
            std::cout << "Result of the operation" << std::endl;
            freeMatrix(matrixAInt, rows, colsA);
            freeMatrix(matrixBInt, colsA, cols);
            printMatrix(resMatrixInt, rows, cols);
            freeMatrix(resMatrixInt, rows, cols);
        }
    }
    else if (cmd == "-ms" || cmd == "-t" || cmd == "-p" || cmd == "-d"
             || cmd == "-md" || cmd == "-srows") {

        /* Getting size of the first matrix from the user */
        while (!getSizeOfMatrix(rows, cols, false)) {
            std::cout << "Size of a matrix need to be provided as positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
        if (parameter == "--floating") {
            matrixADouble = allocMatrixDouble(rows, cols);
            initMatrix(matrixADouble, rows, cols);

            /* matrix by scalar multiplication */
            if (cmd == "-ms") {
                double scalar;
                while (!getOperationalNumber(scalar, "Scalar")) {
                    std::cout << "The operational number has to be passed as number!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                }
                resMatrixDouble = multiplyByScalar(matrixADouble, rows, cols, scalar);
                freeMatrix(matrixADouble, rows, cols);
                std::cout << "Result of the operation" << std::endl;
                printMatrix(resMatrixDouble, rows, cols);
                freeMatrix(resMatrixDouble, rows, cols);
            }

            /* matrix transposition */
            else if (cmd == "-t") {
                resMatrixDouble = transpozeMatrix(matrixADouble, rows, cols);
                freeMatrix(matrixADouble, rows, cols);
                std::cout << "Result of the operation" << std::endl;
                printMatrix(resMatrixDouble, cols, rows);
                freeMatrix(resMatrixDouble, cols, rows);
            }

            /* raising the matrix to the power of x */
            else if (cmd == "-p") {
                unsigned int exponent;
                getExponent(exponent);
                resMatrixDouble = powerMatrix(matrixADouble, rows, cols, exponent);
                std::cout << "Result of the operation" << std::endl;
                freeMatrix(matrixADouble, rows, cols);
                if (!exponent)
                    cols = rows;
                printMatrix(resMatrixDouble, cols, rows);
                freeMatrix(resMatrixDouble, cols, rows);
            }

            /* check if given matrix is diagonal */
            else if (cmd == "-md") {
                printMatrix(matrixADouble, rows, cols);
                if (matrixIsDiagonal(matrixADouble, rows, cols))
                    std::cout << "Given matrix is diagonal" << std::endl;
                else
                    std::cout << "Given matrix is not diagonal" << std::endl;
                freeMatrix(matrixADouble, rows, cols);
            }

            /* Sort rows of the given matrix */
            else if (cmd == "-srows") {
                std::cout << "Original matrix: " << std::endl;
                printMatrix(matrixADouble, rows, cols);
                std::cout << "Matrix after sorting rows operation: " << std::endl;
                resMatrixDouble = sortRowsInMatrix(matrixADouble, rows, cols);
                printMatrix(resMatrixDouble, rows, cols);
                freeMatrix(matrixADouble, rows, cols);
                delete[] resMatrixDouble;
            }

        } else {
            matrixAInt = allocMatrixInt(rows, cols);
            initMatrix(matrixAInt, rows, cols);

            /* matrix by scalar multiplication */
            if (cmd == "-ms") {
                int scalar;
                while (!getOperationalNumber(scalar, "Scalar")) {
                    std::cout << "The operational number has to be passed as number!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                }
                resMatrixInt = multiplyByScalar(matrixAInt, rows, cols, scalar);
                freeMatrix(matrixAInt, rows, cols);
                std::cout << "Result of the operation" << std::endl;
                printMatrix(resMatrixInt, rows, cols);
                freeMatrix(resMatrixInt, rows, cols);
            }

            /* matrix transposition */
            else if (cmd == "-t") {
                resMatrixInt = transpozeMatrix(matrixAInt, rows, cols);
                std::cout << "Result of the operation" << std::endl;
                freeMatrix(matrixAInt, rows, cols);
                printMatrix(resMatrixInt, cols, rows);
                freeMatrix(resMatrixInt, cols, rows);
            }

            /* raising the matrix to the power of x */
            else if (cmd == "-p") {
                unsigned int exponent;
                getExponent(exponent);
                resMatrixInt = powerMatrix(matrixAInt, rows, cols, exponent);
                std::cout << "Result of the operation" << std::endl;
                freeMatrix(matrixAInt, rows, cols);
                if (!exponent)
                    cols = rows;
                printMatrix(resMatrixInt, cols, rows);
                freeMatrix(resMatrixInt, cols, rows);
            }

            /* check if given matrix is diagonal */
            else if (cmd == "-md") {
                printMatrix(matrixAInt, rows, cols);
                if (matrixIsDiagonal(matrixAInt, rows, cols))
                    std::cout << "Given matrix is diagonal" << std::endl;
                else
                    std::cout << "Given matrix is not diagonal" << std::endl;
                freeMatrix(matrixAInt, rows, cols);
            }

            /* Sort rows of the given matrix */
            else if (cmd == "-srows") {
                std::cout << "Original matrix: " << std::endl;
                printMatrix(matrixAInt, rows, cols);
                std::cout << "Matrix after sorting rows operation: " << std::endl;
                resMatrixInt = sortRowsInMatrix(matrixAInt, rows, cols);
                printMatrix(resMatrixInt, rows, cols);
                freeMatrix(matrixAInt, rows, cols);
                delete[] resMatrixInt;
            }
        }
    }
    else
        printHelp();
    return 0;
}

