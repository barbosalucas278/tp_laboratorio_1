/*
 * Articulo.c
 *
 *  Created on: 25 jun. 2020
 *      Author: LucasBarbosa
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Articulo.h"

/*
 *\brief create a new article by reserving dynamic memory
 *\return eArticulo* if ok
 *\return NULL if haven't memory.
 *
 */
eArticulo* articulo_new(){
	eArticulo* newArticulo;
	newArticulo = (eArticulo*)malloc(sizeof(eArticulo));
	if(newArticulo != NULL){
		articulo_setArticulo(newArticulo,"");
		articulo_setPrecio(newArticulo,0.0);
		articulo_setMedida(newArticulo,"");
		articulo_setRubrioId(newArticulo,0);
	}

	return newArticulo;
}
/*
 *\brief create a new article with parameters.
 *\param idStr char*
 *\param articuloStr char*
 *\param precioStr char*
 *\param medidaStr char*
 *\param rubroIdStr char*
 *\return newArticulo eArticulo*
 */
eArticulo* articulo_newParametros(char* idStr, char* articuloStr, char* precioStr, char* medidaStr, char* rubroIdStr){
	eArticulo* newArticulo = articulo_new();
	if(newArticulo != NULL){
		articulo_setId(newArticulo,atoi(idStr));
		articulo_setArticulo(newArticulo,articuloStr);
		articulo_setPrecio(newArticulo,atof(precioStr));
		articulo_setMedida(newArticulo,medidaStr);
		articulo_setRubrioId(newArticulo,atoi(rubroIdStr));
	}
	return newArticulo;
}

/*
 *	\brief  set id of the article.
 *	\param this eArticulo*
 *	\param id int
 *	\return int (-1) Error [this pointer is NULL]
 *				(0) Is ok.
 */
int articulo_setId(eArticulo* this, int id){
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
 *	\brief  get id of the article.
 *	\param this eArticulo*
 *	\param id int*
 *	\return int (-1) Error [this and id pointers are NULL]
 *				(1) Is ok.
 */
int articulo_getId(eArticulo* this, int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		ret = 1;
	}
	return ret;
}

/*
 *	\brief  set name of the article.
 *	\param this eArticulo*
 *	\param articulo char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setArticulo(eArticulo* this, char* articulo){
	int ret = -1;
	if(this != NULL){
		strcpy(this->articulo,articulo);
		ret = 1;
	}
	return ret;

}

/*
 *	\brief  get name of the article.
 *	\param this eArticulo*
 *	\param articulo char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getArticulo(eArticulo* this, char* articulo){
	int ret = -1;
	if(this != NULL){
		strcpy(articulo,this->articulo);
		ret = 1;
	}

	return ret;
}
/*
 *	\brief  set price of the articles.
 *	\param this eArticulo*
 *	\param precio float
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setPrecio(eArticulo* this, float precio){
	int ret = -1;
	if(this != NULL && precio >0){
		this->precio = precio;
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  get price of the articles.
 *	\param this eArticulo*
 *	\param precio float*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getPrecio(eArticulo* this, float* precio){
	int ret = -1;
	if(this != NULL && precio != NULL){
		*precio = this->precio;
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  set measurement of the article.
 *	\param this eArticulo*
 *	\param medida char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setMedida(eArticulo* this, char* medida){
	int ret = -1;
	if(this != NULL){
		strcpy(this->medida,medida);
		ret = 1;
	}
	return ret;
}
/*
 *	\brief  get measurement of the article.
 *	\param this eArticulo*
 *	\param medida char*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getMedida(eArticulo* this, char* medida){
 	int ret = -1;
 	if(this != NULL){
 		strcpy(medida,this->medida);
 		ret = 1;
 	}
 	return ret;
 }
/*
 *	\brief  set entry id of the articles.
 *	\param this eArticulo*
 *	\param rubroId int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_setRubrioId(eArticulo* this, int rubroId){
	int ret = -1;
	if(this != NULL){
		this->rubroId = rubroId;
		ret = 1;
	}
	return ret;

}
/*
 *	\brief  get entry id of the articles.
 *	\param this eArticulo*
 *	\param rubroId int*
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_getRubroId(eArticulo* this, int* rubroId){
	int ret = -1;
	if(this != NULL){
		*rubroId = this->rubroId;
		ret = 1;
	}
	return ret;

}
/*
 *	\brief  get name by entry of the article.
 *	\param this eArticulo*
 *	\param rubroId char*
 *	\return int (-1) Error [this and name pointers are NULL]
 *				(1) Is ok.
 */
