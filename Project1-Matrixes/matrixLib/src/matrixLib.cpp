//
// Created by Kamil on 20.10.2021.
//

#include <iostream>
#include <cstring>

/*
 * @params: None
 * Return value: The function doesn't return a value.
 * Description:
 *  The function prints help note.
*/
void printHelp()
{
    std::cout << "=========MATRIXES CALCULATOR=========\n"
                 "usage: matrixApp [option]\n"
                 "Options:\n"
                 "-a - adding two matrices with the same size\n"
                 "-s - subtraction of two matrices with the same size\n"
                 "-m - multiplication of two matrices\n"
                 "-ms - matrix by scalar multiplication. Scalar "
                        "has to have the same type as the matrix.\n"
                 "-t - transposition of the matrix\n"
                 "-p - raising the matrix to the specified power\n"
                 "-d - calculate determinant of the matrix\n"
                 "-md - check if the matrix is diagonal\n"
                 "-srows - sort each row in the matrix in the ascending order\n"
                 "help - prints helping note\n"
                 "Parameters:\n"
                 "--floating - making mathematical operations on floating point numbers "
                 "by default calculator is set to deal with integers\n"
                 "Or setting the matrices type to double in other words.\n\n"
                 "Note about usage:\n"
                 "Matrices and additional parameters to the commands are passed thorugh"
                 "the standard input after executing the program with the correct option.\n";
}

/*
 * @params:
 *   - rows - the number of rows in the matrix which will be allocated
 *   - cols - the number of columns in the matrix which will be allocated
 * Return value: The function returns the pointer to the allocated space
 *               for the matrix.
 * Description:
 *  This function allocates a matrix with the specified number of rows
 *  and columns.
 * */
int** allocMatrixInt(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int row = 0; row < rows; row++)
        matrix[row] = new int[cols];
    return matrix;
}

double** allocMatrixDouble(int rows, int cols)
{
    double** matrix = new double*[rows];
    for (int row = 0; row < rows; row++)
        matrix[row] = new double[cols];
    return matrix;
}

/*
 * @params:
 *  - rows - the number of rows in the matrix. This value will be given by a user.
 *  - cols - the number of columns in the matrix. This value will be given by a user.
 *  - onlyCols - if this parameter is true, the number of rows is already set and only
 *               the number of columns is fetched from the user.
 * Return value: The function returns false in case when other data than a number is
 *               given. Otherwise, it returns true.
 * Description:
 *  This function reads the number of rows and columns from the standard input. These
 *  values will be used while allocating the matrix.
 */
bool getSizeOfMatrix(int& rows, int& cols, bool onlyCols)
{
    if (!onlyCols) {
        std::cout << "Number of rows for the matrix: ";
        std::cin >> rows;
        if (std::cin.fail() || rows <= 0)
            return false;
    }
    std::cout << "Number of cols for the matrix: ";
    std::cin >> cols;
    if (std::cin.fail() || cols <= 0)
        return false;
    return true;
}

/*
 * @params:
 *  - opNumber - the number needed for making mathematical operation over the matrix.
 *  - name - the type of the number in the mathematical language.
 * Return value: The function returns false in case when other data than a number is
 *               given. Otherwise, it returns true.
 * Description:
 *  This function reads the operational number from the standard input. This
 *  value will be used while doing mathematical operation on the matrix.
 */
bool getOperationalNumber(int& opNumber, std::string type)
{
    std::cout << type << ": ";
    std::cin >> opNumber;
    if (std::cin.fail())
        return false;
    return true;
}

bool getOperationalNumber(double& opNumber, std::string type)
{
    std::cout << type << ": ";
    std::cin >> opNumber;
    if (std::cin.fail())
        return false;
    return true;
}

bool getOperationalNumber(unsigned int& opNumber, std::string type)
{
    std::cout << type << ": ";
    std::cin >> opNumber;
    if (std::cin.fail())
        return false;
    return true;
}

/*
 * @params:
 *  - exponent - the exponent used for raising the matrix to the power
 *               of given number.
 * Return value: This function doesn't return a value.
 * Description:
 *  This function reads the exponent from the user and saves it into
 *  the correct variable.
 */
void getExponent(unsigned int& exponent)
{
    while (!getOperationalNumber(exponent, "Exponent")) {
        std::cout << "The operational number has to be passed as number!" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}

/*
 * @params:
 *  - matrix - the pointer to the matrix which will be initialized.
 *  - rows - the number of rows in the matrix.
 *  - cols - the number of columns in the matrix.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function reads numbers from the standard input and assigns them
 *  to the matrix cells.
 */
void initMatrix(int** matrix, int rows, int cols)
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~INITIALIZATION~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int row = 0; row < rows; row++) {
        std::cout << "Initialization of " << row + 1 << " row\n";
        for (int col = 0; col < cols; col++) {
            std::cout << "[" << row + 1 << "][" << col + 1 << "]=";
            std::cin >> matrix[row][col];
        }
    }
}

