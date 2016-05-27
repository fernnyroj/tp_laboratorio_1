#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANTIDAD 2


int main()
{
    char cargarPersona='s';
    int auxEspacio;
    char seguir='s';
    int auxiliarMenu;
    int flag=0;

    sPersona  datosPersonas[CANTIDAD];

    iniciarPersonas(datosPersonas,CANTIDAD);

    while(seguir=='s')
    {
        auxiliarMenu=menu("\t1- Agregar persona\n \t2- Borrar persona\n \t3- Imprimir lista ordenada por  nombre\n \t4- Imprimir grafico de edades\n \t5- Salir\n",1,5);
        switch(auxiliarMenu)
            {
                case 1:


                    auxEspacio=estadoLibre(datosPersonas,CANTIDAD);
                    if (auxEspacio>=0 && auxEspacio)
                    {
                        addPersona(datosPersonas,CANTIDAD);

                    }
                    else
                    {
                        printf("No hay espacios disponibles \n");
                    }
                    flag=1;
                    system("pause");
                    system("cls");
                    break;
             case 2:
                 if (flag==1)
                 {
                    system("cls");
                    dniPersona(datosPersonas,CANTIDAD);
                 }
                 else
                 {
                     printf("No se ingreso ninguna persona para borrar\n");                }

                system("pause");
                system("cls");
                break;
            case 3:
                if (flag==1)
                 {

                    ordenarPersona(datosPersonas,CANTIDAD);

                 }
                 else
                 {
                     printf("No se ingreso ninguna persona para ordenar\n");
                 }
                system("pause");
                system("cls");
                break;
            case 4:
                if (flag==1)
                 {
                    graficodePersona(datosPersonas,CANTIDAD);
                 }
                 else
                 {
                     printf("No se ingreso ninguna persona para gaficar\n");
                 }
                system("pause");
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
            }
    }
    return 0;

}
