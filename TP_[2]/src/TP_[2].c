	/*
	============================================================================
	Name        : TP_[2].c
	Author      : Pereyra Ian Ezequiel
	Version     :
	Copyright   : Your copyright notice
	Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo.
	Se sabe que no puede tener más de 2000 pasajeros.
	1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el número de Id.
	El resto de los campos se le pedirá al usuario.
	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
	Nombre
	Apellido
	Precio
	Tipo de pasajero
	Código de vuelo
	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
	4. INFORMAR:
	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
	promedio.
	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
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
	int banderaAltaForzada;
	banderaAltaForzada = 0;

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
		if(resultado == -1)
		{
			printf("ERROR AL PEDIR ENTERO\n");
		}
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
			resultado = ModificarPasajero(listaPasajeros, LEN, listaEstados, 3, listaTipos, 3);
			if(resultado == -1)
			{
				printf("||No se pudo acceder al menu de modificacion\n");
			}
			break;
		case 3:
			resultado = BajaLogicaPasajero(listaPasajeros, LEN, listaEstados, 3, listaTipos, 3);
			if(resultado == -1)
			{
				printf("||No se pudo eliminar al pasajero\n");
			}
			break;
		case 4:
			resultado = MenuListados(listaPasajeros, LEN, listaEstados, 3, listaTipos, 3);
			if(resultado == -1)
			{
				printf("||FALLO AL MOSTRAR EL MENU DE LISTADOS\n");
			}
			break;
		case 5:
			if(banderaAltaForzada == 0)
			{
				resultado = AltaForzadaPasajeros(listaPasajeros, LEN);
				if(resultado == 0)
				{
					printf("||Alta forzada de pasajeros realizada de forma exitosa.\n");
					banderaAltaForzada = 1;
				}
				else
				{
					printf("||FALLO AL INTENTAR REALIZAR ALTA FORZADA.\n");
				}
			}
			else
			{
				printf("||La carga forzada ya fue realizada una vez.\n");
			}
			break;
		case 6:
			printf("||Cerrando programa...\n");
			break;
		}
	}while(opcionIngresada != 6);

	system("pause");
	return 0;
	}
