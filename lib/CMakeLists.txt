cmake_minimum_required(VERSION 3.10)
project(MatrixLibrary CXX)

# Установка стандарта C++ и обязательности его поддержки
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Генерация динамической (разделяемой) библиотеки из исходных файлов
add_library(matrixlib SHARED 
    src/matrix.cpp
    src/c_api.cpp
)

# Определение путей поиска заголовочных файлов для компиляции и экспорта
target_include_directories(matrixlib PUBLIC src)
