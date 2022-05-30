/*
 ============================================================================
 Name        : TP_[3].c
 Author      : Pereyra Ian
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros;
	listaPasajeros = ll_newLinkedList();
	int opcion = 0;
	int resultado = 0;
	char* path = {"./data.csv"};

	do{
		switch(opcion)
		{
			case 1:
				controller_loadFromText(path,listaPasajeros);
				break;
		}
	}while(opcion != 10);


    system("pause");
    return 0;
}

/*Que vi de la clase 19?, setters y getters de distintos parametros, funciones para cargar una entidad reservando
 * memoria desde la pila, verificando con NULLs y etcetera, funciones que guardan archivos en formato csv, funciones
 * que escriben en consola los datos del archivo, funciones respetando el tipo de dato y funciones que aceptan
 * todoo como char*.*/
