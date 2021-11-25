/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arcade.h"
#include "Inputs.h"
#include "Controller.h"
#include "Parse.h"
#include "LinkedList.h"


int main()
{
	setbuf(stdout, NULL);
	int opcion;
	int flagDeCarga=-1;

	LinkedList* listaDeArcades=ll_newLinkedList();
	if(listaDeArcades!=NULL && pedirTipoInt(&opcion, "\t\tMENU\n1)\n2)\n3)\n4)\n5)\n6)\n7)\n8)\n", "ERRROR", 1, 9, 2)==0)
	{
		do
		{
			switch(opcion)
			{
				case 1:
					if(flagDeCarga==-1 && controller_loadFromText("arcades.csv", listaDeArcades)==0)
					{
						flagDeCarga=0;
						puts("Carga conseguida. Volviendo al menu...");
					}
					else
					{
						puts("\nMaquina, ya cargo el archivo. No puedo hacer mas por usted.");
						puts("Volviendo al menu...");
					}
					break;
				case 2:
					if(controller_addArcade(listaDeArcades)==0)
					{
						puts("Arcade agregado...");
					}
					else
					{
						puts("Salio mal el alta, empiece por la la funcion addArcade");
					}
						puts("\nVolviendo al menu...");
					break;
				case 3:
					if(ll_isEmpty(listaDeArcades)==0)
					{
						if(controller_editArcade(listaDeArcades)==0)
						{

						}
					}
					break;
				case 4:
					if(ll_isEmpty(listaDeArcades)==0)
					{
						controller_removeArcade(listaDeArcades);
					}
					break;
				case 5:
					if(ll_isEmpty(listaDeArcades)==0)
					{
						controller_sortArcade(listaDeArcades);
						controller_ListArcade(listaDeArcades);

					}
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;

			}



		}while(opcion!=9);
	}

	return 0;
}
