/*
 * Instalación.h
 *
 *  Created on: 23 mar 2023
 *      Author: pablo
 */

#ifndef INSTALACION_H_
#define INSTALACION_H_
#include <stdbool.h>

typedef struct{
	char* nombre;
	int id;
	int* horas[7];
	char* deporte;
	int id_poli;
}Instalacion;

Instalacion* agregarInstalacion();
int comprobarHora();
void verHorario();
void imprimirInstalacion();


#endif /* INSTALACION_H_ */
