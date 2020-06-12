#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


/*
 *
 *
 *
 */
Employee* employee_new(){
	Employee* this = (Employee*) malloc(sizeof(Employee));
	if(this != NULL)
	{

		employee_setNombre(this,"");
		employee_setHorasTrabajadas(this,0);
		employee_setSueldo(this,0);
	}
	else
	{
		printf("No hay espacio en la memoria");
	}
	return this;
}

/*
 *
 *
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* newEmployee = employee_new();
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
		employee_setId(newEmployee,atoi(idStr));
		employee_setNombre(newEmployee,nombreStr);
		employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr));
		employee_setSueldo(newEmployee,atoi(sueldoStr));
	}

	return newEmployee;
}
/*
 *
 *
 *
 */
Employee* employee_newAlta(int id,char* nombre, int horasTrabajadas, int sueldo){
	Employee* newEmployee = employee_new();
	if(id >=0 && nombre != NULL && horasTrabajadas > 0 && sueldo > 0){
		employee_setId(newEmployee,id);
		employee_setNombre(newEmployee,nombre);
		employee_setHorasTrabajadas(newEmployee,horasTrabajadas);
		employee_setSueldo(newEmployee,sueldo);
	}
	return newEmployee;
}
/*
 *
 *
 *
 */
int employee_dataRegistration(char* pNombre,int* pHorasTrabajadas,int* pSueldo){
	int ret = -1;
	char bufferNombre[20];
	int bufferHorasTrabajadas;
	int bufferSueldo;
		if(pNombre != NULL && pHorasTrabajadas != NULL && pSueldo != NULL){
			if(getNameEmployee(bufferNombre)&&
			getHorasTrabajadasEmployee(&bufferHorasTrabajadas)&&
			getSueldoEmployee(&bufferSueldo)){
				strcpy(pNombre,bufferNombre);
				*pHorasTrabajadas = bufferHorasTrabajadas;
				*pSueldo = bufferSueldo;
				ret = 1;
			}
		}

	return ret;
}
/*
 *
 *
 *
 */
int employee_modify(Employee* this){
	int ret = -1;
	char bufferName[20];
	int bufferHoras;
	int bufferSueldo;
	int option;
	char answer[10];
	do{
		option = submenuModidy();
		switch(option){
		case 1:
			getNameEmployee(bufferName);
			getString(answer, "Confirma la MODIFICACION?\n [SI/NO]\n",
					"Opcion incorrecta\n", 10, 2);
			strupr(answer);
			if (strcmp(answer, "SI") == 0) {
				employee_setNombre(this,bufferName);
				printf("MODIFICACION hecha\n");
				ret = 1;
			} else if (strcmp(answer, "NO") == 0) {
				printf("MODIFICACION anulada\n");
			}
			break;
		case 2:
			getHorasTrabajadasEmployee(&bufferHoras);
			getString(answer, "Confirma la MODIFICACION?\n [SI/NO]\n",
					"Opcion incorrecta\n", 10, 2);
			strupr(answer);
			if (strcmp(answer, "SI") == 0) {
				employee_setHorasTrabajadas(this,bufferHoras);
				printf("MODIFICACION hecha\n");
				ret = 1;
			} else if (strcmp(answer, "NO") == 0) {
				printf("MODIFICACION anulada\n");
			}
			break;
		case 3:
			getSueldoEmployee(&bufferSueldo);
			getString(answer, "Confirma la MODIFICACION?\n [SI/NO]\n",
					"Opcion incorrecta\n", 10, 2);
			strupr(answer);
			if (strcmp(answer, "SI") == 0) {
				employee_setSueldo(this,bufferSueldo);
				printf("MODIFICACION hecha\n");
				ret = 1;
			} else if (strcmp(answer, "NO") == 0) {
				printf("MODIFICACION anulada\n");
			}
			break;
		case 4:
			break;
		}
	}while(option != 4);



	return ret;
}
/*
 *
 *
 *
 */
int submenuModidy()
{
	int option;
    printf("1. Nombre\n");
    printf("2. Horas trabajadas\n");
    printf("3. Sueldo\n");
    printf("4. Volver\n");

	getNumber(&option,"¿Qué desea modificar? ","ERROR, opcion incorrecta",1,4,2);
	return option;
}
/*
 *
 *
 *
 */
int getNameEmployee (char* name){
	int ret = -1;
	char axuName[20];

	if(getString(axuName,"Ingrese el nombre","Error, nombre invalido",20,2)){
		strcpy(name,axuName);
		ret = 1;
	}


	return ret;
}
/*
 *
 *
 *
 */
int getHorasTrabajadasEmployee(int* pHorasTrabajadas){
	int ret = -1;
	int auxHoras;

	if(getNumber(&auxHoras,"Ingrese la horas trabajadas","Error, horas invalidas",1,325,2)){
		*pHorasTrabajadas = auxHoras;
		ret = 1;
	}

	return ret;
}
/*
 *
 *
 *
 */
