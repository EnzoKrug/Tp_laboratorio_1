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
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

#endif // UTN_H_INCLUDED

