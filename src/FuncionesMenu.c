/*
 * FuncionesMenu.c
 *
 *  Created on: 10 abr. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesMenu.h"
#include "OperacionesFunciones.h"

int IngresarKilometros()
{
	int kilometros;

	kilometros = PedirNumero("Ingrese los kilometros del viaje: \n", "Los valores ingresados son invalidos, intente nuevamente ", 1, 999999);

	return kilometros;
}

int IngresarPrecioAerolineas()
{
	int precio;

	precio = PedirNumero("Ingrese el valor del viaje para el servicio de Aerolineas: \n", "Los valores ingresados son invalidos, intente nuevamente ", 1, 99999999);

	return precio;
}

int IngresarPrecioLatam()
{
	int precio;

	precio = PedirNumero("Ingrese el valor del viaje para el servicio de Latam: \n", "Los valores ingresados son invalidos, intente nuevamente ", 1, 99999999);

	return precio;
}

void InformarResultadosAerolineas(int precioAerolineas, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioPorKmAerolineas)
{
	printf("Precio Aerolineas: $%d \n", precioAerolineas);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", precioDebitoAerolineas);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", precioCreditoAerolineas);
	printf("c) Precio pagando con bitcoin: %f BTC\n", precioBitcoinAerolineas);
	printf("d) Precio unitario: $ %.3f\n\n", precioPorKmAerolineas);
}

void InformarResultadosLatam(int precioLatam, float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioPorKmLatam)
{
	printf("Precio Latam: $%d \n", precioLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f\n", precioDebitoLatam);
	printf("b) Precio con tarjeta de credito: $ %.2f\n", precioCreditoLatam);
	printf("c) Precio pagando con bitcoin: %f BTC\n", precioBitcoinLatam);
	printf("d) Precio unitario: $ %.3f\n\n", precioPorKmLatam);
}

int CargarInterfaz(int kilometros, int precioAerolineas, int precioLatam)
{
	int opcion;

	if(kilometros < 1)
	{
		printf("1. Ingresar Kilometros: (km=x)\n");
	}
	else
	{
		printf("1. Ingresar Kilometros: (km=%d)\n", kilometros);
	}
	if(precioAerolineas < 1 && precioLatam < 1)
	{
		printf("2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n");
	}
	else
	{
		printf("2. Ingresar Precio de Vuelos: (Aerolineas=$%d, Latam=$%d)\n", precioAerolineas, precioLatam);
	}
	printf("3. Calcular todos los costos: \n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	scanf("%d", &opcion);

	return opcion;
}
