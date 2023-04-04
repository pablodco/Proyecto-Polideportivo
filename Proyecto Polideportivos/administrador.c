/*
 * administrador.c
 *
 *  Created on: 2 abr 2023
 *      Author: pablo
 */

void filtroAdmin(){
	int opcion;
	printf("Elige una de las opciones\n");
	printf("1.Instalaciones \n");
	printf("2.Polideportivos \n");
	printf("3.Salir \n");
	scanf("%d",opcion);
	if(opcion ==1){
		filtoInstalaciones();
	}if(opcion == 2){
		filtroPolideportivos();
	}if(opcion == 3){
		printf("SALIDA");
	}
}

