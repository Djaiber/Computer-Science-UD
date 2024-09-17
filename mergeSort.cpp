#include <stdio.h>

void capturafile(int*, int);
void muestra(int*, int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main() {
    int* datos;
    int n;
    
    printf("Datos a ordenar: ");
    scanf("%d", &n);
    
    datos = new int[n];
    if (datos == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return 1;
    }
    
    capturafile(datos, n);
    
    printf("Arreglo original:\n");
    muestra(datos, n);
    
    mergeSort(datos, 0, n - 1);
    
    printf("\nArreglo ordenado:\n");
    muestra(datos, n);
    
    delete[] datos;
    return 0;
}

void capturafile(int* datos, int n) {
    FILE* archivo = fopen("Datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (fscanf(archivo, "%d", &datos[i]) != 1) {
            printf("Error al leer el archivo o archivo incompleto\n");
            break;
        }
    }
    
    fclose(archivo);
}

void muestra(int* datos, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");
}

void mergeSort(int* datos, int ini, int fin) {
    if (ini < fin) {
        int medio = ini + (fin - ini) / 2;
        
        mergeSort(datos, ini, medio);
        mergeSort(datos, medio + 1, fin);
        
        merge(datos, ini, medio, fin);
    }
}

void merge(int* datos, int ini, int medio, int fin) {
    int i, j, k;
    int n1 = medio - ini + 1;
    int n2 = fin - medio;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = datos[ini + i];
    for (j = 0; j < n2; j++)
        R[j] = datos[medio + 1 + j];
    
    i = 0;
    j = 0;
    k = ini;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            datos[k] = L[i];
            i++;
        } else {
            datos[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        datos[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        datos[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}