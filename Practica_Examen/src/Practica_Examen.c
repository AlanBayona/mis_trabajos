/*
 ============================================================================
 Name        : Practica_Examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"


#define DISPLAYS_LEN   100


int main(void) {
	setbuf(stdout, NULL);

	Display displaysList[DISPLAYS_LEN];

	disp_initList(displaysList, DISPLAYS_LEN);




	return EXIT_SUCCESS;
}

//tengo trabajo para el fin de semana maquina de la programacion

//ALTA
//1)buscar lugar libre: HACER
//2) llamo a funcion de load: LISTOOO

//MODIFICAR
//1)pedir auser que ingrese un ID
//2)buscar por id: HACER
//3)llamar a funcion que modifica: HACER
