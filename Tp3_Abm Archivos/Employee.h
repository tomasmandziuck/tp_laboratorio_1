#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea el espacio en memoria dinamica para un employee
 *
 * \return puntero employee del espacio creado
*/
Employee* employee_new();
/** \brief llama a la funcion employee_new y le carga los datos pasados como cadena de caracteres
 *
 * \param string Id
 * \param string nombre
 * \param string horas trabajadas
 * \param string sueldo
 *
 * \return puntero employee del espacio creado
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
/** \brief llama a la funcion employee_new y le carga los datos pasados en su formato adecuado
 *
 * \param entero Id
 * \param string nombre
 * \param entero horas trabajadas
 * \param entero sueldo
 *
 * \return puntero employee del espacio creado
*/
Employee* employee_newParametrosS(int id,char* nombre,int horasTrabajadasStr, int sueldo);
/** \brief llama a la funcion employee_new y le carga los datos de la estructura pasada
 *
 * \param Employee empleado
 *
 * \return puntero employee del espacio creado
*/
Employee* employee_newParametrosB(Employee emp);
int employee_criterio(void* item1, void* item2);
/** \brief borra de la memoria dinamica al Employee indicado a traves de un free()
 *
 * \param Employee* empleado
 *
 * \return void
*/
void employee_delete(Employee* this);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param entero id
 *
 * \return 0
*/
int employee_setId(Employee* this,int id);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param string id
 *
 * \return 0
*/
int employee_setIdTxt(Employee* this,char* id);
/** \brief toma el dato del Employee indicado y lo asigna en la variable que se le pasa
 *
 * \param Employee* empleado
 * \param entero* id
 *
 * \return 0
*/
int employee_getId(Employee* this,int* id);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param string nombre
 *
 * \return 0
*/
int employee_setNombre(Employee* this,char* nombre);
/** \brief toma el dato del Employee indicado y lo asigna en la variable que se le pasa
 *
 * \param Employee* empleado
 * \param string nombre
 *
 * \return 0
*/
int employee_getNombre(Employee* this,char* nombre);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param int Horas trabajadas
 *
 * \return 0
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param string Horas trabajadas
 *
 * \return 0
*/
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
/** \brief toma el dato del Employee indicado y lo asigna en la variable que se le pasa
 *
 * \param Employee* empleado
 * \param entero* horas Trabajadas
 *
 * \return 0
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param entero sueldo
 *
 * \return 0
*/
int employee_setSueldo(Employee* this,int sueldo);
/** \brief asigna el dato pasado en su lugar correspondiente del puntero employee indicado
 *
 * \param Employee* empleado
 * \param string sueldo
 *
 * \return 0
*/
int employee_setSueldoTxt(Employee* this,char* sueldo);
/** \brief toma el dato del Employee indicado y lo asigna en la variable que se le pasa
 *
 * \param Employee* empleado
 * \param entero* sueldo
 *
 * \return 0
*/
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
