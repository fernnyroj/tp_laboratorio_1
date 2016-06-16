#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "employee.h"


int main()
{

    int auxMenu, flag=0;
    char rta='s';
    char*  nombreArchivo="Libro1.csv";
    FILE* archivo = fopen(nombreArchivo,"r");
    if(archivo == NULL)
    {
        printf("\nError al abrir el archivo.\n");
        return -1;
    }
    else
    {
        printf("Archivo cargado\n \n");
    }
    ArrayList* pArrayEmployee = al_newArrayList();
    //Employee*auxEmployee;
    parserEmployee(archivo,pArrayEmployee);//

    fclose(archivo);

    while (rta=='s')
    {

        auxMenu=menu("\t 1-CARGAR EMPLEADO \n\t 2-BUCAR POR DNI \n\t 3-BORRAR EMPLEDO \n\t 4-EMPLEADOS POR ID DESCENDENTE\n\t 5-GENERAR NUEVO ARCHIVO EMPLEADO\n\t 6-BORRAR LISTADO \n\t 7-SALIR\n",1,7);
        switch(auxMenu)
        {
        case 1:
            printArrayListEmployee(pArrayEmployee);
            flag=1;
            system("pause");
            system("cls");
            break;

        case 2:
            if(flag==1)
            {
                buscarDni(pArrayEmployee);
            }
            else
            {
                printf("No se puede buscar Empleado sin cargar empleados.");
            }
            free(pArrayEmployee);
            system("pause");
            system("cls");
            break;

        case 3:
            if(flag==1)
            {
                removeEmployee(pArrayEmployee);
            }
            else
            {
                printf("No se puede eliminar sin cargar empleados.");
            }

            system("pause");
            system("cls");
            break;

        case 4:
              if(flag==1)
            {
                imprimirId(pArrayEmployee);removeEmployee(pArrayEmployee);
            }
            else
            {
                printf("No se puede eliminar sin cargar empleados.");
            }

            flag=1;
            system("pause");
            system("cls");
            break;

        case 5:

            if(flag==1)
            {
                if(nuevoArchEmpleado(pArrayEmployee)==0)
                {
                    printf("archivo creado con exito \n\n");
                }
                else
                {
                    printf("no se pudo generar archivo");
                }
            }
            else
            {
                printf("No se puede generar archivo sin cargar empleados\n");
            }
            system("pause");
            system("cls");
            break;

        case 6:
            if(flag==1)
            {
               borrarLista(pArrayEmployee);
            }
            else
            {
                printf("No se cargo ninguna lista\n");
            }
            system("pause");
            system("cls");
            break;

        case 7:
            free(pArrayEmployee);
            rta='n';
            free(pArrayEmployee);
            system("pause");
            system("cls");
            break;

        }
    }

    return 0;
}
