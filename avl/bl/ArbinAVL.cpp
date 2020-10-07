//
// Created by Mario Martinez on 30/09/20.
//

#include "ArbinAVL.h"
/**
 * Método:          ArbinAVL
 * Descripción:     constructor de la clase ArbinAVL (Árbol binario o de búsquda AVL)
 * que inicializa de los parámetros.
 */
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
/**
 * Método:          pesoAVL
 * Descripción:     método que permite obtener el peso del árbol binario AVL
 * @return          variable de tipo int que representa el número de
 * elementos que tiene el árbol AVL.
 */
int ArbinAVL::pesoAVL() {
    return getPeso();
}
/**
 * Método:          esVacioAVL
 * Descripción:     Método que permite verificar si el árbol AVL está vacío o no
 * @return          variable de tipo booleana, si es vacia retorna true, y
 * false en caso contrario.
 */
bool ArbinAVL::esVacioAVL() {
    if (getPeso()==0){
        return true;
    } else {
        return false;
    }
}
/**
 * Método:          existeElemento
 * Descripción:     Método que verifica si un elemento ya existe en el árbol
 * @param pValor    variable de tipo int que representa el elemento que se debe
 * buscar en el árbol.
 * @return          variable de tipo bool, si existe retorna true, false caso contrario
 */
bool ArbinAVL::existeElemento(int pValor) {
    if (getPeso()==0){
        return false;
    } else {
        Nodo * aux = buscarNodo(getRaiz(), pValor);
        if (aux == nullptr){
            return false;
        } else {
            return true;
        }

    }
}

/**
 * Método:              insertarElem
 * Descripción:         Método que permite enviar a insertar el valor al árbol AVL
 * @param pValor        representa el valor a ingresar al árbol
 * @return              varible de tipo bool (true) indicando que se cargó correctamente.
 */
