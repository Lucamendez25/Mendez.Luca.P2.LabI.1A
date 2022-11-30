/*
 * Controller.c
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

int controller_cargarDesdeTextoPeliculas(char* path , LinkedList* pArrayListMovies)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListMovies != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_MovieFromText(pArchivo,pArrayListMovies);
			printf("\nCarga exitosa de peliculas.\n");
			systemPause();
			retorno = 0;
		}
		else
		{
			printf("\nError con la carga de peliculas\n");
		}
		fclose(pArchivo);
	}
    return retorno;
}

int controller_guardarPeliculasModoTexto(char* path , LinkedList* pArrayListMovies)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListMovies != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTextoMovie(pFile, pArrayListMovies);
			printf("\nSe guardo correctamente en texto...\n");
			systemPause();

			fclose(pFile);
		}

		retorno = 0;
	}
    return retorno;
}


int controller_listarPeliculas(LinkedList* pArrayListMovies)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListMovies);
	eMovie* auxMovie;

	if(pArrayListMovies != NULL)
	{
	  printf("\n|==========================LISTA PELICULAS===============================|\n");
		printf("|ID                                 TITULO              GENERO  DURACION |\n");
		printf("|========================================================================|\n");
		for(i=0;i<tam;i++)
		{
			auxMovie = (eMovie*)ll_get(pArrayListMovies, i);
			Pelicula_mostrar(auxMovie);

		}

		retorno = 0;
	}
	else
	{
		printf("\nError\n");
	}
	printf("|========================================================================|\n");
	printf("\n\n");
	systemPause();
    return retorno;
}


int controller_setDuracion(LinkedList* pArrayListMovies, LinkedList* pArrayListMoviesDuracion)
{
    int retorno = -1;

    if (pArrayListMovies != NULL && pArrayListMoviesDuracion!=NULL)
    {
    	pArrayListMoviesDuracion = ll_map(pArrayListMovies,movie_mapDuracion);
    	controller_listarPeliculas(pArrayListMoviesDuracion);
    	ll_clear(pArrayListMovies);
    	*pArrayListMovies=*pArrayListMoviesDuracion;
        retorno = 0;
    }
    return retorno;
}


int controller_filterGenero(LinkedList* pArrayListMovies)
{
	int retorno = -1;
	int opcionFilter;
	char path[50];
	LinkedList* listaPorGenero=NULL;

	if(pArrayListMovies!=NULL)
	{
		opcionFilter=subMenuFilter();
		switch(opcionFilter)
		{
			case 1:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroDrama);
				break;
			case 2:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroComedia);
				break;
			case 3:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroAccion);
				break;
			case 4:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroTerror);
				break;
			case 5:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroThriller);
				break;
			case 6:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroDocumental);
				break;
			case 7:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroAnimacion);
				break;
			case 8:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroMusical);
				break;
			case 9:
				listaPorGenero=ll_filter(pArrayListMovies, filterPeliculaGeneroWestern);
				break;

		}

		if(listaPorGenero)
		{
			pedirPath(path);
			controller_guardarPeliculasModoTexto(path,listaPorGenero);
			controller_listarPeliculas(listaPorGenero);
			retorno = 0;
		}
	}

	return retorno;
}

int controller_ordenarPeliculas(LinkedList* pArrayListMovies)
{
	int retorno = -1;

	if(pArrayListMovies!=NULL)
	{
		ll_sort(pArrayListMovies,Movie_ordenaPorGenero,0);
		controller_listarPeliculas(pArrayListMovies);
	}
	return retorno;
}
