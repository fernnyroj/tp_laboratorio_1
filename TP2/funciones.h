
//#ifndef FUNCIONES_H_INCLUDED
//#define FUNCIONES_H_INCLUDED




typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}sPersona;

/** \brief Crea un  menu.
 *
 * \param Texto de seleccion de menu.
 * \param Entero minimo de seleccion.
 * \param Entero maximo de seleccion.
 * \return Menu.
 *
 */
char menu(char textoMenu[],int min,int max);


/** \brief Inicializa los espacios para utilizar.
 *
 * \param  Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada.
 *
 */
void iniciarPersonas(sPersona* lista, int largo);


/**
 * Obtiene el primer indice libre del array.
 * @param Lista el array se pasa como parametro.
 * @param Largo el tamaño del array.
 * @return El primer indice disponible.
 */
int EstadoLibre(sPersona* lista, int largo);


/** \brief Agrega persona.
 *
 * \param Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada. Funcion void.
 *
 */
void addPersona(sPersona* lista, int largo);


/** \brief
 *
 * \param Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada. Funcion void.
 *
 */
void dniPersona(sPersona* lista, int largo);



/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param largo el tamaño del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarDni(sPersona* lista, int dni,int largo);



/** \brief Ordena personas por orden alfabetico.
 *
 * \param Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada. Funcion void.
 *
 */
void ordenarPersona(sPersona* lista,int largo);



/** \brief Grfico de persona segun edad.
 *
 * \param Lista el array se pasa como parametro.
 * \param Largo el tamaño del array
 * \return No devuelve nada. Funcion void.
 *
 */
void graficodePersona(sPersona* lista,int largo);



