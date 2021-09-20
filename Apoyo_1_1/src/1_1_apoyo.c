/*
 * Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.
 ============================================================================
 Name        : PedirEntero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero_ingresado;
	int acumulador_negativos;
	int contador_negativos;
	int acumulador_positivos;
	int contador_positivos;
	float promedio_neg;
	float promedio_posit;
	char seguir;

	acumulador_negativos=0;
	contador_negativos=0;
	acumulador_positivos=0;
	contador_positivos=0;
	promedio_neg=0.0;
	promedio_posit=0.0;

	do{
		printf("Hola, bienvenido.\n");
		printf("Te puedo organizar los numeros ingresados.\n");
		printf("Asi que, ingrese un valor: ");
		scanf("%d", &numero_ingresado);

		if(numero_ingresado>0)
		{
			acumulador_positivos+=numero_ingresado;
			contador_positivos++;
		}
		else if(numero_ingresado<0)
		{
			acumulador_negativos+=numero_ingresado;
			contador_negativos++;
		} else {
			printf("No ingrese cero.");
		}

		printf("\nQuiere intentar de nuevo?");
		scanf(" %c", &seguir );

	}while(seguir=='s');

	promedio_neg= (float)acumulador_negativos / contador_negativos;

	promedio_posit= (float)acumulador_positivos / contador_positivos;

	printf("El promedio de los negativos es: %f", promedio_neg);
	printf("\nEl promedio de los positivos es: %f", promedio_posit);



	return EXIT_SUCCESS;
}
