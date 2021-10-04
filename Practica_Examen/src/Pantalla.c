/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: alanb
 */


#include <stdio.h>
#include <stdlib.h>


int disp_initList(Display displaysList[], int len)
{
	int deteccion;
	int i;
	deteccion=0;
		if(displaysList!=NULL && len>=0)
		{
			for(i=0; i<len; i++)
			{
				displaysList[i].flagEmpty=1;
			}
			deteccion=1;
		}

		return deteccion;
}

//funcion de alta del display
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
		if(utn_getFloat(%precio, "Ingrese precio", "QUe HacEs, Loc0?!",0,10000000.000000,3 )==0)
		{
			if(utn_get)
			{

			}
		}
	}


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
