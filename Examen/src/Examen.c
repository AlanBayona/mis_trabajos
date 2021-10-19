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
#include <string.h>
#include "Salon.h"
#include "Inputs.h"

#define CANT_SALONES 2


int main(void) {
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	int opcion;
	int flag;
	flag=-1;

	initSalon(listaSalones, CANT_SALONES);

	do
	{
		if(pedirTipoInt(&opcion, "\tMENU\n1-ALTA DE SALON", "MAL", 0, 3, 1)==0)
		{
			switch(opcion)
			{

			case 1:
				if(agregarSalon(listaSalones, CANT_SALONES)==0)
				{

					puts("Salio bien");//recordar borrar
					flag=1;
				}
				else
				{
					puts("ERROR.\n Volviendo al menu...");
				}


					break;

			case 2:

				if(imprimirArraySalones(listaSalones, CANT_SALONES)==0 && flag==1)
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
		else{
			puts("Revisa");
		}




	}while(opcion!=9);




	return EXIT_SUCCESS;
}
