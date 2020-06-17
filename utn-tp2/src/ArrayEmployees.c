/*
 * employee.c
 *
 *  Created on: 2 may. 2020
 *      Author: Lucas Barbosa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"
#include "utn.h"
#include "ArrayEmployees.h"

#define SALARY_MAX 100000
#define SALARY_MIN 1
#define SECTOR_MAX 10
#define SECTOR_MIN 1
/*
 * \brief to indicate that all position in the array are empty and salary in zero,
 * 		  this function put the flag (isEmpty) in TRUE in all position of the array.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \return int Return (-1) Error [Invalid lenght or NULL pointer] - (0) if Ok
 * */

int initEmployees(eEmployee *list, int len) {
	int i;
	int ret = -1;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 1;
			list[i].salary = 0;
			ret = 0;
		}
	}

	return ret;
}
/*
 * \brief add in a existing list of employees the values recieved as parameters
 * 		  in the first empty position.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary salary float
 * \param sector sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 * */
int addEmployee(eEmployee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int ret = -1;
	int i;
 if(list != NULL && len >0 && name != NULL && lastName != NULL && salary >0 && sector > 0){
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 1) {
			list[i].id = id +1;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			ret = 0;
		}
	}

 }

	return ret;
}
/*
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \param pId int*
 * */
int addDataEmployees(eEmployee *list, int len, int* pId) {
	int ret = -1;
	char bufferName[51];
	char bufferLastName[51];
	float bufferSalary;
	int bufferSector;
	int bufferId;
	eEmployee auxEmployee;

	if(list != NULL && len >0 && *pId >=0){
			system("CLS");
			auxEmployee.isEmpty = 1;
			if (!getString(bufferName, "ingrese el nombre\n",
					"Error, dato ingresado no valido\n", 51, 2)) {
				printf("Vuelva a intentarlo de nuevo\n");
			}
			if (!getString(bufferLastName, "Ingrese el apellido\n",
					"Error, dato ingresado no valido\n", 51, 2)) {
				printf("Vuelva a intentarlo de nuevo\n");
			}
			if(getNumberDecimal(&bufferSalary, "Ingrese el salario\n",
					"Error, dato ingresado no valido\n", SALARY_MIN, SALARY_MAX, 2)== -1) {
				printf("Vuelva a intentarlo de nuevo\n");
			}
			if (!getNumber(&bufferSector, "Ingrese el sector\n",
					"Error, dato ingresado no valido\n", SECTOR_MIN, SECTOR_MAX,2)) {
				printf("Vuelva a intentarlo de nuevo\n");
			}
			if (addEmployee(&auxEmployee, len, *pId, bufferName, bufferLastName,
					bufferSalary, bufferSector) == -1) {
				printf("ERROR");
			}
			list[*pId] = auxEmployee;
			bufferId = *pId;
			bufferId++;
			*pId = bufferId;
			system("PAUSE");
			system("CLS");
	ret = 0;
	}
	return ret;
}

/*
 * \brief find an employeeby ID  and returns the index position in array
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \param id int
 * \return Return (-1) if Error [Invalir lengt or NULL pointer or if can't find a employee] - (0) if Ok
 *
 * */

int findEmployeeById(eEmployee* list, int len, int id) {
	int ret = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0){
		printf("ID		NAME		LASTNAME		SALARY		SECTOR\n\n");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].id == id ) {
				printf("%d		%s		%s			%.2f	%d\n", list[i].id, list[i].name,
						list[i].lastName, list[i].salary, list[i].sector);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}

/*
 * \brief print the content of employees array.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
int printEmployees(eEmployee* list, int len) {
	int ret = -1;
	int i;

	if(list != NULL && len > 0){
		printf("ID		NAME		LASTNAME		SALARY		SECTOR\n\n");
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				printf("%d		%s		%s			%.2f	%d\n", list[i].id, list[i].name,
						list[i].lastName, list[i].salary, list[i].sector);
			}
			ret = 0;
		}
	}

	return ret;
}

/*
 * \brief Remove a employee by ID (put isEmpty Flag in 1)
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \param id int
 * \return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 * */
