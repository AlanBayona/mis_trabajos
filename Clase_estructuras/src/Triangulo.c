/*
 * Triangulo.c
 *
 *  Created on: 30 sep. 2021
 *      Author: alanb
 */

#include <stdio.h>
#include <stdlib.h>


void triangulo_mostrarPorReferencia(eTriangulo *tri){
    //printf("\nPor referencia \n \nLado A: %d, Lado B: %d, Lado C: %d", tri->ladoA,tri->ladoB, tri->ladoC);
    printf("\nPor referencia \n \nLado A: %d, Lado B: %d, Lado C: %d", (*tri).ladoUno,(*tri).ladoDos, (*tri).ladoTres);
}

int triangulo_cargar(eTriangulo* myEscaleno)
{
	// pedir al usuario los valores de los 3 lados y cargarlos
	// en la variable eTriangulo
	float ladoAAux;
	float ladoBAux;
	float ladoCAux;
	int ret;
	ret=-1;

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
				ret=0; // todo biennnn
			}
		}
	}
	return ret;
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
