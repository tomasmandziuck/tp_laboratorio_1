#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define LEN 128


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	Employee* auxEmpleado;
	FILE* datos;

	 datos=fopen(path,"r+");
	 if(pArrayListEmployee != NULL)
	     {
	         ll_clear(pArrayListEmployee);
	         for(i = 0; i < ll_len(pArrayListEmployee); i++)
	             {
	                 auxEmpleado = ll_get(pArrayListEmployee, i);
	                 employee_delete(auxEmpleado);
	             }
	     }
	if ( datos  != NULL )
	    {
	        parser_EmployeeFromText(datos, pArrayListEmployee);
	        printf("\n\n Carga modo Texto OK.");
	        fclose(datos);
	    }
	    else
	    {
	        printf("\n\nNo se pudo realizar la carga.");
	    }

	    return 0;
	}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
		Employee* auxEmpleado;
		FILE* datos;

		 datos=fopen(path,"rb+");
		 if(pArrayListEmployee != NULL)
		     {
		         ll_clear(pArrayListEmployee);
		         for(i = 0; i < ll_len(pArrayListEmployee); i++)
		             {
		                 auxEmpleado = ll_get(pArrayListEmployee, i);
		                 employee_delete(auxEmpleado);
		             }
		     }
		 	 if (datos != NULL)
		    {
		        parser_EmployeeFromBinary(datos, pArrayListEmployee);
		        printf("\n\n Carga modo Binario OK.");
		        fclose(datos);
		    }
		    else
		    {
		        printf("\n\nNo se pudo realizar la carga.");
		    }

		    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
		Employee bufferAux;
		Employee* pE;
		int idAux,horasAux,sueldoAux;
		char nombreAux[LEN];

				bufferAux.id=ll_len(pArrayListEmployee)+1;
				utn_getString(bufferAux.nombre, "\ningresar nombre:",
						"\nnombre no valido", 2, 50, 90);
				utn_getInt(&bufferAux.horasTrabajadas, "\ningresar Horas trabajadas:",
						"\nhoras invalidas:", 1, 500, 90);
				utn_getInt(&bufferAux.sueldo,
						"\ningresar Sueldo:",
						"sueldo invalido", 1, 100000, 90);

				        		pE=employee_newParametrosS(bufferAux.id,bufferAux.nombre,bufferAux.horasTrabajadas,bufferAux.sueldo);
				        		if(pE!=NULL){

				        			ll_add(pArrayListEmployee,pE);
				        			if(employee_getId(pE,&idAux)==0 && employee_getNombre(pE,nombreAux)==0 && employee_getHorasTrabajadas(pE,&horasAux)==0 && employee_getSueldo(pE,&sueldoAux)==0)
				        			        {
				        			            printf("\n%d - %s - %d - %d", idAux, nombreAux, horasAux, sueldoAux);
				        			        }

				        		}

				        		 return 0;
				        	}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
		int i,idAux,horasAux,sueldoAux,OP,opcion;
	    char nombreAux[LEN];
	    int indice;

	    Employee* auxEmpleado ;
	    utn_getInt(&indice,"Que Id desea buscar\n","id no valido\n",1,ll_len(pArrayListEmployee),99);
	    for(i = 0; i < ll_len(pArrayListEmployee); i++)
	    {
	        auxEmpleado = ll_get(pArrayListEmployee, i);
	        employee_getId(auxEmpleado,&idAux);

	        if(idAux==indice && employee_getId(auxEmpleado,&idAux)==0 && employee_getNombre(auxEmpleado,nombreAux)==0 && employee_getHorasTrabajadas(auxEmpleado,&horasAux)==0 && employee_getSueldo(auxEmpleado,&sueldoAux)==0)
	        {
	        	printf("\n%d - %s - %d - %d\n", idAux, nombreAux, horasAux, sueldoAux);
	        	utn_getInt(&opcion,"desea modificar 1.si/2.no?\n","opcion no valida\n",1,2,99);

	        	if (opcion == 1) {
	        					do {

	        						printf(
	        								"\nQue desea modificar ?\n1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4-salir\n");
	        						utn_getInt(&OP, "\ningresar opcion", "opcion no valida", 1,
	        								4, 3);
	        						switch (OP) {

	        						case 1:
	        							utn_getString(nombreAux,
	        									"\ningresar nuevo apellido:",
	        									"\nnombre no valido", 2, 50, 90);
	        							employee_setNombre(auxEmpleado,nombreAux);
	        							ll_set(pArrayListEmployee, indice,auxEmpleado);
	        							system("cls");
	        							break;

	        						case 2:
	        							utn_getInt(&horasAux,
	        									"\ningresar nueva cantidad de horas:",
	        									"\nhoras no validas", 1, 500, 90);
	        							employee_setHorasTrabajadas(auxEmpleado,horasAux);
	        							ll_set(pArrayListEmployee, indice,auxEmpleado);
	        							system("cls");
	        							break;

	        						case 3:
	        							utn_getInt(&sueldoAux,
	        									"\ningresar nuevo Sueldo:",
	        									"\nsalario no valido:", 100, 100000, 90);
	        							employee_setSueldo(auxEmpleado,sueldoAux);
	        							ll_set(pArrayListEmployee, indice,auxEmpleado);
	        							system("cls");
	        							break;
	        						case 4:
	        							opcion=2;
	        							system("cls");
	        							 break;
	        						}
	        					} while (opcion!=2);
	        				} else {
	        					printf("no se Modifico\n");
	        				}
	        }
	    }
	    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
			int i,idAux,horasAux,sueldoAux,opcion;
		    char nombreAux[LEN];
		    int indice;

		    Employee* auxEmpleado ;
		    utn_getInt(&indice,"Que Id desea buscar\n","id no valido\n",1,ll_len(pArrayListEmployee),99);
		    for(i = 0; i < ll_len(pArrayListEmployee); i++)
		    {
		        auxEmpleado = ll_get(pArrayListEmployee, i);
		        employee_getId(auxEmpleado,&idAux);

		        if(idAux==indice && employee_getId(auxEmpleado,&idAux)==0 && employee_getNombre(auxEmpleado,nombreAux)==0 && employee_getHorasTrabajadas(auxEmpleado,&horasAux)==0 && employee_getSueldo(auxEmpleado,&sueldoAux)==0)
		        {
		        	printf("\n%d - %s - %d - %d\n", idAux, nombreAux, horasAux, sueldoAux);
		        	utn_getInt(&opcion,"desea Borrar 1.Si/2.No?\n","opcion no valida\n",1,2,99);
		        	if (opcion == 1)
		        	{
		        		if(ll_remove(pArrayListEmployee,indice-1)){
		        		employee_delete(auxEmpleado);
		        		printf("se elimino");
		        		}
		        	}
		        	if (opcion == 2)
		        	{
		        		printf("no se elimino\n");
		        	}
		        }
		    }
		    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,idAux,horasAux,sueldoAux;
    char nombreAux[LEN];

    Employee* auxEmpleado ;

    for(i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = ll_get(pArrayListEmployee, i);

        if(employee_getId(auxEmpleado,&idAux)==0 && employee_getNombre(auxEmpleado,nombreAux)==0 && employee_getHorasTrabajadas(auxEmpleado,&horasAux)==0 && employee_getSueldo(auxEmpleado,&sueldoAux)==0)
        {
            printf("\n%d - %s - %d - %d", idAux, nombreAux, horasAux, sueldoAux);
        }
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	if(pArrayListEmployee!=NULL){
	ll_sort(pArrayListEmployee,employee_criterio,1);
	printf("ordenamiento por sueldo completado\n");
	retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* datos;
	Employee* auxEmpleado;
	int i,idAux,horasAux,sueldoAux;
	    char nombreAux[LEN];

	datos=fopen(path,"w");
	if(datos!=NULL){
	for(i = 0; i < ll_len(pArrayListEmployee)+1; i++)
	    {
	        auxEmpleado = ll_get(pArrayListEmployee, i);

	        if(employee_getId(auxEmpleado,&idAux)==0 && employee_getNombre(auxEmpleado,nombreAux)==0 && employee_getHorasTrabajadas(auxEmpleado,&horasAux)==0 && employee_getSueldo(auxEmpleado,&sueldoAux)==0)
	        {
	            fprintf(datos,"%d,%s,%d,%d\n", idAux, nombreAux, horasAux, sueldoAux);
	        }
	    }
	fclose(datos);
	}
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* datos;
	Employee* auxEmpleado;
	int i;

	datos=fopen(path,"wb");
	if(datos!=NULL){
	for(i = 0; i < ll_len(pArrayListEmployee); i++)
	    {
	        auxEmpleado = ll_get(pArrayListEmployee, i);

	        if(auxEmpleado!=NULL)
	        {
	            fwrite(auxEmpleado,sizeof(Employee),1,datos);
	        }
	    }
	fclose(datos);
	}
    return 0;
}

