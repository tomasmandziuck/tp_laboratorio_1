#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

int faGets(char *string, int leng) {
	int retorno = -1;

	if (string != NULL && leng > 0 && fgets(string, leng, stdin) == string) {
		fflush(stdin);
		if (string[strlen(string) - 1] == '\n') {
			string[strlen(string) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}

int esNum(char *string) {
	int retorno = 1;
	int i = 0;

	if (string[0] == '-') {
		i = 1;
	}
	for (; string[i] != '\0'; i++) {

		if (string[i] > '9' || string[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int getInt(int *elInt) {
	int retorno = -1;
	char buffer[4096];

	if (elInt != NULL && faGets(buffer, sizeof(buffer)) == 0
			&& esNum(buffer)) {
		*elInt = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

int getFloat(float *elFloat) {
	int retorno = -1;
	char buffer[4096];

	if (elFloat != NULL && faGets(buffer, sizeof(buffer)) == 0)
	{
		*elFloat = atof(buffer);
		retorno = 0;
	}
	return retorno;
}

int getString(char *elString) {
	int retorno = -1;
	char buffer[4096];

	fflush(stdin);

	if (elString != NULL && faGets(buffer, sizeof(buffer)) == 0) {
		strcpy(elString, buffer);
		retorno = 0;
	}

	return retorno;

}

int utn_getChar(char* elChar, char* mensaje, char* mensajeError, char min, char max, int intentos){
	int retorno = -1;
	char buffer;

	if(elChar != NULL && mensaje!= NULL && mensajeError != NULL && min <= max && intentos >=0){

		do
		{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&buffer);

		if(buffer <= max && buffer >= min){
			*elChar=buffer;
			retorno=0;
		}
		else
		{
			printf("%s\n",mensajeError);
			intentos--;
		}

		}while(intentos>=0);
	}

	return retorno;
}

int utn_getInt(int* elInt, char* mensaje, char* mensajeError, int min, int max, int intentos){
	int retorno = -1;
	int buffer;
	do {
			if (elInt != NULL && mensaje != NULL && mensajeError != NULL && min <= max && intentos >= 0) {
				printf("%s", mensaje);
				if (getInt(&buffer) == 0 && buffer >= min&& buffer <= max) {
					*elInt = buffer;
					retorno = 0;
					break;
				}
				printf("%s \n", mensajeError);
				intentos--;
			}

		} while (intentos >= 0);


	return retorno;
}

int utn_getFloat(float *elFloat, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos) {

	float buffer;
	int retorno = -1;

	do {
		if (elFloat != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0) {
			printf("%s", mensaje);
			if (getFloat(&buffer) == 0 && buffer >= minimo&& buffer <= maximo) {
				*elFloat = buffer;
				retorno = 0;
				break;
			}
			printf("%s \n", mensajeError);
			intentos--;
		}

	} while (intentos >= 0);

	return retorno;
}

int utn_getString(char *elString, char *mensaje, char *mensajeError,int minimo, int maximo, int intentos) {
	char buffer[4096];
	int retorno = -1;

	do {
		if (elString != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0) {

			printf("%s", mensaje);
			if (getString(buffer) == 0 && strlen(buffer) >= minimo && strlen(buffer) <= maximo) {

				strcpy(elString, buffer);
				retorno = 0;
				break;

			}
			printf("%s \n", mensajeError);
			intentos--;
		}

	} while (intentos >= 0);

	return retorno;
}
