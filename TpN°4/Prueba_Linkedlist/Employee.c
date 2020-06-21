#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if( employee_setIdTxt(this,idStr) == -1 ||
            employee_setNombre(this,nombreStr) == -1 ||
            employee_setHorasTrabajadasTxt(this,horasTrabajadasStr) == -1 ||
            employee_setSueldoTxt(this,sueldoStr) == -1)
        {
            employee_delete(this);
            this = NULL;
        }
    }
    return this;
}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* this = NULL;
    this = employee_new();
    if(this != NULL && nombre != NULL && horasTrabajadas > 0 && sueldo > 0 && id >= 0)
    {
        if( employee_setId(this,id) == -1 ||
            employee_setNombre(this,nombre) == -1 ||
            employee_setHorasTrabajadas(this,horasTrabajadas) == -1 ||
            employee_setSueldo(this,sueldo) == -1)
        {
            employee_delete(this);
            this = NULL;
        }
    }
    return this;
}

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        free(this);
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int employee_setSueldoTxt(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        if(esNumerica(sueldo,QTY_SUELDO))
        {
            retorno = 0;
            employee_setSueldo(this,atoi(sueldo));
        }
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo > 0)
    {
        retorno = 0;
        this->sueldo = sueldo;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

int employee_setIdTxt(Employee* this,char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        if(esNumerica(id,QTY_EMPLOYEE))
        {
            retorno = 0;
            employee_setId(this,atoi(id));
        }
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        if(esNumerica(horasTrabajadas,QTY_HORAS))
        {
            retorno = 0;
            employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
        }
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas > 0)
    {
            retorno = 0;
            this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/*****************************************************************/
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/****************************************************************/
int employee_BuscarId(LinkedList* pArrayListEmployee, int idEmployee)
{
    int retorno = -1;
    Employee* pEmployee;
    int len;
    int i;
    int auxIdEmployee;
    if(pArrayListEmployee != NULL && idEmployee >= 0)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(i=0;i<len;i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(pEmployee,&auxIdEmployee);
                if(auxIdEmployee == idEmployee)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int employee_PrintEmployee(LinkedList* pArrayListEmployee,int indice)
{
    int retorno = -1;
    Employee* pEmployee;
    int auxId;
    char auxNombre[NOMBRE_LEN];
    int auxSueldo;
    int auxHorasTrabjadas;
    if(pArrayListEmployee != NULL && indice >= 0)
    {
        pEmployee = ll_get(pArrayListEmployee,indice);
        employee_getId(pEmployee,&auxId);
        employee_getNombre(pEmployee,auxNombre);
        employee_getSueldo(pEmployee,&auxSueldo);
        employee_getHorasTrabajadas(pEmployee,&auxHorasTrabjadas);
        printf("\n\t%s%12s%12s%24s","ID","NOMBRE","SUELDO","HORAS_TRABAJADAS");
        printf("\n\t-----------------------------------------------------");
        printf("\n\t%d%12s%12d%18d",auxId,auxNombre,auxSueldo,auxHorasTrabjadas);
        retorno = 0;
    }
    return retorno;
}

int employee_CompareByName(void* item1, void* item2)
{
    int retorno = 0;
    Employee* e1;
    Employee* e2;
    char nombre1[NOMBRE_LEN];
    char nombre2[NOMBRE_LEN];
    if(item1 != NULL && item2 != NULL)
    {
        e1 = (Employee*) item1;
        e2 = (Employee*) item2;
        if(!employee_getNombre(e1,nombre1) &&
           !employee_getNombre(e2,nombre2))
        {
            if(strncmp(nombre1,nombre2,NOMBRE_LEN) > 0)
            {
                retorno = 1;
            }
            else
            {
                if(strncmp(nombre1,nombre2,NOMBRE_LEN) < 0)
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

int employee_CompareById(void* item1, void* item2)
{
    int retorno = 0;
    Employee* e1;
    Employee* e2;
    int id1;
    int id2;
    if(item1 != NULL && item2 != NULL)
    {
        e1 = (Employee*) item1;
        e2 = (Employee*) item2;
        if(!employee_getId(e1,&id1) &&
           !employee_getId(e2,&id2))
        {
            if(id1 > id2)
            {
                retorno = 1;
            }
            else
            {
                if(id1 < id2)
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

int employee_CompareBySueldo(void* item1, void* item2)
{
    int retorno = 0;
    Employee* e1;
    Employee* e2;
    int sueldo1;
    int sueldo2;
    if(item1 != NULL && item2 != NULL)
    {
        e1 = (Employee*) item1;
        e2 = (Employee*) item2;
        if(!employee_getSueldo(e1,&sueldo1) &&
           !employee_getSueldo(e2,&sueldo2))
        {
            if(sueldo1 > sueldo2)
            {
                retorno = 1;
            }
            else
            {
                if(sueldo1 < sueldo2)
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

int employee_CompareByHorasTrabajadas(void* item1, void* item2)
{
    int retorno = 0;
    Employee* e1;
    Employee* e2;
    int horasTrabajdas1;
    int horasTrabajdas2;
    if(item1 != NULL && item2 != NULL)
    {
        e1 = (Employee*) item1;
        e2 = (Employee*) item2;
        if(!employee_getHorasTrabajadas(e1,&horasTrabajdas1) &&
           !employee_getHorasTrabajadas(e2,&horasTrabajdas2))
        {
            if(horasTrabajdas1 > horasTrabajdas2)
            {
                retorno = 1;
            }
            else
            {
                if(horasTrabajdas1 < horasTrabajdas2)
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}



