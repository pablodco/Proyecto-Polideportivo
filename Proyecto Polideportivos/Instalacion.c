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
	    scanf("%d", &miInstalacion.horario.horas[i].hora);
	    miInstalacion.horario.horas[i].ocupada = FALSE;

	    printf("Introduzca la hora de finalización de la hora %d: ", i+1);
	    scanf("%d", &miInstalacion.horario.horas[i+1].hora);
	}
	free(miInstalacion.horario.horas);


}
