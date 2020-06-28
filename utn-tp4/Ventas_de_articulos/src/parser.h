/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: LucasBarbosa
 */
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Articulo.h"
#include <stdio.h>



#endif /* PARSER_H_ */
FILE* openFileFromText();
int parser_articlesFromText(FILE* pFile , LinkedList* pArrayListVenta);

FILE* writeFileFromText(char* path);
int saveAsText(FILE *pFile, LinkedList *pList);

int fprintfArticle (eArticulo* this, FILE* pFile);

