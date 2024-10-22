#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Nodo {
    int id;
    string nombre;
    float precio;
    int cantidad;
    Nodo* siguiente;
};

void agregarPila(Nodo*&, int, string, float, int);
void cargarYMostrarDatos(Nodo*&, int);
void eliminarElemento(Nodo*&, int);
void buscarElemento(Nodo*, int);


int main() {
    Nodo* pila = NULL;
    int opcion, n, id;
    
    do {
        cout << "\n=== Sistema de Inventario de Tienda ===" << endl;
        cout << "1. Cargar y mostrar productos" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Buscar producto por ID" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese el numero de productos a cargar: ";
                cin >> n;
                cargarYMostrarDatos(pila, n);
                break;
                
            case 2:
                cout << "Ingrese el ID del producto a eliminar: ";
                cin >> id;
                eliminarElemento(pila, id);
                break;
                
            case 3:
                cout << "Ingrese el ID del producto a buscar: ";
                cin >> id;
                buscarElemento(pila, id);
                break;

            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;
                
            default:
                cout << "Opcion invalida!" << endl;
        }
    } while(opcion != 4);

    // Liberar memoria
    while(pila != NULL) {
        Nodo* temp = pila;
        pila = pila->siguiente;
        delete temp;
    }

    return 0;
}

void agregarPila(Nodo*& pila, int id, string nombre, float precio, int cantidad) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->id = id;
    nuevoNodo->nombre = nombre;
    nuevoNodo->precio = precio;
    nuevoNodo->cantidad = cantidad;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void cargarYMostrarDatos(Nodo*& pila, int n) {
    // Parte 1: Cargar datos desde archivo
    ifstream archivo("store.txt");
    if (!archivo) {
        cout << "Error: No se pudo abrir store.txt" << endl;
        return;
    }

    int count = 0;
    int id, cantidad;
    string nombre;
    float precio;

    // Limpiar la pila existente
    while(pila != NULL) {
        Nodo* temp = pila;
        pila = pila->siguiente;
        delete temp;
    }

     while(count < n && archivo >> id >> nombre >> precio >> cantidad) {
        agregarPila(pila, id, nombre, precio, cantidad);
        count++;
    }
    archivo.close();
    cout << count << " productos cargados exitosamente.\n" << endl;


    // Mostrar datos
    if (pila == NULL) {
        cout << "El inventario está vacío." << endl;
        return;
    }

    cout << setw(5) << left << "ID"
        << setw(20) << left << "Producto"
        << setw(10) << right << "Precio"
        << setw(10) << right << "Cantidad" << endl;
    cout << "--------------------------------------------------------" << endl;

    Nodo* actual = pila;
    while (actual != NULL) {
        cout << setw(5) << left << actual->id
            << setw(20) << left << actual->nombre
            << "$" << setw(9) << right << fixed << setprecision(2) << actual->precio
            << setw(10) << right << actual->cantidad << endl;
        actual = actual->siguiente;
    }
}
void eliminarElemento(Nodo*& pila, int id) {
    // Parte 1: Eliminar de la pila (memoria)
    if(pila == NULL) {
        cout << "El inventario está vacío!" << endl;
        return;
    }

    // Si el primer nodo es el que queremos eliminar
    if(pila->id == id) {
        Nodo* temp = pila;
        pila = pila->siguiente;
        cout << "Producto '" << temp->nombre << "' eliminado." << endl;
        delete temp;
    } else {
        Nodo* actual = pila;
        Nodo* anterior = NULL;

        while(actual != NULL && actual->id != id) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if(actual == NULL) {
            cout << "Producto con ID " << id << " no encontrado!" << endl;
            return;
        }

        anterior->siguiente = actual->siguiente;
        cout << "Producto '" << actual->nombre << "' eliminado." << endl;
        delete actual;
    }

    // Parte 2: Eliminar del archivo store.txt
    ifstream archivo("store.txt");
    ofstream archivoTemporal("temp.txt"); // Archivo temporal para reescribir

    if (!archivo || !archivoTemporal) {
        cout << "Error al abrir los archivos!" << endl;
        return;
    }

    int archivoID, cantidad;
    string nombre;
    float precio;

    // Copiar todos los productos excepto el que tiene el ID a eliminar
    while (archivo >> archivoID >> nombre >> precio >> cantidad) {
        if (archivoID != id) {
            archivoTemporal << archivoID << " " << nombre << " " << precio << " " << cantidad << endl;
        }
    }

    archivo.close();
    archivoTemporal.close();

    // Reemplazar el archivo original con el archivo temporal
    remove("store.txt");              // Borrar el archivo original
    rename("temp.txt", "store.txt");   // Renombrar el archivo temporal a "store.txt"

    cout << "Producto con ID " << id << " eliminado del archivo." << endl;
}

void buscarElemento(Nodo* pila, int id) {
    Nodo* actual = pila;
    while(actual != NULL && actual->id != id) {
        actual = actual->siguiente;
    }

    if(actual == NULL) {
        cout << "Producto con ID " << id << " no encontrado." << endl;
    } else {
        cout << "\nProducto encontrado:" << endl;
        cout << "ID: " << actual->id << endl;
        cout << "Nombre: " << actual->nombre << endl;
        cout << "Precio: $" << fixed << setprecision(2) << actual->precio << endl;
        cout << "Cantidad en stock: " << actual->cantidad << endl;
    }
}

