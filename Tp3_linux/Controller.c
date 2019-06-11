#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validaciones.h"
#define EMPTY -1
#define FULL 1
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
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
/*int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile = NULL;
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                fread(&auxEmpleado,sizeof(Employee),1,pFile);
                pEmpleado = employee_new();
                if( !employee_setId(pEmpleado,auxEmpleado.id) &&
                    !employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                    !employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                    !employee_setSueldo(pEmpleado,auxEmpleado.sueldo))
                {
                     ll_add(pArrayListEmployee,pEmpleado);
                }
                else
                {
                    employee_delete(pEmpleado);
                }
            }
            retorno = 0;
            fclose(pFile);
        }
    }
    return retorno;
}*/

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

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
    int retorno = -1;
    int bufferId;
    char bufferName[4096];
    char bufferWorkedHours[4096];
    char bufferSalary[4096];
    Employee* auxEmployee = employee_new();

    if(pArrayListEmployee != NULL && auxEmployee != NULL)
    {
        if(!getName(bufferName,
                    "\n Ingrese nombre del empleado: ",
                    "\n Error, vuelva a ingresar el nombre del empleado.",
                    1,
                    51,
                    1))
        {
            employee_setNombre(auxEmployee, bufferName);
            if(!getInt("\n Ingrese las horas trabajadas del empleado: ",
                        "\n Error, vuelva a ingresar las horas trabajadas del empleado.",
                        1,
                        4,
                        1,
                        bufferWorkedHours))
            {
                employee_setHorasTrabajadasStr(auxEmployee, bufferWorkedHours);
                if(!getInt("\n Ingrese sueldo del empleado: ",
                           "\n Error, vuelva a ingresar el sueldo del empleado.",
                           1,
                           6,
                           1,
                           bufferSalary))
                {
                    employee_setSueldoStr(auxEmployee, bufferSalary);
                    bufferId = employee_idGenerator(pArrayListEmployee);
                    employee_setId(auxEmployee, bufferId);
                    ll_add(pArrayListEmployee, auxEmployee);
                    printf("\n Empleado ingresado correctamente. \n");
                    retorno = 0;
                }
                ll_sort(pArrayListEmployee, employee_compararPorNombre, 1);
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
    int i;
    char bufferName[4096];
    char bufferWorkedHours[4096];
    char bufferSalary[4096];
    Employee *auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            printf("\n ID disponibles: %d", i);
        }

        if(!employee_searchId(pArrayListEmployee, &posId))
        {
            do
            {
                system("cls");
                printf("\n *---------------------------------------------* \n");

                printf("\n *                                             * \n");

                printf("\n *   5. Modificar nombre.                      * \n");

                printf("\n *                                             * \n");

                printf("\n *   6. Modificar horas trabajadas.            * \n");

                printf("\n *                                             * \n");

                printf("\n *   7. Modificar sueldo.                      * \n");

                printf("\n *                                             * \n");

                printf("\n *---------------------------------------------* \n");

                printf("\n Ingrese opcion que quiera modificar: ");
                scanf("%d",&secondMenuOptions);
                system("cls");

                switch(secondMenuOptions)
                {
                    case 5:
                        if(!getName( bufferName,
                                     "\n Modifique el nombre del empleado: ",
                                     "\n Error, vuelva a ingresar el nombre del empleado.",
                                     1,
                                     51,
                                     1))
                        {
                           // employee_setNombre(auxEmployee, bufferName);
                           strcpy(auxEmployee->nombre, bufferName);
                        }
                        break;

                    case 6:
                        if(getInt("\n Modifique las horas trabajadas del empleado: ",
                                "\n Error, vuelva a ingresar las horas trabajadas del empleado.",
                                1,
                                4,
                                1,
                                bufferWorkedHours))
                        {
                            employee_setHorasTrabajadasStr(auxEmployee, bufferWorkedHours);
                        }
                        break;

                    case 7:

                        if(getInt( "\n Modifique el sueldo del empleado: ",
                                  "\n Error, vuelva a ingresar el salario del empleado.",
                                  0,
                                  10,
                                  1,
                                  bufferSalary))
                        {
                            employee_setSueldoStr(auxEmployee, bufferSalary);
                        }
                        break;
                }
                printf("\n ¿Quiere modificar otro campo? \n Presione 's' para continuar o 'n' para salir: ");
                scanf("%s",&mod);
                system("cls");
            }
            while(mod == 's');
            retorno = 0;

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
    return 1;
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
    return 1;
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
    int retorno = -1;
    char* path;
    FILE *pFile = NULL;
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                fread(&auxEmpleado,sizeof(Employee),1,pFile);
                pEmpleado = employee_new();
                if( !employee_setId(pEmpleado,auxEmpleado.id) &&
                    !employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                    !employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                    !employee_setSueldo(pEmpleado,auxEmpleado.sueldo))
                {
                     ll_add(pArrayListEmployee,pEmpleado);
                }
                else
                {
                    employee_delete(pEmpleado);
                }
            }
            retorno = 0;
            fclose(pFile);
            ll_sort(pArrayListEmployee,employee_compararPorNombre,0);
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
    return 1;
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
    int retorno = -1;
    int i;
    Employee *pEmployee = NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");

        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
               // printf("%s", pEmployee->nombre);
               fwrite(pEmployee, sizeof(Employee), 1, pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }
    return retorno;
}
