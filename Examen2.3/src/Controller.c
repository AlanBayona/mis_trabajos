/*
 * Controller.c
 *
 *  Created on: 23 nov. 2021
 *      Author: alanb
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "Inputs.h"
#include "Parse.h"


#define MONO 1 // y riel=riel
#define ESTEREO 2



static int buscarPorId(LinkedList* this, int id);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int deteccion=-1;
	FILE* pArchivo;

	puts("Entre a la funcion controller al menos");
	if(pArrayListArcade!=NULL && path!=NULL)
	{
		puts("Hola llegue hasta aca, ");
		if(ll_isEmpty(pArrayListArcade)==1)
		{
			puts("paso");
			if((pArchivo=fopen(path,"r"))!=NULL)
			{
				puts("paso el null");
				if(parser_EmployeeFromText(pArchivo, pArrayListArcade)==0)
				{
					deteccion=0;
				}
				else
				{
					puts("\nSalio mal el parse");
				}
			}
		}
		else
		{
			puts("ERROR. No se consiguio cargarlo");
		}
	}



    return deteccion;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_loadFromBinary(char* path,LinkedList* pArrayListArcade)
{
	int deteccion=-1;

	FILE* fpArchivo;
	fpArchivo=fopen(path, "w");

	if(pArrayListArcade!=NULL && path!=NULL && fpArchivo!=NULL)
	{

		parser_ArcadeFromBinary(fpArchivo, pArrayListArcade);
		deteccion=0;
	}
	else
	{
		puts("ERROR. No se cargo de forma binaria");
	}




    return deteccion;
}
*/

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addArcade(LinkedList* pArrayListArcade) //falta actualizar
{
	int deteccion=-1;
	int idAux;
	char nombreSalon[128];
	char juego[128];
	char nacionalidad[128];
	int cantJugadores;
	int cantFichas;
	int sonido;
	Arcade* pArcade=arcade_new();
	if(pArrayListArcade!=NULL && pArcade!=NULL)
	{
		if(pedir_texto(nombreSalon, "Ingrese el nombre del empleado ingresado\n", "\nError\n", 1)==0)
		{
			if(pedir_texto(nacionalidad, "\nIngrese la nacionalidad del arcade\n", "\nError\n", 2)==0)
			{
				if(pedirDireccion(juego, "\nIngrese el nombre del juego\n", "\nError. Al ingresar un juego\n", 2)==0)
				{
					if(pedirTipoInt(&cantJugadores, "\nIngrese las hora del trabajas por el empleado\n ", "\nError al pedir horas\n", 1,999, 99)==0)
					{
						if(pedirTipoInt(&cantFichas, "\nIngrese el sueldo del empleado\n", "\nError al ingresar sueldo\n", 1, 999999, 1)==0)
						{
							if(pedirTipoInt(&sonido, "1)Mono\n2)Estereo\n", "Error", MONO, ESTEREO, 2)==0)
							{
								idAux=crearId();
								if(arcade_setSonido(pArcade, sonido)==0 &&
										arcade_setId(pArcade, idAux)==0 &&
										arcade_setCantDeFichas(pArcade, cantFichas)==0 &&
										arcade_setCantDeJugadores(pArcade, cantJugadores)==0 &&
										arcade_setJuego(pArcade, juego)==0 &&
										arcade_setNacionalidad(pArcade, nacionalidad)==0)
								{
									deteccion=ll_add(pArrayListArcade, pArcade);
								}
								else
								{
									puts("Error en la funcion controller_addEmployee");
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

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editArcade(LinkedList* pArrayListArcade) //incompleto
{
	int deteccion=-1;
	char juego[128];
	int cantJugadores;
	int opcion;
	int idABuscar;
	int index;

		if(controller_ListArcade(pArrayListArcade)==0)
		{
			if(pArrayListArcade!=NULL && pedirTipoInt(&idABuscar, "\nIngrese el ID del arcade que desee modificar\n", "\nError en la funcion editArcade\n", 0,99999999, 1)==0)
			{
				index=buscarPorId(pArrayListArcade, idABuscar);
				Arcade* arcadeAux=ll_get(pArrayListArcade, index);
				if(index>-1 && arcadeAux!=NULL)
				{

					if(pedirTipoInt(&opcion, "\n\tCAMPOS\n1. Editar Nombre del Salon.\n"
											 "2. Editar sonido\n"
											 "3. Editar h.\n"
											 "4. SALIR", "Error en la funcion de editEmployee\n", 1, 5,999)==0)
					{

						while(opcion!=4)
						{
								switch(opcion)
							{
								case 1:
									if(pedirDireccion(juego, "Ingrese el juego nuevo", "Error", 2)==0)
									{
										if(arcade_setJuego(arcadeAux, juego)==0)
										{
											puts("Nombre actualizado");
										}

									}
									break;
								case 2:
									if(pedirTipoInt(&cantJugadores, "Ingrese la nueva cantidad de jugadores\n", "ERROR\n", 1, 6,1)==0)
									{
										if(arcade_setCantDeJugadores(arcadeAux, cantJugadores)==0)
										{
											puts("Sueldo actualizado");
										}
									}
									break;


							}

						}
						deteccion=0;
					}
				}
			}
		}






    return deteccion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeArcade(LinkedList* pArrayListArcade) //
{
	int deteccion=-1;
	int indexABorrar;
	int id;
	Arcade* arcadeAux;
	if(pArrayListArcade!=NULL)
	{
		if(pedirTipoInt(&id, "Ingrese la posion del empleado que desee deletear\n", "ERROR. pedirtipo\n", 0, 9999999, 1)==0)
		{
			indexABorrar=buscarPorId(pArrayListArcade, id);
			if(indexABorrar>-1)
			{
					arcadeAux=ll_pop(pArrayListArcade, indexABorrar);
					if(arcadeAux!=NULL)
					{
						arcade_delete(arcadeAux);
							deteccion=0;

					}
				}
			}
		}


    return deteccion;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListArcade(LinkedList* pArrayListArcade) //
{
	int deteccion;
	deteccion=-1;
	Arcade* pArcadeAux=arcade_new();
	int idAux;
	char nombreSalon[128];
	char juego[128];
	char nacionalidad[128];
	int cantJugadores;
	int cantFichas;
	int sonido;
	if(pArrayListArcade!=NULL && pArcadeAux!=NULL)
	{
		for(int i=0; i<=ll_len(pArrayListArcade); i++)
		{
			pArcadeAux=ll_get(pArrayListArcade,i);
			if(arcade_getId(pArcadeAux, &idAux)==0
					&& arcade_getCantDeFichas(pArcadeAux, &cantFichas)==0
					&& arcade_getCantDeJugadores(pArcadeAux, &cantJugadores)==0
					&& arcade_getJuego(pArcadeAux,juego)==0
					&& arcade_getNacionalidad(pArcadeAux, nacionalidad)==0
					&& arcade_getNombreSalon(pArcadeAux, nombreSalon)==0
					&& arcade_getSonido(pArcadeAux, &sonido)==0)
			{
				puts("\n\tLISTA DE EMPLEADOS:");
				if(sonido==1)
				{
					printf("*NOMBRE: [%s]\tID: [%d]\tSalon: [%s]\tNacionalidad: [%s]\tJuego: [%s]\tJugadores: [%d]\tFichas Max: [%d]\tSonido: [Mono]\n\n", nombreSalon, idAux, nombreSalon, nacionalidad, juego, cantJugadores, cantFichas);
				}
				else if(sonido==2)
				{
					printf("*NOMBRE: [%s]\tID: [%d]\tSalon: [%s]\tNacionalidad: [%s]\tJuego: [%s]\tJugadores: [%d]\tFichas Max: [%d]\tSonido: [Estereo]\n\n", nombreSalon, idAux, nombreSalon, nacionalidad, juego, cantJugadores, cantFichas);
				}
			}

		}
		deteccion=0;
	}
	else
	{
		puts("Salio mal el controllearList");
		arcade_delete(pArcadeAux);
	}




    return deteccion;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortArcade(LinkedList* pArrayListArcade) //
{
	int deteccion=-1;
	if(pArrayListArcade!=NULL)
	{

		deteccion=ll_sort(pArrayListArcade, OrdenarPorNombre, 1);
		puts("Ordenando...");
		if( deteccion==0)
		{
			controller_ListArcade(pArrayListArcade);
			puts("\nOrdenamiento completo");
		}


	}

    return deteccion;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	FILE* pArchivoTexto;
	int deteccion=-1;
	int idAux;
	char nombreSalon[65];
	char juego[65];
	char nacionalidad[65];
	int cantJugadores;
	int cantFichas;
	int sonido;
	char sonidoStr[65];
	Arcade* aux;

	pArchivoTexto=fopen(path, "w");

	if(pArrayListArcade!=NULL && path!=NULL && pArchivoTexto!=NULL)
	{
		rewind(pArchivoTexto);
		fprintf(pArchivoTexto, "idAux,nombreAux,horasAux,sueldoAux\n");
		for(int i=0; i<ll_len(pArrayListArcade);i++)
		{
			aux=(Arcade*)ll_get(pArrayListArcade, i);
			if(aux!=NULL)
			{
				arcade_getId(aux, &idAux);
				arcade_getCantDeFichas(aux, &cantFichas);
				arcade_getCantDeJugadores(aux, &cantJugadores);
				arcade_getSonido(aux, &sonido);
				arcade_getNacionalidad(aux, nacionalidad);
				arcade_getNombreSalon(aux, nombreSalon);
				arcade_getJuego(aux, juego);
				if(sonido==1)
				{
					strcpy(sonidoStr, "MONO");
				}
				else if(sonido==2)
				{
					strcpy(sonidoStr, "STEREO");
				}
			}
			fprintf(pArchivoTexto,"%d,%s,%s,%d,%d,%s,%s\n", idAux,nacionalidad,sonidoStr,cantJugadores,cantFichas,nombreSalon,juego);
		}
		deteccion=0;
		printf("\nSalio bien el guardado\n");
	}

	fclose(pArchivoTexto);

    return deteccion;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int deteccion=-1;
	Employee* empleadoAux;
	FILE* pArchivoBinario=fopen(path, "wb");

		if(path!=NULL && pArrayListEmployee!=NULL && pArchivoBinario!=NULL)
		{
			for(int i=0; i<ll_len(pArrayListEmployee); i++)
			{
				empleadoAux=ll_get(pArrayListEmployee, i);
				fwrite(empleadoAux, sizeof(Employee), 1, pArchivoBinario);
			}
			puts("No saque el juego ni apaga la consola");
			puts("Guardando...");
			deteccion=0;
		}

			fclose(pArchivoBinario);
    return deteccion;
}
*/

static int buscarPorId(LinkedList* this, int id)
{
	int index=-1;
	Node* arcadeAux;
	Arcade* aux;

	for(int i=0; i<=ll_len(this); i++)
	{
		arcadeAux=ll_get(this, i);
		if(arcadeAux!=NULL)
		{
			aux=arcadeAux->pElement;
			if(aux->id==id)
			{
				index=i;
				break;
			}
		}
	}



	return index;
}

