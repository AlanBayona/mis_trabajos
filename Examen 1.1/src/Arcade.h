/*
 * Arcade.h
 *
 *  Created on: 19 oct. 2021
 *      Author: alanb
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "Salon.h"
typedef struct{
		char nacionalidad[51];
		int sonido;
		int cant_jugadores;
		int fichasMaxima;
		int idSalon;
		char nombreDelJuego[51];
		int id;
		int isEmpty; //0=libre 1=ocupado

} eArcade;

typedef struct{
	char listaDeJuegos[51];
	int isEmpty;
}eJuego;



void mostrarJuegos(eJuego list[], int len);
int listarJuegos(eJuego list[], int len, char* juego);
int arcade_buscarPorId(eArcade arcades[], int len,int id);


//funcion de inicio
int initArcade(eArcade listado[], int len);//completa


//funciones de ALTA
//completa
int agregarArcade(eArcade list[], int lenArcade);// completa
int buscarArcadeVacio(eArcade list[], int lenArcade);
int validarJuego(eJuego listaJuegos[], int len, char* juego);
//funciones de modificacion
int imprimirSoloArrayArcades(eArcade list[], int len);
int imprimirArrayArcade(eArcade listadoArcades[], eSalon listadoSalones[], int lenArcade, int lenSalon);
int modificarArcade(eArcade arcades[], int len);

//BAJA
int removerArcade(eArcade list[], int lenArcade);


int arca_mostrarJuegos(eArcade listaArcades[], int len);


#endif /* ARCADE_H_ */
