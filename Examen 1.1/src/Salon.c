#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "Inputs.h"


#define LIBRE 0
#define OCUPADO 1

#define SHOPPING 1

#define LOCAL 2







//funciones de impresion

//funciones ALTA

int agregarSalon(eSalon* list[], int len)
{
	int deteccion;
	int index;
	eSalon* salonAux= salon_new();

	deteccion=-1;
	if(list!=NULL && len>0)
	{
		puts("Estoy por buscar un lugar vacio");
		index=buscarSalonVacio(list, len);
		if(index>=0){
			if(pedir_texto(salonAux->nombre, "Ingrese el nombre del salon:\n", "ERROR. Intente de nuevo", 2)==0)
			{
				if(pedirDireccion(salonAux->direccion, "Ingrese direccion del salon:\n", "ERROR B", 2)==0)
				{
					if(pedirTipoInt(&salonAux->tipo, "\tIngrese tipo:\n1-Shopping\n2-Local\n", "ERROR C", 0, 3, 3)==0)
					{
						salonAux->id=crearId();
						if(salonAux->id>0)
						{
							list[index]=salonAux;

							printf("\n*ID: %d - Nombre: %s - Direccion: %s\n", list[index]->id, list[index]->nombre, list[index]->direccion);
							deteccion=0;

						}
					}
				}
			}
		}
	}else {puts("ACA");}


	return deteccion;

}




int initSalon(eSalon* list[], int len)
{
	int deteccion;
	deteccion=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{

			list[i]=NULL;//significa que esta vacio
		}
		deteccion=0;
	}

	return deteccion;
}


//Funciones del ALTA


/*
 * \brief Esta funcion cumple con el trabajo de imprimir
 * \param Recibe un array de la entidad Employee y el largo del vector.
 * \return Devuelve un 0 si salio bien y un -1 si salio mal.
 */

int imprimirArraySalones(eSalon* list[], int len)

{
	int deteccion;
	deteccion=-1;

	if(list!=NULL && len>0)
	{
		printf("\n\t\tLista de los Salones:\n");
		for(int i=0; i< len; i++)
		{
			if(list[i]!=NULL)
			{
				printf("\tID: %d\n",list[i]->id);
				printf("\tNombre: %s\n",list[i]->nombre);
				printf("\tDireccion: %s\n",list[i]->direccion);
				if(list[i]->tipo==SHOPPING)
				{
					printf("\tTipo: Shopping\n\n");
				}
				else
				{
					puts("\tTipo: Local\n\n");
				}
			}
		}
		deteccion=0;
	}

	return deteccion;
}

int buscarSalonVacio(eSalon* list[], int len)
{
	int index;
	index=-1;
	puts("Dentro de buscarSalon");
		for(int i=0; i<len; i++)
		{
			puts("Dentro del for");
			if(list[i]==NULL && len>0)//es 0 si esta libre
			if(list[i]->isEmpty==LIBRE)//es 0 si esta libre
			{
				index=i;
				printf("\nIndice vacio= %d\n",i);
				break;
			}
		}

	return index;
}


/*
 * \brief esta funcion buscar si esta al menos se cargo 1 un salon
 * \param tiene como parametrps una list de eSalon
 *
 */
int verificarSalones(eSalon* list[], int len)
{
	int index;
	index=-1;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i]!=NULL)//es 0 si esta libre
			{
				index=i;
				break;
			}
		}
	}



	return index;
}






//funcion de modificacion


int buscarPorId(eSalon* list[], int len,int id)
{
  int index;
  index=-1;

		  if(list!=NULL && len>0 && id>0)
		  {
			  for(int i=0; i<len; i++)
			  {
				  if(list[i]->id==id && list[i]!=NULL)
				  {
					  index=i;
					  break;
				  }
			  }
		  }
		  	 return index;
}



//funcion de BAJA


int removerSalon(eSalon* list[], int len)
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
					if(list[i]->id==idBuscado && list[i]!=NULL)
					{
					//	free(list[i]);​
						list[i] = NULL;
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
  static int numeroMagico=0;

		numeroMagico++;

	return numeroMagico;
}





eSalon* salon_new(void)
{
	eSalon* pSalon = malloc(sizeof(pSalon));
	if(pSalon!=NULL)
	{
		pSalon->isEmpty=0;
		pSalon->id=0;
	}
	return pSalon;




eSalon* display_new(void)
{
	eSalon* pDisplay = malloc(sizeof(eSalon));
	if(pDisplay!=NULL)
	{
		pDisplay->isEmpty=0;
		pDisplay->id=0;
	}
	return pDisplay;
}

