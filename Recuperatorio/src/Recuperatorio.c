/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Inputs.h"
#include "LinkedList.h"
#include "Controlador.h"
#include "Menu.h"
#include "Libro.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	LinkedList* pListaDeLibros=ll_newLinkedList();
	LinkedList* minotauroLibros;
	int flagDeCargar=0;


	do
	{

	mostrarMenu();
		if(pedirTipoInt(&opcion, "", "Error\n", 1, 8, 2)==0)
		{

			switch(opcion)
			{
				case 1:
					if(ll_isEmpty(pListaDeLibros)==1 && flagDeCargar==0)
					{

						controlador_CargarLista("src/Datos_Recu_2_Dic_2021_TN.csv", pListaDeLibros);
						flagDeCargar=1;
					}
					else
					{
						puts("Error al cargar");
					}
					break;
				case 2:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_OrdenarPorAutor(pListaDeLibros);
					}
					break;
				case 3:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_MostrarListaDeLibros(pListaDeLibros);

					}
					else
					{
						puts("Vacio, esta vacio la lista");
					}
					break;
				case 4:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						if(ll_map(pListaDeLibros, hacerDescuento)==0)
						{
							puts("Map con exito");
						}
					}
					break;
				case 5:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						controlador_guardarLista("mapeado.csv", pListaDeLibros);
					}
					break;
				case 6:
					if(ll_isEmpty(pListaDeLibros)==0)
					{
						if(pedirTipoInt(&opcion, "\tMenu\n1- Filtrar la lista por la editorial Minotauro\n2- Generar el archivo de salida: minotauroLibros.csv\n", "Opcion del rango\n", 1, 2, 3)==0)
						{
							switch(opcion)
							{
								case 1:
									minotauroLibros=ll_filter(pListaDeLibros, libro_filtrarPorEditorialMinotauro);
									if(minotauroLibros!=NULL)
									{
										puts("Filtracion lograda....");
									}
									else
									{
										puts("Salio mal la filtracion..");
									}
									break;
								case 2:
									if(controlador_guardarLista("minotauroLibros.csv", minotauroLibros)==0)
									{
										puts("Se guardo con exito. Puede apagar la consola");
									}
									else
									{
										puts("ERROR al guardar...");
									}
									break;
							}
						}
					}
					break;
			}
		}

	}while(opcion!=7);

	return EXIT_SUCCESS;
}
