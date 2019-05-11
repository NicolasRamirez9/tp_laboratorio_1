#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_strings.h"
#define EMPLEADO 3
#define EMPTY -1
#define FULL 1

int abm(void)
{
    int options;
    int posLibre;
    int flagValidar = 0;
    char seguir;
    int report;
    Employee eEmployee[EMPLEADO];

    initEmployees(eEmployee, EMPLEADO);

    do
        {
            system ("color 4f");

            printf("\n *------------------Trabajo practico N°2-------------------* \n");

            printf("\n *                                                         * \n");

            printf("\n *   1. Alta.                                              * \n");

            printf("\n *                                                         * \n");

            printf("\n *   2. Modificar.                                         * \n");

            printf("\n *                                                         * \n");

            printf("\n *   3. Baja.                                              * \n");

            printf("\n *                                                         * \n");

            printf("\n *   4. Informar.                                          * \n");

            printf("\n *                                                         *\n");

            printf("\n *   5. Salir.                                             *\n");

            printf("\n *---------------------------------------------------------* \n");

            printf ("\n Ingrese una opcion: ");
            scanf("%d" , &options);

            switch (options)
            {

            case 1:
                system ("cls");
                if(!spaceFinderInTheArray(eEmployee, EMPLEADO, &posLibre))
                {
                    flagValidar = FULL;
                    switch(addEmployee(eEmployee, EMPLEADO, posLibre))
                    {
                    case 0:

                        printf("\n El dato ingresado es correcto. \n");
                        break;

                    case 1:

                        printf("\n El dato ingresado es incorrecto. \n");
                        break;
                    }
                }
                else
                {
                    printf("\n LLENO. \n");
                }
                break;

            case 2:
                if(flagValidar == 0)
                {
                    system ("cls");
                    printf("\n No hay datos para modificar, se debe cargar el empleado primero. \n");
                }
                else
                {
                    modifyEmployee(eEmployee, EMPLEADO);
                }
                break;

            case 3:
                if(flagValidar == 0)
                {
                    system ("cls");
                    printf("\n No hay datos para dar de baja, se debe cargar al empleado primero. \n");
                }
                else
                {
                    removeEmployee(eEmployee, EMPLEADO);
                }
                break;

            case 4:
                if(flagValidar == 0)
                {
                    system ("cls");
                    printf("\n No hay datos que informar, se debe cargar al empleado primero. \n");
                }
                else
                {
                    printf("\n *---------------------------------------------------* \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   1. Apellido y sector del empleado ordenados     * \n");

                    printf("\n *      alfabeticamente de manera ascendente.        * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   1. Apellido y sector del empleado ordenados     * \n");

                    printf("\n *      alfabeticamente de manera descendente.       * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *   3. Total y promedio de los salarios.            * \n");

                    printf("\n *                                                   * \n");

                    printf("\n *---------------------------------------------------* \n");

                    printf("\n Elija una opcion: ");
                    scanf("%d", &report);

                    switch(report)
                    {
                    case 1:
                        sortEmployeesUpward(eEmployee, EMPLEADO);
                        break;
                    case 2:
                        sortEmployeesFalling(eEmployee, EMPLEADO);
                        break;
                    case 3:
                        totalAndAverageSalary(eEmployee, EMPLEADO);
                        break;
                    }
                }
                break;

                default:
                    printf("\n");
                    printf("\n Ingrese una opcion valida! \n");
                    printf("\n");
                    break;
            }
            printf("\n Quiere volver al menu?\n Presione 's' para continuar o 'n' para salir: ");
            scanf("%s",&seguir);
            system("pause");
            system("cls");

        }while(seguir == 's');

        return 0;
}

static int generarId(void)
{
    static int idEmployee = 0;
    return idEmployee++;
}

int initEmployees(Employee* eEmployee, int len)
{
    int i;
    int ret;
    for(i=0; i<len;i++)
    {
        eEmployee[i].isEmpty = EMPTY;
        ret = 0;
    }
    return ret;
}

int spaceFinderInTheArray(Employee* eEmployee,int len,int* index)
{
    int i;
    int ret;

    for(i=0; i<len; i++)
    {
        if(eEmployee[i].isEmpty == EMPTY)
        {
            *index = i;
            ret=0;
            break;
        }
        ret=EMPTY;
    }

    return ret;
}