bool ArbinAVL::insertarElem(int pValor) {
    bool existe = existeElemento(pValor);
    if (!existe){
        bool insercion = insertarElemRecursivo(getRaiz(), new Nodo(), pValor ,0);
        if (insercion){
            insertarFE(getRaiz());
            balancearAVL();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
/**
 * Método:              insertarElemRecursivo
 * Descripción:         Método que permite hacer la inserción de un arbol binario AVL
 * @param nodo          representa el nodo raiz,
 * @param nodoPadre      representa el nodo hijo
 * @param pValor        representa el valor a insertar, variable de tipo int
 * @param tipo          representa el tipo de hijo, 1 es izquierdo y 2 es derecho.
 */
bool ArbinAVL::insertarElemRecursivo(Nodo *nodo, Nodo *nodoPadre, int pValor, int tipo) {
    if (nodo == nullptr){
        nodo = new Nodo(pValor);
        if(getPeso()== 0){
            setRaiz(nodo);
        } else if (tipo == 1){
            nodoPadre->setIzq(nodo);
            nodo->setPadre(nodoPadre);
        } else if (tipo == 2) {
            nodoPadre->setDer(nodo);
            nodo->setPadre(nodoPadre);
        }
        setPeso(getPeso() + 1);
    } else if (pValor < nodo->getNum()){
        insertarElemRecursivo(nodo->getIzq(), nodo, pValor, 1);
    } else if (pValor > nodo->getNum()) {
        insertarElemRecursivo(nodo->getDer(), nodo, pValor, 2);
    }
    return true;
}
/**
 * Método:              insertarFE
 * Descripción:         Método recursivo que permite insertar el factor de equilibrio (fe)
 * a cada nodo.
 * @param nodo          variable de tipo nodo que representa a la raíz del árbol.
 */
void ArbinAVL::insertarFE(Nodo * nodo) {
    if (nodo == nullptr){
        return;
    } else if (esHoja(nodo->getNum())){
        nodo->setFe(0);
    } else {
        insertarFE(nodo->getIzq());
        insertarFE(nodo->getDer());
        nodo->setFe(alturaFE(nodo->getDer()) - alturaFE(nodo->getIzq()));
    }
}
/**
 * Método:              balancearAVL
 * Descripción:         Método que verifica si el árbol se encuentra balanceado,
 * y en caso de no se así, procede a balancearlo llamando los métodos respectivos.
 * @param nodo          representa el nodo raiz,
 */
void ArbinAVL::balancearAVL() {
    Nodo * aux = buscarNodoDesbalance(getRaiz());
    if (aux != nullptr){
        if (aux->getFe() == 2 && aux->getDer()->getFe() == -1){
            rdi(aux);
            insertarFE(getRaiz());
        } else if (aux->getFe() == 2 && aux->getDer()->getFe() == 1 ||
                   aux->getFe() == 2 && aux->getDer()->getFe() == 0) {
            rsi(aux);
            insertarFE(getRaiz());
        } else if (aux->getFe() == -2 && aux->getIzq()->getFe() == 1){
            rdd(aux);
            insertarFE(getRaiz());
        } else if (aux->getFe() == -2 && aux->getIzq()->getFe() == -1 ||
                   aux->getFe() == -2 && aux->getIzq()->getFe() == 0) {
            rsd(aux);
            insertarFE(getRaiz());
        }
    }
}
/**
 * Método:              rsd
 * Descripción:         (rotación simple derecha) Método que permite rotar las
 * posiciones de un árbol cuando su fe (factor de equilibrio) sea dos unidades más alto
 * que el derecho; es decir, que su fe = -2; y ademas, la raíz del sub árbol izquierdo
 * tenga un factor de equilibrio (fe) = -1 ó 0; es decir, que esté cargado a la izquierda.
 * @param nodo          variable de tipo nodo que representa el nodo que debe ser reequilibrado
 * @return              variable de tipo nodo que representa ...
 */
void ArbinAVL::rsd(Nodo * nodo) {
    Nodo *p = nodo;
    Nodo *q = nodo->getIzq();
    Nodo * b = q->getDer();
    Nodo *padre = nodo->getPadre();
    p->setIzq(b);
    if (b != nullptr){
        b->setPadre(p);
    }
    q->setDer(p);
    p->setPadre(q);
    if (nodo == getRaiz()){
        setRaiz(q);
        q->setPadre(nullptr);
    } else {

        if (padre->getDer() == nodo){
            padre->setDer(q);
        } else {
            padre->setIzq(q);
        }
        q->setPadre(padre);
    }
}
/**
 * Método:              rdd
 * Descripción:         (rotación doble derecha) Método que permite rotar las
 * posiciones de un árbol cuando su fe (factor de equilibrio) sea dos unidades más alto
 * que el derecho; es decir, que su fe = -2; y ademas, la raíz del sub árbol izquierdo
 * tenga un factor de equilibrio (fe) = 1; es decir, que esté cargado a la derecha.
 * @param nodo          variable de tipo nodo que representa el nodo que debe ser reequilibrado
 * @return              variable de tipo nodo que representa el nodo que ha sido equilibrado
 */
void ArbinAVL::rdd(Nodo * nodo) {
    Nodo *p = nodo;
    Nodo *q = nodo->getIzq();
    Nodo *r = q->getDer();
    Nodo * c = r->getDer();
    Nodo * b = r->getIzq();
    Nodo *padre = nodo->getPadre();
    p->setIzq(c);
    if (c != nullptr){
        c->setPadre(p);
    }
    r->setDer(p);
    p->setPadre(r);
    r->setIzq(q);
    q->setPadre(r);
    q->setDer(b);
    if (b != nullptr){
        b->setPadre(q);
    }
    if (nodo == getRaiz()){
        setRaiz(r);
        r->setPadre(nullptr);
    } else {
        if (padre->getDer() == nodo){
            padre->setDer(r);
        } else {
            padre->setIzq(r);
        }
        r->setPadre(padre);
    }
}
/**
 * Método:              rsi
 * Descripción:         (rotación simple izquierda) Método que permite rotar las
 * posiciones de un árbol cuando su fe (factor de equilibrio) sea dos unidades más alto
 * que el izquierdo; es decir, que su fe = 2; y ademas, la raíz del sub árbol derecho
 * tenga un factor de equilibrio (fe) = 1 ó 0; es decir, que esté cargado a la derecha.
 * @param nodo          variable de tipo nodo que representa el nodo que debe ser reequilibrado
 * @return              variable de tipo nodo que representa el nodo que ha sido equilibrado
 */
void ArbinAVL::rsi(Nodo * nodo) {
    Nodo *p = nodo;
    Nodo *q = nodo->getDer();
    Nodo * b = p->getDer()->getIzq();
    Nodo *padre = nodo->getPadre();
    p->setDer(b);
    if (b != nullptr){
        b->setPadre(p);
    }
    q->setIzq(p);
    p->setPadre(q);
    if (nodo == getRaiz()){
        setRaiz(q);
        q->setPadre(nullptr);
    } else {
        if (padre->getDer() == nodo){
            padre->setDer(q);
        } else {
            padre->setIzq(q);
        }
        q->setPadre(padre);
    }
}
/**
 * Método:              rdi
 * Descripción:         (rotación doble izquierda) Método que permite rotar las
 * posiciones de un árbol cuando su fe (factor de equilibrio) sea dos unidades más alto
 * que el izquierdo; es decir, que su fe = 2; y ademas, la raíz del sub árbol derecho
 * tenga un factor de equilibrio (fe) = -1; es decir, que esté cargado a la izquierda.
 * @param nodo          variable de tipo nodo que representa el nodo que debe ser reequilibrado
 * @return              variable de tipo nodo que representa el nodo que ha sido equilibrado
 */
void ArbinAVL::rdi(Nodo * nodo) {
    Nodo *p = nodo;
    Nodo *q = nodo->getDer();
    Nodo *r = q->getIzq();
    Nodo * c = r->getDer();
    Nodo * b = r->getIzq();
    Nodo *padre = nodo->getPadre();
    p->setDer(b);
    if (b != nullptr){
        b->setPadre(p);
    }
    r->setDer(q);
    q->setPadre(r);
    r->setIzq(p);
    p->setPadre(r);
    q->setIzq(c);
    if(c != nullptr){
        c->setPadre(q);
    }
    if (nodo == getRaiz()){
        setRaiz(r);
        r->setPadre(nullptr);
    } else {

        if (padre->getDer() == nodo){
            padre->setDer(r);
        } else {
            padre->setIzq(r);
        }
        r->setPadre(padre);
    }
}
/**
 * Método:              buscarMaximo
 * Descripción:         Método que permite buscar el valor máximo en el árbol AVL
 * @return              variable de tipo int que representa el valor máximo del árbol
 */
int ArbinAVL::buscarMaximo() {
    Nodo *max = nodoMaximo(getRaiz());
    if (max == nullptr){
        return -99999;
    } else {
        return max->getNum();
    }
}
/**
 * Método:              nodoMaximo
 * Descripción:         Método recursivo que permite retornar el nodo que contiene el
 * valor máximo en el árbol AVL
 * @param nodo          variable de tipo nodo que representa el nodo raíz
 * @return              variable de tipo int que representa el valor máximo del árbol AVL
 */
Nodo *ArbinAVL::nodoMaximo(Nodo * nodo) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getDer() != nullptr){
            return nodoMaximo(nodo->getDer());
        } else {
            return nodo;
        }
    }
}
/**
 * Método:              buscarMinimo
 * Descripción:         Método que permite buscar el valor mínimo en el árbol AVL
 * @return              variable de tipo int que representa el valor mínimo del árbol
 */
