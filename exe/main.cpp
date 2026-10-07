#include <iostream>

// Определение внутреннего типа данных библиотеки (одинарная точность)
typedef float real;

// Импорт C-интерфейса из разделяемой библиотеки matrixlib
extern "C" {
    struct Matrix;
    struct Matrix* math_createMatrix(int rows, int cols);
    void math_deleteMatrix(struct Matrix* M);
    void math_set(struct Matrix* M, int row, int col, real value);
    void math_print(const struct Matrix* M);
    
    // Импорт матричной операции умножения на скаляр
    void math_multiplyByScalar(struct Matrix* M, real scalar);
}

int main() {
    std::cout << "=== Запуск приложения EXE с импортированной библиотекой ===" << std::endl;
    
    // Инициализация структуры данных размерностью 3x3
    struct Matrix* m = math_createMatrix(3, 3);
    
    // Формирование единичной главной диагонали
    math_set(m, 0, 0, 1.0f);
    math_set(m, 1, 1, 1.0f);
    math_set(m, 2, 2, 1.0f);
    
    std::cout << "Исходная единичная матрица:" << std::endl;
    math_print(m);
    
    // Вызов высокоуровневой матричной операции библиотеки (умножение на число)
    // Данная функция демонстрирует работу встроенных перегруженных операторов класса
    math_multiplyByScalar(m, 7.0f);
    
    std::cout << "\nМатрица после выполнения операции умножения на скаляр (7.0):" << std::endl;
    math_print(m);
    
    // Освобождение динамической памяти разделяемой библиотеки
    math_deleteMatrix(m);
    return 0;
}
