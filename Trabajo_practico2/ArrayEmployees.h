#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define NOMBRE_APELLIDO 51

struct
{
 int id;
 char name[NOMBRE_APELLIDO];
 char lastName[NOMBRE_APELLIDO];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

/** \brief genera ID automaticamente
 *
 * \param void
 * \return i
 *
 */
static int generarId(void);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param eEmployee Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee* eEmployee, int len);

/** \brief busca vacio para cambiarlo a lleno
 *
 * \param eEmployee Employee*
 * \param len int
 * \param index int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int spaceFinderInTheArray(Employee* eEmployee,int len,int* index);

/** \brief da de alta empleado
 *
 * \param eEmployee Employee*
 * \param len int
 * \param posLibre int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int addEmployee(Employee* eEmployee, int len,int posLibre);

/** \brief modifica datos empleado
 *
 * \param eEmployee Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(Employee* eEmployee, int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param eEmployee Employee*
 * \param len int
 * \param idE int*
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* eEmployee, int len,int* idE);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param eEmployee Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* eEmployee, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP order
 *
 * \param eEmployee Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployeesUpward(Employee* eEmployee, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate DOWN order
 *
 * \param eEmployee Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeesFalling(Employee* eEmployee, int len);

/** \brief calcula el total y el promedio de los salarios
 *
 * \param eEmployee Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void totalAndAverageSalary(Employee* eEmployee,int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
