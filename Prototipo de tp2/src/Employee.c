/*
 * Employee.c
 *
 *  Created on: 8 oct 2021
 *      Author: cesar
 */
/*
int   id;
	char  name[51];
	char  lastName[51];
	float salary;
	int   sector;
	int   isEmpty;*/
#include <stdio.h>
#include <string.h>
#include "Employee.h"
#include "Inputs.h"


void IncializarLista(Employee list[], int len)
{
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty=0;//significa que esta vacio
		}
	} else {
		puts("ERROR. Programador, verifique los parametros que ingreso.");
	}
}


//Funciones del ALTA

int cargarListaDeEmpleados(Employee list[], int len)
{
	int deteccion;

	Employee listaAuxiliar;


		if(list!=NULL && len>0)
		{
			if(myGets(listaAuxiliar.name, len)!=-1)
			{
				if(myGets(listaAuxiliar.lastName, len)!=-1)
				{
					if(PedirTipoFloat(listaAuxiliar.salary, "Ingrese el salario del empleado", "ERROR. Use numero reales, porfavor", 0.0, 999999, 2)==0)
					{
						if(PedirTipoInt(listaAuxiliar.sector, "Ingrese el sector del gil laburante.", "ERROR. Sector invalido", 0, 3, 2))
						{
							if((listaAuxiliar.id=crearId())>0)
							{
								list->lastName=listaAuxiliar.lastName;
								list->name=listaAuxiliar.name;
								list->salary=listaAuxiliar.salary;
								list->sector=listaAuxiliar.sector;
								list->id=listaAuxiliar.id;
							}
						}
					}
				}
			}
		}

	return deteccion;
}



void mostrarLista(Employee list[], int len)
{
	printf("\tLista del ID:\n");
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==1)
		{
			printf("* ID: %d\n", list[i].id);
			printf("\tName: %s\n",list[i].name);
			printf("\tLastName: %s\n",list[i].lastName);
			printf("\tSalary: %f\n",list[i].salary);
			printf("\tSector: %d\n",list[i].sector);
		}
	}
}

int buscarLugarVacio(Employee list[], int len)
{
	int index;
	index=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				index=i;
				break;
			}
		}
	}



	return index;
}



int crearId(void)
{
  static int numeroMagico;
	numeroMagico=0;
		numeroMagico++;

	return numeroMagico;
}
