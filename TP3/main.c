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
    /*int option;
    LinkedList* listaEmployee = ll_newLinkedList();
    int size;
    Employee* aux;
    int i;

    Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);



    size = ll_len(miLista);
    printf("\nsize : %d",size);


    ll_sort(miLista,employee_CompareById,0);

    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("\n%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }*/
/*
   printf("Remuevo 1\n");

    ll_remove(miLista, 1);

    size = ll_len(miLista);
    for(i=0; i<size; i++)
    {
        aux =(Employee*) ll_get(miLista, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);

    }

    printf("El indice de e2 es: %d\n", ll_indexOf(miLista,e3));
*/
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     .3. Alta de empleado
     .4. Modificar datos de empleado
     .5. Baja de empleado
     .6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    .10. Salir
*****************************************************/
    int option;
    LinkedList* listaEmployee;
    listaEmployee = ll_newLinkedList();
    int idEmployee = 0;
/*
    Employee* e1 = (Employee*) malloc(sizeof(Employee));
    Employee* e2 = (Employee*) malloc(sizeof(Employee));
    Employee* e3 = (Employee*) malloc(sizeof(Employee));

    e1->id = 5;
    e1->horasTrabajadas = 10;
    strcpy(e1->nombre,"Juan");
    e1->sueldo = 10000;

    e2->id = 1;
    e2->horasTrabajadas = 15;
    strcpy(e2->nombre,"Martin");
    e2->sueldo = 15000;

    e3->id = 3;
    e3->horasTrabajadas = 10;
    strcpy(e3->nombre,"Aria");
    e3->sueldo = 20000;

    ll_add(listaEmployee, e1);
    ll_add(listaEmployee, e2);
    ll_add(listaEmployee, e3);*/
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
            if(!controller_loadFromBinary("data.csv",listaEmployee,&idEmployee))
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
            if(!controller_saveAsBinary("data.csv",listaEmployee))
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


