#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmployee;
    listaEmployee = ll_newLinkedList();
    int idEmployee = 0;
    do
    {
        option = menu();

        switch(option)
        {
        case 1:

            if(!controller_loadFromText("data.csv",listaEmployee,&idEmployee))
            {
                printf("\nSe cargo el archivo exitosamente.");
            }
            else
            {
                printf("\nNo hay datos cargados en el archivo (modo texto).");
            }
            break;
        case 2:
            if(!controller_loadFromBinary("dataBin.csv",listaEmployee))
            {
                printf("\nSe cargo el archivo binario exitosamente.");
            }
            else
            {
                printf("\nNo hay datos cargados en el archivo (modo binario).");
            }
            break;
        case 3:
                if(!controller_addEmployee(listaEmployee,&idEmployee))
                {
                    printf("\nSe cargo exitosamente.");
                }
                else
                {
                    printf("\nOcurrio un error al agregar.");
                }
            break;
        case 4:
            if(!ll_isEmpty(listaEmployee))
            {
                if(!controller_editEmployee(listaEmployee))
                {
                    printf("\nSe modifico exitosamente.");
                }
                else
                {
                    printf("\nOcurrio un error al modificar.");
                }
            }
            else
            {
                printf("No hay empleados cargados para interactuar.");
            }
            break;
        case 5:
            if(!ll_isEmpty(listaEmployee))
            {
                if(!controller_removeEmployee(listaEmployee))
                {
                    printf("\nSe elimino exitosamente.");
                }
                else
                {
                    printf("\nOcurrio un error al borrar.");
                }
            }
            else
            {
                printf("No hay empleados cargados para interactuar.");
            }
            break;
        case 6:
            if(!ll_isEmpty(listaEmployee))
            {
                if(!controller_ListEmployee(listaEmployee))
                {
                    printf("\nSe listo correctamente");
                }
                else
                {
                    printf("\nOcurrio un error al listar.");
                }
            }
            else
            {
                printf("No hay empleados cargados para interactuar.");
            }
            break;
        case 7:
            if(!ll_isEmpty(listaEmployee))
            {
                if(!controller_sortEmployee(listaEmployee))
                {
                    printf("\nSe ordeno correctamente");
                }
                else
                {
                    printf("\nOcurrio un error al ordenar.");
                }
            }
            else
            {
                printf("No hay empleados cargados para interactuar.");
            }
            break;
        case 8:
            if(!controller_saveAsText("data.csv",listaEmployee))
            {
                printf("\nSe guardaron los datos exitosamente en el archivo.");
            }
            else
            {
                printf("\nNo hay datos para ser guardados en el archivo (modo texto).");
            }
            break;
        case 9:
            if(!controller_saveAsBinary("dataBin.csv",listaEmployee))
            {
                printf("\nSe guardaron los datos exitosamente en el archivo binario.");
            }
            else
            {
                printf("\nNo hay datos para ser guardados en el archivo (modo binario).");
            }
            break;
        }
    }while(option != 10);
    return 0;
}


