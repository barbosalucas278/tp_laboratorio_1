

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
static int getInt (long* pResultado);
static int isNumber (char* cadena);
/*
 * \brief Se utiliza para sumar 2 variables
 * \param	dos variables enteras
 * \return la suma de las mismas
 * */
int Sumar (long x, long y, long* pResultado){
	int r=0;
	if(pResultado != NULL)
	{
		*pResultado = x + y;
		r=1;
	}
	return r;
}

/*
 * \brief Se utiliza para restar 2 variables
 * \param dos variables enteras
 * \return la resta de las mismas
 * */

int Restar (long x, long y, long* pResultado){
	int r=0;
	if(pResultado != NULL)
	{
	*pResultado  = x - y;
	r=1;
	}
	return r;
}

/*
 * \brief Se utiliza para dividir 2 variables
 * \param dos variables enteras
 * \return la division de las mismas
 * */

int Dividir (long x, long y, float* pResultado){
	float r=0;
	if(pResultado!=NULL){
		if(y != 0){
			*pResultado = (float)x / y;
			r=1;
		}
	}
	return r;
}

/*
 * \brief Se utiliza para multiplicar 2 variables
 * \param dos variables enteras
 * \return el producto de las mismas
 * */

int Multiplicar (long x, long y, long* pResultado)
{
	int r=0;
	if(pResultado != NULL)
	{
	*pResultado = x * y;
	r=1;
	}
	return r;
}

/*
 * \brief Se utiliza para sacar el factorial de 2 variables
 * \param dos variables enteras
 * \return el factorial de las mismas
 * */

int Factorial (long x, double* pResultado)
{
	int r = -1;
	double buffer;
	int i;
	if(pResultado != NULL)
	{
	for(i = 1; i<=x;i++)
	{
		if(i==1){
		buffer = i *(i);
		continue;
		}

		buffer = buffer *(i);

	}
	*pResultado = buffer;
	r=1;
	}
	return r;
}
/*
 * \brief se utiliza para validar si es un int positivo o negativo, sin ninguna otro caracter.
 * \param la cadena de caracteres previamente ingresada por el usuario
 * \return 1 si es un int von la validacion correspondiente -1 si no es un int.
 *
 * */

static int isNumber(char *cadena) {
	int ret=0;
	int i;
	if (cadena != NULL) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && cadena[i] == '-') { //se acepta el - de los negativos
				continue;
			}
			if(cadena[i]>='0' && cadena[i] <='9'){ //solo n�mero
				continue;
			}
			if ((cadena[i] <= '~' && cadena[i] >= ':')|| (cadena[i]<='/' && cadena[i]>='!')) //lo que hice fue poner todos los caracteres de la tabla ASCII como invalidos
			{
				break;
			}
		}
		if (cadena[i] == '\0') {
			ret = 1;
		}
	}
	return ret;
}
/*
 * \brief se utiliza para tomar un numero entero.
 * \param pResultado es el valor de la direccion de memoria en donde voy a guardar lo que voy a tranformar con atoi().
 * \return 1 si es un int -1 si no es un int
 * */
static int getInt(long *pResultado) {
	int ret = 0;
	char buffer[MAX_ARRAY_CHAR];
	if (pResultado != NULL) {
		fflush(stdin);
		buffer[MAX_ARRAY_CHAR-1] = '\0';
		fgets(buffer, MAX_ARRAY_CHAR, stdin);
		if (isNumber(buffer)) {
			*pResultado = atoi(buffer);
			ret = 1;
		}
	}

	return ret;
}
/*
 * \brief se utiliza para pedirle al usuario un numero
 * \param pResultado es la direccion de memoria en donde voy a guardar el numero obtenido
 * \param mensaje es la cadena de caracteres que muestra al inicio de la funcion al usuario
 * \param mensajeError es la cadena de caracteres que se muestra al usuario cuando sucede un error
 * \param min rango minimo del valor ingresado
 * \param max rango maximo del valor ingresado
 * \param reintentos el numero de reintentos para iongresar el numero
 * \return -1 si hay un error y 1 si es un numero.
 *
 */

int get_Number(long *pResultado, char *mensaje, char *mensajeError, long min,
		long max, int reintentos) {
	int ret=0;
	long num;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		while (reintentos > 0) {
			printf("%s", mensaje);
			if (getInt(&num))  // si scanf =1 es porque pudo abrir la variable
			{
				if (num <= max && num >= min)
				{
					break;
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}
		if (reintentos > 0) {
			*pResultado = num; //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
			ret = 1;
		}

	}
	return ret;
}



