#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

static int submenuOrder();
static int submenuSort();

/** \brief Loads the employee data from the data.csv file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [path pointer and pArrayListEmployee pointer are NULL]
 * 				(1) is ok
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	FILE* file;
	if (path != NULL && pArrayListEmployee != NULL) {
		system("cls");
		file = openFileFromText(path);
		if(file != NULL){
			if(parser_EmployeeFromText(file,pArrayListEmployee)){
				printf("Se cargo correctamente la lista [MODO TEXTO]\n");
				fclose(file);
				system("pause");
			}
		}
	}
    return ret;
}

/** \brief Loading employee data from the data.csv file (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [path pointer and pArrayListEmployee pointer are NULL]
 * 				(1) is ok
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int ret = -1;
	FILE *file;
	if (pArrayListEmployee != NULL) {
		system("cls");
		file = fopen(path, "rb");
		if (file == NULL) {
			printf("No se pudo abrir el archivo.");
		}
		else {
			if (parser_EmployeeFromBinary(file, pArrayListEmployee)) {
				printf("Se cargo correctamente la lista [MODO BINARIO]");
				fclose(file);
				system("pause");
			}else{
				printf("ERROR");
			}
		}
	}

	return ret;
}

/** \brief Employee registration
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee pointer is NULL or failed to load the data]
 * 				(1) is ok.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	char bufferName[20];
	int bufferHoursWorked;
	int bufferSalary;
	int bufferId;
	Employee* newEmployee = NULL;
	system("cls");
	if(pArrayListEmployee != NULL){
		if(employee_dataRegistration(bufferName,&bufferHoursWorked,&bufferSalary)==-1){
			printf("No se pudo realizar la carga de los datos");
			ret = -1;
		}
		else{
			bufferId = ll_len(pArrayListEmployee);
			newEmployee = employee_newRegistration(bufferId,bufferName,bufferHoursWorked,bufferSalary);
			if(newEmployee != NULL){
				ll_add(pArrayListEmployee,(Employee*)newEmployee);
				printEmployee(newEmployee);
				ret = 1;
			}

		}

	}

    return ret;

}

/** \brief Modify employee data
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee pointer is NULL)
 *				(1) Is ok.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int indexModify;
	int idModify;
	int auxId;
	int set;
	Employee* auxEmp = NULL;
	int lenLL = ll_len(pArrayListEmployee);
	int i;
	system("cls");
	if(pArrayListEmployee != NULL){
		auxEmp = (Employee*)ll_get(pArrayListEmployee,lenLL-1);
		employee_getId(auxEmp,&auxId);
		if(getNumber(&idModify,"Ingrese el ID del empleado que desea modificar",
						"Error ID invalido", 1, auxId, 2)){
			for(i=0;i<lenLL;i++){
				auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(auxEmp,&auxId);
				if(auxId == idModify && auxEmp != NULL){
					indexModify = i;
					printEmployee(auxEmp);
					if(employee_modify(auxEmp)){
						set = ll_set(pArrayListEmployee,indexModify,auxEmp);
						printEmployee(auxEmp);
						if(set==0){
							ret = 1;
						}
					break;
					}
				}
			}
		}
	}

    return ret;
}

/** \brief employee removal
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee pointer is NULL]
 * 				(0) if remove is canceled.
 *				(1) Is ok.
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int ret = -1;
	int lenLL;
	int indexDelete;
	int idDelete;
	int auxId;
	int i;
	Employee *auxEmp = NULL;
	system("cls");
	lenLL = ll_len(pArrayListEmployee);
	if (pArrayListEmployee != NULL) {
		getNumber(&idDelete,"Ingrese el ID del empleado que desea dar de baja",
								"Error ID invalido", 1, lenLL, 2);
		for(i=0;i<lenLL;i++){
			auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(auxEmp,&auxId);
			if(auxId == idDelete && auxEmp != NULL){
				indexDelete = i;
				printEmployee(auxEmp);
				if(questionConfirm("BAJA CONFIRMADA","BAJA CANCELADA")){
								ll_remove(pArrayListEmployee,indexDelete);
								ret = 1;
							}else{
								ret = 0;
							}
				break;
			}
		}

	}
	return ret;
}

/** \brief List employees
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayLisyEmployee pointer is NULL].
 *				(1) Is ok.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int i;
	int lenLL;
	Employee* auxEmp = NULL;
	lenLL = ll_len(pArrayListEmployee);
	system("cls");
	if(pArrayListEmployee != NULL){
		for(i=0;i<lenLL;i++){
			auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmp != NULL){
				printEmployee(auxEmp);
				ret = 1;
			}
		}
	}
	system("pause");
    return ret;
}

/** \brief Sort employees
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee pointer is NULL].
 *				(1) Is ok.
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int ret = -1;
	int option;
	int optionSort;
	system("cls");
	if(pArrayListEmployee != NULL){
		do {
			system("cls");
			option = submenuSort();
			switch (option) {
			case 1:
				system("cls");
				optionSort = submenuOrder();
				if ((ll_sort(pArrayListEmployee, sortEmployeeBySalary,
						optionSort))) {
					option = 4;
					ret = 1;
				}
					controller_ListEmployee(pArrayListEmployee);
				break;
			case 2:
				system("cls");
				optionSort = submenuOrder();
				if ((ll_sort(pArrayListEmployee, sortEmployeeByWorkedHours,
						optionSort))) {
					option = 4;
					ret = 1;
				}
					controller_ListEmployee(pArrayListEmployee);
				break;
			case 3:
				system("cls");
				optionSort = submenuOrder();

				if ((ll_sort(pArrayListEmployee, sortEmployeeById, optionSort))) {
					option = 4;
					ret = 1;
				}
					controller_ListEmployee(pArrayListEmployee);
				break;
			case 4:
				break;
			}
		} while (option != 4);
	}
	system("pause");
	return ret;
}

/** \brief Save employee data in data.csv file (text mode)
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee and path pointers are NULL].
 * 			   (1) Is ok.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	FILE* file;
	int lenLL;
	lenLL = ll_len(pArrayListEmployee);

	if(path != NULL && pArrayListEmployee != NULL && lenLL >0){
		system("cls");
		file = writeFileFromText(path);
		 if(file != NULL){
			 if(saveAsText(file,pArrayListEmployee,lenLL)){
				 printf("Guardado exitoso\n");
				 fclose(file);
				 system("pause");
				 ret = 1;
			 }
		 }
	}else{
		printf("Primero debe agregar empleados a la lista\n");
	}
    return ret;
}

/** \brief Save employee data in data.csv file (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pArrayListEmployee and path pointers are NULL].
 * 			   (1) Is ok.
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int ret = -1;
	FILE *file;
	int lenLL = ll_len(pArrayListEmployee);
	if(path != NULL && pArrayListEmployee != NULL && lenLL >0){
		system("cls");
		file = fopen(path, "wb");
		if (file == NULL) {
			printf("No se pudo abrir el documento para escribirlo\n");
			fclose(file);
		}
		if (file != NULL) {
			if (saveAsBinary(file, pArrayListEmployee, lenLL)) {
				printf("Guardado exitoso\n");
				fclose(file);
				system("pause");
				ret = 1;
			}

		}
	}else{
		printf("Primero debe agregar empleados a la lista\n");
	}
	return ret;
}


/*
 *	\brief submenu for sort employees controller.
 *
 *	\return int option value.
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
 *\brief submenu to choose the sorting criteria
 *
 *\return int option value.
 */
static int submenuOrder()
{
	int option;
    printf("1. Descendente\n");
    printf("2. Ascendente\n");
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
