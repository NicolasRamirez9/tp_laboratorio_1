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
                    controller_loadFromText("data.csv", listaEmpleados);
                    printf("\n");
                    printf("\n Cargando datos del archivo data.csv(modo texto)... \n");
                    printf("\n");
                    break;

                case 2:
                    system ("cls");
                    controller_loadFromBinary("data.csv", listaEmpleados);
                    printf("\n");
                    printf("\n Cargando datos del archivo data.csv(modo binario)... \n");
                    printf("\n");
                    break;

                case 3:
                    system ("cls");
                    controller_addEmployee(listaEmpleados);
                    break;

                case 4:
                    system ("cls");
                    controller_editEmployee(listaEmpleados);
                    break;

                case 5:
                    system ("cls");
                    controller_removeEmployee(listaEmpleados);
                    break;

                case 6:
                    system ("cls");
                    controller_ListEmployee(listaEmpleados);
                    break;

                case 7:
                    system ("cls");
                    controller_sortEmployee(listaEmpleados);
                    break;

                case 8:
                    system ("cls");
                    controller_saveAsText("data.csv", listaEmpleados);
                    break;

                case 9:
                    system ("cls");
                    controller_saveAsBinary("data.csv", listaEmpleados);
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
