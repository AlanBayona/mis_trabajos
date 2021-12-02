/*
 * Menu.c
 *
 *  Created on: 2 dic 2021
 *      Author: cesar
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void mostrarMenu()
{

	puts("\n ============================================= BIENVENIDO ========================================================");
	puts("*                                                                                                        ");
	printf("*-----------------------------------\t\tMENU\t\t------------------------------------------------------\n");
	puts("* OPCIONES:                                                                                 ");
	puts("*  1. Leer un archivo con los datos de libro.                                                              ");
	puts("*\t2. Ordenar la lista con el criterio por AUTOR.                                             ");//un \t equivale a 7 asteriscos(*)
	puts("*\t\t3. Imprirmir por pantalla todos los datos de los libros.                           ");
	puts("*\t\t\t4. Mapear lista para realizar descuento.                                             ");
	puts("*\t\t\t\t5. Generar el archivo de salida: mapeado.csv.                                     ");
	puts("*\t\t\t\t\t6. FILTRAR.                                                                 ");
	puts("***************************************** ..:7) Salir:.. **********************************************************");
}
