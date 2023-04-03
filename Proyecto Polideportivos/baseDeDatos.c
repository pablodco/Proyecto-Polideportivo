/*
 * baseDeDatos.c
 *
 *  Created on: 23 mar 2023
 *      Author: pablo
 */

#include "basededatos.h"
#include <stdio.h>
cargarBD(){
	sqlite3* bd;
	sqlite3_stmt* stmt;
	int result=sqlite3_open("PolisBD", &bd);
	if (result== SQLITE_OK){
		printf("error al abrir la base de datos");
	}
	char* sql="create table Admin if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña,int id_p)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Usuario if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña,string dir,string ciudad)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Reserva if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Instalacion if not exists(int id Primary KEY;string nombre,string deporte)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
	sql="create table Poli if not exists(int id Primary KEY;string nombre,string apellido,string email,string contraseña)";
	result= sqlite3_prepare(bd, sql, strlen(sql)+1, stmt, NULL);
	if (result==SQLITE_OK){

	}sqlite3_step(stmt);
}

cargarPolideportivo(char* p,sqlite3* bd){
	sqlite3_stmt* stmt;
	char* sql="Select * from Polideportivo where nombre='?'";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, p);
	sqlite3_step(stmt);

}


