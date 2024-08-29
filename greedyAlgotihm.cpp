#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct evento{
	int id;
	int Hinicio;
	int Hfinal;
};

int ContarEventos(const char *);
void CapturaFile(evento *, int);
void muestra(evento *, int);
void OrdenarPorFin(evento *, int);
void SeleccionarEvento(evento *, int);

int main(){
	evento *event;
	int n;
	
	n = ContarEventos("eventos.txt");
	if(n==0){
		printf("El archivo no contiene eventos o no se pudo abrir.\n");
        return 1;
	}
	
	event = new evento[n];
	CapturaFile(event, n);
	
	printf("Eventos Leídos desde el archivo:\n");
	muestra(event, n);
	
	OrdenarPorFin(event, n);
	
	printf("\nEventos seleccionados que no se superponen:\n");
	SeleccionarEvento(event, n);
}

int ContarEventos(const char *Eventos){
	FILE * archivo;
	int count=0;
	int id, Hinicio, Hfinal;
	
	archivo = fopen("eventos.txt", "r");
	
	while (fscanf(archivo, "%i %i %i", &id, &Hinicio, &Hfinal) == 3) {
        count++;
    }

    fclose(archivo);
    return count;
}

void CapturaFile(evento *event, int n){
	
	FILE * archivo;
	
	archivo = fopen("eventos.txt", "a+");
	
	for (int i = 0; i < n; i++) {
        fscanf(archivo, "%i", &event[i].id);
        fscanf(archivo, "%i", &event[i].Hinicio);
        fscanf(archivo, "%i", &event[i].Hfinal);
    }
    fclose(archivo);
}

void muestra (evento * event, int n){
	for(int i=0;i<n;i++){
		printf("Evento %i: \n", i);
		printf("ID: %i \n", event[i].id);
		printf("Hora Inicio: %i \n", event[i].Hinicio);
		printf("Hora Final: %i \n", event[i].Hfinal);
		printf("-------------------------------\n");
	}
}

void OrdenarPorFin(evento *event, int n){
	// algoritmo de ordenación (Burbuja)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (event[j].Hfinal > event[j + 1].Hfinal) {
                // Intercambiar eventos
                evento temp = event[j];
                event[j] = event[j + 1];
                event[j + 1] = temp;
            }
        }
    }
}

void SeleccionarEvento(evento *event, int n){
	// Seleccionar el primer evento
    int ultimoFin = event[0].Hfinal;
    printf("Evento %i [Inicio: %i, Fin: %i]\n", event[0].id, event[0].Hinicio, ultimoFin);

    // Iterar y seleccionar los siguientes eventos que no se superpongan
    for (int i = 1; i < n; i++) {
        if (event[i].Hinicio >= ultimoFin) {
            printf("Evento %i [Inicio: %i, Fin: %i]\n", event[i].id, event[i].Hinicio, event[i].Hfinal);
            ultimoFin = event[i].Hfinal;
        }
    }
}