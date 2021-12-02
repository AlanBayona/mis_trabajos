/*
 * Calculos.c
 *
 *  Created on: 2 dic 2021
 *      Author: cesar
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int realizarDescuento(int* resultado, int precioADescontar, int descuento)
{
	int deteccion=-1;

	if(resultado!=NULL && precioADescontar!=NULL && descuento!=NULL)
	{
		*resultado=precioADescontar - (descuento / 10);
		(int)*resultado;
		deteccion=0;
	}

	return deteccion;
}
