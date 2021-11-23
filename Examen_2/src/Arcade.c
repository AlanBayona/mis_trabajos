#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Arcade.h"

#define MONO 1
#define ESTEREO 2

//funciones normales
Arcade* arcade_new()
{
	return (Arcade*) malloc(sizeof(Arcade));
}

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* sonidoStr,char* cantDeJuegosStr,char* cantFichasStr, char* salonStr,char* juegosStr)
{
	Arcade* this = arcade_new();
	int idAux;
	int sonido;
	int cantDeFichasMax;
	int cantDeJuegos;
	if(		idStr!=NULL
			&& nacionalidadStr!=NULL
			&& sonidoStr!=NULL
			&& cantDeJuegosStr!=NULL
			&& cantFichasStr!=NULL
			&& salonStr!=NULL
			&&juegosStr!=NULL)
	{
		idAux=atoi(idStr);
		cantDeFichasMax=atoi(cantFichasStr);
		cantDeJuegos=atoi(cantDeJuegosStr);
		if(strcmp(sonidoStr, "STEREO")==0)
		{
			sonido=ESTEREO;
		}
		else if(strcmp(sonidoStr, "MONO")==0)
		{
			sonido=MONO;
		}

		if(!arcade_setNombreSalon(this, salonStr)
				&& !arcade_setId(this, idAux)
				&& !arcade_setCantDeFichas(this, cantDeFichasMax)
				&& !arcade_setCantDeJugadores(this, cantDeJuegos)
				&& !arcade_setNacionalidad(this, nacionalidadStr)
				&& !arcade_setSonido(this, sonido))
		{
			puts("Salio bien el newParametros");
		}
		else
		{
		arcade_delete(this);
		this=NULL;
		}
	}

	return this;
}

void arcade_delete(Arcade* this)
{
	if(this!=NULL)
	{
		free(this);
	}

}

int arcade_setId(Arcade* this,int id)
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


int arcade_getId(Arcade* this,int* id)
{
	int deteccion=-1;
	if(this!=NULL && id>0)
	{
		deteccion=0;
		*id=this->id;
	}
	return deteccion;
}


int arcade_setNombreSalon(Arcade* this,char* nombre)
{
	int deteccion=-1;
	if(this!=NULL && nombre!=NULL )
	{
		deteccion=0;
		strcpy(this->nombreSalon, nombre);
	}
	return deteccion;
}
int arcade_getNombreSalon(Arcade* this,char* nombreSalon)
{
	int deteccion=-1;
	if(this !=NULL && nombreSalon!=NULL)
	{
		deteccion=0;
		strcpy(nombreSalon, this->nombreSalon);
	}
	return deteccion;
}


//////////////////////////////////////////////////////////////77

int arcade_setJuego(Arcade* this,char* nombreDeJuego)
{
	int deteccion=-1;
	if(this!=NULL && nombreDeJuego!=NULL )
	{
		deteccion=0;
		strcpy(this->juego, nombreDeJuego);
	}
	return deteccion;
}
int arcade_getJuego(Arcade* this,char* nombreDeJuego)
{
	int deteccion=-1;
	if(this!=NULL && nombreDeJuego!=NULL )
	{
		deteccion=0;
		strcpy(nombreDeJuego, this->juego);
	}
	return deteccion;
}


/////////////////////////////////////////////////////////////////////////////////
int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int deteccion=-1;
	if(this!=NULL && nacionalidad!=NULL )
	{
		deteccion=0;
		strcpy(this->nacionalidad, nacionalidad);
	}
	return deteccion;
}
int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int deteccion=-1;
	if(this!=NULL && nacionalidad!=NULL )
	{
		deteccion=0;
		strcpy(nacionalidad, this->nacionalidad);
	}
	return deteccion;
}






////////////////////////////////////////////////////////////////////////////



int arcade_setCantDeJugadores(Arcade* this,int cantjugadores)
{
	int deteccion=-1;
	if(this!=NULL && cantjugadores>=0)
	{
		deteccion=0;
		this->cantidadDeJugadores=cantjugadores;
	}
	return deteccion;
}
int arcade_getCantDeJugadores(Arcade* this,int* cantJugadores)
{
	int deteccion=-1;
	if(this!=NULL && cantJugadores>=0)
	{
		deteccion=0;
		*cantJugadores=this->cantidadDeJugadores;
	}
	return deteccion;
}

/////////////////////////////////////////////////////////////////////////////////////////

int arcade_setCantDeFichas(Arcade* this,int cant_maxFichas)
{
	int deteccion=-1;
	if(this!=NULL && cant_maxFichas>=0 )
	{
		deteccion=0;
		this->cant_maximaDeFichas=cant_maxFichas;
	}
	return deteccion;
}
int arcade_getCantDeFichas(Arcade* this,int* cant_maxFichas)
{
	int deteccion=-1;
	if(this!=NULL && cant_maxFichas>0)
	{
		deteccion=0;
		*cant_maxFichas=this->cant_maximaDeFichas;
	}
	return deteccion;
}




///////////////////////////////////////////////



int arcade_setSonido(Arcade* this,int sonido)
{
	int deteccion=-1;
	if(this!=NULL && (sonido>0 && sonido<=2))
	{
		deteccion=0;
		this->sonido=sonido;
	}
	return deteccion;
}
int arcade_getSonido(Arcade* this,int* sonido)
{
	int deteccion=-1;
	if(this!=NULL && (sonido>0 && sonido<=2))
	{
		deteccion=0;
		*sonido=this->sonido;
	}
	return deteccion;
}









int OrdenarPorNombre(void* arcadeAnterior, void* arcadePosterior)
{
	int ordenamiento=-4;
	Arcade* empleadoAux=(Arcade*)arcadeAnterior;
	Arcade* empleadoAux2=(Arcade*)arcadePosterior;

	if(empleadoAux!=NULL && empleadoAux2!=NULL)
	{
		ordenamiento=stricmp(empleadoAux2->juego, empleadoAux->juego);
	}



	return ordenamiento;
}






/*

int OrdenarPorSueldo(void* empleadoAnterior, void* empleadoPosterior)
{
	int retorno=0;
	Arcade* empleadoAux=(Arcade*)empleadoAnterior;
	Arcade* empleadoAux2=(Arcade*)empleadoPosterior;

	if(empleadoAux->sueldo!=empleadoAux2->sueldo)
	{
		if(empleadoAux->sueldo>empleadoAux2->sueldo)
		{
			retorno=1;
		}
		else if(empleadoAux->sueldo<empleadoAux2->sueldo)
		{
			retorno=-1;
		}
	}



	return retorno;
}

int OrdenarPorHora(void* empleadoAnterior, void* empleadoPosterior)
{
	int retorno=0;
	Arcade* empleadoAux=(Arcade*)empleadoAnterior;
	Arcade* empleadoAux2=(Arcade*)empleadoPosterior;

	if(empleadoAux->horasTrabajadas!=empleadoAux2->horasTrabajadas)
	{
		if(empleadoAux->horasTrabajadas>empleadoAux2->horasTrabajadas)
		{
			retorno=1;
		}
		else if(empleadoAux->horasTrabajadas<empleadoAux2->horasTrabajadas)
		{
			retorno=-1;
		}
	}



	return retorno;
} */


