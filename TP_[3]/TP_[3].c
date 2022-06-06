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
#include "InputsDatos.h"
#include "parser.h"

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
	int banderaListaCargada = 0;
	//int banderaUnPasajero = 0;
	//int banderaDatosGuardados = 0;
	char* path = {"./data.csv"};
	//char* binaryPath = {""};
	do{
		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de pasajero.\n");
		printf("4. Modificar datos de pasajero.\n");
		printf("5. Baja de pasajero.\n");
		printf("6. Listar pasajeros.\n");
		printf("7. Ordenar pasajeros.\n");
		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
		resultado = PedirEntero(&opcion, "10. Salir.", "Opcion invalida! Intente nuevamente.", 0, 11);
		if(resultado != 0)
		{
			printf("ERROR!\n");
		}
		switch(opcion)
		{
			case 1:
				if(banderaListaCargada == 0)
				{
					resultado = controller_loadFromText(path,listaPasajeros);
					if(resultado == 1)
					{
						printf("Carga de datos exitosa!\n");
						banderaListaCargada = 1;
						//TEST ONLY
						resultado = ll_len(listaPasajeros);
						printf("Elementos de la lista: %d\n", resultado);
					}
					else
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("Los datos ya fueron cargados.\n");
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				if(banderaListaCargada == 1)
				{
					resultado = controller_ListPassenger(listaPasajeros);
					if(resultado != 1)
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para mostrar.\n");
				}
				break;
			case 7:
				if(banderaListaCargada == 1)
				{
					resultado = controller_sortPassenger(listaPasajeros);
					if(resultado != 1)
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para ordenar.\n");
				}
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				printf("Cerrando aplicacion...\n");
				break;
		}
	}while(opcion != 10);

    system("pause");
    return 0;
}