void initMatrix(double** matrix, int rows, int cols)
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~INITIALIZATION~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int row = 0; row < rows; row++) {
        std::cout << "Initialization of " << row + 1 << " row\n";
        for (int col = 0; col < cols; col++) {
            std::cout << "[" << row + 1 << "][" << col + 1 << "]=";
            std::cin >> matrix[row][col];
        }
    }
}

/*
 * @params:
 *  - matrix - the pointer to the matrix which will be printed.
 *  - rows - the number of rows in the matrix.
 *  - cols - the number of columns in the matrix.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function prints the content of the matrix into standard output.
 */
void printMatrix(int** matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        std::cout << '[';
        for (int col = 0; col < cols; col++) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << "]\n";
    }
}

void printMatrix(double** matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        std::cout << '[';
        for (int col = 0; col < cols; col++) {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << "]\n";
    }
}

/*
 * @params:
 *  - matrix - two-dimensional array representing a matrix
 *  - rows - the number of rows inside the passed matrix
 *  - cols - the number of columns inside the passed matrix
 *  Return value: This function doesn't return a value.
 *  Description:
 *      The freeMatrix function clears the memory after
 *      allocating space for the passed matrix.
 */
void freeMatrix(int** matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
        delete[] matrix[row];
    delete[] matrix;
}

void freeMatrix(double** matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
            delete[] matrix[row];
    delete[] matrix;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - matrixB - the pointer to the matrix B.
 *  - rows - the number of rows in each provided matrix.
 *  - cols - the number of columns in each provided.
 * Return value: This function returns a matrix C such that C = matrixA + matrixB.
 * Description:
 *  The function adds two matrices and returns matrix C such that C = matrixA + matrixB.
 */
int** addMatrix(int** matrixA, int** matrixB, int rows,
                  int cols)
{
    int** matrixC = allocMatrixInt(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
    }
    return matrixC;
}

double** addMatrix(double** matrixA, double** matrixB, int rows,
                     int cols)
{
    double** matrixC = allocMatrixDouble(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            matrixC[row][col] = matrixA[row][col] + matrixB[row][col];
    }
    return matrixC;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - matrixB - the pointer to the matrix B.
 *  - rows - the number of rows in each provided matrix.
 *  - cols - the number of columns in each provided.
 * Return value: This function returns a matrix C such that C = matrixA - matrixB.
 * Description:
 *  The function subtracts two matrices and returns matrix C such that C = matrixA - matrixB.
 */
int** subtractMatrix(int** matrixA, int** matrixB, int rows,
                  int cols)
{
    int** matrixC = allocMatrixInt(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            matrixC[row][col] = matrixA[row][col] - matrixB[row][col];
    }
    return matrixC;
}

double** subtractMatrix(double** matrixA, double** matrixB, int rows,
                        int cols)
{
    double** matrixC = allocMatrixDouble(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++)
            matrixC[row][col] = matrixA[row][col] - matrixB[row][col];
    }
    return matrixC;
}

/*
 * @params:
 *  - arr - two-dimensional array which will be processed.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 * Return value: The function doesn't return a value.
 * Description:
 *  This function is in charge of filling two-dimensional array passed
 *  as the argument with NULL bytes.
 * */
static void fillArrayWithZeroes(int** arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        std::memset(arr[row], 0, cols * sizeof(int));
    }
}

static void fillArrayWithZeroes(double** arr, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        std::memset(arr[row], 0, cols * sizeof(double));
    }
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - matrixB - the pointer to the matrix B.
 *  - rowsA - the number of rows in matrixA.
 *  - colsA - the number of columns in matrixA.
 *  - colsB - the number of columns in matrixB.
 * Return value: This function returns a matrix C such that C = matrixA * matrixB.
 * Description:
 *  The function multiplies two matrices and returns matrix C such that C = matrixA * matrixB.
 */
int** multiplyMatrix(int** matrixA, int** matrixB, int rowsA,
                     int colsA, int colsB)
{
    int** matrixC = allocMatrixInt(rowsA, colsB);
    fillArrayWithZeroes(matrixC, rowsA, colsB);
    for (int row = 0; row < rowsA; row++) {
        for (int colB = 0; colB < colsB; colB++) {
            for (int rowB = 0; rowB < colsA; rowB++) {
                matrixC[row][colB] += matrixA[row][rowB] * matrixB[rowB][colB];
            }
        }
    }
    return matrixC;
}

