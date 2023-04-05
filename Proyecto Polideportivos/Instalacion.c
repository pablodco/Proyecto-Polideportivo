#include "Instalacion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0


Instalacion* agregarInstalacion(){
	char* aux=(char*) malloc(sizeof(char)*100);
	Instalacion* miInstalacion= (Instalacion*)malloc(sizeof(Instalacion));
	printf("Introduzca el nombre de la instalación:");
	fflush(stdout);
	scanf("%s", aux);
	miInstalacion->nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1));
	strcpy(miInstalacion->nombre,aux);
	printf("Introduzca el deporte:");
	fflush(stdout);
	scanf("%s", aux);
	miInstalacion->deporte=(char*)malloc(sizeof(char)*(strlen(aux)+1));
	strcpy(miInstalacion->deporte,aux);
	printf("Introduzca el id del polideportivo:");
	scanf("%d", &miInstalacion->id_poli);
	// Pregunta al usuario por el horario
	int numHoras;
	printf("Introduzca el número de horas en el horario:");
	fflush(stdout);
	scanf("%d", &numHoras);
	for (int i=0;i<7;i++){
	miInstalacion->horas[i]= (int*)malloc(sizeof(int)*numHoras);
	}free(aux);

	return miInstalacion;
}

void imprimirInstalacion(Instalacion i){
	printf("ID de la instalación: %i\n", i.id);
	printf("Nombre de la instalación: %s\n", i.nombre);
	printf("Nombre del deporte: %s\n", i.deporte);
	fflush(stdout);
}

int comprobarHora(Instalacion i){
	int dia, hora;
	printf("Introduce el día de la semana (0-6):\n");
	fflush(stdout);
	scanf("%d", &dia);
	printf("Introduce la hora del día (0-23):\n");
	fflush(stdout);
	scanf("%d", &hora);
	if (i.horas[dia][hora] == 0) {
		printf("La hora está libre.\n");
		return 0;
	} else {
		printf("La hora está ocupada.\n");
		return 1;
	}
}
