#include <iostream>

using namespace std;

struct Nodo {

    int dato; // Dato o valor
    struct Nodo *izq; // Apuntador al siguiente elemento de la lista
    struct Nodo *der; // Apuntador al elemento anterior de la lista

};

Nodo *arbol = NULL;

Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);

int main() {

    int dato, cont;
    cout << "Digite cuantos nodos desea ingresar: ";
    cin >> cont;

    for (int i = 0; i < cont; i++) {

        cout << "Digite el dato a guardar en un nodo: ";
        cin >> dato;
        insertarNodo(arbol, dato);
    }

    cout << "Mostrando arbol: " << endl;

    mostrarArbol(arbol, 0);

    return 0;

}

Nodo *crearNodo(int n) {

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;
    return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, int n) {

    if (arbol == NULL) { // Si el arbol está vacío
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;

    } else {

        int valorRaiz = arbol->dato; // Obtenemos el valor raíz

        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n);
        } else {
            insertarNodo(arbol->der, n);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont) {

    if (arbol == NULL) {
        return; // Si es vacío, caso base
    } else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }

}