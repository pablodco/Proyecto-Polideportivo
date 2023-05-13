#include <string.h>
#include <stdio.h>
#include "Polideportivo.h"
#include "basededatos.h"


void imprimirPolideportivo(Polideportivo p){
	printf("ID: %i.\n", p.id);
	fflush(stdout);
	printf("Nombre: %s.\n", p.nombre);
	fflush(stdout);
	printf("Número de instalaciones: %i.\n", p.NumInsta);
	fflush(stdout);
	printf("Dirección: %s.\n", p.dir);
	fflush(stdout);
	printf("------------------------------------\n");
	fflush(stdout);
	printf("Información sobre las instalaciones:\n");
	fflush(stdout);
	int i;
	for (i = 0; i < p.NumInsta; ++i) {
		printf("   - Instalación %i: %s \n",i+1,p.instalaciones[i]->nombre);
		fflush(stdout);
	}
	printf("------------------------------------");
	fflush(stdout);
}

//void cambiarElemento(Polideportivo* p){
//	int i;
//	char* aux;
//	printf("Cada elemento está asociado a un numero: \n");
//	printf("ID = 1 \n");
//	printf("Nombre = 2 \n");
//	printf("Dirección = 3 \n");
//	printf("Teclea el número del elemento que quieras cambiar: ");
//	fflush(stdout);
//	scanf("%i",&i);
//
//	int j;
//	if(i == 1){
//		printf("Escribe el nuevo número de ID: ");
//		fflush(stdout);
//		scanf("%i", &j);
//		p->id = j;
//	}
//	if(i == 2){
//		printf("Escribe el nuevo nombre del polideportivo: ");
//		fflush(stdout);
//		scanf("%s",*aux);
//		free(p->nombre);
//		p->nombre=(char*)malloc(sizeof(char)*strlen(aux));
//		strcpy(p->nombre,aux);
//		limpiarVariable(aux, 15);
//	}
//
//	if(i == 3){
//		printf("Escribe la nueva dirección: ");
//		fflush(stdout);
//		scanf("%s",&aux);
//		free(p->dir);
//		p->dir=(char*)malloc(sizeof(char)*strlen(aux));
//		strcpy(p->dir,aux);
//	}
//}

void limpiarVariable(char *str, int max_line){
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
Polideportivo* agregarPolideportivo(sqlite3* bd){
	char* aux= malloc(sizeof(char)*100);
	Polideportivo* miPolideportivo=
		(Polideportivo*)malloc(sizeof(Polideportivo));
	printf("Introduzca el nombre del polideportivo:");
	fflush(stdout);
	scanf("%s", aux);
	miPolideportivo->nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1));
	strcpy(miPolideportivo->nombre,aux);
	printf("Introduzca el municipio del polideportivo:");
	fflush(stdout);
	scanf("%s",aux);
	miPolideportivo->dir=(char*)malloc(sizeof(char)*(strlen(aux)+1));
	strcpy(miPolideportivo->dir,aux);
	printf("Introduzca el número de instalaciones del polideportivo:");
	fflush(stdout);
	scanf("%d", &miPolideportivo->NumInsta);
	miPolideportivo->instalaciones = (Instalacion*)malloc(miPolideportivo->NumInsta * sizeof(Instalacion));
 	for (int i = 0; i < miPolideportivo->NumInsta; i++) {
		Instalacion* inst= agregarInstalacion();
	    anadirInstalacionaBD(inst->nombre,inst->deporte,inst->id_poli,bd);
	}free(aux);
 	return miPolideportivo;
}
