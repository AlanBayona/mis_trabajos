/*
 * utn.h
 *
 *  Created on: 14 sep. 2021
 *      Author: alanb
 */

#ifndef UTN_H_
#define UTN_H_

typedef struct{
	float ladoUno;
	float ladoDos;
	float ladoTres;
}eTriangulo;

//triangulo
int triangulo_cargar(eTriangulo* myEscaleno);




//cadena de caracteres

int comprobadorTexto(char cadena[]);


int myGets(char* cadena, int len);
int arrayPromedio(int valores_ingresado[], int largo);
int sumarEnteros(int* pResultado, int numero_uno, int numero_dos);
int sumarFlotante(float* pResultado, float numero_uno, float numero_dos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int  minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char mensajeError, int minimo, int maximo, int reintentos);
#endif /* UTN_H_ */
