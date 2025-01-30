#include <iostream>

using namespace std;

struct Nodo {

    int dato; // Dato o valor
    struct Nodo *izq; // Apuntador al siguiente elemento de la lista
    struct Nodo *der; // Apuntador al elemento anterior de la lista
};
// Declaración de funciones
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

// Nodo raíz inicial
Nodo *arbol = NULL;

int main() {
    int dato, count, contador = 0, valor, nivel = 1;
    Nodo *arbol = NULL; // Inicializamos el árbol vacío

    cout << "Digite cuantos nodos desea ingresar: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Digite el dato a guardar en el nodo " << i + 1 << ": ";
        cin >> dato;
        insertarNodo(arbol, dato);
    }

    cout << "\nMostrando árbol:" << endl;
    mostrarArbol(arbol, 0);

    cout << "\nRecorrido en Preorden: ";
    preOrden(arbol);
    cout << endl;

    cout << "Recorrido en Inorden: ";
    inOrden(arbol);
    cout << endl;

    cout << "Recorrido en Postorden: ";
    postOrden(arbol);
    cout << endl;

    cout << "\nIngrese el valor que desea buscar: ";
    cin >> valor;
    
    if (busqueda(arbol, valor, nivel))
        cout << "El valor fue encontrado" << endl;
    else
        cout << "El valor NO fue encontrado" << endl;

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
        } else if (n> valorRaiz){
            insertarNodo(arbol->der, n);
        }
        else{
            cout<<"GRAVES, Se repite dato"<<endl;
        }
    }
}
void preOrden(Nodo * arbol)
{
    if(arbol == NULL) // Si está vacío
        return;
    else
    {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
void inOrden(Nodo * arbol)
{
    if (arbol == NULL) // Si el árbol está vacío
        return;
    
    inOrden(arbol->izq);         // Recorre el subárbol izquierdo
    cout << arbol->dato << " - "; // Visita la raíz
    inOrden(arbol->der);         // Recorre el subárbol derecho
}

void postOrden(Nodo * arbol)
{
    if (arbol == NULL) // Si el árbol está vacío
        return;
    
    postOrden(arbol->izq);       // Recorre el subárbol izquierdo
    postOrden(arbol->der);       // Recorre el subárbol derecho
    cout << arbol->dato << " - "; // Visita la raíz
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

bool busqueda(Nodo *arbol, int valor, int nivel)
{
    if(arbol == NULL)
        return false;
    else
    {
        if(arbol -> dato == valor){
            cout << "Nivel: "<<nivel<<endl;
            return true;
        }
        else
        {
            if(valor<arbol -> dato){
                return busqueda(arbol -> izq, valor, nivel+1);}
            else
            {
                return busqueda(arbol -> der, valor, nivel+1);
            }
        }
    }
}

