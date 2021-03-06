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

#define OCUPADO  0
#define LIBRE   1

typedef struct {
	int type;
	float price;
	int id;
	char name [128];
	char address[128];
	int flagEmpty; // 0:ocupado 1:vacio/libre
}Display;

void mostrarPantallasConId(Display displaysList[], int len);
int modificarPantalla(Display displaysList[], int len, int id);
int buscarPorId(Display displaysList[], int len);
int buscarLugarVacio(Display displaysList[], int len);
int disp_initList(Display displaysList[], int len);
int disp_loadDisplay(Display* pDisplay);

#endif /* PANTALLA_H_ */
