#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Persona {
    int cedula;
    char nombre[15];
    char apellido[15];
};

// Comparar personas por su cédula 
int compararCedula(const void *a, const void *b) {
    Persona *p1 = (Persona *)a;
    Persona *p2 = (Persona *)b;
    return (p1->cedula - p2->cedula);
}

// Realiza la búsqueda binaria
int busquedaBinaria(Persona *personas, int izquierda, int derecha, int cedulaBuscada) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (personas[medio].cedula == cedulaBuscada) {
            return medio; // Cédula encontrada
        }
        if (personas[medio].cedula < cedulaBuscada) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1; // Cédula no encontrada
}

int main() {
    ifstream archivo("Personas.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo 'Personas.txt'" << endl;
        return 1;
    }

    int n = 1000000; // Número de personas en el archivo
    Persona *personas = new Persona[n];

    // Leer el archivo y cargar los datos en el arreglo dinámico
    int i = 0;
    while (archivo >> personas[i].cedula) {
        archivo >> personas[i].nombre >> personas[i].apellido;
        i++;
    }
    archivo.close();

    // Ordenar las personas por cédula usando qsort
    qsort(personas, i, sizeof(Persona), compararCedula);
    cout << "Número de personas leidas: "<<i<<endl ;
    int cedulaBuscada;
    cout << "Ingrese el número de cédula a buscar: ";
    cin >> cedulaBuscada;


    int indice = busquedaBinaria(personas, 0, i - 1, cedulaBuscada);

    if (indice != -1) {
        cout << "Cédula: " << personas[indice].cedula << endl;
        cout << "Nombre: " << personas[indice].nombre << endl;
        cout << "Apellido: " << personas[indice].apellido << endl;
    } else {
        cout << "Persona con cédula " << cedulaBuscada << " no encontrada." << endl;
    }

    delete[] personas;
    return 0;
}
