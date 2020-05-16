#include <stdio.h>
#include <stdlib.h>


/**
*    Una empresa requiere un sistema para administrar su nómina de empleados.
*    Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
*
*
*    El sistema deberá tener el siguiente menú de opciones:
*    1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
*    de Id. El resto de los campos se le pedirá al usuario.
*    2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
*    o Salario o Sector
*    3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
*    4. INFORMAR:
*    1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
*    2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*    NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
*    Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
*    carga de algún empleado.
*    Para la realización de este programa, se utilizará una biblioteca llamada “ArrayEmployees” que
*    facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se
*    detallan las funciones que esta biblioteca debe tener.
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_CARACTERES 51

int main()
{
    sEmployee arrayEmpleados[QTY_EMPLEADOS];
    int opcion;
    int indiceLugarLibre;
    int indiceARetornar;
    int flagDeParo = 0; //PARA NO CORRER NINGUNA OPCION HASTA QUE NO SE INGRESE DATOS
    char auxName[QTY_CARACTERES];
    char auxLastName[QTY_CARACTERES];
    float auxSalary;
    int auxSector;
    int idEmployee = 0;//Inicializamos el autoincremental

    printf("\n----SISTEMA DE ADMINISTRACION DE EMPLEADOS----\n");

    if(empl_initEmployees(arrayEmpleados,QTY_EMPLEADOS) == 0)
    {
        printf("INIT OK\n");
    }
    else
    {
        printf("INIT  ERROR\n");
    }

    if(!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,0,&idEmployee, "Juan", "Perez", 1000, 1) &&
        (!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,1,&idEmployee, "Martin", "Perez", 2000, 5)) &&
        (!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,2,&idEmployee, "Mariela", "Tondo", 8500,3)) &&
        (!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,3,&idEmployee, "Rocio", "Zelli",  4500, 6)) &&
        (!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,4,&idEmployee, "Franco", "Saucedo",5500,2)) &&
        (!empl_altaForzadaArray(arrayEmpleados,QTY_EMPLEADOS,5,&idEmployee, "Hernan", "Aleman", 500,2)))
     {
         printf("\nCarga Forzada OK!!");
         flagDeParo = 1;
     }

        do
        {
            utn_getNumero(&opcion,"\n1. DAR DE ALTA\n2. MODIFICAR\n3. DAR DE BAJA\n4. LISTAR EMPLEADOS\n5. SALIR\n",
                                  "ERROR. Reingrese entre los numeros que aparecen en pantalla [1-5]",1,5,2);

            switch(opcion)
            {
            case 1:
                printf("\n----DAR DE ALTA----\n");
                indiceLugarLibre = empl_getEmptyIndex(arrayEmpleados, QTY_EMPLEADOS);
                if(indiceLugarLibre >= 0)
                {
                    flagDeParo = 1;
                    utn_getNombre(auxName,QTY_CARACTERES,"\nIngrese el nombre del empleado: ",
                                                         "\nERROR. El nombre debe contener solo letras.",2);
                    utn_getNombre(auxLastName,QTY_CARACTERES,"\nIngrese el apellido del empleado: ",
                                                             "\nERROR. El nombre debe contener solo letras.",2);
                    utn_getNumeroFlotante(&auxSalary,"\nIngrese el salario del empleado [10-100000]: ",
                                                     "\nERROR. El salario debe ser entre 10 y 100000 y no contener letras.",
                                                                                                                10,100000,2);
                    utn_getNumero(&auxSector,"\nIngrese el numero de sector en el que esta el empleado [1-6]: ",
                                             "\nERROR. El sector debe ser entre 1 y 6 y no contener letras.",1,6,2);

                    if(empl_addEmployee(arrayEmpleados,QTY_EMPLEADOS,&idEmployee,auxName,auxLastName,auxSalary,auxSector,indiceLugarLibre) == 0)
                    {
                        printf("\nCarga realizada con exito.");
                    }
                }
                else
                {
                    printf("\nNO HAY MAS LUGARES PARA CARGAR.");
                }
                break;
            case 2:
                printf("\n----MODIFICAR----\n");
                if(flagDeParo == 0)
                {
                    printf("No se ingresaron datos para modificar.\n");
                }
                else
                {
                    empl_imprimirEmployee(arrayEmpleados,QTY_EMPLEADOS);
                    if(utn_getNumero(&idEmployee,"Ingrese el numero de Id del empleado que sea modificar: ",
                                                 "\nERROR. Numero de Id fuera de rango.",0,QTY_EMPLEADOS,2) == 0)
                    {
                        indiceARetornar = empl_findEmployeeById(arrayEmpleados,QTY_EMPLEADOS,idEmployee);
                        if(indiceARetornar >= 0)
                        {
                            printf("\nId %d encontrado con exito.",idEmployee);
                            empl_menuModificar(arrayEmpleados, QTY_EMPLEADOS,indiceARetornar);
                        }
                        else
                        {
                            printf("\nId %d no encontrado",idEmployee);
                        }
                    }
                }
                break;
            case 3:
                printf("\n----DAR DE BAJA----\n");
                if(flagDeParo == 0)
                {
                    printf("No se ingresaron datos para dar de baja.\n");
                }
                else
                {
                    empl_imprimirEmployee(arrayEmpleados,QTY_EMPLEADOS);
                    if(utn_getNumero(&idEmployee,"\nIngrese el numero de Id del empleado que desea dar de baja: ",
                    "\nERROR. El Id del empleado debe contener solo numeros [0-1000].",0,QTY_EMPLEADOS,2) == 0)
                    {
                        indiceARetornar = empl_findEmployeeById(arrayEmpleados,QTY_EMPLEADOS,idEmployee);
                        if(indiceARetornar >= 0)
                        {
                            if(empl_removeEmployee(arrayEmpleados,QTY_EMPLEADOS,indiceARetornar) == 0)
                            {
                                printf("\nSe elimino al empleado con exito!!");
                            }
                            else
                            {
                                printf("\nId %d no encontrado",idEmployee);
                            }
                        }
                    }
                }
                break;
            case 4:
                printf("\n----LISTAR EMPLEADOS----\n");
                if(flagDeParo == 0)
                {
                    printf("No se ingresaron datos para modificar.\n");
                }
                else
                {
                   empl_menuOrdenar(arrayEmpleados,QTY_EMPLEADOS);
                }
                break;
            }
        }while(opcion != 5);

    return 0;
}

