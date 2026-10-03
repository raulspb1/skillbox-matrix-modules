#include "c_api.h"
#include "matrix.h"

#include <iostream>

typedef math::Matrix MatrixImpl;

Matrix* math_createMatrix(int rows, int cols) {
    return reinterpret_cast<Matrix*>(new MatrixImpl(rows, cols));
}

void math_deleteMatrix(Matrix* M) {
    delete reinterpret_cast<MatrixImpl*>(M);
}

void math_set(Matrix* M, int row, int col, real value) {
    // Используем оператор () для записи значения в матрицу
    (*reinterpret_cast<MatrixImpl*>(M))(row, col) = value;
}

void math_print(const Matrix* M) {
    reinterpret_cast<const MatrixImpl*>(M)->print();
}
