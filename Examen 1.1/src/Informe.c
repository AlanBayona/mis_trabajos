#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Arcade.h"
#include "Salon.h"

#define LIBRE 0
#define OCUPADO 1

#define SHOPPING 1
#define LOCAL 2

static int buscarArcadesEnLocales(eArcade list[], int len, int idABuscar);
static void listarArcades(eArcade listaArcades[], int len, int idABuscar);
static int encontrarMaximo(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade);







/*
 * \brief Esta funcion cumple con el trabajo de imprimir los salones que tengan mas de 4 arcades
 * \param listaSalones Array recibe a la entidad eSalon
 * \param listaArcades Array que recibe la lista de los Arcades
 * \param lenSalon Recibe el largo del array de salones
 * \param lenArcade Recibe el largo del array de arcades
 * \return deteccion 0(salio bien) -1(salio mal)
 */

int informe_listarSalonesConMasDeCuatroArcades(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)//A
{
	int deteccion;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		printf("\tLISTA DE SALONES CON MAS DE 4 ARCADES:\n");
		for(int i=0; i< lenSalon; i++)
		{
		if(listaSalones[i].isEmpty==OCUPADO)
		{
			if(buscarArcadesEnLocales(listaArcades, lenSalon, listaSalones[i].id)>4)
			{
				printf("\tID: %d\n", listaSalones[i].id);
				printf("\tNombre: %s\n",listaSalones[i].nombre);
				printf("\tDireccion: %s\n",listaSalones[i].direccion);
				if(listaSalones[i].tipo==SHOPPING)
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




int informe_listarArcadesParaMasDeDosJugadores(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)//B
{
	int deteccion;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		printf("\tLISTA DE SALONES CON MAS DE 4 ARCADES:\n");
		for(int i=0; i< lenArcade; i++)
		{
			if(listaArcades[i].isEmpty==OCUPADO && listaArcades[i].cant_jugadores >2)
			{
					printf("\tID: %d\n", listaArcades[i].id);
					printf("\tCantidad de jugadores: %d\n",listaArcades[i].cant_jugadores);
					printf("\tNombre de juego: %s\n",listaArcades[i].nombreDelJuego);
					printf("\tSALON: %s", listaSalones[buscarPorId(listaSalones, lenSalon, listaArcades[i].idSalon)].nombre);


			}
		}
		deteccion=0;
	}

	return deteccion;
}


int informe_listarInfoDeSalonBuscadoPorId(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)//C
{
	int deteccion;
	int indexSalon;
	int idABuscar;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		if(pedirTipoInt(&idABuscar, "Para listar info debe ingresar el ID que busca\n", "ERROR", 1, 9999, 3)==0)
		{
			indexSalon=buscarPorId(listaSalones, lenSalon, idABuscar);
			if(indexSalon>0)
			{
				printf("\tNombre: %s\n",listaSalones[indexSalon].nombre);
				if(listaSalones[indexSalon].tipo==SHOPPING)
				{
					printf("\tTipo: Shopping\n\n");
				}
				else
				{
					puts("\tTipo: Local\n\n");
				}
				printf("\tDireccion: %s\n",listaSalones[indexSalon].direccion);
				printf("Cantidad de Arcades que posee: %d", contadorDeArcades(listaArcades, lenArcade, listaSalones[indexSalon].id));
			}
		}


	}

	return deteccion;
}

int contadorDeArcades(eArcade list[], int len, int idABuscar)
{
	int cont_DeArcades;
	cont_DeArcades=0;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1 && list[i].idSalon==idABuscar)
		{
			cont_DeArcades++;
		}
	}

	return cont_DeArcades;
}









int informe_listarArcadesDeUnSalonBuscadoPorId(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)//D
{
	int deteccion;
	int indexSalon;
	int idABuscar;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		if(pedirTipoInt(&idABuscar, "Para listar info debe ingresar el ID que busca\n", "ERROR", 1, 9999, 3)==0)
		{
			indexSalon=buscarPorId(listaSalones, lenSalon, idABuscar);
			if(indexSalon>0)
			{
				printf("\tNombre: %s\n",listaSalones[indexSalon].nombre);
				if(listaSalones[indexSalon].tipo==SHOPPING)
				{
					printf("\tTipo: Shopping\n\n");
				}
				else
				{
					puts("\tTipo: Local\n\n");
				}
				listarArcades(listaArcades, lenArcade, listaSalones[indexSalon].id);
			}
		}


	}

	return deteccion;
}



static void listarArcades(eArcade listaArcades[], int len, int idABuscar)
{
	int cont_DeArcades;
	cont_DeArcades=0;
	for(int i=0; i<len; i++)
	{
		if(listaArcades[i].isEmpty==1 && listaArcades[i].idSalon==idABuscar)
		{
			if(listaArcades[i].isEmpty==OCUPADO && listaArcades[i].cant_jugadores >2)
			{
					printf("\t\tID: %d\n", listaArcades[i].id);
					printf("\tNacionalidad: %s\n",listaArcades[i].nacionalidad);
					printf("\tCantidad de jugadores: %d\n",listaArcades[i].cant_jugadores);
					printf("\tCantidad de fichas maxima: %d\n",listaArcades[i].fichasMaxima);
					printf("\n\t\tNombre de juego: %s\n",listaArcades[i].nombreDelJuego);


			}
		}
	}

}




int informe_ImprimirSalonConMasArcades(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)//E
{
	int deteccion;
	int indexSalon;
	int arcadesMax;
	int cant_arcades;
	arcadesMax=0;
	deteccion=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		deteccion=0;
		indexSalon=encontrarMaximo(listaSalones, listaArcades, lenSalon, lenArcade);

				printf("\tID: %d\n",listaSalones[indexSalon].id);
				printf("\tNombre: %s\n",listaSalones[indexSalon].nombre);
				if(listaSalones[indexSalon].tipo==SHOPPING)
				{
					printf("\tTipo: Shopping\n\n");
				}
				else
				{
					puts("\tTipo: Local\n\n");
				}
				printf("\tDireccion: %s\n",listaSalones[indexSalon].direccion);
				printf("Cantidad de Arcades que posee: %d", contadorDeArcades(listaArcades, lenArcade, listaSalones[indexSalon].id));



	}



	return deteccion;
}



static int encontrarMaximo(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade)
{
	int indexSalon;
	int arcadesMax;
	int cant_arcades;
	arcadesMax=0;
	indexSalon=-1;

	if(listaSalones!=NULL && lenSalon>0 && listaArcades!=NULL && lenArcade>0)
	{
		for(int i=0; i<lenSalon; i++)
		{
			if(listaSalones[i].isEmpty==OCUPADO)
			{

				cant_arcades=contadorDeArcades(listaArcades, lenArcade, listaSalones[i].id);
				if(arcadesMax<cant_arcades)
				{
					arcadesMax=cant_arcades;
					indexSalon=i;
				}

			}
		}
	}


	return indexSalon;
}

