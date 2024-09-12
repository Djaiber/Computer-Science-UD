/*
Nombre: JAIBER DUVAN DIAZ LEON
Código: 20222020011
Grupo: 020-84
*/


#include <stdio.h>

void capturafile(int*, int);
void muestra(int*, int);
void insertion(int*, int);

int main()
{
    int *datos;
    int n;
    printf("Ingrese cuantos datos:");
    scanf("%i", &n);
    datos = new int[n];  // Habilitamos la memoria para n datos
    capturafile(datos, n);
    muestra(datos, n);
    insertion(datos, n);
    muestra(datos, n);
    delete[] datos;  // Liberar la memoria
}

void insertion(int *datos, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = datos[i];
        int j = i - 1;
        
        // Mueve los elementos que son mayores que la clave un lugar adelante
        while (j >= 0 && datos[j] > key)
        {
            datos[j + 1] = datos[j];
            j = j - 1;
        }
        datos[j + 1] = key;
    }
}

void capturafile(int *datos, int n)
{
    FILE *archivo;
    archivo = fopen("Datos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    for (int i = 0; i < n; i++) // Captura datos
    {
        fscanf(archivo, "%i", &datos[i]);
    }
    fclose(archivo);
}

void muestra(int *datos, int n)
{
    for (int i = 0; i < n; i++) // Muestra datos
    {
        printf("%i - ", datos[i]);
    }
    printf("\n");
}
