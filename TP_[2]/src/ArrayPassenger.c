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
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int ModificarPasajero(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int resultado;
	int idIngresado;
	int indice;
	retorno = -1;

	if(list != NULL && lenPass > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		resultado = printPassenger(list, lenPass, listStatus, lenStat, listType, lenType);
		if(resultado == -1)
		{
			printf("FALLO AL IMPRIMIR PASAJEROS\n");
		}
		else
		{
			resultado = PedirEntero(&idIngresado, "||Ingrese el ID del pasajero que desea modificar:", "||ERROR! Ingrese un ID valido:", 999, 3001);
			if(resultado == -1)
			{
				printf("FALLO AL PEDIR ENTERO\n");
			}
			indice = findPassengerById(list, lenPass, idIngresado);
			if(indice == -1)
			{
				printf("||El indice ingresado no existe.\n");
			}
			else
			{
				resultado = modifyPassenger(list, lenPass, indice, listType, lenType);
				if(resultado == -1)
				{
					printf("FALLO AL MODIFICAR PASAJERO\n");
				}
				retorno = 0;
			}
		}
	}

	return retorno;
}

int modifyPassenger(Passenger* list, int len, int index, sType* listType, int lenType)
{
	int retorno;
	int opcion;
	int resultado;
	int confirmar;
	char nuevoNombre[51];
	char nuevoApellido[51];
	float nuevoPrecio;
	int nuevoTipo;
	char descripcionNuevoTipo[21];
	char nuevoCodigo[10];
	int indiceTipo;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		do
		{
			printf("||1. MODIFICAR NOMBRE\n");
			printf("||2. MODIFICAR APELLIDO\n");
			printf("||3. MODIFICAR PRECIO\n");
			printf("||4. MODIFICAR TIPO DE PASAJERO\n");
			printf("||5. MODIFICAR CODIGO DE VUELO\n");
			resultado = PedirEntero(&opcion, "||6. VOLVER AL MENU", "||Opcion invalida!", 0, 7);
			switch(opcion)
			{
			case 1:
				resultado = PedirString("||Ingrese el nuevo nombre:", "||ERROR! Ingrese un nombre real", nuevoNombre, 51);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR NOMBRE\n");
				}
				printf("||¿Desea cambiar el nombre del pasajero %s por %s?", list[index].name, nuevoNombre);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					strcpy(list[index].name, nuevoNombre);
					printf("||El nombre fue modificado correctamente\n");
				}
				else
				{
					printf("||La modificacion del nombre fue cancelada.\n\n");
				}
				break;
			case 2:
				resultado = PedirString("||Ingrese el nuevo apellido:", "||ERROR! Ingrese un apellido real", nuevoApellido, 51);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR APELLIDO\n");
				}
				printf("||¿Desea cambiar el apellido del pasajero %s por %s?", list[index].lastName, nuevoApellido);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					strcpy(list[index].lastName, nuevoApellido);
					printf("||El apellido fue modificado correctamente\n");
				}
				else
				{
					printf("||La modificacion del apellido fue cancelada.\n\n");
				}
				break;
			case 3:
				resultado = PedirFlotante(&nuevoPrecio, "||Ingrese el nuevo precio:", "ERROR! Ingrese un precio valido", -1, 999999999);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR FLOTANTE\n");
				}
				printf("||¿Desea cambiar el precio de %.2f a %.2f?", list[index].price, nuevoPrecio);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					list[index].price = nuevoPrecio;
					printf("||El precio fue modificado correctamente\n");
				}
				else
				{
					printf("||La modificacion del precio fue cancelada.\n\n");
				}
				break;
			case 4:
				ListarTiposDePasajeros(listType, lenType);
				resultado = PedirEntero(&nuevoTipo, "||Ingrese el numero correspondiente al nuevo tipo de pasajero:", "||ERROR! Ingrese un numero valido", 0, 4);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR ENTERO\n");
				}
				for(int j=0; j<lenType; j++)
				{
					if(nuevoTipo == listType[j].typePassenger)
					{
						strcpy(descripcionNuevoTipo, listType[j].descriptionType);
						break;
					}
				}
				indiceTipo = BuscarRelacionPasajeroTipo(list[index], listType, lenType);
				printf("||¿Desea modificar el tipo de pasajero %s por %s?", listType[indiceTipo].descriptionType, descripcionNuevoTipo);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					list[index].typePassenger = nuevoTipo;
					printf("||El tipo de pasajero fue modificado correctamente.\n");
				}
				else
				{
					printf("||La modificacion del tipo de pasajero fue cancelada.\n\n");
				}
				break;
			case 5:
				resultado = PedirStringAlfaNumerico("||Ingrese el nuevo codigo:", "||ERROR! Ingrese un codigo valido", nuevoCodigo, 10);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR CODIGO\n");
				}
				printf("||¿Desea cambiar el codigo del vuelo %s por %s?", list[index].flycode, nuevoCodigo);
				confirmar = ConfirmarCambios();
				if(confirmar == 1)
				{
					strcpy(list[index].flycode, nuevoCodigo);
					printf("||El codigo del vuelo fue modificado correctamente\n");
				}
				else
				{
					printf("||La modificacion del codigo del vuelo fue cancelada.\n\n");
				}
				break;
			}
		}while(opcion != 6);
	}

	return retorno;
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

