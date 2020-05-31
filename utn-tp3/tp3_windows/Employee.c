#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Employee.h"

Employee* employee_new(){
	Employee* auxEmp = (Employee*) malloc(sizeof(Employee));
	if(auxEmp != NULL)
	{
		auxEmp->sueldo = 0;
		strcpy(auxEmp->nombre,"lucitas");
		auxEmp->horasTrabajadas = 0;
	}
	else
	{
		printf("No hay espacio en la memoria");
	}
	return auxEmp;
}

int printEmployee (Employee* list,int len,int indice){
	int ret = -1;


	return ret;
}
