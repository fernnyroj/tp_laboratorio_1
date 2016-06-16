#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement)//añade un elemento al arraylst y si es nesesario agranda el array
{
    int returnAux = -1;
    if(pList!=NULL && pElement!=NULL)
    {

        resizeUp(pList);

        *((pList->pElements)+ pList->size)=pElement;
        pList->size ++;

        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;

    int i;

    if (pList != NULL)
    {
        for(i=pList->size ; i>0 ; i--)
        {
            free(pList->pElements[i]);
        }

        if(pList->size == 0)
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

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)//Debuelve el zise del array.
{
    int returnAux = -1 ;
    if(pList != NULL)
    {
        returnAux=pList->size;//return pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index) //obtener un elemento por el indice
{
    void* returnAux = NULL;
    if(pList !=NULL && index>=0 && index <=pList->size )
    {
        returnAux = *((pList->pElements)+index);
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement) //Encontrar si plist contiene al menos un elemento pElement
{
    int returnAux = -1;
    int i;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(pList->pElements[i] == pElement)
            {
                return 1;
            }
            else
            {
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)//Establecer un elemento en Plist en posición de índice
{
    int returnAux = -1;

    if(pList !=NULL && pElement != NULL && index>=0 && index < pList->size)
    {
        if (index== pList->size)
        {
            al_add(pList,pElement);
        }
        else
        {
            *((pList->pElements) +index) = pElement;
        }

        *((pList->pElements) + index) = pElement;

        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)//remueve un elemento del indice
{
    int returnAux = -1;

    if(pList !=NULL && (index>=0 && index < pList->size))
    {
        pList->pElements[index]=NULL;
        pList->size-=1;
        contract(pList,index);
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)//Elimina todos los elementos de esta lista
{
    int returnAux = -1;
    int i;

    if(pList !=NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            pList->pElements[i]=NULL;
        }
        pList->size=0;
        returnAux = 0;

    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)//Devuelve una matriz que contiene todos los elementos en esta lista en la secuencia correcta
{

     ArrayList* returnAux = NULL;
     int i, r;

     if(pList != NULL)
     {
         returnAux = al_newArrayList();
         if(returnAux != NULL)
         {
             for(i=0; i < pList->size; i++)
             {
                 r = returnAux->add(returnAux, *(pList->pElements + i));
                 if(r == -1)
                 {
                     free(returnAux->pElements);
                     free(returnAux);
                     returnAux = NULL;
                     return returnAux;
                 }
             }

         }
     }

     return returnAux;



}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)//Inserta un elemento en una posicion especifica.
{
    int returnAux = -1;

    if(pList !=NULL && pElement != NULL && index>=0 && index <= pList->size)
    {

        if (expand(pList,index)==0)
        {
            al_set(pList,index,pElement);
            //pList->size++;
            returnAux = 0;
        }


    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)//Devuelve el índice de la primera ocurrencia del elemento especificado
{
  int returnAux = -1;
     int i;

     if(pList != NULL && pElement != NULL)
     {
         for(i=0 ; i<pList->size ; i++)
         {
             if(pList->pElements[i]==pElement)
             {
                 return i;
             }
         }
     }

     return returnAux;

}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)//Devuelve true si esta lista no contiene elementos.
{
    int returnAux = -1;
    int i;

    if(pList != NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            if(pList->pElements[i] != NULL)
            {
                returnAux = 0;
                break;
            }
        }
        if(returnAux!=0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)//Quita el elemento en la posición dada en la lista , y lo devuelve.
{
    void* returnAux = NULL;
    if(pList !=NULL && (index>=0 && index < pList->size))
    {
        returnAux = pList->pElements[index];
        pList->remove(pList,index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    void* returnAux = NULL;
    void* aux;
    int i;

    if(pList != NULL && from >= 0 && from < pList->size && to>=0 && to <=pList->size && to> from)
    {
        returnAux =al_newArrayList();

        for(i=from ; i<to ; i++)
        {
            aux= al_get(pList,i);
            al_add(returnAux,aux);
        }

    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
     int returnAux = -1, i, r;

     if(pList != NULL && pList2 != NULL )
     {
         returnAux = 1;
         if(pList->size != pList2->size)
             returnAux = 0;

         for(i = 0; i < pList2->size; i++)
         {
             r = pList->contains(pList, *(pList2->pElements + i));
             if(r != 1)
             {
                 returnAux = 0;
                 break;
             }
         }
     }
     return returnAux;


    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order) //Ordena los objetos de la lista, el uso comparar pFunc
{
    int returnAux = -1, i, j;
     void *temp;

     if(pList != NULL && pFunc != NULL && (order == 1 || order == 0))
     {
         if(order == 1)
         {
             for(i = 0; i < pList->size - 1; i++)
             {
                 for(j = i + 1; j < pList->size; j++)
                 {
                     if(pFunc(*(pList->pElements + i), *(pList->pElements + j)) == 1)
                     {
                         temp = *(pList->pElements + i);
                         *(pList->pElements + i) = *(pList->pElements + j);
                         *(pList->pElements + j) = temp;
                     }
                 }
             }
         }
         else
         {
             for(i = 0; i < pList->size - 1; i++)
             {
                 for(j = i + 1; j < pList->size; j++)
                 {
                     if(pFunc(*(pList->pElements + i), *(pList->pElements + j)) == -1)
                     {
                         temp = *(pList->pElements + i);
                         *(pList->pElements + i) = *(pList->pElements + j);
                         *(pList->pElements + j) = temp;
                     }
                 }
             }
         }

         returnAux = 0;
     }

     return returnAux;
 }



/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)//Incrementa el nuemero de elementos en pList
{
    void* auxVoid=NULL;
    int returnAux = -1;

    if(pList!=NULL)
    {
        if (pList-> size == pList-> reservedSize )
        {
            auxVoid = realloc(pList->pElements, sizeof (void*)* (pList->size+10));
        }
        if (auxVoid != NULL)
        {
            pList->reservedSize+=10;
            pList->pElements=auxVoid;
            returnAux =0;

        }
    }




    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int returnAux = -1,i,aux;

    if(pList !=NULL && index>=0 && index <= pList->size)
    {
        if(pList->reservedSize== pList->size)
        {
            aux= resizeUp(pList);
        }

        if (aux==0)
        {
            for(i=pList->size ; i>=index ; i--)
            {
                *((pList->pElements) +(i+1)) = *((pList->pElements)+i);
            }
            returnAux = 0;
            pList->size++;
        }

    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1,i;

    if(pList !=NULL && index>=0 && index <= pList->size)
    {
        for(i=index ; i<pList->size ; i++)
        {
            pList->pElements[i] = pList->pElements[i+1];
        }
        returnAux = 0;
    }
    return returnAux;
}

