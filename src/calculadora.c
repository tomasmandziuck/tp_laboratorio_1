
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
	setbuf(stdout,NULL);
    int opcion =0;
    char seguir = 's';

    float num1=0;
    float num2=0;
    float rsuma;
    float rresta;
    float rmultiplicacion;
    float rdivision;
    float rfactorialA;
    float rfactorialB;
    int flag1=0;
    int flag2=0;
    int flag3=0;


       while (seguir=='s')
        {
            printf("Los operandos son A=%.2f B%.1f \n",num1,num2);
            printf("1- ingresar operando A\n");
            printf("2- Ingresar operando B\n");
            printf("3- Realizar operaciones \n");
            printf("4- Mostrar resultados\n");
            printf("5- Salir\n");
            scanf("%d",&opcion);
            system("cls");

            if(opcion==5)
                {
                    seguir = 'n';
                    printf("operacion terminada");
                break;
                }

            switch(opcion)
            {
            case 1:
                printf("ingrese primer numero\n");
                scanf("%f",&num1);
                flag1=1;
                break;
            case 2:
                if(flag1==1)
                {
                    printf("ingrese segundo numero\n");
                    scanf("%f",&num2);
                    flag2=1;
                }
                else{
                        printf("Debe ingresarse el primer operando antes de continuar \n");
                    }
                system("pause");
                break;
            case 3:
                if(flag2==1)
                {
                    rsuma =opsuma(num1, num2);
                    rresta=opresta(num1, num2);
                    rdivision=opdivision(num1,num2);
                    rmultiplicacion=opmultiplicacion(num1,num2);
                    rfactorialA=opfactorial(num1);
                    rfactorialB=opfactorial(num2);
                    flag3=1;
                }
                else
                {
                    printf("Deben haberse ingresado ambos operandos antes de continuar \n");
                }
                system("pause");
                break;
            case 4:
                if(flag3==1){
                printf("El resultado de la suma es: %.2f\n",rsuma);
                printf("El resultado de la resta es: %.2f\n",rresta);
                if(num2==0)
                {
                        printf("No se puede dividir por 0 \n");
                }
                else
                    {
                        printf("El resultado de la division es: %.2f\n",rdivision);
                    }
                printf("El resultado de la multiplicacion es: %.2f\n",rmultiplicacion);
                printf("El resultado del Factorial de A es: %.2f\n",rfactorialA);
                printf("El resultado del Factorial de B es: %.2f\n",rfactorialB);
                }
                else
                    {
                        printf("No se han realizado las operaciones");
                    }
                system("pause");
                break;

            }
            printf("Desea seguir operando? \n\n");

       }
        return EXIT_SUCCESS;

}
