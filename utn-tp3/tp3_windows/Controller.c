#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

static int submenuOrder();
static int submenuSort();

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	FILE* file;
	if (path != NULL && pArrayListEmployee != NULL) {
		file = parser_openFileFromText(path);
		if(file != NULL){
			if(parser_EmployeeFromText(file,pArrayListEmployee)){
				printf("Se cargo correctamente la lista [MODO TEXTO]");
				fclose(file);
			}
		}
	}
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	FILE* file;
	if(path != NULL && pArrayListEmployee!= NULL){
		file = parser_openFileFromBinary(path);
		if(file != NULL){
			if(parser_EmployeeFromBinary(file,pArrayListEmployee)){
				printf("Se cargo correctamente la lista [MODO BINARIO]");
				fclose(file);
			}
		}
	}

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	char bufferNombre[20];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	int bufferId;
	Employee* newEmployee;

	if(pArrayListEmployee != NULL){
		if(employee_dataRegistration(bufferNombre,&bufferHorasTrabajadas,&bufferSueldo)==-1){
			printf("No se pudo realizar la carga de los datos");
			ret = -1;
		}
		else{
			bufferId = ll_len(pArrayListEmployee);
			bufferId++;
			newEmployee = employee_newAlta(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
			if(newEmployee != NULL){
				ll_add(pArrayListEmployee,(Employee*)newEmployee);
				printEmployee(newEmployee);

				ret = 1;
			}

		}

	}

    return ret;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int lenLL;
	int indexModify;
	int set;
	Employee* auxEmp = employee_new();
	lenLL = ll_len(pArrayListEmployee);
	if (getIndexFromId(&indexModify, lenLL)){
		auxEmp = ll_get(pArrayListEmployee, indexModify);
		printEmployee(auxEmp);
		if(employee_modify(auxEmp)){
			set = ll_set(pArrayListEmployee,indexModify,auxEmp);
			printEmployee(auxEmp);
			if(set==0){
				ret = 1;
			}

		}
	}

    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int ret = -1;
	int lenLL;
	int indexDelete;
	char respuesta[10];
	Employee *auxEmp = employee_new();
	lenLL = ll_len(pArrayListEmployee);
	if (getIndexFromId(&indexDelete, lenLL)) {
		auxEmp = ll_get(pArrayListEmployee, indexDelete);
		if (auxEmp != NULL) {
			printEmployee(auxEmp);
			getString(respuesta, "Confirma darlo de BAJA?\n [SI/NO]\n",
					"Opcion incorrecta\n", 10, 2);
			strupr(respuesta);
			if (strcmp(respuesta, "SI") == 0) {
				ll_remove(pArrayListEmployee, indexDelete);
				employee_delete(auxEmp);
				printf("BAJA hecha\n");
				ret = 0;
			} else if (strcmp(respuesta, "NO") == 0) {
				printf("BAJA anulada\n");
			}

			ret = 1;
		}
	}



	return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int i;
	int lenLL;
	Employee* auxEmp = employee_new();
	lenLL = ll_len(pArrayListEmployee);

	for(i=0;i<lenLL;i++){
		auxEmp = ll_get(pArrayListEmployee,i);
		if(auxEmp != NULL){
			printEmployee(auxEmp);
			ret = 1;
		}
	}

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int ret = -1;
	int option;
	int optionSort;
	do {
		option = submenuSort();
		switch (option) {
		case 1:
			optionSort = submenuOrder();
			if ((ll_sort(pArrayListEmployee, sortEmployeeBySalary,
					optionSort))) {
				ret = 1;
			}
				controller_ListEmployee(pArrayListEmployee);
			break;
		case 2:
			optionSort = submenuOrder();
			if ((ll_sort(pArrayListEmployee, sortEmployeeByWorkedHours,
					optionSort))) {
				ret = 1;
			}
				controller_ListEmployee(pArrayListEmployee);
			break;
		case 3:
			optionSort = submenuOrder();

			if ((ll_sort(pArrayListEmployee, sortEmployeeById, optionSort))) {
				ret = 1;
			}
				controller_ListEmployee(pArrayListEmployee);
			break;
		case 4:
			break;
		}
	} while (option != 4);

	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


/*
 *
 *
 *
 */
static int submenuSort()
{
	int option;
    printf("1. Por sueldo\n");
    printf("2. Por horas trabajadas\n");
    printf("3. Por Id\n");
    printf("4. Volver\n");

	getNumber(&option,"¿Por cuál criterio desea ordenar? ","ERROR, opcion incorrecta",1,4,2);
	return option;
}
/*
 *
 *
 *
 */
static int submenuOrder()
{
	int option;
    printf("1. Ascendente\n");
    printf("2. Descendente\n");
    printf("3. Volver\n");

	getNumber(&option,"¿Cómo lo desea desea ordenar? ","ERROR, opcion incorrecta",1,3,2);
	switch(option){
	case 1:
		option = 0;
		break;
	case 2:
		option = 1;
		break;
	}
	return option;
}
