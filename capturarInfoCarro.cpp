#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Definir una estructura para contener los datos del automóvil
struct Automovil {
    char placa[7]; // 6 caracteres más el terminador nulo
    int costo;
    int serial;
};

// Declaración de funciones
void capturafile(Automovil *, int);
void muestra(Automovil *, int);

int main() {
    Automovil *autos;
    int n;
    
    printf("Ingrese cuántos datos: ");
    scanf("%i", &n);
    
    autos = new Automovil[n]; // Asignar memoria para n automóviles
    
    capturafile(autos, n); // Leer datos del archivo
    muestra(autos, n);    // Mostrar los datos
    
    delete[] autos; // Liberar la memoria asignada
    return 0;
}

void capturafile(Automovil *autos, int n) {
    FILE *archivo;
    archivo = fopen("datosAutomovil.txt", "r"); // Abrir el archivo en modo lectura
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1); // Salir si no se puede abrir el archivo
    }
    
    for (int i = 0; i < n; i++) {
        // Leer datos del archivo en la estructura
        fscanf(archivo, "%6s", autos[i].placa); // Leer placa (6 caracteres + terminador nulo)
        fscanf(archivo, "%i", &autos[i].costo); // Leer costo
        fscanf(archivo, "%i", &autos[i].serial); // Leer serial
    }
    
    fclose(archivo); // Cerrar el archivo
}

void muestra(Automovil *autos, int n) {
    for (int i = 0; i < n; i++) {
        // Mostrar los datos de cada automóvil
        printf("Placa: %s\nCosto: %d\nSerial: %d\n\n", autos[i].placa, autos[i].costo, autos[i].serial);
    }
}
