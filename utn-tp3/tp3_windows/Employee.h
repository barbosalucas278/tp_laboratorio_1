#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newAlta(int id,char* nombre, int horasTrabajadas, int sueldo);
int employee_delete(Employee* this); // void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_dataRegistration(char* pNombre,int* pHorasTrabajadas,int* pSueldo);
int getNameEmployee (char* name);
int getHorasTrabajadasEmployee(int* pHorasTrabajadas);
int getSueldoEmployee(int* pSueldo);

int printEmployee(Employee *this);
int getIndexFromId(int *pIndex, int lenLL);
int submenuModidy();
int employee_modify(Employee* this);
int sortEmployeeBySalary(void* employee1, void* employee2);
int sortEmployeeById(void* employee1, void* employee2);
int sortEmployeeByWorkedHours(void* employee1, void* employee2);
#endif // employee_H_INCLUDED
