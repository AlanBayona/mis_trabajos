#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

static int validarFloat(char cadenaFloat[]);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int validarEntero(char charDeEnteros[]);





int PedirTipoInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int deteccion= -1;
	int bufferInt;
	int i;

	 for(i=0; i<reintentos; i++)
	 {
		if(pResultado!=NULL && mensaje!= NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			printf("%s", mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				deteccion=0;
				break;
			} else
			{
				printf("%s", mensajeError);
			}

		}

	 }


		return deteccion;
}



int PedirTipoFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	//primero ante nada declare algunas variables utiles
	int deteccion; //sera de retorno y el que verifique si esta bien
	int i; // index de la array.
	float bufferFloat;// esta variable es un auxiliar para poder pasar el dato por puntero
	deteccion=-1;//Tomo que salio mal desde un principio

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos!=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			//aca directamente usamos la funcion getFloat para cargar un numero float
			if(getFloat(&bufferFloat)==0)//ahi obtendremos la validacion mediante la funcion
			{
					if(bufferFloat>minimo && bufferFloat<maximo)
					{
					//la condicion de minimo y max debe cambiar , cuando aprende bien cadena de caracteres
						deteccion=0;
						//ahora el numero que se uso para cargar el numero float
						*pResultado=bufferFloat;
						//lo vuelvo a cargar en el puntero que ingrese dentro del parametro de la funcion
						break;
					}
					else
					{
						printf("%s", mensajeError);//mensaje de error por si la cosa se pone complicada xd
					}
			}
		}

	}

	return deteccion;//0 para si salio bien
}



int myGets(char cadena[], int len)
{
	if(cadena != NULL && len > 0 && fgets(cadena, len,stdin)==cadena)
	{
		fflush(stdin);
			if(cadena[strlen(cadena)-1]=='\n')//no me quedo claro pero creo que para evitar revisar espacios de mas
			{
				cadena[strlen(cadena)-1]='\0';//osea que el lugar anterior donde se de el salto de linea
			}//se pondra un \0 para terminar cualquier cadena de caracteres
			return 0;
	}

	return -1;
}



static int validarFloat(char cadenaFloat[])//osea aunque sea guardado, al final, en una variable float
{//de forma discreta fuera de los ojos del usuario. Se esta pidiendo una cadena
	//Y aca es donde se valida
	int deteccion;
	int flagPunto;
	flagPunto=0;
	deteccion=-1;
	if(cadenaFloat!=NULL && strlen(cadenaFloat)>0)//la funcion strlen es usado para saber, en int, la cantidad de caracteres antes de un \0
	{
		for(int i=0; cadenaFloat[i]!='\0'; i++)//mientras no hay un \0 este bucle se repetira
		{
			if(i==0 && (cadenaFloat=='-' || cadenaFloat=='+')) //con esto puedo saber si hay un mas o menos adelante
			{//aunque falta pulir mas cosas

				//tengo la intencion de verificar si es un float en caracteres
				if(cadenaFloat[i]<48 && cadenaFloat[i]>57)//donde 48=0 y 57=9 en ascii
				{
						deteccion=0;//osea que esta saliendo bien.
				}
				else if(flagPunto=0 && cadenaFloat[i]== 46)
				{
					flagPunto=-1;
				} else {
					deteccion=-1;
					break;
				}
			}
		}
	}


	return deteccion;
}
static int getInt(int* pResultado)//esta funcion en complemento de getFloat(debe cambiar el nombre) por eso es static
{
	int deteccion=-1;
	char buffer[64];

	if(pResultado!=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && validarEntero(buffer))//luego con validarFloat, valido si la funcion ingresado por myGet sea numero, en este caso un numero float.
		{
			*pResultado=atoi(buffer);
			deteccion=0;
		}
	}

	return deteccion;
}

static int getFloat(float* pResultado)//esta funcion en complemento de getFloat(debe cambiar el nombre) por eso es static
{
	int deteccion=-1;
	char buffer[64];//creo una array de tipo array para almacenar lo que el usuario ingrese

	if(pResultado!=NULL)
	{//se usa la funcion myGet para pedir una cadena para
		if(myGets(buffer,sizeof(buffer))==0 && validarFloat(buffer))//luego con validarFloat, valido si la funcion ingresado por myGet sea numero, en este caso un numero float.
		{
			*pResultado=atof(buffer);//esta funcion es para convertir las cadena de char en float, osea debe tener un punto (.)
			deteccion=0;//valido que salio bien con el 0
		}
	}

	return deteccion;
}
static int validarEntero(char charDeEnteros[])
{
	int deteccion;
	deteccion=-1;
	if(charDeEnteros!=NULL && strlen(charDeEnteros)>0)
	{
		for(int i=0; charDeEnteros[i]!='\0'; i++)
		{
			if(i==0 && (charDeEnteros=='-' || charDeEnteros=='+'))
			{


				if(charDeEnteros[i]<48 && charDeEnteros[i]>57)//donde 48=0 y 57=9 en ascii
				{
						deteccion=0;//osea que esta saliendo bien.

				}
				else
				{
					deteccion=-1;
					break;
				}
			}
		}
	}
	return deteccion;
}