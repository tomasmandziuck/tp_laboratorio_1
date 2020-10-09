#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int faGets(char *string, int leng);
int esNum(char *string);
int getInt(int *elInt);
int getFloat(float *elFloat);
int getString(char *elString);
int utn_getChar(char* elChar, char* mensaje, char* mensajeError, char min, char max, int intentos);
int utn_getInt(int* elInt, char* mensaje, char* mensajeError, int min, int max, int intentos);
int utn_getFloat(float *elFloat, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos);
int utn_getString(char *elString, char *mensaje, char *mensajeError,int minimo, int maximo, int intentos);

