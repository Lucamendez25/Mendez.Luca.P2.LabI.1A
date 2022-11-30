/*
 * parser.c
 *
 *  Created on: 28 nov. 2022
 *      Author: Luca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movie.h"
#include "parser.h"
#include "utn.h"
//tomar datos y transformalos en otra cosa


int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{

	int retorno = -1;
	char idStr[4];
	char tituloStr[50];
	char idGeneroStr[30];
	char ratingStr[20];

	eMovie* unaPelicula = NULL;


	if(pFile != NULL && pArrayListPeliculas !=NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n"
				,idStr,tituloStr,idGeneroStr,ratingStr);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n"
				,idStr,tituloStr,idGeneroStr,ratingStr);

			unaPelicula = movie_newParametros(idStr, tituloStr, idGeneroStr, ratingStr);

			if(unaPelicula != NULL)
			{
				ll_add(pArrayListPeliculas, unaPelicula);
			}
		}
	}
	retorno = 0;
	return retorno;
}

int parser_guardarTextoMovie(FILE* pFile , LinkedList* pArrayListPeliculas)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListPeliculas);
	eMovie* aux;
	int auxId;
	char auxTitulo[50];
	char auxGenero[50];
	int auxDuracion;


	if(pFile != NULL && pArrayListPeliculas != NULL)
	{
		fprintf(pFile,"id,titulo,genero,duracion\n");

		for(i=0;i<tam;i++)
		{
			aux = (eMovie*)ll_get(pArrayListPeliculas, i);
			if(aux != NULL)
			{
				movie_getId(aux, &auxId);
				movie_getTitulo(aux, auxTitulo);
				movie_getGenero(aux, auxGenero);
				movie_getDuracion(aux, &auxDuracion);
				fprintf(pFile, "%d,%s,%s,%d\n",
				auxId,auxTitulo,auxGenero,auxDuracion);
				retorno = 0;
			}
		}
	}
	return retorno;
}
