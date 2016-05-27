#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 100



int main()
{
    char seguir='s';
    int opcion, flag=0;
    EMovie movies[MAX];
    iniciarPelicula(movies,MAX);
    cargaArchivo(movies, MAX);
    while(seguir=='s')
    {
       opcion = menu( "\t 1- Agregar pelicula\n\t 2- Borrar pelicula\n\t 3- Generar pagina web\n\t 4- Salir\n",1,4);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movies, MAX);
                flag=1;
                system("pause");
                system("cls");
                break;
            case 2:
                if(flag==1)
                {
                   borrarPelicula(movies,MAX);
                }
                else
                {
                    printf("debe ingresar almenos 1 pelicula para borrar");
                }

                system("pause");
                system("cls");
                break;
            case 3:
                if (flag==1)
                {
                    generarPagina(movies,"lista peliculas",MAX);
                }
                else
                {
                    printf("debe ingresar pelicula para generar pagina");
                }
                system("pause");
                system("cls");
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