int articulo_getRubroChar(eArticulo* this, char* rubroId){
	int ret = -1;
	int auxRubroId;
	articulo_getRubroId(this,&auxRubroId);
	if(this != NULL){
		switch(auxRubroId){
		case 1:
			strcpy(rubroId,"CUIDADO DE ROPA");
			ret = 1;
			break;
		case 2:
			strcpy(rubroId,"LIMPIEZA Y DESINFECCION");
			ret = 1;
			break;
		case 3:
			strcpy(rubroId,"CUIDADO PERSONAL E HIGIENE");
			ret = 1;
			break;
		case 4:
			strcpy(rubroId,"CUIDADO DEL AUTOMOTOR");
			ret = 1;
			break;
		}
	}
	return ret;
}
/*
 *	\brief  print an articles.
 *	\param this eArticulo*
 *	\param rubroId int
 *	\return int (-1) Error [this pointer is NULL]
 *				(1) Is ok.
 */
int articulo_printArticle (eArticulo* this){
	int ret = -1;
	int bufferId;
	char bufferArticulo[64];
	float bufferPrecio;
	char bufferMedida[16];
	char bufferRubroId[64];
	if(this != NULL){
		articulo_getId(this,&bufferId);
		articulo_getArticulo(this,bufferArticulo);
		articulo_getPrecio(this,&bufferPrecio);
		articulo_getMedida(this,bufferMedida);
		articulo_getRubroChar(this,bufferRubroId);

		printf("%5d | %28s | %7.2f | %7s | %20s\n",bufferId,bufferArticulo,bufferPrecio,bufferMedida,bufferRubroId);
		ret = 1;
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
int sortByArticle(void* article1, void* article2){
	int ret = 0;
	char nameArticle1[64];
	char nameArticle2[64];
	articulo_getArticulo(article1,nameArticle1);
	articulo_getArticulo(article2,nameArticle2);
	if(article1  != NULL && article2 != NULL){
		if(strcmp(nameArticle1,nameArticle2)>0){
			ret = 1;
		}
		else if(strcmp(nameArticle2,nameArticle1)>0){
			ret = -1;
		}
	}

	return ret;
}

/*\brief calcula el descuento del precio de los articulos segun el rubro
 * \param articulo void*
 *
 */

void articulo_discount(void *articulo) {
	int rubroId ;
	float precio;
	float nuevoPrecio;
	articulo_getRubroId(articulo, &rubroId);
	articulo_getPrecio(articulo,&precio);
	if(rubroId == 1 && precio >= 120){
		nuevoPrecio = (precio)-((precio*20)/(float)100);
		articulo_setPrecio(articulo, nuevoPrecio);
	}else if((rubroId == 3 || rubroId == 2 || rubroId == 4) && precio <=200){
		nuevoPrecio = (precio)-((precio*10)/(float)100);
		articulo_setPrecio(articulo, nuevoPrecio);
	}

}
/*
 *\brief devuelve la cantidad de articulos con el precio mayor a 100
 *\param pArticle void*
 *\return int (0) si el articulo es NULL o el precio es menos a 100.0
 *			  (1) si el precio dle articulo es mayor a 100.0
 */
int articulo_masDe100(void* pArticle){
	int auxCantidad=0;
	float precio;
	if(pArticle != NULL){
		articulo_getPrecio(pArticle,&precio);
		if(precio > 100.0){
			auxCantidad = 1;
		}
	}
	return auxCantidad;
}
/*
 *\brief devuelve la cantidad de articulos del rubroId 1
 *\param pArticle void*
 *\return int (0) si el articulo es NULL o el rubroId es distinto de 1.
 *			  (1) si el articulo es del rubroId 1.
 */
int articulo_cantidadRubro1(void* pArticle){
	int auxCantidad = 0;
	int rubroId;
	if(pArticle != NULL){
		articulo_getRubroId(pArticle,&rubroId);
		if(rubroId == 1){
			auxCantidad = 1;
		}
	}
	return auxCantidad;
}
/*
 *
 *
 */
void articulo_delete(eArticulo* this){
	if(this != NULL){
		free(this);
	}
}


