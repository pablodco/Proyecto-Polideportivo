/*
 * baseDeDatos.c
 *
 *  Created on: 23 mar 2023
 *      Author: pablo
 */

#include "basededatos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

sqlite3* cargarBD() {
	sqlite3 *bd;
	int result = sqlite3_open("./Recursos/Polis.db", &bd);
	if (result != SQLITE_OK) {
		printf("error al abrir la base de datos");
	}
	return bd;
}
int cerrarBD(sqlite3 *bd) {
	int result = sqlite3_close(bd);
	if (result != SQLITE_OK) {
		printf("error al cerrar la base de datos,%s", sqlite3_errmsg(bd));
	}
	return result;
}
int numeroPolis(sqlite3* bd){
		sqlite3_stmt* stmt;
		int i=0;
		int numInsta;
		char *sql = "Select count(*) from Polideportivo";
		int result = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);// sustituir -1 por strlen(sql)+1
			result = sqlite3_step(stmt);
		if(result==SQLITE_ROW){
			numInsta=sqlite3_column_int(stmt, 0);
		}return numInsta;
}

int numeroInstalaciones(sqlite3* bd){
		sqlite3_stmt* stmt;
		int i=0;
		int numInsta;
		char *sql = "Select count(*) from Instalacion";
		int result = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);// sustituir -1 por strlen(sql)+1
		result = sqlite3_step(stmt);
		if(result==SQLITE_ROW){
			numInsta=sqlite3_column_int(stmt, 0);
		}return numInsta;
}
Polideportivo* cargarPolideportivo(int id, sqlite3 *bd) {
	sqlite3_stmt *stmt;
	Polideportivo *p = (Polideportivo*) malloc(sizeof(Polideportivo));
	char *sql = "Select * from Polideportivo where id=?";
	int result = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		p->id = sqlite3_column_int(stmt, 0);
		p->nombre = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 1)) + 1));
		strcpy(p->nombre, (char*) sqlite3_column_text(stmt, 1));
		p->dir = malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 2)) + 1));
		strcpy(p->dir, (char*) sqlite3_column_text(stmt, 2));
		p->NumInsta = sqlite3_column_int(stmt, 3);
	}
	result = sqlite3_finalize(stmt);
	return p;
}

Polideportivo** cargarPolideportivos(sqlite3 *bd) {
	sqlite3_stmt *stmt;
	sqlite3_stmt *stmt2;
	int i = 0;
	int e = 0;
	int numPolis=numeroPolis(bd);
	Polideportivo **Listap = malloc(sizeof(Polideportivo) * 10);
	Polideportivo *p = (Polideportivo*) malloc(sizeof(Polideportivo));
	char *sql = "Select * from Polideportivo";
	int result = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);
	result = sqlite3_step(stmt);
	while (result == SQLITE_ROW) {
		i++;
		p->id = sqlite3_column_int(stmt, 0);
		p->nombre = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 1)) + 1));
		strcpy(p->nombre, (char*) sqlite3_column_text(stmt, 1));
		p->dir = malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 2)) + 1));
		strcpy(p->dir, (char*) sqlite3_column_text(stmt, 2));
		p->NumInsta = sqlite3_column_int(stmt, 3);
		p->instalaciones = malloc(sizeof(Instalacion) * p->NumInsta);
		char *sql2 = "Select * from Instalacion where id=?";
		int result2 = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);
		result2 = sqlite3_bind_int(stmt2, 1, p->id);
		result2 = sqlite3_step(stmt2);
		while (result == SQLITE_ROW) {
			Instalacion *i = malloc(sizeof(Instalacion));
			i->id = sqlite3_column_int(stmt2, 0);
			i->nombre =
					(char*) malloc(
							sizeof(char)
									* (strlen(
											(char*) sqlite3_column_text(stmt2,
													1)) + 1));
			strcpy(i->nombre, (char*) sqlite3_column_text(stmt2, 1));
			i->deporte =
					(char*) malloc(
							sizeof(char)
									* (strlen(
											(char*) sqlite3_column_text(stmt2,
													2)) + 1));
			strcpy(i->nombre, (char*) sqlite3_column_text(stmt2, 2));
			i->id_poli = sqlite3_column_int(stmt2, 3);
			p->instalaciones[e] = i;
			e++;
		}
		Listap[i] = p;
	}
	return Listap;
}
Instalacion** cargarInstalaciones(sqlite3 *bd) {
	sqlite3_stmt* stmt;
	Instalacion** Listainsta;
	int i=0;
	int numInsta=numeroInstalaciones(bd);
	Listainsta=(Instalacion**)malloc(sizeof(Instalacion*)*numInsta);
	char* sql= "Select * from Instalacion";
	int result= sqlite3_step(stmt);
	while (result == SQLITE_ROW) {
		Instalacion *insta = malloc(sizeof(Instalacion));
		insta->id = sqlite3_column_int(stmt, 0);
		insta->nombre = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 1)) + 1));
		strcpy(insta->nombre, (char*) sqlite3_column_text(stmt, 1));
		insta->deporte = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 2)) + 1));
		strcpy(insta->nombre, (char*) sqlite3_column_text(stmt, 2));
		insta->id_poli = sqlite3_column_int(stmt, 3);
		Listainsta[i]=insta;
		i++;
	}
	sqlite3_finalize(stmt);
	return Listainsta;
}
int anadirPolideportivoaBD(char *nombre, int NumInsta, char *Localidad,
		sqlite3 *bd) {
	sqlite3_stmt *stmt;
	char *sql =
			"insert into Polideportivo(id,nombre,Localidad,NumInsta) values(NULL,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf(sqlite3_errmsg(bd));
	}
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_TEXT);
	sqlite3_bind_text(stmt, 2, Localidad, strlen(Localidad) + 1, SQLITE_TEXT);
	sqlite3_bind_int(stmt, 3, NumInsta);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("ERROR AL ANADIR POLI\n");
	}
	result = sqlite3_finalize(stmt);
	return result;
}
int anadirAdmin(sqlite3 *bd, int dni, char *nombre, char *apellido, char *email,
		char *contrasena, int id_poli) {
	sqlite3_stmt *stmt;
	char *sql =
			"insert into Admin (DNI,nombre_a,apellido,email,contrasena,id_p) values(?,?,?,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf(sqlite3_errmsg(bd));
	}
	sqlite3_bind_int(stmt, 1, dni);
	sqlite3_bind_text(stmt, 2, nombre, strlen(nombre) + 1, SQLITE_TEXT);
	sqlite3_bind_text(stmt, 3, apellido, strlen(apellido) + 1, SQLITE_TEXT);
	sqlite3_bind_text(stmt, 4, email, strlen(email) + 1, SQLITE_TEXT);
	sqlite3_bind_text(stmt, 5, contrasena, strlen(contrasena) + 1, SQLITE_TEXT);
	sqlite3_bind_int(stmt, 6, id_poli);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf(sqlite3_errmsg(bd));
		fflush(stdout);
	}
