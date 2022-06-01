/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "InputsDatos.h"

#define FIRST_CLASS "1"
#define EXECUTIVE_CLASS "2"
#define ECONOMY_CLASS "3"

#define ATERRIZADO_STATUS "1"
#define EN_HORARIO_STATUS "2"
#define EN_VUELO_STATUS "3"
#define DEMORADO_STATUS "4"


Passenger* Passenger_new()
{
	Passenger* auxPasajero = NULL;
	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	return auxPasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr)
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
		if(Passenger_changeEstadoVueloToInt(estadoStr)==1 && Passenger_changeTipoPasajeroToInt(tipoPasajeroStr)==1)
		{
			if(isNumber(idStr, sizeof(idStr))==1)
			{
				idAuxiliar = atoi(idStr);
				if(Passenger_setId(pPasajero, idAuxiliar)==0)
				{
					if(Passenger_setNombre(pPasajero, nombreStr)==0)
					{
						if(Passenger_setApellido(pPasajero, apellidoStr)==0)
						{
							if(isFloat(precioStr, sizeof(precioStr))==1)
							{
								precioAuxiliar = atof(precioStr);
								if(Passenger_setPrecio(pPasajero, precioAuxiliar)==0)
								{
									if(Passenger_setCodigoVuelo(pPasajero, codigoStr)==0)
									{
										if(isNumber(tipoPasajeroStr, sizeof(tipoPasajeroStr))==1)
										{
											tipoPasajeroAuxiliar = atoi(tipoPasajeroStr);
											if(Passenger_setTipoPasajero(pPasajero, tipoPasajeroAuxiliar)==0)
											{
												if(isNumber(estadoStr, sizeof(estadoStr))==1)
												{
													estadoAuxiliar = atoi(estadoStr);
													if(Passenger_setEstado(pPasajero, estadoAuxiliar)==0)
													{
														bandera = 1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(bandera == 0)
		{
			Passenger_delete(pPasajero);
			pPasajero = NULL;
		}
	}

	return pPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_compareByName(void* p1, void* p2)
{
	int retorno;
	char* nombre1 = {""};
	char* nombre2 = {""};
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	retorno = Passenger_getNombre(pasajero1, nombre1);
	if(retorno != 0)
	{
		printf("ERROR en getNombre!\n");//borrar? agregar _delete?
	}
	retorno = Passenger_getNombre(pasajero2, nombre2);
	if(retorno != 0)
	{
		printf("ERROR en getNombre!\n");
	}
	return strcmp(nombre1, nombre2);
}

int Passenger_compareByID(void* p1, void* p2)
{
	int retorno;
	int id1;
	int id2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int compare;

	compare = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	retorno = Passenger_getId(pasajero1, &id1);
	if(retorno != 0)
	{
		printf("ERROR en getId!\n");
	}
	retorno = Passenger_getId(pasajero2, &id2);
	if(retorno != 0)
	{
		printf("ERROR en getId!\n");
	}
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
				strcpy(tipoPasajero, "FirstClass");
				retorno = 1;
				break;
			case 2:
				strcpy(tipoPasajero, "ExecutiveClass");
				retorno = 1;
				break;
			case 3:
				strcpy(tipoPasajero, "EconomyClass");
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
				strcpy(estadoVuelo, "En Horario");
				retorno = 1;
				break;
			case 3:
				strcpy(estadoVuelo, "En Vuelo");
				retorno = 1;
				break;
			case 4:
				strcpy(estadoVuelo, "Demorado");
				retorno = 1;
				break;
		}
	}
	return retorno;
}
