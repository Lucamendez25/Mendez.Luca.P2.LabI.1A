/*
 * Controller.h
 *
 *  Created on: 28 nov. 2022
 *      Author: Luca
 */
#include "LinkedList.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_cargarDesdeTextoPeliculas(char* path ,LinkedList* pArrayListMovies);
int controller_guardarPeliculasModoTexto(char* path , LinkedList* pArrayListMovies);
int controller_listarPeliculas(LinkedList* pArrayListMovies);
int controller_setDuracion(LinkedList* pArrayListMovies, LinkedList* pArrayListMoviesDuracion);
int controller_filterGenero(LinkedList* pArrayListMovies);
int controller_ordenarPeliculas(LinkedList* pArrayListMovies);




#endif /* CONTROLLER_H_ */
