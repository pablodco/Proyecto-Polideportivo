#include "Instalacion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0


void agregarInstalacion(){
	Instalacion miInstalacion;
	printf("Introduzca el nombre de la instalación: ");
	scanf("%s", miInstalacion.nombre);

	printf("Introduzca el deporte: ");
	scanf("%s", miInstalacion.deporte);

	printf("Introduzca el id del polideportivo: ");
	scanf("%d", &miInstalacion.id_poli);

	// Pregunta al usuario por el horario
	int numHoras;
	printf("Introduzca el número de horas en el horario: ");
	scanf("%d", &numHoras);

	miInstalacion.horario.horas = (Hora*) malloc(numHoras * sizeof(Hora));

	for (int i = 0; i < numHoras; i++) {
	    printf("Introduzca la hora de inicio de la hora %d: ", i+1);
	    scanf("%d", &miInstalacion.horario.horas[i]->hora);
	    miInstalacion.horario.horas[i]->ocupada = FALSE;

	    printf("Introduzca la hora de finalización de la hora %d: ", i+1);
	    scanf("%d", &miInstalacion.horario.horas[i+1]->hora);
	}
	free(miInstalacion.horario.horas);

}

void imprimirInstalacion(Instalacion i){
	printf("ID de la instalación: %i", i.id);
	fflush(stdout);
	printf("Nombre de la instalación: %s", i.nombre);
	fflush(stdout);
	printf("Nombre del deporte: %s", i.deporte);
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
	if (i.horario.horas[dia][hora] == 0) {
		printf("La hora está libre.\n");
		return 0;
	} else {
		printf("La hora está ocupada.\n");
		return 1;
	}
}
