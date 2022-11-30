/*
 * movies.h
 *
 *  Created on: 28 nov. 2022
 *      Author: Luca
 */
#include "LinkedList.h"


#ifndef MOVIE_H_
#define MOVIE_H_

typedef struct{
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
}eMovie;


eMovie* movie_new();
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* duracionStr);
void Movie_delete(eMovie* this);

int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id);

int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);

int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);

int movie_setDuracion(eMovie* this,int duracion);
int movie_getDuracion(eMovie* this,int* duracion);

void Pelicula_mostrar(eMovie* unaPelicula);

void* movie_mapDuracion (void* element);


int filterPeliculaGeneroDrama(void* pElement);//1
int filterPeliculaGeneroComedia(void* pElement);//2
int filterPeliculaGeneroAccion(void* pElement);//3
int filterPeliculaGeneroTerror(void* pElement);//4
int filterPeliculaGeneroThriller(void* pElement);//5
int filterPeliculaGeneroDocumental(void* pElement);//6
int filterPeliculaGeneroAnimacion(void* pElement);//7
int filterPeliculaGeneroMusical(void* pElement);//8
int filterPeliculaGeneroWestern(void* pElement);//9


int Movie_ordenaPorGenero(void* pPeliculaUno , void* pPeliculaDos);
#endif /* MOVIE_H_ */
