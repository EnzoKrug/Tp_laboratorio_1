int controller_loadFromText(char* path, LinkedList* pArrayListEmployee, int* proximoId);
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee, int* proximoId);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int menu(void);
int menuModificar(void);
int menuOrdenar(void);


