#include <src/matrix.h>
#include <iostream>

int main()
{
    // 1. Создаем две базовые матрицы размером 3x3
    math::Matrix m(3, 3);
    m(0,0)=1.;
    m(1,1)=1.;

    math::Matrix m1(3, 3);
    m1(0,0)=5.;
    m1(1,1)=5.;

    // Использование перегруженного оператора вывода << вместо старого метода print()
    std::cout << "Matrix m is:" << std::endl;
    std::cout << m; 

    std::cout << std::endl << "Matrix m1 is:" << std::endl;
    std::cout << m1;

    // Вычисление базовых операций
    math::Matrix m2 = m + m1;
    std::cout << std::endl << "Summ of m + m1 is:" << std::endl;
    std::cout << m2;

    math::Matrix m3 = m - m1;
    std::cout << std::endl << "Difference of m - m1 is:" << std::endl;
    std::cout << m3;

    std::cout << std::endl << "Multiplication of matrices m and m1 is:" << std::endl;
    math::Matrix m4 = m * 2.0;
    std::cout << m4;

    // Вычисление арифметических операций с присваиванием
    std::cout << std::endl << "Executing: m += m1 (modifying matrix m)..." << std::endl;
    m += m1;
    std::cout << "Matrix m after += operation is:" << std::endl;
    std::cout << m;

    std::cout << std::endl << "Executing: m -= m1 (modifying matrix m)..." << std::endl;
    m -= m1;
    std::cout << "Matrix m after -= operation is:" << std::endl;
    std::cout << m;

        // Тестирование оператора умножения матрицы на число
    std::cout << std::endl
              << "Executing: m *= 2.0 (multiplying matrix m by scalar 2.0):" << std::endl;
    m *= 2.0;

    std::cout << "Matrix m after *= operation is:" << std::endl;
    std::cout << m;


    // 2. Тестирование нового оператора ручного ввода >>
    std::cout << std::endl << "--- Testing Matrix Input Operator ---" << std::endl;
    math::Matrix user_matrix(3, 3); // Создаем матрицу 3x3 для быстрого ввода
    std::cout << "Please enter elements for a 3x3 matrix:" << std::endl;
    
    // Ввод элементов с клавиатуры
    std::cin >> user_matrix;

    // Вывод введенной пользователем матрицы для проверки
    std::cout << "\nYou entered the following matrix:" << std::endl;
    std::cout << user_matrix;

    return 0;
}
