#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


/*
 *\brief create a new employee by reserving dynamic memory
 *\return Employee* if ok
 *\return NULL if haven't memory.
 *
 */
Employee* employee_new(){
	Employee* this = (Employee*) malloc(sizeof(Employee));
	if(this != NULL)
	{
		employee_setName(this,"");
		employee_setWorkedHours(this,0);
		employee_setSalary(this,0);
	}
	else
	{
		printf("No hay espacio en la memoria");
	}
	return this;
}

/*
 *\brief create a new employee with parameters.
 *\param id char*
 *\param name char*
 *\param hoursWorked char*
 *\param salary char*
 *\return Employee*
 */
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr,char* salaryStr){
	Employee* newEmployee = employee_new();
	if(idStr != NULL && nameStr != NULL && workedHoursStr != NULL && salaryStr != NULL){
		employee_setId(newEmployee,atoi(idStr));
		employee_setName(newEmployee,nameStr);
		employee_setWorkedHours(newEmployee,atoi(workedHoursStr));
		employee_setSalary(newEmployee,atoi(salaryStr));
	}

	return newEmployee;
}
/*
 *\brief create a new employee record.
 *\param id int
 *\param name char*
 *\param hoursWorked int
 *\param salary int
 *\return Employee*
 */
Employee* employee_newRegistration(int id,char* name, int workedHours, int salary){
	Employee* newEmployee = employee_new();
	if(id >=0 && name != NULL && workedHours > 0 && salary > 0){
		employee_setId(newEmployee,id);
		employee_setName(newEmployee,name);
		employee_setWorkedHours(newEmployee,workedHours);
		employee_setSalary(newEmployee,salary);
	}
	return newEmployee;
}
/*
 *\brief asks the user to enter the information for the new employee.
 *\param pName char*
 *\param pHoursWordked int*
 *\param pSalary int*
 *\return int
 */
int employee_dataRegistration(char* pName,int* pHoursWordked,int* pSalary){
	int ret = -1;
	char bufferName[20];
	int bufferHoursWorked;
	int bufferSalary;
		if(pName != NULL && pHoursWordked != NULL && pSalary != NULL){
			if(getFromABMName(bufferName)&&
			getFromABMWorkedHours(&bufferHoursWorked)&&
			getFromABMSalary(&bufferSalary)){
				strcpy(pName,bufferName);
				*pHoursWordked = bufferHoursWorked;
				*pSalary = bufferSalary;
				ret = 1;
			}
		}

	return ret;
}
/* \brief function to request new information from the employee
 *\param this Employee*
 *\return int (-1) Error [this pointer is NULL]
 *			(1) is OK.
 *
 */
int employee_modify(Employee* this){
	int ret = -1;
	char bufferName[20];
	int bufferHours;
	int bufferSalary;
	int option;

	if(this != NULL){
		do{
			option = submenuModidy();
			switch(option){
			case 1:
				getFromABMName(bufferName);
				if (questionConfirm("MODIFICACION HECHA\n","MODIFICACION CANCELADA\n")) {
					employee_setName(this,bufferName);

					option = 4;
					ret = 1;
					system("pause");
				}
				break;
			case 2:
				getFromABMWorkedHours(&bufferHours);
				if (questionConfirm("MODIFICACION HECHA\n","MODIFICACION CANCELADA\n")) {
					employee_setWorkedHours(this,bufferHours);
					ret = 1;
					option = 4;
					system("pause");
				}
				break;
			case 3:
				getFromABMSalary(&bufferSalary);
				if (questionConfirm("MODIFICACION HECHA\n","MODIFICACION CANCELADA\n")) {
					employee_setSalary(this,bufferSalary);
					ret = 1;
					option = 4;
					system("pause");
				}
				break;
			case 4:
				break;
			}
		}while(option != 4);

	}



	return ret;
}
/*
 *\brief submenu to choose the modify
 *
 *\return int option value.
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
 *	\brief  get by ABM the name of employee.
 *	\param name char*
 *	\return int (-1) Error [name pointer is NULL]
 *				(1) Is ok.
 */
int getFromABMName (char* name){
	int ret = -1;
	char axuName[20];
	if(name != NULL){
		if(getString(axuName,"Ingrese el nombre","Error, nombre invalido",20,2)){
			strcpy(name,axuName);
			ret = 1;
		}

	}


	return ret;
}
/*
 *	\brief  get by ABM the name of employee.
 *	\param pWorkedHours int*
 *	\return int (-1) Error [pWorkedHours pointer is NULL]
 *				(1) Is ok.
 */
int getFromABMWorkedHours(int* pWorkedHours){
	int ret = -1;
	int auxHours;
	if(pWorkedHours != NULL){
		if(getNumber(&auxHours,"Ingrese la horas trabajadas","Error, horas invalidas",1,325,2)){
			*pWorkedHours = auxHours;
			ret = 1;
		}

	}

	return ret;
}
/*
 *	\brief  get by ABM the name of employee.
 *	\param pSalary int*
 *	\return int (-1) Error [pSalary pointer is NULL]
 *				(1) Is ok.
 */
