/*
 * Inputs.h
 *
 *  Created on: 11 oct 2021
 *      Author: cesar
 */

#ifndef INPUTS_H_
#define INPUTS_H_




int myGets(char cadena[], int len);
int PedirTipoInt(int* pResultado, char* mensaje, char* mensajeError, int  minimo, int maximo, int reintentos);
int PedirTipoFloat(float* pResultado, char* mensaje, char mensajeError, int minimo, int maximo, int reintentos);




#endif /* INPUTS_H_ */
