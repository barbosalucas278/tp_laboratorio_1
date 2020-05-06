/*
 * employee.h
 *
 *  Created on: 2 may. 2020
 *      Author: LUcas Barbosa
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct eEmployee{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */

int initEmployees(eEmployee* list, int len);
int addEmployee (eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int addDataEmployees (eEmployee* list,int len, int* pId);
int findEmployeeById (eEmployee* list,int len,int id);
int printEmployees (eEmployee* list,int len);
int removeEmployee(eEmployee* list, int len, int id);
int getId(eEmployee* list, int len);
int modifyEmployee(eEmployee* list, int len);
int sortEmployees (eEmployee * list, int len, int order);
void menuSort(eEmployee *list, int len, int id);
void getAverage (eEmployee *list, int len);
