
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
}EMovie;


char menu(char textoMenu[],int min,int max);
void iniciarPelicula(EMovie* listaMovie, int largo);
int estadoLibre(EMovie* listaMovie, int largo);
int getInt(int *imput,char message[],char eMessage[], int lowLimit, int hiLimit);
int getString(char*imput,char message[],char eMessage[], int lowLimit, int hiLimit);
void agregarPelicula(EMovie* listaMovie, int largo);
int buscarPorTitulo(EMovie* listaMovie,char titulo[50],int largo);
int borrarPelicula(EMovie*lista, int largo);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
