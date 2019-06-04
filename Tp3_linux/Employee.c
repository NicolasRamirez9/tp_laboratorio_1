#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,
                                 char* nombreStr,
                                 char* horasTrabajadasStr,
                                 char* sueldoStr)
{
    Employee* retorno = NULL;
    Employee* pAuxEmployee;

    if( idStr != NULL && nombreStr != NULL &&
        horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        pAuxEmployee = employee_new();
        if(pAuxEmployee != NULL)
        {
            if( !employee_setNombre(pAuxEmployee, nombreStr) &&
                !employee_setHorasTrabajadas(pAuxEmployee, horasTrabajadasStr) &&
                !employee_setId(pAuxEmployee, idStr) &&
                !employee_setSueldo(pAuxEmployee, sueldoStr))
            {
                retorno = pAuxEmployee;
            }
            else
            {
                employee_delete(pAuxEmployee);
            }
        }
    }
    return retorno;
}

void employee_delete()
{
    Employee* this;

    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