double** multiplyMatrix(double** matrixA, double** matrixB, int rowsA,
                     int colsA, int colsB)
{
    double** matrixC = allocMatrixDouble(rowsA, colsB);
    fillArrayWithZeroes(matrixC, rowsA, colsB);
    for (int row = 0; row < rowsA; row++) {
        for (int colB = 0; colB < colsB; colB++) {
            for (int rowB = 0; rowB < colsA; rowB++) {
                matrixC[row][colB] += matrixA[row][rowB] * matrixB[rowB][colB];
            }
        }
    }
    return matrixC;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 *  - scalar - this is scalar S such that matrixC[row][col] = matrixA[row][col] * S
 * Return value: This function returns a matrix C which is the product of matrixA
 *               multiplicated by scalar.
 * Description:
 *  The function multiplies matrixA from the first argument by the passed scalar.
 */
int** multiplyByScalar(int** matrixA, int rows, int cols, int scalar)
{
    int** matrixC = allocMatrixInt(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrixC[row][col] = matrixA[row][col] * scalar;
        }
    }
    return matrixC;
}

double** multiplyByScalar(double** matrixA, int rows, int cols, double scalar)
{
    double** matrixC = allocMatrixDouble(rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrixC[row][col] = matrixA[row][col] * scalar;
        }
    }
    return matrixC;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 * Return value: This function returns a matrix C which is a transposition
 *               of the matrix from the first argument.
 * Description:
 *  The function transposes matrices.
 */
int** transpozeMatrix(int** matrixA, int rows, int cols)
{
    int** matrixC = allocMatrixInt(cols, rows);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrixC[col][row] = matrixA[row][col];
        }
    }
    return matrixC;
}

double** transpozeMatrix(double** matrixA, int rows, int cols)
{
    double** matrixC = allocMatrixDouble(cols, rows);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            matrixC[col][row] = matrixA[row][col];
        }
    }
    return matrixC;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function modifies the matrix such that it becomes an identity matrix.
 */
static void createIdentityMatrix(double** matrixA, int rows, int cols)
{
    fillArrayWithZeroes(matrixA, rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row == col)
                matrixA[row][col] = 1;
        }
    }
}

static void createIdentityMatrix(int** matrixA, int rows, int cols)
{
    fillArrayWithZeroes(matrixA, rows, cols);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (row == col)
                matrixA[row][col] = 1;
        }
    }
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 *  - exponent - the number used as exponent in the exponentiation of the matrix.
 * Return value: This function returns matrixC such that matrixC is the product of rising
 *               matrixA to the power of exponent (matrixC = matrixA**exponent)
 * Description:
 *  The function raises matrixA to the power of exponent.
 */
int** powerMatrix(int** matrixA, int rows, int cols, unsigned int exponent)
{
    int** matrixC = allocMatrixInt(rows, cols);
    if (!exponent) {
        freeMatrix(matrixC, rows, cols);
        int** identityMatrix = allocMatrixInt(rows, rows);
        createIdentityMatrix(identityMatrix, rows, rows);
        return identityMatrix;
    }
    else {
        matrixC = matrixA;
        for (unsigned int i = 1; i < exponent; i++)
            matrixC = multiplyMatrix(matrixC, matrixA, rows, cols, cols);
    }
    return matrixC;
}

double** powerMatrix(double** matrixA, int rows, int cols, unsigned int exponent)
{
    double** matrixC = allocMatrixDouble(rows, cols);
    if (!exponent) {
        freeMatrix(matrixC, rows, cols);
        double** identityMatrix = allocMatrixDouble(rows, rows);
        createIdentityMatrix(identityMatrix, rows, rows);
        return identityMatrix;
    }
    else {
        matrixC = matrixA;
        for (unsigned int i = 1; i < exponent; i++)
            matrixC = multiplyMatrix(matrixC, matrixA, rows, cols, cols);
    }
    return matrixC;
}

static void getCofactor(int** matrixA, int** cofactor, int rowA, int colA,
                        int n)
{
    int rowCo = 0, colCo = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != rowA && col != colA) {
                cofactor[rowCo][colCo++] = matrixA[row][col];
                if (colCo == n - 1) {
                    colCo = 0;
                    rowCo++;
                }
            }
        }
    }
}

static void getCofactor(double** matrixA, double** cofactor, int rowA, int colA,
                        int n)
{
    int rowCo = 0, colCo = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != rowA && col != colA) {
                cofactor[rowCo][colCo++] = matrixA[row][col];
                if (colCo == n - 1) {
                    colCo = 0;
                    rowCo++;
                }
            }
        }
    }
}

