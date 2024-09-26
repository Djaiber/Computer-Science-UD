#include <stdio.h>

// Función para ordenar un arreglo de números enteros, colocando los pares primero
void ordenarArreglo(int arr[], int n) {
    int i, j, temp;
    
    // Ordenar los números en dos partes: pares primero, luego impares
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Condición para que los números pares queden antes que los impares
            if ((arr[j] % 2 != 0 && arr[j+1] % 2 == 0) || 
                (arr[j] % 2 == arr[j+1] % 2 && arr[j] > arr[j+1])) {
                // Intercambiar
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 6, 2, 5, 9, 13, 21, 8, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    imprimirArreglo(arr, n);

    // Ordenar el arreglo
    ordenarArreglo(arr, n);

    printf("Arreglo ordenado (pares primero, impares después):\n");
    imprimirArreglo(arr, n);

    return 0;
}