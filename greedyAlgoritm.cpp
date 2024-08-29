#include <vector>
#include <cstdio>

using namespace std;

struct Evento {
    int id;
    int inicio;
    int fin;
};

// Función para ordenar los eventos por tiempo de finalización usando Bubble Sort
void ordenarEventos(vector<Evento> &eventos) {
    int n = eventos.size();
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

void seleccionarEventos(vector<Evento> &eventos) {
    // Ordenar los eventos por tiempo de finalización
    ordenarEventos(eventos);

    printf("Eventos seleccionados:\n");
    printf("ID\tInicio\tFin\n");

    // Seleccionar el primer evento
    int i = 0;
    printf("%i\t%i\t%i\n", eventos[i].id, eventos[i].inicio, eventos[i].fin);

    // Considerar los siguientes eventos
    for (int j = 1; j < eventos.size(); j++) {
        // Si este evento empieza después de que el último seleccionado terminó, seleccionarlo
        if (eventos[j].inicio >= eventos[i].fin) {
            printf("%i\t%i\t%i\n", eventos[j].id, eventos[j].inicio, eventos[j].fin);
            i = j;
        }
    }
}

int main() {
    vector<Evento> eventos;

    // Abrir el archivo "eventos.txt" para lectura
    FILE *file = fopen("eventos.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo eventos.txt\n");
        return 1;
    }

    Evento evento;
    // Leer cada línea del archivo y almacenar los datos en el vector de eventos
    while (fscanf(file, "%i,%i,%i", &evento.id, &evento.inicio, &evento.fin) != EOF) {
        eventos.push_back(evento);
    }

    // Cerrar el archivo
    fclose(file);

    // Seleccionar eventos que no se superpongan
    seleccionarEventos(eventos);

    return 0;
}
