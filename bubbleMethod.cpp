#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Headers
string toString (double);
int toInt (string);
double toDouble (string);

int main() {
    int posiones, apuntador1, apuntador2, auxiliar, contadorVueltas;

    apuntador1 = 0;
    apuntador2 = 1;
    auxiliar = 0;
    contadorVueltas = 0;
    cout << "¿Cuantas números desea ordenar?: " << endl;
    cin >> posiones;
    int burbuja[posiones];

    for (apuntador1 = 0; apuntador1 <= posiones - 1; apuntador1++) {
        cout << "Dame el valor #" << apuntador1 + 1 << " :" << endl;
        cin >> burbuja[apuntador1];
    }
    cout << "Los números resgistrados son: ";
    for (apuntador1 = 0; apuntador1 <= posiones - 1; apuntador1++) {
        cout << " " << burbuja[apuntador1] << " ,";
    }
    apuntador1 = 0;
    while (posiones != contadorVueltas) {
        while (apuntador2 < posiones) {
            if (burbuja[apuntador1] > burbuja[apuntador2]) {
                auxiliar = burbuja[apuntador1];
                burbuja[apuntador1] = burbuja[apuntador2];
                burbuja[apuntador2] = auxiliar;
            }
            apuntador1 = apuntador1 + 1;
            apuntador2 = apuntador2 + 1;
        }
        apuntador1 = 0;
        apuntador2 = 1;
        contadorVueltas = contadorVueltas + 1;
    }
    cout << " " << endl;
    cout << "Orden ascendente: ";
    for (apuntador1 = 0; apuntador1 <= posiones - 1; apuntador1++) {
        cout << "" << burbuja[apuntador1] << " ,";
    }
    cout << " " << endl;
    cout << "Orden descendente: ";
    for (apuntador1 = posiones - 1; apuntador1 >= 0; apuntador1--) {
        cout << "" << burbuja[apuntador1] << " ,";
    }
    return 0;
}

// The following implements type conversion functions.
string toString (double value) { //int also
    stringstream temp;
    temp << value;
    return temp.str();
}

int toInt (string text) {
    return atoi(text.c_str());
}

double toDouble (string text) {
    return atof(text.c_str());
}
