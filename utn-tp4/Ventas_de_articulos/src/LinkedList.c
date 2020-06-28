#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;
	int i;
	int lenLL = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < lenLL){
		if(nodeIndex == 0){
			if(lenLL == 0){
				pNode = NULL;
			}else{
				pNode = this->pFirstNode;
			}
		}else{
				pNode = this->pFirstNode;
			for(i=0;i<nodeIndex;i++){
				pNode = pNode->pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;
    Node* auxNode;
    int lenLL = ll_len(this);
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= lenLL){
    	pNewNode = (Node*)malloc(sizeof(Node));
		if(pNewNode != NULL){
			if(nodeIndex == 0){
				pNewNode->pNextNode = this->pFirstNode;
				pNewNode->pElement = pElement;
				this->pFirstNode = pNewNode;
				this->size++;
				returnAux = 0;
			}
			else
			{
				auxNode = getNode(this,nodeIndex-1);
				if(auxNode != NULL){
					pNewNode->pNextNode = auxNode->pNextNode;
					pNewNode->pElement = pElement;
					auxNode->pNextNode = pNewNode;
					this->size++;
					returnAux = 0;
				}

			}
		}

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenLL = ll_len(this);
    if(this != NULL){
    	if(!addNode(this,lenLL,pElement)){
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* bufferNode= NULL;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL && index >= 0 && index < lenLL){
    		if(index==0){
    			bufferNode = getNode(this,0);
    			if(bufferNode != NULL){
					returnAux = bufferNode->pElement;
    			}else{
    				returnAux = NULL;
    			}
    		}else if (index == lenLL){
				bufferNode = getNode(this,lenLL);
				if(bufferNode != NULL){
					returnAux = bufferNode->pElement;
				}
    		}else{
				for(i=0;i<lenLL;i++){
					bufferNode = getNode(this,i);
					if(i==index && bufferNode != NULL){
						returnAux = bufferNode->pElement;
					}
				}
    		}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *auxNode = NULL;
	int lenLL = ll_len(this);
	int i;
	if (this != NULL && index >= 0 && index < lenLL) {
			if (index == 0) {
				auxNode = getNode(this, 0);
				if(auxNode != NULL){
					auxNode->pElement = pElement;
					returnAux = 0;
				}
			} else if (index == lenLL-1) {
				auxNode = getNode(this, lenLL-1);
				if(auxNode != NULL){
					auxNode->pElement = pElement;
					returnAux = 0;
				}
			} else {
				for (i = 0; i <= index; i++) {
					auxNode = getNode(this, i);
					if(auxNode != NULL){
						if (i == index) {
							auxNode->pElement = pElement;
							returnAux = 0;
						}
					}
				}
			}

		}
	return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) //9
{
    int returnAux = -1;
    int i;
    int lenLL = ll_len(this); //10
    Node* auxNode = NULL;
    Node* auxNode2 = NULL;
    if(this != NULL && index >= 0 && index <lenLL){
    	if(index == 0){
    		if(lenLL == 0){
				auxNode = getNode(this,index);
				if(auxNode == NULL){
					returnAux = 0;
				}
    		}else{
    			auxNode2 = getNode(this,index+1);
    			this->pFirstNode = auxNode2;
    			this->size--;
				returnAux = 0;
    		}
    	}else {
    		auxNode = getNode(this,index+1);
    		if(auxNode != NULL){
    			for(i=0;i<lenLL;i++){ //se va este for
					if(i == index-1){
						auxNode2 = getNode(this,i);
						if(auxNode2 != NULL){
							auxNode2->pNextNode = auxNode;
							this->size--;
							returnAux = 0;
						}
					}

    			}
    		}else{
    			auxNode = getNode(this,index-1);
    			auxNode->pNextNode = NULL;
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL){
    	for(i=0;i<lenLL;i++){
    		ll_remove(this,i);
			returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int i;
    int lenLL = ll_len(this);
    if(this != NULL){
    	for(i=0;i<lenLL;i++){
			auxNode = getNode(this,i);
			if(auxNode != NULL && auxNode->pElement == pElement){
				returnAux = i;
			}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int lenLL = ll_len(this);
    int returnAux = -1;
    if(this != NULL){
    	if(lenLL == 0){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int lenLL = ll_len(this);
    int returnAux = -1;
    Node* auxNode = NULL;
   // int i;
    if(this != NULL && index >= 0 && index <=lenLL){
    	auxNode = getNode(this, index);
    	if(auxNode == NULL){
			addNode(this,index,pElement);
			returnAux = 0;
    		}
        }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)//9
{
	int lenLL = ll_len(this);
    void* returnAux = NULL;
    Node* auxNode = NULL;
    int i;
    if(this != NULL && index >= 0 && index < lenLL){
    	for(i=0;i<lenLL;i++){
			auxNode = ll_get(this,i);
			if(i == index && auxNode != NULL){
				if(ll_remove(this,i)==0){
					returnAux = auxNode;
					break;
				}
			}
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL){
    	if(ll_indexOf(this,pElement) == -1){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement;
    int i;
    int lenLL2 = ll_len(this2);
    if(this != NULL && this2 != NULL){
    	if(lenLL2 == 0){
    		returnAux = 0;
    	}else{
			for(i=0;i<lenLL2;i++){
				auxElement = ll_get(this2,i);
				if(!ll_contains(this,auxElement)){
					returnAux = 0;
					break;
				}else{
					returnAux = 1;
				}
			}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode = NULL;
    int lenLL = ll_len(this);
    int i;
    if(this != NULL && (from >=0 && from < lenLL) && (to > from && to <= lenLL)){
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL){
			for(i=from;i<=to;i++){
				auxNode = getNode(this,i);
				if(auxNode != NULL){
					addNode(cloneArray,i,auxNode->pElement);
				}
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int lenLL = ll_len(this);
    if(this != NULL){
    	cloneArray = ll_subList(this,0,lenLL);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	void *pElement1 = NULL;
	void *pElement2 = NULL;
	void *pAux = NULL;
	int lenLL = ll_len(this);
	int flagSwap = 1;
	int i;
	int r;
	if(this != NULL && pFunc != NULL && (order == 1 || order == 0) && lenLL > 0) {
		switch(order){
		    	case 1://ascendente
		    		do{
		    			flagSwap = 0;
		    			for(i=0;i<lenLL-1;i++){
		    				pElement1 = ll_get(this,i);
		    				pElement2 = ll_get(this,i+1);
							r = pFunc(pElement1,pElement2);
							if(r == 1){
								pAux = pElement1;
								ll_set(this,i,pElement2);
								ll_set(this,i+1,pAux);
								flagSwap = 1;
							}
						}
						lenLL--;
		    		}while(flagSwap);
					returnAux = 0;
		    		break;
		    	case 0://descendente
		    		do{
		    			flagSwap = 0;
						for(i=0;i<lenLL-1;i++){
							pElement1 = ll_get(this,i);
							pElement2 = ll_get(this,i+1);
							r = pFunc(pElement1,pElement2);
							if(r == -1){
								pAux = pElement1;
								ll_set(this,i,pElement2);
								ll_set(this,i+1,pAux);
								flagSwap = 1;
							}
						}
						lenLL--;
		    		}while(flagSwap);
					returnAux = 0;
		    		break;
		    	}
	}
	return returnAux;

}
/*	\brief modifica un elemento de la lista usando una funcion como criterio.
 * 	\param this LinkedList* puntero a la lista
 * 	\param (*pFunc) puntero a la funcion criterio
 * 	\return this LinkedList* retorna un puntero a la lista modificada.
 *
 *
 */

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void*)){
	int i;
	void* auxElement;
	int lenLL = ll_len(this);
	if(this != NULL && pFunc != NULL){
			for(i=0;i<lenLL;i++){
				auxElement = ll_get(this, i);
				if(auxElement!= NULL){
					pFunc(auxElement);
					ll_set(this,i,auxElement);
				}
			}
	}
	return this;
}
/*	\brief cuenta los elementos de la lista usando como criterio una funcion.
 *
 * 	\param this LinkedList* puntero a la lista
 * 	\param (*pFunc) puntero a la funcion criterio
 * 	\return this LinkedList* retorna el valor de la cantidad.
 *
 */
int ll_count(LinkedList* this, int (*pFunc)(void* )){
	int auxCantidad = 0;
	int cantidadRetornada = 0;
	int i;
	int lenLL = ll_len(this);
	void* auxElement;
	if(this != NULL){
		for(i=0;i<lenLL;i++){
			auxElement = ll_get(this,i);
			auxCantidad = pFunc(auxElement);
			cantidadRetornada = cantidadRetornada + auxCantidad;
		}
	}
	return cantidadRetornada;
}