int MostrarVuelosActivos(Passenger* list, int lenght, sStatus* listStatus, int lenStat, sType* listType, int lenType)
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
			if(list[i].statusFlight == 1 && (indiceUno > -1 && indiceDos > -1))
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

int MenuListados(Passenger* list, int lenPass, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int opcion;
	int resultado;
	int orden;
	retorno = -1;
	if(list != NULL && lenPass > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		retorno = 0;
		do{
			printf("\n||Ingrese el numero correspondiente al informe que desea ver:\n");
			printf("||1. Listar pasajeros por orden alfabetico de Apellido y tipo de pasajero.\n");
			printf("||2. Listar total y promedio de precios de los pasajes y los pasajeros que superan el precio promedio\n");
			printf("||3. Listar pasajeros por codigo de vuelo y estados de vuelos ‘ACTIVO’\n");
			resultado = PedirEntero(&opcion, "||4. Volver al menu", "||Opcion invalida!", 0, 5);
			if(resultado == -1)
			{
				printf("ERROR AL PEDIR ENTERO\n");
			}
			switch(opcion)
			{
			case 1:
				resultado = PedirEntero(&orden, "||Ingrese el numero 1 para desplegar el listado de forma ascendente o el numero 0 para desplegar el listado de forma descendente:", "||ERROR! Ingrese el numero 1 para desplegar el listado de forma ascendente o el numero 0 para desplegar el listado de forma descendente:", -1, 2);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR ENTERO\n");
				}
				resultado = sortPassengers(list, lenPass, orden, listStatus, lenStat, listType, lenType);
				if(resultado == -1)
				{
					printf("FALLO AL LISTAR PASAJEROS ORDENADOS\n");
				}
				break;
			case 2:
				resultado = MostrarTotalYPromedioDePrecios(list, lenPass);
				if(resultado == -1)
				{
					printf("FALLO AL TOTAL Y PROMEDIO DE PRECIOS\n");
				}
				break;
			case 3:
				resultado = PedirEntero(&orden, "||Ingrese el numero 1 para desplegar el listado de forma ascendente o el numero 0 para desplegar el listado de forma descendente:", "||ERROR! Ingrese el numero 1 para desplegar el listado de forma ascendente o el numero 0 para desplegar el listado de forma descendente:", -1, 2);
				if(resultado == -1)
				{
					printf("FALLO AL PEDIR ENTERO\n");
				}
				resultado = sortPassengersByCode(list, lenPass, orden, listStatus, lenStat, listType, lenType);
				if(resultado == -1)
				{
					printf("FALLO AL LISTAR PASAJEROS ORDENADOS\n");
				}
				break;
			}
		}while(opcion != 4);
	}


	return retorno;
}

int sortPassengers(Passenger* list, int len, int order, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int resultado;
	retorno = -1;

	if(list != NULL && len > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		retorno = 0;
		if(order == 1)
		{
			resultado = OrdenarPasajerosPorApellidoAscendente(list, len, listType, lenType);
			if(resultado == -1)
			{
				printf("FALLO AL ORDENAR DE FORMA ASCENDENTE\n");
			}
		}
		else
		{
			resultado = OrdenarPasajerosPorApellidoDescendente(list, len, listType, lenType);
			if(resultado == -1)
			{
				printf("FALLO AL ORDENAR DE FORMA DESCENDENTE\n");
			}
		}
		resultado = printPassenger(list, len, listStatus, lenStat, listType, lenType);
		if(resultado == -1)
		{
			printf("FALLO AL MOSTRAR PASAJEROS\n");
		}
	}

	return retorno;
}

int OrdenarPasajerosPorApellidoAscendente(Passenger* list, int len, sType* listType, int lenType)
{
	int retorno;
	int indiceUno;
	int indiceDos;
	Passenger auxiliar;
	retorno = -1;
	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		retorno = 0;
		for(int i=0; i<len-1; i++)
		{
			indiceUno = BuscarRelacionPasajeroTipo(list[i], listType, lenType);
			for(int j=i+1; j<len; j++)
			{
				indiceDos = BuscarRelacionPasajeroTipo(list[j], listType, lenType);
				if((indiceUno > -1 && indiceDos > -1) && strcmp(list[i].lastName, list[j].lastName) > 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
				else
				{
					if((indiceUno > -1 && indiceDos > -1) && strcmp(list[i].lastName, list[j].lastName) == 0 && strcmp(listType[indiceUno].descriptionType, listType[indiceDos].descriptionType) > 0)
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}
			}
		}
	}

	return retorno;
}

