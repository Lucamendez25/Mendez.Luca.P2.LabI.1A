/*
 * utn.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Luca
 */
#include "LinkedList.h"

#ifndef UTN_H_
#define UTN_H_



int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
///////////////////////////////////////////////
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
///////////////////////////////////////////////
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
///////////////////////////////////////////////
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
///////////////////////////////////////////////

//
//Funciones mias de validaciones//
//
int validarNumero(char *numero);
///////////////////////////////////////////////
int pedirEntero(char *mensaje,char *mensajeError);
///////////////////////////////////////////////
int menu();
///////////////////////////////////////////////
int subMenuFilter();
//////////////////////////////////////////////
void cerrandoMenu();
//////////////////////////////////////////////
int pedirPath(char *path);
//////////////////////////////////////////////
void systemCls();
///////////////////////////////////////////////
void systemPause();
///////////////////////////////////////////////
#endif /* UTN_H_ */
