/*
 * baseDeDatos.h
 *
 *  Created on: 1 abr 2023
 *      Author: pablo
 */

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_
#include "sqlite3.h"
cargarBD(sqlite3* bd,);
guardarBD();
comprobarContraseña(Administrador a,sqlite3* bd);
anadirInstalacion(Instalacion in,sqlite3* bd);
modificarInstalacion(Instalacion in,sqlite3* bd);
comprobarInstalacion(Instalacion in,sqlite3* bd);
cargarPolideportivo(Polideportivo p,sqlite3* bd);
anadirPolideportivo(Polideportivo p,sqlite3* bd);



#endif /* BASEDEDATOS_H_ */
