#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX 1000

void Alta(eEmployee emp[], int cant, int *id) {
	int i, auxId;
	for (i = 0; i < cant; i++) {

		if (emp[i].isEmpty == 1) {
			auxId = *id;
			emp[i].Id = auxId;
			utn_getString(emp[i].apellido, "\ningresar apellido:",
					"\napellido no valido", 2, 20, 3);
			utn_getString(emp[i].nombre, "\ningresar nombre:",
					"\nnombre no valido", 2, 20, 3);
			utn_getFloat(&emp[i].salario, "\ningresar salario:",
					"\nsalario no valido:", 1000, 100000, 3);
			utn_getInt(&emp[i].sector,
					"\ningresar sector:\n1-Finanzas \n2-Ventas \n3-Atencion al cliente \n4-Produccion",
					"Sector no valido", 1, 4, 3);
			emp[i].isEmpty = 0;
			(*id)++;
			break;
		}

	}

}

void mostrarTodos(eEmployee emp[], int cant) {
	int i;

	for (i = 0; i < cant; i++) {

		if (emp[i].isEmpty == 0) {
			mostrarUno(emp[i]);
		}
	}

}
void mostrarUno(eEmployee emp) {
	printf("\nId:%d\nApellido:%s\nNombre:%s\nSalario:%.0f\nSector:%d\n", emp.Id,
			emp.apellido, emp.nombre, emp.salario, emp.sector);
}

void ordenarApySec(eEmployee emp[], int cant) {
	int i, j;
	eEmployee auxemp;
	for (i = 0; i < cant - 1; i++) {
		for (j = i + 1; j < cant; j++) {
			if (emp[i].sector > emp[j].sector) {
				auxemp = emp[i];
				emp[i] = emp[j];
				emp[j] = auxemp;
			} else {
				if (emp[i].sector == emp[j].sector
						&& (stricmp(emp[i].apellido, emp[j].apellido) == 1)) {
					auxemp = emp[i];
					emp[i] = emp[j];
					emp[j] = auxemp;
				}
			}
		}
	}
}

void init(eEmployee emp[], int cant) {

	int i;
	for (i = 0; i < cant; i++) {
		emp[i].isEmpty = 1;
	}

}

void Baja(eEmployee emp[], int cant) {
	int auxId;
	int flag = 0, i;
	char rta;
	mostrarTodos(emp, MAX);
	fflush(stdin);
	utn_getInt(&auxId, "que Id desea buscar?", "Id no encontrado", 1, 1000, 3);
	for (i = 0; i < cant; i++) {
		if (auxId == emp[i].Id && emp[i].isEmpty==0) {
			printf("\nId:%d\nApellido:%s\nNombre:%s\nSalario:%.0f\nSector:%d\n",
					emp[i].Id, emp[i].apellido, emp[i].nombre, emp[i].salario,
					emp[i].sector);
			do {
				 printf("\nDesea borrar este registro s/n");
				 scanf("%c",&rta);
				 fflush(stdin);
				 rta=tolower(rta);
			} while (rta != 's' && rta != 'n');
			if (rta == 's') {
				emp[i].isEmpty = 1;
			} if (rta == 'n')
			{
				printf("\nno se dio de baja\n");
			}

		}
		flag = 1;

	}
	if (flag == 0) {
		printf("no existe dato\n");
	}

}

void Modificacion(eEmployee emp[], int cant) {
	int auxId;
	int flag = 0, i, OP;
	char rta;
	mostrarTodos(emp, MAX);
	fflush(stdin);
	utn_getInt(&auxId, "Que Id desea buscar?", "Id no encontrado", 1, 1000, 3);
	for (i = 0; i < cant; i++) {
		if (auxId == emp[i].Id && emp[i].isEmpty==0) {
			mostrarUno(emp[i]);
			flag = 1;
			do {
			     printf("\nDesea modificar este registro ?s/n");
								scanf("%c", &rta);
								fflush(stdin);
								rta = tolower(rta);
			} while (rta != 's' && rta != 'n');
			if (rta == 's') {
				do {

					printf(
							"\nQue desea modificar ?\n1- Apellido\n2- Nombre\n3- Salario\n4- Sector\n5-salir\n");
					utn_getInt(&OP, "\ningresar opcion", "opcion no valida", 1,
							5, 99);
					switch (OP) {

					case 1:
						utn_getString(emp[i].apellido,
								"\ningresar nuevo apellido:",
								"\napellido no valido", 2, 20, 3);
						system("cls");
						break;

					case 2:
						utn_getString(emp[i].nombre, "\ningresar nuevo nombre:",
								"\nnombre no valido", 2, 20, 3);
						system("cls");
						break;

					case 3:
						utn_getFloat(&emp[i].salario,
								"\ningresar nuevo salario:",
								"\nsalario no valido:", 1000, 100000, 3);
						system("cls");
						break;
					case 4:
						utn_getInt(&emp[i].sector,
								"\ningresar nuevo sector:\n1-Finanzas \n2-Ventas \n3-Atencion al cliente \n4-Produccion",
								"Sector no valido", 1, 4, 3);
						system("cls");
						break;
					case 5:
						rta = 'n';
						break;
					}
				} while (rta == 's');
			} if (rta == 'n') {
				printf("no se Modifico\n");
				break;
			}
		}

	}

	if (flag == 0) {
			printf("no existe dato");
			system("pause");
		}
}

int AllEmpty(eEmployee emp[], int cant) {

	int i;
	int flag = 1;
	for (i = 0; i < cant; i++) {
		if (emp[i].isEmpty != 1) {
			flag = 0;
		}
	}
	return flag;
}

float promedioSalario(eEmployee emp[], int cant) {
	float acumulador = 0;
	float promedio;
	int contador = 0;

	for (int i = 0; i < cant; i++) {
		if (emp[i].isEmpty == 0) {
			acumulador += emp[i].salario;
			contador++;
		}

	}

	promedio = acumulador / contador;

	return promedio;

}

float totalSalarios(eEmployee emp[], int cant) {
	float acumulador = 0;

	for (int i = 0; i < cant; i++) {
		if (emp[i].isEmpty == 0) {
			acumulador += emp[i].salario;

		}
	}

	return acumulador;
}

int cantMayorPromedio(eEmployee emp[], int cant) {
	float promedio = promedioSalario(emp, cant);
	int contador = 0;

	for (int i = 0; i < cant; i++) {
		if (emp[i].isEmpty == 0) {
			if (emp[i].salario > promedio) {
				contador++;
			}
		}
	}

	return contador;

}

void mostrarSalarios(eEmployee emp[], int cant) {
	int cantidad;
	float total, promedio;
	cantidad = cantMayorPromedio(emp, cant);
	total = totalSalarios(emp, cant);
	promedio = promedioSalario(emp, cant);

	printf(
			"\nLa suma total de salarios es:%.2f\nEl promedio de los salarios es:%.2f\nLa cantidad de empleado por encima del promedio salarial es:%d\n",
			total, promedio, cantidad);

}
