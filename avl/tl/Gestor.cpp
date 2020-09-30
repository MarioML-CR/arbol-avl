//
// Created by Mario Martinez on 30/09/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    arbolAVL = new ArbinAVL();
}

ArbinAVL *Gestor::getArbolAvl() const {
    return arbolAVL;
}

void Gestor::setArbolAvl(ArbinAVL *arbolAvl) {
    arbolAVL = arbolAvl;
}
bool Gestor::insertarElem(int pValor) {
    return getArbolAvl()->insertarElem(pValor);
}

int Gestor::pesoAVL() {
    return getArbolAvl()->getPeso();
}

bool Gestor::esVacioAVL() {
    return getArbolAvl()->esVacioAVL();
}


int Gestor::buscarMaximo() {
    return getArbolAvl()->buscarMaximo();
}

int Gestor::buscarMinimo() {
    return getArbolAvl()->buscarMinimo();
}

string Gestor::esHoja(int pValor) {
    if (getArbolAvl()->esHoja(pValor)){
        return "El valor ingresado es hoja";
    } else {
        return "El valor ingresado no es hoja";
    }
}

int Gestor::nivel() {
    return getArbolAvl()->nivel();
}

int Gestor::altura() {
    return getArbolAvl()->altura();
}

int Gestor::numHojas() {
    return getArbolAvl()->numHojas();
}

string Gestor::camino(int inicio, int final) {
    string camino = getArbolAvl()->camino(inicio, final);
    if(camino.substr(camino.length()-1, camino.length()-1) == " "){
        camino = "No hay camino entre los valores ingresados\n";
    }
    return camino;
}

string Gestor::preOrden() {
    string preorden = getArbolAvl()->preOrden();
    preorden = preorden.substr(0, preorden.length() - 3);
    return preorden;
}

string Gestor::inOrden() {
    string inOrden = getArbolAvl()->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}

string Gestor::postOrden() {
    string postOrden = getArbolAvl()->postOrden();
    postOrden = postOrden.substr(0, postOrden.length() - 3);
    return postOrden;
}

string Gestor::eliminarElem(int pValor) {
    bool resultado = getArbolAvl()->eliminarElem(pValor);
    if (resultado){
        return "El elemento se eliminó satisfactoriamente\n";
    } else {
        return "El elemento No fue eliminado\n";
    }
}