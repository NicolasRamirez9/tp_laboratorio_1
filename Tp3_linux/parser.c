#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char bufferId[4000];
    char bufferName[4000];
    char bufferHorasTrabajadas[4000];
    char bufferSueldo[4000];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,
                   "%[^,],%[^,],%[^,],%[^\n]\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo);
            printf("ID empleado: %s | Nombre: %s | Horas trabajadas: %s | Sueldo: %s\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo);
        }
        fclose(pFile);
    }
    return 1;
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
    int i = 0;
    int flag=0;
    char bufferId[50];
    char bufferName[50];
    char bufferHorasTrabajadas[50];
    char bufferSueldo[50];

    pFile = fopen("data.csv", "rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo);
            if(flag == 0)
            {
                flag++;

            }
            i++;
            printf("ID empleado: %s | Nombre: %s | Horas trabajadas: %s | Sueldo: %s\n",
                   bufferId,
                   bufferName,
                   bufferHorasTrabajadas,
                   bufferSueldo);
        }
        fclose(pFile);
    }
    return 1;
}
