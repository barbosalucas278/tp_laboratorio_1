#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define DATA "data.csv"
#define DATABIN "databin.csv"
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
            case 2:
            	controller_loadFromBinary(DATABIN,listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_ListEmployee(listaEmpleados);
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText(DATA,listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary(DATABIN,listaEmpleados);
            	break;
            case 10:
            	break;
        }
    }while(option != 10);

    ll_clear(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
