#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    float a ;
    float b;
    float resultSum;
    float resultRest;
    float resultMulti;
    float resultDivi;
    int resultFacto;
    int flag1=0;
    int flago2=0;

    while(seguir=='s')
    {
        printf("                               \n");
        printf("                               \n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("                               \n");
        printf("                               \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese primer operador");
                scanf("%f",&a);
                flag1=1;
                if(flag1==1)
                {
                    printf("el numero A es %.4f \n",a);
                }
                printf("                               \n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Ingrese segundo operador");
                scanf("%f",&b);
                flago2=1;
                if (flago2==1)
                {
                    printf("El numero B es %f \n",b);

                }
                printf("                               \n");
                system("pause");
                system("cls");
                break;
            case 3:
                if (flag1==1&& flago2==1)
                {

                    resultSum=suma(a,b);
                    printf("La SUMA entre %.4f y %.4f es %.4f \n", a,b,resultSum);

                }
                    else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la suma \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la suma.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para sumar \n");
                        }

                system("pause");
                system("cls");
                break;
            case 4:

                if (flag1==1 && flago2==1)
                {
                     resultRest=resta(a,b);
                     printf("La RESTA entre %.4f y %.4f es %.4f \n", a,b,resultRest);
                }
                else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la resta \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la resta.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para restar \n");
                        }

                system("pause");
                system("cls");
                break;
            case 5:

                if (flag1==1&& flago2==1)
                {
                      if(b!=0)
                      {
                        resultDivi=divicion(a,b);
                        printf("La DIVICION entre %.4f y %.4f es %.4f \n", a,b,resultDivi);
                      }
                     else
                     {
                       printf("#ERROR MATEMATICO \n");
                       printf("No existe la divicion por 0. \n");
                     }
                }
                else if(flag1==1 && flago2==0)
                {
                    printf("No se pudo realizar la divicion \n Por favor ingrese valor B \n");
                }
                   else if (flag1==0 && flago2==1)
                   {
                        printf("No se pudo realizar la divicion.\n Por favor ingrese valor de A \n");
                    }
                    else if(flag1==0 && flago2==0)
                    {
                           printf("No se ingresaron valores de A y B para dividir \n");
                    }

                system("pause");
                system("cls");
                break;
            case 6:
                if (flag1==1&& flago2==1)
                {
                      resultMulti=multiplicacion(a,b);
                      printf("La MULTIPLICION entre %.4f y %.4f es %.4f \n", a,b,resultMulti);
                }
                 else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la multiplicaicon \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la multiplicacion.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para multiplicar \n");
                        }

                system("pause");
                system("cls");
                break;
            case 7:
            if (flag1==1)
            {
               if  (a<0)
               {
                    printf("ERROR MATEMATICO \n");
                    printf("No existe factorial de numeros negativos\n");
               } else if (a>=0 && a<33)
                   {
                      a=validacionEnteros(a);
                      resultFacto= factorial(a);
                      printf("El Factorial de %.4f es %d \n",a,resultFacto);
                   }
                    else if (a>=33)

                    {
                         printf("El numero ingresado exede el rango \n");
                         printf(" Por favor ingrese un numero entre 0 y 32 \n");
                    }
            }
            else
            {
                printf("Ingrese un valor de A \n");
            }
                system("pause");
                system("cls");
                break;
            case 8:
            if (flag1==1&& flago2==1)
                {

                    resultSum=suma(a,b);
                    printf("La SUMA entre %.4f y %.4f es %.4f \n", a,b,resultSum);

                }
                    else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la suma \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la suma.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para sumar \n");
                        }


              if (flag1==1 && flago2==1)
                {
                     resultRest=resta(a,b);
                     printf("La RESTA entre %.4f y %.4f es %.4f \n", a,b,resultRest);
                }
                   else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la resta \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la resta.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para restar \n");
                        }
              if (flag1==1&& flago2==1)
              {
                      if(b!=0)
                      {
                        resultDivi=divicion(a,b);
                        printf("La DIVICION entre %.4f y %.4f es %.4f \n", a,b,resultDivi);
                      }
                     else
                      {
                       printf("#ERROR MATEMATICO \n");
                       printf("No existe la divicion por 0. \n");
                      }
              }
               else if(flag1==1 && flago2==0)
               {
                  printf("No se pudo realizar la divicion \n Por favor ingrese valor B \n");
                }
                  else if (flag1==0 && flago2==1)
                  {
                    printf("No se pudo realizar la divicion.\n Por favor ingrese valor de A \n");
                   }
                    else if(flag1==0 && flago2==0)
                     {
                        printf("No se ingresaron valores de A y B para dividir \n");
                      }

             if (flag1==1&& flago2==1)
                {
                      resultMulti=multiplicacion(a,b);
                      printf("La MULTIPLICION entre %.4f y %.4f es %.4f \n", a,b,resultMulti);
                }
                 else if(flag1==1 && flago2==0)
                     {
                        printf("No se pudo realizar la multiplicaicon \n Por favor ingrese valor B \n");
                     }
                      else if (flag1==0 && flago2==1)
                      {
                        printf("No se pudo realizar la multiplicacion.\n Por favor ingrese valor de A \n");
                      }
                        else if(flag1==0 && flago2==0)
                        {
                           printf("No se ingresaron valores de A y B para multiplicar \n");
                        }
              if (flag1==1)
            {

               a=validacionEnteros(a);
               if  (a<0)
               {
                    printf("ERROR MATEMATICO \n");
                    printf("No existe factorial de numeros negativos\n");
               } else if (a>=0 && a<33)
                   {
                      resultFacto= factorial(a);
                      printf("El Factorial de %.4f es %d \n",a,resultFacto);
                   }
                    else if (a>=33)

                    {
                         printf("El numero ingresado exede el rango \n");
                         printf(" Por favor ingrese un numero entre 0 y 32 \n");
                    }
            }
            else
            {
                printf("Ingrese un valor de A \n");
            }

             system("pause");
             system("cls");
             break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
        }

