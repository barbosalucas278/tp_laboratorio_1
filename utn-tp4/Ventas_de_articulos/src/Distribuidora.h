/*
 * Distribuidora.h
 *
 *  Created on: 25 jun. 2020
 *      Author: LucasBarbosa
 */
#include "Articulo.h"

int distribuidora_readFromFlie(LinkedList* pList);
int distribuidora_sortArticles(LinkedList* pList);
int distribuidora_listArticles(LinkedList* pList);
int distribuidora_calculateDiscount(LinkedList* pList);
int distribuidora_saveOnFile(LinkedList* pList,char* path);
int distribuidora_informes(LinkedList* pList);

int distribuidora_printAllArticles (eArticulo* this , int lenList);



