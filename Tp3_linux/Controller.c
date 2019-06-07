#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validaciones.h"

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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }
    return 1;
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
    int id;
    char bufferName[4000];
    char bufferHorasTrabajadas[4000];
    int auxHoras;
    char bufferSueldo[4000];
    int auxSueldo;
    Employee* auxEmployee = employee_new();

    if(pArrayListEmployee != NULL && auxEmployee != NULL)
    {
        id = generarId(pArrayListEmployee);
        if(id != -1)
        {
            employee_setId(auxEmployee, id);
            if(!getName(bufferName,
                        "\n Ingrese nombre del empleado: ",
                        "\n Error, vuelva a ingresar el nombre del empleado: ",
                        1,
                        100,
                        2))
            {
                if(!getInt("\n Ingrese las horas trabajadas del empleado: ",
                        "\n Error, vuelva a ingresar las horas trabajadas del empleado: ",
                        0,
                        100,
                        2,
                        bufferHorasTrabajadas))
                {
                    auxHoras = atoi(bufferHorasTrabajadas);
                    if(!getInt("\n Ingrese sueldo del empleado: ",
                                 "\n Error, vuelva a ingresar el sueldo del empleado: ",
                                 0,
                                 1000000,
                                 2,
                                 bufferSueldo))
                    {
                        auxSueldo = atoi(bufferSueldo);
                        employee_setNombre(auxEmployee, bufferName);
                        employee_setHorasTrabajadas(auxEmployee, auxHoras);
                        employee_setSueldo(auxEmployee, auxSueldo);
                    }
                }
            }
        }
    }
    ll_add(pArrayListEmployee, auxEmployee);
    printf("\n Empleado ingresado correctamente. \n");
    return 1;
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
    return 1;
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
    return 1;
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

int generarId(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = NULL;
    int len;
    int idActual;
    int maxID = -1;
    int i;

    if(pArrayListEmployee != NULL && auxEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &idActual);
            if(idActual > maxID)
            {
                maxID = idActual;
            }
        }
    }
    maxID ++;
    return maxID;
}
