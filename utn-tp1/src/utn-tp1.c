/*
 ============================================================================
 Name        : utn-tp1.c
 Author      :  Lucas Barbosa
 Version     :
 Description : Trabajo pr�ctico n�1 UTNFRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main() {
	setbuf(stdout, NULL);
	long option;
	long a;
	long b;
	int contadorA = 0;
	int contadorB = 0;
	long laSumaEs;
	long laRestaEs;
	float laDivisionEs;
	int division;
	long elProductoEs;
	double elFactorialA;
	double elFactorialB;
	do{
		get_Number(&option,"\n�Qu� desea ahacer?\nIngrese una opcion: \n1. Ingrese n�mero A\n2. Ingrese n�mero B\n3. Calcular todas las operaciones\n4. Resultados\n5. Salir\n","ERROR, opcion invalida\n",1,5,3);
		switch(option)
		{
			case 1:
				if(get_Number(&a,"A =\n","N�mero invalido\n",MIN,MAX,2))
				{
					contadorA++;
				}
				break;
			case 2:
				if(get_Number(&b,"B =\n","N�mero invalido\n",MIN,MAX,2))
				{
					contadorB++;
				}
				break;
			case 3:
				if(contadorA>0 && contadorB>0)
				{
					Sumar(a,b,&laSumaEs);
					Restar(a,b,&laRestaEs);
					division = Dividir(a,b,&laDivisionEs);
					Multiplicar(a,b,&elProductoEs);
					Factorial(a,&elFactorialA);
					Factorial(b,&elFactorialB);
				}
				else
				{
					printf("Valores no cargados");
				}
				break;
			case 4:
				if(contadorA>0 && contadorB>0)
				{
					printf("\nLa suma de A y B es: %ld",laSumaEs);
					printf("\nLa resta entre A y B es: %ld",laRestaEs);
					if(!division){
						printf("\nERROR, no se puede dividir por cero !!!");
					}else{
						printf("\nLa division de A por B es: %.2f",laDivisionEs);
					}
					printf("\nEl producto de A con B es: %ld",elProductoEs);
					printf("\nEl factorial de A es: %.02f ",elFactorialA);
					printf("\nEl factorial de B es: %.02f \n",elFactorialB);
				}
				else
				{
					printf("Valores no cargados");
				}

				break;
			case 5:
				break;
			}
		if(contadorA >0 && contadorB >0 )
		{
			printf("A = %ld   B = %ld",a,b);
		}
		}while(option!=5);


	return 0;
}
