/*
 * administrador.c
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */
#include "administrador.h"

void iniciarAdmin(sqlite3* bd){
	int id;
	char* aux= (char*)malloc(sizeof(char)*100);
	printf("Introduzca el dni:");
	fflush(stdout);
	scanf("%d", id);
	printf("Introduzca contrasena:");
	fflush(stdout);
	scanf("%s",aux);
	//cargarAdmin(id,aux,bd);
}
void registroAdmin(sqlite3* bd){
		Administrador* admin=
		(Administrador*)malloc(sizeof(Administrador));
		char* aux= (char*)malloc(sizeof(char)*100);
		printf("Introduzca el dni:");
		fflush(stdout);
		scanf("%s", &admin->id);
		printf("Introduzca el nombre:");
		fflush(stdout);
		scanf("%s", aux);
		admin->nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->nombre,aux);
		printf("Introduzca el apellido:");
		fflush(stdout);
		scanf("%s",aux);
		admin->apellido=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->apellido,aux);
		printf("Introduzca el email:");
		fflush(stdin);
		fflush(stdout);
		scanf("%s", aux);
		admin->email=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->email,aux);
		printf("Introduzca la contrasena:");
		fflush(stdin);
		fflush(stdout);
		scanf("%s",aux);
		admin->contrasena=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->contrasena,aux);
		printf("Introduzca el polideportivo para el que trabaja:");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&admin->id_poli);
		free(aux);
		anadirAdmin(bd, admin->id, admin->nombre, admin->apellido, admin->email, admin->contrasena, admin->id_poli);
		filtroPolideportivos(bd);
}


