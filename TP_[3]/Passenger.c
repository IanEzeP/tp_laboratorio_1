/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "InputsDatos.h"

#define ECONOMY_CLASS "1"
#define EXECUTIVE_CLASS "2"
#define FIRST_CLASS "3"

#define ATERRIZADO_STATUS "1"
#define DEMORADO_STATUS "2"
#define EN_HORARIO_STATUS "3"
#define EN_VUELO_STATUS "4"


Passenger* Passenger_new()
{
	Passenger* auxPasajero = NULL;
	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	return auxPasajero;
}

Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr)
{
	Passenger* pPasajero = NULL;
	int idAuxiliar;
	float precioAuxiliar;
	int tipoPasajeroAuxiliar;
	int estadoAuxiliar;
	int bandera = 0;
	pPasajero = Passenger_new();
	if(pPasajero != NULL)
	{
		if(Passenger_changeEstadoVueloToInt(estadoStr)==1 &&
		   Passenger_changeTipoPasajeroToInt(tipoPasajeroStr)==1 &&
		   isNumber(idStr, sizeof(idStr))==1 &&
		   isNumber(tipoPasajeroStr, sizeof(tipoPasajeroStr))==1 &&
		   isNumber(estadoStr, sizeof(estadoStr))==1 &&
		   isFloat(precioStr, sizeof(precioStr))==1)
		{
			idAuxiliar = atoi(idStr);
			tipoPasajeroAuxiliar = atoi(tipoPasajeroStr);
			estadoAuxiliar = atoi(estadoStr);
			precioAuxiliar = atof(precioStr);

			if(Passenger_setId(pPasajero, idAuxiliar)==0 &&
			   Passenger_setNombre(pPasajero, nombreStr)==0 &&
			   Passenger_setApellido(pPasajero, apellidoStr)==0 &&
			   Passenger_setPrecio(pPasajero, precioAuxiliar)==0 &&
			   Passenger_setCodigoVuelo(pPasajero, codigoStr)==0 &&
			   Passenger_setTipoPasajero(pPasajero, tipoPasajeroAuxiliar)==0 &&
			   Passenger_setEstado(pPasajero, estadoAuxiliar)==0)
			{
				bandera = 1;
			}
		}
	}
	if(bandera == 0)
	{
		Passenger_delete(pPasajero);
		pPasajero = NULL;
	}

	return pPasajero;
}

Passenger* Passenger_newParametrosBin(int id, char* nombre, char* apellido, float precio, char* codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	Passenger* pPasajero = NULL;

	pPasajero = Passenger_new();

	if(pPasajero != NULL)
	{
		if(Passenger_setId(pPasajero, id)!=0 ||
		   Passenger_setNombre(pPasajero, nombre)!=0 ||
		   Passenger_setApellido(pPasajero, apellido)!=0 ||
		   Passenger_setPrecio(pPasajero, precio)!=0 ||
		   Passenger_setCodigoVuelo(pPasajero, codigoVuelo)!=0 ||
		   Passenger_setTipoPasajero(pPasajero, tipoPasajero)!=0 ||
		   Passenger_setEstado(pPasajero, estadoVuelo)!=0)
		{
			Passenger_delete(pPasajero);
			pPasajero = NULL;
		}
	}

	return pPasajero;
}

Passenger* Passenger_requestData()
{
	Passenger* unPasajero;
	int id;
	char* nombre;
	char* apellido;
	float precio;
	char* codigoVuelo;
	int tipoPasajero;
	int estadoVuelo;
}
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_compareByID(void* p1, void* p2)
{
	int id1;
	int id2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getId(pasajero1, &id1);
	Passenger_getId(pasajero2, &id2);

	if(id1 > id2)
	{
		compare = 1;
	}
	else
	{
		if(id1 < id2)
		{
			compare = -1;
		}
	}

	return compare;
}

