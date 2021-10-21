#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Arcade.h"
#include "Salon.h"

#define LIBRE 0
#define OCUPADO 1

static int buscarArcadesEnLocales(eArcade list[], int len, int idABuscar);








/*
 * \brief Esta funcion cumple con el trabajo de imprimir los salones que tengan mas de 4 arcades
 * \param listaSalones Array recibe a la entidad eSalon
 * \param listaArcades Array que recibe la lista de los Arcades
 * \param lenSalon Recibe el largo del array de salones
 * \param lenArcade Recibe el largo del array de arcades
 * \return deteccion 0(salio bien) -1(salio mal)
 */

int informe_listarSalonesConMasDeCuatroArcades(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)
{
	int deteccion;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0)
	{
		printf("\tLISTA DE SALONES CON MAS DE 4 ARCADES:\n");
		for(int i=0; i< lenSalon; i++)
		{
		if(listaSalones[i].isEmpty==OCUPADO)
		{
			if(buscarArcadesEnLocal(listaArcades, lenSalon, listaSalones[i].id)>4)
			{
				printf("\tID: %d\n",list[i].id);
				printf("\tNombre: %s\n",list[i].nombre);
				printf("\tDireccion: %s\n",list[i].direccion);
				if(list[i].tipo==SHOPPING)
				{
					printf("\tTipo: Shopping\n\n");
				}
				else
				{
					puts("\tTipo: Local\n\n");
				}
			}
		}
		}
		deteccion=0;
	}

	return deteccion;
}


/*
 * \brief Esta funcion tiene el solo trabajo de contar los arcades que estan en un local
 * \param recibe la entidad de Arcade siendo la array de la estructura anteriormente nombrada
 * \param recibe un tipo int siendo el largo del array de la entidad
 * \param y como ultimo recibe un tipo int, siendo el id del salon
 * \return esta funcion va a retornar un numero mayor a cero(contadorDeArcades), Solo me interesa que el local tenga mas de 4 arcades.
 */
static int buscarArcadesEnLocales(eArcade list[], int len, int idABuscar)
{
	int contadorDeArcades;
	contadorDeArcades=0;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1 && list[i].idSalon==idABuscar)
		{
			contadorDeArcades++;
		}
	}

	return contadorDeArcades;
}
