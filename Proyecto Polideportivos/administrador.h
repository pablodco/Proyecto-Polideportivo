/*
 * administrador.h
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */

#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

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

#endif /* ADMINISTRADOR_H_ */
