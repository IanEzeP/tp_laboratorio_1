/*
 * OperacionesFunciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesFunciones.h"

int PedirNumero(char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior)
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);
    while(numeroIngresado < limiteInferior || numeroIngresado > limiteSuperior)
    {
    	printf("%s", mensajeError);
        scanf("%d", &numeroIngresado);
    }

    return numeroIngresado;
}

float CalcularPrecioTarjetaDebito(int descuento, int precio)
{
	float rebaja;

	float precioFinal;

	rebaja = (float)(precio * descuento) /100;
	precioFinal = precio - rebaja;

	return precioFinal;
}

float CalcularPrecioTarjetaCredito(int interes, int precio)
{
	float recarga;
	float precioFinal;

	recarga = (float)(precio * interes) /100;
	precioFinal = precio + recarga;

	return precioFinal;
}

float CalcularPrecioBitcoin(float cotizacion, int precio)
{
	float valorEnBTC;

	valorEnBTC = (float)precio / cotizacion;

	return valorEnBTC;
}

float CalcularPrecioPorKM(int kilometros, int precio)
{
	float precioUnitario;

	precioUnitario = (float)precio / kilometros;

	return precioUnitario;
}

int CalcularDiferenciaAerolineasLatam(int precioAerolineas, int precioLatam)
{
	int diferenciaPrecios;

	diferenciaPrecios = precioAerolineas - precioLatam;

	if(diferenciaPrecios < 0)
	{
		diferenciaPrecios = diferenciaPrecios * -1;
	}
	return diferenciaPrecios;
}
