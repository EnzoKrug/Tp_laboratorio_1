#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 51
#define TRUE -1 //Esta vacio
#define FALSE 1 //Esta ocupado

typedef struct
{
    int idEmployee; //Identificacion
    char name[QTY_CARACTERES]; //Nombre
    char lastName[QTY_CARACTERES]; //Apellido
    float salary; //Sueldo
    int sector;
    int isEmpty; //Estado del empleado

}sEmployee; //Empleado/a

/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 * \param list sEmployee[] Array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int empl_initEmployees(sEmployee list[], int len);

/** \brief Find the first free position
 *
 * \param list[] sEmployee Array of employees
 * \param len int Array lenght
 * \return int Return employee index position or (-1) if [Invalid length or NULL
 *         pointer received or employee not found]
 *
 */
int empl_getEmptyIndex(sEmployee list[], int len);

/** \brief Add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list sEmployee[] Array of employees
 * \param len int Array lenght
 * \param id int Empoyee's Id
 * \param name[] char Empoyee's name
 * \param lastName[] char Empoyee's lastName
 * \param salary float Empoyee's salary
 * \param sector int Empoyee's sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int empl_addEmployee(sEmployee list[], int len, int* id, char name[], char lastName[], float salary, int sector, int indice);

/** \brief Shows employees
 *
 * \param list[] sEmployee Array of employees
 * \param len int Array lenght
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int empl_imprimirEmployee(sEmployee list[], int len);

/** \brief Find an Employee by Id en returns the index position in array.
 *
 * \param list[] sEmployee Array of employees
 * \param len int Employee of lenght
 * \param id int Empoyee's Id
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *         pointer received or employee not found]
 *
 */
int empl_findEmployeeById(sEmployee list[], int len, int valorBuscado);

/** \brief Modify menu
 *
 * \param list[] sEmployee Array of employees
 * \param len int Employee of lenght
 * \param auxIndex int Index found to be analyzed
 * \return void
 *
 */
void empl_menuModificar(sEmployee list[], int len, int auxIndex);

/** \brief Remove the employee using the entered index
 *
 * \param list[] sEmployee Array of employees
 * \param len int Employee of lenght
 * \param auxIndex int Index found to be analyzed
 * \return return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *         find a employee] - (0) if Ok
 *
 */
int empl_removeEmployee(sEmployee list[], int len, int auxIndex);

/** \brief Sort menu
 *
 * \param list[] sEmployee Array of employees
 * \param len int Employee of lenght
 * \return void
 *
 */
void empl_menuOrdenar(sEmployee list[], int len);

/** \brief Sort the elements in the array of employees, the argument order
 *         indicate UP or DOWN order
 *
 * \param list sEmployee[] Array of employees
 * \param len int Employee of lenght
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void empl_sortEmployees(sEmployee list[], int len, int order);

/** \brief Forcibly add an employee
 * \param list sEmployee[] Array of employees
 * \param len int Array lenght
 * \param auxIndice int Empoyee's auxIndice
 * \param id int Empoyee's Id
 * \param name[] char Empoyee's name
 * \param lastName[] char Empoyee's lastName
 * \param salary float Empoyee's salary
 * \param sector int Empoyee's sector
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int empl_altaForzadaArray(sEmployee list[],int len, int auxIndice, int* id, char name[], char lastName[], float salary, int sector);

/** \brief Calculate the average salary of the total employees
 *
 * \param list[] sEmployee Array of employees
 * \param len int Array lenght
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int empl_salarioPromedio(sEmployee list[], int len);

/** \brief Calculates the number of employees that exceed the average salary
 *
 * \param list[] sEmployee Array of employees
 * \param len int Array lenght
 * \param promedioSalary float Average salary of total employees
 * \return int Return (-1) if Error - (Quantity of employees) if Ok
 *
 */
int calcularMaximoPromedio(sEmployee list[], int len, float promedioSalary);
#endif // ARRAYEMPLOYEES_H_INCLUDED
