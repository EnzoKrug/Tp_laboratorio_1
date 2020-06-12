#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* proximoId)
{
    int retorno = -1;
    Employee* pEmployee;
    char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarSueldo[4096];
	char auxiliarHorasTrabajadas[4096];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarSueldo,auxiliarHorasTrabajadas) == 4)
            {
                pEmployee = employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarSueldo,auxiliarHorasTrabajadas);
                if(pEmployee != NULL)
                {
                    if(atoi(auxiliarId) >= *proximoId)
                    {
                        ll_add(pArrayListEmployee,pEmployee);
                        retorno = 0;
                        *proximoId = atoi(auxiliarId)+1;

                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int* proximoId)
{
    int retorno = -1;
    Employee* pEmployee;
    int i;
    char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarSueldo[4096];
	char auxiliarHorasTrabajadas[4096];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            i = 0;
            pEmployee = ll_get(pArrayListEmployee,i);
            if(fread(pEmployee,sizeof(Employee),1,pFile) == 1)
            {
                pEmployee = employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarSueldo,auxiliarHorasTrabajadas);
                if(pEmployee != NULL)
                {
                   if(atoi(auxiliarId) >= *proximoId)
                    {
                        ll_add(pArrayListEmployee,pEmployee);
                        retorno = 0;
                        *proximoId = atoi(auxiliarId)+1;
                    }
                }
                i++;
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }
    return retorno;
}
