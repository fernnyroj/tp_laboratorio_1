#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu(char textoMenu[],int min,int max)
{
    int opcion;
    printf("%s",textoMenu);
    scanf("%d",&opcion);

    while(opcion<min||opcion>max)
    {
        printf("ERROR, Reingrese:\n ");
        scanf("%d",&opcion);
    }
    return opcion;
}

void iniciarPersonas(sPersona* lista, int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        lista[i].estado=1;
    }
}

int estadoLibre(sPersona* lista, int largo)
{
    int i;
    int auxEstado=-1;
    for(i=0; i<largo; i++)
    {
        if(lista[i].estado==1)
        {
            auxEstado=i;
            break;
        }
    }
    return auxEstado;
}


void addPersona(sPersona* lista, int largo)
{
    char respuesta='s';
    do
    {
        int auxEstado;
        int auxLargo;
        auxEstado= estadoLibre(lista,largo);
        printf("Ingrese nombre \t");
        fflush(stdin);
        gets(lista[auxEstado].nombre);
        auxLargo=strlen(lista[auxEstado].nombre);
        while (auxLargo<0 || auxLargo>50 )
        {
            printf("#ERROR, El nombre no debe tener mas de 50 caracteres.\n");
            gets(lista[auxEstado].nombre);
            auxLargo=strlen(lista[auxEstado].nombre);
        }

        printf("Ingrese edad \t");
        fflush(stdin);
        scanf("%d",&lista[auxEstado].edad);
        while (lista[auxEstado].edad<1 || lista[auxEstado].edad>100)
        {
            printf("#ERROR, edad fuera de rango. \n Por favor reingrese \n");
            fflush(stdin);
            scanf("%d",&lista[auxEstado].edad);
        }
        printf("Ingrese DNI\t");
        fflush(stdin);
        scanf("%d",&lista[auxEstado].dni);
        while (lista[auxEstado].dni<5000000 || lista[auxEstado].dni>45000000)
        {
            printf("#ERROR, DNI fuera de rango. \n Por favor reingrese. \n");
            fflush(stdin);
            scanf("%d",&lista[auxEstado].dni);
        }

        printf("\nNOMBRE %s EDAD %d, DNI %d \n\n",lista[auxEstado].nombre,lista[auxEstado].edad,lista[auxEstado].dni);
        printf("Decea modificar los datos s/n\t");
        scanf("%s",&respuesta);
        lista[auxEstado].estado=0;
    }
    while(respuesta=='s');


}

int buscarDni(sPersona* lista,int dni,int largo)
{
    int i;
    int auxDisponible=-1;
    for(i=0; i<largo; i++)
    {
        if(lista[i].dni==dni)
        {
            auxDisponible=i;
            break;
        }
    }
    return auxDisponible;
}

void dniPersona(sPersona* lista, int largo)
{
    int auxDisponible;
    int auxDni;
    char opcion;
    printf("Ingrese Dni");
    fflush(stdin);
    scanf("%d",&auxDni);
    while (auxDni<5000000 || auxDni>45000000)
    {
        printf("#ERROR, DNI fuera de rango. \n Por favor reingrese. \n");
        fflush(stdin);
        scanf("%d",&auxDni);
    }
    auxDisponible=buscarDni(lista,auxDni,largo);
    if(auxDisponible>=0)
    {
        printf("Se encontro el DNI");
        printf("NOMBRE %s  , EDAD  %d DNI %d \n",lista[auxDisponible].nombre,lista[auxDisponible].edad,lista[auxDisponible].dni);;
        printf("Desea eliminar persona s/n \t");
        fflush(stdin);
        scanf("%c",&opcion);
        if (opcion=='s')
        {
            printf("Se elimino a %s. \n",lista[auxDisponible].nombre);
            lista[auxDisponible].estado=1;
        }
        else
        {
            printf("ACCION CANSELADA POR USUARIO \n");
        }
    }
    else
    {
        printf("El DNI ingresado no existe \n ");
    }

}

void ordenarPersona(sPersona* lista,int largo)
{
    sPersona backupLista;
    int i,j;
    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                strcpy(backupLista.nombre,lista[i].nombre);
                strcpy(lista[i].nombre,lista[j].nombre);
                strcpy(lista[j].nombre,backupLista.nombre);

                backupLista.edad=lista[i].edad;
                lista[i].edad=lista[j].edad;
                lista[j].edad=backupLista.edad;

                backupLista.dni=lista[i].dni;
                lista[i].dni=lista[j].dni;
                lista[j].dni=backupLista.dni;


            }
        }
    }
    for(i=0;i<largo;i++)
    {
       printf("NOMBRE\tEDAD\tDNI\n");
       printf("%s\t%d\t%d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
    }

}

void graficodePersona(sPersona* lista,int largo)
{
    int i;
    int max=0;
    int menor18=0;
    int entre19y35=0;
    int mayor35=0;
    for(i=0; i<largo; i++)
    {
        if(lista[i].edad<=18)
        {
            menor18++;
        }
        else if(lista[i].edad>=19 && lista[i].edad<=35)
        {
            entre19y35++;
        }
        else
        {
            mayor35++;
        }
    }
    if(menor18>entre19y35&&menor18>mayor35)
    {
        max=menor18;
    }
    else if (entre19y35>menor18&&entre19y35>mayor35)
    {
        max=entre19y35;
    }
    else
    {
        max=mayor35;
    }
    printf("GRAFICO SEGUN EDADES");
    printf("\n");
    for(i=0; i<max; i++)
    {

        if((max-i-1)<menor18)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }

        printf("\t");
        if((max-i-1)<entre19y35)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        printf("\t");
        if((max-i-1)<mayor35)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("<18\t19-35\t>35\n");
}

