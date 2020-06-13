#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parse data employee data from data.csv file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pFile pointer and pArrayListEmployee are NULL or fscanf can't read the file]
 * 				(1) is ok.
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int ret = -1;
	Employee *newEmployee;
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
/*\brief opens file from text in read mode.
 *
 * \param path char*
 * \return FILE*
 *
 */
FILE* openFileFromText(char* path){

	FILE* file;
	if(path != NULL){
		file = fopen(path, "r");
		if (file == NULL) {
			printf("No se pudo abrir el archivo.");
		}
	}

	return file;
}

/*\brief opens file from text in write mode.
 *
 * \param path char*
 * \return FILE*
 *
 */
FILE* writeFileFromText(char* path){

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
 * \brief save information in the file.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\param lenLL int
 *	\return (-1) Error [pFile and pArrayListEmployee pointers are NUL or lenLL less than 0].
 *			(1)Is ok.
 */

int saveAsText(FILE *pFile, LinkedList *pArrayListEmployee, int lenLL) {
	int ret = -1;
	Employee *newEmployee = employee_new();
	int i = 0;

	if(pFile != NULL && pArrayListEmployee != NULL && lenLL >=0){
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for (i = 0; i < lenLL; i++) {
			newEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			fprintf(pFile,"%d,%s,%d,%d\n",newEmployee->id,newEmployee->name,
					newEmployee->workedHours,newEmployee->salary);
			ret = 1;
		}

	}
	return ret;
}
/** \brief Parse data employee data from file data.csv (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pFile pointer and pArrayListEmployee are NULL or fread can't read the file]
 * 				(1) is ok.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	Employee* bufferEmp;
	int count;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile)){
			bufferEmp = employee_new();
			count = fread(bufferEmp,sizeof(Employee),1,pFile);
			if(count != 1){
				if(feof(pFile)){
					system("pause");
					break;
				}else{
					ret = -1;
					printf("No se pudo leer el ultimo registro");
					break;
				}
			}
			ll_add(pArrayListEmployee,(Employee*)bufferEmp);
		}

	}

    return ret;
}

/*
 * \brief save information in the file.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\param lenLL int
 *	\return (-1) Error [pFile and pArrayListEmployee pointers are NUL or lenLL less than 0].
 *			(1)Is ok.
 */
int saveAsBinary(FILE* pFile,LinkedList* pArrayList,int lenLL){
	int ret = -1;
	Employee *newEmployee = employee_new();
	int i = 0;
	if(pFile != NULL && pArrayList != NULL && lenLL > 0){
		for (i = 0; i < lenLL; i++) {
			newEmployee = (Employee*)ll_get(pArrayList, i);
			fwrite(newEmployee,sizeof(Employee),1,pFile);
			ret = 1;
		}
	}
	return ret;
}