//		sqlite3_finalize(stmt);
//		printf("E");
//		fflush(stdout);
	return result;
}
int ConsultarInstalaciones(sqlite3 *bd, Polideportivo *p) {
	sqlite3_stmt *stmt;
	Instalacion *i = (Instalacion*) malloc(sizeof(Instalacion));
	char *aux = (char*) malloc(sizeof(char) * 100);
	char *sql =
			"Select id_i,nombre_i,deporte,id_p from Instalacion where id_p=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf(sqlite3_errmsg(bd));
		fflush(stdout);
	}
	sqlite3_bind_int(stmt, 1, p->id);
	result = sqlite3_step(stmt);
	while (result == SQLITE_ROW) {
		i->id = sqlite3_column_int(stmt, 0);
		i->nombre = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 1)) + 1));
		strcpy(i->nombre, (char*) sqlite3_column_text(stmt, 1));
		i->deporte = malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 2)) + 1));
		strcpy(i->deporte, (char*) sqlite3_column_text(stmt, 2));
		i->id_poli = sqlite3_column_int(stmt, 3);
		imprimirInstalacion(*i);
	}
	free(aux);
	result = sqlite3_finalize(stmt);
	return result;
}
int cargarAdmin(sqlite3 *bd) {
	sqlite3_stmt *stmt;
	char *sql = "Select contrasena from Admin where DNI=?";
	int id;
	int i = 1;
	printf("Introduce tu dni:");
	fflush(stdout);
	scanf("%d", &id);
	char *cont = (char*) malloc(sizeof(char) * 100);
	printf("Introduce tu contrasena:");
	fflush(stdout);
	scanf("%s", cont);
	char *cont2 = (char*) malloc(sizeof(char) * 100);
	strcpy(cont2, cont);
	int result = sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		cont = (char*) sqlite3_column_text(stmt, 0);
		i = strcmp(cont, cont2);
	}
	sqlite3_finalize(stmt);
	free(cont);
	return i;
}
int anadirInstalacionaBD(char *nombre, char *deporte, int id_poli, sqlite3 *bd) {
	sqlite3_stmt *stmt;
	char *sql =
			"insert into Instalacion(id_i,nombre_i,deporte,id_p) values(NULL,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_TEXT);
	sqlite3_bind_text(stmt, 2, deporte, strlen(deporte) + 1, SQLITE_TEXT);
	sqlite3_bind_int(stmt, 3, id_poli);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf(
				"Error al añadir Instalacion, se recomienda comprbar que el codigo no exista con anterioridad");
		fflush(stdout);
	}
	sqlite3_finalize(stmt);
	return result;
}

