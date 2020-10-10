//
// Created by Mario Martinez on 30/09/20.
//

#ifndef ARBOL_AVL_ARBINAVL_H
#define ARBOL_AVL_ARBINAVL_H


#include "Nodo.h"
#include <iostream>
using namespace std;

class ArbinAVL {
public:
    ArbinAVL();

    virtual ~ArbinAVL();

    Nodo *getRaiz() const;

    void setRaiz(Nodo *raiz);

    int getPeso() const;

    void setPeso(int peso);

    int pesoAVL(); //Calcula el número de elementos del Arbin

    bool esVacioAVL(); //Retorna si un Arbin es vacío o no

    bool existeElemento(int); // Retorna verdadero si el elemento existe, y falso caso contrario.

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

    int buscarMaximo(); //Busca el elemento de mayor valor

    int buscarMinimo(); //Busca el elemento de menor valor

    bool esHoja(int); //Dice si un Arbin es hoja o no

    int nivel(); //Calcula del nivel de un Arbin

    int altura(); // calcula la altura del árbol.

    int numHojas(); //Calcula el número de hojas de un Arbin

    string camino(int, int); // Calcula el camino entre dos elementos del Arbin

    string preOrden(); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

    string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)

    bool eliminarElem(int, int); //Elimina un elemento del Arbin.

    bool esLleno(); //Retorna si un Arbin es completo o no

    bool esCompleto(); // Retorna si un Arbin es completo o no

    bool sonArbolesIguales(Nodo *); // Verifica si dos árboles son iguales

    bool sonArbolesSemejantes(Nodo *); // Verifica si dos árboles son semejantes

    bool sonArbolesIsomorfos(Nodo *); // Verifica si dos árboles son isomorfos

private:
    Nodo *raiz;
    int peso;

    bool insertarElemRecursivo(Nodo* , Nodo*, int, int); //Inserta un entero en el árbol ordenado.

    void insertarFE(Nodo*); // Inserta el factor de equilibrio en cada nodo.

    void balancearAVL(); // Modifica la estructura del árbol de forma que quede balanceado.

    void verificarValance(Nodo*); // Modifica la estructura del árbol de forma que quede balanceado.

    void rsd(Nodo*); // Modifica la estructura del árbol si fe = -2, y la raíz del sub árbol izq su fe = -1 ó 0

    void rdd(Nodo *); // Modifica la estructura del árbol si fe = -2, y la raíz del sub árbol der su fe = 1

    void rsi(Nodo*); // Modifica la estructura del árbol si fe = 2, y la raíz del sub árbol der su fe = 1 ó 0

    void rdi(Nodo *); // Modifica la estructura del árbol si fe = 2, y la raíz del sub árbol der su fe = -1

    Nodo *buscarNodo(Nodo*, int); // retorna el nodo del valor pasado por parámetro

    Nodo *buscarNodoDesbalance(Nodo*); // retorna el nodo del valor pasado por parámetro

    Nodo * nodoMaximo(Nodo*); //Busca el elemento de mayor valor

    Nodo *nodoMinimo(Nodo*); //Busca el elemento de menor valor

    int alturaFE(Nodo *); // Calcula el la altura de un nodo;

    int nivelRecursivo(Nodo*); //Calcula la nivel de un Arbin

    int numHojasRecursivo(Nodo*); //Calcula el número de hojas de un Arbin

    string caminoRecursivo(Nodo*, int); //Calcula el camino entre dos elementos del Arbin

    string preOrdenRecursivo(Nodo*); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

    string inOrdenRecursivo(Nodo*); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

    string postOrdenRecursivo(Nodo*); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)

    bool  eliminarNodo(Nodo *, int); // Elimina un nodo del árbol

    void  eliminarNodoPorIzq(Nodo *, Nodo *, Nodo *, Nodo *); // Elimina un nodo que tiene dos hijos por la izq

    void eliminarNodoPorDer(Nodo *, Nodo *, Nodo *, Nodo *); // Elimina un nodo que tiene dos hijos por la der

    int esCompletoRecursivo(Nodo *); // Retorna el número de nodos que presentan sólo un hijo

    int sonArbolesIsomorfosRecursivo(Nodo *, Nodo *); // Verifica si dos árboles son isomorfos

};


#endif //ARBOL_AVL_ARBINAVL_H
