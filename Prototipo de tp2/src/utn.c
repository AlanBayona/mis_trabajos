/*
 * utn.c
 *
 *  Created on: 14 sep. 2021
 *      Author: alanb
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int validarFloat(char cadenaFloat[]);
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
//es para la funcion utn_getFloat para poder saber si la cadena que pedire es un float
static int validarFloat(char cadenaFloat[]);






//revisar esta cosa esta mal
void getString(char cadena[], char mensaje[], int tamaño)
{
	char auxiliar[tamaño];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", auxiliar);
	strcpy(cadena, auxiliar);
}




int triangulo_cargar(eTriangulo* myEscaleno)
{
	// pedir al usuario los valores de los 3 lados y cargarlos
	// en la variable eTriangulo.

	float ladoAAux;
		float ladoBAux;
		float ladoCAux;
		float ret=-1;
	​
		if(utn_getFloat( &ladoAAux  ,"ingrese lado A:","error",1,1000,3)==0)
		{
			if(utn_getFloat( &ladoBAux  ,"ingrese lado B:","error",1,1000,3)==0)
			{
				if(utn_getFloat( &ladoCAux  ,"ingrese lado C:","error",1,1000,3)==0)
				{
					// cargo los campos en la struct
					myEscaleno->ladoUno = ladoAAux;
					myEscaleno->ladoDos = ladoBAux;
					myEscaleno->ladoTres = ladoCAux;
					ret=0; // salio bien
				}
			}
		}
		return ret;
}

//esta funcion nos dara un promedio de numeros de una array, por ahora solo funciona con enteros
float arrayPromedio(int valores_ingresados[], int largo)
{
	int acumulador;
		float promedio;
		int i;
		acumulador=0;
		//la funcion sumar y se acumulara cada vez que avanza el i.
		for(i=0; i<largo; i++){

			acumulador+= valores_ingresados[i];
		}

		promedio= acumulador/largo;

		return promedio;
}




//esta funcion imprimira el array
void imprimirArrayEnteros(int arrayEnteros[], int tamaño )
{
	int i;
		for(i=0; i<tamaño; i++)
		{
			printf("posicion %d: %d", i+1, arrayEnteros[i]);
		}
}


//funcion para numeros, debo moverlo a una biblioteca nueva
int sumarEnteros(int* pResultado, int numero_uno, int numero_dos)
{
	int resultado;
	int retorno;
	if(numero_uno != NULL && numero_dos != NULL){
		resultado= numero_uno + numero_dos;
		retorno=0;
	} else {
		retorno=-1;
	}

	return retorno;
}

//debo moverlo a una biblioteca llamada Calculadora o algo asi
int sumarFlotante(float* pResultado, float numero_uno, float numero_dos)
{
	float resultado;
	int retorno;
	if(numero_uno != NULL && numero_dos != NULL){
		resultado= numero_uno + numero_dos;
		*pResultado=resultado;
		retorno=0;
	} else {
		retorno=-1;
	}

	return retorno;
}


//version definitica, aunque debo cambiar el nombre de la funcion para que sea mas facil de entender
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
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

	return deteccion;
}


int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int deteccion;
	int i;
	float bufferChar;// esta variable es un auxiliar para poder pasar el dato por puntero
	deteccion=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos!=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			scanf("%f", bufferChar);
			if(bufferChar>minimo && bufferChar<maximo)
			{
			//la condicion de minimo y max debe cambiar , cuando aprende bien cadena de caracteres
				deteccion=0;
				*pResultado=bufferChar;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}

	}

	return deteccion;
}


//recuerda cuando ingreses los parametros de una funcion, son cosas que tu controlas. No lo controla el usuario
//ejemplo//recuerda que el resultado(como variable) solo es la conclusion de lo que se destinaria a algun lugar
//siendo una variable en este caso edad
//utn_getNumero(&edad, "Edad?", "Error valor invalido",0,200,3)//recuerda que los reintentos puedo usar una constante o un #define

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
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



//funcion con el proposito de saber si la cadena de caracteres que mande por parametro de otra funcion
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

//la madre de las funciones. Muy corta para la relevancia de esta
int myGets(char* cadena, int len)
{
	if(cadena != NULL && len > 0 && fgets(cadena, len,stdin)==cadena)
	{
		fflush(stdin);//usado para que no se atasque algun char
			if(cadena[strlen(cadena)-1]=='\n')//no me quedo claro pero creo que para evitar revisar espacios de mas
			{
				cadena[strlen(cadena)-1]='\0';//osea que el lugar anterior donde se de el salto de linea
			}//se pondra un \0 para terminar cualquier cadena de caracteres
			return 0;
	}

	return -1;
}

//funcion con la que convierto una cadena de caracteres en una numero, en este caso float
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



