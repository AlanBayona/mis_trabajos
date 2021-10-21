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
#include "Arcade.h"

#define CANT_SALONES 2
#define CANT_ARCADES 4


int main(void)
{
	setbuf(stdout, NULL);

	eSalon listaSalones[CANT_SALONES];
	eArcade listaArcades[CANT_ARCADES];
	int opcion;
	int opcionChar;
	int flagSalon;
	int flagArcade;
	flagArcade=-1;
	flagSalon=-1;

	initSalon(listaSalones, CANT_SALONES);
	initArcade(listaArcades, CANT_ARCADES);

	do
	{
		if(pedirTipoInt(&opcion, "\t*MENU*\n*1-ALTA DE SALON\n*2-ELIMINAR SALON\n*3-IMPRIMIR SALONES\n*4-INCORPORAR ARCADE\n*5-MODIFICAR ARCADE\n*6-ELIMINAR ARCADES\n*7-IMPRIMIR ARCADES\n*8-IMPRIMIR JUEGOS\n*9-SALIR\n", "MAL", 0, 9, 99)==0)
		{
			switch(opcion)
			{

			case 1:
				if(agregarSalon(listaSalones, CANT_SALONES)==0)
				{
					puts("\nSalio bien");//recordar borrar
					flagSalon=1;
				}
				else
				{
					puts("\nERROR.\n Volviendo al menu...");
				}
					break;

			case 2:
					if(imprimirArraySalones(listaSalones, CANT_SALONES)==0 && flagSalon==1)
					{
						if(removerSalon(listaSalones, CANT_SALONES)==0)
						{
							puts("\nLa baja se realizo con exito.\n");
							if(verificarSalones(listaSalones, CANT_SALONES)<0)
							{
								flagSalon=0;
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

				if(imprimirArraySalones(listaSalones, CANT_SALONES)==0 && flagArcade==1)
				{
					puts("case 3 salio bien");
				}
				else
				{
					puts("Salio mal la impresion");
				}
				break;
			case 4:
				if(agregarArcade(listaArcades, CANT_ARCADES)==0)
				{
					flagArcade=0;
					puts("\nAlta concretada.\nVolviendo al Menu...");
				}
				else
				{
					puts("\nSalio mal. Volviendo al Menu...");
				}
				break;
			case 5:
				if(flagArcade==0 && modificarArcade(listaArcades, CANT_ARCADES)==0)
				{
					puts("\nLa modificacion se realizo con exito\n");
				}
				else
				{
					puts("Primero debe ingresar algun Arcade para der de baja, maquina");
					printf("flag: %d", flagArcade);
				}
				break;
			case 6:
					if(flagArcade==0 && flagSalon)
					{

						if(removerArcade(listaArcades,CANT_ARCADES, listaSalones, CANT_SALONES)==0)
						{
							puts("Se elimino con exito.\n Volviendo al Menu...");
						}
						else
						{
							puts("Eliminacion no concretado.\n Volviendo al menu....");
						}
					}
					else if(flagArcade!=0)
					{
						puts("\nIngrese un arcade primero");
					}
					else{
						puts("\nIngrese un salon primero, maquina de la programacion.");
					}

				break;

			case 7:
				if(flagArcade==0 && imprimirSoloArrayArcades(listaArcades, CANT_ARCADES)==0)
				{
					puts("\nVolviendo al Menu....");
				}
				else
				{
					puts("ERROR");
				}
				break;
			case 8:
				if(flagArcade==0 && arca_mostrarJuegos(listaArcades, CANT_ARCADES)==0)
				{
					puts("\nSalio bien\n");
				}
				break;
			case 9:
				if(flagArcade==0 && flagSalon==0)
				{
					if(pedirChar(&opcionChar, "\t*MENU*\n*A)Listar los salones con más de 4 arcades\n*B) Listar los arcades para más de 2 jugadores\n*C) Listar toda la información de un salón en específico\n*D) Listar todos los arcades de un salón determinado\n*E) Imprimir el salón con más cantidad de arcades\n"
											"*F) Imprimir el monto máximo en pesos que puede recaudar el salón \n*G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen\n*8-IMPRIMIR JUEGOS\n*9-SALIR\n", "Error", 'A', 'Z')==0)
					{






					}
				}
				else
				{
					puts("Dato incompleto para realizar el informe. Que hace? largo. No intente romper el codigo >:u");
				}

			}
		}

	}while(opcion!=10);




	return EXIT_SUCCESS;
}