int ArbinAVL::buscarMinimo() {
    Nodo *min = nodoMinimo(getRaiz());
    if (min == nullptr){
        return -99999;
    } else {
        return min->getNum();
    }
}
/**
 * Método:              nodoMinimo
 * Descripción:         Método recursivo que permite retornar el nodo con el valor mínimo
 * correspondiente al nodo recibido por parámetro.
 * @param nodo          variable de tipo nodo que representa el nodo raíz
 * @return              variable de tipo int que representa el valor mínimo del árbol
 */
Nodo *ArbinAVL::nodoMinimo(Nodo * nodo) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getIzq() != nullptr){
            return nodoMinimo(nodo->getIzq());
        } else {
            return nodo;
        }
    }
}
/**
 * Método:              buscarNodo
 * Descripción:         Método recursivo que permite retornar el nodo en el cual
 * se ubica el valor recibido como parámetro, o un nodo nulo si es que no hay
 * ningún nodo que contenga este valor.
 * @param pValor        variable de tipo int que representa el valor a buscar
 * @return              variable de tipo nodo que representa el nodo donde se ubica
 * el valor a buscar
 */
Nodo *ArbinAVL::buscarNodo(Nodo * nodo, int pValor) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getNum() == pValor){
            return nodo;
        } else if (nodo->getNum() > pValor) {
            return buscarNodo(nodo->getIzq(), pValor);
        } else {
            return buscarNodo(nodo->getDer(), pValor);
        }
    }
}
/**
 * Método:              buscarNodoDesbalance
 * Descripción:         Método recursivo que permite retornar el nodo en el cual ubica
 * el factor de equilibio (fe) igual a 2 ó -2
 * @param nodo          variable de tipo nodo que representa la raíz del árbol
 * @return              variable de tipo nodo que representa el nodo donde se ubica
 * el fe = 2 ó -2.
 */
