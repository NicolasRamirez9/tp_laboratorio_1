#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
        fclose(pFile);
    }
    return 1;
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
    char bufferId;
    char bufferName[4000];
    char bufferHorasTrabajadas[4000];
    char bufferSueldo[4000];

    if(pArrayEmployee != NULL)
    {
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
                if(!getFloat("\n Ingrese sueldo del empleado: ",
                             "\n Error, vuelva a ingresar el sueldo del empleado: ",
                             0,
                             10000000,
                             2,
                             bufferSueldo))
                {
                    aux
                }
            }
        }
    }
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
    return 1;
}

int generarId(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
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
