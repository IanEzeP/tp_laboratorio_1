/*
 * InputsDatos.c
 *
 *  Created on: 25 abr. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InputsDatos.h"

static int getInt(int* pResultado);
static int isNumber(char* cadena, int limite);
static int getFloat(float* pResultado);
static int isFloat(char* cadena, float limite);

static int getFloat(float* pResultado)
{
	int retorno;
	char bufferString[50];
	retorno = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isFloat(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}

static int isFloat(char* cadena, float limite)
{
	int retorno;
	int banderaPunto;
	banderaPunto = 0;
	retorno = -1;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i=0; i<limite && cadena[i] !='\0'; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && banderaPunto == 0)
				{
					banderaPunto = 1;
					continue;
				}
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno;
	char bufferString[50];
	retorno = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isNumber(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

static int isNumber(char* cadena, int limite)
{
	int retorno;
	retorno = -1;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i=0; i<limite && cadena[i] !='\0'; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int myGetString(char* cadena, int lenght)
{
	int retorno;
	char bufferString[4096];
	retorno = -1;
	if(cadena != NULL && lenght > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL && bufferString[0] != '\n')
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= lenght)
			{
				strncpy(cadena, bufferString, lenght);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorno;
	int bufferInt;
	retorno = -1;
	printf("%s\n", mensaje);
	while(retorno != 0)
	{
		if(getInt(&bufferInt) == 0 && bufferInt > minimo && bufferInt < maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorno;
}

int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retorno;
	float bufferFloat;
	retorno = -1;
	printf("%s\n", mensaje);
	while(retorno != 0)
	{
		if(getFloat(&bufferFloat) == 0 && bufferFloat > minimo && bufferFloat < maximo)
		{
			retorno = 0;
			*pResultado = bufferFloat;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorno;
}

char PedirCaracter(char mensaje[])
{
	char caracter;
	printf("%s\n", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* cadena, int lenght)
{
	int retorno;
	char bufferString[lenght];
	retorno = -1;
	printf("%s\n", mensaje);
	while(retorno != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarStringAlfaNumerico(bufferString) == 0)
		{
			retorno = 0;
			strncpy(cadena, bufferString, lenght);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorno;
}

int PedirString(char* mensaje, char* mensajeError, char* cadena, int lenght)
{
	int retorno;
	char bufferString[lenght];
	retorno = -1;
	printf("%s\n", mensaje);
	while(retorno != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarString(bufferString) == 0)
		{
			retorno = 0;
			strncpy(cadena, bufferString, lenght);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorno;
}

int ValidarString(char* string)
{
	int retorno;
	retorno = 0;
	for(int i=0;i<strlen(string);i++)
	{
		if(!isalpha(string[i]))
		{
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int ValidarStringAlfaNumerico(char* string)
{
	int retorno;
	int banderaAlpha;
	int banderaNum;
	banderaAlpha = 0;
	banderaNum = 0;
	retorno = 0;

	for(int i=0;i<strlen(string);i++)
	{
		if(isalpha(string[i]))
		{
			banderaAlpha = 1;
		}
		else
		{
			if(isdigit(string[i]))
			{
				banderaNum = 1;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	if(banderaAlpha == 0 || banderaNum == 0)
	{
		retorno = -1;
	}
	return retorno;
}
/*
int ValidarRangoEntero(char mensajeError[], int limiteInferior, int limiteSuperior, int numero)
{
	while(numero < limiteInferior || numero > limiteSuperior)
	{
		printf("%s\n", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}

int ValidarRangoInversoEntero(char mensajeError[], int limiteInferior, int limiteSuperior, int numero)
{
	while(numero > limiteInferior && numero < limiteSuperior)
	{
		printf("%s\n", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}

float ValidarRangoFlotante(char mensajeError[], float limiteInferior, float limiteSuperior, float numero)
{
	while(numero < limiteInferior || numero > limiteSuperior)
	{
		printf("%s\n", mensajeError);
		scanf("%f", &numero);
	}
	return numero;
}

float ValidarRangoInversoFlotante(char mensajeError[], float limiteInferior, float limiteSuperior, float numero)
{
	while(numero > limiteInferior && numero < limiteSuperior)
	{
		printf("%s\n", mensajeError);
		scanf("%f", &numero);
	}
	return numero;
}*/

char ValidarCaracter(char mensajeError[], char limiteInferior, char limiteSuperior, char caracter)
{
	while(caracter > limiteInferior && caracter < limiteSuperior)
	{
		printf("%s\n", mensajeError);
		fflush(stdin);
		scanf("%c", &caracter);
	}
	return caracter;
}

void FormatearNombreCompleto(char cadena[])
{
	int size;
	int i;

	size = strlen(cadena);
	strlwr(cadena);

	for(i=0; i<size; i++)
	{
		if(cadena[i-1] == 32 || i==0)
		{
			cadena[i] = toupper(cadena[i]);
		}
	}

}

int ConfirmarCambios()
{
	int cambioRealizado;
	char confirmar[3];

	cambioRealizado = 0;
	PedirString(" (SI o NO)", "ERROR! Intentelo de nuevo (SI o NO)", confirmar, 3);
	strupr(confirmar);
	while(strcmp(confirmar, "SI") != 0 && strcmp(confirmar, "NO") != 0)
	{
		PedirString("ERROR! Intentelo de nuevo (SI o NO)", "ERROR! Intentelo de nuevo (SI o NO)", confirmar, 3);
		strupr(confirmar);
	}
	if(strcmp(confirmar, "SI") == 0)
	{
		cambioRealizado = 1;
	}

	return cambioRealizado;
}

//Esta funcion se puede modificar segun lo necesite el enunciado, agregando mas caracteres esperados.
/*
char ValidarDistintosCaracteres(char mensajeError[], char charEsperado1, char charEsperado2, char caracterIngresado)
{
	while(caracterIngresado != charEsperado1 && caracterIngresado != charEsperado2)
	{
		printf("%s\n", mensajeError);
		fflush(stdin);
		scanf("%c", caracterIngresado);
	}
	return caracterIngresado;
}*/
