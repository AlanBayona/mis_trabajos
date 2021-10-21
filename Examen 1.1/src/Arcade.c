#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Arcade.h"
#include "Salon.h"

#define MONO 1 // y riel=riel
#define ESTEREO 2
#define LIBRE 0
#define OCUPADO 1

//static int validarId(eSalon list[], int len, int id);
static void mostrarRelacionPorId(eSalon list[], int len, int idABuscar);
static int initJuegos(eJuego juegos[], int len);

//funcion de inicio






static int initJuegos(eJuego juegos[], int len)
{
	int deteccion;
	deteccion=-1;
	if(juegos!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			juegos[i].isEmpty=0;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}








int initArcade(eArcade listado[], int len)
{
	int deteccion;
	deteccion=-1;
	if(listado!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			listado[i].isEmpty=0;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}








/*
 * ebref Esta funcion cumple con el trabajo de imprimir
 * parametros Recibe un array de la entidad Employee y el largo del vector.
 * return Devuelve un 0 si salio bien y un -1 si salio mal.
 */



int imprimirSoloArrayArcades(eArcade list[], int len)
{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && len>0)
	{
		printf("\n\t\tLista de los Arcade:\n");
		for(int i=0; i< len; i++)
		{
			if(list[i].isEmpty==1)
			{

				printf("\t\tID: %d\n",list[i].id);
				printf("\tNacionalidad: %s\n",list[i].nacionalidad);
				printf("\tNombre del juego: %s\n",list[i].nombreDelJuego);
				printf("\tCantidad de jugadores: %d\n",list[i].cant_jugadores);
				printf("\tCantidad de fichas maxima: %d\n",list[i].fichasMaxima);
				if(list[i].sonido==MONO)
				{
					printf("\tTipo de sonido: Mono\n");
				}
				else
				{
					puts("\tTipo de sonido: Estereo\n");
				}
			}
		}
		deteccion=0;
	}

	return deteccion;
}





int imprimirArrayArcade(eArcade listadoArcades[], eSalon listadoSalones[], int lenArcade, int lenSalon)
{
	int deteccion;
	deteccion=-1;

	if(listadoSalones!=NULL && lenArcade>0 && listadoArcades!=NULL && lenSalon>0)
	{
		printf("\n\t\tLista de los Arcade:\n");
		for(int i=0; i< lenArcade; i++)
		{
			if(listadoArcades[i].isEmpty==1)
			{

				printf("\t\tID: %d\n",listadoArcades[i].id);
				printf("\tNacionalidad: %s\n",listadoArcades[i].nacionalidad);
				printf("\tNombre del juego: %s\n",listadoArcades[i].nombreDelJuego);
				printf("\tCantidad de jugadores: %d\n",listadoArcades[i].cant_jugadores);
				printf("\tCantidad de fichas maxima: %d\n",listadoArcades[i].fichasMaxima);
				if(listadoArcades[i].sonido==MONO)
				{
					printf("\tTipo de sonido: Mono\n");
				}
				else
				{
					puts("\tTipo de sonido: Estereo\n");
				}
				mostrarRelacionPorId(listadoSalones, lenSalon, listadoArcades[i].idSalon);
				printf("\t//ID que busco: %d\n", listadoArcades[i].idSalon);
			}
		}
		deteccion=0;
	}

	return deteccion;
}




static void mostrarRelacionPorId(eSalon list[], int len, int idABuscar)
{
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1 && list[i].id==idABuscar)
		{
			puts("\tLOCAL");
			printf("\n\tNombre: %s\n",list[i].nombre);
			printf("\tDireccion: %s\n",list[i].direccion);
			if(list[i].tipo==1)
			{
				printf("\tTipo: Shopping\n");
			}
			else
			{
				puts("\tTipo: Local\n");
			}
		}
	}
}









//ALTA

