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
	int indexAux;
	Employee employeesList[LEN]={{12,"Alan","Auget",3.1415,4,1},{13,"Hobbs","Maru",30.9,2,1}};
	Employee employeeAux;
	initEmployees(&employeesList, LEN);
	do{

		seeMenu();

		PedirTipoInt(&option, "\n", "Opcion invalida", 0, 6, INTENTOS);

		switch(option)
		{
		case 1:

			if(addEmployeesAux(&employeeAux)==0)
			{
				if((addEmployee(employeesList, LEN, crearId(), employeeAux.name, employeeAux.lastName, employeeAux.salary, employeeAux.sector))==-1)
				{
					puts("ERROR. VOLVIENDO AL MENU.");//esto es de prueba de codeo
					break;
				}
				else{
					puts("Informacion guardada.(Ahora puedes acceder a las otras opciones ^w^)");
					puts("Volviendo al menu...");
				}
			}
			break;
		case 2:
			if(findEmpty(employeesList, LEN)!=-1)
			{
				puts("Maquina por aca me avisan que no ingresaste nada.");
				puts("Asi que, para el lobby...");
				break;
			}
			else
			{
				printEmployees(&employeesList, LEN);
				if(pedirTipoInt(&employeeAux.id, "Elija el ID del empleado que desee modificar", "DEJE DE TRATAR DE BUGGEARME!!", 0, 1000000, 3)==0)
				{
					if(pedirTipoInt(&option, "\tBienvanido a modificar campos.\n1-MOD: nombre/name\n2-MOD: Apellido/lastName\n3-MOD: Salario/salary\n4-MOD:Sector\nSALIR- USE: 5\n", "OPCION INVALIDA", 0, 6, 2)==0)
					{
						if(modifyEmployeebyId(&employeesList, LEN, employeeAux.id, option)!=0)
						{
							if(option==5)
							{
								puts("Regresando al menu principal");
								option=0;
							}
							else
							{
								puts("Intentos agotados.");
								puts("Volviendo al menu....");

							}
						}
						else
						{
							printf("El empleado con el ID: %d. Fue actualizado", employeeAux.id);
						}

					}
				}
			}
			break;
		case 3:
						if(findEmpty(employeesList, LEN)!=-1)
						{
							puts("Maquina por aca me avisan que no ingresaste nada.");
							puts("Asi que, para el lobby...");
							break;
						}
						else
						{
							printEmployees(&employeesList, LEN);
							if(pedirTipoInt(&employeeAux.id, "Elija el ID del empleado que desee modificar", "DEJE DE TRATAR DE BUGGEARME!!", 0, 1000000, 3)==0)
							{
								if(removeEmployee(&employeesList, LEN, employeeAux.id)==0)
								{
									puts("La baja del empleado se realizo con exito");
								}
								else
								{
									printf("EL ID: %d ya no existe",employeeAux.id);
								}
							}
						}
			break;
		case 4:
			//informes, aca debo informar todo. Parece mas facil de lo debido
				//se subdivide en un menu que debo fabricar. aunque lo mas probable
				//que se resuelva con el mensaje de la funcion
					//usar la variable option. al acabo no sirve mantener ese numero cuando se haya hecho lo que se nesecitba
			break;
		case 5:
			puts("\nADIOS");
			break;

	printEmployees(&employeesList, LEN);

		}

	}while(option==5);

	return EXIT_SUCCESS;
}


