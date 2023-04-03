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
	char* nombre;
	int id;
	Instalacion* instalaciones;
	int NumInsta;
	char* dir;
	char* provincia;
}Polideportivo;

void verInstalaciones();
void verNuMInsta();
void imprimirPolideportivo();
void verDir();
void PolisDeCiudad();

#endif /* POLIDEPORTIVO_H_ */
