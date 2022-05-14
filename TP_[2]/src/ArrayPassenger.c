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
			resultado = PedirFlotante(&precioPasajero, "||Ingrese el precio del vuelo:", "||ERROR! Ingrese un valor valido", -1, 999999999);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR FLOTANTE\n");
			}
			resultado = PedirStringAlfaNumerico("||Ingrese el codigo de vuelo:", "||ERROR! Ingrese un codigo valido", codigoDeVuelo, 10);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR CODIGO\n");
			}
			ListarTiposDePasajeros(listType, lenType);
			resultado = PedirEntero(&tipoPasajero, "||Ingrese el numero correspondiente a la opcion adecuada:", "||ERROR! Ingrese un numero valido", 0, 4);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR ENTERO\n");
			}
			ListarEstadosDeVuelo(listStatus, lenStat);
			resultado = PedirEntero(&estadoVuelo, "||Ingrese el numero correspondiente a la opcion adecuada:", "||ERROR! Ingrese un numero valido", 0, 4);
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

int findPassengerById(Passenger* list, int len, int id)
{
	int indice;
	indice = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int BajaLogicaPasajero(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int resultado;
	int idIngresado;
	retorno = 0;

	if(list != NULL && lenPass > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		resultado = printPassenger(list, lenPass, listStatus, lenStat, listType, lenType);
		if(resultado == -1)
		{
			printf("FALLO AL IMPRIMIR PASAJEROS\n");
			retorno = -1;
		}
		else
		{
			resultado = PedirEntero(&idIngresado, "||Ingrese el ID del pasajero que desea dar de baja del sistema:", "||ERROR! Ingrese un ID valido:", 999, 3001);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR ENTERO\n");
			}
			resultado = removePassenger(list, lenPass, idIngresado);
			if(resultado == -1)
			{
				printf("||El indice ingresado no existe.\n");
				retorno = -1;
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno;
	int indice;
	int confirmar;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		indice = findPassengerById(list, len, id);
		if(indice > -1)
		{
			if(list[indice].isEmpty == 0 && list[indice].id == id)
			{
				printf("||¿Desea dar de baja al pasajero %s %s?", list[indice].name, list[indice].lastName);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					list[indice].isEmpty = 1;
					printf("||Baja del sistema realizada correctamente\n");
				}
				else
				{
					printf("||La baja del pasajero fue cancelada.\n\n");
				}
				retorno = 0;
			}
		}
	}

	return retorno;
}
/*
int sortPassengers(Passenger* list, int len, int order)
{

}*/

int printPassenger(Passenger* list, int lenght, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int indiceUno;
	int indiceDos;
	retorno = -1;

	if(list != NULL && lenght > 0)
	{
		for(int i=0; i<lenght; i++)
		{
			indiceUno = BuscarRelacionPasajeroEstado(list[i], listStatus, lenStat);
			indiceDos = BuscarRelacionPasajeroTipo(list[i], listType, lenType);
			if(indiceUno > -1 && indiceDos > -1)
			{
				ImprimirUnPasajero(list[i], listStatus[indiceUno], listType[indiceDos]);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int BuscarRelacionPasajeroEstado(Passenger onePassenger, sStatus* listStatus, int lenStat)
{
	int retorno;
	retorno = -1;

	for(int i=0; i<lenStat; i++)
	{
		if(onePassenger.isEmpty == 0 && (onePassenger.statusFlight == listStatus[i].statusFlight))
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}
int BuscarRelacionPasajeroTipo(Passenger onePassenger, sType* listType, int lenType)
{
	int retorno;
	retorno = -1;

	for(int i=0; i<lenType; i++)
	{
		if(onePassenger.isEmpty == 0 && (onePassenger.typePassenger == listType[i].typePassenger))
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

void ImprimirUnPasajero(Passenger onePassenger, sStatus oneStatus, sType oneType)
{
	printf("||%-5d|%-20s|%-20s|%-18.2f|%-15s|%-15s|%-15s||\n",onePassenger.id,
															onePassenger.name,
															onePassenger.lastName,
															onePassenger.price,
															onePassenger.flycode,
															oneType.descriptionType,
															oneStatus.descriptionStatus);
}


int AltaForzadaPasajeros(Passenger* list, int len)
{
	int retorno;
	int indice;
    char nombre[5][51]={"Ian", "Silvana", "Alexander", "Jose", "Irina"};
    char apellido[5][51]={"Pereyra", "Mendoza", "Iron", "Joestar", "DeCarim"};
    float precio[5]={12000, 7500.50, 2000.95, 15000, 16300.20};
    char codigoVuelo[5][10]={"4AEMGR1M3", "4AEMGR1M3", "7DEMON1S0", "2BATTL3T1", "7DEMON1S0"};
    int idType[5]={1, 1, 3, 2, 2};
    int idStatus[5]={2, 2, 1, 3, 1};
    retorno = -1;
    if(list != NULL && len > 0)
    {
    	for(int i=0; i<5; i++)
		{
			indice = BuscarEmpty(list, len);
			if(indice == -1)
			{
				printf("||No quedan espacios libres.\n");
			}
			else
			{
				list[indice].id = ObtenerPasajeroID();
				strcpy(list[indice].name, nombre[i]);
				strcpy(list[indice].lastName, apellido[i]);
				list[indice].price = precio[i];
				strcpy(list[indice].flycode, codigoVuelo[i]);
				list[indice].typePassenger = idType[i];
				list[indice].statusFlight = idStatus[i];
				list[indice].isEmpty = 0;
				retorno = 0;
			}
		}
    }

    return retorno;
}
/*
int sortPassengersByCode(Passenger* list, int len, int order)
{

}*/
