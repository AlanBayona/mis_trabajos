#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Inputs.h"


//funciones de impresion

//funciones ALTA

int agregarSalon(eSalon list[], int len)
{
	int deteccion;
	int index;
	eSalon salonAux;

	deteccion=-1;
	if(list!=NULL && len>0)
	{
		index=buscarSalonVacio(list, len);
		if(index>0){
			if(pedir_texto(&salonAux.nombre, "Ingrese el nombre del salon:\n", "ERROR. Intente de nuevo", 2)==0)
			{
				if(pedirDireccion(&salonAux.direccion, "Ingrese direccion del salon:\n", "ERROR", 2)==0)
				{
					if(pedirTipoInt(&salonAux->tipo, "\tIngrese tipo:\n1-Shopping\n2-Local\n", "Error", 0, 3, 2)==0)
					{
						salonAux.id=crearId();
						if(salonAux.id>0)
						{
							strncpy(list[index].nombre, salonAux.nombre, 51);
							strncpy(list[index].direccion, salonAux.direccion, 51);
							list[index].tipo=salonAux.tipo;
							list[index].id=salonAux.id;
							list[index].isEmpty=1;


							deteccion=0;

						}
					}
				}
			}
		}
	}


	return deteccion;

}




int initSalon(eSalon list[], int len)
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


/*int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int check;
	int index;
	check=-1;
	if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary!=NULL && sector>0)
	{
		index=findEmpty(&list, len);
		if(index>0)
		{
			list->id[index]=id;
			strncpy(list->lastName[index], lastName, 51);
			strncpy(list->lastName[index], lastName, 51);
			list->salary[index]=salary;
			list->sector[index]=sector;
			check=0;
		}
	}

	return check;
} */






/*
 * ebref Esta funcion cumple con el trabajo de imprimir
 * parametros Recibe un array de la entidad Employee y el largo del vector.
 * return Devuelve un 0 si salio bien y un -1 si salio mal.
 */

int imprimirSalon(eSalon list[], int len)

{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && len>0)
	{
		//printf("\tLista del ID:\n");
		for(int i=0; i< len; i++)
		{
			if(list[i].isEmpty==1)
			{
				printf("* ID: %d\n", list[i].id);
				printf("\tName: %s\n",list[i].nombre);
				printf("\tDireccion: %s\n",list[i].direccion);
			}
		}
		deteccion=0;
	}

	return deteccion;
}

int buscarSalonVacio(eSalon list[], int len)
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

/*int modifyEmployeebyId(Employee* list, int len, int id, int option)
{
	int check;
	int indexEmployee;
	char nombreAux[len];
	char apellidoAux[len];
	float salarioAux;
	int sectorAux;

	check=-1;


		if(list!=NULL && len>0)
		{
			indexEmployee=findEmployeeById(&list, len, id);
			switch(option)
			{
			  case 1:
				 if(pedir_texto(&nombreAux, "ingrese el nuevo nombre el empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee]->name, nombreAux, len);
				 }
				 else
				 {
					 check=-1;
				 }
				 break;
			  case 2:
				 if(pedir_texto(&apellidoAux, "ingrese el nuevo apellido del empleado.", "ERROR. VOLVIENDO AL MENU", 1)==0)
				 {
					 strncpy(list[indexEmployee]->lastName, apellidoAux, len);
				 }
				 else
				 {
				 	 check=-1;
				 }
				 break;
			  case 3:
				  if(pedirTipoFloat(&salarioAux, "Ingrese le nuevo salario del empleado", "ERROR. VOLVIENDO AL MENU...", -999999999999.999999, 9999999.9999999, 1)==0)
				  {
					  list[indexEmployee]->salary=salarioAux;
				  }
				  else
				  {
					  check=-1;
				  }
				  break;
			  case 4:
				  if(pedirTipoInt(&sectorAux, "Ingrese el sector en cual sera movido el empleado", "ERROR", 0, 6, 1)==0)
				  {
					  list[indexEmployee]->sector=sectorAux;
				  }
				  else
				  {
					  check=-1;
				  }
				  break;
			  case 5:
				  check=1;
				  break;

			}

		}



	return check;
}*/


int buscarPorId(eSalon list[], int len,int id)
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


int removerSalon(eSalon list[], int len)
{
	int deteccion;
	int idBuscado;
	deteccion=-1;
		if(list!=NULL && len>0)
		{
			if(pedirTipoInt(&idBuscado, "Ingrese el id que desee remover", "Invalido", 0, 999, 1)==0)
			{
				for(int i=0; i<len; i++)
				{
					if(list[i].id==idBuscado && list[i].isEmpty==1)
					{
						list[i].isEmpty=0;
						deteccion=0;
						break;
					}
				}
			}
		}



	return deteccion;
}









//aca iran las funciones static





int crearId(void)
{
  static int numeroMagico;
	numeroMagico=0;
		numeroMagico++;

	return numeroMagico;
}
