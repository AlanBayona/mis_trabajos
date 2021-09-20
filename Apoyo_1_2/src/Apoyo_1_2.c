/*
 * Ejercicio 1-2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
fue ingresado.
 ============================================================================
 Name        : Apoyo_1_2.c
 Author      : Alan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main(void) {
	setbuf(stdout, NULL);
	int i;
	int numero_ingresado;
	int max;
	int min;
	int listado[TAM];
	int flag=1;

	for(i=0; i<TAM; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero_ingresado);

		if(flag==1)
		{
			max=numero_ingresado;
			min=numero_ingresado;
			listado[i]=numero_ingresado;
			flag=0;
		}
		 else if(numero_ingresado>max)
		{
			max=numero_ingresado;
			listado[i]=numero_ingresado;

		} else if(numero_ingresado<min){
			min=numero_ingresado;
			listado[i]=numero_ingresado;
		}


	}

	printf("Maximo es %d en el orden ", max);
	printf("\nMinimo es %d en el orden ", min);

	return EXIT_SUCCESS;
}
