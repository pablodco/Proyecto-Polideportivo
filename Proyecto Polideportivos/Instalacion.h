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
	boolean ocupada;
	int hora;
}Hora;

typedef struct{
	Hora* horas;
}Horario;

typedef struct{
	char* nombre;
	int id;
	Horario horario;
	char* deporte;
}Instalacion;


comprobarHora();
verHorario();
imprimirInstalacion();


#endif /* INSTALACION_H_ */
