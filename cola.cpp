#include <iostream>

using namespace std;

template <class TIPO>
class Nodo {
    TIPO dato;
    Nodo *siguiente;
    
public:
    Nodo(TIPO n) {
        dato = n;
        siguiente = NULL;
    }
    TIPO obtenerDato() const {
        return dato;
    }
    Nodo* obtenerSiguiente() const {
        return siguiente;
    }
    void establecerSiguiente(Nodo *nodo) {
        siguiente = nodo;
    }
};

template <class TIPO>
class Cola {
    Nodo<TIPO> *inicio; // Front of the queue
    Nodo<TIPO> *final; // Back of the queue
    unsigned int tam; // Size of the queue
    
public:
    Cola() {
        inicio = NULL;
        final = NULL;
        tam = 0;
    }
    
    ~Cola() {
        while (inicio) {
            Nodo<TIPO> *aux = inicio;
            inicio = inicio->obtenerSiguiente();
            delete aux;
        }
    }
    
    void push(TIPO n) {
        Nodo<TIPO> *nuevo = new Nodo<TIPO>(n);
        if (final == NULL) {
            inicio = final = nuevo;
        } else {
            final->establecerSiguiente(nuevo);
            final = nuevo;
        }
        tam++;
    }
    
    void pop() {
        if (inicio == NULL) {
            cout << "La cola está vacía, no se puede eliminar." << endl;
            return;
        }
        Nodo<TIPO> *aux = inicio;
        inicio = inicio->obtenerSiguiente();
        delete aux;
        tam--;
        if (inicio == NULL) {
            final = NULL;
        }
    }
    
    void mostrar() const {
        Nodo<TIPO> *aux = inicio;
        while (aux) {
            cout << aux->obtenerDato() << " ";
            aux = aux->obtenerSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Cola<int> cola; // Queue of integers
    int n, datos;
    
    cout << "Ingrese el número de datos: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el dato " << i + 1 << ": ";
        cin >> datos;
        cola.push(datos); // Add data to the queue
    }
    
    cout << "Elementos en la cola: ";
    cola.mostrar(); // Display data in the queue
    
    cout << "Eliminando el elemento del frente de la cola..." << endl;
    cola.pop();
    
    cout << "Cola después de eliminar el frente: ";
    cola.mostrar();
    
    return 0;
}
