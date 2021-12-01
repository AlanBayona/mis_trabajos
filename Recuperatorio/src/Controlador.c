/*
 * Controlador.c
 *
 *  Created on: 30 nov 2021
 *      Author: cesar
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Inputs.h"
#include "LinkedList.h"




/**
 * \brief Carga los datos de los libros desde el archivo
 * \param nomDelArchivo char*
 * \param pListaDeLibros LinkedList*
 * \return deteccion int
 */
int controlador_CargarLista(char* nomDelArchivo, LinkedList* pListaDeLibros)
{
	int deteccion=-1;

	FILE* pArchivo;

	if(pListaDeLibros!=NULL && nomDelArchivo!=NULL)
	{
		if((pArchivo=open(nomDelArchivo, "r"))!=NULL)
		{
			if(parser_bookFromText(nomDelArchivo, pListaDeLibros)==0)
			{
				deteccion=0;
			}
			else
			{
				puts("\nError en el parse, revisa el el parse");
			}
		}
	}
	else
	{
		puts("Error. lista o archivo son NULL");
	}


	return deteccion;
}




int controlador_OrdenarPorAutor(LinkedList* pListaDeLibros)
{
	int deteccion=-1;

	if(pListaDeLibros!=NULL)
	{
		deteccion=ll_sort(pListaDeLibros, OrdenarPorAutor, 1);
		if(deteccion!=0)
		{
			deteccion=-1;
		}
	}



	return deteccion;
}



int controlador_MostrarListaDeLibros(LinkedList* pListaDeLibros)
{
	int deteccion=-1;





	return deteccion;
}



