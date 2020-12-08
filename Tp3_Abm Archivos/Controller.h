/** \brief Abre el archivo en modo texto y llena una linkedlist cono todos sus elementos
 *
 * \param string nombre de archivo a abrir
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Abre el archivo en modo binario y llena una linkedlist cono todos sus elementos
 *
 * \param string nombre de archivo a abrir
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Pide los datos para cargar en la estructura Employee y crea un nuevo nodo en la linkedlist con esos datos
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief busca en el linkedlist el nodo con el indice indicado y le pregunta al usuario si quiere modificar alguno de los datos del empleado
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief busca en el linkedlist el nodo con el indice indicado y le pregunta al usuario si quiere borrar al empleado
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief imprime por pantalla todos los elementos del linkedlist cargado
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief ordena a los empleados segun su sueldo de manera acendente
 *
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief guarda los datos del linkedlist en un archivo en modo texto, si el archivo no existe crea uno
 *
 * \param string nombre de archivo donde guardar
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda los datos del linkedlist en un archivo en modo binario, si el archivo no existe crea uno
 *
 * \param string nombre de archivo donde guardar
 * \param LinkedList* Puntero a la lista
 * \return 0
*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


