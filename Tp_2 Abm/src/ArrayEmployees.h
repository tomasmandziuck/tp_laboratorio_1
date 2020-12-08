

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
typedef struct
{
    int Id;
    char apellido[51];
    char nombre[51];
    float salario;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief A la variable isEmpty de la estructura de eEmployee le pone un 1
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */
void Alta(eEmployee emp[], int cant,int* id);
/** \brief Recorre todos los indices del array empleado y ejecuta la funcion mostrarUno
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */
void mostrarTodos (eEmployee emp[],int cant);
/** \brief Muestra los datos de un empleado del indice indicado
 *
 * \param array eEmployee
 * \return 0
 *
 */

void mostrarUno(eEmployee emp);

/** \brief Ejecuta el ordenamiento de burbuja por apellido y sector de forma ascendiente
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */
void ordenarApySec(eEmployee emp[],int cant);

/** \brief Busca un espacio vacio en el array eEmployee y pide datos para cargar
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */
void init (eEmployee emp[], int cant);
/** \brief Muestra todos los datos de los empleados te pide que elijas uno por id y abre un menu para elegir que dato modificar
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */

void Modificacion (eEmployee emp[], int cant);
/** \brief Da la baja logica al empleado deseado reemplazando el 0 por un 1
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */
void Baja (eEmployee emp[], int cant);
/** \brief revisa que todos los indices del array eEmployee tengan un 1 en isEmpty
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return flag 1 si estan vacios 0 si no
 *
 */

int AllEmpty(eEmployee emp[], int cant);
/** \brief Calcula el promedio de todos los salarios cargados hasta el momento
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return promedio
 *
 */

float promedioSalario(eEmployee emp[], int cant);
/** \brief Hace la suma total de todos los salarios cargados y la muestra
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return acumulador (total de salarios)
 *
 */

float totalSalarios(eEmployee emp [], int cant);
/** \brief Revisa cuantos empleados tienen un salario mayor al promedio de salarios
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return contador (cantidad de empleados)
 *
 */

int cantMayorPromedio(eEmployee emp [], int cant);
/** \brief Muestra el total de los salarios, el promedio y cuantos empleados estan por encima del promedio
 *
 * \param array eEmployee
 * \param tamanio del array
 * \return 0
 *
 */

void mostrarSalarios (eEmployee emp [], int cant);



#endif /* ARRAYEMPLOYEES_H_ */