int OrdenarPasajerosPorApellidoDescendente(Passenger* list, int len, sType* listType, int lenType)
{
	int retorno;
	int indiceUno;
	int indiceDos;
	Passenger auxiliar;
	retorno = -1;
	if(list != NULL && len > 0 && listType != NULL && lenType > 0)
	{
		retorno = 0;
		for(int i=0; i<len-1; i++)
		{
			indiceUno = BuscarRelacionPasajeroTipo(list[i], listType, lenType);
			for(int j=i+1; j<len; j++)
			{
				indiceDos = BuscarRelacionPasajeroTipo(list[j], listType, lenType);
				if((indiceUno > -1 && indiceDos > -1) && strcmp(list[i].lastName, list[j].lastName) < 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
				else
				{
					if((indiceUno > -1 && indiceDos > -1) && strcmp(list[i].lastName, list[j].lastName) == 0 && strcmp(listType[indiceUno].descriptionType, listType[indiceDos].descriptionType) < 0)
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}
			}
		}
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order, sStatus* listStatus, int lenStat, sType* listType, int lenType)
{
	int retorno;
	int resultado;
	retorno = -1;

	if(list != NULL && len > 0 && listStatus != NULL && lenStat > 0 && listType != NULL && lenType > 0)
	{
		retorno = 0;
		if(order == 1)
		{
			resultado = OrdenarPasajerosPorCodigoAscendente(list, len);
			if(resultado == -1)
			{
				printf("FALLO AL ORDENAR DE FORMA ASCENDENTE\n");
			}
		}
		else
		{
			resultado = OrdenarPasajerosPorCodigoDescendente(list, len);
			if(resultado == -1)
			{
				printf("FALLO AL ORDENAR DE FORMA DESCENDENTE\n");
			}
		}
		resultado = MostrarVuelosActivos(list, len, listStatus, lenStat, listType, lenType);
		if(resultado == -1)
		{
			printf("FALLO AL MOSTRAR PASAJEROS\n");
		}
	}

	return retorno;
}

int OrdenarPasajerosPorCodigoAscendente(Passenger* list, int len)
{
	int retorno;
	Passenger auxiliar;
	retorno = -1;
	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if(strcmp(list[i].flycode, list[j].flycode) > 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
	}

	return retorno;
}

int OrdenarPasajerosPorCodigoDescendente(Passenger* list, int len)
{
	int retorno;
	Passenger auxiliar;
	retorno = -1;
	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if(strcmp(list[i].flycode, list[j].flycode) < 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
			}
		}
	}

	return retorno;
}

int MostrarTotalYPromedioDePrecios(Passenger* list, int lenPass)
{
	int retorno;
	int resultado;
	int totalPasajeros;
	int contadorMayorPromedio;
	float totalPrecios;
	float promedio;
	contadorMayorPromedio = 0;
	retorno = -1;

	if(list != NULL && lenPass > 0)
	{
		retorno = 0;
		resultado = CalcularTotal(&totalPrecios, list, lenPass);
		if(resultado == -1)
		{
			printf("ERROR AL CALCULAR TOTAL\n");
		}
		resultado = ContarPasajeros(&totalPasajeros, list, lenPass);
		if(resultado == -1)
		{
			printf("ERROR AL CONTAR PASAJEROS\n");
		}
		promedio = (float)totalPrecios / totalPasajeros;
		for(int i=0; i<lenPass; i++)
		{
			if(list[i].isEmpty == 0 && list[i].price > promedio)
			{
				contadorMayorPromedio++;
			}
		}
		printf("||Total de los precios de los pasajes: %f\n||Promedio de los precios: %f\n||Cantidad de pasajeros por encima del promedio: %d\n", totalPrecios, promedio, contadorMayorPromedio);
	}


	return retorno;
}

int CalcularTotal(float* total, Passenger* list, int lenPass)
{
	int retorno;
	float acumulador;
	acumulador = 0;
	retorno = -1;
	if(list != NULL && lenPass > 0)
	{
		for(int i=0; i<lenPass; i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumulador = acumulador + list[i].price;
			}
		}
		*total = acumulador;
		retorno = 0;
	}

	return retorno;
}

int ContarPasajeros(int* cantidad, Passenger* list, int lenPass)
{
	int retorno;
	int contador;
	contador = 0;
	retorno = -1;
	if(list != NULL && lenPass > 0)
	{
		for(int i=0; i<lenPass; i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
			}
		}
		*cantidad = contador;
		retorno = 0;
	}

	return retorno;
}

