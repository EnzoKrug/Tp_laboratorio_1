#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 128
#define QTY_SUELDO 50000
#define QTY_HORAS 120
#define QTY_EMPLOYEE 10
#include "LinkedList.h"

typedef struct
{
    int  id;
    char nombre[NOMBRE_LEN];
    int  horasTrabajadas;
    int  sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr);
int employee_delete(Employee* this);
int employee_setIdTxt(Employee* this,char* id);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
/********************************************************************************************************/
int employee_BuscarId(LinkedList* pArrayListEmployee, int idEmployee);
int employee_PrintEmployee(LinkedList* pArrayListEmployee,int indice);
int employee_CompareByName(void* item1, void* item2);
int employee_CompareById(void* item1, void* item2);
int employee_CompareBySueldo(void* item1, void* item2);
int employee_CompareByHorasTrabajadas(void* item1, void* item2);
/********************************************************************************************************/


#endif // employee_H_INCLUDED
