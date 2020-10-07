/**
 * Nombre del programa: Árbol binario de búsquda
 * Descripción: Programa que contiene la estructura básica de un árbol binario,
 * que recibe números enteros y permite mostrarlos en preorden (RID: raíz -
 * izquierda - derecha), in-orden (IRD: izquierda - raíz - derecha) y en post-inOrden
 * (IDR: izquierda - derecha - raíz)
 * Fecha de creación: 2020-09-30
 * Autores:
 *      Francisco Sandoval Cordero
 *      Juan Hidalgo González
 *      Mario Martínez Lanuza
 * Modificación: 2020-09-23
 */
#include <iostream>
#include "../tl/Gestor.h"
#include "../utilitario/Validar.h"

using namespace std;
Gestor gestor;
Validar validar;
void menu();
void procesarMenu(int &, bool &);
int ingresarNum(string);
void esVacioAVL();
void pesoAVL();
void insertarEnAVL();
void buscarMaximo();
void buscarMinimo();
void esHoja();
void nivel();
void altura();
void numHojas();
void camino();
void preOrden();
void postOrden();
void inOrden();
void eliminarElemIzq();
void eliminarElemDer();
void esLleno();
void esCompleto();
void insertarEnArbolB();
void sonArbolesIguales();
void sonArbolesSemejantes();
void sonArbolesIsomorfos();

int main() {
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Arbol Binario Balanceado AVL\n\nElija una opción\n" <<
             "01 Agregar datos al árbol\n" <<
             "02 Verificar si el árbol tiene elementos\n" <<
             "03 Peso del árbol\n" <<
             "04 Número menor del árbol\n" <<
             "05 Número mayor del árbol\n" <<
             "06 Verificar si valor es hoja\n" <<
             "07 Nivel del arbol\n" <<
             "08 Altura del árbol\n" <<
             "09 Número de hojas del árbol\n" <<
             "10 Camino entre dos valores\n" <<
             "11 Imprimir árbol en PREORDEN\n" <<
             "12 Imprimir árbol en POSTORDEN\n" <<
             "13 Imprimir árbol en ORDEN\n" <<
             "14 Eliminar elemento - Izquierda\n" <<
             "15 Elminar elemento - Derecha\n" <<
             "16 Está lleno?\n" <<
             "17 Es completo?\n" <<
             "18 Insertar en arbol B\n" <<
             "19 Los árboles son iguales?\n" <<
             "20 Los árboles son semejantes?\n" <<
             "21 Los árboles son isomorfos?\n" <<
             "22 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            insertarEnAVL();
            break;
        case 2:
            esVacioAVL();
            break;
        case 3:
            pesoAVL();
            break;
        case 4:
            buscarMinimo();
            break;
        case 5:
            buscarMaximo();
            break;
        case 6:
            esHoja();
            break;
        case 7:
            nivel();
            break;
        case 8:
            altura();
            break;
        case 9:
            numHojas();
            break;
        case 10:
            camino();
            break;
        case 11:
            preOrden();
            break;
        case 12:
            postOrden();
            break;
        case 13:
            inOrden();
            break;
        case 14:
            eliminarElemIzq();
            break;
        case 15:
            eliminarElemDer();
            break;
        case 16:
            esLleno();
            break;
        case 17:
            esCompleto();
            break;
        case 18:
            insertarEnArbolB();
            break;
        case 19:
            sonArbolesIguales();
            break;
        case 20:
            sonArbolesSemejantes();
            break;
        case 21:
            sonArbolesIsomorfos();
            break;
        case 22:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}
void insertarEnAVL() {
    string msg = "Ingrese la cantidad de números que desea cargar al árbol AVL\n";
    int ciclos = ingresarNum(msg);
    for (int i = 0; i < ciclos; ++i) {
        msg = "ingrese el valor " + to_string(i + 1);
        bool carga = gestor.insertarElem(ingresarNum(msg));
        if (carga) {
            cout << "Cargado satisfactoriamente el valor ingresado\n";
        } else {
            cout << "No se cargó el valor ingresado; ya existe en el árbol AVL\n";
        }
    }
    cout << "Finalizado el procesamiento de datos ...\n";
}
void esVacioAVL(){
    if (gestor.esVacioAVL()) {
        cout << "El árbol AVL está vacío\n";
    } else {
        cout << "El árbol AVL tiene elementos\n";
    }
}
void pesoAVL(){
    cout << "El peso del árbol AVL es " << gestor.pesoAVL() << endl;
}
void buscarMinimo(){
    if (!gestor.esVacioAVL()) {
        int min = gestor.buscarMinimo();
        if(min != -99999){
            cout << "El valor mínimo del árbol AVL es " << min << endl;
        } else {
            cout << "Aún no se ha ingresado datos al árbol AVL\n";
        }
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void buscarMaximo(){
    if (!gestor.esVacioAVL()) {
        int max = gestor.buscarMaximo();
        if (max != -99999){
            cout << "El valor máximo del árbol AVL es " << max << endl;
        } else {
            cout << "Aún no se ha ingresado datos al árbol AVL\n";
        }
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void esHoja(){
    string msg = "ingrese el valor\n";
    string esHoja = gestor.esHoja(ingresarNum(msg));
    if (!gestor.esVacioAVL()) {
        cout << esHoja;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void nivel(){
    if (!gestor.esVacioAVL()) {
        cout << "El nivel del árbol AVL es " << gestor.nivel() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void altura(){
    if (!gestor.esVacioAVL()) {
        cout << "La altura del árbol AVL es " << gestor.altura() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void numHojas(){
    if (!gestor.esVacioAVL()) {
        cout << "El número de hojas del árbol AVL es " << gestor.numHojas() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void camino(){
    if (!gestor.esVacioAVL()) {
        int inicial = ingresarNum("Ingrese el valor inicial");
        int final = ingresarNum("Ingrese el valor final");
        cout << gestor.camino(inicial, final) << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void preOrden(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.preOrden() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void postOrden(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.postOrden() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void inOrden(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.inOrden() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void eliminarElemIzq(){
    if (!gestor.esVacioAVL()) {
        string msg = "Ingrese el número que desea eliminar del árbol AVL\n";
        int num = ingresarNum(msg);
        cout << gestor.eliminarElemIzq(num) << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void eliminarElemDer(){
    if (!gestor.esVacioAVL()) {
        string msg = "Ingrese el número que desea eliminar del árbol AVL\n";
        int num = ingresarNum(msg);
        cout << gestor.eliminarElemDer(num) << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void esLleno(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.esLleno() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol AVL\n";
    }
}
void esCompleto(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.esCompleto() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void insertarEnArbolB(){
    string msg = "Ingrese la cantidad de números que desea cargar al árbol\n";
    int ciclos = ingresarNum(msg);
    for (int i = 0; i < ciclos; ++i) {
        msg = "ingrese el valor " + to_string(i + 1);
        bool carga = gestor.insertarElemB(ingresarNum(msg));
        if (carga) {
            cout << "El valor ingresado se cargó correctamente\n";
        } else {
            cout << "No se cargó el valor ingresado; ya existe en el árbol\n";
        }
    }
    cout << "Finalizado el procesamiento de datos ...\n";
}
void sonArbolesIguales(){
    cout << gestor.sonArbolesIguales() << endl;
}
void sonArbolesSemejantes(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.sonArbolesSemejantes() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void sonArbolesIsomorfos(){
    if (!gestor.esVacioAVL()) {
        cout << gestor.sonArbolesIsomorfos() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}