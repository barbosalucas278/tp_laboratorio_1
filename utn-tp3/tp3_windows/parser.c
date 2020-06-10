#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int ret;
	Employee *newEmployee;
	char buffer[4][20];
	int count;
	if(pFile != NULL && pArrayListEmployee != NULL){

		fscanf(pFile, "%[id],%[nombre],%[horasTrabajadas],%[sueldo]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			while (!feof(pFile)) {
				count = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
						buffer[1], buffer[2], buffer[3]);
				if (count < 4) {
					ret = -1;
					break;
				}
				newEmployee = employee_newParametros(buffer[0], buffer[1],
						buffer[2], buffer[3]);
				if (newEmployee != NULL) {
					ll_add(pArrayListEmployee,(Employee*)newEmployee);
						ret = 1;
				}
			}
		}

	return ret;
}
/*
 *
 *
 *
 *
 */
FILE* parser_openFileFromText(char* path){

	FILE* file;
	if(path != NULL){
		file = fopen(path, "r");
		if (file == NULL) {
			printf("No se pudo abrir el archivo.");
		}
	}

	return file;
}

/*
 *
 *
 *
 *
 */
FILE* parser_WriteFlieFromText(char* path){

	FILE* file;
	if(path != NULL){
		file = fopen(path,"w");
		if(file == NULL){
			printf("El archivo no se puede abrir en modo escritura");
		}
	}
	return file;
}
/*
 *
 *
 *
 *
 */

int parser_saveAsText(FILE *pFile, LinkedList *pArrayListEmployee, int lenLL) {
	int ret = -1;
	Employee *newEmployee = employee_new();

	int i = 0;
	for (i = 0; i < lenLL; i++) {

		newEmployee = ll_get(pArrayListEmployee, i);
		fprintf(pFile,"%d,%s,%d,%d\n",newEmployee->id,newEmployee->nombre,
				newEmployee->horasTrabajadas,newEmployee->sueldo);
		ret = 1;
	}
	return ret;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	Employee* newEmployee;
	char buffer[4][20];
	int count;

	if(pFile != NULL && pArrayListEmployee != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while (!feof(pFile)) {
					count = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
							buffer[1], buffer[2], buffer[3]);
					if (count < 4) {
						ret = -1;
						break;
					}
					newEmployee = employee_newParametros(buffer[0], buffer[1],
							buffer[2], buffer[3]);
					if (newEmployee != NULL) {
						ll_add(pArrayListEmployee,(Employee*)newEmployee);
							ret = 1;
					}
				}
	}

    return ret;
}

FILE* parser_openFileFromBinary(char* path){

	FILE* file;
	if(path != NULL){
		file = fopen(path, "rb");
		if (file == NULL) {
			file = fopen(path,"wb");
			if(file == NULL){
				printf("No se pudo abrir el archivo.");
			}
		}
	}

	return file;
}

FILE* parser_WriteFileAsBinary(char* path){
	FILE* file;
	if(path != NULL){
		file = fopen(path,"wb");
		if(file == NULL){
			printf("No se pudo abrir el documento para escribirlo\n");
			fclose(file);
		}

	}
	return file;
}
int parser_saveAsBinary(FILE* pFile,LinkedList* pArrayList,int lenLL){
	int ret = -1;
	Employee *newEmployee = employee_new();

	int i = 0;
	for (i = 0; i < lenLL; i++) {

		newEmployee = ll_get(pArrayList, i);
		fprintf(pFile,"%d,%s,%d,%d\n",newEmployee->id,newEmployee->nombre,
						newEmployee->horasTrabajadas,newEmployee->sueldo);
		ret = 1;
	}
	return ret;
}
