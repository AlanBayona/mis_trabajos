/*
 * Informe.h
 *
 *  Created on: 21 oct. 2021
 *      Author: alanb
 */

#ifndef INFORME_H_
#define INFORME_H_

int contadorDeArcades(eArcade list[], int len, int idABuscar);



int informe_listarSalonesConMasDeCuatroArcades(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade);//a
int informe_listarArcadesParaMasDeDosJugadores(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade);//b
int informe_listarInfoDeSalonBuscadoPorId(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade);//c
int informe_listarArcadesDeUnSalonBuscadoPorId(eSalon listaSalones[], eArcade listaArcades[], int lenSalon, int lenArcade);//d

#endif /* INFORME_H_ */
