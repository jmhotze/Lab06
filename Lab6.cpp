#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrix[][MAX_SIZE], int& size, const std::string& filename);
void printMatrix(const int matrix[][MAX_SIZE], int size);
void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);

int main() {
    int size;
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrixFromFile(matrix1, size, "matrix_input.txt");
    readMatrixFromFile(matrix2, size, "matrix_input.txt"); // Read the second matrix from the same file

    std::cout << "Matrix 1 = \n";
    printMatrix(matrix1, size);

    std::cout << "Matrix 2 = \n";
    printMatrix(matrix2, size);

    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 added to Matrix 2 = \n";
    printMatrix(result, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 times Matrix 2 =\n";
    printMatrix(result, size);

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 - Matrix 2 =\n";
    printMatrix(result, size);

    return 0;
}

void readMatrixFromFile(int matrix[][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        exit(1);
    }

    file >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
}

void printMatrix(const int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }
}

void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

