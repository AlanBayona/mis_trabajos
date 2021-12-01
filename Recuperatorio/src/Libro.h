/*
 * Libro.h
 *
 *  Created on: 30 nov 2021
 *      Author: Alan
 */

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
    char titulo[63];
    char autor[63];
    int precio;
    int editorialId;

}eLibro;

eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* editorialAuxStr);
void libro_delete(eLibro* this);

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setPrecio(eLibro* this,int precio);
int libro_getPrecio(eLibro* this,int* precio);

int libro_setEditorialId(eLibro* this,int editorilaId);
int libro_getEditorialId(eLibro* this,int* editorialId);

int arcade_setAutor(eLibro* this,char* autor);
int arcade_getAutor(eLibro* this,char* autor);






int OrdenarPorNombre(void* arcadeAnterior, void* arcadePosterior);

#endif /* LIBRO_H_ */
