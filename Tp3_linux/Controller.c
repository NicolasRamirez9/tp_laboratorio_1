#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validaciones.h"
#define EMPTY -1
#define FULL 1
#define BUFFER 4096

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    FILE *pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            retorno = 0;
            parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    FILE *pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            retorno = 0;
            parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    int bufferId;
    char bufferName[BUFFER];
    char bufferWorkedHours[BUFFER];
    char bufferSalary[BUFFER];
    Employee* pEmployee = employee_new();

    if(pArrayListEmployee != NULL && pEmployee != NULL)
    {
        if(!getName(bufferName,
                    "\n Ingrese nombre del empleado: ",
                    "\n Error, vuelva a ingresar el nombre del empleado.",
                    1,
                    51,
                    1))
        {
            employee_setNombre(pEmployee, bufferName);
            if(!getInt("\n Ingrese las horas trabajadas del empleado: ",
                        "\n Error, vuelva a ingresar las horas trabajadas del empleado.",
                        1,
                        3,
                        1,
                        bufferWorkedHours))
            {
                employee_setHorasTrabajadasStr(pEmployee, bufferWorkedHours);
                if(!getInt("\n Ingrese sueldo del empleado: ",
                           "\n Error, vuelva a ingresar el sueldo del empleado.",
                           1,
                           7,
                           1,
                           bufferSalary))
                {
                    employee_setSueldoStr(pEmployee, bufferSalary);
                    bufferId = employee_idGenerator(pArrayListEmployee);
                    employee_setId(pEmployee, bufferId);
                    ll_add(pArrayListEmployee, pEmployee);
                    printf("\n Empleado ingresado correctamente. \n");
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int secondMenuOptions;
    char mod;
    int retorno = EMPTY;
    int posId;
    char bufferName[BUFFER];
    char bufferWorkedHours[BUFFER];
    char bufferSalary[BUFFER];
    Employee *pEmployee;

    if(pArrayListEmployee != NULL)
    {
        if(!employee_searchId(pArrayListEmployee, &posId))
        {
            pEmployee = ll_get(pArrayListEmployee, posId);
            if(pEmployee != NULL)
            {
                do
                {
                    system("cls");
                    printf("\n *---------------------------------------------* \n");

                    printf("\n *                                             * \n");

                    printf("\n *   1. Modificar nombre.                      * \n");

                    printf("\n *                                             * \n");

                    printf("\n *   2. Modificar horas trabajadas.            * \n");

                    printf("\n *                                             * \n");

                    printf("\n *   3. Modificar sueldo.                      * \n");

                    printf("\n *                                             * \n");

                    printf("\n *---------------------------------------------* \n");

                    printf("\n Ingrese opcion que quiera modificar: ");
                    scanf("%d",&secondMenuOptions);
                    system("cls");

                    switch(secondMenuOptions)
                    {
                        case 1:
                            getName( bufferName,
                                         "\n Modifique el nombre del empleado: ",
                                         "\n Error, vuelva a ingresar el nombre del empleado.",
                                         1,
                                         51,
                                         1);
                            employee_setNombre(pEmployee, bufferName);
                            break;

                        case 2:
                            getInt("\n Modifique las horas trabajadas del empleado: ",
                                    "\n Error, vuelva a ingresar las horas trabajadas del empleado.",
                                    1,
                                    4,
                                    1,
                                    bufferWorkedHours);
                            employee_setHorasTrabajadasStr(pEmployee, bufferWorkedHours);
                            break;

                        case 3:

                            getInt( "\n Modifique el sueldo del empleado: ",
                                      "\n Error, vuelva a ingresar el salario del empleado.",
                                      0,
                                      10,
                                      1,
                                      bufferSalary);
                            employee_setSueldoStr(pEmployee, bufferSalary);
                            break;
                    }
                    printf("\n �Quiere modificar otro campo? \n Presione 's' para continuar o 'n' para salir: ");
                    scanf("%s",&mod);
                    system("cls");
                }
                while(mod == 's');
                retorno = 0;

            }
        }
        else
        {
            printf("\n No se encontro ID. \n");
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    int posId;

    if(pArrayListEmployee != NULL)
    {
            if(employee_searchId(pArrayListEmployee, &posId) == -1)
            {
                printf("\n Ingrese un ID valido. \n");
            }
            else
            {
                ll_remove(pArrayListEmployee,posId);
                printf("\n Se ha dado de baja a este empleado. \n");
                retorno=0;
            }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    int auxId;
    char bufferName[BUFFER];
    int auxWorkedHours;
    int auxSalary;
    int i;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &auxId);
                employee_getNombre(pEmployee, bufferName);
                employee_getHorasTrabajadas(pEmployee, &auxWorkedHours);
                employee_getSueldo(pEmployee, &auxSalary);
                printf("\n ID del empleado: %d \n", auxId);
                printf(" Nombre del empleado: %s \n", bufferName);
                printf(" Horas Trabajadas del empleado: %d \n", auxWorkedHours);
                printf(" Sueldo del empleado: %d \n", auxSalary);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    int auxId;
    char bufferName[BUFFER];
    int auxWorkedHours;
    int auxSalary;
    int i;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &auxId);
                employee_getNombre(pEmployee, bufferName);
                employee_getHorasTrabajadas(pEmployee, &auxWorkedHours);
                employee_getSueldo(pEmployee, &auxSalary);
                printf("\n ID del empleado: %d \n", auxId);
                printf(" Nombre del empleado: %s \n", bufferName);
                printf(" Horas Trabajadas del empleado: %d \n", auxWorkedHours);
                printf(" Sueldo del empleado: %d \n", auxSalary);
                ll_sort(pArrayListEmployee, employee_compararPorNombre, 1);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int bufferId;
    char bufferName[BUFFER];
    int bufferWorkedHours;
    int bufferSalary;
    Employee *pEmployee = NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                employee_getId(pEmployee, &bufferId);
                employee_getNombre(pEmployee, bufferName);
                employee_getHorasTrabajadas(pEmployee, &bufferWorkedHours);
                employee_getSueldo(pEmployee, &bufferSalary);
                fprintf(pFile,
                        "%d, %s, %d, %d \n",
                        bufferId,
                        bufferName,
                        bufferWorkedHours,
                        bufferSalary);
            }
            retorno = 0;
            fclose(pFile);
            printf("\n Los elementos se han guardado de manera correcta. \n");
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    int i;
    Employee *pEmployee = NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");

        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                fwrite(pEmployee, sizeof(Employee), 1, pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
        printf("\n Los elementos se han guardado de manera correcta. \n");
    }
    return retorno;
}
