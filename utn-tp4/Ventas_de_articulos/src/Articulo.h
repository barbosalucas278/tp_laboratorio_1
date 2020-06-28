/*
 * Articulo.h
 *
 *  Created on: 25 jun. 2020
 *      Author: LucasBarbosa
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
typedef struct{
	int id;
	char articulo[64];
	float precio;
	char medida[16];
	int rubroId;
}eArticulo;


#endif /* ARTICULO_H_ */

eArticulo* articulo_new();
eArticulo* articulo_newParametros(char* idStr, char* articuloStr, char* precioStr, char* medidaStr, char* rubroIdStr);

int articulo_setId(eArticulo* this, int id);
int articulo_getId(eArticulo* this, int* id);

int articulo_setArticulo(eArticulo* this, char* articulo);
int articulo_getArticulo(eArticulo* this, char* articulo);

int articulo_setPrecio(eArticulo* this, float precio);
int articulo_getPrecio(eArticulo* this, float* precio);

int articulo_setMedida(eArticulo* this, char* medida);
int articulo_getMedida(eArticulo* this, char* medida);

int articulo_setRubrioId(eArticulo* this, int rubroId);
int articulo_getRubroId(eArticulo* this, int* rubroId);
int articulo_getRubroChar(eArticulo* this, char* rubroId);

int articulo_printArticle(eArticulo* this);

int sortByArticle(void* article1, void* article2);
void articulo_discount(void *articulo);

int articulo_masDe100(void* pArticle);
int articulo_cantidadRubro1(void* pArticle);

void articulo_delete(eArticulo* this);
