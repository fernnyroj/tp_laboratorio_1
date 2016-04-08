

/**
*\ suma. Realiza la suma de dos numeros, en este caso suma "x" con "y".
*\parametro 1. Declara el valor de "x" en float.
*\parametro 2.Declara el valor de "y" en float.
*\retorna variable auxiliar "result" en float que contiene el resultado de la suma entre "x" e "y".
*
*/


 float suma(float x,float y)
{
    float result;
    result= x + y ;
    return result;
}
/**
*\ resta. Realiza la resta de dos numeros, en este caso resta "x" con "y".
*\parametro 1. Declara el valor de "x" en float.
*\parametro 2.Declara el valor de "y" en float.
*\retorna variable auxiliar "result" en float que contiene el resultado de la resta entre "x" e "y".
*
*/

 float resta(float x,float y)
{
    float result;
    result= x - y ;
    return result;
}

/**
*\ suma. Realiza la multiplicacion de dos numeros, en este caso multiplicacion "x" con "y".
*\parametro 1. Declara el valor de "x" en float.
*\parametro 2.Declara el valor de "y" en float.
*\retorna variable auxiliar "result" en float que contiene el resultado de  la multiplicacion entre "x" e "y".
*
*/

 float multiplicacion(float x,float y)
{
    float result;
    result= x * y ;
    return result;
}

/**
*\ divicion. Realiza la divicion de dos numeros, en este caso divide "x" con "y".
*\parametro 1. Declara el valor de "x" en float.
*\parametro 2.Declara el valor de "y" en float.
*\retorna variable auxiliar "result" en float que contiene el resultado de la divicion entre "x" e "y".
*
*/

 float divicion(float x,float y)
{
    float result;
    result= x / y ;
    return result;
}

/**
*\ validacion de enteros. Realiza una verificacion si la varible "x" es entero o flotante.
*\parametro 1. Declara el valor de "x" en float.
*\ se declara una variable "y" al que sele asigna la parte entera de "x".
*\ se declara una variable "z" al que se le resta "y" menos "x".
*\ se condiciona "z" si es distinto de cero se imprime un error; si esigual a 0 retona "x".
*\retorna "z" si en condiconal "z" es distinto de cero.
*
*/

int validacionEnteros(float x)
{
    int y;

    float z;
    y = (int) x;
    z = y-x;
    if(z!=0)
      {
        printf(" ERROR MATEMATICO \n No se puede calcular Factorial de un numero decimal.\n");
      }
    else
    {
        return x;
    }

    return z;
}

/**
*\ factorial. Realiza el factorial del entero de "x".
*\parametro 1. Declara el valor de "x" en entero.
*\ si "x" es igual a 0 retorna 1; por definicion de factorial "0!=1"
*\ si "x" es distinto de 0 se declara un acumuladro inicializada en 1.
*\ ingresa en un ciclo for donde se acumula "x" de forma regrsiva.
*\retorna variable auxiliar fact cuando sale del ciclo for.
*
*/

int factorial(int x)
{
   int i;
   int fact = 1;
    if(x==0)
    {
        return 1;
    }

    for(i=1; i<=x ;i++)
    {
      fact=fact*i;
    }
     return fact;
}