int getFromABMSalary(int* pSalary){
	int ret = -1;
	int auxSalary;
	if(pSalary !=  NULL){
		if(getNumber(&auxSalary,"Ingrese el sueldo","Error, horas invalidas",1,65000,2)){
			*pSalary = auxSalary;
			ret = 1;
		}

	}

	return ret;
}
/*
 *	\brief  set id of the employee.
 *	\param this Employee*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(0) Is ok.
 */
int employee_setId(Employee *this, int id) {
	int ret = -1;
	static int maxId = -1;
	if(this != NULL){
		ret = 0;
		if(id < 0 || id <maxId || id == maxId){
			maxId++;
			this->id = maxId;
		}else{
			if(id > maxId){
				maxId = id;
			}
				this->id = id;
		}
	}
return ret;
}
/*
 *	\brief  get id of the employee.
 *	\param this Employee*
 *	\param id int*
 *	\return int (-1) Error [this and id pointers are NULL]
 *				(1) Is ok.
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
 *	\brief  set name of the employee.
 *	\param this Employee*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int employee_setName(Employee* this,char* name){
	int ret = -1;
	if(this != NULL && name != NULL){
		strcpy(this->name,name);
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  get name of the employee.
 *	\param this Employee*
 *	\param id int*
 *	\return int (-1) Error [this and name pointers are NULL]
 *				(1) Is ok.
 */
int employee_getName(Employee* this,char* name){
	int ret = -1;
	if(this != NULL && name != NULL){
		strcpy(name,this->name);
		ret = 1;
	}

	return ret;
}
/*
 *	\brief  set workedHours of the employee.
 *	\param this Employee*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int employee_setWorkedHours(Employee* this,int workedHours){
	int ret = -1;
	if(this != NULL && workedHours >0){
		this->workedHours = workedHours;

		ret = 1;
	}
	return ret;
}
/*
 *	\brief  get workedHours of the employee.
 *	\param this Employee*
 *	\param id int*
 *	\return int (-1) Error [this and workedHours pointers are NULL]
 *				(1) Is ok.
 */
int employee_getWorkedHours(Employee* this,int* workedHours){
	int ret = -1;
	if(this != NULL && workedHours!= NULL){
		*workedHours = this->workedHours;
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  set salary of the employee.
 *	\param this Employee*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int employee_setSalary(Employee* this,int salary){
	int ret = -1;
	if(this != NULL && salary >0){
		this->salary = salary;
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  get salary of the employee.
 *	\param this Employee*
 *	\param id int*
 *	\return int (-1) Error [this and salary pointers are NULL]
 *				(1) Is ok.
 */
int employee_getSalary(Employee* this,int* salary){
	int ret = -1;
	if(this != NULL && salary != NULL){
		*salary = this->salary;
		ret = 1;
	}
	return ret;
}
/*\brief print an employee
 *\param this LinkedList*
 *\return int (-1) Error [if pointer this is NULL]
 *			  (1) if ok.
 *
*/
int printEmployee(Employee *this){
	int ret = -1;
	if(this != NULL){
		printf("%6d %15s %6d %6d\n",this->id,this->name,
				this->workedHours,this->salary);
		ret =1;
	}

	return ret;
}

/* \brief sort employees by salary
 * \param employee1 void*
 * \param employee2 void*
 * \return int (0) [employee1 and employee2 pointers are NULL or equal]
 *			   (1) [employee1 is higher than employee2].
 *			   (-1)[employee2 is higher than emploee1].
 */
int sortEmployeeBySalary(void* employee1, void* employee2){
	int ret = 0;
	int bufferSalary1;
	int bufferSalary2;

	employee_getSalary(employee1,&bufferSalary1);
	employee_getSalary(employee2,&bufferSalary2);

	if(employee1  != NULL && employee2 != NULL){
		if(bufferSalary1 > bufferSalary2){
			ret = 1;
		}else if(bufferSalary2 > bufferSalary1){
			ret = -1;
		}else if(bufferSalary1 == bufferSalary2){
			ret = 0;
		}
	}

	return ret;
}
/* \brief sort employees by worked hours.
 * \param employee1 void*
 * \param employee2 void*
 * \return int (0) [employee1 and employee2 pointers are NULL or equal]
 *			   (1) [employee1 is higher than employee2].
 *			   (-1)[employee2 is higher than emploee1].
 */
int sortEmployeeByWorkedHours(void* employee1, void* employee2){
	int ret = 0;
	int bufferHours1;
	int bufferHours2;

	employee_getWorkedHours(employee1,&bufferHours1);
	employee_getWorkedHours(employee2,&bufferHours2);
	if(employee1  != NULL && employee2 != NULL){
		if(bufferHours1 > bufferHours2){
			ret = 1;
		}else if(bufferHours2 > bufferHours1){
			ret = -1;
		}else if(bufferHours2 == bufferHours1){
			ret = 0;
		}

	}

	return ret;
}
/* \brief sort employees by id.
 * \param employee1 void*
 * \param employee2 void*
 * \return int (0) [employee1 and employee2 pointers are NULL or equal]
 *			   (1) [employee1 is higher than employee2].
 *			   (-1)[employee2 is higher than emploee1].
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
 * \brief free reserved memory from employee.
 * \param this Employee*
 * \return int (-1) Error [this pointer is NULL]
 */
int employee_delete(Employee* this){
	int ret = -1;
	if(this != NULL){
		free(this);
		ret = 1;
	}
	return ret;
}
