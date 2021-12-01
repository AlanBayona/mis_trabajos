/*
 * Libro.c
 *
 *  Created on: 30 nov 2021
 *      Author: cesar
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Libro.h"

#define PLANETA 1
#define SIGLO_XXI_EDITORES 2
#define PEARSEON 3
#define MINOTAURO 4
#define SALAMANDRA 5
#define PENGUIN_BOOKS 6

//funciones normales
eLibro* libro_new()
{
	return (eLibro*) malloc(sizeof(eLibro));
}


eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* editorialStr)
{
	eLibro* this = libro_new();
	int idAux;
	int precioAux;
	int editorialAux;
	if(		idStr!=NULL
			&& tituloStr!=NULL
			&& autorStr!=NULL
			&& precioStr!=NULL
			&& editorialStr!=NULL)
	{
		idAux=atoi(idStr);
		precioAux=atoi(precioStr);
		if(strcmp(editorialStr, "PLANETA")==0)
		{
			editorialAux=PLANETA;
		}
		else if(strcmp(editorialStr, "SIGLO XXI EDITORES")==0)
		{
			editorialAux=SIGLO_XXI_EDITORES;
		}
		else if(strcmp(editorialStr, "PEARSEON")==0)
		{
			editorialAux=PEARSEON;
		}
		else if(strcmp(editorialStr, "MINUTAURO")==0)
		{
				editorialAux=MINOTAURO;
		}
		else if(strcmp(editorialStr, "SALMANDRA")==0)
		{
			editorialAux=SALAMANDRA;
		}
		else if(strcmp(editorialStr, "PENGUIN BOOKS")==0)
		{
			editorialAux=PENGUIN_BOOKS;
		}

		if(!libro_setId(this, idAux)
				&& !libro_setAutor(this, autorStr)
				&& !libro_setEditorialId(this, editorialAux)
				&& !libro_setPrecio(this, precioAux)
				&& !libro_setTitulo(this, tituloStr))
		{
			puts("Salio bien el newParametros");
		}
		else
		{
		libro_delete(this);
		this=NULL;
		}
	}

	return this;
}

void libro_delete(eLibro* this)
{
	if(this!=NULL)
	{
		free(this);
	}

}

int libro_setId(eLibro* this,int id)
{
	int deteccion= -1;
	static int maximoId= -1;
	if(this!=NULL)
	{
		deteccion=0;
		if(id<0)
		{
			maximoId++;
			this->id=maximoId;
		}
		else
		{
			if(id>maximoId)
			{
				maximoId=id;
				this->id=id;
			}
		}
	}
	return deteccion;
}


int libro_getId(eLibro* this,int* id)
{
	int deteccion=-1;
	if(this!=NULL && id>0)
	{
		deteccion=0;
		*id=this->id;
	}
	return deteccion;
}


int libro_setTitulo(eLibro* this,char* titulo)
{
	int deteccion=-1;
	if(this!=NULL && titulo!=NULL )
	{
		deteccion=0;
		strcpy(this->titulo, titulo);
	}
	return deteccion;
}
int libro_getTitulo(eLibro* this,char* titulo)
{
	int deteccion=-1;
	if(this !=NULL && titulo!=NULL)
	{
		deteccion=0;
		strcpy(titulo, this->titulo);
	}
	return deteccion;
}


//////////////////////////////////////////////////////////////77

int libro_setAutor(eLibro* this,char* autor)
{
	int deteccion=-1;
	if(this!=NULL && autor!=NULL )
	{
		deteccion=0;
		strcpy(this->autor, autor);
	}
	return deteccion;
}
int libro_getAutor(eLibro* this,char* autor)
{
	int deteccion=-1;
	if(this!=NULL && autor!=NULL )
	{
		deteccion=0;
		strcpy(autor, this->autor);
	}
	return deteccion;
}


/////////////////////////////////////////////////////////////////////////////////

int libro_setPrecio(eLibro* this,int precio)
{
	int deteccion=-1;
	if(this!=NULL && precio>=0)
	{
		deteccion=0;
		this->precio=precio;
	}
	return deteccion;
}
int libro_getPrecio(eLibro* this,int* precio)
{
	int deteccion=-1;
	if(this!=NULL && precio>=0)
	{
		deteccion=0;
		*precio=this->precio;
	}
	return deteccion;
}

/////////////////////////////////////////////////////////////////////////////////////////

int libro_setEditorialId(eLibro* this,int editorialId)
{
	int deteccion=-1;
	if(this!=NULL && editorialId>=0 )
	{
		deteccion=0;
		this->editorialId=editorialId;
	}
	return deteccion;
}
int libro_getEditorialId(eLibro* this,int* editorialId)
{
	int deteccion=-1;
	if(this!=NULL && editorialId>0)
	{
		deteccion=0;
		*editorialId=this->editorialId;
	}
	return deteccion;
}










int OrdenarPorNombre(void* arcadeAnterior, void* arcadePosterior)
{
	int ordenamiento=-4;
	eLibro* empleadoAux=(eLibro*)arcadeAnterior;
	eLibro* empleadoAux2=(eLibro*)arcadePosterior;

	if(empleadoAux!=NULL && empleadoAux2!=NULL)
	{
		ordenamiento=stricmp(empleadoAux2->autor, empleadoAux->autor);
	}



	return ordenamiento;
}
