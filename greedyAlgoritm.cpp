#include <cstdio>

struct Evento {
    int id;
    int inicio;
    int fin;
};

// Función para ordenar los eventos por tiempo de finalización usando Bubble Sort
void ordenarEventos(Evento eventos[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (eventos[j].fin > eventos[j+1].fin) {
                Evento temp = eventos[j];
                eventos[j] = eventos[j+1];
                eventos[j+1] = temp;
            }
        }
    }
}

void seleccionarEventos(Evento eventos[], int n) {
    // Ordenar los eventos por tiempo de finalización
    ordenarEventos(eventos, n);

    printf("Eventos seleccionados:\n");
    printf("ID\tInicio\tFin\n");

    // Seleccionar el primer evento
    int i = 0;
    printf("%i\t%i\t%i\n", eventos[i].id, eventos[i].inicio, eventos[i].fin);

    for (int j = 1; j < n; j++) {
        // Si este evento empieza después de que el último seleccionado terminó, seleccionarlo
        if (eventos[j].inicio >= eventos[i].fin) {
            printf("%i\t%i\t%i\n", eventos[j].id, eventos[j].inicio, eventos[j].fin);
            i = j;
        }
    }
}

int main() {
    Evento eventos[100]; // Asumiendo que no habrá más de 100 eventos
    int n = 0;

    FILE *file = fopen("eventos1.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo eventos.txt\n");
        return 1;
    }

    // Leer cada línea del archivo y almacenar los datos en el array de eventos
    while (fscanf(file, "%i,%i,%i", &eventos[n].id, &eventos[n].inicio, &eventos[n].fin) == 3) {
        n++;
    }
    fclose(file);

    seleccionarEventos(eventos, n);

    return 0;
}
