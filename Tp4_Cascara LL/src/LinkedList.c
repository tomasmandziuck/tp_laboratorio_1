#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
	LinkedList* this;
	    this=(LinkedList *)malloc(sizeof(LinkedList));
	    	if(this!=NULL){
	    		this->size=0;
	    		this->pFirstNode=NULL;
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
    		returnAux=this->size;

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
		//int i;
	    Node* pNode=NULL;
	    if (this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
	    {
	        pNode=this->pFirstNode;
	        while(nodeIndex > 0)//for(i=0;i<nodeIndex;i++)
	        {
	           pNode=pNode->pNextNode;
	           nodeIndex--;
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
	/*int returnAux = -1;
		Node *pNodoNuevo;
		Node *pNodoAnterior;

		if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
		{
			pNodoNuevo = (Node*) malloc(sizeof(Node));
			if (pNodoNuevo != NULL)
			{
				pNodoNuevo->pElement = pElement; // le asigno la direccion de memoria del elemento que pasaron por parametro
				if (nodeIndex == 0)
				{
					if (this->pFirstNode == NULL)
					{
						pNodoNuevo->pNextNode = NULL; // si no habia nada lo inicializo en NULL
					}
					if (this->pFirstNode != NULL)
					{
						pNodoNuevo->pNextNode = this->pFirstNode; // si guardaba un dato lo respaldo
					}
					this->pFirstNode = pNodoNuevo; // lo piso recien despues de respaldarlo
				}
				else
				{
					pNodoAnterior = getNode(this, nodeIndex - 1);
					pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
					pNodoAnterior->pNextNode = pNodoNuevo;
				}
				this->size++;
				returnAux = 0;
			}

}
		return returnAux;*/
	int returnAux = -1;
	Node* nuevoNodo=NULL;

	if(this != NULL && nodeIndex >=0 && nodeIndex <= ll_len(this) ){

		nuevoNodo= (Node*)malloc(sizeof(Node));
			if(nuevoNodo != NULL){
				nuevoNodo->pElement=pElement;

				if(nodeIndex == 0){
					nuevoNodo->pNextNode=this->pFirstNode;
					this->pFirstNode=nuevoNodo;
				}
				else{
					nuevoNodo->pNextNode=getNode(this,nodeIndex);
					(getNode(this, nodeIndex-1))->pNextNode= nuevoNodo;
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

	    if ( this != NULL ) {
	    	returnAux = addNode ( this, ll_len ( this ), pElement );
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

	    if (  this != NULL && index > -1 && index < ll_len ( this ) )
	    {
	    	returnAux = getNode ( this, index )->pElement;
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
	int returnAux = -1;
	    Node* pNode;

	    if(this != NULL && index >= 0 && index < ll_len(this))
	    {
	    	pNode = getNode(this, index);
	    	if(pNode != NULL)
	    	{
	    		pNode->pElement = pElement;
	    		returnAux = 0;
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
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
		Node* actualNode;
		Node* previousNode;
	if (this != NULL && index < ll_len(this) && index >= 0)
		{
			actualNode = getNode(this, index);
			if (actualNode != NULL )
			{
				if (index == 0)
				{
					this->pFirstNode = actualNode->pNextNode;
				} else {
					previousNode = getNode(this, index - 1);
					if (previousNode != NULL)
					{
						previousNode->pNextNode = actualNode->pNextNode;
					}
				}
				this->size--;
				free(actualNode);
				returnAux = 0;
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
	 	if(this != NULL){
	 		while(ll_len(this)>0){
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
	int returnAux = -1;

	    if(this!=NULL)
	    {
	    	if(!ll_clear(this))
	    	{
	    		free(this);
	    		returnAux = 0;
	    	}
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

	    if (this != NULL)
	    {
	    	for (int i = 0; i < ll_len(this); i++)
	    	{
	    		if (ll_get(this, i) == pElement)
	    		{
	    				returnAux = i;
	    				break;
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
	 int returnAux = -1;

	    if(this!= NULL)
	    {
	    	returnAux = 0;
	    	if(!ll_len(this))
	    	{
	    		returnAux = 1;
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
    int returnAux = -1;
    returnAux = addNode(this, index, pElement);

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
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;

	    if(this!= NULL )
	    {
	    	returnAux = (void*)ll_get(this, index);
	    	if(returnAux!= NULL)
	    	{
	    		ll_remove(this, index);
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

    	if(this!=NULL){
    		if(ll_indexOf(this, pElement) != -1){
    			returnAux=1;
    		}
    		else{
    			returnAux=0;
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
    int i;
    	if(this!=NULL && this2!=NULL){
    		returnAux=1;
    		for(i=0; i < ll_len(this2);i++){
    			if(!ll_contains(this,ll_get(this2,i))){
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
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;

    if(this!=NULL){

    	if(from>=0 && from<= ll_len(this) && to>from && to <= ll_len(this)){

    		cloneArray=ll_newLinkedList();

    		if(cloneArray!=NULL){

    			for(i=from;i<to;i++){
    				pElement=ll_get(this,i);

    				ll_add(cloneArray,pElement);
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
    if(this != NULL){
        	cloneArray = ll_subList(this,0,ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* var1;
        void* var2;

        if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
        {
        	for(int a = 0; a < ll_len(this)-1; a++)
        	{
        		for(int b = a+1; b < ll_len(this); b++)
        		{
        			var1 = ll_get(this, a);
        			var2 = ll_get(this, b);
        			if((pFunc(var1,var2) > 0 && order) || (pFunc(var1,var2) < 0 && !order))
        			{
        				ll_set(this, a, var2);
        				ll_set(this, b, var1);
        			}
        		}
        	}
        	returnAux = 0;
        }
        return returnAux;
}


