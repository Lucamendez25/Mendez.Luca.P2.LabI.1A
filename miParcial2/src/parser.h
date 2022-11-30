/*
 * parser.h
 *
 *  Created on: 28 nov. 2022
 *      Author: Luca
 */

#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_

int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_guardarTextoMovie(FILE* pFile , LinkedList* pArrayListPeliculas);

#endif /* PARSER_H_ */
