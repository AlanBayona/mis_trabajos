/*
 * Employee.h
 *
 *  Created on: 8 oct 2021
 *      Author: cesar
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct{
	int   id;
	char  name[51];
	char  lastName[51];
	float salary;
	int   sector;
	int   isEmpty;//1=ocupado y 0=vacio

}Employee;

void IncializarLista(Employee list[], int len);


//Funciones de la parte ALTA
void mostrarLista(Employee list[], int len);
int buscarLugarVacio();
int cargarListaDeEmpleados();
int crearId(void);

//Funciones para modificar

//Funciones para la baja




#endif /* EMPLOYEE_H_ */