// TODO: MML solucionar
Nodo *ArbinAVL::buscarNodoDesbalance(Nodo *nodo) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if ((nodo->getFe() == 2 &&
        (nodo->getDer()->getFe() == 0 || nodo->getDer()->getFe() == 1 || nodo->getDer()->getFe() == -1)) ||
            nodo->getFe() == -2 &&
            (nodo->getIzq()->getFe() == 0 || nodo->getIzq()->getFe() == 1 || nodo->getIzq()->getFe() == -1) ) {
            return nodo;
        } else {
            buscarNodoDesbalance(nodo->getIzq());
            return buscarNodoDesbalance(nodo->getDer());
        }
    }
}

/**
 * Método:              esHoja
 * Descripción:         Método que permite establecer si al valor ingresado
 * es hoja o no, si no existe en el arbol o si no hay datos en el árbol AVL.
 * @param pValor        valor que representa el valor a buscar en el árbol.
 * @return              variable de tipo string con el resultado de la búsqueda.
 */
bool ArbinAVL::esHoja(int pValor) {
    if (getRaiz() == nullptr){
        return false;
    } else {
        Nodo *nodo = buscarNodo(getRaiz(), pValor);
        if (nodo == nullptr){
            return false;
        } else if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr){
            return true;
        } else {
            return false;
        }
    }
}
/**
 * Método:              nivel
 * Descripción:         Método que permite obtener el nivel del árbol a travéz
 * del método privado recursivo.
 * @return              variable de tipo int que representa el nivel del árbol.
 */
int ArbinAVL::nivel() {
    return nivelRecursivo(getRaiz());
}
/**
 * Método:              nivelRecursivo
 * Descripción:         Método que permite recorrer el árbol de forma recursiva
 * para obtener el nivel del árbol.
 * @param nodo          varible de tipo Nodo que respresenta cada nivel.
 * @return              variable de tipo int que representa el nivel del árbol.
 */
int ArbinAVL::nivelRecursivo(Nodo * nodo) {
    int a, b;
    if (nodo == nullptr){
        return -1;
    } else {
        a = nivelRecursivo(nodo->getIzq());
        b = nivelRecursivo(nodo->getDer());
        if (a > b){
            return a + 1;
        } else {
            return b + 1;
        }
    }
}
/**
 * Método:              altura
 * Descripción:         Método que permite establecer la altura el árbol
 * @return              variable de tipo int que representa la altura del árbol
 */
int ArbinAVL::altura() {
    return nivel() + 1;
}
/**
 * Método:              alturaFE
 * Descripción:         Método recursivo que permite establecer la altura del nodo
 * recibido por parámetro.
 * @param nodo          varible de tipo Nodo que respresenta el hijo del nodo que se
 * está evaluanco.
 * @return              variable de tipo int que representa la altura del nodo hijo
 * que se está evaluando
 */
int ArbinAVL::alturaFE(Nodo * nodo) {
    int altura = nivelRecursivo(nodo);
    return  altura + 1;
}

/**
 * Método:              numHojas
 * Descripción:         Método que permite establecer el número de hojas del árbol
 * @return              variable de tipo int que representa el número hojas del árbol
 */
