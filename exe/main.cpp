#include <iostream>

// Определение внутреннего типа данных библиотеки (одинарная точность)
typedef float real;

// Импорт C-интерфейса из динамической библиотеки matrixlib
extern "C" {
    struct Matrix;
    struct Matrix* math_createMatrix(int rows, int cols);
    void math_deleteMatrix(struct Matrix* M);
    void math_set(struct Matrix* M, int row, int col, real value);
    void math_print(const struct Matrix* M);
}

int main() {
    std::cout << "=== Запуск приложения EXE с импортированной библиотекой ===" << std::endl;
    
    // Демонстрация работы с импортированной структурой данных
    struct Matrix* m = math_createMatrix(3, 3);
    
    math_set(m, 0, 0, 7.0f);
    math_set(m, 1, 1, 7.0f);
    math_set(m, 2, 2, 7.0f);
    
    std::cout << "Вывод матрицы из импортированной библиотеки:" << std::endl;
    math_print(m);
    
    // Освобождение памяти, выделенной внутри динамической библиотеки
    math_deleteMatrix(m);
    return 0;
}