int addEmployee(Employee* eEmployee, int len,int posLibre)
{
    int ret=FULL;
    char salary[50];
    float auxSal;
    char sector[50];
    int auxSec;

    if (!getName( eEmployee[posLibre].name,
                  "\n Ingrese nombre del empleado: ",
                  "\n Error, vuelva a ingresar el nombre del empleado: ",
                  2,
                  20,
                  1))
    {
        if (!getName( eEmployee[posLibre].lastName,
                      "\n Ingrese apellido del empleado: ",
                      "\n Error, vuelva a ingresar el apellido del empleado: ",
                      2,
                      20,
                      1))
        {
            if (!getFloat("\n Ingrese salario del empleado: ",
                          "\n Error,vuelva a ingresar el salario del empleado: ",
                          0,
                          10,
                          1,
                          salary))
            {
                auxSal=atof(salary);
                eEmployee[posLibre].salary = auxSal;
                if(!getInt( "\n Ingrese el sector del empleado: ",
                            "\n Error, vuelva a ingresar el sector del empleado: ",
                            1,
                            10,
                            1,
                            sector))
                {
                    auxSec=atoi(sector);
                    eEmployee[posLibre].sector = auxSec;
                    eEmployee[posLibre].id = generarId();
                    eEmployee[posLibre].isEmpty = 0;
                    ret=0;
                }
            }
        }
    }
    else
    {
        ret=FULL;
    }
    return ret;
}

int modifyEmployee(Employee* eEmployee, int len)
{
    int secondMenuOptions;
    char mod;
    int ret = EMPTY;
    int posId;
    char salary[50];
    float auxSal;
    char sector[50];
    int auxSec;
    int i;
    int posPrueba=0;

    for(i=0; i < len; i++)
    {
        if(eEmployee[i].isEmpty != EMPTY)
        {
            printf("\n ID disponibles: %d", eEmployee[i].id);
        }
    }
    if(!findEmployeeById(eEmployee, len, &posId))
    {
        do
        {
            system("cls");
            printf("\n *---------------------------------------------* \n");

            printf("\n *                                             * \n");

            printf("\n *   5. Nombre.                                * \n");

            printf("\n *                                             * \n");

            printf("\n *   6. Apellido.                              * \n");

            printf("\n *                                             * \n");

            printf("\n *   7. Salario.                               * \n");

            printf("\n *                                             * \n");

            printf("\n *   8. Sector.                                * \n");

            printf("\n *                                             * \n");

            printf("\n *---------------------------------------------* \n");

            printf("\n Ingrese opcion que quiera modificar: ");
            scanf("%d",&secondMenuOptions);
            system("cls");
            switch(secondMenuOptions)
            {
            case 5:
                getName( eEmployee[posPrueba].name,
                         "\n Modifique el nombre del empleado: ",
                         "\n Error, vuelva a ingresar el nombre del empleado: ",
                         2,
                         20,
                         1);
                break;

            case 6:
                getName( eEmployee[posPrueba].lastName,
                         "\n Modifique el apellido del empleado: ",
                         "\n Error, vuelva a ingresar el apellido del empleado: ",
                         2,
                         20,
                         1);
                break;

            case 7:
                getFloat( "\n Modifique el salario del empleado: ",
                          "\n Error,vuelva a ingresar el salario del empleado: ",
                          0,
                          10,
                          1,
                          salary);
                auxSal=atof(salary);
                eEmployee[posPrueba].salary=auxSal;
                break;

            case 8:
                getInt( "\n Modifique el sector del empleado: ",
                        "\n error,vuelva a intentar",
                        1,
                        2,
                        1,
                        sector);
                auxSec=atoi(sector);
                eEmployee[posPrueba].sector=auxSec;
                break;
            }
            printf("\n ¿Quiere modificar otro campo? \n Presione 's' para continuar o 'n' para salir: ");
            scanf("%s",&mod);
            system("cls");
        }
        while(mod == 's');
        ret=0;
    }
    else
    {
        printf("\n No se encontro ID. \n");
    }
    return ret;
}

int findEmployeeById(Employee* eEmployee, int len, int* idE)
{
    int i;
    int ret = EMPTY;
    Employee auxEmployee;
    printf("\n Buscar ID: ");
    scanf("%d", &auxEmployee.id);

    for(i=0; i < len; i++)
    {
        if(eEmployee[i].id == auxEmployee.id)
        {
            ret = 0;
            *idE = i;
            break;
        }
    }
    return ret;
}

