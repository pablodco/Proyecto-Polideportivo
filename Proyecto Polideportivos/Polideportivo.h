/*
 * Polideportivo.h
 *
 *  Created on: 23 mar 2023
 *      Author: pablo
 */

#ifndef POLIDEPORTIVO_H_
#define POLIDEPORTIVO_H_
#include "instalacion.h"
typedef struct {
	char nombre[15];
	int id;
	Instalacion* instalaciones;
	int NumInsta;
	char dir[15];
}Polideportivo;

void agregarPoliderportivo();
void imprimirPolideportivo(Polideportivo p);
void cambiarElemento(Polideportivo* p);
void limpiarVariable(char *str, int max_line);

#endif /* POLIDEPORTIVO_H_ */
