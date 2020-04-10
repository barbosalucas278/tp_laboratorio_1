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
#include "func.h"

int main() {
	setbuf(stdout, NULL);
	int option;
	int a;
	int b;
	int laSumaEs;
	int laRestaEs;
	float laDivisionEs;
	int elProductoEs;
	double elFactorialA;
	double elFactorialB;
	int flag=-1;

	do{
		switch(flag)
		{
			case -1:
				break;
			case 0:
				printf(" A = %d\n",a);
				printf(" B = %d\n",b);
				break;
			case 1:
				printf(" A = %d\n",a);
				break;
		}

		while(getNumero(&option,"\n�Qu� desea ahacer?\nIngrese una opcion: \n1. Ingrese n�mero A\n2. Ingrese n�mero B\n3. Calcular todas las operaciones\n4. Resultados\n5. Salir\n","ERROR, opcion invalida\n",1,5,3))
		{
			printf("Vuelva a intentarlo nuevamente");
		}

		switch(option){
			case 1:
				getNumero(&a,"A =\n","N�mero invalido\n",-32768,32768,2);
				flag = 1;
				break;
			case 2:
				getNumero(&b,"B =\n","N�mero invalido\n",-32768,32768,2);
				flag=0;
				break;
			case 3:
				laSumaEs = Sumar(a,b);
				laRestaEs = Restar(a,b);
				laDivisionEs = Dividir(a,b);
				elProductoEs = Multiplicar(a,b);
				elFactorialA = Factorial(a);
				elFactorialB = Factorial(b);
				break;
			case 4:
				printf("\nLa suma de A y B es: %d",laSumaEs);
				printf("\nLa resta entre A y B es: %d",laRestaEs);
				if(laDivisionEs==0){
					printf("\nERROR, no se puede dividir por cero !!!");
				}else{
					printf("\nLa division de A por B es: %.2f",laDivisionEs);
				}
				printf("\nEl producto de A con B es: %d",elProductoEs);
				printf("\nEl factorial de A es: %.2f ",elFactorialA);
				printf("\nEl factorial de B es: %.2f \n",elFactorialB);
			break;
			case 5:
				break;
			}
		}while(option!=5);


	return 0;
}