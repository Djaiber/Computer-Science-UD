#include <stdio.h>

void capturafile(int*, int);
void muestra(int*, int);
void swap(int*, int*);
void quicksort(int*, int, int);


int main() {
    int* datos;
    int n;
    printf("Datos a ordenar: ");
    scanf("%i", &n);
    datos = new int[n];
    capturafile(datos, n);
    quicksort(datos, 0, n - 1);
 	muestra(datos, n);
 	
    delete[] datos; // Liberamos la memoria reservada
    return 0;
}

void capturafile(int* datos, int n) {
    FILE* archivo;
    archivo = fopen("Datos.txt", "r"); 
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    for (int i = 0; i < n; i++) { 
        fscanf(archivo, "%i", &datos[i]);
    }	
    fclose(archivo);
}


void muestra(int* datos, int n) {
    for (int i = 0; i < n; i++) { 
        printf("%i ,", datos[i]);     
    }
}

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quicksort(int* datos, int ini, int fin) {
    if (ini >= fin) {
        return; 
    }
    int pivote = datos[(ini + fin) / 2];
     printf("Pivote: %i \n", pivote);
    // Inicializamos los índices
    int i = ini;
    int j = fin;

    // Hacemos el proceso de partición con los dos índices
    while (i <= j) {
        //DERECHA
        while (datos[i] < pivote) {
            i++;
        }
        //iZQUIERDA
        while (datos[j] > pivote) {
            j--;
        }

        // Si los índices no se han cruzado, intercambiamos los elementos
        if (i <= j) {
            swap(&datos[i], &datos[j]);
            i++;
            j--;
        }
    }
    quicksort(datos, ini, j); // Parte izquierda
    quicksort(datos, i, fin); // Parte derecha
}
