/*
 * Parse.c
 *
 *  Created on: 23 nov. 2021
 *      Author: alanb
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "LinkedList.h"
#include "Inputs.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	Arcade* arcadeAux;// nunca habia usado tantas veces la palabr Aux jeje
	int deteccion=-1;
	char idAux[64];
	char nacionalidad[65];
	char sonido[64];
	char cantDeJuegos[64];
	char fichasMax[64];
	char salon[65];
	char cantFichas[65];

	puts("Entro al menos a la funciond e parse");
	if(pFile!=NULL && pArrayListArcade !=NULL)
	{puts("hay algo en el ´pFile");
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nacionalidad,sonido,cantDeJuegos,fichasMax,salon,cantFichas)==7)
		{
			puts("\nLLego a pasar el fopen\n");
			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nacionalidad,sonido,cantDeJuegos,fichasMax,salon,cantFichas)==7)
				{
					arcadeAux=arcade_newParametros(idAux,nacionalidad,sonido,cantDeJuegos,fichasMax,salon,cantFichas);
					if(arcadeAux!=NULL)
					{
						deteccion=0;
						ll_add(pArrayListArcade, arcadeAux);
					}
					else
					{
						arcade_delete(arcadeAux);
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
