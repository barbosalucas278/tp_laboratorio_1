

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN -32768
#define MAX 32768
/*
 * \brief Se utiliza para imprimir en pantalla dos valores dentro del rango establecido.
 * \param	dos punteros de variables enteras
 * \return 0 si las imprime -1 si no logra imprimirlas
 * */

int mostrarDosValores (int* pVal1, int* pVal2)
{
	int r=-1;
	if(pVal1 != NULL && pVal2 != NULL)
	{
		if((*pVal1 > MIN && *pVal1 < MAX )&&(* pVal2 > MIN && *pVal2 < MAX))
		{
		printf("A = %d   B = %d",*pVal1, *pVal2);
		r=0;
		}
	}
	return r;
}
/*
 * \brief Se utiliza para sumar 2 variables
 * \param	dos variables enteras
 * \return la suma de las mismas
 * */
int Sumar (int x, int y, int* pResultado){
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

int Restar (int x, int y, int* pResultado){
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

int Dividir (int x, int y, float* pResultado){
	float r=0;
	if(y!=0 && pResultado!=NULL){
		*pResultado = (float)x / y;
		r=1;
	}
	return r;
}

/*
 * \brief Se utiliza para multiplicar 2 variables
 * \param dos variables enteras
 * \return el producto de las mismas
 * */

int Multiplicar (int x, int y, int* pResultado)
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

int Factorial (int x, int* pResultado)
{
	int r = -1;
	int buffer;
	int i;
	if(pResultado != NULL)
	{
	for(i = 1; i<=x;i++)
	{
		buffer = i *(i+1);

	}
	*pResultado = buffer;
	r=1;
	}
	return r;
}
/*
 * \brief Se utiliza para sacar verificar si en la cadena existen tipos de datos que no esten entre 0 y 9.
 * \param una array de caracteres
 * \return -1 si tiene caracteres invalidos y 1 si solo tiene numeros entre 0 y 9
 * */

static int esNumerica(char* cadena){
	int ret = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
					break;
			i++;
		}
		if (cadena[i] == '\0')
			ret = 1;
	}
	return ret;
}

/*
 * \brief Se utiliza para captar la cadena de caracteres ingresada por el usuario y si es valida se la transforma en una variable de tipo int.
 * \param direccion de memoria de la variable donde voy a guardar el numero en el main.
 * \return -1 si es invalido y 1 si es numerico el valor ingresado.
 * */

static int getInt(int* pResultado)
{
	int ret = -1 ;
	char buffer[64];
	fgets(buffer, sizeof(buffer),stdin);
	buffer[strlen(buffer)-1] = '\0';
	//FUNCION QUE VALIDA LA CADENA SEGÚN CRITERIO ESTABLECIDO
	if(esNumerica(buffer))
	{
		*pResultado = atoi(buffer);  // <----- atoi() recibe cadena de caracteres y devuelve int. se usa con <stdlib.h>
		ret = 1 ;
	}

	return ret;
}

/*
 * \brief Se utiliza para sacar poder captar un numero entero ingresado por el usuario, y validarlo.
 * \param pResultado es la direccion de memoria de la variable numero en el main.
 * \param mensaje es el mensaje que le queremos mostrar al usuario.
 * \param mensajeError es el mensaje que le queremos mostrar en caso de algun error
 * \param minimo
 * \param maximo son los valores entre los que se tiene que encontrar el valor ingrsado
 * \param reintentos son la cantidad de reintentos tras ocurrirse un error.
 * \return -1 si se quedo sin intentos 0 si la funcion fue procesada correctamente, agregando el numero ingresado a la direccion de memoria
 * 				del puntero.
 * */

int getNumero (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret;
	int num;
	while(reintentos>0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		if(getInt(&num)==1)  // si scanf =1 es porque pudo abrir la variable
		{
		if(num<=maximo && num>=minimo)
			{
			break;
			}
		}
		reintentos--;
		printf("%s",mensajeError);
	}
	if(reintentos==0)
	{
		ret = -1;
	}
	else
	{
		*pResultado = num;  //se asigna en la direccion de memoria del parametro el valor del numero ingresado.
		ret = 0;
	}
	return ret;
}




