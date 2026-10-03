#pragma once
#include <vector>
#include <iostream> 

namespace math
{
typedef double real;

class Matrix
{
private:
    int cols_;
    int rows_;
    std::vector<real> mvec_;

public:
    Matrix() {};
    Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

    real& operator()(int row, int col);
    real operator()(int row, int col) const;
    void print();

    // Операторы арифметических действий с присваиванием
    Matrix& operator+=(const Matrix &other);
    Matrix& operator-=(const Matrix &other);
    Matrix& operator*=(real scalar); // Оставили умножение на число с присваиванием

    // Дружественные операторы для выполнения базовых матричных операций
    friend Matrix operator+(const Matrix &A, const Matrix &B);
    friend Matrix operator-(const Matrix &A, const Matrix &B);
    
    // Новые дружественные операторы умножения матрицы на число (возвращают новую матрицу)
    friend Matrix operator*(const Matrix &A, real scalar);
    friend Matrix operator*(real scalar, const Matrix &A);

    // Дружественные операторы для перегрузки ввода-вывода в потоки
    friend std::ostream& operator<<(std::ostream &os, const Matrix &M);
    friend std::istream& operator>>(std::istream &is, Matrix &M);
};
} // namespace math
