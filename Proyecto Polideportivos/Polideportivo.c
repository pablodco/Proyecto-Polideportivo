/*
 * Polideportivo.c
 *
 *  Created on: 23 mar 2023
 *      Author: pablo
 */

#include "Polideportivo.h"

Polideportivo* agregarPolideportivo(){
	Polideportivo* miPolideportivo;

	printf("Introduzca el nombre del polideportivo: ");
	scanf("%s", *miPolideportivo->nombre);

	printf("Introduzca el id del polideportivo: ");
	scanf("%d", miPolideportivo->id);

	printf("Introduzca la dirección del polideportivo: ");
	scanf("%s", *miPolideportivo->dir);

	printf("Introduzca la provincia del polideportivo: ");
	scanf("%s", *miPolideportivo->provincia);

	printf("Introduzca el número de instalaciones del polideportivo: ");
	scanf("%d", miPolideportivo->NumInsta);
	miPolideportivo->instalaciones = (Instalacion*)malloc(miPolideportivo->NumInsta * sizeof(Instalacion));
	miPolideportivo= (Polideportivo*)malloc(sizeof (Polideportivo));
	for (int i = 0; i < miPolideportivo->NumInsta; i++) {
	    printf("Introduzca el nombre de la instalación %d: ", i+1);
	    scanf("%s", *miPolideportivo->instalaciones[i].nombre);
	    printf("Introduzca el deporte de la instalación %d: ", i+1);
	    scanf("%d", miPolideportivo->instalaciones[i].deporte);
	}return miPolideportivo;
}
