#include <stdio.h>


using namespace std;

void captura(int *, int);
void capturafile(int *, int);
void muestra(int *, int );


int main (){
	
	
	int * notas;
	int n ;
	
	printf("Ingrese cuantos datos:");
	
	scanf("%i",&n);
	
	notas = new int[n];//Habilita la memoria n datos
	
	//captura(notas,n);
	capturafile(notas,n);//Captura del archivo Datos.txt
	muestra(notas,n);
}
	
	void capturafile(int * notas, int n){
		
		FILE * archivo;
		archivo = fopen("Datos.txt","a+");//Al apuntador le asociamos datos.txt; a+ permite adicionar al archivo
		
		for(int i=0;i<n;i++)//Captura datos
		{
	
		   fscanf(archivo,"%i",&notas[i]);
		}
		
	}
	
	void muestra(int * notas, int n){
		for(int i=0;i<n;i++)//Muestra datos
		{
	
		printf("%i - ",notas[i]);
	
	
		}
		
		
	}