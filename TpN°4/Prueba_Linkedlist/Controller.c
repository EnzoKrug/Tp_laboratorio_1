#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* proximoId)
{
    int retorno = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {

        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            if(!parser_EmployeeFromText(pFile,pArrayListEmployee,proximoId))
            {
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* proximoId)
{
    int retorno = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        pFile = fopen(path,"rb");
        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee,proximoId))
            {
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmployee)
{
    int retorno = -1;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
    Employee* pEmployee;
    if(pArrayListEmployee != NULL && idEmployee >= 0)
    {
        if(!utn_getNombre(nombre,NOMBRE_LEN,"\nNombre del empleado?","\nERROR.",2) &&
           !utn_getNumero(&horasTrabajadas,"\nHoras trabajadas?","\nERROR.",1,250,2) &&
           !utn_getNumero(&sueldo,"\nSueldo del empleado? [1000/100000]","\nERROR.",1000,100000,2))
       {
           pEmployee = employee_newParametros(*idEmployee,nombre,horasTrabajadas,sueldo);
           if(pEmployee != NULL)
           {
                retorno = 0;
                ll_add(pArrayListEmployee,pEmployee);
                (*idEmployee)++;
           }
       }
    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;
    Employee* pEmployeeAux;
    pEmployeeAux = employee_new();
    int len;
    int opcion;
    int sueldo;
    int horasTrabajadas;
    char nombre[NOMBRE_LEN];
    int idEmployee;
    int indiceIdEmployee;
    char respuesta = 'n';
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            controller_ListEmployee(pArrayListEmployee);
            if(!utn_getNumero(&idEmployee,"\nIngrese el ID del empleado que desea modificar: ","\nERROR.",0,QTY_EMPLOYEE,2))
            indiceIdEmployee = employee_BuscarId(pArrayListEmployee,idEmployee);
            if(indiceIdEmployee >= 0)
            {
                printf("\nID ENCONTRADO!.");
                employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                pEmployee = ll_get(pArrayListEmployee,indiceIdEmployee);
                *pEmployeeAux = *pEmployee; //GUARDO UNA COPIA
                do
                {
                    opcion = menuModificar();
                    switch(opcion)
                    {
                    case 1:
                    if(!utn_getNombre(nombre,NOMBRE_LEN,"\nNombre del empleado?","\nERROR.",2))
                    {
                        if(!employee_setNombre(pEmployee,nombre))
                        {
                            printf("\nNombre modificado.");
                            employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                        }
                        else
                        {
                            printf("\nOcurrio un error al modificar el nombre.");
                        }
                    }
                    break;
                    case 2:
                    if(!utn_getNumero(&sueldo,"\nSueldo del empleado?","\nERROR.",1,QTY_SUELDO,2))
                    {
                        if(!employee_setSueldo(pEmployee,sueldo))
                        {
                            printf("\nSueldo modificado.");
                            employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                        }
                        else
                        {
                            printf("\nOcurrio un error al modificar el sueldo.");
                        }
                    }
                    break;
                    case 3:
                    if(!utn_getNumero(&horasTrabajadas,"\nHoras trabajadas?","\nERROR.",1,QTY_HORAS,2))
                    {
                        if(!employee_setHorasTrabajadas(pEmployee,horasTrabajadas))
                        {
                            printf("\nHoras trabajadas modificadas.");
                            employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                        }
                        else
                        {
                            printf("\nOcurrio un error al modificar las horas trabajadas.");
                        }
                    }
                    break;
                    case 4:
                        employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                        if(!utn_getChar(&respuesta,"\nEsta seguro que desea cancelar? [s/n] ","\ERROR.",'s','n',2))
                        {
                            *pEmployee = *pEmployeeAux;
                        }
                        else
                        {
                            printf("\nModificacion cancelada.");
                        }
                    break;
                    }

                }while(opcion!=5);
                retorno = 0;
            }
            else
            {
                printf("\nID no registrado.");
            }
        }
        else
        {
            printf("\nNo hay datos cargados para modificar.");
        }

    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int idEmployee;
     int indiceIdEmployee;
     char respuesta = 'n';
     if(pArrayListEmployee != NULL)
     {
         controller_ListEmployee(pArrayListEmployee);
         if(!utn_getNumero(&idEmployee,"\nIngrese el ID del empleado que desea eliminar: ","\nERROR.",0,QTY_EMPLOYEE,2))
         {
            indiceIdEmployee = employee_BuscarId(pArrayListEmployee,idEmployee);
            if(indiceIdEmployee >= 0)
            {
                printf("\nID ENCONTRADO!.");
                employee_PrintEmployee(pArrayListEmployee,indiceIdEmployee);
                if(!utn_getChar(&respuesta,"\nEsta seguro que desea cancelar? [s/n] ","\ERROR.",'s','n',2))
                {
                    ll_remove(pArrayListEmployee,indiceIdEmployee);
                    retorno = 0;
                }
                else
                {
                    printf("\nDar de baja cancelada.");
                }
            }
            else
            {
                printf("\nID NO REGISTRADO.");
            }
         }

     }
     return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;
    int len;
    int i;
    int id;
    int sueldo;
    int horasTrabjadas;
    char nombre[NOMBRE_LEN];
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            printf("\n\t%s%12s%12s%24s","ID","NOMBRE","SUELDO","HORAS_TRABAJADAS");
            printf("\n\t-----------------------------------------------------");
            retorno = 0;
            for(i=0;i<len;i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                employee_getId(pEmployee,&id);
                employee_getNombre(pEmployee,nombre);
                employee_getSueldo(pEmployee,&sueldo);
                employee_getHorasTrabajadas(pEmployee,&horasTrabjadas);
                printf("\n\t%d%12s%12d%18d",id,nombre,sueldo,horasTrabjadas);
            }
        }
        else
        {
            printf("\nNo se ingresaron datos para imprimir.");
        }
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opcion;
    int order;
    if(pArrayListEmployee != NULL)
    {
        do
        {
            opcion = menuOrdenar();
            switch(opcion)
            {
            case 1://POR ID
                if(!utn_getNumero(&order,"\n1. DESCENDENTE\n2. ASCENDENTE","\nERROR.",1,2,2))
                {
                    switch(order)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,employee_CompareById,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_CompareById,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    }
                }
                break;
            case 2: //POR NOMBRE
                if(!utn_getNumero(&order,"\n1. DESCENDENTE\n2. ASCENDENTE","\nERROR.",1,2,2))
                {
                    switch(order)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,employee_CompareByName,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_CompareByName,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    }
                }
            break;
            case 3: //POR SUELDO
                if(!utn_getNumero(&order,"\n1. DESCENDENTE\n2. ASCENDENTE","\nERROR.",1,2,2))
                {
                    switch(order)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,employee_CompareBySueldo,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_CompareBySueldo,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    }
                }
            break;
            case 4: //POR HORAS TRABAJADAS
                if(!utn_getNumero(&order,"\n1. DESCENDENTE\n2. ASCENDENTE","\nERROR.",1,2,2))
                {
                    switch(order)
                    {
                    case 1:
                        ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,(order-1));
                        controller_ListEmployee(pArrayListEmployee);
                        retorno = 0;
                        break;
                    }
                }
            break;
            }
        }while(opcion!=5);
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    Employee* pEmployee;
	int i;
	int len;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarSueldo;
	int auxiliarHorasTrabajadas;
	if(path != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        pFile = fopen(path,"w");

        if(pFile != NULL && len > 0)
        {
            for(i=0;i<len;i++)
			{
               pEmployee = ll_get(pArrayListEmployee,i);
               if(!employee_getId(pEmployee,&auxiliarId) &&
                  !employee_getNombre(pEmployee,auxiliarNombre) &&
                  !employee_getSueldo(pEmployee,&auxiliarSueldo) &&
                  !employee_getHorasTrabajadas(pEmployee,&auxiliarHorasTrabajadas))
               {
                   fprintf(pFile,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre,auxiliarSueldo,auxiliarHorasTrabajadas);
                    retorno = 0;
               }
			}
			fclose(pFile);
        }
    }
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;
    FILE* pFile;
    int len;
    int i;
    int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarSueldo;
	int auxiliarHorasTrabajadas;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"wb");
        len = ll_len(pArrayListEmployee);
        if(pFile != NULL && len > 0)
        {
            for(i=0;i<len;i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                if(!employee_getId(pEmployee,&auxiliarId) &&
                  !employee_getNombre(pEmployee,auxiliarNombre) &&
                  !employee_getSueldo(pEmployee,&auxiliarSueldo) &&
                  !employee_getHorasTrabajadas(pEmployee,&auxiliarHorasTrabajadas))
                {
                    fwrite(pEmployee,sizeof(Employee),1,pFile);
                    //printf("\nid: %d - nombre: %s",auxiliarId,auxiliarNombre);
                    retorno = 0;
                }
            }
            fclose(pFile);
        }
    }
    return retorno;
}

