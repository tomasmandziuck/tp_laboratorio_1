#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmp;

	char id[50],nombre[50],horas[50],sueldo[50];


		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo)==4){
				auxEmp=employee_newParametros(id,nombre, horas,sueldo);
				ll_add(pArrayListEmployee,auxEmp);
			}

		}while(feof(pFile)==0);

    return 0;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	 	Employee* auxEmpleado;
	    Employee empleado;
	    do{
	    	auxEmpleado = employee_newParametrosB(empleado);
	        fread(&empleado, sizeof(Employee), 1, pFile);
	        ll_add(pArrayListEmployee, auxEmpleado);
	    }while(feof(pFile)==0);
	    return 0;
}
