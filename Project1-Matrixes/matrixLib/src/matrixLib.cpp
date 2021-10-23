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
                 "-sw - swapping number [a] with [b] inside the matrix\n"
                 "-srow - ???\n"
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

