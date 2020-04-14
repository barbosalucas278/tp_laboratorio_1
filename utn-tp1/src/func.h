/*
 * func.h
 *
 *  Created on: 2 abr. 2020
 *      Author: Lucas Barbosa
 */

#ifndef FUNC_H_
#define FUNC_H_
#define MIN -32768
#define MAX 32768
#define MAX_ARRAY_CHAR 4068

#endif /* FUNC_H_ */


int Sumar (int x, int y, int* pResultado);

int Restar (int x, int y, int* pResultado);

int Dividir (int x, int y, float* pResultado);

int Multiplicar (int x, int y, int* pRestulado);

int Factorial (int x, int* pResultado);

int getNumber (int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);
int getInt (int* pResultado);
int isNumber (char* cadena);

int mostrarDosValores (int* pVal1, int* pVal2);
