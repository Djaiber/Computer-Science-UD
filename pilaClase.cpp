#include <stdlib.h>
#include <stdio.h>

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

TipoLista lista_vacia(void)
{
	return NULL;
}

void lee_nodo(struct Datos *dato, int persona_num)
{
	int cedula;
	char nombre[20];
	float saldo;
	
	printf("Persona #%d\n", persona_num);
	
	printf("Ingrese cedula: ");
	scanf("%i", &cedula);
	
	printf("Ingrese Nombre: ");
	scanf("%s", nombre);
	
	printf("Ingrese el saldo: ");
	scanf("%f", &saldo);
	
	dato->cedula = cedula;
	dato->nombre = (char *)malloc(20 * sizeof(char)); // Allocate memory for nombre
	
	// Manually copy each character from 'nombre' to 'dato->nombre'
	int i = 0;
	while (nombre[i] != '\0') 
	{
		dato->nombre[i] = nombre[i];
		i++;
	}
	dato->nombre[i] = '\0'; // Ensure the string is null-terminated
	
	dato->saldo = saldo;	
}

TipoLista inserta(TipoLista lista, int persona_num)
{
	struct Datos *data = new struct Datos();
	lee_nodo(data, persona_num);
	struct Nodo *nuevo = new struct Nodo();
	nuevo->dato = *data;
	nuevo->sig = lista;
	lista = nuevo;
	return lista;
}

void mostrar(TipoLista lista)
{
	struct Nodo *aux = lista;
	while (aux != NULL)
	{
		printf("Cedula: %d, Nombre: %s, Saldo: %.2f\n", aux->dato.cedula, aux->dato.nombre, aux->dato.saldo);
		aux = aux->sig;
	}
}

int main()
{
	TipoLista l = lista_vacia();
	int n;
	
	printf("¿Cuántos elementos desea agregar? ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		l = inserta(l, i + 1); // Passing i + 1 to display "Persona #n"
	}
	
	printf("\nDatos ingresados:\n");
	mostrar(l);
	
	return 0;
}
