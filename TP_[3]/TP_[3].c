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
	int banderaListaCargadaTxT = 0;
	int banderaListaCargadaBin = 0;
	int ultimoId;
	int banderaDatosGuardadosTxT = 0;
	int banderaDatosGuardadosBin = 0;

	char* idPath = {"./lastID.txt"};
	char* path = {"./new_data.csv"};
	char* binaryPath = {"./new_data.bin"};

	do{
		ultimoId = controller_saveLastID(idPath, listaPasajeros);
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
				if(banderaListaCargadaTxT == 0 && banderaListaCargadaBin == 0)
				{
					resultado = controller_loadFromText(path,listaPasajeros);
					if(resultado == 1)
					{
						printf("Carga de datos exitosa!\n");
						banderaListaCargadaTxT = 1;
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
				if(banderaListaCargadaTxT == 0 && banderaListaCargadaBin == 0)
				{
					resultado = controller_loadFromBinary(binaryPath, listaPasajeros);
					if(resultado == 1)
					{
						printf("Carga de datos exitosa.\n");
						banderaListaCargadaBin = 1;
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
			case 3:
				resultado = controller_addPassenger(listaPasajeros, ultimoId);
				if(resultado == 1)
				{
					printf("Pasajero cargado de forma exitosa.\n");
					banderaDatosGuardadosTxT = 0;
					banderaDatosGuardadosBin = 0;
				}
				else
				{
					printf("ERROR!\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					resultado = controller_editPassenger(listaPasajeros);
					if(resultado == 1)
					{
						banderaDatosGuardadosTxT = 0;
						banderaDatosGuardadosBin = 0;
					}
					else
					{
						if(resultado == 0)
						{
							printf("No se hallo el ID ingresado.\n");
						}
						else
						{
							printf("ERROR!\n");
						}
					}
				}
				else
				{
					printf("No hay elementos para modificar.\n");
				}
				break;
			case 5:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					resultado = controller_removePassenger(listaPasajeros);
					if(resultado == 1)
					{
						banderaDatosGuardadosTxT = 0;
						banderaDatosGuardadosBin = 0;
					}
					else
					{
						if(resultado == 0)
						{
							printf("No se hallo el ID ingresado.\n");
						}
						else
						{
							printf("ERROR!\n");
						}
					}
				}
				else
				{
					printf("No hay elementos para eliminar.\n");
				}
				break;
			case 6:
				if(ll_isEmpty(listaPasajeros)==0)
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
				if(ll_isEmpty(listaPasajeros)==0)
				{
					resultado = controller_sortPassenger(listaPasajeros);
					if(resultado != 0)
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
				if(banderaListaCargadaTxT == 1 || banderaListaCargadaBin == 1)
				{
					resultado = controller_saveAsText(path, listaPasajeros);
					if(resultado == 1)
					{
						printf("Los datos fueron guardados correctamente.\n");
						banderaDatosGuardadosTxT = 1;
					}
					else
					{
						printf("ERROR.\n");
					}
				}
				else
				{
					printf("No se pueden guardar datos si la lista no fue cargada.\n");
				}
				break;
			case 9:
				if(banderaListaCargadaTxT == 1 || banderaListaCargadaBin == 1)
				{
					resultado = controller_saveAsBinary(binaryPath, listaPasajeros);
					if(resultado == 1)
					{
						printf("Los datos fueron guardados correctamente.\n");
						banderaDatosGuardadosBin = 1;
					}
					else
					{
						printf("ERROR.\n");
					}
				}
				else
				{
					printf("No se pueden guardar datos si la lista no fue cargada.\n");
				}
				break;
			case 10:
				if(banderaDatosGuardadosTxT == 0 || banderaDatosGuardadosBin == 0)
				{
					printf("No puede cerrar la aplicacion sin guardar los datos.\n");
				}
				else
				{
					printf("Cerrando aplicacion...\n");
				}
				break;
		}
	}while(opcion != 10 || banderaDatosGuardadosTxT == 0 || banderaDatosGuardadosBin == 0);

    system("pause");
    return 0;
}
