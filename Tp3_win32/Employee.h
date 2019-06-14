#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un empleado
 *
 * \param void
 * \return employee
 *
 */
Employee* employee_new();

/** \brief retorna un puntero al empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadas char*
 * \param sueldoStr char*
 * \return retorno
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief elimina un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this);

/** \brief setea el valor del ID del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this, int id);

/** \brief setea el valor ID del empleado como char
 *
 * \param this Employee*
 * \param id char*
 * \return employee
 *
 */
int employee_setIdStr(Employee* this, char* id);

/** \brief toma el valor del ID del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this, int* id);

/** \brief setea el valor del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this, char* nombre);

/** \brief toma el valor del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this, char* nombre);

/** \brief setea el valor de las horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);

/** \brief setea el valor de las horas trabajadas del empleado como char
 *
 * \param this Employee*
 * \param horasTrabajadas char*
 * \return int
 *
 */
int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas);

/** \brief toma el valor de las horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

/** \brief setea el valor del sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this, int sueldo);

/** \brief setea el valor del sueldo del empleado como char
 *
 * \param this Employee*
 * \param sueldo char*
 * \return int
 *
 */
int employee_setSueldoStr(Employee* this, char* sueldo);

/** \brief toma el valor del sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);

/** \brief compara nombres de los empleados
 *
 * \param this1 void*
 * \param this2 void*
 * \return int
 *
 */
int employee_compararPorNombre(void* this1, void* this2);

/** \brief genera un ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_idGenerator(LinkedList* pArrayListEmployee);

/** \brief busca un ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param idEncontrado int*
 * \return employee
 *
 */
int employee_searchId (LinkedList* pArrayListEmployee, int* idEncontrado);
#endif // employee_H_INCLUDED
