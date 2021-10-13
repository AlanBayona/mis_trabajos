/*
 * Contratacion.h
 *
 *  Created on: 12 oct 2021
 *      Author: cesar
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

typedef struct{
	int idcontratacion;
	int isEmpty;
	int cuit;
	int cantidadDeDias;
	char nombredelarchivo;
	int idPantalla;
}Contratacion;

void mostrarPantallasConId(Display displaysList[], int len);
int buscarPorId(Display displaysList[], int len);
int buscarLugarVacio(Display displaysList[], int len);
int disp_initList(Display displaysList[], int len);
int disp_loadDisplay(Display* pDisplay);




#endif /* CONTRATACION_H_ */
