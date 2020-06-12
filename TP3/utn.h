#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief
 *
 * \param pResultado char*
 * \param longitud int
 * \param mensaje char*
 * \param mensajeError char*
 * \param reintentos int
 * \return int
 *
 */
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/** \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud int Es la longitud del array resultado
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param reintentos int Cantidad de reintentos
 * \return int Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


int utn_getChar(char* pResultado, char mensaje[], char mensajeError[], char op1, char op2, int reintentos);

int utn_getStrLwr(char* cadena);


#endif // UTN_H_INCLUDED
