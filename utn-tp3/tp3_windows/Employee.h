#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char name[128];
    int workedHours;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr,char* salaryStr);
Employee* employee_newRegistration(int id,char* nombre, int horasTrabajadas, int sueldo);
int employee_delete(Employee* this); // void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* nombre);
int employee_getName(Employee* this,char* nombre);

int employee_setWorkedHours(Employee* this,int horasTrabajadas);
int employee_getWorkedHours(Employee* this,int* horasTrabajadas);

int employee_setSalary(Employee* this,int sueldo);
int employee_getSalary(Employee* this,int* sueldo);

int employee_dataRegistration(char* pNombre,int* pHorasTrabajadas,int* pSueldo);
int getFromABMName (char* name);
int getFromABMWorkedHours(int* pHorasTrabajadas);
int getFromABMSalary(int* pSueldo);

int printEmployee(Employee *this);
int submenuModidy();
int employee_modify(Employee* this);
int sortEmployeeBySalary(void* employee1, void* employee2);
int sortEmployeeById(void* employee1, void* employee2);
int sortEmployeeByWorkedHours(void* employee1, void* employee2);
#endif // employee_H_INCLUDED
