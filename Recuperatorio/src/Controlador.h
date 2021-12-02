/*
 * Controlador.h
 *
 *  Created on: 30 nov 2021
 *      Author: cesar
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_


int controlador_CargarLista(char* nomDelArchivo, LinkedList* pListaDeLibros);
int controlador_OrdenarPorAutor(LinkedList* pListaDeLibros);
int controlador_MostrarListaDeLibros(LinkedList* pListaDeLibros);
int controlador_mapearLista(LinkedList* pListaDeLibros);
int controlador_filtrarListaDeLibros(LinkedList* pListaDelibros);
int controlador_guardarLista(char* nomDelArchivo , LinkedList* pListaDeLibros);



#endif /* CONTROLADOR_H_ */
