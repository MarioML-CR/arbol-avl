//
// Created by Mario Martinez on 30/09/20.
//

#include "ArbinAVL.h"

ArbinAVL::ArbinAVL(): raiz(nullptr), peso(0) {}

ArbinAVL::~ArbinAVL() {

}

Nodo *ArbinAVL::getRaiz() const {
    return raiz;
}

void ArbinAVL::setRaiz(Nodo *raiz) {
    ArbinAVL::raiz = raiz;
}

int ArbinAVL::getPeso() const {
    return peso;
}

void ArbinAVL::setPeso(int peso) {
    ArbinAVL::peso = peso;
}

int ArbinAVL::pesoAVL() {
    return 0;
}

bool ArbinAVL::esVacioAVL() {
    return false;
}

bool ArbinAVL::insertarElem(int) {
    return false;
}

bool ArbinAVL::insertarElemRecursivo(Nodo *, Nodo *, int, int) {
    return false;
}

int ArbinAVL::buscarMaximo() {
    return 0;
}

Nodo *ArbinAVL::nodoMaximo(Nodo *) {
    return nullptr;
}

int ArbinAVL::buscarMinimo() {
    return 0;
}

Nodo *ArbinAVL::nodoMinimo(Nodo *) {
    return nullptr;
}

bool ArbinAVL::esHoja(int) {
    return false;
}

int ArbinAVL::nivel() {
    return 0;
}
int ArbinAVL::nivelRecursivo(Nodo *) {
    return 0;
}
int ArbinAVL::altura() {
    return 0;
}

int ArbinAVL::numHojas() {
    return 0;
}

int ArbinAVL::numHojasRecursivo(Nodo *) {
    return 0;
}

string ArbinAVL::camino(int, int) {
    return std::string();
}

string ArbinAVL::caminoRecursivo(Nodo *, int) {
    return std::string();
}

string ArbinAVL::preOrden() {
    return std::string();
}

string ArbinAVL::preOrdenRecursivo(Nodo *) {
    return std::string();
}

string ArbinAVL::inOrden() {
    return std::string();
}

string ArbinAVL::inOrdenRecursivo(Nodo *) {
    return std::string();
}

string ArbinAVL::postOrden() {
    return std::string();
}

string ArbinAVL::postOrdenRecursivo(Nodo *) {
    return std::string();
}

bool ArbinAVL::eliminarElem(int) {
    return false;
}




