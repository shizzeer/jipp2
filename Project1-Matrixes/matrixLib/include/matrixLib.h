//
// Created by Kamil on 20.10.2021.
//

#ifndef JIPP2_MATRIXLIB_H
#define JIPP2_MATRIXLIB_H
void printHelp();

int** allocMatrixInt(int rows, int cols);
double** allocMatrixDouble(int rows, int cols);

bool getSizeOfMatrix(int& rows, int& cols, bool onlyCols);
bool getOperationalNumber(int& opNumber, std::string type);
bool getOperationalNumber(double& opNumber, std::string type);
bool getOperationalNumber(unsigned int& opNumber, std::string type);

void getExponent(unsigned int& exponent);

void initMatrix(int** matrix, int rows, int cols);
void initMatrix(double** matrix, int rows, int cols);

void printMatrix(int** matrix, int rows, int cols);
void printMatrix(double** matrix, int rows, int cols);

int** addMatrix(int** matrixA, int** matrixB, int rows,
                  int cols);
double** addMatrix(double** matrixA, double** matrixB, int rows,
                     int cols);

void freeMatrix(int** matrix, int rows, int cols);
void freeMatrix(double** matrix, int rows, int cols);

int** subtractMatrix(int** matrixA, int** matrixB, int rows,
                  int cols);
double** subtractMatrix(double** matrixA, double** matrixB, int rows,
                     int cols);

int** multiplyMatrix(int** matrixA, int** matrixB, int rowsA,
                     int colsA, int colsB);
double** multiplyMatrix(double** matrixA, double** matrixB, int rowsA,
                        int colsA, int colsB);

int** multiplyByScalar(int** matrixA, int rows, int cols, int scalar);
double** multiplyByScalar(double** matrixA, int rows, int cols, double scalar);

int** transpozeMatrix(int** matrixA, int rows, int cols);
double** transpozeMatrix(double** matrixA, int rows, int cols);

int** powerMatrix(int** matrixA, int rows, int cols, unsigned int exponent);
double** powerMatrix(double** matrixA, int rows, int cols, unsigned int exponent);

bool matrixIsDiagonal(int** matrixA, int rows, int cols);
bool matrixIsDiagonal(double** matrixA, int rows, int cols);

void swap(int& a, int& b);
void swap(double& a, double& b);

void sortRow(int* matrixRow, int cols);
void sortRow(double* matrixRow, int cols);

int** sortRowsInMatrix(int** matrixA, int rows, int cols);
double** sortRowsInMatrix(double** matrixA, int rows, int cols);

#endif //JIPP2_MATRIXLIB_H