int ArbinAVL::numHojas() {
    return numHojasRecursivo(getRaiz());
}
/**
 * Método:              numHojasRecursivo
 * Descripción:         Método recursivo que permite establecer el número de hojas del
 * árbol.
 * @param nodo          varible de tipo nodo que representa la raíz del árbol
 * @return              variable de tipo int que representa el número hojas del árbol
 */
int ArbinAVL::numHojasRecursivo(Nodo * nodo) {
    if (nodo == nullptr){
        return 0;
    } else {
        if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr){
            return 1;
        } else {
            return numHojasRecursivo(nodo->getIzq()) + numHojasRecursivo(nodo->getDer());
        }
    }
}
/**
 * Método:              camino
 * Descripción:         Método que permite generar el camino del árbol entre dos de sus puntos
 * @param pValorInicial variable de tipo int que representa el valor del nodo inicial a partir
 * del cual se establecerá el camino.
 * @param pValorFinal   variable de tipo int que representa el valor del nodo final a partir
 * del cual se establecerá el camino.
 * @return              variable de tipo string que representa el camino del árbol.
 */
string ArbinAVL::camino(int pValorInicial, int pValorFinal) {
    Nodo *inicial = buscarNodo(getRaiz(), pValorInicial);
    Nodo *final = buscarNodo(getRaiz(), pValorFinal);
    if (inicial == nullptr || final == nullptr){
        return "Al menos uno de los valores ingresados no existe en el árbol";
    } else if(pValorInicial == pValorFinal) {
        return "No hay camino entre los valores ingresados";
    }
    else {
        return caminoRecursivo(inicial, pValorFinal);
    }
}
/**
 * Método:              caminoRecursivo
 * Descripción:         Método recursivo que permite establecer el camino entre el valor
 * que contiene el nodo inicial y el valor final recibido como parámetro
 * @param nodo          varible de tipo nodo que representa al nodo que contiene el valor
 * inicial
 * @param pValorFinal   variable de tipo int que representa el valor final del camino.
 * @return              variable de tipo string que representa el camino del árbol.
 */
string ArbinAVL::caminoRecursivo(Nodo *nodo, int pValorFinal) {
    string camino;
    if (getRaiz() == nullptr){
        camino = "El árbol está vacío";
    } else if (nodo == nullptr){
        return "";
    } else if (nodo->getNum() == pValorFinal){
        camino = to_string(nodo->getNum());
    }
    else {
        if (nodo->getNum() > pValorFinal){
            Nodo *aux = nodo->getIzq();
            camino = to_string(nodo->getNum()) + " - " + caminoRecursivo(aux, pValorFinal);
        } else if (nodo->getNum() < pValorFinal){
            Nodo *aux = nodo->getDer();
            camino = to_string(nodo->getNum()) + " - " + caminoRecursivo(aux, pValorFinal);
        }
    }
    return camino;
}
/**
 * Método:              preOrden
 * Descripción:         Método recursivo que permite mostrar el recorrido
 * del árbol en pre-orden.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::preOrden() {
    return preOrdenRecursivo(getRaiz());
}
/**
 * Método:              preOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el
 * árbol siguiendo el esquema: se recorre la raíz, en pre-orden el subárbol
 * izquierdo, y en preorden el subárbol derecho.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::preOrdenRecursivo(Nodo * nodo) {
    string preorden;
    if (nodo != nullptr){
        preorden = to_string(nodo->getNum()) + " - ";
        preorden += preOrdenRecursivo(nodo->getIzq());
        preorden += preOrdenRecursivo(nodo->getDer());
    }
    return preorden;
}
/**
 * Método:              inOrden
 * Descripción:         Método recursivo que permite mostrar el recorrido
 * del árbol in-orden.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::inOrden() {
    return inOrdenRecursivo(getRaiz());
}
/**
 * Método:              inOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el
 * árbol siguiendo la secuencia se recorre en in-orden el subárbol izquierdo,
 * se recorre la raíz, y se recore en in-orden el subárbol derecho.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::inOrdenRecursivo(Nodo * nodo) {
    string inOrden;
    if (nodo != nullptr){
        inOrden = inOrdenRecursivo(nodo->getIzq());
        inOrden += to_string(nodo->getNum()) + " - ";
        inOrden += inOrdenRecursivo(nodo->getDer());
    }
    return inOrden;
}
/**
 * Método:              postOrden
 * Descripción:         Método que permite mostrar el recorrido del
 * árbol en post-orden (izquierda - derecha - raíz)
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::postOrden() {
    return postOrdenRecursivo(getRaiz());
}
/**
 * Método:              postOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el árbol
 * siguiendo la secuencia recorre en post-orden el subárbol izquierdo,
 * se recorre en post-orden el subárbol derecha, se recorre la raíz.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string ArbinAVL::postOrdenRecursivo(Nodo * nodo) {
    string postOrden;
    if (nodo != nullptr){
        postOrden = postOrdenRecursivo(nodo->getIzq());
        postOrden += postOrdenRecursivo(nodo->getDer());
        postOrden += to_string(nodo->getNum()) + " - ";
    }
    return postOrden;
}
/**
 * Método:              eliminarElem
 * Descripción:         Método que permite eliminar un elemento del árbol
 * @param pValor        variable de tipo int que representa el valor a eliminar
 * @param tipo          variable de tipo int que representa la forma de eliminar en caso
 * que el nodo a eliminar tenga dos hijos; si es 0 elimina por la izquierda, y si es 1
 * elimina por la derecha.
 * @return              variable de tipo bool (true si lo eliminó, falso caso contrario)
 */
