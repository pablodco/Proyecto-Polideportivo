#include <stdlib.h>
#include <stdio.h>
#include "administrador.h"
#include"polideportivo.h"

int main(void) {
	int numero;// Numero de la primera pregunta
	sqlite3* bd=cargarBD();
//	printf("Bienvenido a la gestion de polideportivos\n");
//	printf("¿ Has iniciado sesion antes ?\n");
//	printf("1 = Si // 2 = No \n");
	//fflush(stdout);
//	scanf("%d",&numero);
//	primeraVentana(numero);
//	printf("HOLA ");
//	filtroPolideportivos(bd);
//	filtroAdmin(bd);//falla
//	Polideportivo* poli= (Polideportivo*) malloc(sizeof(Polideportivo));
//	filtroInstalaciones(bd, poli);
//	agregarInstalacion();
//	agregarPolideportivo(bd);
//	imprimirPolideportivo(*poli);
	//anadirPolideportivoaBD("Polideportivo t", 2, "albacete", bd);
	//anadirInstalacionaBD("poli 2", "futbol", 1, bd);
	//borrarInstalacion(1, bd);
	//borrarPolideportivo(3, bd);
	//editarInstalacion(1, bd);
	//imprimirInstalacion(*cargarInstalacion(1, bd));
	imprimirPolideportivo(*cargarPolideportivo(2, bd));
	fflush(stdout);
	cerrarBD(bd);
}
