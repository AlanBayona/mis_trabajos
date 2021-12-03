/*
 * Calculos.c
 *
 *  Created on: 2 dic 2021
 *      Author: cesar
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int realizarDescuento( int precioADescontar, int descuento)
{
	int resultado;
	float resultado2;
	float porcentaje;
	float resta;
	float precioADescontarAux;
	float descuentoFloat;


	printf("\ndescuento: %d\n", descuento);
	descuentoFloat=(float)descuento;
	porcentaje = descuentoFloat/100;
	printf("\nPorcentaje: %f\n", porcentaje);
	precioADescontarAux=(float)precioADescontar;
		resta=(porcentaje * precioADescontarAux);
		printf("\nresta: %f\n", resta);

		resultado2=precioADescontarAux - resta;
		printf("Resultado:%f", resultado2);
		resultado=(int)resultado2;


	return resultado;
}
