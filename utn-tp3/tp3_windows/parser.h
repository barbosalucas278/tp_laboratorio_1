/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: pocho
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

FILE* openFileFromText(char* path);
FILE* writeFileFromText(char* path);
int saveAsText(FILE* pFile,LinkedList* pArrayListEmployee, int lenLL );

int saveAsBinary(FILE* pFile,LinkedList* pArrayList,int lenLL);
