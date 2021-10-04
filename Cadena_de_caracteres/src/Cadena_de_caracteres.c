/*
 ============================================================================
 Name        : Cadena_de_caracteres.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20


int esNumerica(char cadena[], int tamanio);

int main(void) {
	setbuf(stdout, NULL);

	char cad1[5];
	char cad2[TAM];

	puts("Ingresa un char de tipo numerico");
	scanf("%s", &cad2);
	strcpy(cad1, cad2); //de derecha a izquierda//el nombre de la array es su lugar punto de referencia solo el nombre
	//con esa funcion puedo hacer esto     cad1 = cad2;
	puts(cad1);
	strcpy(cad2, "Chau");
	puts(cad2);

	strncpy(cad1, cad2, sizeof(cad1)-1);//el tercer argumento sirve para aclarar cuanto espacio como max puedo poner en la ubicacion
	//para poder frenar debo forzarlo por ej      cad1[10] (la pocision de la array)= "\0";

	cad1[sizeof(cad1)-1] = '\0';


	if(esNumerica(&cad2, TAM)==0)
	{
		puts("Es numerica");
	} else
	{
		puts("malio sal");
	}


	/*int len= strlen(cadenaDeCaracteres);
	printf("LEN: %d ", len);

	if(len<4){
		puts("NO");
	} else {
		puts("Si, mi rey");

*/
	return EXIT_SUCCESS;
}

int esNumerica(char cadena[], int tamanio)
{
	int deteccion;
	int i;
	deteccion=-1;
	if(cadena!=NULL && tamanio>0)
	{
		for(i=0; i<tamanio; i++)
		{
			if(cadena[i]!='\0');
			{
			  if(cadena[i]< 57 && cadena[i]>48) //ocurrio un error hace poco, por usar mal el operador logico
				{
					deteccion=0;

				}
			}

		}
	}


	return deteccion;
}



//int esTexto(char cadena[]){}

//int esAlFanumerica(char cadena[]){}

//int esMail(char[]){}

