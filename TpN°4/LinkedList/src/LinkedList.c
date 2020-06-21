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
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0; //INICIALIZO
        this->pFirstNode = NULL; //INICIALIZO
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
    }
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int len;
    int i = 0;
    if(this != NULL)
    {
        len = ll_len(this);
        if(nodeIndex > -1 && nodeIndex < len)
        {
            pNode = this->pFirstNode;
            while(i != nodeIndex)
            {
                pNode = pNode->pNextNode;
                i++;
            }
        }
    }
    return pNode;
}
/*
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int len;
    int i = 0;
    if(this != NULL)
    {
        len = ll_len(this);
        if(nodeIndex > -1 && nodeIndex < len)
        {
            pNode = this->pFirstNode;
            while(i != nodeIndex)
            {
                pNode = pNode->pNextNode;
                i++;
            }
        }
    }
    return pNode;
}*/

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
    Node* prev;
    Node* next;
    Node* nuevoNodo;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(nodeIndex > -1 && nodeIndex <= len && len > -1)
        {
            nuevoNodo = (Node*) malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                if(nodeIndex == 0) ///AGREGAR EN LA PRIMERA POSICION
                {
                    if(this->pFirstNode == NULL) //SI LA LISTA ESTA VACIA
                    {
                        this->pFirstNode = nuevoNodo;
                        nuevoNodo->pNextNode = NULL;
                        nuevoNodo->pElement = pElement;
                        this->size++;
                        returnAux = 0;
                    }
                    else if(this->pFirstNode != NULL)//SI LA LISTA TIENE ALGO
                    {
                        nuevoNodo->pNextNode = this->pFirstNode;
                        nuevoNodo->pElement = pElement;
                        this->pFirstNode = nuevoNodo;
                        this->size++;
                        returnAux = 0;
                    }
                }
                else if(nodeIndex == len) ///AGREGAR EN LA ULTIMA POSICION
                {
                    nuevoNodo->pNextNode = NULL; //POR SER EL ULTIMO NODO
                    nuevoNodo->pElement = pElement;
                    prev = getNode(this,(nodeIndex-1));
                    prev->pNextNode = nuevoNodo;
                    this->size++;
                    returnAux = 0;
                }
                else if(nodeIndex > 0 && nodeIndex < len) ///AGREGAR EN ALGUNA POSICION INTERMEDIA
                {
                    next = getNode(this,nodeIndex);
                    nuevoNodo->pNextNode = next;
                    nuevoNodo->pElement = pElement;
                    prev = getNode(this,(nodeIndex-1));
                    prev->pNextNode = nuevoNodo;
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
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;
    Node* actual;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && indice >= 0 && indice <= len)
        {
            if(!addNode(this,len,pElement))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Obtiene un elemento de la lista en base al indice ingresado
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
    int len;
    Node* auxNodo;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && index >= 0 && index < len)
        {
            auxNodo = getNode(this,index);
            returnAux = auxNodo->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && index >= 0 && index < len)
        {
            actual = getNode(this,index);
            actual->pElement = pElement;
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
    Node* prev;
    Node* actual;
    Node* next;
    int indice = 0;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && index >= 0 && index < len)
        {
            if(index == 0)
            {
                actual = getNode(this,index);
                this->pFirstNode = getNode(this,index+1);
                free(actual);
                this->size--;
                returnAux = 0;
            }

            else if(index == len)
            {
                actual = getNode(this,index);
                free(actual);
                prev = getNode(this,index-1);
                prev->pNextNode = NULL;
                this->size--;
                returnAux = 0;
            }
            else if(index > 0 && index < len)
            {
                prev = getNode(this,index-1);
                actual = getNode(this,index);
                next = getNode(this,index+1);
                free(actual);
                prev->pNextNode = next;
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
    Node* nodo;
    int i;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        for(i=len;i>-1;i--)
        {
            ll_remove(this,i);
            /*nodo = getNode(this,i);
            free(nodo);*///OTRA MANERA DE HACERLO
        }
        this->size = 0;
        this->pFirstNode = NULL;
        returnAux = 0;
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
    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            this = NULL;
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
    int i;
    int len;
    Node* nodo;
    if(this != NULL)
    {
        len = ll_len(this);
        for(i=0;i<len;i++)
        {
            nodo = getNode(this,i);
            if(nodo->pElement == pElement)
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
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            returnAux = 0;
        }
        else
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
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && index >= 0 && index <= len)
        {
            if(!addNode(this,index,pElement))
            {
                returnAux = 0;
            }
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
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* nodo;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len > -1 && index >= 0 && index < len)
        {
            nodo = getNode(this,index);
            returnAux = nodo->pElement;
            ll_remove(this,index);
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
    int indexFound;
    if(this != NULL)
    {
        indexFound = ll_indexOf(this,pElement);
        if(indexFound != -1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    int j;
    Node* pNodo1;
    Node* pNodo2;
    int len1;
    int len2;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        len2 = ll_len(this2);
        for(i=0;i<len2;i++)
        {
            returnAux = 0;
            pNodo2 = ll_get(this2,i);
            len1 = ll_len(this);
            for(j=0;j<len1;j++)
            {
                pNodo1 = ll_get(this,i);
                if(pNodo2 == pNodo1)
                {
                    returnAux = 1;
                }
                else
                {
                    returnAux = 0;
                    break;
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
    int i;
    void* pElement;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(from > -1 && from <= len && to >= from && to <= len && to >= 0)
        {
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL && from < to)
            {
                for(i=from;i<=to;i++)
                {
                    pElement = ll_get(this,i);
                    if(pElement != NULL)
                    {
                        ll_add(cloneArray,pElement);
                    }
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
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            cloneArray = ll_subList(this,0,this->size);
        }
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* pAux;
    int len;
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        len = ll_len(this);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(ll_get(this,i) != NULL && ll_get(this,j) != NULL)
                {
                    if(pFunc(ll_get(this,i),ll_get(this,j)) < 1 && order == 0)
                    {
                        pAux = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,pAux);
                    }
                    else if(pFunc(ll_get(this,i),ll_get(this,j)) > 1 && order == 1)
                    {
                        pAux = ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,pAux);
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

