/*
 * Parse.c
 *
 *  Created on: 23 nov. 2021
 *      Author: alanb
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "LinkedList.h"
#include "Inputs.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	eLibro* libroAux;// nunca habia usado tantas veces la palabr Aux jeje
	int deteccion=-1;
	char idAux[64];
	char tituloAux[65];
	char autorAux[64];
	char precioAux[64];
	char editorialAux[64];

	puts("Entro al menos a la funciond e parse");
	if(pFile!=NULL && pArrayListLibro !=NULL)
	{puts("hay algo en el ´pFile");
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idAux,tituloAux,autorAux,precioAux,editorialAux)==5)
		{
			puts("\nLLego a pasar el fopen\n");
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idAux,tituloAux,autorAux,precioAux,editorialAux)==5)
				{
					libroAux=libro_newParametros(idAux,tituloAux,autorAux,precioAux,editorialAux);
					if(libroAux!=NULL)
					{
						deteccion=0;
						ll_add(pArrayListLibro, libroAux);
					}
					else
					{
						arcade_delete(libroAux);
						deteccion=-1;
						break;
					}
				}
			}while(!feof(pFile));
		}
		fclose(pFile);

	}


    return deteccion;
}
