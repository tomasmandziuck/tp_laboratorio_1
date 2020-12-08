#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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

int main() {
	int option = 0, flag = 0;

	LinkedList *listaEmpleados = ll_newLinkedList();
	do {
		utn_getInt(&option,
				"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
						"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
						"3. Alta de empleado.\n"
						"4. Modificar datos de empleado\n"
						"5. Baja de empleado\n"
						"6. Listar empleados\n"
						"7. Ordenar empleados\n"
						"8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
						"9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
						"10. Salir\n", "opcion no valida", 1, 10, 90);
		switch (option) {
		case 1:
			controller_loadFromText("data.csv", listaEmpleados);
			flag = 1;
			break;
		case 2:
			controller_loadFromBinary("data3.csv", listaEmpleados);
			flag = 1;
			break;
		case 3:
			if (flag == 1) {
				controller_addEmployee(listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 4:

			if (flag == 1) {
				controller_editEmployee(listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 5:

			if (flag == 1) {
				controller_removeEmployee(listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 6:
			if (flag == 1) {
				controller_ListEmployee(listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 7:
			if (flag == 1) {
				controller_sortEmployee(listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 8:

			if (flag == 1) {
				controller_saveAsText("data.csv", listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		case 9:
			if (flag == 1) {
				controller_saveAsBinary("data3.csv", listaEmpleados);
				break;
			} else {
				printf("se debe cargar una lista primero");
				break;
			}
		}
	} while (option != 10);
	return 0;
}

