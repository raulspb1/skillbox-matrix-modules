#pragma once
#include <export.h>

#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Matrix Matrix;

MATRIXLIB_EXPORT Matrix* math_createMatrix(int rows, int cols);
MATRIXLIB_EXPORT void math_deleteMatrix(Matrix* M);
MATRIXLIB_EXPORT void math_set(Matrix* M, int row, int col, real value);
MATRIXLIB_EXPORT void math_print(const Matrix* M);

#ifdef __cplusplus
}
#endif
