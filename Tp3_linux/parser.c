#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#define EMPTY -1;
#define FULL 1;

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    char bufferId[4096];
    char bufferName[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int flag = 0;
    Employee *auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            retorno = 0;
            fscanf(pFile,
                   "%[^,],%[^,],%[^,],%[^\n]\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo);
            if(flag == 0)
            {
                flag ++;
                continue;
            }
            auxEmployee = employee_newParametros(bufferId,
                                                 bufferName,
                                                 bufferHorasTrabajadas,
                                                 bufferSueldo);
           /*  printf("ID empleado: %s | Nombre: %s | Horas trabajadas: %s | Sueldo: %s\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo); */
            if(auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = EMPTY;
    char bufferId[4096];
    char bufferName[4096];
    char bufferWorkedHours[4096];
    char bufferSalary[4096];
    Employee auxEmployee;
    Employee *pEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            retorno = 0;
            fread(&auxEmployee, sizeof(Employee), 1, pFile);

            if( !employee_setNombre(pEmployee, bufferName)&&
                !employee_setHorasTrabajadasStr(pEmployee, bufferWorkedHours)&&
                !employee_setIdStr(pEmployee, bufferId)&&
                !employee_setSueldoStr(pEmployee, bufferSalary))
            {
                ll_add(pArrayListEmployee, pEmployee);
            }
        }
    }
    return retorno;
}
