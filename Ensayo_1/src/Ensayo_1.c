/*
 ============================================================================
 Name        : Ensayo_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define INTENTOS 2
//int utn_getNumero(int pResultado, char* mensaje, char mensajeError, int minimo, int maximo, int reintentos);

int main(){
	setbuf(stdout, NULL);
	int valor_uno;

	if(utn_getNumero(&valor_uno, "Ingrese un numero: ", "Error\n", 0,10,INTENTOS)==-1){
		puts("Sin intentos");
	} else {
		printf("El valor ingresado es de: %d", valor_uno);
	}



	return 0;
}


/*int utn_getNumero(int pResultado, char* mensaje, char mensajeError, int minimo, int maximo, int reintentos)
{



}*/
