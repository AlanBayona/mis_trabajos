/*
 * utn.c
 *
 *  Created on: 14 sep. 2021
 *      Author: alanb
 */

#include <stdio.h>
#include <stdlib.h>





















//recuerda cuando ingreses los parametros de una funcion, son cosas que tu controlas. No lo controla el usuario
//ejemplo//recuerda que el resultado(como variable) solo es la conclusion de lo que se destinaria a algun lugar
//siendo una variable en este caso edad
//utn_getNumero(&edad, "Edad?", "Error valor invalido",0,200,3)//recuerda que los reintentos puedo usar una constante o un #define

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
