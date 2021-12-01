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

	if(pedirTipoInt(&opcion, "", "Error\n", 1, 8, 2)==0)
	{
		do
		{
			switch(opcion)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
			}




		}while(opcion!=8);
	}
	return EXIT_SUCCESS;
}
