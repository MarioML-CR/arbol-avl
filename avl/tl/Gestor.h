//
// Created by Mario Martinez on 30/09/20.
//

#ifndef ARBOL_AVL_GESTOR_H
#define ARBOL_AVL_GESTOR_H


#include "../bl/ArbinAVL.h"
#include <iostream>
using namespace std;

class Gestor {
public:
    Gestor();

    ArbinAVL *getArbolAvlA() const;

    void setArbolAvlA(ArbinAVL *arbolAvl);

    ArbinAVL *getArbolAvla() const;

    void setArbolAvla(ArbinAVL *arbolAvla);

    ArbinAVL *getArbolAvlB() const;

    void setArbolAvlB(ArbinAVL *arbolAvlb);

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

    int pesoAVL(); //Calcula el número de elementos del Arbin

    bool esVacioAVL(); //Retorna si un Arbin es vacío o no

    int buscarMaximo(); //Busca el elemento de mayor valor

    int buscarMinimo(); //Busca el elemento de menor valor

    string esHoja(int); //Dice si un Arbin es hoja o no

    int nivel(); //Calcula del nivel de un Arbin

    int altura(); // calcula la altura del árbol.

    int numHojas(); //Calcula el número de hojas de un Arbin

    string camino(int, int); // Calcula el camino entre dos elementos del Arbin

    string preOrden(); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

    string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)

    string eliminarElemIzq(int); //Elimina un elemento del Arbin.

    string eliminarElemDer(int); //Elimina un elemento del Arbin.

    string esLleno(); //Retorna si un Arbin es completo o no

    string esCompleto(); // Retorna si un Arbin es completo o no

    bool insertarElemB(int); //Inserta un entero en el árbol ordenado.

    string sonArbolesIguales(); // Verifica si dos árboles son iguales

    string sonArbolesSemejantes(); // Verifica si dos árboles son semejantes

    string sonArbolesIsomorfos(); // Verifica si dos árboles son isomorfos

private:
    ArbinAVL *arbolAVLA;

    ArbinAVL *arbolAVLB;
};


#endif //ARBOL_AVL_GESTOR_H