int removeEmployee(Employee* eEmployee, int len)
{
    int posId;
    char resp;
    int posBaja = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(eEmployee[i].isEmpty != EMPTY)
        {
            printf("ID disponibles: %d", eEmployee[i].id);
        }
    }
    if(!findEmployeeById(eEmployee, len, &posId))
    {
        printf("\n Esta seguro que quiere dar de baja este ID? \n Presione 's' para aceptar o 'n' para cancelar: ");
        scanf("%s",&resp);
        if(resp=='s')
        {
            printf("\n Este ID ha sido dado de baja. \n");
            eEmployee[posBaja].isEmpty = EMPTY;
        }
        else
        {
            printf("\n Vuelva al menu. \n");
        }
    }
    return 0;
}

int sortEmployeesUpward(Employee* eEmployee, int len)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Employee auxOne;
    Employee auxTwo;

    printf("\n Apellido ordenado alfabeticamente de manera ascendente: ");

    for(i = 1; i < len; i++)
    {
        auxOne = eEmployee[i];
        j = i;

        while(j > 0 && strcmp( auxOne.lastName, eEmployee[j - 1].lastName) < 0)
        {
            eEmployee[j] = eEmployee[j - 1];
            j--;
        }
        eEmployee[j] = auxOne;
    }

    for (d=0; d < len; d++)
    {
        if(eEmployee[d].isEmpty != EMPTY)
        {
            printf("\n Nombre: %s \n Apellido: %s \n Salario: %.2f \n Sector: %d ",
                   eEmployee[d].name,
                   eEmployee[d].lastName,
                   eEmployee[d].salary,
                   eEmployee[d].sector);
        }
    }
    printf("\n Sector ordenado alfabeticamente de manera ascendente: ");
    for(b = 1; b < len; b++)
    {
        auxTwo = eEmployee[b];
        c = b;
        while(c > 0 &&  auxTwo.sector < eEmployee[j - 1].sector)
        {
            eEmployee[c] = eEmployee[c - 1];
            c--;
        }
        eEmployee[c] = auxTwo;
    }
    for (a=0; a < len; a++)
    {
        if(eEmployee[a].isEmpty != EMPTY)
        {
            printf("\n  Nombre: %s  \n Apellido: %s \n Salario: %.2f  \n Sector: %d ",
                   eEmployee[a].name,
                   eEmployee[a].lastName,
                   eEmployee[a].salary,
                   eEmployee[a].sector);
        }
    }
    return 0;
}

int sortEmployeesFalling(Employee* eEmployee, int len)
{
    int i;
    int j;
    int a;
    int b;
    int c;
    int d;
    Employee auxOne;
    Employee auxTwo;

    printf("\n Apellido ordenado alfabeticamente de manera descendente: ");
    for(i = 1; i < len; i++)
    {
        auxOne = eEmployee[i];
        j = i;
        while(j > 0 && strcmp(auxOne.lastName, eEmployee[j - 1].lastName)>0)
        {
            eEmployee[j] = eEmployee[j - 1];
            j--;
        }
        eEmployee[j] = auxOne;
    }
    for (d=0; d<len; d++)
    {
        if(eEmployee[d].isEmpty != EMPTY)
        {
            printf("\n  Nombre: %s  \n Apellido: %s \n Salario: %.2f  \n Sector: %d ",
                   eEmployee[d].name,
                   eEmployee[d].lastName,
                   eEmployee[d].salary,
                   eEmployee[d].sector);
        }
    }
    printf("\n Sector ordenado alfabeticamente de manera descendente: ");
    for(b = 1; b < len; b++)
    {
        auxTwo = eEmployee[b];
        c = b;
        while(c > 0 &&  auxTwo.sector > eEmployee[j - 1].sector)
        {
            eEmployee[c] = eEmployee[c - 1];
            c--;
        }
        eEmployee[c] = auxTwo;
    }
    for (a=0; a < len; a++)
    {
        if(eEmployee[a].isEmpty != EMPTY)
        {
            printf("\n  Nombre: %s  \n Apellido: %s \n Salario: %.2f  \n Sector: %d ",
                   eEmployee[a].name,
                   eEmployee[a].lastName,
                   eEmployee[a].salary,
                   eEmployee[a].sector);
        }
    }
    return 0;
}
void totalAndAverageSalary(Employee* eEmployee,int len)
{
    float accumulator = 0;
    float average;
    float counter = 0;
    int averageCounter = 0;
    int i;

    for(i=0; i < len; i++)
    {
        accumulator = accumulator + eEmployee[i].salary;
        if(eEmployee[i].isEmpty != EMPTY)
        {
            counter++;
        }
    }
    average = accumulator / counter;
    if(eEmployee[i].isEmpty > average)
    {
        averageCounter++;
    }
    printf("\n El salario total es: %.2f y el promedio es: %.2f", accumulator, average);
    printf("\n Los empleados que superaron el salario son: %d", averageCounter);
}


