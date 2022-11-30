#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movie.h"
#include "parser.h"
#include "utn.h"

static Node* getNode(LinkedList* this, int nodeIndex); //NO SE TOCA WACHIN
static int addNode(LinkedList* this, int nodeIndex,void* pElement);//NO SE TOCAN

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    //reserva memoria dinamica para la linkedlist

    if(this != NULL)
    {
        this->pFirstNode = NULL;
        //inicializo en NULL para que no apunte a basura

        this->size = 0;
        //inicializa el tamaño

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

    if(this != NULL)
    {
    	returnAux = this->size;
    	//Me da el tamaño de this
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
	Node* pNodo = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex <  ll_len(this))
	{
		pNodo = this->pFirstNode;

		while(nodeIndex > 0)
		{
			pNodo=pNodo->pNextNode;
			nodeIndex--;
		}
	}

    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)//NO SE TOCA WACHIN
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
    Node* nuevoNodo=NULL;
    Node* nodoAnterior=NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	 nuevoNodo = (Node*) malloc(sizeof(Node));
    	 if(nuevoNodo != NULL)
    	 {
    		 nuevoNodo->pElement=pElement;
    		 nuevoNodo->pNextNode=getNode(this, nodeIndex);
    		 if(nodeIndex==0)
    		 {
    			 this->pFirstNode=nuevoNodo;
    		 }
    		 else
    		 {
    			 nodoAnterior=getNode(this, nodeIndex-1);
    			 nodoAnterior->pNextNode=nuevoNodo;
    		 }
    		 this->size++;
    		 returnAux=0;
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)//NO SE TOCA
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
    return addNode(this, ll_len(this),pElement);
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
    void * returnAux=NULL;
    Node* pNode = getNode(this,index);

    if(pNode!=NULL)
    {
    	returnAux=pNode->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux=-1;
    Node* pNode = getNode(this,index);

    if(pNode!=NULL)
    {
    	pNode->pElement=pElement;
    	returnAux=0;
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
int ll_remove(LinkedList* this,int index)
{
	int returnAux=-1;
	Node* pNodeToDelete = NULL;
	Node* pNodeNext= NULL;
	if(this!=NULL && index >=0 && index < ll_len(this))
	{
		if(index==0)
		{
			pNodeToDelete=this->pFirstNode;
			this->pFirstNode = getNode(this, 1);

		}
		else
		{
			pNodeNext=getNode(this, index-1);
			pNodeToDelete=pNodeNext->pNextNode;
			pNodeNext->pNextNode = pNodeToDelete->pNextNode;
		}
		free(pNodeToDelete);
		this->size--;
		returnAux=0;
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
   int returnAux=-1;
   if(this!=NULL)
   {
	   while(!ll_isEmpty(this))
	   {
		   ll_remove(this, 0);
	   }
	   returnAux=0;
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
	int returnAux=-1;
	if(this!=NULL)
	{
		ll_clear(this);
		free(this);
		returnAux=0;
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
	int returnAux=-1;
	for(int i=0; i < ll_len(this);i++)
	{
		if(ll_get(this, i)==pElement)
		{
			returnAux=i;
			break;
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
	int returnAux=-1;
	int len=ll_len(this);
	if(len==0)
	{
		returnAux=1;
	}
	else
	{
		if(len>0)
		{
			returnAux=0;
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
	return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
   void* returnAux=ll_get(this, index);
   ll_remove(this, index);
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
	int returnAux=-1;
	int index;
	if(this!=NULL)
	{
		returnAux=0;
		index=ll_indexOf(this, pElement);
		if(index>=0)
		{
			returnAux=1;
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
	int returnAux=-1;
	int len;
	void* pElement = NULL;
	if(this!=NULL && this2!=NULL)
	{
		returnAux=1;
		len=ll_len(this2);
		for(int i=0; i<len;i++)
		{
			pElement=ll_get(this2, i);
			if(!ll_contains(this, pElement))
			{
				returnAux=0;
				break;
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
	LinkedList* cloneArray=NULL;
	void* pElement=NULL;
	if(this != NULL && from >=0 && from < to && to <= ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		if(cloneArray!=NULL)
		{
			for(int i=from;i<to; i++)
			{
				pElement=ll_get(this, i);
				ll_add(cloneArray, pElement);
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
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux=-1;
	int len;
	void* elementoI=NULL;
	void* elementoJ=NULL;
	void* aux=NULL;
	if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
	{
		len=ll_len(this);
		for(int i=0; i<len-1;i++)
		{
			for(int j=i+1; j<len;j++)
			{
				elementoI=ll_get(this, i);
				elementoJ=ll_get(this, j);
				if((pFunc(elementoI,elementoJ)>0 && order)
				|| (pFunc(elementoI,elementoJ)<0 && !order))
				{
					aux=elementoI;
					ll_set(this, i, elementoJ);
					ll_set(this, j, aux);
				}
			}
		}
		returnAux=0;
	}
    return returnAux;
}

/**
 * \brief Devuelve un nuevo LinkedList cargado con los elementos que pasan la funcion filtro
 *
 * \param this LinkedList a filtrar
 * \param int (*pFunc)(void*) puntero a la funcion que filtra
 * \return Nuevo puntero a LinkedList con los elementos que pasaron la funcion
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* filterList=NULL;
	int len;
	void* pAux=NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		filterList=ll_newLinkedList();
		if(filterList!=NULL)
		{
			len=ll_len(this);
			for(int i=0; i<len;i++)
			{
				pAux=ll_get(this, i);
				if(pFunc(pAux))
				{
					if(ll_add(filterList, pAux))
					{
						ll_deleteLinkedList(filterList);
						filterList=NULL;
						break;
					}
				}
			}
		}
	}
	return filterList;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    LinkedList* auxLista = NULL;
    int len;
    void* pElementAux;
    if(this != NULL && pFunc != NULL)
    {
        auxLista = ll_newLinkedList();
        if(auxLista != NULL)
        {
            len = ll_len(this);
            for (int i = 0; i < len; i++)
            {
                pElementAux = pFunc(ll_get(this,i));
                ll_add(auxLista,pElementAux);

            }
        }
    }
    return auxLista;
}
