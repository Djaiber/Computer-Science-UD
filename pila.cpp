#include <conio.h>
#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int); // Prototipo
void mostrarPila(Nodo *); // Prototipo

int main()
{
    Nodo *pila = NULL; // Mantiene la dirección del último elemento
    int dato, n;
    
    cout << "Ingrese el numero de datos a usar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Digite un dato: ";
        cin >> dato;
        agregarPila(pila, dato);
    }

    // Llama a la función mostrarPila para mostrar la pila
    cout << "Elementos en la pila: ";
    mostrarPila(pila);
    
    cout << "Oprima una tecla para continuar..." << endl;
    getch();
    return 0;
}

void agregarPila(Nodo *&pila, int data)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->dato = data;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void mostrarPila(Nodo *pila)
{
    Nodo *actual = pila; // Comienza desde la parte superior de la pila
    while (actual != NULL)
    {
        cout << actual->dato << " "; // Imprime el dato del nodo actual
        actual = actual->siguiente; // Mueve al siguiente nodo
    }
    cout << endl; // Nueva línea después de mostrar todos los elementos
}
