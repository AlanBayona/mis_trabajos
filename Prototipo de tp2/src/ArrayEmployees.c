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
#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"


int initEmployees(Employee list[], int len)
{
	int deteccion;
	deteccion=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			list[i].isEmpty=0;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}


//Funciones del ALTA


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int check;
	int index;

	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary!=NULL && sector>0)
	{
		if((index=findEmpty(&list, len))==0)
		{
			list->id[index]=id;
			list->name[index]=name;
			list->lastName[index]=lastName;
			list->salary[index]=salary;
			list->sector[index]=sector;
		}
	}






	return check;
}








/*int addEmployees(Employee list[], int len)
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
}*/



int printEmployees(Employee* list, int length)

{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && length>0)
	{
		printf("\tLista del ID:\n");
		for(int i=0; i< length; i++)
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
		deteccion=0;
	}

	return deteccion;
}

int findEmpty(Employee list[], int len)
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




//funciones Modificacion

int modifyEmployeebyId(Employee* list, int len, int id, int option)
{
	int check;
	int indexEmployee;
	check=-1;


		if(list!=NULL && len>0)
		{
			indexEmployee=findEmployeeById(&list, len, id);
			switch(option)
			{
			  case 1:

			}

		}



	return check;
}


int findEmployeeById(Employee* list, int len,int id)
{
  int index;
  index=-1;

		  if(list!=NULL && len>0 && id>0 && id!=NULL)
		  {
			  for(int i=0; i<len; i++)
			  {
				  if(list[i].id==id)
				  {
					  index=i;
					  break;
				  }
			  }
		  }
		  	 return index;
}



//funcion de BAJA


int removeEmployee(Employee* list, int len, int id)
{
	int check;
	check=-1;
		if(list!=NULL && len>0 && id!=NULL)
		{
			for(int i=0; i<len; i++)
			{
				if(list[i].id==id)
				{
					list[i].isEmpty=0;
					check=0;
					break;
				}
			}
		}



	return check;
}







void seeMenu(){

	puts("\n ======================== BIENVENIDO =========================");
	puts("*                                                              *");
	printf("*---------------\t\tMENU\t\t---------------*\n");
	puts("* OPCIONES:                                                    *");
	puts("*  1. ALTA.                                                    *");
	puts("*\t2. MODIFICAR.                                           *");//un \t equivale a 7 asteriscos(*)
	puts("*\t\t3. BAJA.                                       *");
	puts("*\t\t\t4. INFORMAR.                           *");
	puts("************************ ..:5) Salir:.. ************************");
}










int crearId(void)
{
  static int numeroMagico;
	numeroMagico=0;
		numeroMagico++;

	return numeroMagico;
}