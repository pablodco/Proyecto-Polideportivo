/*
 * administrador.h
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */

#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_
#include "polideportivo.h"
#include  "baseDeDatos.h"
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
typedef struct{
	char* nombre;
	char* apellido;
	char* contrasena;
	int id;
	char* email;
	int id_poli;
}Administrador;

void filtroAdmin();

void filtroInstalaciones(sqlite3* bd,Polideportivo* poli);

void filtroPolideportivos(sqlite3* bd);

void menuBorrarInstalacion(Instalacion *insta,sqlite3* bd,Polideportivo* poli);

void menuBorrarPolideportivo(Polideportivo* poli,sqlite3* bd);

#endif /* ADMINISTRADOR_H_ */
