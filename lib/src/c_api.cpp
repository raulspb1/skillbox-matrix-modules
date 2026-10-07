#include "c_api.h"
#include "matrix.h"

#include <iostream>

// Привязка к исходному классу Matrix из пространства имен math
typedef math::Matrix MatrixImpl;

Matrix* math_createMatrix(int rows, int cols) {
    return reinterpret_cast<Matrix*>(new MatrixImpl(rows, cols));
}

void math_deleteMatrix(Matrix* M) {
    delete reinterpret_cast<MatrixImpl*>(M);
}

void math_set(Matrix* M, int row, int col, real value) {
    // Запись значения через перегруженный оператор круглых скобок ()
    (*reinterpret_cast<MatrixImpl*>(M))(row, col) = value;
}

void math_print(const Matrix* M) {
    reinterpret_cast<const MatrixImpl*>(M)->print();
}

void math_multiplyByScalar(Matrix* M, real scalar) {
    // Вызов встроенного матричного оператора *= класса Matrix
    *(reinterpret_cast<MatrixImpl*>(M)) *= scalar;
}
