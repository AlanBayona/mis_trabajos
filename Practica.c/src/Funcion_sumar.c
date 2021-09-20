/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int sumarEnteros(int uno, int dos );

int main(void) {
	setbuf(stdout, NULL);
	int uno;
	int dos;
	int resultado;

	printf("Ingresar un valor: ");
	scanf("%d", &uno);
	printf("Ingresar un segundo valor: ");
	scanf("%d", &dos);

	resultado = sumarEnteros(uno, dos);


	printf("\nEl valor ingresado es: %d", resultado); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

int sumarEnteros(int uno, int dos)
{
	int resultado;

	resultado= uno + dos;

	return resultado;
}

