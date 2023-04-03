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
int cargarBD(){
	sqlite3* bd;
	sqlite3_stmt* stmt;
	int result=sqlite3_open("PolisBD", &bd);
	if (result== SQLITE_OK){
		printf("error al abrir la base de datos");
	}
	char* sql="create table Admin if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña,int id_p)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, &stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Usuario if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña,string dir,string ciudad)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, &stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Reserva if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, &stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Instalacion if not exists(int id Primary KEY;string nombre,string deporte)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, &stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table [if not exists] Polideportivo(int id Primary KEY;string nombre,string contraseña)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, &stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	result= sqlite3_finalize(stmt);
	return result;
}

Polideportivo* cargarPolideportivo(char* nombre,sqlite3* bd){
	sqlite3_stmt* stmt;
	Polideportivo* p= (Polideportivo*)malloc(sizeof(Polideportivo));
	char* sql="Select * from Polideportivo where nombre='?'";
	int result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, nombre,strlen(nombre)+1,NULL);
	sqlite3_step(stmt);
	if (result== SQLITE_ROW){
		p->id=sqlite3_column_int(stmt, 0);
		strcpy(p->nombre,(char*)sqlite3_column_text(stmt, 1));
		sqlite3_stmt* stmt2;
		int result2;
		char* sql="Select nombre_l from Localidad where id='?'";
		result2=sqlite3_prepare(bd, sql,strlen(sql)+1, &stmt2, NULL);
		sqlite3_bind_int(stmt2, 1, sqlite3_column_int(stmt, 2));
		result2=sqlite3_step(stmt2);
		if (result2== SQLITE_ROW){
			p->dir=malloc(sizeof(char)*(strlen((char*)sqlite3_column_text(stmt2, 0))+1));
			p->dir=(char*)sqlite3_column_text(stmt2, 0);
		}
	}
	result= sqlite3_finalize(stmt);
	return p;
}


int anadirPolideportivo(char* nombre,int id,Instalacion* insta,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="Insert into Polideportivos values(?,?,?,?)";
	int result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, id);
	sqlite3_bind_text(stmt, 2, nombre,strlen(nombre)+1,NULL);
	sqlite3_step(stmt);
	return result;
}

int anadirInstalacion(char* nombre,int id,char* deporte,Horario* h,int id_poli,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="Insert into Instalacion values(?,?,?,?)";
	int result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	sqlite3_bind_text(stmt, 2, nombre,strlen(nombre)+1,NULL);
	sqlite3_bind_text(stmt,3,deporte,strlen(deporte)+1,NULL);
	sqlite3_bind_int(stmt,4,id_poli);
	result=sqlite3_step(stmt);
	return result;
}

int editarInstalacion(Instalacion* insta,sqlite3* bd){
	sqlite3_stmt* stmt;
	int result=0;
	printf("Elige una de las siguientes opciones a modificar;\n");
	printf("1) codigo\n2)nombre\n3)deporte\n4)codigo de polideportivo");
	char c= getchar();
	switch (c){
	case '1':
		printf("Introduzca el codigo nuevo:");
		int id=getchar();
		char* sql="Update id_l from Polideportivo value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_int(stmt,1, id);
		sqlite3_bind_int(stmt, 2,insta->id);
		sqlite3_step(stmt);
		insta->id=id;
		break;
	case '2':
		printf ("introduzca el nuevo nombre:");
		c=getchar();
		char nom[15];
		int i=0;
		while(c!='\n'){
			nom[i]=c;
			c=getchar();
			i++;
		}sql="Update nombre_i from Instalacion value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_text(stmt,1,nom,strlen(nom)+1,NULL);
		sqlite3_bind_int(stmt, 2,insta->id);
		sqlite3_step(stmt);
		insta->nombre=nom;
		break;
	case '3':
		printf ("introduzca el nuevo deporte:");
		c=getchar();
		char deporte[15]="";
		int e=0;
		while(c!='\n'){
			nom[e]=c;
			c=getchar();
			i++;
		} sql="Update deporte from Instalacion value(?)where id=?";
		result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
		sqlite3_bind_text(stmt,1, deporte,strlen(deporte)+1,NULL);
		sqlite3_bind_int(stmt, 2,insta->id);
		sqlite3_step(stmt);
		insta->deporte=nom;
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
int editarPolideportivo(Polideportivo* p,sqlite3* bd){
		sqlite3_stmt* stmt;
		int result ;
		printf("Elige una de las siguientes opciones a modificar;\n");
		printf("1) codigo\n2)nombre\n3)Localidad");
		char c= getchar();
		switch (c){
			case '1':
				printf("Introduzca el codigo nuevo:");
				int id=getchar();
				char* sql="Update id from Polideportivo value(?) where id=?";
				result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
				sqlite3_bind_int(stmt,1,id);
				sqlite3_bind_int(stmt, 2,p->id);
				result=sqlite3_step(stmt);
				return result;
			break;
			case '2':
				printf ("introduzca el nuevo nombre:");
				c=getchar();
				char nom[15];
				int i=0;
				while(c!='\n'){
					nom[i]=c;
					c=getchar();
					i++;
				}	sql="Update nombre_p from polideportivo value(?) where id=?";
				result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
				sqlite3_bind_text(stmt,1,nom,strlen(nom)+1,NULL);
				sqlite3_bind_int(stmt, 2,p->id);
				result=sqlite3_step(stmt);
				return result;
				break;
			case '3':
				printf("Introduzca el codigo de la Localidad:");
				int id_Localidad=getchar();
				sql="Update id_l from Polideportivo value(?) where id=?";
				result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL);
				sqlite3_bind_int(stmt,1, id_Localidad);
				sqlite3_bind_int(stmt, 2,p->id);
				sqlite3_step(stmt);
				sql="Select nombre_l from Localidad where id_l=?";
				sqlite3_bind_int(stmt, 1, id_Localidad);
				result=sqlite3_step(stmt);
				char* loc;
				if (result == SQLITE_ROW) {
					loc=(char*)sqlite3_column_text(stmt, 0);
					//strcpy(loc,(char*)sqlite3_column_text(stmt, 0));
				}
				p->dir=loc;
				return result;
				break;
			default:
				return result;
				break;
		}
}
Instalacion* cargarInstalacion(int id,sqlite3* bd){
	sqlite3_stmt* stmt;
		Instalacion* i= (Instalacion*)malloc(sizeof(Instalacion));
		char* sql="Select * from Polideportivo where id='?'";
		int result = sqlite3_prepare(bd, sql, strlen(sql) + 1, &stmt, NULL) ;
		sqlite3_bind_int(stmt, 1, id);
		result=sqlite3_step(stmt);
		if (result== SQLITE_ROW){
			i->id=sqlite3_column_int(stmt, 0);
			strcpy(i->nombre,(char*)sqlite3_column_text(stmt, 1));
			strcpy(i->deporte,(char*)sqlite3_column_text(stmt, 2));
			i->id_poli=sqlite3_column_int(stmt, 3);
		}
		result= sqlite3_finalize(stmt);
		return i;
	}
