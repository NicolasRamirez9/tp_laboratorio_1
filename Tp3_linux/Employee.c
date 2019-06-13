#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
#define EMPTY -1;
#define FULL 1;

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
                !employee_setHorasTrabajadasStr(pAuxEmployee, horasTrabajadasStr) &&
                !employee_setIdStr(pAuxEmployee, idStr) &&
                !employee_setSueldoStr(pAuxEmployee, sueldoStr))
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

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{
    int retorno = EMPTY;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this, char* id)
{
    int retorno = EMPTY;
    if(this != NULL && id >= 0)
    {
        retorno = employee_setId(this, atoi(id));
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = EMPTY;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = EMPTY;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = EMPTY;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = EMPTY;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
    int retorno = EMPTY;
    if(this != NULL && horasTrabajadas != NULL)
    {
        retorno = employee_setHorasTrabajadas(this, atoi(horasTrabajadas));
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = EMPTY;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = EMPTY;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this, char* sueldo)
{
    int retorno = EMPTY;
    if(this != NULL && sueldo != NULL)
    {
        retorno = employee_setSueldo(this, atoi(sueldo));
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = EMPTY;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_compararPorNombre(void* this1, void* this2)
{
    char auxStrA[4096];
    char auxStrB[4096];
    employee_getNombre((Employee*)this1, auxStrA);
    employee_getNombre((Employee*)this2, auxStrB);
    if(strcmp(auxStrA, auxStrB) > 0)
    {
        return FULL;
    }
    else if(strcmp(auxStrA, auxStrB) < 0)
    {
        return EMPTY;
    }
    return 0;
}

int employee_idGenerator(LinkedList* pArrayListEmployee)
{
    int maxId = EMPTY;
    int auxId;
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

                if(auxId > maxId)
                {
                    maxId = auxId;
                }
            }
        }
    }
    maxId ++;
    return maxId;
}

int employee_searchId (LinkedList* pArrayListEmployee, int *idEncontrado)
{
    int retorno = EMPTY;
    int i;
    int id;
    int auxId;
    int len;
    Employee *auxEmpleado;

    printf("\n Ingrese ID que quiere buscar: ");
    scanf("%d", &auxId);
    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && idEncontrado != NULL)
    {
        for(i=0; i<len; i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmpleado,&id);
            if (id == auxId && auxEmpleado != NULL)
            {
                retorno = 0;
                *idEncontrado = i;
                break;
            }
        }
    }
    return retorno;
}