int agregarArcade(eArcade list[], int lenArcade)
{
	int deteccion;
	int index;
	eArcade arcadeAux;

	deteccion=-1;
	if(list!=NULL && lenArcade>0)
	{
		index=buscarArcadeVacio(list, lenArcade);
		if(index >= 0)
		{
			if(pedir_texto(&arcadeAux.nacionalidad, "\nIngrese la nacionadad del juego:\n", "ERROR. Intente de nuevo\n", 2)==0)
			{
				if(pedirDireccion(&arcadeAux.nombreDelJuego, "Ingrese el nombre del juego:\n", "ERROR tipo A. fallo en el nombre del juego\n", 2)==0)
				{
					if(pedirTipoInt(&arcadeAux.sonido, "\tIngrese tipo de sonido:\n1-Mono\n2-Estereo\n", "ERROR A\n", 1, 2, 3)==0)
					{
						if(pedirTipoInt(&arcadeAux.cant_jugadores,"\nCantidad de juegadores: ", "Error tipo A\n",1,6,3)==0)
						{
							if(pedirTipoInt(&arcadeAux.fichasMaxima, "\nIngrese la cantidad de fichas maximo que admite: ","ERROR tipo A", 1, 99, 3)==0)
							{
								if(pedirTipoInt(&arcadeAux.idSalon, "\nIngrese el id del cual pertenece este ARCADE: ", "Perdon, el id ingre", 1, 999, 2)==0)
								{
										arcadeAux.id=crearId();
										if(arcadeAux.id>0)
										{
											strncpy(list[index].nacionalidad, arcadeAux.nacionalidad, 51);
										    strncpy(list[index].nombreDelJuego, arcadeAux.nombreDelJuego, 51);
										    list[index].cant_jugadores=arcadeAux.cant_jugadores;
										    list[index].fichasMaxima=arcadeAux.fichasMaxima;
										    list[index].idSalon=arcadeAux.idSalon;
									        list[index].sonido=arcadeAux.sonido;
											list[index].id=arcadeAux.id;
											list[index].isEmpty=OCUPADO;

									//	printf("\n*ID: %d - Nombre: %s - Direccion: %s\n", salonAux.id, salonAux.nombre, salonAux.direccion);
										   deteccion=0;
										}
								}

							}
						}
					}
				}
			}
		}
	}


	return deteccion;

}


int buscarArcadeVacio(eArcade list[], int lenArcade)
{
	int index;
		index=-1;
		if(list!=NULL && lenArcade>0)
		{
			for(int i=0; i<lenArcade; i++)
			{
				if(list[i].isEmpty==LIBRE)//es 0 si esta libre
				{
					index=i;
					break;
				}
			}
		}
	return index;
}



/* static int validarId(eSalon list[], int len, int id)
{
	int index;
	index=-1;

			if(list!=NULL && len>0 && id>0)
			  {
				  for(int i=0; i<len; i++)
				  {
					  if(list[i].id==id)
					  {
						  index=i;
						  break;
					  }
				  }
			  }



	return index;
}*/


//BAJA
/*
 *\brief esta funcion hace la baja logica de un arcade
 *\param pido una array de una entidad, en este casi eArcade y su largo, siendo lenArcade
 *\return Devuelve -1 si hubo algun inconveniente y 0 si la funcion cumplio su objetivo
 */
int removerArcade(eArcade listArcades[], int lenArcade, eSalon listSalones, int lenSalon)
{
	int deteccion;
	int idBuscado;
	int opcion;
	deteccion=-1;
		if(listArcades!=NULL && lenArcade>0 && listSalones!=NULL && lenSalon>0)
		{
			imprimirArrayArcade(listArcades, listSalones, lenArcade, lenSalon)
			if(pedirTipoInt(&idBuscado, "Ingrese el id que desee remover", "Invalido", 0, 999, 1)==0)
			{
				for(int i=0; i<lenArcade; i++)
				{
					if(listArcades[i].id==idBuscado && listArcades[i].isEmpty==1)
					{
						if(pedirTipoInt(&opcion, "\n\tSeguro que desea borrar el Arcade?\n1-SI, MI REY.\n2-NO, ABORTE LA DECISION.\n", "Estas pendejo! solo hay dos optiones\n", 1, 2, 99)==0)
						{
							if(opcion==1)
							{
								listArcades[i].isEmpty=0;
								deteccion=0;
								break;
							}
							else
							{
								deteccion=1;
								break;
							}
						}
					}
				}
			}
		}



	return deteccion;
}




