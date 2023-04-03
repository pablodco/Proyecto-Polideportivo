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
int cargarBD();//hecho
int guardarBD();
int comprobarContrasena(Administrador a,sqlite3* bd);
int anadirInstalacion(char* nombre,int id,char* deporte,Horario* h,int id_poli,sqlite3* bd);
int editarInstalacion(Instalacion* insta,sqlite3* bd);
int comprobarInstalacion(Instalacion in,sqlite3* bd);//hecho
Polideportivo* cargarPolideportivo(char* nombre,sqlite3* bd);//hecho
int anadirPolideportivo(char* nombre,int id,Instalacion* insta,sqlite3* bd);
int editarPolideportivo(Polideportivo* p,sqlite3* bd);


#endif /* BASEDEDATOS_H_ */