int determinantMatrix(int** matrixA, int rows, int cols)
{
    if (1 == rows == cols)
        return matrixA[0][0];
    else if (2 == rows == cols)
        return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];

    int** cofactor = allocMatrixInt(rows, cols);
    int sign = 1;
    int determinant = 0;
    /* Firstly, always the first row is processed */
    for (int col = 0; col < cols; col++) {
        /* matrixA is a square matrix so we can pass its size as cols or rows */
        getCofactor(matrixA, cofactor, 0, col, cols);
        determinant += sign * matrixA[0][col] * determinantMatrix(cofactor, rows - 1, cols - 1);
        sign = -sign;
    }
    freeMatrix(cofactor, rows, cols);
    return determinant;
}

double determinantMatrix(double** matrixA, int rows, int cols)
{
    if (1 == rows == cols)
        return matrixA[0][0];
    else if (2 == rows == cols)
        return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];

    double** cofactor = allocMatrixDouble(rows, cols);
    double sign = 1;
    double determinant = 0;
    /* Firstly, always the first row is processed */
    for (int col = 0; col < cols; col++) {
        /* matrixA is a square matrix so we can pass its size as cols or rows */
        getCofactor(matrixA, cofactor, 0, col, cols);
        determinant += sign * matrixA[0][col] * determinantMatrix(cofactor, rows - 1, cols - 1);
        sign = -sign;
    }
    freeMatrix(cofactor, rows, cols);
    return determinant;
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 * Return value: This function returns true if a matrix is diagonal and false otherwise.
 * Description:
 *  The function checks if a matrix is diagonal.
 */
bool matrixIsDiagonal(int** matrixA, int rows, int cols)
{
    if (rows != cols)
        return false;
    else if (1 == rows == cols)
        return true;
    for (int row = 0; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            if (row == col)
                continue;
            else if (matrixA[row][col] != 0)
                return false;
        }
    }
    return true;
}

bool matrixIsDiagonal(double** matrixA, int rows, int cols)
{
    if (rows != cols)
        return false;
    else if (1 == rows == cols)
        return true;
    for (int row = 0; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            if (row == col)
                continue;
            else if (matrixA[row][col] != 0)
                return false;
        }
    }
    return true;
}

/*
 * @params:
 *  - a - a reference to the arbitrary number.
 *  - b - a reference to the arbitrary number.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function swaps two numbers in its original places.
 */
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

/*
 * @params:
 *  - matrixRow - row of the matrix to sort.
 *  - cols - the number of elements inside the row.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function sorts the given row of a matrix. It
 *  uses optimized bubble sort as sorting algorithm.
 */
void sortRow(int* matrixRow, int cols)
{
    bool change;
    for (int colOut = 0; colOut < cols; colOut++) {
        change = false;
        for (int colIn = 0; colIn < cols - 1; colIn++) {
            if (matrixRow[colIn] > matrixRow[colIn + 1]) {
                change = true;
                swap(matrixRow[colIn], matrixRow[colIn + 1]);
            }
        }
        if (!change)
            break;
    }
}

void sortRow(double* matrixRow, int cols)
{
    bool change;
    for (int colOut = 0; colOut < cols; colOut++) {
        change = false;
        for (int colIn = 0; colIn < cols - 1; colIn++) {
            if (matrixRow[colIn] > matrixRow[colIn + 1]) {
                change = true;
                swap(matrixRow[colIn], matrixRow[colIn + 1]);
            }
        }
        if (!change)
            break;
    }
}

/*
 * @params:
 *  - matrixA - the pointer to the matrix A.
 *  - rows - the number of rows of the passed two-dimensional array.
 *  - cols - the number of columns of the passed two-dimensional array.
 * Return value: This function doesn't return a value.
 * Description:
 *  The function sorts each row in the given matrix.
 */
int** sortRowsInMatrix(int** matrixA, int rows, int cols)
{
    int** matrixC = allocMatrixInt(rows, cols);
    for (int row = 0; row < rows; row++) {
        delete[] matrixC[row];
        sortRow(matrixA[row], cols);
        matrixC[row] = matrixA[row];
    }
    return matrixC;
}

double** sortRowsInMatrix(double** matrixA, int rows, int cols)
{
    double** matrixC = allocMatrixDouble(rows, cols);
    for (int row = 0; row < rows; row++) {
        delete[] matrixC[row];
        sortRow(matrixA[row], cols);
        matrixC[row] = matrixA[row];
    }
    return matrixC;
}
