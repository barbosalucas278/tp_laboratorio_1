
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "utn.h"
#include "Articulo.h"

/*
 * \brief opens a text file in read mode by entering the file name of the by command line.
 *
 * \return FILE*
 *
 */
FILE* openFileFromText(){
	FILE* file;
	char path[32];
	getString(path,"Ingrese el nombre dle archivo","Error, nombre incorrecto, no se olvide de agregarle .csv",32,2);
	file = fopen(path, "r");
	if (file == NULL) {
		printf("No se pudo abrir el archivo.");
	}
	return file;
}
/** \brief Parse data employee data from file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) Error [pFile pointer and pArrayListEmployee are NULL or fscanf can't read the file]
 * 				(1) is ok.
 *
 */
int parser_articlesFromText(FILE *pFile, LinkedList *pArrayListVentas) {
	int ret = -1;
	eArticulo *newArticle;
	char buffer[5][20];
	int count;
	if (pFile != NULL && pArrayListVentas != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
				buffer[1], buffer[2], buffer[3], buffer[4]);
		while (!feof(pFile)) {
			count = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
			if (count < 5) {
				ret = -1;
				printf("No se pudo leer un articulo\n");
				break;
			}
			newArticle = articulo_newParametros(buffer[0], buffer[1], buffer[3], buffer[2], buffer[4]);
			if(newArticle != NULL){
				ll_add(pArrayListVentas, (eArticulo*)newArticle);
				ret = 1;
			}
		}


	}

	return ret;
}

/*\brief opens file from text in write mode.
 *
 * \param path char*
 * \return FILE*
 *
 */
FILE* writeFileFromText(char* path){

	FILE* file;
		file = fopen(path,"w");
		if(file == NULL){
			printf("El archivo no se puede abrir en modo escritura");
		}
	return file;
}
/*  \brief write all articles in text mode.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\return int (-1) Error [pFile and eArticulo pointers are NULL].
 *			(1)Is ok.
 */
int fprintfArticle (eArticulo* this, FILE* pFile){
	int ret = -1;
	int bufferId;
	char bufferArticulo[64];
	float bufferPrecio;
	char bufferMedida[16];
	int bufferRubroId;
	if(this != NULL && pFile != NULL){
		articulo_getId(this,&bufferId);
		articulo_getArticulo(this,bufferArticulo);
		articulo_getPrecio(this,&bufferPrecio);
		articulo_getMedida(this,bufferMedida);
		articulo_getRubroId(this,&bufferRubroId);

		fprintf(pFile,"%d,%s,%.0f,%s,%d\n",bufferId,bufferArticulo,bufferPrecio,bufferMedida,bufferRubroId);
		ret = 1;
	}
	return ret;
}
/*
 * \brief save information in the file.
 *	\param pFile FILE*
 *	\param pArrayListEmployee LinkedList*
 *	\return (-1) Error [pFile and pList pointers are NULL].
 *			(1)Is ok.
 */

int saveAsText(FILE *pFile, LinkedList *pList) {
	int ret = -1;
	eArticulo* auxArticulo;
	int i;
	int lenLL = ll_len(pList);
	if(pFile != NULL && pList != NULL){
		for(i=0;i<lenLL;i++){
			auxArticulo = ll_get(pList,i);
			if(auxArticulo != NULL){
				fprintf(pFile,"id,articulo,medida,precio,rubroId\n");
				fprintfArticle(auxArticulo,pFile);
				ret = 1;
			}
		}
	}
	return ret;
}
