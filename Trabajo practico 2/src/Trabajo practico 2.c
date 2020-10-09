#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX 1000


int main()
{
	setbuf(stdout,NULL);
    int opcion=0,flag=0;
    char seguir ='s';
    eEmployee emp[MAX];


    init(emp,MAX);


    do
    {

        printf("1- Cargar Dato\n2- Mostrar Empleados\n3- Mostrar salarios\n4- Baja\n5- Modificar\n6- Salir");
        utn_getInt(&opcion, "\n", "opcion no valida", 1,6,3);
        switch(opcion)
        {
        case 1:

            Alta(emp,MAX);
            system("cls");
            break;
        case 2:
            flag=AllEmpty(emp, MAX);
            if(flag==0){
            system("cls");
            ordenarApySec(emp,MAX);
            mostrarTodos(emp, MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 3:
            flag=AllEmpty(emp, MAX);
            if(flag==0){
            system("cls");
            mostrarSalarios (emp,MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 4:
            flag=AllEmpty(emp, MAX);
            if(flag==0){
            system("cls");
            Baja(emp, MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 5:
            flag=AllEmpty(emp, MAX);
            if(flag==0){
            Modificacion(emp, MAX);
            break;
            }
            else{
                printf("\nse debe ingresar un dato primero\n");
                break;
            }
        case 6:
            seguir='n';
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
