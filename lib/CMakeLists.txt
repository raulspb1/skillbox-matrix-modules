cmake_minimum_required(VERSION 3.10)
project(MatrixLibrary CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Сборка динамической (разделяемой) библиотеки из исходных файлов модуля lib
add_library(matrixlib SHARED 
    src/matrix.cpp
    src/c_api.cpp
)

# Определение путей поиска заголовочных файлов
target_include_directories(matrixlib PUBLIC src)
