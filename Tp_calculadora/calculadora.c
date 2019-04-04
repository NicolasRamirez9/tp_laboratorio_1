#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

float ingresarValor(void);
float sumaDeValores(float* , float*);
float restaDeValores(float* , float*);
float multiplicacionDeValores(float* , float*);
float divisionDeValores(float* , float*);
float factorialDeValores(float*);

int calculadora ()
{
    int opciones;
    float primerValor = 0;
    float segundoValor = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    float resultadoFactoreoUno;
    float resultadoFactoreoDos;
    int flagValidar = 0;

    do
    {
        system ("color 4f");

        printf("\n *------------------CALCULADORA-------------------* \n");

        printf("\n *                                                *");

        printf ("\n *   1. Ingresar 1er operando (A = %.2f).         *\n" , primerValor);

        printf("\n *                                                *");

        printf ("\n *   2. Ingresar 2do operando (B = %.2f).         *\n" , segundoValor);

        printf("\n *                                                *");

        printf ("\n *   3. Calcular todas las operaciones.           *\n");

        printf("\n *                                                *");

        printf ("\n *   4. Informar resultados.                      *\n");

        printf("\n *                                                *");

        printf ("\n *   5. Salir.                                    *\n");

        printf("\n *------------------------------------------------* \n");

        printf ("\n Ingrese una opcion: ");
        scanf("%d" , &opciones);

        switch (opciones)
        {
        case 1:
            system ("cls");
            primerValor = ingresarValor();
            break;

        case 2:
            system ("cls");
            segundoValor = ingresarValor();
            break;

        case 3:
            system ("cls");
            resultadoSuma = sumaDeValores(&primerValor , &segundoValor);
            resultadoResta = restaDeValores(&primerValor , &segundoValor);
            resultadoMultiplicacion = multiplicacionDeValores(&primerValor , &segundoValor);

            if(segundoValor != 0)                                                      //No se puede dividir por cero.
            {
                primerValor = (float)primerValor;                                      //Convierto a los valores enteros en flotantes.
                segundoValor = (float)segundoValor;
                resultadoDivision = divisionDeValores(&primerValor , &segundoValor);
            }
            if(primerValor >= 0)                                                       //No puedo factorear un numero negativo.
            {
                resultadoFactoreoUno = factorialDeValores(&primerValor);
            }
            if(segundoValor >= 0)
            {
                resultadoFactoreoDos = factorialDeValores(&segundoValor);
            }
            flagValidar = 1;
            printf("\n");
            printf ("\n Calculando... \n");
            printf("\n");
            break;

        case 4:
            if(flagValidar == 1)                                                                                // No se puede seleccionar la opcion 4 sin antes haber calculado las operaciones.
            {
            system ("cls");
            printf("  \n El resultado de %.2f + %.2f es: %.2f \n" , primerValor , segundoValor , resultadoSuma);
            printf("\n");
            printf(" \n El resultado de %.2f - %.2f es: %.2f \n" , primerValor , segundoValor , resultadoResta);
            printf("\n");
            printf(" \n El resultado de %.2f * %.2f es: %.2f \n" , primerValor , segundoValor , resultadoMultiplicacion);
            printf("\n");
            if(segundoValor == 0)
            {
                printf("\n No se puede dividir por 0! \n");
                printf("\n");
            }
            else
            {
                printf(" \n El resultado de %.2f / %.2f es: %.2f \n" , primerValor , segundoValor , resultadoDivision);
                printf("\n");
            }
            if(primerValor <= 0)                                          //Ningun numero tiene como factorial al numero cero
            {                                                                      //por lo tanto uso como control que sea cero o numero entero.
                printf("\n No se puede factorear a '0' o un numero negativo. \n");
                printf("\n");
            }
            else
            {
                printf(" \n El factorial de %.2f es: %.2f \n" , primerValor, resultadoFactoreoUno);
                printf("\n");
            }
            if(segundoValor <= 0)
            {
                printf("\n No se puede factorear a '0' o un numero negativo. \n");
                printf("\n");
            }
            else
            {
                printf(" \n El factorial de %.2f es: %.2f \n" , segundoValor,resultadoFactoreoDos);
                printf("\n");
            }
            }
            else
            {
                system("cls");
                printf("\n");
                printf("\n No se pueden obtener los resultados sin antes haber calculado las operaciones! \n");
                printf("\n");
            }
            resultadoDivision = 0;                                                                                      //Resetea los valores de control
            resultadoFactoreoUno = 0;                                                                                   //para poder volver a usar la calculadora
            resultadoFactoreoDos = 0;                                                                                   //sin tener que cerrarla.
            flagValidar = 0;

            break;

        case 5:
            system("cls");
            opciones = 5;
            printf("\n Finalizando calculadora... \n");
            printf("\n");
            break;

        default:
            printf("\n");
            printf("\n Ingrese una opcion valida! \n");
            printf("\n");
        }

        system("pause");
        system("cls");

    }while(opciones != 5);

    return 0;
}
float ingresarValor(void)
{
    float numero;

    printf ("Ingrese un numero: ");
    scanf ("%f" , &numero);

    return numero;
}

float sumaDeValores (float *valorUno , float *valorDos)
{
    int retorno = -1;

    if(valorUno != NULL && valorDos != NULL)
    {
        return *valorUno + *valorDos;
        retorno = 0;
    }
    return retorno;
}

float restaDeValores (float *valorUno , float *valorDos)
{
    int retorno = -1;

    if(valorUno != NULL && valorDos != NULL)
    {
        return *valorUno - *valorDos;
        retorno = 0;
    }
    return retorno;
}

float multiplicacionDeValores (float *valorUno , float *valorDos)
{
    int retorno = -1;

    if(valorUno != NULL && valorDos != NULL)
    {
        return *valorUno * *valorDos;
        retorno = 0;
    }
    return retorno;
}

float divisionDeValores (float *valorUno , float *valorDos)
{
    int retorno = -1;

    if(valorUno != NULL && valorDos != NULL)
    {
        return *valorUno / *valorDos;
        retorno = 0;
    }
    return retorno;
}

float factorialDeValores (float *valor)
{
    float factorialUno;
    float factorUno = 1;

    for (factorialUno = *valor ; factorialUno > 0 ; factorialUno --)
    {
        factorUno = factorUno * factorialUno;
    }
    return factorUno;
}


