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
#include "Employee.h"

#define LEN 2

int main(void) {
	setbuf(stdout, NULL);

	Employee employeesList[LEN]={{12,"HOLA","Auget",3.1415,4,1},{13,"Jaqui","Maru",30.9,2,1}};

	initEmployees(&employeesList, LEN);
	printEmployees(&employeesList, LEN);



	return EXIT_SUCCESS;
}
