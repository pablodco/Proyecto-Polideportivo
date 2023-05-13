/*
 * baseDeDatos.h
 *
 *  Created on: 1 abr 2023
 *      Author: pablo
 */

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_
#include "sqlite3.h"
#include "polideportivo.h"
#include "administrador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

sqlite3* cargarBD();//hecho
int ConsultarInstalaciones(sqlite3* bd,Polideportivo* p);
int cerrarBD(sqlite3* bd);
int anadirAdmin(sqlite3* bd,int dni,char* nombre,char* apellido,char* email,char* contrasena,int id_poli);
int cargarAdmin(sqlite3* bd);
int anadirInstalacionaBD(char* nombre,char* deporte,int id_poli,sqlite3* bd);
int editarInstalacion(int id,sqlite3* bd);
Instalacion* cargarInstalacion(int id,sqlite3* bd);//hecho
Polideportivo* cargarPolideportivo(int id,sqlite3* bd);//hecho
int anadirPolideportivoaBD(char* nombre,int NumInsta,char* Localidad,sqlite3* bd);
int editarPolideportivoaBD(int id,sqlite3* bd);
int borrarInstalacion(int id,sqlite3* bd);
int borrarPolideportivo(int id,sqlite3* bd);
Instalacion** cargarInstalaciones(sqlite3* bd);
Polideportivo** cargarPolideportivos(sqlite3* bd);
int numeroPolis(sqlite3* bd);
int numeroInstalaciones(sqlite3* bd);

#endif /* BASEDEDATOS_H_ */
