#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



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


/** \brief Inicializa los espacios para utilizar.
 *
 * \param  Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada.
 *
 */
void iniciarPelicula(EMovie* listaMovie, int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        listaMovie[i].isEmpty=1;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * @param Lista el array se pasa como parametro.
 * @param Largo el tamaño del array.
 * @return El primer indice disponible.
 */
int estadoLibre(EMovie* listaMovie, int largo)
{
    int i;
    int auxId=-1;
    for(i=0; i<largo; i++)
    {
        if(listaMovie[i].isEmpty==1)
        {
            auxId=i;
            break;
        }
    }
    return auxId;
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
    int auxScan;
    printf("%s",message);
    fflush(stdin);
    auxScan=scanf("%d",&aux);
    if (auxScan!=1)
    {
        return -1;
    }
    else if (aux<lowLimit || aux>hiLimit)
    {
        printf("%s",eMessage);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}
/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[10000];
    int auxScan;
    int auxLen;
    printf("%s",message);
    fflush(stdin);
    auxScan=scanf("%s",&aux);
    auxLen=strlen(aux);
    if (auxScan!=1)
    {
        return -1;
    }
    else if (auxLen<lowLimit || auxLen>hiLimit)
    {
        printf("%s",eMessage);
        return -1;
    }
    else
    {
        strcpy(input,aux);
        return 0;
    }
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie *listaMovie, int largo )
{
     int auxId, duracion,puntaje;
     char titulo,genero,descripcion, link, respuesta='s';

     while (respuesta=='s')
     {
         auxId= estadoLibre(listaMovie,largo);
     if (auxId>=0)
     {


        titulo= getString(&listaMovie[auxId].titulo,"Ingrese titulo de pelicula\t "," # ERROR el titulo debe tener de 1 a 20 caracteres",1,20 );
        genero= getString( &listaMovie[auxId].genero, "Ingrese genero de pelicula\t "," # ERROR el genero debe tener de 1 a 20 caracteres",1,20);
        duracion= getInt(&listaMovie[auxId].duracion,"Ingrese duracion de pelicula \t"," #ERROR la duracion debe ser de 1 a 400 minutos",1,400);
        descripcion= getString( &listaMovie[auxId].descripcion, "Ingrese descripcion de pelicula\t "," # ERROR la descripcion debe tener de 1 a 50 caracteres",1,50);
        puntaje= getInt(&listaMovie[auxId].puntaje,"Ingrese puntaje de pelicula\t "," #ERROR el puntaje debe ser de 1 a 5",1,5);
        link= getString( &listaMovie[auxId].linkImagen, "Ingrese lin de imagen de pelicula\t "," # ERROR el link debe tener de 1 a 20 caracteres",1,20);
     }
     printf("titulo %s , genero %s ,duracion %d ,puntaje %d ",listaMovie[auxId].titulo,listaMovie[auxId].genero,listaMovie[auxId].duracion,listaMovie[auxId].puntaje );
     printf("decea agregar otra pelicula s/n");
     scanf("%s",&respuesta);
     }

}


/** \brief Busca coincidencia por titulo.
 *
 * \param Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada. Funcion void.
 *
 */
int buscarPorTitulo(EMovie* listaMovie,char* titulo,int largo)
{
    int i;
    int auxReturn=-1;
    for(i=0; i<largo; i++)
    {
        if(strcmp(listaMovie[i].titulo,titulo)==0)
        {
            if(listaMovie[i].isEmpty==0)
            {
                auxReturn=i;
                break;
            }
            else
            {
                break;
            }

        }
    }
    return auxReturn;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie*listaMovie, int largo)
{
    int aux;
    char auxTitulo[50];
    char opcion;
    printf("Ingrese titulo \t");
    fflush(stdin);
    scanf("%s",&auxTitulo);
    aux=buscarPorTitulo(listaMovie,auxTitulo,largo);
    if(aux>=0)
    {
        printf("TITULO ENCONTRADO");
        printf("titulo\t descrpicon\tpuntaje\n");
        printf("%s\t%s\t%d\n",listaMovie[aux].titulo,listaMovie[aux].descripcion,listaMovie[aux].puntaje);
        printf("Desea Eliminarlo? s/n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=tolower(opcion);
        if (opcion=='s')
        {
            printf("pelicula Eliminado");
            listaMovie[aux].isEmpty=1;
        }
        else
        {
            printf("pelicula No Eliminado");
        }
    }
    else
    {
        printf("El titulo de pelicula no esta registrado");
    }

}
/*
void ordenarPeliculas(EMovie* listaMovie,int largo)
{
    EMovie backupLista;
    int i,j;
    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(strcmp(listaMovie[i].titulo,listaMovie[j].titulo)>0)
            {
                backupLista=listaMovie[i];
                listaMovie[i]=listaMovie[j];
                listaMovie[j]=backupLista;
            }
        }
    }
} */

/** \brief Guarda estructura de pelicula en archivo.
 *
 * \param Estructura pelicula.
 * \param Largo de array.
 * \return o si se cargo 1 si no.
 *
 */

int guardarEnArchivo(EMovie * lista,int largo)
{
    FILE *f;
    f=fopen("peliculas.dat","wb");
    if(f == NULL)
    {
        return 1;
    }
    fwrite(lista,sizeof(EMovie),largo,f);
    fclose(f);
    return 0;
}


/** \brief Carga estructura de pelicula en archivo.
 *
 * \param Estructura pelicula.
 * \param Largo de array.
 * \return o si se cargo 1 si no.
 *
 */
int cargaArchivo(EMovie *listaMovie,int largo)
{
    int flag = 0;
    FILE *f;
    f=fopen("peliculas.dat", "rb");
    if(f==NULL)
    {
        f= fopen("peliculas.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }
    if(flag ==0)
    {
        fread(listaMovie,sizeof(EMovie),largo,f);
    }
    fclose(f);
    return 0;
}


/** \brief Genera un archivo html.
 *
 * \param Estructura pelicula.
 * \param Nobre de archivo.
 * \return Nada,funcion void.
 *
 */

void generarPagina(EMovie listaMovie[], char nombre[],int largo)
{
    if(listaMovie!=NULL&&largo>0)
    {
        int flag=0;
        int i;
        if(guardarEnArchivo(listaMovie,largo))
        {
            printf("No se pudo abrir archivo");
            system("pause");
            system("cls");
        }
        else
        {
            printf("Se guardo el archivo");
            system("pause");
            system("cls");

            if(cargaArchivo(listaMovie,largo))
            {
                printf("No se pudo abrir el archivo");
                system("pause");
                system("cls");
            }
            else
            {
                printf("se realizo la carga\n");
                system("pause");
                system("cls");
            }
        }
        FILE *pHtml;
        pHtml=fopen(nombre,"w");
        if(pHtml==NULL)
        {
            pHtml= fopen("peliculas.dat", "wb");
            flag=1;
        }
        if(flag ==0)
        {
            fprintf(pHtml,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>");
            for(i=0;i<largo;i++)
            {
                if(listaMovie[i].isEmpty==0)
                {
                    fprintf(pHtml,"\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n				<ul>\n					<li>Genero:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duracion:%d</li>					\n				</ul>\n                <p>%s</p>\n            </article>\n",listaMovie[i].linkImagen,listaMovie[i].titulo,listaMovie[i].genero,listaMovie[i].puntaje,listaMovie[i].duracion,listaMovie[i].descripcion);
                }
            }
            fprintf(pHtml,"</div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>");
        }
        fclose(pHtml);
    }
}