int Passenger_compareByName(void* p1, void* p2)
{
	int comparacion;
	char nombre1[50];
	char nombre2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getNombre(pasajero1, nombre1);
	Passenger_getNombre(pasajero2, nombre2);

	comparacion = strcmp(nombre1, nombre2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByLastName(void* p1, void* p2)
{
	int comparacion;
	char apellido1[50];
	char apellido2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getApellido(pasajero1, apellido1);
	Passenger_getApellido(pasajero2, apellido2);

	comparacion = strcmp(apellido1, apellido2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByPrice(void* p1, void* p2)
{
	float price1;
	float price2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getPrecio(pasajero1, &price1);
	Passenger_getPrecio(pasajero2, &price2);

	if(price1 > price2)
	{
		compare = 1;
	}
	else
	{
		if(price1 < price2)
		{
			compare = -1;
		}
	}

	return compare;
}

int Passenger_compareByFlyCode(void* p1, void* p2)
{
	int comparacion;
	char codigoVuelo1[50];
	char codigoVuelo2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getCodigoVuelo(pasajero1, codigoVuelo1);
	Passenger_getCodigoVuelo(pasajero2, codigoVuelo2);

	comparacion = strcmp(codigoVuelo1, codigoVuelo2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByTypePassenger(void* p1, void* p2)
{
	int tipoPasajero1;
	int tipoPasajero2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getTipoPasajero(pasajero1, &tipoPasajero1);
	Passenger_getTipoPasajero(pasajero2, &tipoPasajero2);

	if(tipoPasajero1 > tipoPasajero2)
	{
		compare = 1;
	}
	else
	{
		if(tipoPasajero1 < tipoPasajero2)
		{
			compare = -1;
		}
	}

	return compare;
}
int Passenger_compareByStatusFlight(void* p1, void* p2)
{
	int estadoVuelo1;
	int estadoVuelo2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getEstado(pasajero1, &estadoVuelo1);
	Passenger_getEstado(pasajero2, &estadoVuelo2);

	if(estadoVuelo1 > estadoVuelo2)
	{
		compare = 1;
	}
	else
	{
		if(estadoVuelo1 < estadoVuelo2)
		{
			compare = -1;
		}
	}

	return compare;
}

void Passenger_listOne(Passenger* this)
{
	char tipoPasajeroAuxiliar[50];
	char estadoVueloAuxiliar[50];
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

	if(Passenger_getId(this, &id)==0 &&
	   Passenger_getNombre(this, nombre)==0 &&
	   Passenger_getApellido(this, apellido)==0 &&
	   Passenger_getPrecio(this, &precio)==0 &&
	   Passenger_getCodigoVuelo(this, codigoVuelo)==0 &&
	   Passenger_getTipoPasajero(this, &tipoPasajero)==0 &&
	   Passenger_getEstado(this, &estadoVuelo)==0 &&
	   Passenger_showTipoPasajero(tipoPasajeroAuxiliar, tipoPasajero)==1 &&
	   Passenger_showEstadoVuelo(estadoVueloAuxiliar, estadoVuelo)==1)
	{
		printf("||%8d||%16s||%16s||%16.2f||%15s||%16s||%16s||\n",
				id,
				nombre,
				apellido,
				precio,
				codigoVuelo,
				tipoPasajeroAuxiliar,
				estadoVueloAuxiliar);
	}
	else
	{
		printf("No se pudo mostrar al pasajero.\n");
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre, nombre);
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre, this->nombre);
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(this->apellido, apellido);
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(apellido, this->apellido);
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(this->codigoVuelo, codigoVuelo);
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(codigoVuelo, this->codigoVuelo);
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}


int Passenger_setEstado(Passenger* this,int estado)
{
	int retorno = -1;

	if(this != NULL && estado > 0)
	{
		retorno = 0;
		this->estadoVuelo = estado;
	}
	return retorno;
}

int Passenger_getEstado(Passenger* this,int* estado)
{
	int retorno = -1;

	if(this != NULL && estado != NULL)
	{
		retorno = 0;
		*estado = this->estadoVuelo;
	}
	return retorno;
}

int Passenger_changeTipoPasajeroToInt(char* tipoPasajero)
{
	int retorno = -1;
	if(tipoPasajero != NULL)
	{
		retorno = 0;
		if(strcmp(tipoPasajero, "FirstClass")==0)
		{
			strcpy(tipoPasajero, FIRST_CLASS);
			retorno = 1;
		}
		else
		{
			if(strcmp(tipoPasajero, "ExecutiveClass")==0)
			{
				strcpy(tipoPasajero, EXECUTIVE_CLASS);
				retorno = 1;
			}
			else
			{
				strcpy(tipoPasajero, ECONOMY_CLASS);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_showTipoPasajero(char* tipoPasajero, int numberTipoPasajero)
{
	int retorno = -1;
	if(tipoPasajero != NULL && numberTipoPasajero > 0)
	{
		retorno = 0;
		switch(numberTipoPasajero)
		{
			case 1:
				strcpy(tipoPasajero, "EconomyClass");
				retorno = 1;
				break;
			case 2:
				strcpy(tipoPasajero, "ExecutiveClass");
				retorno = 1;
				break;
			case 3:
				strcpy(tipoPasajero, "FirstClass");
				retorno = 1;
				break;
		}
	}
	return retorno;
}

int Passenger_changeEstadoVueloToInt(char* estadoVuelo)
{
	int retorno = -1;
	if(estadoVuelo != NULL)
	{
		retorno = 0;
		if(strcmp(estadoVuelo, "Aterrizado")==0)
		{
			strcpy(estadoVuelo, ATERRIZADO_STATUS);
			retorno = 1;
		}
		else
		{
			if(strcmp(estadoVuelo, "En Horario")==0)
			{
				strcpy(estadoVuelo, EN_HORARIO_STATUS);
				retorno = 1;
			}
			else
			{
				if(strcmp(estadoVuelo, "En Vuelo")==0)
				{
					strcpy(estadoVuelo, EN_VUELO_STATUS);
					retorno = 1;
				}
				else
				{
					strcpy(estadoVuelo, DEMORADO_STATUS);
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int Passenger_showEstadoVuelo(char* estadoVuelo, int numberEstadoVuelo)
{
	int retorno = -1;
	if(estadoVuelo != NULL && numberEstadoVuelo > 0)
	{
		retorno = 0;
		switch(numberEstadoVuelo)
		{
			case 1:
				strcpy(estadoVuelo, "Aterrizado");
				retorno = 1;
				break;
			case 2:
				strcpy(estadoVuelo, "Demorado");
				retorno = 1;
				break;
			case 3:
				strcpy(estadoVuelo, "En Horario");
				retorno = 1;
				break;
			case 4:
				strcpy(estadoVuelo, "En Vuelo");
				retorno = 1;
				break;
		}
	}
	return retorno;
}
