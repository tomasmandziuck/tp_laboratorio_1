#include <stdio.h>
#include <stdlib.h>

float opsuma (float num1, float num2)//evalua los valores ingresados, los suma y almacena el resultado en variable suma
{
    float suma;
    suma=num1+num2;
    return suma;
}
float opresta (float num1, float num2)//evalua los valores ingresados, los resta y almacena el resultado en variable resta
{
    float resta;
    resta=num1-num2;
    return resta;
}
float opmultiplicacion (float num1, float num2)//evalua los valores ingresados, los multiplica y almacena el resultado en variable multiplicacion
{
    float multiplicacion;
    multiplicacion=num1*num2;
    return multiplicacion;
}

float opdivision (float num1, float num2)//evalua los valores ingresados, los divide y almacena el resultado en variable division
{
    float division;
    division=num1/num2;
    return division;
}
float opfactorial (float num)//evalua los valores ingresados, aplica factorizacion y almacena los resultados en variable factorial1 y factorial2
{
    float factorial=1;
    float i;
    for (i=1;i<=num;i++)
    {
        factorial= factorial*i;
    }
    return factorial;
}
