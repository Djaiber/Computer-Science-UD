#include <iostream>

int main()
{
    int * notas; int n;
    printf("Ingrese cuantos datos: ");
    scanf("%1", &n);
    notas = new int[n];
    

    for(int i=0; i<100;i++){
    	
      printf("Ingrese el dato %i", i);
      scanf("%i", &notas[i]);
        
    }
    
    for(int i=0; i<100;i++){
		  printf("%i", &notas[i]);
        
    }
    
    
}