void mostrarJuegos(eJuego list[], int len)
{
	int i;

	printf("\tJUEGOS\n");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==1)
		{
			printf("* %s *\n", list[i].listaDeJuegos);
		}
	}
}

int arca_mostrarJuegos(eArcade listArcades[], int len)
{
	int deteccion;
	int flag;
	flag=0;
	eJuego listaAuxJuegos[25];
	deteccion=-1;

	if(listArcades != NULL && len > 0 && initJuegos(listaAuxJuegos, 25)==0)
	{
		for(int i=0; i<len; i++)

		{
			if(listArcades[i].isEmpty==1)
			{
				if(listarJuegos(listaAuxJuegos, 25, listArcades[i].nombreDelJuego)==0)
				{
					flag=0;
					continue;
				}
			}

		}

		if(flag==0)
		{
			mostrarJuegos(listaAuxJuegos, 25);
			deteccion=0;
		}

	}


	return deteccion;
}





int listarJuegos(eJuego list[], int len, char* juego)
{
	int deteccion;
	deteccion=-1;
	for(int i=0; i<len; i++)
	{
		if(strcmp(list[i].listaDeJuegos, juego)!=0 && list[i].isEmpty==LIBRE)
		{
			if(validarJuego(list, len, juego)==0)
			{
				strncpy(list[i].listaDeJuegos, juego, 51);
				list[i].isEmpty=1;
				deteccion=0;
				break;
			}
		}

	}

	return deteccion;
}



int validarJuego(eJuego listaJuegos[], int len, char* juego)
{
	  int deteccion;
	  deteccion=0;

			  if(listaJuegos!=NULL && len>0 && juego!=NULL)
			  {
				  for(int i=0; i<len; i++)
				  {
					  if(strcmp(listaJuegos[i].listaDeJuegos, juego)==0)
					  {
						  deteccion=-1;
						  break;
					  }
				  }
			  }
			  	 return deteccion;

}





//modificar

int modificarArcade(eArcade arcades[], int len)
{
	int deteccion;
	int idABuscar;
	int opcion;
	int cant_jugadoresAux;
	char nombreNuevoDelJuego[51];
	int index;
	deteccion=-1;

		if(arcades!=NULL && len>0)
		{
			if(imprimirSoloArrayArcades(arcades, len)==0 && pedirTipoInt(&idABuscar, "\nIngrese el Id del Arcade que desee modificar\n", "\nError\n", 1, 2, 2)==0)
			{
				index= arcade_buscarPorId(arcades, len, idABuscar);
				if(index>=0 && pedirTipoInt(&opcion, "\tMODIFICACION\n*1-Cantidad de jugadores\n*2-juego\n", "Opcion invalido", 1, 2, 2)==0)
				{
					switch(opcion)
					{
						case 1:
							if(pedirTipoInt(&cant_jugadoresAux, "\nIngrese la nueva cantidad de jugadores\n ", "ERROR", 1, 2, 2)==0)
							{
								arcades[index].cant_jugadores=cant_jugadoresAux;
								deteccion=0;
							}
						break;

						case 2:
							if(arca_mostrarJuegos(arcades, len)==0 && pedirDireccion(nombreNuevoDelJuego, "\nIngresa el nuevo nombre del juego\n", "ERROR", 3)==0)
							{
								strncpy(arcades[index].nombreDelJuego, nombreNuevoDelJuego, 51);
								deteccion=0;
							}
					}
				}
			}
		}
	return deteccion;
}




int arcade_buscarPorId(eArcade arcades[], int len,int id)
{
  int index;
  index=-1;

		  if(arcades!=NULL && len>0 && id>0)
		  {
			  for(int i=0; i<len; i++)
			  {
				  if(arcades[i].id==id && arcades[i].isEmpty==OCUPADO)
				  {
					  index=i;
					  break;
				  }
			  }
		  }
		  	 return index;
}
