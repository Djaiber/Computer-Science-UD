#include <iostream>
#include <cstdlib>
using namespace std;

// Primera estructura para el Nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Segunda estructura para la Cola
struct Cola {
    struct Nodo* frente;
    struct Nodo* fin;
};

// Función para crear una nueva cola
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    if(cola == NULL) {
        cout << "Error al crear la cola" << endl;
        return NULL;
    }
    cola->frente = cola->fin = NULL;
    return cola;
}

// Función para verificar si la cola está vacía
bool cola_vacia(struct Nodo *frente) {
    return (frente == NULL) ? true : false;
}

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nuevoNodo == NULL) {
        cout << "Error: No se pudo asignar memoria para el nuevo nodo" << endl;
        return NULL;
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para agregar nodo
void agregarNodo(struct Cola* cola, int dato) {
    struct Nodo* nuevoNodo = crearNodo(dato);
    if(nuevoNodo == NULL) return;
    
    if(cola_vacia(cola->frente)) {
        cola->frente = cola->fin = nuevoNodo;
    } else {
        cola->fin->siguiente = nuevoNodo;
        cola->fin = nuevoNodo;
    }
    cout << "Elemento " << dato << " agregado exitosamente" << endl;
}

// Función para eliminar nodo
int eliminarNodo(struct Cola* cola) {
    if(cola_vacia(cola->frente)) {
        cout << "La cola está vacía" << endl;
        return -1;
    }
    
    struct Nodo* temp = cola->frente;
    int dato = temp->dato;
    
    if(cola->frente == cola->fin) {
        cola->frente = cola->fin = NULL;
    } else {
        cola->frente = cola->frente->siguiente;
    }
    
    free(temp);
    cout << "Elemento " << dato << " eliminado exitosamente" << endl;
    return dato;
}

// Nueva función para buscar y mostrar un nodo específico
void buscarNodo(struct Cola* cola, int valorBuscado) {
    if(cola_vacia(cola->frente)) {
        cout << "La cola está vacía" << endl;
        return;
    }
    
    struct Nodo* temp = cola->frente;
    int posicion = 1;
    bool encontrado = false;
    
    cout << "Buscando nodo con valor " << valorBuscado << "..." << endl;
    
    while(temp != NULL) {
        if(temp->dato == valorBuscado) {
            cout << "Nodo encontrado en la posición " << posicion << endl;
            cout << "Valor: " << temp->dato << endl;
            if(temp->siguiente != NULL) {
                cout << "Siguiente nodo: " << temp->siguiente->dato << endl;
            } else {
                cout << "Este es el último nodo" << endl;
            }
            encontrado = true;
        }
        temp = temp->siguiente;
        posicion++;
    }
    
    if(!encontrado) {
        cout << "No se encontró ningún nodo con el valor " << valorBuscado << endl;
    }
}

// Función para mostrar el frente
void mostrarFrente(struct Cola* cola) {
    if(cola_vacia(cola->frente)) {
        cout << "La cola está vacía" << endl;
        return;
    }
    cout << "Elemento del frente: " << cola->frente->dato << endl;
}

// Función para mostrar toda la cola
void mostrarCola(struct Cola* cola) {
    if(cola_vacia(cola->frente)) {
        cout << "La cola está vacía" << endl;
        return;
    }
    
    struct Nodo* temp = cola->frente;
    cout << "Elementos en la cola: ";
    while(temp != NULL) {
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << endl;
}

// Función para liberar la memoria de la cola
void liberarCola(struct Cola* cola) {
    struct Nodo* actual = cola->frente;
    struct Nodo* siguiente;
    
    while(actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(cola);
}

// Función principal
int main() {
    struct Cola* cola = crearCola();
    if(cola == NULL) return 1;
    
    int opcion, numElementos, elemento, valorBuscar;
    
    do {
        cout << "\n=== MENÚ DE COLA ===" << endl;
        cout << "1. Agregar nodos" << endl;
        cout << "2. Eliminar nodo" << endl;
        cout << "3. Mostrar frente" << endl;
        cout << "4. Mostrar cola completa" << endl;
        cout << "5. Verificar si está vacía" << endl;
        cout << "6. Buscar nodo específico" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "\n¿Cuántos elementos desea agregar? ";
                cin >> numElementos;
                
                for(int i = 0; i < numElementos; i++) {
                    cout << "Ingrese el elemento " << (i+1) << ": ";
                    cin >> elemento;
                    agregarNodo(cola, elemento);
                }
                break;
                
            case 2:
                eliminarNodo(cola);
                break;
                
            case 3:
                mostrarFrente(cola);
                break;
                
            case 4:
                mostrarCola(cola);
                break;
                
            case 5:
                if(cola_vacia(cola->frente)) {
                    cout << "La cola está vacía" << endl;
                } else {
                    cout << "La cola NO está vacía" << endl;
                }
                break;
                
            case 6:
                cout << "Ingrese el valor del nodo a buscar: ";
                cin >> valorBuscar;
                buscarNodo(cola, valorBuscar);
                break;
                
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
        
    } while(opcion != 7);
    
    // Liberamos la memoria antes de terminar
    liberarCola(cola);
    
    return 0;
}