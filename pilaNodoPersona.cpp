#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Datos
{
    int cedula;
    char *nombre;
    float saldo;
};

struct Nodo
{
    struct Datos dato;
    struct Nodo *sig;
};

typedef struct Nodo *TipoLista;

// Fix: Change function declaration to match definition
TipoLista Lista_vacia();  // Changed from lista_vacia to Lista_vacia
void lee_nodo(struct Datos*);
TipoLista inserta(TipoLista);
void muestra_nodo(struct Nodo *);
void guardarDatos(TipoLista lista, int n);

int main()
{
    TipoLista l;
    int n;
    printf("Cuántos datos desea ingresar?:\n");
    scanf("%i", &n);
    
    // Fix: Change function call to match definition
    l = Lista_vacia();  // Changed from lista_vacia to Lista_vacia
    for (int i = 1; i <= n; i++)
        l = inserta(l);
    
    struct Nodo *actual = l;
    for (int i = 0; i < n && actual != NULL; i++)
    {
        printf("\nDatos del nodo %d:\n", i + 1);
        muestra_nodo(actual);
        actual = actual->sig;
    }
    
    guardarDatos(l, n);
    
    return 0;
}

TipoLista Lista_vacia()
{
    return NULL;
}

void lee_nodo(struct Datos *dato)
{
    int cedula;
    char nombreaux[100];
    float saldo;
    
    printf("Ingrese cedula: ");
    scanf("%i", &cedula);
    printf("Ingrese Nombre: ");
    scanf("%s", nombreaux);
    printf("Ingrese el saldo: ");
    scanf("%f", &saldo);
    
    dato->nombre = new char[strlen(nombreaux) + 1];
    strcpy(dato->nombre, nombreaux);
    
    dato->cedula = cedula;
    dato->saldo = saldo;
}

TipoLista inserta(TipoLista lista)
{
    struct Datos *data = new struct Datos();
    lee_nodo(data);
    
    struct Nodo *nuevo = new struct Nodo();
    nuevo->dato = *data;
    nuevo->sig = lista;
    lista = nuevo;
    return lista;
}

void muestra_nodo(struct Nodo *nodo)
{
    printf("Cedula: %d\n", nodo->dato.cedula);
    printf("Nombre: %s\n", nodo->dato.nombre);
    printf("Saldo: %.2f\n", nodo->dato.saldo);
}

void guardarDatos(TipoLista lista, int n)
{
    FILE *archivo = fopen("DatosPersona.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }
    
    struct Nodo *actual = lista;
    fprintf(archivo, "Total de registros: %d\n\n", n);
    
    while (actual != NULL)
    {   
        fprintf(archivo, "Cedula: %d\n", actual->dato.cedula);
        fprintf(archivo, "Nombre: %s\n", actual->dato.nombre);
        fprintf(archivo, "Saldo: %.2f\n", actual->dato.saldo);
        fprintf(archivo, "------------------------\n");
        actual = actual->sig;
    }
    
    fclose(archivo);
    printf("\nDatos guardados exitosamente en 'DatosPersona.txt'\n");
}