/*
 * utn.c
 *
 *  Created on: 14 sep. 2021
 *      Author: alanb
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"




float ingresarFloat(char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}


//revisar esta cosa esta mal
void getString(char cadena[], char mensaje[], int tamaño)
{
	char auxiliar[tamaño];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", auxiliar);
	strcpy(cadena, auxiliar);
}




int triangulo_cargar(eTriangulo* myEscaleno)
{
	// pedir al usuario los valores de los 3 lados y cargarlos
	// en la variable eTriangulo.

	float ladoAAux;
		float ladoBAux;
		float ladoCAux;
		float ret=-1;
	​
		if(utn_getFloat( &ladoAAux  ,"ingrese lado A:","error",1,1000,3)==0)
		{
			if(utn_getFloat( &ladoBAux  ,"ingrese lado B:","error",1,1000,3)==0)
			{
				if(utn_getFloat( &ladoCAux  ,"ingrese lado C:","error",1,1000,3)==0)
				{
					// cargo los campos en la struct
					myEscaleno->ladoUno = ladoAAux;
					myEscaleno->ladoDos = ladoBAux;
					myEscaleno->ladoTres = ladoCAux;
					ret=0; // salio bien
				}
			}
		}
		return ret;
}

//esta funcion nos dara un promedio de numeros de una array, por ahora solo funciona con enteros
float arrayPromedio(int valores_ingresados[], int largo)
{
	int acumulador;
		float promedio;
		int i;
		acumulador=0;
		//la funcion sumar y se acumulara cada vez que avanza el i.
		for(i=0; i<largo; i++){

			acumulador+= valores_ingresados[i];
		}

		promedio= acumulador/largo;

		return promedio;
}




//esta funcion imprimira el array
void imprimirArrayEnteros(int arrayEnteros[], int tamaño )
{
	int i;
		for(i=0; i<tamaño; i++)
		{
			printf("posicion %d: %d", i+1, arrayEnteros[i]);
		}
}



int sumarEnteros(int* pResultado, int numero_uno, int numero_dos)
{
	int resultado;
	int retorno;
	if(numero_uno != NULL && numero_dos != NULL){
		resultado= numero_uno + numero_dos;
		retorno=0;
	} else {
		retorno=-1;
	}

	return retorno;
}

int sumarFlotante(float* pResultado, float numero_uno, float numero_dos)
{
	float resultado;
	int retorno;
	if(numero_uno != NULL && numero_dos != NULL){
		resultado= numero_uno + numero_dos;
		*pResultado=resultado;
		retorno=0;
	} else {
		retorno=-1;
	}

	return retorno;
}


//este pedira un float, pero aun debe ser modificado
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


int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int deteccion;
	int i;
	float bufferChar;// esta variable es un auxiliar para poder pasar el dato por puntero
	deteccion=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos!=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			scanf("%f", bufferChar);
			if(bufferChar>minimo && bufferChar<maximo)
			{
			//la condicion de minimo y max debe cambiar , cuando aprende bien cadena de caracteres
				deteccion=0;
				*pResultado=bufferChar;
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
