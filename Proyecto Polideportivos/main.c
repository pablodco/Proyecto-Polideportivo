#include <stdlib.h>
#include <stdio.h>
#include "administrador.h"
#include"polideportivo.h"

int main(void) {

	int numero;// Numero de la primera pregunta
	sqlite3* bd=cargarBD();
	int numPolis= numeroPolis(bd);
	int numInsta= numeroInstalaciones(bd);
	Polideportivo** listaPoli=cargarPolideportivos(bd);
	printf("Bienvenido a la gestion de polideportivos\n");
	printf("¿ Has iniciado sesion antes ?\n");
	printf("1 = Si // 2 = No \n");
	fflush(stdout);
	scanf("%d",&numero);
	int i;
	switch(numero){
	case 1:
		i=cargarAdmin(bd);
		printf("%i",i);
		if(i==0){
			filtroPolideportivos(bd);
		}else{
			printf("Ha habido un error con la contrasena");
		}
		break;
	case 2:
		registroAdmin(bd);
	}
	for(int e=0;e<numPolis;e++){
		free(listaPoli[e]->dir);
		free(listaPoli[e]->nombre);
		for(int j=0;j<numInsta;j++){
			free(listaPoli[e]->instalaciones[j]->nombre);
			free(listaPoli[e]->instalaciones[j]->deporte);
			free(listaPoli[e]->instalaciones[j]->horas);
		}
	}
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
	//imprimirPolideportivo(*cargarPolideportivo(2, bd));
	//fflush(stdout);

	cerrarBD(bd);
}


void filtroPolideportivos(sqlite3* bd){
	int opcion;
	printf("Elige una de las opciones\n");
	printf("1.Consultar Instalaciones \n");
	printf("2.Añadir Polideportivo \n");
	printf("3.Editar Polideportivo \n");
	printf("4.Borrar Polideportivo \n");
	printf("5.Volver\n");
	fflush(stdout);
	scanf("%d",&opcion);
	Polideportivo* p=(Polideportivo*) malloc(sizeof(Polideportivo));
	if(opcion ==1){
			filtroAdmin(bd);
			filtroInstalaciones(bd,p);
	}if(opcion == 2){
			p=agregarPolideportivo(bd);
			anadirPolideportivoaBD(p->nombre, p->NumInsta,p->dir, bd);
	}if(opcion == 3){
			filtroAdmin(bd);
			editarPolideportivo(p->id, bd);
	}if(opcion == 4){
		filtroAdmin(bd);
		menuBorrarPolideportivo(p,bd);
	}if(opcion == 5){
			filtroAdmin(bd);
	}
}

void filtroInstalaciones(sqlite3* bd,Polideportivo* poli){
	int opcion;
	Instalacion* inst= (Instalacion*)malloc(sizeof(Instalacion));
	printf("Elige una de las opciones\n");
	fflush(stdout);
	printf("1.Consultar Instalaciones \n");
	fflush(stdout);
	printf("2.Añadir Instalacion \n");
	fflush(stdout);
	printf("3.Editar Instalacion \n");
	fflush(stdout);
	printf("4.Borrar Instalacion \n");
	fflush(stdout);
	printf("5.Volver\n");
	fflush(stdout);
	scanf("%d",&opcion);
	if(opcion == 2){
		inst=agregarInstalacion(inst);
		anadirInstalacionaBD(inst->nombre, inst->deporte,inst->id_poli, bd);
	}if(opcion == 3){
		printf("Inserta el id de la instalacion:");
		fflush(stdout);
		int id;
		scanf("%d",&id);
		inst=cargarInstalacion(id, bd);
		editarInstalacion(inst, bd);
	}if(opcion == 4){
			menuBorrarInstalacion(inst,bd,poli);
	}if(opcion == 5){
			filtroPolideportivos(bd);
	}
}
void filtroAdmin(sqlite3* bd){
	int opcion;
	printf("Introduce el id del Polideportivo a Consultar \n");
	printf("0.Salir \n");
	fflush(stdout);
	scanf("%d",&opcion);
	// opcion == id-respectivo del poli
	if(opcion == 0){
		filtroPolideportivos(bd);
	}else{
		Polideportivo* poli=cargarPolideportivo(opcion, bd);
		filtroInstalaciones(bd, poli);
	}
}

void menuBorrarInstalacion(Instalacion *insta,sqlite3* bd,Polideportivo* poli){
	int opcion;
	printf("¿Estas seguro que quieres borrar la Instalacion? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	fflush(stdout);
	scanf("%d",&opcion);
	if(opcion == 1){
		//Proceso de borrado
		borrarInstalacion(insta, bd);
		//añadir un filtro
		printf("Intalacion borrada \n");
		//añadir direccionamiento
	}if(opcion == 2){
		filtroInstalaciones(bd,poli);
	}
}

void menuBorrarPolideportivo(Polideportivo* poli,sqlite3* bd){
	int opcion;
	printf("¿Estas seguro que quieres borrar el Polideportivo? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	fflush(stdout);
	scanf("%d",&opcion);
	if(opcion == 1){
		//Proceso de borrado
		borrarPolideportivo(poli, bd);
		printf("Polideportivo borrado \n");
		fflush(stdout);
		filtroPolideportivos(bd);
	}if(opcion == 2){
		filtroPolideportivos(bd);
	};
}
