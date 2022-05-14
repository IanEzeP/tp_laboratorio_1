/*
 * ArrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InputsDatos.h"
#include "ArrayPassenger.h"

static int idIncrementalPasajeros = 1000;
static int ObtenerPasajeroID();
static int ObtenerPasajeroID()
{
	return idIncrementalPasajeros++;
}

int initPassengers(Passenger* list, int len)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int CargarPasajeros(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int resultado;
	retorno = -1;
	if(list != NULL && lenPass > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		resultado = PedidoDeDatos(list, lenPass, listStatus, lenStat, listType, lenType);
		if(resultado == -1)
		{
			printf("FALLO AL PEDIR DATOS\n");
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}

int BuscarEmpty(Passenger* list, int lenPass)
{
	int index;
	index = -1;

	if(list != NULL && lenPass > 0)
	{
		for(int i=0; i<lenPass; i++)
		{
			if(list[i].isEmpty == 1)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int PedidoDeDatos(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int index;
	int retorno;
	int resultado;
	int idPasajero;
	int tipoPasajero;
	int estadoVuelo;
	char nombrePasajero[51];
	char apellidoPasajero[51];
	char codigoDeVuelo[10];
	float precioPasajero;
	retorno = -1;

	if(list != NULL && lenPass > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		index = BuscarEmpty(list, lenPass);
		if(index != -1)
		{
			idPasajero = ObtenerPasajeroID();
			resultado = PedirString("||Ingrese el nombre del pasajero:", "||ERROR! Ingrese un nombre real", nombrePasajero, 51);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR NOMBRE\n");
			}
			resultado = PedirString("||Ingrese el apellido del pasajero:", "||ERROR! Ingrese un apellido real", apellidoPasajero, 51);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR APELLIDO\n");
			}
			resultado = PedirFlotante(&precioPasajero, "||Ingrese el precio del vuelo", "||ERROR! Ingrese un valor valido", -1, 999999999);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR FLOTANTE\n");
			}
			resultado = PedirStringAlfaNumerico("||Ingrese el codigo de vuelo", "||ERROR! Ingrese un codigo valido", codigoDeVuelo, 10);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR CODIGO\n");
			}
			ListarTiposDePasajeros(listType, lenType);
			resultado = PedirEntero(&tipoPasajero, "||Ingrese el numero correspondiente a la opcion adecuada", "||ERROR! Ingrese un numero valido", 0, 4);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR ENTERO\n");
			}
			ListarEstadosDeVuelo(listStatus, lenStat);
			resultado = PedirEntero(&estadoVuelo, "||Ingrese el numero correspondiente a la opcion adecuada", "||ERROR! Ingrese un numero valido", 0, 4);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR ENTERO\n");
			}
			resultado = addPassenger(list, lenPass, idPasajero, nombrePasajero, apellidoPasajero, precioPasajero, tipoPasajero, codigoDeVuelo, estadoVuelo, index);
			if(resultado == -1)
			{
				printf("FALLO AL CARGAR DATOS EN EL VECTOR\n");
			}
			retorno = 0;
		}

	}

	return retorno;
}

void ListarTiposDePasajeros(sType* listType, int lenType)
{
	if(listType != NULL && lenType > 0)
	{
		printf("||LISTA DE TIPOS DE PASAJEROS\n");
		for(int i=0; i<lenType; i++)
		{
			printf("||%-3d|%20s|\n", listType[i].typePassenger, listType[i].descriptionType);
		}
	}
}

void ListarEstadosDeVuelo(sStatus* listStatus, int lenStat)
{
	if(listStatus != NULL && lenStat > 0)
	{
		printf("||LISTA DE ESTADOS DE VUELO\n");
		for(int i=0; i<lenStat; i++)
		{
			printf("||%-2d|%20s|\n", listStatus[i].statusFlight, listStatus[i].descriptionStatus);
		}
	}
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight, int index)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		strcpy(list[index].flycode, flycode);
		list[index].statusFlight = statusFlight;
		list[index].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}
/*
int findPassengerById(Passenger* list, int len, int id)
{

}

int removePassenger(Passenger* list, int len, int id)
{

}

int sortPassengers(Passenger* list, int len, int order)
{

}

int printPassenger(Passenger* list, int lenght)
{

}

int sortPassengers(Passenger* list, int len, int order)
{

}*/
