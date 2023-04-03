/*
 * usuario.h
 *
 *  Created on: 2 abr 2023
 *      Author: AnderPCU
 */

#ifndef USUARIO_H_
#define USUARIO_H_

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
}Usuario;

#endif /* USUARIO_H_ */
