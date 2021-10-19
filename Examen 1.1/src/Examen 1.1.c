/*
 ============================================================================
 Name        : 1.c
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
		if(pedirTipoInt(&opcion, "\t*MENU*\n*1-ALTA DE SALON\n*2-ELIMINAR SALON\n*3-IMPRIMIR SALONES\n*4-INCORPORAR ARCADE\n*5-MODIFICAR ARCADE\n*6-ELIMINAR ARCADES\n*7-IMPRIMIR ARCADES\n*8-IMPRIMIR JUEGOS\n*9-SALIR\n", "MAL", 0, 3, 99)==0)
		{
			switch(opcion)
			{

			case 1:
				if(agregarSalon(listaSalones, CANT_SALONES)==0)
				{

					puts("\nSalio bien");//recordar borrar
					flag=1;
				}
				else
				{
					puts("\nERROR.\n Volviendo al menu...");
				}


					break;

			case 2:

					if(imprimirArraySalones(listaSalones, CANT_SALONES)==0 && flag==1)
					{
						if(removerSalon(listaSalones, CANT_SALONES)==0)
						{
							puts("\nLa baja se realizo con exito.\n");
							if(verificarSalones(listaSalones, CANT_SALONES)<0)
							{
								flag=0;
							}
						}
						else
						{
							puts("\nERROR. Su id de baja no existe");
						}
					}
					else
					{
						puts("\nNo se ingreso ningun SALON.\nVolviendo al menu...\n");
					}
				break;
			case 3:

				if(imprimirArraySalones(listaSalones, CANT_SALONES)==0)
				{

				}



			}
		}
		else{
			puts("Revisa");
		}




	}while(opcion!=9);




	return EXIT_SUCCESS;
}
