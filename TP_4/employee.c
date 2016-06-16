#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"
#include "employee.h"
/** \brief Crea un  menu.
 *
 * \param Texto de seleccion de menu.
 * \param Entero minimo de seleccion.
 * \param Entero maximo de seleccion.
 * \return Menu.
 *
 */
char menu(char textoMenu[],int min,int max)
{
    int opcion;
    printf("%s",textoMenu);
    scanf("%d",&opcion);

    while(opcion<min||opcion>max)
    {
        printf("ERROR, Reingrese :\n Seleccion de menu del 1-4 solo numeros\n");
        scanf("%d",&opcion);
    }
    return opcion;
}

/** \brief Crea un nuevo empleado.
 *
 * \param Paramettros para construir la estructura in dni,id.
 * \param char name, lastname,sector.
 * \return puntero a empleado.
 *
 */

Employee* newEmployee(int id, int dni, char name[],char lastName[],char sector[])
{

    Employee* returnAux;
    returnAux = (Employee*) malloc(sizeof(Employee));
    if(returnAux != NULL)
    {
        returnAux->id = id;
        returnAux-> dni = dni;
        strcpy(returnAux->name,name);
        strcpy(returnAux->lastName,lastName);
        strcpy(returnAux->sector,sector);
    }

    return returnAux;
}

/** \brief Carga estrucura de empleado a traves fde un archivo,
 *
 * \param puntero a archivo
 * \param puntero a arraylist
 * \return 0 si cargo -1 si no.
 *
 */

int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    int auxInt;
    int intId,intdni;
    char name[50];
    char lastName[50], sector[20];
    char trueFalse[32];
    char id [10], dni[10];
    Employee* auxEmpleado;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!(feof(pFile)))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", id,dni, name, lastName,sector, trueFalse);
            if(strcmp("true.",trueFalse)== 0)
            {
                intId = atoi(id);
                intdni=atoi(dni);
                auxEmpleado = newEmployee(intId,intdni, name, lastName,sector);
                auxInt = al_add(pArrayListEmployee, auxEmpleado);

                if(auxInt == -1)
                {
                    printf("ERROR");
                    break;
                }
            }
        }
    }
    else
    {
        printf("\n empleados no agregados no agregados.\n");
        free(pArrayListEmployee);
    }
}

/** \brief obtiene id de empleado
 *
 * \param puntero a void.
 * \return 0 si consigui id , -1 si no.
 *
 */

int obtenerId(void *empleado)
{
    int aux = -1;
    if(empleado != NULL)
    {
        aux = ((Employee*)empleado)->id;
        aux=0;
    }
    return aux;
}

/** \brief compara empleados por id.
 *
 * \param puntero a void
 * \param punero a vios
 * \return 1 si A es mayor a B , -1 si B es mayor a A , 0 si no logra comparar.
 *
 */

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{
    if(obtenerId(pEmployeeA) > obtenerId(pEmployeeB))
    {
        return 1;
    }

    if(obtenerId(pEmployeeA) < obtenerId(pEmployeeB))
    {
        return -1;
    }
    return 0;
}

/** \brief Imprime un empleado.
 *
 * \param puntero a empleado
 * \return no devueve nada.
 *
 */
void printEmployee(Employee* p)
{
    printf("\n %d\n %d\n %s\n %s\n %s\n\n",p->id,p->dni,p->name,p->lastName,p->sector);
}

/** \brief imprime arraya de empleados.
 *
 * \param puntero a empleado
 * \return no devuelve nada.
 *
 */
void printArrayListEmployee(ArrayList* lista)
{
    int i, auxlen;
    Employee* aux;
    for(i=0; i < lista->len(lista); i++)
    {
        aux = (Employee*)lista->get(lista,i);
        printEmployee(aux);
    }
    auxlen=lista->len(lista);
    printf("\ncantidad de empleados %d\n", auxlen);
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s", message);
    scanf("%d", &aux);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMessage);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }

}

/** \brief Compara empleado opr dni
 *
 * \param puntero a empleado
 * \param entero
 * \return -1 si no logro encontrar, i si lo encontro;
 *
 */

int compararDni(ArrayList*pArrayEmpleado,int pElement)
{
    int i, returnAux = -1,aux;
    {

        if(pArrayEmpleado != NULL && pElement != NULL)
        {
            for(i = 0; i < pArrayEmpleado->size; i++)
            {
                aux=al_get(pArrayEmpleado,i);
                if( ( ((Employee*)aux)->dni == pElement))
                {
                    returnAux = i;
                    break;
                }
            }
        }
    }
}