int removeEmployee(eEmployee *list, int len, int id) {
	int ret = -1;
	char respuesta[10];

	if(list != NULL && len > 0 ){
		system("CLS");
		if (findEmployeeById(list, len, id) == 0) {
			getString(respuesta, "Confirma darlo de BAJA?\n [SI/NO]\n",
					"Opcion incorrecta\n", 10, 2);
			strupr(respuesta);
			if (strcmp(respuesta, "SI") == 0) {
				list[id-1].isEmpty = 1;
				printf("BAJA hecha\n");
				ret = 0;
			} else if (strcmp(respuesta, "NO") == 0) {
				printf("BAJA anulada\n");
			}
		}
		system("PAUSE");
		system("CLS");
	}

	return ret;
}

/*
 * \brief find id with Flag isEmpty = 0;
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \return Return (-1) if Error [Invalid length or NULL pointer or if invalid Id] - (id) if Ok.
 * */
int getId(eEmployee *list, int len) {
	int ret = -1;
	int id;

	if (list != NULL && len > 0) {
		system("CLS");
		if (getNumber(&id, "Ingrese el ID\n", "Error, ID invalido\n", 0, len,
				2)) {
			if (list[id-1].isEmpty == 0) {
				ret = id;
			}
		}
	}

	return ret;
}

/*
 * \brief Search for an employee by Id and give the possibility to modify name, surname, salary or sector.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
*  \return Return (-1) if Error [Invalid length or NULL pointer] - (id) if Ok.
 * */
int modifyEmployee(eEmployee *list, int len) {
	int ret = -1;
	int option;
	char bufferName[51];
	char bufferLastName[51];
	float bufferSalary;
	int bufferSector;
	char respuesta[10];
	int id = getId(list, len);
	int busqueda = findEmployeeById(list, len,id);

	if(list != NULL && len > 0){
		system("CLS");
		if ( busqueda == 0) {
			do{
				findEmployeeById(list,len,id);
				getNumber(&option,
						"Que quiere modificar? \n\n 1 - Nombre\n2 - Apellido\n 3 - Salario\n4 - Sector\n5 - Volver\n",
						"Error, opcion invalida", 1, 5, 2);
				switch (option) {
				case 1:
					getString(bufferName, "ingrese el nombre\n",
							"Error, dato ingresado no valido", 51, 2);
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						strcpy(list[id-1].name, bufferName);
						printf("MODIFICACION hecha\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("MODIFICACION anulada\n");
					}
					break;
				case 2:
					getString(bufferLastName, "Ingrese el apellido",
							"Error, dato ingresado no valido", 51, 2);
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						strcpy(list[id - 1].lastName, bufferLastName);
						printf("MODIFICACION hecha\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("MODIFICACION anulada\n");
					}
					break;
				case 3:
					getNumberDecimal(&bufferSalary, "Ingrese el salario",
							"Error, dato ingresado no valido", SALARY_MIN, SALARY_MAX,
							2);
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						list[id - 1].salary = bufferSalary;
						printf("MODIFICACION hecha\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("MODIFICACION anulada\n");
					}
					break;
				case 4:
					getNumber(&bufferSector, "Ingrese el sector",
							"Error, dato ingresado no valido", SECTOR_MIN, SECTOR_MAX,
							2);
					getString(respuesta, "Confirma la modificacion\n [SI/NO]\n",
							"Opcion incorrecta\n", 10, 2);
					strupr(respuesta);
					if (strcmp(respuesta, "SI") == 0) {
						list[id - 1].sector = bufferSector;
						printf("MODIFICACION hecha\n");

						ret = 0;
					} else if (strcmp(respuesta, "NO") == 0) {
						printf("MODIFICACION anulada\n");
					}
					break;
				case 5:
					break;
					}
				system("CLS");
			}while (option != 5);
		}
	}
	return ret;
}

