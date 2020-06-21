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
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas,auxiliarSueldo) == 4)
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
    int fin;
    char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarSueldo[4096];
	char auxiliarHorasTrabajadas[4096];
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            pEmployee = employee_new();
            fin = fread(pEmployee,sizeof(Employee),1,pFile);
            if(fin != 0)
            {
                ll_add(pArrayListEmployee,pEmployee);
                retorno = 0;
                //printf("\nid: %d nombre: %s \n",pEmployee->id,pEmployee->nombre,pEmployee->sueldo);
            }
        }while(!feof(pFile));
    }
    return retorno;
}

