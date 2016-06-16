
#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList
{
    int size;
    void **pElements;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

} typedef ArrayList;
#endif


ArrayList* al_newArrayList(void);

int al_add(ArrayList* pList,void* pElement);

int al_deleteArrayList(ArrayList* pList);

int al_len(ArrayList* pList);

void* al_get(ArrayList* pList, int index);

int al_contains(ArrayList* pList, void* pElement);

int al_set(ArrayList* pList, int index,void* pElement);

int al_remove(ArrayList* pList,int index);

int al_clear(ArrayList* pList);

ArrayList* al_clone(ArrayList* pList);

int al_push(ArrayList* pList, int index, void* pElement);

int al_indexOf(ArrayList* pList, void* pElement);

int al_isEmpty(ArrayList* pList);

void* al_pop(ArrayList* pList,int index);

ArrayList* al_subList(ArrayList* pList,int from,int to);

int al_containsAll(ArrayList* pList,ArrayList* pList2);

int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order);

int resizeUp(ArrayList* pList);

int expand(ArrayList* pList,int index);

int contract(ArrayList* pList,int index);
int buscarElementos(ArrayList *pArrayEmpleado, void *pElement, int (*pFunc)(void*, void*));


// Private function
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);
//___________________
