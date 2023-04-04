#include <stdlib.h>
#include <stdio.h>
#include "proyecto.h"

int main(void) {
	int numero;// Numero de la primera pregunta

	printf("Bienvenido a la gestion de polideportivos\n");
	printf("¿ Has iniciado sesion antes ?\n");
	printf("1 = Si // 2 = No \n");
	scanf("%d",&numero);
	primeraVentana(numero);


}
