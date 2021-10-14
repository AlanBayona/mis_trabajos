/*
 * Pantalla.c
 *
 *  Created on: 30 sep. 2021
 *      Author: alanb
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Inputs.h"


//Modificacion//acá empieza las funciones de modificación


int modificarPantalla(Display displaysList[], int len)
{
	int deteccion;
	int index;
	deteccion=-1;


	if(displaysList!=NULL && len>0)
	{

		mostrarPantallasConId(&displaysList, len);
		index=buscarPorId(&displaysList, len);
		if(index>0)
		{
			modCamposDePantalla(&displaysList, len, index);
		}

	}

	return deteccion;
}



int modCamposDePantalla(Display displaysList[], int len, int index)
{
	int deteccion;
	int opcion;
	Display displaysAux;
	deteccion=-1;

	if(PedirTipoInt(&opcion, "\t¿Que desea modificar?\n1-type\n2-Price\n3-name\n4-address\n5-SALIR\n", "OPTION INVALIDA", 0, 6, 999)==0)
	{
		switch(opcion)
		{
			case 1:
				if(PedirTipoInt(&displaysAux.type, "Ingrese el tipo que desee cambiar.", "Incorrecto", 0, 5, 3)==0)
				{
					deteccion=0;
					displaysList->type=displaysAux.type;

				}
				break;

			case 2:
				if(PedirTipoFloat(&displaysAux.price, "Ingrese el precio nuevo", "Error", 0.0, 9999.999, 3)==0)
				{
					deteccion=0;
					displaysList->price=displaysAux.price;
				}
				break;

			case 3:
				if(pedir_texto(&displaysAux.name, "Ingrese el nombre nuevo", "Nono", 3)==0)
				{
					deteccion=0;
					strcpy(&displaysList->name, displaysAux.name);
				}
				break;
			case 4:
				if(pedirDireccion(&displaysAux.address, "Ingrese la nueva direccion.", "ERROR", 3)==0)
				{
					deteccion=0;
					strcpy(&displaysList->address, displaysAux.address);
				}
				break;
			case 5:
				deteccion=5;



		}
	}





	return deteccion;
}

















void mostrarPantallasConId(Display displaysList[], int len)
{
	if(displaysList!=NULL && len>0){
			for(int i=0; i<len; i++)
			{
				if(displaysList[i].flagEmpty==OCUPADO && displaysList[i].id>0)
				{
					printf("Pantalla nº:%d con el id:%d", i, displaysList[i].id);
				}
			}
	    }
}





int disp_initList(Display displaysList[], int len)
{
	int deteccion;
	int i;
	deteccion=0;
		if(displaysList!=NULL && len>=0)
		{
			for(i=0; i<len; i++)
			{
				displaysList[i].flagEmpty=LIBRE;
			}
			deteccion=1;
		}

		return deteccion;
}



int buscarPorId(Display displaysList[], int len)
{
	int deteccion;
	int idBuscado;

	deteccion=-1;
	if(displaysList!=NULL && len>0)
	{
		if(PedirTipoInt(&idBuscado, "Ingrese el id que desee buscar", "ERROR", 0, 100, 3)==0)
		{
			for(int i=0; i<len; i++)
			{
				if(displaysList[i].id==idBuscado && displaysList[i].flagEmpty==LIBRE)
				{
					deteccion=i;
				}
			}
		}
	}




	return deteccion;
}



int buscarLugarVacio(Display displaysList[], int len)
{
	int i;
	int index;
		if(displaysList!=NULL && len>=0)
		{
			for(i=0; i<len; i++)
			{
				if(displaysList[i].flagEmpty==LIBRE)
				{
					index=i;
					break;
				}
			}
			}
			else
			{
				index=-1;
			}

		return index;
}




//funcion de ALTA

int disp_loadDisplay(Display* pDisplay)
{
	int tipo;
	float precio;
	int id;
	char nombre[30];
	char direccion[30];
	int deteccion;
	deteccion=-1;

	if(PerdirT(&tipo,"Ingrese 1: LED o 0:LCD","ERROR",0,2,3)==0)// cambiar
	{
		if(utn_getFloat(&precio, "Ingrese precio", "QUe HacEs, Loc0?!",0,10000000.000000,3 )==0)
		{
			if(pedir_texto(&nombre, "Ingrese el de la pantalla.", "ERROR", 3)==0)
			{
				if(pedirDireccion(&direccion, "Ingrese la direccion", "ERROR", 3)==0)
				{
					pDisplay->type=tipo;
					pDisplay->price=precio;
					pDisplay->id=id;
					strcpy(pDisplay->name, nombre);
					strcpy(pDisplay->address, direccion);
					deteccion=0;
				}
			}
		}
	}

	return deteccion;
}





//funciones de la BAJA
















//esta cosa es para odenar por orden alfabetico



/*

 int pan_ordenarPorNombre(Pantalla* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Pantalla buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
*/
