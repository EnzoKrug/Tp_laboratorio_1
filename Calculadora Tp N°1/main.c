#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    float num1;
    float num2;
    char respuesta='s';

    do
    {
    printf("Ingrese el primer numero a operar: ");
    scanf("%f",&num1);
    printf("Ingrese el segundo numero a operar: ");
    scanf("%f",&num2);

    printf("Desea volver a ingresar los numeros? (s)");
    fflush(stdin);
    scanf("%c",&respuesta);

    }while(respuesta=='s');

    Menu(num1,num2);

    return 0;
}