/** \brief busca empleado por dni.
 *
 * \param puntero a arraylist.
 * \return no retona nada.
 *
 */

void buscarDni(ArrayList*pArrayEmployee)
{
    int aux,busqueda,empleado, index;

    getInt(&aux, "Ingrese dni del empleado: ", "\nError. dni invalido.\n", 1, 45000000);
    busqueda=compararDni(pArrayEmployee,aux);
    if (busqueda!=-1)
    {

        empleado= (Employee*)pArrayEmployee->pop (pArrayEmployee, busqueda);

        printEmployee(empleado);
        index = pArrayEmployee-> indexOf(pArrayEmployee,empleado);
        printf("Ubicacion de empleado\n", index);

    }
    else if (busqueda==-1)
    {
        printf("No existe empleado con ese DNI\n");
    }
}

/** \brief compara empleados por id.
 *
 * \param puntero arraylist
 * \param elemento
 * \return -1 si no logra encontrarlo. i si lo encuenra.
 *
 */

int compararId(ArrayList*pArrayEmpleado,int pElement)
{
     int i, returnAux = -1,aux;

        if(pArrayEmpleado != NULL && pElement != NULL)
        {
            for(i = 0; i < pArrayEmpleado->size; i++)
            {
                aux=al_get(pArrayEmpleado,i);

                if( ( ((Employee*)aux)->id == pElement))
                {
                    returnAux = i;
                    break;
                }
            }
        }
}

/** \brief Elimina un empleado.
 *
 * \param puntero a Arraylist.
 * \return
 *
 */

int removeEmployee(ArrayList *pArrayEmployee)
{
    int aux,busqueda,empleado, index;
    printf("Si no recuerda ID busque con la opcion 2 en menu");
    if(pArrayEmployee != NULL)
    {

    getInt(&aux,"\n\nIngrese el ID a eliminar:\n\n","Por favor ingrese ID valido:\n\n",0,100);
    busqueda=compararId(pArrayEmployee,aux);
    if (busqueda!=1)
    {
        empleado = (Employee*)pArrayEmployee->pop(pArrayEmployee,busqueda);
        printEmployee(empleado);
        free(empleado);
        printf("Empleado eliminado \n\n");

    }
    else if (busqueda==-1)
    {
        pArrayEmployee->push(pArrayEmployee, aux, empleado);
        printf("\nEl empleado no fue eliminado.\n");
    }
       return -1;
    }
}



/** \brief borra el arraylist
 *
 * \param puntero a arraylist
 * \return no retorna nada
 *
 */

void borrarLista(ArrayList*pArrayEmployee)
{
    if(pArrayEmployee==NULL)
    {
        return -1;
    }

    if(pArrayEmployee->isEmpty(pArrayEmployee)!=0)
    {
        printf("No existen empleados cargados\n\n");
    }
    else
    {
        pArrayEmployee->clear(pArrayEmployee);
        printf("Se eliminaron todos los empleados\n\n");
    }
}

/** \brief clona Arraylist y ordena por id
 *
 * \param puntero a arraylis
 * \return no retorna nada
 *
 */

void imprimirId(ArrayList* pArrayEmployee)
{
    ArrayList* aux;
    if(pArrayEmployee != NULL)
    {
       aux = pArrayEmployee->clone(pArrayEmployee);
        printf("LISTA CLONADA\n");
        if(pArrayEmployee->containsAll(pArrayEmployee,aux))
        {
            printf("Se clono con todos los elementos\n");
        }

        else
        {
            printf("Faltan elementos a la lista");
        }

    aux->sort(aux, compareEmployee,1);
    printf("Lista Clonada Ordenada por ID descendente \r\n");
    printArrayListEmployee(aux);
}
}
/** \brief genera un nuevo archivo de empleados
 *
 * \param puntero a arraylist
 * \return 0 sise genero archivo, -1 si no se logro.
 *
 */

int nuevoArchEmpleado(ArrayList *pArraylistEmployee)
{
    FILE *farch = NULL;
    Employee*aux;
    int i;
    farch = fopen("archivo.scv","r");
    if(farch == NULL && pArraylistEmployee != NULL)
    {
        farch = fopen("archivo.csv","w");
        for(i=0; i < pArraylistEmployee->size; i++)
        {
            aux = (Employee *) pArraylistEmployee->get(pArraylistEmployee, i);
            fprintf(farch,"%d,%d,%s,%s,%s\n", aux->id,aux->dni, aux->name, aux->lastName, aux->sector);
        }
        fclose(farch);
        return 0;
    }
    fclose(farch);
    return -1;
}