int menu(void)
{
    int opcion;
    printf("\n=====================================================================");
    printf("\n1. CARGAR DATOS DE EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)");
    printf("\n2. CARGAR DATOS DE EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO BINARIO)");
    printf("\n3. ALTA EMPLEADO");
    printf("\n4. MODIFICAR DATOS DEL EMPLEADO");
    printf("\n5. BAJA DEL EMPLEADO");
    printf("\n6. LISTAR EMPLEADOS");
    printf("\n7. ORDENAR EMPLEADOS");
    printf("\n8. GUARDAR DATOS DE EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO)");
    printf("\n9. GUARDAR DATOS DE EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO BINARIO)\n");
    printf("10. SALIR");
    printf("\n=====================================================================");

    utn_getNumero(&opcion,"\nIngrese una opcion: ","\nERROR.",1,10,2);
    return opcion;
}

int menuModificar(void)
{
    int opcion;
    printf("\n====MODIFICAR EMPLOYEE=====");
    printf("\n1. Nombre");
    printf("\n2. Salario");
    printf("\n3. Horas trabajadas");
    printf("\n4. Cancelar cambios");
    printf("\n5. Guardar cambios y salir");
    printf("\n===========================");

    utn_getNumero(&opcion,"\nIngrese una opcion: ","\nERROR.",1,5,2);
    return opcion;
}

int menuOrdenar(void)
{
    int opcion;
    printf("\n====ORDENAR LISTA EMPLOYEE=====");
    printf("\n1. Id");
    printf("\n2. Nombre");
    printf("\n3. Salario");
    printf("\n4. Horas trabajadas");
    printf("\n5. Guardar y salir");
    printf("\n===========================");

    utn_getNumero(&opcion,"\nIngrese una opcion: ","\nERROR.",1,5,2);
    return opcion;
}

