/*
 ============================================================================
 Name        : MiniCalculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//la razon de porque se declara primero esto
//es que el programa debe saber que es lo que va recibir la funcion main.
int multiplicarEnteros(int valor_uno, int valor_dos);
int sumarEnteros(int valor_uno, int valor_dos);
int restarEnteros(int valor_uno, int valor_dos);
int dividirEnteros(float* pResultado, int valor_uno, int valor_dos);

int main(void) {
	setbuf(stdout, NULL);//recuerda esa mierda.
	int numero_uno;//aunque pongas el resultado como float si las variables no son float
	int numero_dos;//va a ignorar cualquier decimal despues de la coma.
	float resultado;
	int deteccion_error;//util para comprobar si tiene algun error del usuario como el divir por cero.
	char operacion;// es un truco que pense para que pareciera la interfaz de una calculadora.

	//LA INTERFAZ(o al menos algo asi)
	printf("Hola, bienvenido.\n");
	printf("Ingrese un numero: ");
	scanf("%d", &numero_uno);
	printf("%d ", numero_uno);
	scanf(" %c", &operacion);
	printf("ingrese el segundo valor ");
	scanf("%d",&numero_dos);

//CONDICIONES// La manera en como
	switch(operacion)
	{
		case '+':
			resultado= sumarEnteros(numero_uno, numero_dos);
			deteccion_error=1;
			break;
		case '-':// jaja una carita xd
			resultado= restarEnteros(numero_uno, numero_dos);
			deteccion_error=1;
			break;
		case '*':
			resultado= multiplicarEnteros(numero_uno, numero_dos);
			deteccion_error=1;
			break;
		case '/':
			deteccion_error= dividirEnteros(&resultado, numero_uno, numero_dos);
			//printf("%d %c %d = %f", numero_uno, operacion, numero_dos, resultado);
			break;
	}

	if(deteccion_error==-1)
	{
		printf("\nMatch Error.");
//La calculadora cuantas veces habra tirado este error, como el Syntax Error
	} else{
	printf("\n%d %c %d = %f", numero_uno, operacion, numero_dos, resultado);
	}
	return EXIT_SUCCESS;
}
//funcion de division
int dividirEnteros(float* pResultado, int valor_uno, int valor_dos)
{//si el dato del resultado es de tipo float debe ir el tipo como float aca.
	int informacion;
	float resolucion;
	//recuerda que debes poner una variables
	if(valor_dos==0){
		informacion=-1;
	} else {
	resolucion= valor_uno / valor_dos;
	(*pResultado)=resolucion;//recuerda que debo hacer este proceso
	//tendre que averiguar si se puefe jugar con la sintaxis
	informacion=1;
	}
	return informacion;
}
//funcion de producto de enteros.
int multiplicarEnteros(int valor_uno, int valor_dos)
{
	int conclucion;// lo cambie por un accidente en el codeo :(

	conclucion= valor_uno * valor_dos;

	return conclucion;
}
//funcion de resta de enteros
int restarEnteros(int valor_uno, int valor_dos)
{
	int resultado;
	resultado= valor_uno - valor_dos;

	return resultado;
}
//funcion de suma de enteros.
int sumarEnteros(int valor_uno, int valor_dos)
{
	int retorno;
	retorno= valor_uno + valor_dos;

	return retorno;
}

