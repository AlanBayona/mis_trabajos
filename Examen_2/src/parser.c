#include <stdio.h>
#include <stdlib.h>

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
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListArcade)
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
	{puts("hay algo en el ?pFile");
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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int deteccion=-1;

	Employee* pEmpleadoAuxiliar;

	puts("Ingreso a la funcion binary");
	if(pArrayListEmployee!=NULL && pFile!=NULL)
	{

		do{
			pEmpleadoAuxiliar=employee_new();
			if(fread(pEmpleadoAuxiliar,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, pEmpleadoAuxiliar);
				deteccion=0;
			}
			else
			{
				employee_delete(pEmpleadoAuxiliar);
				break;
			}




		}while(feof(pFile)==0);
		fclose(pFile);
	}
    return deteccion;
}
*/
