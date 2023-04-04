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
sqlite3* cargarBD();//hecho
int cerrarBD(sqlite3* bd);
int comprobarContrasena(Administrador a,sqlite3* bd);
int anadirInstalacion(char* nombre,int id,char* deporte,Horario* h,int id_poli,sqlite3* bd);
int editarInstalacion(Instalacion* insta,sqlite3* bd);
int comprobarInstalacion(Instalacion in,sqlite3* bd);//hecho
Polideportivo* cargarPolideportivo(int id,sqlite3* bd);//hecho
int anadirPolideportivoaBD(char* nombre,int id,int NumInsta,char* Localidad,sqlite3* bd);
int editarPolideportivoaBD(Polideportivo* p,sqlite3* bd);
int borrarInstalacion(Instalacion* i,sqlite3* bd);
int borrarPolideportivo(Polideportivo* p,sqlite3* bd);

#endif /* BASEDEDATOS_H_ */
