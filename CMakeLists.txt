cmake_minimum_required(VERSION 3.17)
project(arbol_avl)

set(CMAKE_CXX_STANDARD 20)

add_executable(arbol_avl avl/ui/main.cpp avl/bl/Nodo.cpp avl/bl/Nodo.h avl/bl/ArbinAVL.cpp avl/bl/ArbinAVL.h avl/tl/Gestor.cpp avl/tl/Gestor.h avl/utilitario/Validar.cpp avl/utilitario/Validar.h)