/*
 * \brief sort the elements in the array of employees, the argument order indicate UP or DOWN order.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
int sortEmployees(eEmployee *list, int len, int order) {
	int flagDesordenado = 1;
	int ret = -1;
	int i;
	eEmployee auxEmployee;
	if(list != NULL && len > 0){
		system("CLS");
		switch(order) {
		case 1:
			do {
				flagDesordenado = 0;
				for (i = 0; i < len-1; i++) {
					if (strcmp(list[i].lastName,list[i+1].lastName)<0) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					if (strcmp(list[i].lastName,list[i+1].lastName)==0
							&& list[i].sector < list[i+1].sector) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					len--;
				}

			} while (flagDesordenado);
			//system("PAUSE");
			system("CLS");
			ret = 0;
			break;
		case 0:
			do {
				flagDesordenado=0;
				for (i = 0; i < len-1; i++) {
					if (strcmp(list[i].lastName,list[i+1].lastName)>0) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					if (strcmp(list[i].lastName,list[i+1].lastName)==0
							&& list[i].sector > list[i+1].sector) {
						auxEmployee = list[i+1];
						list[i+1] = list[i];
						list[i] = auxEmployee;
						flagDesordenado = 1;
					}
					len--;
				}

			} while (flagDesordenado);

			system("CLS");
			ret = 0;
			break;
		}
	}

	return ret;
}

/*
 * \brief Sum all employee salaries (with isEmpty = 0) from an array and print their
 * 		  average and the employees that exceed that average as salary.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
void getAverage (eEmployee *list, int len){
	int i;
	float collector = 0;
	int acc = 0;
	float average;

	if(list != NULL && len > 0){
		system("CLS");
		for(i=0;i<len;i++){
			if(list[i].isEmpty==0){
				collector = collector + list[i].salary;
				acc++;
			}
		}
		average = collector / acc;
		printf("TOTAL DE LOS SALARIO : %.2f\n",collector);
		printf("SALARIO PROMEDIO : %.2f\n",average);
		printf("ID		NAME		LASTNAME		SALARY		SECTOR\n\n");
		for(i=0;i<len;i++){
			if(list[i].salary > average){
				printf("%d		%s		%s			%.2f		%d\n", list[i].id, list[i].name,
									list[i].lastName, list[i].salary, list[i].sector);
			}
		}
		system("PAUSE");
		system("CLS");
	}
}
/*
 * \brief menu where you can choose the option to order employees or calculate the average wages.
 * \param list eEmployee* Pointer to array of employees.
 * \param len int Array lenght.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if Id is invalid] - (0) if Ok.
 * */
void menuSort(eEmployee *list, int len, int id) {
	int optionSort;
	int order;

	if(list != NULL && len > 0 && id > 0){
		//system("CLS");
		do {
			system("CLS");
			getNumber(&optionSort,
							"MENU INFORMES\n\n1 - Ordenar listado\n2 - Promedio de salarios\n3 - Volver",
							"Error, opcion invalida", 1, 3, 2);
			switch (optionSort) {
			case 1:
				if(id > 1){
					system("CLS");
					getNumber(&optionSort,"ELIJA EL ORDEN\n\n 1 - Menor a mayor\n 2 - Mayor a menor","Error, opcion invalida",1,2,2);
					if(optionSort== 1){
						order = 1;
					}else if(optionSort == 2){
						order = 0;
					}
					sortEmployees(list,len,order);
					printEmployees(list,len);
					system("PAUSE");
				}else{
					printf("Debe agregar un empleado mas para poder ordenarlos\n");
				}
				break;
			case 2:
				system("CLS");
				getAverage(list,len);
				break;
			case 3:
				break;
			}

		} while (optionSort != 3);
	}

}


/*
if(this != NULL && pFunc != NULL && (order == 1 || order == 0) && lenLL > 0)
switch(order){
    	case 0://ascendente
    		do{
    			flagSwap = 0;
    			for(i=0;i<lenLL-1;i++){
    				pElement1 = ll_get(this,i);
    				pElement2 = ll_get(this,i+1);
					r = pFunc(pElement1,pElement2);
					if(r == -1){
						pAux = pElement1;
						ll_set(this,i,pElement2);
						ll_set(this,i+1,pAux);
						flagSwap = 1;
					}
				}
				lenLL--;
    		}while(flagSwap);
			returnAux = 0;
    		break;
    	case 1://descendente
    		do{
    			flagSwap = 0;
				for(i=0;i<lenLL-1;i++){
					pElement1 = ll_get(this,i);
					pElement2 = ll_get(this,i+1);
					r = pFunc(pElement1,pElement2);
					if( r == 1){
						pAux = pElement1;
						ll_set(this,i,pElement2);
						ll_set(this,i+1,pAux);
						flagSwap = 1;
					}
				}
				lenLL--;
    		}while(flagSwap);
			returnAux = 0;
    		break;
    	}

*/
