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
typedef struct{
	char* nombre;
	char* apellido;
	char* cotrasena;
	int id;
	char* email;
	int longitudnombre;
	int longitudEmail;
	int longitudContrasena;
	int longitudApellido;
}Administrador;

void filtroAdmin();

void filtoInstalaciones(sqlite3* bd,Polideportivo* poli);

void filtroPolideportivos(sqlite3* bd);

void menuBorrarInstalacion(Instalacion *insta,sqlite3* bd);

void menuBorrarPolideportivo(Polideportivo poli,sqlite3* bd);

#endif /* ADMINISTRADOR_H_ */
