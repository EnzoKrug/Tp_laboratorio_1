/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


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

            if(!controller_loadFromText("dataa.csv",listaEmployee,&idEmployee))
            {
                printf("\nSe cargo el archivo exitosamente.");
            }
            else
            {
                printf("\nNo hay datos cargados en el archivo (modo texto).");
            }
            break;
        case 2:
            if(!controller_loadFromBinary("dataaBin.csv",listaEmployee,&idEmployee))
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
            if(!controller_saveAsText("dataa.csv",listaEmployee))
            {
                printf("\nSe guardaron los datos exitosamente en el archivo.");
            }
            else
            {
                printf("\nNo hay datos para ser guardados en el archivo (modo texto).");
            }
            break;
        case 9:
            if(!controller_saveAsBinary("dataaBin.csv",listaEmployee))
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




































