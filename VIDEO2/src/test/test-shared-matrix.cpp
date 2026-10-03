#include <src/export.h>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif

extern Matrix* MATRIXLIB_EXPORT math_createMatrix(int, int);
extern void MATRIXLIB_EXPORT math_set(Matrix*, int, int, double);
extern void MATRIXLIB_EXPORT math_print(Matrix*);
extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix*);

#ifdef __cplusplus
}
#endif    

int main()
{
    Matrix* m = math_createMatrix(3, 3);
    
    math_set(m, 0,0,1);
    math_set(m, 1,1,1);

    math_print(m);

    math_deleteMatrix(m);

    return 0;
}