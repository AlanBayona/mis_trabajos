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
#include "Inputs.h"

#define CANT_SALONES 2


int main(void) {
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	int opcion;

	do
	{
		if(pedirTipoInt(&opcion, "\tMenu\n1-ALTA DE SALON\n2-ELIMINAR SALON\n", "ERROR", 0, 10, 999)==0)
		{
			switch(opcion)
			{

			case 1:
				if(agregarSalon(listaSalones, CANT_SALONES)==0)
				{
					puts("Salio bien");
				}
				else
				{
					puts("ERROR.\n Volviendo al menu...");
				}
					break;

			case 2:

				if(imprimirSalon(listaSalones, CANT_SALONES)==0)
				{
					if(removerSalon(listaSalones, CANT_SALONES)==0)
					{
						puts("La baja se realizo con exito.");
					}
					else
					{
						puts("ERROR. Su id de baja no existe");
					}
				}
				else
				{
					puts("No se ingreso ningun SALON.\nVolviendo al menu...");
				}
				break;
			}
		}




	}while(opcion==9);




	return EXIT_SUCCESS;
}
