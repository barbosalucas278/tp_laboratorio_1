/*
 * Distribuidora.c
 *
 *  Created on: 25 jun. 2020
 *      Author: LucasBarbosa
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Articulo.h"
#include "parser.h"

/** \brief print all articles from Linkedlist.
 *
 * \param pList LinkedList*
 * \param lenList int
 * \return int (-1) Error [pList pointer are NULL or lenList less than 0]
 * 				(1) is ok
 *
 */
int distribuidora_printAllArticles (LinkedList* pList , int lenList){
	int ret = -1;
	int i;
	eArticulo* this;
	if(pList != NULL && lenList > 0){
		for(i = 0; i <lenList; i++){
			this = ll_get(pList,i);
			if(this != NULL){
				articulo_printArticle(this);
				ret = 1;
			}
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
/* \brief loads the articles from file in text mode
 *	\papram pList LinkedList*
 *	\return int (-1) Error [path pointer and pList pointer are NULL]
 * 				(1) is ok
 */

int distribuidora_readFromFlie(LinkedList* pList){
	int ret = -1;
	FILE* file = openFileFromText();
	if(file != NULL){
		if(parser_articlesFromText(file,pList)){
			ret = 1;
		}
	}
	return ret;
}
/* \brief list and print the articles from LinkedList
 *	\papram pList LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int distribuidora_listArticles(LinkedList *pList) {
	int ret = -1;
	int lenLL = ll_len(pList);
	if (pList != NULL && lenLL >0) {
		if (distribuidora_printAllArticles(pList, lenLL)) {
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
/* \brief sort the articles from LinkedList
 *	\papram pList LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int distribuidora_sortArticles(LinkedList* pList){
	int ret = -1;
	int lenLL = ll_len(pList);
	if(pList != NULL && lenLL >2){
		if(!ll_sort(pList,sortByArticle,1)){
			distribuidora_listArticles(pList);
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
/* \brief calculate an discount on articles from LinkedList
 *	\papram pList LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int distribuidora_calculateDiscount(LinkedList* pList){
	int ret = -1;
	int lenLL = ll_len(pList);
	if(pList != NULL && lenLL > 0){
		if(ll_map(pList,articulo_discount)!= NULL){
			ret = 1;
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
/* \brief saves the articles to a file in text mode
 *	\papram pList LinkedList*
 *	\return int (-1) Error [path pointer and pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int distribuidora_saveOnFile(LinkedList* pList,char* path){
	int ret = -1;
	FILE* file;
	int lenLL = ll_len(pList);
	if(pList != NULL && path != NULL && lenLL >0){
		file = writeFileFromText(path);
		if(file != NULL){
			if(saveAsText(file,pList)){
				ret = 1;
			}
		}
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}
/*	\brief generates reports from the list of articles.
 *  \param pList LinkedList*
 *	\return int (-1) Error [pList pointer are NULL or lenLL equal than 0]
 * 				(1) is ok
 */
int distribuidora_informes(LinkedList* pList){
	int ret = -1;
	int informe1;
	int informe2;
	int lenLL = ll_len(pList);
	if(pList != NULL && lenLL >0){
		informe1 = ll_count(pList,articulo_masDe100);
		informe2 = ll_count(pList,articulo_cantidadRubro1);
		printf("Informe de articuolos\n");
		printf("*****************************\n");
		printf("- Cantidad de articulos cuyo precio es mayor a $100  : %d\n",informe1);
		printf("- Cantidad de articulos del rubro 1 - CUIDADO PARA LA ROPA  : %d\n",informe2);
		ret = 1;
	}else{
		printf("Primero debe cargar los articulos\n");
	}
	return ret;
}