bool ArbinAVL::eliminarElem(int pValor, int tipo) {
    Nodo * nodo = buscarNodo(getRaiz(),pValor);
    if (nodo == nullptr){
        return false;
    } else {
        bool eliminar = eliminarNodo(nodo, tipo);
        if (eliminar && getRaiz() != nullptr){
            insertarFE(getRaiz());
            balancearAVL();
        }
        return true;
    }
}

/**
 * Método:              eliminarNodo
 * Descripción:         Método que permite eliminar un elemento del árbol
 * utilizando la opción de eliminar por la izquierda cuando el elemento a
 * eliminar presenta dos ramas
 * @param nodo          variable de tipo no que representa el nodo del elemento
 * a eliminar
 * @param tipo          variable de tipo int que representa la forma de eliminar en caso
 * que el nodo a eliminar tenga dos hijos; si es 0 elimina por la izquierda, y si es 1
 * elimina por la derecha.
 * @return              variable de tipo bool si se eliminó retorna true, false
 * caso contrario.
 */
bool ArbinAVL::eliminarNodo(Nodo * nodo, int tipo) {
    Nodo * a = nodo->getPadre(); // nodo padre del elemento a eliminar
    Nodo * b = nodo; // nodo del elemento a eliminar
    Nodo * c = b->getIzq(); // nodo izquierdo del elemento a eliminar
    Nodo * d = b->getDer(); // nodo derecho del elemento a eliminar
    if (b->getIzq() != nullptr & b->getDer() != nullptr){ // tiene dos hojas
        if (tipo == 0){
            eliminarNodoPorIzq(a,b,c,d);
        } else {
            eliminarNodoPorDer(a,b,c,d);
        }
    } else if (b->getIzq() != nullptr & b->getDer() == nullptr ||
            b->getIzq() == nullptr & b->getDer() != nullptr){ // tiene una hoja, izquierda o derecha caso 4 y 5
        if (b == getRaiz()){
            setRaiz(c);
        } else {
            if (a->getIzq() == b){
                a->setIzq(d);
            } else {
                a->setDer(c);
            }
        }
    } else { // es hoja caso 6
        if (b == getRaiz()){ // es raíz
            setRaiz(nullptr);
        } else { // no es raíz
            if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
                a->setIzq(nullptr);
            } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
                a->setDer(nullptr);
            }
        }
    }
    setPeso(getPeso() - 1);
    delete b;
    return true;
}
/**
 * Método:              eliminarNodoPorIzq
 * Descripción:         Método que permite eliminar un nodo que tiene dos hijos y la
 * eliminación es por la izquierda.
 * @param a             variable de tipo Nodo que representa el nodo padre del elemento a eliminar
 * @param b             variable de tipo Nodo que representa el nodo a eliminar
 * @param c             variable de tipo Nodo que representa el nodo izquierdo del elemento a eliminar
 * @param d             variable de tipo Nodo que representa el nodo derecho del elemento a eliminar
 */
