#include <conio.h>
#include <iostream>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&, int);//prototipo

int main()
{
	Nodo *pila = NULL;//Mantiene actualizada la direccion del último elemento
	int dato,n;
	cout << "Ingrese el numero de datos a usar:";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"Digite un dato: ";
		cin>>dato;
		agregarPila(pila, dato);
		
	}
	cout <<"Oprima una tecla para continuar..."<<endl;
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int data)
{
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo -> dato = data;
	nuevoNodo -> siguiente=pila;
	pila = nuevoNodo;
	
}
