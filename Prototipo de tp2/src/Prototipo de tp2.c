/*
 ============================================================================
 Name        : Prototipo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"

#define LEN 2
#define INTENTOS 999


int main(void) {
	setbuf(stdout, NULL);
	int option;
	Employee employeesList[LEN]={{12,"Alan","Auget",3.1415,4,1},{13,"Hobbs","Maru",30.9,2,1}};
	Employee employeeAux;
	initEmployees(&employeesList, LEN);
	do{

		PedirTipoInt(&option, "\n", "Opcion invalida", 0, 6, INTENTOS);

		if(option==1)
		{
			addEmployee(employeesList, LEN, crearId(), name, lastName, salary, sector);
		}

	printEmployees(&employeesList, LEN);

	}while();

	return EXIT_SUCCESS;
}


