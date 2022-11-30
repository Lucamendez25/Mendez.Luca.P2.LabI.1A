/*
 * movies.c
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

//Lo unico que puedo hacer aca es agregar, sacar, modificar, getters y setters. Printear NO


eMovie* movie_new()
{
	return malloc(sizeof(eMovie));
}
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* duracionStr)
{
	eMovie* unaPelicula;
	int todoOk;

	unaPelicula = movie_new();

	if(unaPelicula != NULL && idStr != NULL && tituloStr != NULL
	&& generoStr != NULL && duracionStr != NULL)
	{
		if(movie_setId(unaPelicula, atoi(idStr))==0 &&
		   movie_setTitulo(unaPelicula, tituloStr)==0 &&
		   movie_setGenero(unaPelicula, generoStr)==0 &&
		   movie_setDuracion(unaPelicula, atoi(duracionStr))==0)
		{
			todoOk=1;
		}

	}
	if(!todoOk)
	{
		free(unaPelicula);
		unaPelicula=NULL;
		printf("\nNo se pudo asignar memoria..\n");
	}

	return unaPelicula;
}

void Movie_delete(eMovie* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int movie_setId(eMovie* this,int id)
{
	int retorno=-1;

	if(this != NULL && id > 0 )
	{
		retorno = 0;
		this->id = id;
	}

	return retorno;
}

int movie_getId(eMovie* this,int* id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int movie_setTitulo(eMovie* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL && strlen(titulo) > 2 )
    {
        strcpy(this->titulo, titulo);

        retorno = 0;
    }

    return retorno;
}

int movie_getTitulo(eMovie* this,char* titulo)
{
	int retorno=-1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);

		retorno = 0;
	}

	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int movie_setGenero(eMovie* this,char* genero)
{
	int retorno=-1;

	if(this != NULL && genero !=NULL  && strlen(genero) > 2)
	{
		retorno = 0;
		strcpy(this->genero, genero);
	}

	return retorno;
}

int movie_getGenero(eMovie* this,char* genero)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(genero,this->genero);
	}

	return retorno;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int movie_setDuracion(eMovie* this,int duracion)
{
	int retorno=-1;

	if(this != NULL && duracion >= 0 )
	{
		retorno = 0;
		this->duracion = duracion;
	}

	return retorno;
}

int movie_getDuracion(eMovie* this,int* duracion)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*duracion = this->duracion;
	}

	return retorno;
}


void Pelicula_mostrar(eMovie* unaPelicula)
{
	int auxId;
	char auxTitulo[50];
	char auxGeneroStr[20];
	int auxDuracion;

	movie_getId(unaPelicula, &auxId);
	movie_getTitulo(unaPelicula, auxTitulo);
	movie_getGenero(unaPelicula, auxGeneroStr);
	movie_getDuracion(unaPelicula, &auxDuracion);


	if(unaPelicula != NULL)
	{
		printf("|%4d        | %30s|  %15s |  %4d  |\n",
				auxId,auxTitulo,auxGeneroStr,auxDuracion);
	}
	else
	{
		printf("\nError\n");
	}

}



void* movie_mapDuracion (void* pElement)
{
    void* retorno = pElement;
    int max=241;
    int min=100;
    eMovie* auxElement = NULL;
    eMovie* auxNuevaPelicula = NULL;
    int duracionRandom;
    auxNuevaPelicula = movie_new();
    if (auxNuevaPelicula != NULL)
    {
        auxElement = (eMovie*)pElement;
        *auxNuevaPelicula = *auxElement;

		duracionRandom =(rand()%(max-min+1))+min;


        movie_setDuracion(auxNuevaPelicula,duracionRandom);
        retorno = auxNuevaPelicula;
    }

    return retorno;
}



int filterPeliculaGeneroDrama(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Drama")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroComedia(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Comedy")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroAccion(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Action")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroTerror(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Horror")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}


int filterPeliculaGeneroThriller(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Thriller")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroDocumental(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Documentary")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroAnimacion(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Animation")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}

int filterPeliculaGeneroMusical(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Musical")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}


int filterPeliculaGeneroWestern(void* pElement)
{
	int retorno=0;
	eMovie* pAux=NULL;

	if(pElement!=NULL)
	{
		pAux=(eMovie*)pElement;
		if(strcmp(pAux->genero, "Western")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}


int Movie_ordenaPorGenero(void* pPeliculaUno , void* pPeliculaDos)
{
	int retorno = -1;
	char generoPeliculaUno[50];
	char generoPeliculaDos[50];

	int duracionPeliculaUno;
	int duracionPeliculaDos;

	eMovie* peliculaUno = NULL;
	eMovie* peliculaDos = NULL;

	if(pPeliculaUno != NULL && pPeliculaDos != NULL)
	{
		peliculaUno = (eMovie*)pPeliculaUno;
		peliculaDos =  (eMovie*)pPeliculaDos;

		if(peliculaUno != NULL && peliculaDos != NULL)
		{
			movie_getGenero(peliculaUno, generoPeliculaUno);
			movie_getGenero(peliculaDos, generoPeliculaDos);
			if(strcmp(generoPeliculaDos,generoPeliculaUno)==1)
			{
				retorno = 1;
			}
			else
			{
				if(strcmp(generoPeliculaUno,generoPeliculaDos)==0)
				{
					movie_getDuracion(peliculaUno, &duracionPeliculaUno);
					movie_getDuracion(peliculaDos, &duracionPeliculaDos);
					if(duracionPeliculaUno>duracionPeliculaDos)
					{
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}
