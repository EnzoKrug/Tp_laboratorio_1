#include "Funciones.h"


void Menu(float numero1, float numero2)
{
    float suma=0;
    float resta=0;
    float producto=1;
    float division=0;
    float factorial=1;
    int opcion;

    do
    {
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Factorial\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                suma=CargarSuma(numero1,numero2);
                printf(" El resultado de %.2f + %.2f es: %.2f\n",numero1,numero2, suma);
            break;
            case 2:
                resta=CargarResta(numero1,numero2);
                printf(" El resultado de %.2f - %.2f es: %.2f\n",numero1,numero2, resta);
            break;
            case 3:
                producto=CargarMultiplicacion(numero1,numero2);
                printf(" El resultado de %.2f * %.2f es: %.2f\n",numero1,numero2, producto);
            break;
            case 4:
                division=CargarDivision(numero1,numero2);
            break;
            case 5:
                factorial=CargarFactorial(numero1,numero2);
            break;
        }
    }while(opcion!=6);
}

float CargarSuma(float numA,float numB)
{
    float suma;
    suma=numA+numB;

    return suma;
}

float CargarResta(float numA,float numB)
{
    float resta;
    resta=numA-numB;

    return resta;
}

float CargarMultiplicacion(float numA,float numB)
{
    float multiplicar;
    multiplicar=numA*numB;

    return multiplicar;
}

float CargarDivision(float numA,float numB)
{
    float dividir;
    dividir=numA/numB;
    if(numA==0 || numB==0)
    {
        printf(" No se puede dividir por cero.\n");
    }
    else
    {
        printf("El resultado de %.2f / %.2f es: %.2f\n",numA,numB,dividir);
    }

    return dividir;
}

int CargarFactorial(float numA,float numB)
{
    int factorialA=1;
    int factorialB=1;
    int i;

    if(numA<0)
    {
        printf("No se puede sacar el factorial de %.2f. \n",numA);
    }
    else
    {
        for(i=1;i<=numA;i++)
        {
            factorialA=factorialA*i;

        }
        printf("El factorial de %.2f es: %d\n",numA,factorialA);
    }

    if(numB<0)
    {
        printf("No se puede sacar el factorial de %.2f. \n",numB);
    }
    else
    {
        for(i=1;i<=numB;i++)
        {
            factorialB=factorialB*i;

        }
        printf("El factorial de %.2f es: %d\n",numB,factorialB);
    }
    return factorialA, factorialB;
}

