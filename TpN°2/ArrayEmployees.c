/**
 * ArrayEmployee.c
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

static void imprimirEmployee(sEmployee auxEmployee);
static int empl_modificarEmployee(int opcionModificar, sEmployee list[], int len, int auxIndex);



int empl_initEmployees(sEmployee list[], int len) //POR VALOR
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 0;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = TRUE; //Inicializar en -1 (todos los lugares estan libres)
        }
    }
    return retorno;
}

int empl_getEmptyIndex(sEmployee list[], int len) //POR VALOR //BUSCAR INDICE LIBRE
{
    int retorno = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == TRUE) //Encuentro la primer posicion libre
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int empl_addEmployee(sEmployee list[], int len, int* id, char name[], char lastName[], float salary, int sector, int indice) //POR VALOR //AGREGAR EMPLEADO
{
    int retorno = -1;
    sEmployee auxEmployee;

    if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
    {
        strncpy(auxEmployee.name,name,sizeof(auxEmployee.name));
        strncpy(auxEmployee.lastName,lastName,sizeof(auxEmployee.lastName));
        auxEmployee.salary = salary;
        auxEmployee.sector = sector;
        auxEmployee.isEmpty = FALSE; //Cambio el estado a 1 (ocupado), porque se cargo el empleado
        auxEmployee.idEmployee = *id;
        list[indice] = auxEmployee;
        *id = *id + 1;
        retorno = 0;
    }

    return retorno;
}

int empl_findEmployeeById(sEmployee list[], int len, int valorBuscado)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].idEmployee == valorBuscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static void imprimirEmployee(sEmployee auxEmployee)
{
    printf("| ID: %d | NOMBRE: %s | APELLIDO: %s | SALARIO: $%.3f | SECTOR: %d | ESTADO: %d |\n",auxEmployee.idEmployee,
                                                                                                 auxEmployee.name,
                                                                                                 auxEmployee.lastName,
                                                                                                 auxEmployee.salary,
                                                                                                 auxEmployee.sector,
                                                                                                 auxEmployee.isEmpty);
}

int empl_imprimirEmployee(sEmployee list[], int len)
{
    int retorno = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                imprimirEmployee(list[i]);
            }
        }
        retorno = 0;
    }
    return retorno;
}

void empl_menuModificar(sEmployee list[], int len , int auxIndex)
{
    int opcionModificar;
    do
    {
        printf("\nIngrese la opcion que desea modificar del Id ingresado: ");
        utn_getNumero(&opcionModificar,"\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n5. Volver al inicio\n",
                                       "\nERROR. Respuesta invalida, verifique las opciones y reingrese.\n",1,5,2);

        switch(opcionModificar)
        {
        case 1:
            if(empl_modificarEmployee(opcionModificar,list,len, auxIndex) == 0)
            {
                printf("\nSe modifico correctamente.");
            }
            break;
        case 2:
            if(empl_modificarEmployee(opcionModificar,list,len, auxIndex) == 0)
            {
                printf("\nSe modifico correctamente.");
            }
            break;
        case 3:
            if(empl_modificarEmployee(opcionModificar,list,len, auxIndex) == 0)
            {
                printf("\nSe modifico correctamente.");
            }
            break;
        case 4:
            if(empl_modificarEmployee(opcionModificar,list,len, auxIndex) == 0)
            {
                printf("\nSe modifico correctamente.");
            }
            break;
        }
    }while(opcionModificar != 5);
    printf("\nSe guardaron todos los cambios con exito!!");
}

static int empl_modificarEmployee(int opcionModificar, sEmployee list[], int len, int auxIndex)
{
    int retorno = -1;
    sEmployee auxList;

    if(list != NULL && len > 0 && opcionModificar < 4 && opcionModificar > 0 && list[auxIndex].isEmpty == FALSE)
    {
        switch(opcionModificar)
        {
        case 1:
            if(utn_getNombre(auxList.name,QTY_CARACTERES,"Ingrese el nuevo nombre del empleado: ",
                                                         "\nERROR. El nombre debe contener solo letras.",2) == 0)
            {
                retorno = 0;
                auxList.idEmployee = list[auxIndex].idEmployee;
                auxList.isEmpty = FALSE;
                strncpy(list[auxIndex].name,auxList.name,sizeof(list[auxIndex].name));
                break;
            }
            break;
        case 2:
            if(utn_getNombre(auxList.lastName,QTY_CARACTERES,"Ingrese el nuevo apellido del empleado: ",
                                                                 "\nERROR. El apellido debe contener solo letras.",2) == 0)
            {
                retorno = 0;
                auxList.idEmployee = list[auxIndex].idEmployee;
                auxList.isEmpty = FALSE;
                strncpy(list[auxIndex].lastName,auxList.lastName,sizeof(list[auxIndex].lastName));
                break;
            }
            break;
        case 3:
            if(utn_getNumeroFlotante(&auxList.salary,"Ingrese el nuevo salario del empleado [10-100000]: ",
                                                     "\nERROR. El salario debe ser entre 10 y 100000 y no contener letras.",
                                                                                             10,100000,2) == 0)
            {
                retorno = 0;
                auxList.idEmployee = list[auxIndex].idEmployee;
                auxList.isEmpty = FALSE;
                list[auxIndex].salary = auxList.salary;
                break;
            }
            break;
        case 4:
            if(utn_getNumero(&auxList.sector,"Ingrese el nuevo sector del empleado [1-6]: ",
                                             "\nERROR. El sector debe ser entre 1 y 6 y no contener letras.",1,6,2) == 0)
            {
                retorno = 0;
                auxList.idEmployee = list[auxIndex].idEmployee;
                auxList.isEmpty = FALSE;
                list[auxIndex].sector = auxList.sector;
                break;
            }
            break;
        }
    }
    return retorno;
}

int empl_removeEmployee(sEmployee list[], int len, int auxIndex)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[auxIndex].isEmpty == FALSE)
            {
                list[auxIndex].isEmpty = TRUE; //DOY DE BAJA LOGICA
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

void empl_menuOrdenar(sEmployee list[], int len)
{
    int order;
    do
    {
        printf("\nIngrese la opcion que desea mostrar: ");
        utn_getNumero(&order,"\n1. LISTAR EMPLEADOS EN TIEMPO DE CARGA\n2. LISTAR EMPLEADOS POR APELLIDO Y SECTOR \n3. LISTAR SUMA Y PROMEDIO DE LOS SALARIOS\n",
                             "\nERROR. Ingrese solo numeros [1-4]",1,4,2);

        switch(order)
        {
        case 1:
            empl_imprimirEmployee(list,len);
            break;
        case 2:
            printf("\n---LISTAR EMPLEADOS POR APELLIDO Y SECTOR---\n");
            do
            {
                utn_getNumero(&order,"\n1. DE FORMA ASCENDENTE\n2. DE FORMA DESCENDENTE \n3. VOLVER\n",
                     "\nERROR. Ingrese solo numeros [1-3]",1,3,2);

                switch(order)
                {
                case 1:
                    empl_sortEmployees(list,len,order);
                    empl_imprimirEmployee(list,len);
                    break;
                case 2:
                    empl_sortEmployees(list,len,order);
                    empl_imprimirEmployee(list,len);
                    break;
                }
            }while(order != 3);
            break;
        case 3:
            empl_salarioPromedio(list,len);
            break;
        }

    }while(order != 3);
}

void empl_sortEmployees(sEmployee list[], int len, int order)
{
    int i;
    int j;
    sEmployee buffer;
    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                   buffer  = list[i];
                   list[i] = list[j];
                   list[j] = buffer;
                }
                else
                {
                   if(strcmp(list[i].lastName,list[j].lastName)==0)
                   {
                       if(list[i].sector>list[j].sector)
                       {
                           buffer  = list[i];
                           list[i] = list[j];
                           list[j] = buffer;
                       }
                   }
                }
            }
        }
    }
    else if(order == 2)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)<0)
                {
                   buffer  = list[i];
                   list[i] = list[j];
                   list[j] = buffer;
                }
                else
                {
                   if(strcmp(list[i].lastName,list[j].lastName)==0)
                   {
                       if(list[i].sector<list[j].sector)
                       {
                           buffer  = list[i];
                           list[i] = list[j];
                           list[j] = buffer;
                       }
                   }
                }
            }
        }
    }
}

//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio

int empl_salarioPromedio(sEmployee list[], int len)
{
    int retorno = -1;
    int i;
    int contador = 0;
    float acumulador = 0;
    float promedio;
    int contadorEmployee;
    if(len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                contador++;
                acumulador+= list[i].salary;
            }
        }
        retorno = 0;
        promedio = acumulador/contador;
        printf("\nTOTAL DE LOS SALARIOS: %.3f \nPROMEDIO DE LOS SALARIOS: %.3f \n",acumulador,promedio);
        contadorEmployee = calcularMaximoPromedio(list,len,promedio);
        if(contadorEmployee > 0)
        {
            printf("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d\n",contadorEmployee);
        }
        else
        {
            printf("\nNO HAY NINGUN EMPLEADO QUE SUPERE EL SALARIO PROMEDIO\n");
        }
    }
    return retorno;
}

int calcularMaximoPromedio(sEmployee list[], int len, float promedioSalary)
{
    int retorno = -1;
    int i;
    int contador = 0;
    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].salary>promedioSalary && list[i].isEmpty == FALSE)
            {
                contador++;
            }
        }
        retorno = contador;
    }

    return retorno;
}

int empl_altaForzadaArray(sEmployee list[],int len, int auxIndice, int* id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;
	sEmployee bufferEmployee;

	if(len > 0 && auxIndice < len && auxIndice >= 0 && id != NULL)
	{
			strncpy(bufferEmployee.name,name,QTY_CARACTERES);
			strncpy(bufferEmployee.lastName,lastName,QTY_CARACTERES);
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			retorno = 0;
			bufferEmployee.idEmployee = *id;
			bufferEmployee.isEmpty = FALSE;
			list[auxIndice] = bufferEmployee;
			(*id)++;
	}
	return retorno;
}

