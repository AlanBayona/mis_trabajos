/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Inputs.h"
#include "LinkedList.h"
#include "Controlador.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	LinkedList* pListaDeLibros=ll_newLinkedList();


	do
	{

		mostrarMenu();
		if(pedirTipoInt(&opcion, "", "Error\n", 1, 8, 2)==0)
		{

			switch(opcion)
			{
				case 1:
					if(ll_isEmpty(pListaDeLibros)==1)
					{
						controlador_CargarLista("Datos_Recu_2_Dic_2021_TN.csv", pListaDeLibros);
					}
					break;
				case 2:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_OrdenarPorAutor(pListaDeLibros);
					}
					break;
				case 3:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_MostrarListaDeLibros(pListaDeLibros);

					}
					break;
				case 4:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_mapearLista(pListaDeLibros);
					}
					break;
				case 5:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						if(pedirTipoInt(&opcion, "\tSub-Menu\n1. ", mensajeError, minimo, maximo, reintentos))
						{

						}
					}
					break;
			}
		}

	}while(opcion!=8);

	return EXIT_SUCCESS;
}
