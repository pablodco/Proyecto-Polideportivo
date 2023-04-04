/*
 * administrador.c
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */

void filtroAdmin(){
	int opcion;
	printf("Introduce el id del Polideportivo a Consultar \n");
	printf("1.Salir \n");
	scanf("%d",opcion);
	// opcion == id-respectivo del poli
	if(opcion ==2){
		filtroPolideportivos();
	}if(opcion == 1){
		printf("SALIDA");
	}
}

void filtoInstalaciones(Instalacion *insta){
	int opcion;
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
			agregarInstalacion();
	}if(opcion == 3){
			editarInstalacion();
	}if(opcion == 4){
			borrarInstalacion();
	}if(opcion == 5){
			filtroPolideportivos();
	}
}
void filtoPolideportivos(Polideportivo poli){
	int opcion;
	printf("Elige una de las opciones\n");
	printf("1.Consultar Instalaciones \n");
	printf("2.Añadir Polideportivo \n");
	printf("3.Editar Polideportivo \n");
	printf("4.Borrar Polideportivo \n");
	printf("5.Volver\n");
	scanf("%d",opcion);
	if(opcion ==1){
			filtroInstalaciones(poli.instalaciones);
	}if(opcion == 2){
			agregarPolideportivo();
	}if(opcion == 3){
			editarPolideportivo();
	}if(opcion == 4){
			borrarPolideportivo(poli);
	}if(opcion == 5){
			filtroAdmin();
	}
}
void borrarInstalacion(Instalacion *insta){
	int opcion;
	printf("¿Estas seguro que quieres borrar la Instalacion? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	scanf("%d",opcion);
	if(opcion == 1){
		//Proceso de borrado
		//añadir un filtro
		printf("Intalacion borrada \n");
		//añadir direccionamiento
	}if(opcion == 2){
		filtoInstalaciones(insta);
	}
}

void borrarPolideportivo(Polideportivo poli){
	int opcion;
	printf("¿Estas seguro que quieres borrar el Polideportivo? \n");
	printf("1.Si, estoy seguro\n");
	printf("2.No, volver \n");
	scanf("%d",opcion);
	if(opcion == 1){
		//Proceso de borrado
		printf("Polideportivo borrado \n");
		filtroAdmin();
	}if(opcion == 2){
		filtoPolideportivos(poli);
	}
}
