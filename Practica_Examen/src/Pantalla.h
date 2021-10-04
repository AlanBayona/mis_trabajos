/*
 * Pantalla.h
 *
 *  Created on: 30 sep. 2021
 *      Author: alanb
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_


#define LCD    0
#define LED    1

typedef struct {
	int type;
	float price;
	int id;
	char name [128];
	char address[128];
	int flagEmpty; // 0:ocupado 1:vacio/libre
}Display;

int disp_initList(Display displaysList[], int len);
int disp_loadDisplay(Display* pDisplay);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



#endif /* PANTALLA_H_ */
