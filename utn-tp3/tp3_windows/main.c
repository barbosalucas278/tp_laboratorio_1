#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define DATA "data.csv"
#define DATA2 "data2.csv"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    //LinkedList* empleadosActualizados = ll_newLinkedList();
    //Employee* pruebaEmp;

    do{
    	option = menu();
        switch(option)
        {
            case 1:
                controller_loadFromText(DATA,listaEmpleados);
               printf("CANTIDAD EN LISTA [%d]\n",ll_len(listaEmpleados));
               /*for(int i=0;i<ll_len(listaEmpleados);i++){
            	  pruebaEmp = ll_get(listaEmpleados,i);
            	   printf("%6d %15s %6d %6d\n",pruebaEmp->id,pruebaEmp->nombre,
            			   pruebaEmp->horasTrabajadas,pruebaEmp->sueldo);
               }*/
                break;
            case 2://cargar desde binario
            	controller_loadFromBinary(DATA2,listaEmpleados);
            	//printf("CANTIDAD EN LISTA [%d]\n",ll_len(listaEmpleados));
            	break;
            case 3://alta employee
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4://modify employee
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5://remove employee
            	controller_ListEmployee(listaEmpleados);
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6://prints employees
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7://sort employee
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8://guardar en texto

            	break;
            case 9://guardar en binario
            	break;
            case 10://exit
            	break;
        }
    }while(option != 10);
    return 0;
}
