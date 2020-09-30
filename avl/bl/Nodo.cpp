//
// Created by Mario Martinez on 30/09/20.
//

#include "Nodo.h"

Nodo::Nodo(int num) : num(num), fe(0), izq(nullptr), der(nullptr), padre(nullptr) {}

Nodo::~Nodo() {

}

int Nodo::getNum() const {
    return num;
}

void Nodo::setNum(int num) {
    Nodo::num = num;
}

int Nodo::getFe() const {
    return fe;
}

void Nodo::setFe(int fe) {
    Nodo::fe = fe;
}

Nodo *Nodo::getIzq() const {
    return izq;
}

void Nodo::setIzq(Nodo *izq) {
    Nodo::izq = izq;
}

Nodo *Nodo::getDer() const {
    return der;
}

void Nodo::setDer(Nodo *der) {
    Nodo::der = der;
}

Nodo *Nodo::getPadre() const {
    return padre;
}

void Nodo::setPadre(Nodo *padre) {
    Nodo::padre = padre;
}
