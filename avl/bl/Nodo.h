//
// Created by Mario Martinez on 30/09/20.
//

#ifndef ARBOL_AVL_NODO_H
#define ARBOL_AVL_NODO_H


class Nodo {
public:
    Nodo();

    Nodo(int num);

    virtual ~Nodo();

    int getNum() const;

    void setNum(int num);

    int getFe() const;

    void setFe(int fe);

    Nodo *getIzq() const;

    void setIzq(Nodo *izq);

    Nodo *getDer() const;

    void setDer(Nodo *der);

    Nodo *getPadre() const;

    void setPadre(Nodo *padre);

private:
    int num;
    int fe;
    Nodo *izq;
    Nodo *der;
    Nodo *padre;
};


#endif //ARBOL_AVL_NODO_H
