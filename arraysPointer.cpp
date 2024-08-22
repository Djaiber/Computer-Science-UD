#include <iostream>

int main()
{
    int * notas; int n;
    printf("Ingrese cuantos datos: ");
    scanf("%i", &n);
    notas = new int[n];
    

    for(int i=0; i<n;i++){
    	
      printf("Ingrese el dato %i\n", i);
      scanf("%i", &notas[i]);
        
    }
    
    for(int i=0; i<n;i++){
		  printf("%i\n", &notas[i]);
        
    }
    
    
}