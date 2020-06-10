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

FILE* parser_openFileFromText(char* path);
FILE* parser_WriteFlieFromText(char* path);
int parser_saveAsText(FILE* pFile,LinkedList* pArrayListEmployee, int lenLL );

FILE* parser_openFileFromBinary(char* path);
FILE* parser_WriteFileAsBinary(char* path);
int parser_saveAsBinary(FILE* pFile,LinkedList* pArrayList,int lenLL);
