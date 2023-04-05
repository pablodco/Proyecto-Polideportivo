/*
 * administrador.c
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */
#include "administrador.h"

void iniciarAdmin(sqlite3* bd){
	int id;
	char* aux= (char*)malloc(sizeof(char)*100);
	printf("Introduzca el dni:");
	fflush(stdout);
	scanf("%d", id);
	printf("Introduzca contrasena:");
	fflush(stdout);
	scanf("%s",aux);
	//cargarAdmin(id,aux,bd);
}
void registroAdmin(sqlite3* bd){
		Administrador* admin=
		(Administrador*)malloc(sizeof(Administrador));
		char* aux= (char*)malloc(sizeof(char)*100);
		printf("Introduzca el dni:");
		fflush(stdout);
		scanf("%s", &admin->id);
		printf("Introduzca el nombre:");
		fflush(stdout);
		scanf("%s", aux);
		admin->nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->nombre,aux);
		printf("Introduzca el apellido:");
		fflush(stdout);
		scanf("%s",aux);
		admin->apellido=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->apellido,aux);
		printf("Introduzca el email:");
		fflush(stdout);
		scanf("%s", aux);
		admin->email=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->email,aux);
		printf("Introduzca la contrasena:");
		fflush(stdout);
		admin->contrasena=(char*)malloc(sizeof(char)*(strlen(aux)+1));
		strcpy(admin->contrasena,aux);
		printf("Introduzca el polideportivo para el que trabaja:");
		fflush(stdout);
		scanf("%d",&admin->id_poli);
		free(aux);
		anadirAdmin(bd, admin->id, admin->nombre, admin->apellido, admin->email, admin->contrasena, admin->id_poli);
		filtroPolideportivos(bd);
}
void filtroAdmin(sqlite3* bd){
	int opcion;
	printf("Introduce el id del Polideportivo a Consultar \n");
	printf("1.Salir \n");
	fflush(stdout);
	scanf("%d",&opcion);
	// opcion == id-respectivo del poli
	if(opcion == 1){
		filtroPolideportivos(bd);
	}else{
		Polideportivo* poli=cargarPolideportivo(opcion, bd);
		filtroInstalaciones(bd, poli);
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
	if(opcion ==1){
			//consultarInstalaciones();
	}if(opcion == 2){
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
			p=agregarPolideportivo();
			anadirPolideportivoaBD(p->nombre, p->NumInsta,p->dir, bd);
	}if(opcion == 3){
			filtroAdmin(bd);
			editarPolideportivo(p, bd);
	}if(opcion == 4){
		filtroAdmin(bd);
		menuBorrarPolideportivo(p,bd);
	}if(opcion == 5){
			filtroAdmin(bd);
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
