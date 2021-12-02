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
#include "Calculos.h"




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
	int deteccion;
	deteccion=-1;
	eLibro* pLibroAux=libro_new();
	int idAux;
	char tituloAux[128];
	char autorAux[128];
	int precioAux;
	int editorialAux;
	if(pListaDeLibros!=NULL && pLibroAux!=NULL)
	{
		for(int i=0; i<=ll_len(pListaDeLibros); i++)
		{
			pLibroAux=ll_get(pListaDeLibros,i);
			if(libro_getId(pLibroAux, &idAux)==0
					&& libro_getEditorialId(pLibroAux, &editorialAux)==0
					&& libro_getAutor(pLibroAux, autorAux)==0
					&& libro_getPrecio(pLibroAux,&precioAux)==0
					&& libro_getTitulo(pLibroAux, tituloAux)==0)
			{
				puts("\n\tLISTA DE EMPLEADOS:");
				switch(editorialAux)
				{
					case 1:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [Planeta]\n\n", idAux, tituloAux, autorAux, precioAux);

						break;
					case 2:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [SIGLO XXI EDITORES]\n\n", idAux, tituloAux, autorAux, precioAux);
						break;
					case 3:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [PEARSEON]\n\n", idAux, tituloAux, autorAux, precioAux);
						break;
					case 4:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [Minotauro]\n\n", idAux, tituloAux, autorAux, precioAux);
						break;
					case 5:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [SALAMANDRA]\n\n", idAux, tituloAux, autorAux, precioAux);
						break;
					case 6:
						printf("*ID: [%d]\tTitulo: [%s]\tAutor: [%s]\tPrecio: [%d]\tEditorial: [PENGUIN BOOKS]\n\n", idAux, tituloAux, autorAux, precioAux);
						break;

				}



			}

		}
		deteccion=0;
	}
	else
	{
		puts("Salio mal el controllearList");
		libro_delete(pLibroAux);
	}




    return deteccion;
}





int controlador_mapearLista(LinkedList* pListaDeLibros)
{
	int deteccion=-1;

	if(pListaDeLibros!=NULL)
	{
		deteccion=ll_map(pListaDeLibros, hacerDescuento);
	}


	return deteccion;
}




int controlador_filtrarListaDeLibros(LinkedList* pListaDelibros)
{
	int deteccion=-1;
	if(pListaDelibros!=NULL)
	{

	}



	return deteccion;
}





