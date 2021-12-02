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
#include "Libro.h"
#include "Controlador.h"
#include "Parse.h"




/**
 * \brief Carga los datos de los libros desde el archivo
 * \param nomDelArchivo char*
 * \param pListaDeLibros LinkedList*
 * \return deteccion int
 */
int controlador_CargarLista(char* nomDelArchivo, LinkedList* pListaDeLibros)
{
	int deteccion=-1;
	puts("Antes de toda comprobacion");
	FILE* pArchivoAux;

	if(pListaDeLibros!=NULL && nomDelArchivo!=NULL)
	{
		puts("Paso el primer NULL");
		pArchivoAux=fopen(nomDelArchivo, "r");
		if(pArchivoAux==NULL){puts("Esta vacia webon");}
		if(pArchivoAux!=NULL)
		{
			puts("Paso el NULL");
			if(parser_bookFromText(pArchivoAux, pListaDeLibros)==0)
			{
				puts("paso el parse");
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
	puts("Antes del primer NULL");
	if(pListaDeLibros!=NULL)
	{
		puts("Paso");
		deteccion=ll_sort(pListaDeLibros, OrdenarPorAutor, 1);
		printf("\nDeteccion: %d\n", deteccion);
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







int controlador_guardarLista(char* nomDelArchivo , LinkedList* pListaDeLibros)
{
	FILE* pArchivo;
	int deteccion=-1;
	int idAux;
	char tituloAux[128];
	char autorAux[128];
	int precioAux;
	int editorialAux;
	char editorialTexto[128];
	eLibro* libroAux;

	pArchivo=fopen(nomDelArchivo, "w");

	if(pListaDeLibros!=NULL && nomDelArchivo!=NULL && pArchivo!=NULL)
	{
		rewind(pArchivo);
		fprintf(pArchivo, "idAux,tituloAux,autorAux,precioAux,aditorialAux\n");
		for(int i=0; i<ll_len(pListaDeLibros);i++)
		{
			libroAux=(eLibro*)ll_get(pListaDeLibros, i);
			libro_getId(libroAux, &idAux);
			libro_getTitulo(libroAux, tituloAux);
			libro_getAutor(libroAux, autorAux);
			libro_getPrecio(libroAux, precioAux);
			libro_getEditorialId(libroAux, editorialAux);

				switch(editorialAux)
							{
								case 1:
									strcpy(editorialTexto, "Planeta");
									break;
								case 2:
									strcpy(editorialTexto, "SIGLO XXI EDITORES");
									break;
								case 3:
									strcpy(editorialTexto, "Pearson");
									break;
								case 4:
									strcpy(editorialTexto, "Minotauro");
									break;
								case 5:
									strcpy(editorialTexto, "SALAMANDRA");
									break;
								case 6:
									strcpy(editorialTexto, "PENGUIN BOOKS");
									break;

							}


			fprintf(pArchivo,"%d,%s,%s,%d,%s\n", idAux,tituloAux,autorAux,precioAux, editorialTexto);
		}
		deteccion=0;
		printf("\nSalio bien el guardado\n");
	}

	fclose(pArchivo);

    return deteccion;
}





