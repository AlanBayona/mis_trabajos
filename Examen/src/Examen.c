/*
 ============================================================================
 Name        : Examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"

#define CANT_SALONES 2


int main(void) {
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	int opcion;

	do
	{

		if(pedirTipoInt(&opcion, "\tMenu\n1-ALTA DE SALON", mensajeError, minimo, maximo, reintentos))
		{
			switch(opcion)

			case 1:

			case 2:
				if(imprimirSalon(listaSalones, CANT_SALONES)==0)
				{

				}
				else
				{
					puts("No se ingreso ningun SALON.\nVolviendo al menu...");
				}
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
		}




	}while(opcion==5);




	return EXIT_SUCCESS;
}
