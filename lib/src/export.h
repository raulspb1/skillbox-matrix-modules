#pragma once

#ifndef MATRIXLIB_EXPORT
    // Определение макроса экспорта функций для разделяемых библиотек в операционных системах семейства Linux (GCC)
    #define MATRIXLIB_EXPORT __attribute__((visibility("default")))
#endif
