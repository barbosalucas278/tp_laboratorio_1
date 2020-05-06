/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
#include "utn.h"
#include "ArrayEmployees.h"
#define CANT_EMP 1000

int main() {
	setbuf(stdout, NULL);
	int optionMenu;
	eEmployee employees[CANT_EMP];
	int id = 0;

	initEmployees(employees,CANT_EMP);

	do
	{
		system("CLS");
		optionMenu = menu();
		switch(optionMenu)
		{
		case 1:
			addDataEmployees(employees,CANT_EMP,&id);
			break;
		case 2:
			if(id>0){
			modifyEmployee(employees,CANT_EMP);
			}
			else{
			printf("Primero debe dar de alta un empleado\n");
			}
			break;
		case 3:
			if(id>0){
			removeEmployee(employees,CANT_EMP,getId(employees,CANT_EMP));
			}else{
				printf("Primero debe dar de alta un empleado\n");
			}
			break;
		case 4:
			if(id>0){
			menuSort(employees,CANT_EMP,id);
			}
			else{
				printf("primero tiene que agregar de un empleado\n");
			}
			break;
		case 5:
			break;
		}

	}while(optionMenu!=5);


	return 0;
}
