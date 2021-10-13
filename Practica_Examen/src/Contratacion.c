/*
 * Contratacion.c
 *
 *  Created on: 12 oct 2021
 *      Author: cesar
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contratacion.h"

#define LIBRE 0
#define OCUPADO 1

/*
 * int idcontratacion;
	int isEmpty;
	int cuit;
	int cantidadDeDias;
	char nombredelarchivo;
	int idPantalla;
 *
 * */

int modificarPantalla(Display displaysList[], int len)
{
	int deteccion;
	int i;

	mostrarPantallasConId(&displaysList, len);

	if(displaysList!=NULL && len>0)
	{

	}



	return deteccion;
}



//función para mostrar todo el array e mio struct
void mostrarPantallasConId(Display displaysList[], int len)
{
	if(displaysList!=NULL && len>0){
			for(int i=0; i<len; i++)
			{
				if(displaysList[i].flagEmpty==OCUPADO && displaysList[i].id>0)
				{
					printf("Pantalla nº:%d con el id:%d", i, displaysList[i].id);
				}
			}
	    }
}






//sirve para pedir al usuario cargar una struct
int disp_initList(Display displaysList[], int len)
{
	int deteccion;
	int i;
	deteccion=0;
		if(displaysList!=NULL && len>=0)
		{
			for(i=0; i<len; i++)
			{
				displaysList[i].flagEmpty=LIBRE;
			}
			deteccion=1;
		}

		return deteccion;
}

//función de alta del display

//hacer la funcion buscarPorId

int buscarPorId(Display displaysList[], int len)
{
	int deteccion;
	int idBuscado;

	deteccion=-1;
	if(displaysList!=NULL && len>0)
	{
		printf("Ingrese el id, que busca");
		scanf("%d", &idBuscado);
			for(int i=0; i<len; i++)
			{
				if(displaysList[i].id==idBuscado && displaysList[i].flagEmpty==LIBRE)
				{
					deteccion=i;
				}
			}
	}




	return deteccion;
}



int buscarLugarVacio(Display displaysList[], int len)
{
	int i;
	int index;
		if(displaysList!=NULL && len>=0)
		{
			for(i=0; i<len; i++)
			{
				if(displaysList[i].flagEmpty==LIBRE)
				{
					index=i;
					break;
				}


			}
		}
		else
		{
			index=-1;
		}

		return index;
}






int disp_loadDisplay(Display* pDisplay)
{
	int tipo;
	float precio;
	int id;
	char nombre[30];
	char direccion[30];
	int deteccion;
	deteccion=-1;

	if(utn_getFloat(&tipo,"Ingrese 1: LED o 0:LCD","ERROR",0,2,3)==0)
	{
		if(utn_getFloat(&precio, "Ingrese precio", "QUe HacEs, Loc0?!",0,10000000.000000,3 )==0)
		{

			//debe ser cambiado por las funciones que no hice
			puts("Ingrese un nombre");
			scanf("%s", &nombre);
			puts("ingrese direccion");
			scanf("%s", &direccion);
			puts("Da una ID diferente(esto es de prueba)");
			scanf("%d", &id);//debo hacer la verga que no entendi con static
				if(nombre!=NULL && direccion!=NULL)
				{
					pDisplay->type=tipo;
					pDisplay->price=precio;
					pDisplay->id=id;
					strcpy(pDisplay->name, nombre);
					strcpy(pDisplay->address, direccion);
					deteccion=0;
				}

		}
	}

	return deteccion;
}



int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int deteccion;
	int i;
	float bufferFloat;// esta variable es un auxiliar para poder pasar el dato por puntero
	deteccion=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos!=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			scanf("%f", bufferFloat);
			if(bufferFloat>minimo && bufferFloat<maximo)
			{
			//la condicion de minimo y max debe cambiar , cuando aprende bien cadena de caracteres
				deteccion=0;
				*pResultado=bufferFloat;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}

	}
		return deteccion;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int deteccion= -1;
	int bufferInt;
	int i;

	 for(i=0; i<reintentos; i++)
	 {
		if(pResultado!=NULL && mensaje!= NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			printf("%s", mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				deteccion=0;
				break;
			} else
			{
				printf("%s", mensajeError);
			}

		}

	 }


		return deteccion;
}





