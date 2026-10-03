#include <src/matrix.h>
#include <iostream>

namespace math
{
real& Matrix::operator()(int row, int col)
{
    if(row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
    }
    if(col >= this->cols_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
    }

    int pos{0};
    pos = cols_ * row + col;
    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col) const
{
    if(row >= this->rows_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
    }
    if(col >= this->cols_)
    {
        std::cerr << "Matrix: row number out of bounds" << std::endl;
    }

    int pos{0};
    pos = cols_ * row + col;
    return this->mvec_.at(pos);
}

void Matrix::print()
{
    for(int i = 0; i < this->rows_; ++i)
    {
        for (int j = 0; j < this->cols_; ++j)
        {
            std::cout << this->mvec_.at(cols_ * i + j) << " ";
        }
        std::cout << std::endl;
    }
}

Matrix operator+(const Matrix &A, const Matrix &B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be added!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.rows_, A.cols_);

    for(int i = 0; i < M.mvec_.size(); ++i)
    {
        M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
    }

    return M;
}

Matrix operator-(const Matrix &A, const Matrix &B)
{
    if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
    {
        std::cerr << "Matrix: Matrices can't be subtracted!" << std::endl;
        return Matrix(0, 0);
    }

    Matrix M(A.rows_, A.cols_);

    for(int i = 0; i < M.mvec_.size(); ++i)
    {
        M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
    }

    return M;
}

// Реализация обычного умножения: Матрица * Число
Matrix operator*(const Matrix &A, real scalar)
{
    Matrix result = A; 
    result *= scalar;  // Переиспользуем ваш operator*=
    return result;     
}

// Реализация обычного умножения: Число * Матрица
Matrix operator*(real scalar, const Matrix &A)
{
    return A * scalar; // Просто вызываем вариант (Матрица * Число)
}

// Реализация оператора сложения с присваиванием
Matrix& Matrix::operator+=(const Matrix &other)
{
    if ((this->rows_ != other.rows_) || (this->cols_ != other.cols_))
    {
        std::cerr << "Matrix error: Dimensions must match for operator+=" << std::endl;
        return *this;
    }

    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) += other.mvec_.at(i);
    }

    return *this;
}

// Реализация оператора вычитания с присваиванием
Matrix& Matrix::operator-=(const Matrix &other)
{
    if ((this->rows_ != other.rows_) || (this->cols_ != other.cols_))
    {
        std::cerr << "Matrix error: Dimensions must match for operator-=" << std::endl;
        return *this;
    }

    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) -= other.mvec_.at(i);
    }

    return *this;
}

// Реализация оператора умножения матрицы на число с присваиванием
Matrix& Matrix::operator*=(real scalar)
{
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) *= scalar;
    }

    return *this;
}

// Перегрузка оператора вывода матрицы в поток
std::ostream& operator<<(std::ostream &os, const Matrix &M)
{
    for (int i = 0; i < M.rows_; ++i)
    {
        for (int j = 0; j < M.cols_; ++j)
        {
            os << M.mvec_.at(M.cols_ * i + j) << " ";
        }
        os << std::endl;
    }
    return os;
}

// Перегрузка оператора ввода элементов матрицы из потока
std::istream& operator>>(std::istream &is, Matrix &M)
{
    for (int i = 0; i < M.rows_; ++i)
    {
        for (int j = 0; j < M.cols_; ++j)
        {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            is >> M.mvec_.at(M.cols_ * i + j);
        }
    }
    return is;
}

} // namespace math
