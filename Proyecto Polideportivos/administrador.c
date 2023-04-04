/*
 * administrador.c
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */
#include "administrador.h"
void filtroAdmin(sqlite3* bd,Polideportivo* poli){
	int opcion;
	printf("Introduce el id del Polideportivo a Consultar \n");
	printf("1.Salir \n");
	scanf("%d",opcion);
	// opcion == id-respectivo del poli
	if(opcion == 1){
		filtroPolideportivos(bd);
	}else{
		poli=cargarPolideportivo(opcion, bd);
	}
}

void filtroInstalaciones(sqlite3* bd,Polideportivo* poli){
	int opcion;
	Instalacion* inst= malloc(sizeof(Instalacion));
	printf("Elige una de las opciones\n");
	printf("1.Consultar Instalaciones \n");
	printf("2.Añadir Instalacion \n");
	printf("3.Editar Instalacion \n");
	printf("4.Borrar Instalacion \n");
	printf("5.Volver\n");
	scanf("%d",opcion);
	if(opcion ==1){
			consultarInstalaciones();
	}if(opcion == 2){
		inst=agregarInstalacion();
		anadirInstalacionaBD(inst->nombre, inst->id, inst->deporte, inst->horario, inst->id_poli, bd);
	}if(opcion == 3){
			editarInstalacion(inst, bd);
	}if(opcion == 4){
			menuBorrarInstalacion();
	}if(opcion == 5){
			filtroPolideportivos();
	}
}
void filtroPolideportivos(sqlite3* bd){
	int opcion;
	Polideportivo* p= malloc(sizeof(Polideportivo));
	printf("Elige una de las opciones\n");
	printf("1.Consultar Instalaciones \n");
	printf("2.Añadir Polideportivo \n");
	printf("3.Editar Polideportivo \n");
	printf("4.Borrar Polideportivo \n");
	printf("5.Volver\n");
	scanf("%d",opcion);
	if(opcion ==1){
			filtroInstalaciones(bd,p);
	}if(opcion == 2){
			p=agregarPolideportivo();
			anadirPolideportivoaBD(p->nombre, p->id, p->NumInsta, bd);
	}if(opcion == 3){
			filtroAdmin(bd,p);
			editarPolideportivo(p, bd);
	}if(opcion == 4){
		filroAdmin();
		menuBorrarPolideportivo(p,bd);
	}if(opcion == 5){
			filtroAdmin(bd,p);
	}
}
void menuBorrarInstalacion(Instalacion *insta,sqlite3* bd){
	int opcion;
	printf("¿Estas seguro que quieres borrar la Instalacion? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	scanf("%d",opcion);
	if(opcion == 1){
		//Proceso de borrado
		borrarInstalacion(insta, bd);
		//añadir un filtro
		printf("Intalacion borrada \n");
		//añadir direccionamiento
	}if(opcion == 2){
		filtoInstalaciones(insta);
	}
}

void menuBorrarPolideportivo(Polideportivo* poli,sqlite3* bd){
	int opcion;
	printf("¿Estas seguro que quieres borrar el Polideportivo? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	scanf("%d",opcion);
	if(opcion == 1){
		//Proceso de borrado
		borrarPolideportivo(poli, bd);
		printf("Polideportivo borrado \n");
		filtroAdmin();
	}if(opcion == 2){
		filtoPolideportivos(poli);
	};
}
