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
sqlite3* cargarBD(){
	sqlite3* bd;
	int result=sqlite3_open("./Recursos/Polis.db", &bd);
	if (result!= SQLITE_OK){
		printf("error al abrir la base de datos");
	}return bd;
}
int cerrarBD(sqlite3* bd){
	int result=sqlite3_close(bd);
	if (result!= SQLITE_OK){
			printf("error al cerrar la base de datos");
	}return result;
}
Polideportivo* cargarPolideportivo(int id,sqlite3* bd){
	sqlite3_stmt* stmt;
	Polideportivo* p= (Polideportivo*)malloc(sizeof(Polideportivo));
	char* sql="Select * from Polideportivo where id=?";
	int result = sqlite3_prepare_v2(bd, sql,-1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	result=sqlite3_step(stmt);
	if (result== SQLITE_ROW){
		p->id=sqlite3_column_int(stmt, 0);
		p->nombre= (char*) malloc(sizeof(char)*(strlen((char*)sqlite3_column_text(stmt, 1))+1));
		strcpy(p->nombre,(char*)sqlite3_column_text(stmt, 1));
		p->dir=malloc(sizeof(char)*(strlen((char*)sqlite3_column_text(stmt, 2))+1));
		strcpy(strlen)
		p->NumInsta= sqlite3_column_int(stmt, 3);
	}
	result= sqlite3_finalize(stmt);
	return p;
}


int anadirPolideportivoaBD(char* nombre,int NumInsta,char* Localidad,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="insert into Polideportivo(id,nombre,Localidad,NumInsta) values(NULL,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql,strlen(sql)+1, &stmt, NULL) ;
	if(result!= SQLITE_OK){
		printf(sqlite3_errmsg(bd));
	}
	sqlite3_bind_text(stmt, 1, nombre,strlen(nombre)+1,SQLITE_TEXT);
	sqlite3_bind_text(stmt,2,Localidad,strlen(Localidad)+1,SQLITE_TEXT);
	sqlite3_bind_int(stmt,3,NumInsta);
	result=sqlite3_step(stmt);
	if(result!=SQLITE_DONE){
		printf("ERROR AL ANADIR POLI\n");
	}
	result=sqlite3_finalize(stmt);
	return result;
}
int anadirAdmin(sqlite3* bd,int dni,char* nombre,char* apellido,char* email,char* contrasena,int id_poli){
	sqlite3_stmt* stmt;
		char* sql="insert into Administrador(DNI,nombre_a,apellido,email,contrasena,id_p) values(?,?,?,?,?,?)";
		int result = sqlite3_prepare_v2(bd, sql,strlen(sql)+1, &stmt, NULL) ;
		if(result!= SQLITE_OK){
			printf(sqlite3_errmsg(bd));
		}
		sqlite3_bind_int(stmt,1,dni);
		sqlite3_bind_text(stmt, 2, nombre,strlen(nombre)+1,SQLITE_TEXT);
		sqlite3_bind_text(stmt,3,apellido,strlen(apellido)+1,SQLITE_TEXT);
		sqlite3_bind_text(stmt,4,email,strlen(email)+1,SQLITE_TEXT);
		sqlite3_bind_text(stmt,5,contrasena,strlen(contrasena)+1,SQLITE_TEXT);
		sqlite3_bind_int(stmt,6,id_poli);
		result=sqlite3_step(stmt);
		if(result!=SQLITE_DONE){
			printf("ERROR AL ANADIR POLI\n");
		}
		result=sqlite3_finalize(stmt);
		return result;
}
int anadirInstalacionaBD(char* nombre,char* deporte,int id_poli,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="insert into Instalacion(id_i,nombre_i,deporte,id_p) values(NULL,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql)+1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre,strlen(nombre)+1,SQLITE_TEXT);
	sqlite3_bind_text(stmt,2,deporte,strlen(deporte)+1,SQLITE_TEXT);
	sqlite3_bind_int(stmt,3,id_poli);
	result=sqlite3_step(stmt);
	if(result!= SQLITE_DONE){
		printf("Error al añadir Instalacion, se recomienda comprbar que el codigo no exista con anterioridad");
		fflush(stdout);
	}
	sqlite3_finalize(stmt);
	return result;
}

int editarInstalacion(int id,sqlite3* bd){
	Instalacion* insta= cargarInstalacion(id, bd);
	sqlite3_stmt* stmt;
	int result=0;
	printf("Elige una de las siguientes opciones a modificar;\n");
	printf("1) codigo\n2)nombre\n3)deporte\n4)codigo de polideportivo");
	fflush(stdout);
	char c= getchar();
	switch (c){
	case '1':
		printf("Introduzca el codigo nuevo:");
		fflush(stdout);
		scanf("%d",insta->id);
		char* sql="Update id_l from Polideportivo value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_int(stmt,1,insta->id);
		sqlite3_bind_int(stmt, 2,insta->id);
		result=sqlite3_step(stmt);
		break;
	case '2':
		printf ("introduzca el nuevo nombre:");
		scanf("%s",insta->nombre);
		int i=0;
		sql="Update nombre_i from Instalacion value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_text(stmt,1,insta->nombre,strlen(insta->nombre)+1,NULL);
		sqlite3_bind_int(stmt, 2,insta->id);
		result=sqlite3_step(stmt);
		break;
	case '3':
		printf ("introduzca el nuevo deporte:");
		fflush(stdout);
		scanf("%s",insta->deporte);
		sql="Update deporte from Instalacion value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_text(stmt,1, insta->deporte,strlen(insta->deporte)+1,NULL);
		sqlite3_bind_int(stmt, 2,insta->id);
		result=sqlite3_step(stmt);
		break;
	case '4':
		printf("Introduzca el codigo nuevo:");
		int id_poli=getchar();
		sql="Update id_p from Instalacion value(?) where id_i=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_int(stmt,1, id_poli);
		sqlite3_bind_int(stmt, 2,insta->id);
		sqlite3_step(stmt);
		insta->id_poli=id_poli;
		break;
	}return result;
}
int editarPolideportivo(int id,sqlite3* bd){
		Polideportivo* p=cargarPolideportivo(id, bd);
		sqlite3_stmt* stmt;
		int result;
		char* sql;
		printf("Elige una de las siguientes opciones a modificar;\n");
		printf("1)nombre\n2)Localidad");
		char c= getchar();
		switch (c){
			case '1':
				printf("Escribe el nuevo nombre del polideportivo: ");
				fflush(stdout);
				scanf("%s",p->nombre);
				free(p->nombre);
				sql="Update nombre_p from polideportivo value(?) where id=?";
				result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
				sqlite3_bind_text(stmt,1,p->nombre,strlen(p->nombre)+1,NULL);
				sqlite3_bind_int(stmt, 2,p->id);
				result=sqlite3_step(stmt);
				return result;
				break;
			case '2':
				printf("Escribe el nuevo municipio: ");
				fflush(stdout);
				scanf("%s",p->dir);
				int id_Localidad=(int)NULL;
				sql="Select id_l from Localidad where nombre_l='?'";
				sqlite3_bind_text(stmt, 1, p->dir,strlen(p->dir)+1,NULL);
				result=sqlite3_step(stmt);
				if (result == SQLITE_ROW) {
					id_Localidad=sqlite3_column_int(stmt, 0);
				}
				sql="Update id_l from Polideportivo value(?) where id=?";
				result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
				sqlite3_bind_int(stmt,1, id_Localidad);
				sqlite3_bind_int(stmt, 2,p->id);
				sqlite3_step(stmt);
				sql="Select nombre_l from Localidad where id_l=?";
				sqlite3_bind_int(stmt, 1, id_Localidad);
				result=sqlite3_step(stmt);
				return result;
				break;
			default:
				return result;
				break;
		}
}
int borrarPolideportivo(int id,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="Delete from Polideportivo where id=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1,id);
	result= sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	return result;
}
int borrarInstalacion(int id,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="Delete from Polideportivo where id=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, id);
	result= sqlite3_step(stmt);
	result=sqlite3_finalize(stmt);
	if(result!=SQLITE_DONE){
		sqlite3_errmsg(bd);
	}
	return result;
}
Instalacion* cargarInstalacion(int id,sqlite3* bd){
	sqlite3_stmt* stmt;
	Instalacion* i= (Instalacion*)malloc(sizeof(Instalacion));
	char* aux= (char*)malloc(sizeof(char)*100);
	char* sql="Select id_i,nombre_i,deporte,id_p from Instalacion where id_i=?";
	int result = sqlite3_prepare(bd, sql, -1, &stmt, NULL) ;
	if(result!=SQLITE_OK){
		printf(sqlite3_errmsg(bd));
		fflush(stdout);
	}
	sqlite3_bind_int(stmt, 1, id);
	result=sqlite3_step(stmt);
		if (result== SQLITE_ROW){
			i->id=sqlite3_column_int(stmt, 0);
			strcpy(aux,(char*)sqlite3_column_text(stmt, 1));
			i->nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1));
			strcpy(i->deporte,aux);
			strcpy(i->nombre,aux);
			strcpy(aux,(char*)sqlite3_column_text(stmt, 2));
			i->deporte=(char*)malloc(sizeof(char)*(strlen(aux)+1));
			strcpy(i->deporte,aux);
			i->id_poli=sqlite3_column_int(stmt, 3);
		}if(result==SQLITE_DONE){

		}free(aux);
		printf(sqlite3_errmsg(bd));
		fflush(stdout);
		result= sqlite3_finalize(stmt);
		return i;
}
