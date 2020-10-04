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

    ArbinAVL *getArbolAvl() const;

    void setArbolAvl(ArbinAVL *arbolAvl);

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

    string eliminarElem(int); //Elimina un elemento del Arbin.

private:
    ArbinAVL *arbolAVL;
};


#endif //ARBOL_AVL_GESTOR_H
