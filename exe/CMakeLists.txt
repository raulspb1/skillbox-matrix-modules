cmake_minimum_required(VERSION 3.10)
project(MatrixExecutable CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Объявление внешней целевой библиотеки как общей (динамической) и импортируемой
add_library(imported_matrix SHARED IMPORTED)

# 2. Определение пути к предварительно скомпилированному бинарному файлу .so
set_target_properties(imported_matrix PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/matrixlib/libmatrixlib.so"
)

# 3. Конфигурация исполняемого файла приложения
add_executable(matrix_app main.cpp)

# 4. Компоновка исполняемого файла с импортированным целевым объектом библиотеки
target_link_libraries(matrix_app PRIVATE imported_matrix)