int editarInstalacion(int id, sqlite3 *bd) {
	Instalacion *insta = cargarInstalacion(id, bd);
	sqlite3_stmt *stmt;
	int result = 0;
	printf("Elige una de las siguientes opciones a modificar;\n");
	printf("1)nombre\n2)deporte\n3)codigo de polideportivo\n opcion:");
	fflush(stdout);
	char c = getchar();
	char *sql;
	switch (c) {
	case '1':
		printf("introduzca el nuevo nombre:");
		fflush(stdout);
		scanf("%s", insta->nombre);
		int i = 0;
		sql = "Update Instalacion set nombre_i='?' where id_i=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		if (result != SQLITE_OK) {
			printf(sqlite3_errmsg(bd));
			fflush(stdout);
		}
		sqlite3_bind_text(stmt, 1, insta->nombre, strlen(insta->nombre) + 1,
				NULL);
		sqlite3_bind_int(stmt, 2, insta->id);
		result = sqlite3_step(stmt);
		result = sqlite3_finalize(stmt);
		break;
	case '2':
		printf("introduzca el nuevo deporte:");
		fflush(stdout);
		scanf("%s", insta->deporte);
		sql = "Update Instalacion set deporte='?'where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, SQLITE3_TEXT);
		sqlite3_bind_text(stmt, 1, insta->deporte, strlen(insta->deporte) + 1,
				SQLITE3_TEXT);
		sqlite3_bind_int(stmt, 2, insta->id);
		result = sqlite3_step(stmt);
		result = sqlite3_finalize(stmt);
		break;
	case '3':
		printf("Introduzca el codigo nuevo:");
		int id_poli = getchar();
		sql = "Update Instalacion set id_p=? where id_i=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_int(stmt, 1, id_poli);
		sqlite3_bind_int(stmt, 2, insta->id);
		sqlite3_step(stmt);
		insta->id_poli = id_poli;
		result = sqlite3_finalize(stmt);
		break;
	}
	return result;
}
int editarPolideportivo(int id, sqlite3 *bd) {
	Polideportivo *p = cargarPolideportivo(id, bd);
	sqlite3_stmt *stmt;
	int result;
	char *sql;
	printf("Elige una de las siguientes opciones a modificar;\n");
	printf("1)nombre\n2)Localidad");
	char c = getchar();
	switch (c) {
	case '1':
		printf("Escribe el nuevo nombre del polideportivo: ");
		fflush(stdout);
		scanf("%s", p->nombre);
		free(p->nombre);
		sql = "Update polideportivo set nombre_p='?' where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_text(stmt, 1, p->nombre, strlen(p->nombre) + 1, NULL);
		sqlite3_bind_int(stmt, 2, p->id);
		result = sqlite3_step(stmt);
		result = sqlite3_finalize(stmt);
		return result;
		break;
	case '2':
		printf("Escribe el nuevo municipio: ");
		fflush(stdout);
		scanf("%s", p->dir);
		int id_Localidad = (int) NULL;
		sql = "Select id_l from Localidad where nombre_l='?'";
		sqlite3_bind_text(stmt, 1, p->dir, strlen(p->dir) + 1, NULL);
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			id_Localidad = sqlite3_column_int(stmt, 0);
		}
		sql = "UpdatePolideportivo set Localidad='?' where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_int(stmt, 1, id_Localidad);
		sqlite3_bind_int(stmt, 2, p->id);
		result = sqlite3_step(stmt);
		return result;
		result = sqlite3_finalize(stmt);
		break;
	default:
		return result;
		break;
	}
}
int borrarPolideportivo(int id, sqlite3 *bd) {
	sqlite3_stmt *stmt;
	char *sql = "Delete from Polideportivo where id=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return result;
}
int borrarInstalacion(int id, sqlite3 *bd) {
	sqlite3_stmt *stmt;
	char *sql = "Delete from Polideportivo where id=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_DONE) {
		sqlite3_errmsg(bd);
	}
	return result;
}
Instalacion* cargarInstalacion(int id, sqlite3 *bd) {
	sqlite3_stmt *stmt;
	Instalacion *i = (Instalacion*) malloc(sizeof(Instalacion));
	char *aux = (char*) malloc(sizeof(char) * 100);
	char *sql =
			"Select id_i,nombre_i,deporte,id_p from Instalacion where id_i=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf(sqlite3_errmsg(bd));
		fflush(stdout);
	}
	sqlite3_bind_int(stmt, 1, id);
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		i->id = sqlite3_column_int(stmt, 0);
		i->nombre = (char*) malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 1)) + 1));
		strcpy(i->nombre, (char*) sqlite3_column_text(stmt, 1));
		i->deporte = malloc(
				sizeof(char)
						* (strlen((char*) sqlite3_column_text(stmt, 2)) + 1));
		strcpy(i->deporte, (char*) sqlite3_column_text(stmt, 2));
		i->id_poli = sqlite3_column_int(stmt, 3);
	}
	free(aux);
	result = sqlite3_finalize(stmt);
	return i;
}
