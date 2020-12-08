#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"
#define LEN 128

Employee* employee_new(void) {
	Employee *p=NULL;
	p = (Employee*) malloc(sizeof(Employee));
	return p;
	}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {
	Employee* punteroEmp;
	punteroEmp=employee_new();
	if (punteroEmp != NULL) {
		employee_setIdTxt(punteroEmp,idStr);
		employee_setNombre(punteroEmp,nombreStr);
		employee_setHorasTrabajadasTxt(punteroEmp,horasTrabajadasStr);
		employee_setSueldoTxt(punteroEmp,sueldoStr);

		return punteroEmp;
	}
	else
	{
		return NULL;
	}

}
Employee* employee_newParametrosS(int id,char* nombre,int horasTrabajadas, int sueldo) {
	Employee* punteroEmp;
	punteroEmp=employee_new();
	if (punteroEmp != NULL) {
		employee_setId(punteroEmp,id);
		employee_setNombre(punteroEmp,nombre);
		employee_setHorasTrabajadas(punteroEmp,horasTrabajadas);
		employee_setSueldo(punteroEmp,sueldo);

		return punteroEmp;
	}
	else
	{
		return NULL;
	}

}
Employee* employee_newParametrosB(Employee emp)
{
    Employee* auxiliarEmp = employee_new();
    employee_setId(auxiliarEmp, emp.id);
    employee_setNombre(auxiliarEmp, emp.nombre);
    employee_setHorasTrabajadas(auxiliarEmp, emp.horasTrabajadas);
    employee_setSueldo(auxiliarEmp, emp.sueldo);
    return auxiliarEmp;
}

int employee_criterio(void* item1, void* item2){
	Employee* e1;
	Employee* e2;
	int retorno=0;
	char nAux1[LEN],nAux2[LEN];
	e1=(Employee*)item1;
	e2=(Employee*)item2;


	if(employee_getNombre(e1,nAux1)==0 && employee_getNombre(e2,nAux2)==0)
		{

			retorno=strcmpi(nAux1, nAux2);

		}

	return retorno;

}





void employee_delete(Employee* this){
	free(this);
}

int employee_setId(Employee* this,int id){
	int retorno=-1;

		if(this!=NULL && id>=0){
			retorno=0;
			this->id=id;
		}
		return retorno;
	}
int employee_setIdTxt(Employee* this,char*id){
	int retorno=-1;

		if(this!=NULL && id>=0 ){
			retorno=0;
			this->id=atoi(id);
		}
		return retorno;
	}
int employee_getId(Employee* this,int* id){
	int retorno=-1;

	if(this!=NULL && id>=0){
		retorno=0;
		*id=this->id;
	}
	return retorno;
}


int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;

			if(this !=NULL && nombre!=NULL ){
					strcpy(this->nombre,nombre);
					retorno=0;
			}

		return retorno;
	}

int employee_getNombre(Employee* this,char* nombre){
	int retorno=-1;

		if(this!=NULL && nombre!=NULL){
			retorno=0;
			strncpy(nombre,this->nombre,LEN);
		}
		return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno=-1;

			if(this!=NULL && horasTrabajadas>=0){
				retorno=0;
				this->horasTrabajadas=horasTrabajadas;
			}
			return retorno;
}
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas){
	int retorno=-1;

			if(this!=NULL && horasTrabajadas>=0){
				retorno=0;
				this->horasTrabajadas=atoi(horasTrabajadas);
			}
			return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno=-1;

		if(this!=NULL && horasTrabajadas>=0){
			retorno=0;
			*horasTrabajadas=this->horasTrabajadas;
		}
		return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno=-1;

			if(this!=NULL && sueldo>=0){
				retorno=0;
				this->sueldo=sueldo;
			}
			return retorno;
}
int employee_setSueldoTxt(Employee* this,char* sueldo){
	int retorno=-1;

			if(this!=NULL && sueldo>=0 ){
				retorno=0;
				this->sueldo=atoi(sueldo);
			}
			return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno=-1;

		if(this!=NULL && sueldo>=0){
			retorno=0;
			*sueldo=this->sueldo;
		}
		return retorno;
}
