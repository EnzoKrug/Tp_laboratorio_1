/*
*
*
* FUNCIONES DE VALIDACION
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena, int longitud);
static int getNombre(char* pResultado, int longitud);
static int esDescripcion(char* cadena, int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int getDni(char* pResultado, int longitud);


/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int getString(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096]; //ERROR QUE SE VA A RESOLVER MAS ADELANTE
    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin); // fflush o __fpurge
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
            }
            if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Obtiene un string valido como nombre
 *
 * \param pResultado char* Puntero al espacio de mmemoria donde se dejara el resultado de la funcion
 * \param longitud int Es el limite de elementos del array
 * \return int Retorna 0 (EXITO) si se obtiene un nombre y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL && longitud > 0)
    {
        if(getString(buffer,sizeof(buffer)) == 0 &&
           esNombre(buffer,sizeof(buffer)) &&
           strnlen(buffer,sizeof(buffer)) < longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int esNombre(char* cadena, int longitud)
{
    int i;
    int retorno  = -1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0;cadena[i] != '\0' && i < longitud;i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
            {
                retorno = 0; //si esta fuera del rango de las letras
                break;
            }
        }
    }
    return retorno;
}

int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos = -1)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}

/** \brief
 *
 * \param pResultado char*
 * \param longitud int
 * \return int
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL && longitud >0)
    {
        if(getString(buffer,sizeof(buffer)) == 0 &&
           esDescripcion(buffer,sizeof(buffer))  &&
           strnlen(buffer,sizeof(buffer)) < longitud)
        {
            strncpy(pResultado,buffer,longitud);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param cadena char*
 * \param longitud int
 * \return int
 *
 */
static int esDescripcion(char* cadena, int longitud)
{
    int i;
    int retorno = -1;

    if(cadena != NULL && longitud > 0)
    {
        for(i=0;cadena[i] != '\0' && i < longitud;i++)
        {
            if(cadena[i] < ' ' || cadena[i] > '~') //ver caracteres permitidos en la tabla ASCII
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos = -1)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}


//=========================================================================//
/**
 * \brief Ordena el array de tipo int ingresado de manera descenciente optimizado
 *  (sacando aquellas iteraciones que ya fueron ordenadas)
 * \param mensaje[] Es el mensaje a mostrar antes del array
 * \param arrayParametro[] Es el array que se muestra
 * \param tam Es el limite de elementos del array
 * \return El numero de Iteraciones si Ok o -1 para indicar un error
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[50];
    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena[] Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena)
{
    int i = 0;
    int retorno = -1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
        {
            retorno = 0;
            *pResultado = bufferInt;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos >= 0);
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena[] Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(getString(buffer,sizeof(buffer)) == 0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena[] Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
    int i;
    int retorno = 1;
    int contadorPuntos = 0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0 ; cadena[i] != '\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos >= 0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
//=========================================================================//
/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int utn_getChar(char* pResultado, char mensaje[], char mensajeError[], char op1, char op2, int reintentos)
{
    int retorno = -1;
    if(pResultado != NULL)
    {
        while(reintentos = -1)
        {
            reintentos--;
            printf("%s",mensaje);
            scanf("%c", pResultado);
            if(*pResultado == op1 || *pResultado == op2)
            {
                retorno = 0;
                break;
            }
            printf("%s", mensajeError);
            scanf("%c", pResultado);
        }
    }
    return retorno;
}

int utn_getStrLwr(char* cadena)
{
    int retorno = -1;
    int i;
    if(cadena != NULL)
    {
        retorno = 0;
        i = 0;
        while(cadena[i] != '\0')
        {
            cadena[i] = tolower(cadena[i]);
            i++;
        }
    }
    return retorno;
}


