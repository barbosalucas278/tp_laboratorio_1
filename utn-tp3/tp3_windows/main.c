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
    int controller = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	system("cls");
    	option = menu();
        switch(option)
        {
            case 1:
                if(controller_loadFromText(DATA,listaEmpleados) && controller == 0){
                	controller = 1;
                }else{
            		printf("ya se cargó la nomina de empleados\n");
            	}
                break;
            case 2:
            	if(controller_loadFromBinary(DATABIN,listaEmpleados) && controller == 0){
            		controller = 1;
            	}else{
            		printf("ya se cargó la nomina de empleados\n");
            	}
            	break;
            case 3:
            	if(controller == 1){
					controller_addEmployee(listaEmpleados);
            	}else{
            		printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
            case 4:
            	if(controller == 1){
            	controller_editEmployee(listaEmpleados);
            	}else{
            		printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
            case 5:
            	if(controller == 1){
            	controller_ListEmployee(listaEmpleados);
            	controller_removeEmployee(listaEmpleados);
            	}else{
            	    printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
            case 6:
            	if(controller == 1){
            	controller_ListEmployee(listaEmpleados);
            	}else{
            	    printf("Primero tiene que cargar la nomina de empleados\n");
            	}
            	break;
            case 7:
            	if(controller == 1){
            	controller_sortEmployee(listaEmpleados);
            	}else{
            	    printf("Primero tiene que cargar la nomina de empleados\n");
            	}
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
