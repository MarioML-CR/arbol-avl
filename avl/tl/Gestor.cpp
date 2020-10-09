//
// Created by Mario Martinez on 30/09/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    arbolAVLA = new ArbinAVL();
    arbolAVLB = new ArbinAVL();
}

ArbinAVL *Gestor::getArbolAvlA() const {
    return arbolAVLA;
}

ArbinAVL *Gestor::getArbolAvlB() const {
    return arbolAVLB;
}

void Gestor::setArbolAvlB(ArbinAVL *arbolAvlb) {
    arbolAVLB = arbolAvlb;
}

void Gestor::setArbolAvlA(ArbinAVL *arbolAvl) {
    arbolAVLA = arbolAvl;
}
bool Gestor::insertarElem(int pValor) {
    return getArbolAvlA()->insertarElem(pValor);
}

int Gestor::pesoAVL() {
    return getArbolAvlA()->getPeso();
}

bool Gestor::esVacioAVL() {
    return getArbolAvlA()->esVacioAVL();
}


int Gestor::buscarMaximo() {
    return getArbolAvlA()->buscarMaximo();
}

int Gestor::buscarMinimo() {
    return getArbolAvlA()->buscarMinimo();
}

string Gestor::esHoja(int pValor) {
    if (getArbolAvlA()->esHoja(pValor)){
        return "El valor ingresado es hoja";
    } else {
        return "El valor ingresado no es hoja";
    }
}

int Gestor::nivel() {
    return getArbolAvlA()->nivel();
}

int Gestor::altura() {
    return getArbolAvlA()->altura();
}

int Gestor::numHojas() {
    return getArbolAvlA()->numHojas();
}

string Gestor::camino(int inicio, int final) {
    string camino = getArbolAvlA()->camino(inicio, final);
    if(camino.substr(camino.length()-1, camino.length()-1) == " "){
        camino = "No hay camino entre los valores ingresados\n";
    }
    return camino;
}

string Gestor::preOrden() {
    string preorden = getArbolAvlA()->preOrden();
    preorden = preorden.substr(0, preorden.length() - 3);
    return preorden;
}

string Gestor::inOrden() {
    string inOrden = getArbolAvlA()->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}

string Gestor::postOrden() {
    string postOrden = getArbolAvlA()->postOrden();
    postOrden = postOrden.substr(0, postOrden.length() - 3);
    return postOrden;
}

string Gestor::eliminarElemIzq(int pValor) {
    bool resultado = getArbolAvlA()->eliminarElem(pValor, 0);
    if (resultado){
        return "El elemento se eliminó satisfactoriamente\n";
    } else {
        return "El elemento No fue eliminado\n";
    }
}
string Gestor::eliminarElemDer(int pValor) {
    bool resultado = getArbolAvlA()->eliminarElem(pValor, 1);
    if (resultado){
        return "El elemento se eliminó satisfactoriamente\n";
    } else {
        return "El elemento No fue eliminado\n";
    }
}
string Gestor::esLleno() {
    bool esLleno = getArbolAvlA()->esLleno();
    if (esLleno){
        return "El árbol está lleno\n";
    } else {
        return "El árbol no está lleno\n";
    }
}
string Gestor::esCompleto() {
    bool completo = getArbolAvlA()->esCompleto();
    if (completo){
        return "El árbol está completo\n";
    } else {
        return "El árbol no está completo\n";
    }
}

bool Gestor::insertarElemB(int pValor) {
    return getArbolAvlB()->insertarElem(pValor);
}

string Gestor::sonArbolesIguales() {
    bool iguales = getArbolAvlA()->sonArbolesIguales(getArbolAvlB()->getRaiz());
    if (iguales){
        return "Son iguales\n";
    } else {
        return "No son iguales\n";
    }
}
string Gestor::sonArbolesSemejantes() {
    bool semejantes = getArbolAvlA()->sonArbolesSemejantes(getArbolAvlB()->getRaiz());
    if (semejantes){
        return "Son semejantes\n";
    } else {
        return "No son semejantes\n";
    }
}

string Gestor::sonArbolesIsomorfos() {
    bool semejantes = getArbolAvlA()->sonArbolesIsomorfos(getArbolAvlB()->getRaiz());
    if (semejantes){
        return "Son isomorfos\n";
    } else {
        return "No son isomorfos\n";
    }
}
