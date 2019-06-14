#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int option = 0;
    int flagUno = 0;
    int flagTexto = 0;
    int flagBinario = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do {
            system ("color 4f");

            printf("\n*----------------------------Trabajo practico Nro3----------------------------*\n");

            printf("\n 1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");

            printf("\n 2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");

            printf("\n 3.Alta de empleado.                                                          \n");

            printf("\n 4.Modificar datos de empleado.                                               \n");

            printf("\n 5.Baja de empleado.                                                          \n");

            printf("\n 6.Listar empleados.                                                          \n");

            printf("\n 7.Ordenar empleados.                                                         \n");

            printf("\n 8.Guardar los datos de los empleados en el archivo data.csv (modo texto).    \n");

            printf("\n 9.Guardar los datos de los empleados en el archivo data.csv (modo binario).  \n");

            printf("\n 10.Salir.                                                                    \n");

            printf("\n*----------------------------------------------------------------------------*\n");

            printf ("\n Ingrese una opcion: ");
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                    system ("cls");
                    if(flagUno == 0 && flagBinario == 0)
                    {
                        controller_loadFromText("data.csv", listaEmpleados);
                        flagUno = 1;
                        flagTexto = 1;
                        printf("\n");
                        printf("\n Cargando datos del archivo data.csv(modo texto)... \n");
                        printf("\n");
                    }
                    else
                    {
                        printf("\n No se puede cargar mas de un archivo. \n");
                    }
                    break;

                case 2:
                    system ("cls");
                    if(flagUno == 0 && flagTexto == 0)
                    {
                        controller_loadFromBinary("data.csv", listaEmpleados);
                        flagUno = 1;
                        flagBinario = 1;
                        printf("\n");
                        printf("\n Cargando datos del archivo data.csv(modo binario)... \n");
                        printf("\n");
                    }
                    else
                    {
                        printf("\n No se puede cargar mas de un archivo. \n");
                    }
                    break;

                case 3:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        controller_addEmployee(listaEmpleados);
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 4:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        if(ll_len(listaEmpleados) == 0)
                        {
                            printf("\n No hay ningun empleado cargado. \n");
                        }
                        else
                        {
                            controller_editEmployee(listaEmpleados);
                        }
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 5:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        if(ll_len(listaEmpleados) == 0)
                        {
                            printf("\n No hay ningun empleado cargado para mostrar. \n");
                        }
                        else
                        {
                            controller_removeEmployee(listaEmpleados);
                        }
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 6:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        if(ll_len(listaEmpleados) == 0)
                        {
                            printf("\n No hay ningun empleado cargado para mostrar. \n");
                        }
                        else
                        {
                            controller_ListEmployee(listaEmpleados);
                        }
                    }
                    else
                    {
                         printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 7:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        if(ll_len(listaEmpleados) == 0)
                        {
                             printf("\n No hay ningun empleado cargado para mostrar. \n");
                        }
                        else
                        {
                            controller_sortEmployee(listaEmpleados);
                        }
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 8:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        controller_saveAsText("data.csv",listaEmpleados);
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 9:
                    system ("cls");
                    if(flagTexto == 1 || flagBinario == 1)
                    {
                        controller_saveAsBinary("data.bin",listaEmpleados);
                    }
                    else
                    {
                        printf("\n No hay ningun archivo cargado, cargue el archivo primero. \n");
                    }
                    break;

                case 10:
                    system("cls");
                    option = 10;
                    printf("\n Finalizando programa... \n");
                    printf("\n");
                    break;

                default:
                    system("cls");
                    printf("\n");
                    printf("\n Ingrese una opcion valida! \n");
                    printf("\n");
            }
            system("pause");
            system("cls");

    }while(option != 10);
    return 0;
}