int getSueldoEmployee(int* pSueldo){
	int ret = -1;
	int auxSueldo;

	if(getNumber(&auxSueldo,"Ingrese el sueldo","Error, horas invalidas",1,65000,2)){
		*pSueldo = auxSueldo;
		ret = 1;
	}

	return ret;
}
/*
 *
 *
 *
 */
int employee_setId(Employee *this, int id) {
	int ret = -1;
	static int maximoId = -1;
	if(this != NULL){
		ret = 0;
		if(id < 0 || id <maximoId){
			maximoId++;
			this->id = maximoId;
			printf("DEBUG 1 [%d]\n",maximoId);
		}else{
			if(id > maximoId){
				maximoId = id;
				printf("DEBUG 2 [%d]\n",maximoId);
			}
				this->id = id;
		}
	}
return ret;
}
/*
 *
 *
 *
 */
int employee_getId(Employee* this,int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		ret = 1;
	}
	return ret;
}

/*
 *
 *
 *
 */
int employee_setNombre(Employee* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		ret = 1;
	}
	return ret;
}
/*
 *
 *
 *
 */
int employee_getNombre(Employee* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		ret = 1;
	}

	return ret;
}
/*
*
*
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int ret = -1;
	if(this != NULL && horasTrabajadas >0){
		this->horasTrabajadas = horasTrabajadas;
		ret = 1;
	}
	return ret;
}
/*
 *
 *
 *
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int ret = -1;
	if(this != NULL && horasTrabajadas!= NULL){
		*horasTrabajadas = this->horasTrabajadas;
		ret = 1;
	}
	return ret;
}
/*
 *
 *
 *
 */
int employee_setSueldo(Employee* this,int sueldo){
	int ret = -1;
	if(this != NULL && sueldo >0){
		this->sueldo = sueldo;
		ret = 1;
	}
	return ret;
}
/*
 *
 *
 *
 */
int employee_getSueldo(Employee* this,int* sueldo){
	int ret = -1;
	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		ret = 1;
	}
	return ret;
}
int printEmployee(Employee *this){
	int ret = -1;
	if(this != NULL){
		printf("%6d %15s %6d %6d\n",this->id,this->nombre,
				this->horasTrabajadas,this->sueldo);
		ret =1;
	}

	return ret;
}
int getIndexFromId(int *pIndex, int lenLL) {
	int ret = -1;
	int bufferId;
	if (pIndex != NULL && lenLL > 0) {
		if (getNumber(&bufferId,
				"Ingrese el ID del empleado que desea dar de baja",
				"Error ID invalido", 1, lenLL, 2)) {
			*pIndex = bufferId-1;
			ret = 1;
		}
	}

	return ret;
}
/*
 *
 *
 *
 */
int sortEmployeeBySalary(void* employee1, void* employee2){
	int ret = 0;
	int bufferSueldo1;
	int bufferSueldo2;

	employee_getSueldo(employee1,&bufferSueldo1);
	employee_getSueldo(employee2,&bufferSueldo2);

	if(employee1  != NULL && employee2 != NULL){
		if(bufferSueldo1 > bufferSueldo2){
			ret = 1;
		}else if(bufferSueldo2 > bufferSueldo1){
			ret = -1;
		}else if(bufferSueldo1 == bufferSueldo2){
			ret = 0;
		}
	}

	return ret;
}
/*
 *
 *
 *
 */
int sortEmployeeByWorkedHours(void* employee1, void* employee2){
	int ret = 0;
	int bufferHoras1;
	int bufferHoras2;

	employee_getHorasTrabajadas(employee1,&bufferHoras1);
	employee_getHorasTrabajadas(employee2,&bufferHoras2);
	if(employee1  != NULL && employee2 != NULL){
		if(bufferHoras1 > bufferHoras2){
			ret = 1;
		}else if(bufferHoras2 > bufferHoras1){
			ret = -1;
		}else if(bufferHoras2 == bufferHoras1){
			ret = 0;
		}

	}

	return ret;
}
/*
 *
 *
 *
 */
int sortEmployeeById(void* employee1, void* employee2){
	int ret = 0;
	int id1;
	int id2;
	employee_getId(employee1,&id1);
	employee_getId(employee2,&id2);
	if(employee1  != NULL && employee2 != NULL){
		if(id1 > id2){
			ret = 1;
		}
		else if(id2 > id1){
			ret = -1;
		}
	}

	return ret;
}
/*
 *
 *
 *
 */
int employee_delete(Employee* this){
	int ret = -1;
	if(this != NULL){
		free(this);
		ret = 1;
	}
	return ret;
}
