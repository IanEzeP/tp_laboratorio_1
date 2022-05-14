/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Pereyra Ian Ezequiel
 Version     :
 Copyright   : Your copyright notice
 Description : Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo.
 Se sabe que no puede tener m�s de 2000 pasajeros.
 1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el n�mero de Id.
 El resto de los campos se le pedir� al usuario.
 2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar:
 Nombre
 Apellido
 Precio
 Tipo de pasajero
 C�digo de vuelo
 3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
 4. INFORMAR:
 1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
 2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
 promedio.
 3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "InputsDatos.h"
#include "ArrayPassenger.h"

int main(void)
{
	setbuf(stdout, NULL);

	sType listaTipos[] = {{1, "Turista"},{2, "Primera Clase"},{3, "Ejecutivo"}};
	sStatus listaEstados[] = {{1, "ACTIVO"}, {2, "DEMORADO"}, {3, "CANCELADO"}};
	Passenger listaPasajeros[LEN];

	int resultado;
	int opcionIngresada;

	resultado = initPassengers(listaPasajeros, LEN);
	if(resultado == -1)
	{
		printf("ERROR AL INICIAR ARRAY PASAJEROS");
	}
	do{
			printf("\n||Para interactuar con el programa ingrese el numero correspondiente a la opcion deseada:\n");
			printf("||1. ALTA PASAJERO\n");
			printf("||2. MODIFICAR PASAJERO\n");
			printf("||3. BAJA DE PASAJERO\n");
			printf("||4. INFORMAR\n");
			printf("||5. ALTA FORZADA DE PASAJEROS\n");
			resultado = PedirEntero(&opcionIngresada, "||6. CERRAR PROGRAMA", "||Opcion invalida!", 0, 7);
			switch(opcionIngresada)
			{
			case 1:
				resultado = CargarPasajeros(listaPasajeros, LEN, listaEstados, 3, listaTipos, 3);
				if(resultado == -1)
				{
					printf("||No se pudo cargar al pasajero\n");
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
				printf("||Cerrando programa...\n");
				break;
			}
		}while(opcionIngresada != 6);







	system("pause");
	return 0;
}
