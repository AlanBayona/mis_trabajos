/*
 * Triangulo.h
 *
 *  Created on: 30 sep. 2021
 *      Author: alanb
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

typedef struct{
	float ladoUno;
	float ladoDos;
	float ladoTres;
}eTriangulo;

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int triangulo_cargar(eTriangulo* myEscaleno);

void triangulo_mostrarPorReferencia(eTriangulo* myEscaleno);

#endif /* TRIANGULO_H_ */