void ArbinAVL::eliminarNodoPorIzq(Nodo * a, Nodo * b, Nodo * c, Nodo * d) {
    Nodo * f = nodoMaximo(c); // nodo máximo por la izquierda
    Nodo * e = f->getPadre(); // nodo padre del nodo máximo
    Nodo * g = f->getIzq(); // nodo izquierdo del nodo máximo
    if (b == getRaiz()){
        setRaiz(f);
    } else {
        if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
            a->setIzq(f);
        } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
            a->setDer(f);
        }
    }
    f->setDer(d);
    if (b == e && c == f){ // caso 1
        f->setIzq(g);
    } else { // caso 2 y 3
        f->setIzq(c);
        e->setDer(g);
    }
}
/**
 * Método:              eliminarNodoPorDer
 * Descripción:         Método que permite eliminar un nodo que tiene dos hijos y la
 * eliminación es por la derecha.
 * @param a             variable de tipo Nodo que representa el nodo padre del elemento a eliminar
 * @param b             variable de tipo Nodo que representa el nodo a eliminar
 * @param c             variable de tipo Nodo que representa el nodo izquierdo del elemento a eliminar
 * @param d             variable de tipo Nodo que representa el nodo derecho del elemento a eliminar
 */
void ArbinAVL::eliminarNodoPorDer(Nodo * a, Nodo * b, Nodo * c, Nodo * d) {
    Nodo * f = nodoMinimo(d); // nodo mínimo por la derecha
    Nodo * e = f->getPadre(); // nodo padre del nodo mínimo
    Nodo * g = f->getDer(); // nodo derecho del nodo mínimo
    if (b == getRaiz()){
        setRaiz(f);
    } else {
        if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
            a->setIzq(f);
        } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
            a->setDer(f);
        }
    }
    f->setIzq(c);
    if (b == e && d == f){ // caso 1
        f->setDer(g);
    } else { // caso 2
        f->setDer(d);
        e->setIzq(g);
    }
}
/**
 * Método:              esLleno
 * Descripción:         Método que permite verificar si un árbol está lleno; es decir, que
 * todos los nodos tienen dos hijos o ninguno, y sus hojas están al mismo nivel.
 * @return              variable de tipo bool (true si es completo, falso caso contrario)
 */
bool ArbinAVL::esLleno() {
    int hojas = numHojasRecursivo(getRaiz());
    int nivel = nivelRecursivo(getRaiz());
    if (pow(2, nivel) == hojas){
        return true;
    } else {
        return false;
    }
}
/**
 * Método:              esCompleto
 * Descripción:         Método que permite verificar si un árbol está completo; lo que
 * se alcanza si y solo si no existe un nodo con solo un hijo. Un árbol completo puede
 * estar lleno, pero un árbol compleno no implica que debe estar lleno.
 * @return              variable de tipo bool (true si es completo, falso caso contrario)
 */
bool ArbinAVL::esCompleto() {
    int completo = esCompletoRecursivo(getRaiz());
    if (completo > 0){
        return false;
    } else {
        return true;
    }
}
/**
 * Método:              esCompletoRecursivo
 * Descripción:         Método recursivo que cuenta el número de nodos que tienen un solo
 * hijo.
 * @param nodo          variable de tipo Nodo que representa al árbol que se va a analizar
 * @return              variable de tipo int que representa el número de nodos que tienen
 * un sólo hijo
 */
int ArbinAVL::esCompletoRecursivo(Nodo * nodo) {
    if (nodo == nullptr){
        return 0;
    } else {
        if (nodo->getDer() != nullptr && nodo->getIzq() == nullptr ||
            nodo->getDer() == nullptr && nodo->getIzq() != nullptr){
            return 1;
        } else {
            return esCompletoRecursivo(nodo->getIzq()) + esCompletoRecursivo(nodo->getDer());
        }
    }
}
