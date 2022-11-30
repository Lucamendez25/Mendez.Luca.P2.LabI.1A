/*
 ============================================================================
 Name        : miParcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movie.h"
#include "parser.h"
#include "utn.h"


int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int flagCargar=0;
	int flagSetDuracion=0;
	int flagOrdenarPeliculas=0;
	char path[50];
	srand(time(NULL));
	LinkedList* listaPeliculas= ll_newLinkedList();
	LinkedList* listaPeliculasDuracion = ll_newLinkedList();

	do{
		systemCls();
		opcion=menu();
		switch(opcion)
		{
			case 1:
				if(flagCargar==0 && pedirPath(path))
				{
					if(strcmp(path,"movies.csv")==0)
					{
						controller_cargarDesdeTextoPeliculas(path, listaPeliculas);
						flagCargar=1;
					}
					else
					{
						printf("\nNo existe ese path...\n\nRedirigiendo al menu principal\n");
						systemPause();
					}
				}
				else
				{
					printf("\nYa se realizo la carga de peliculas...\n\nRedirigiendo al menu principal\n");
					systemPause();
				}
				break;
			case 2:
				if(ll_isEmpty(listaPeliculas) == 0 && flagCargar)
				{
					controller_listarPeliculas(listaPeliculas);
				}
				else
				{
					printf("Primero deberia cargar la lista para poder mostrar...\n");
					systemPause();
				}
				break;
			case 3:
				if(ll_isEmpty(listaPeliculas) == 0 && flagCargar)
				{
					controller_setDuracion(listaPeliculas, listaPeliculasDuracion);
					flagSetDuracion=1;
				}
				else
				{
					printf("Primero deberia setear la duracion para entrar en esta opcion...\n");
					systemPause();
				}
				break;
			case 4:
				if(flagSetDuracion==1)
				{
					controller_filterGenero(listaPeliculas);
				}
				else
				{
					printf("Primero deberia setear la duracion para entrar en esta opcion...\n");
					systemPause();
				}
				break;
				break;
			case 5:
				if(flagSetDuracion==1)
				{
					controller_ordenarPeliculas(listaPeliculas);
					flagOrdenarPeliculas=1;
				}
				else
				{
					printf("Primero deberia setear la duracion para entrar en esta opcion...\n");
					systemPause();
				}
				break;
			case 6:
				if(flagOrdenarPeliculas==1 && pedirPath(path))
				{
					controller_guardarPeliculasModoTexto(path, listaPeliculas);
				}
				else
				{
					printf("Primero deberia ordenar las peliculas para entrar en esta opcion...\n");
					systemPause();
				}
				break;
			case 7:
				systemCls();
				cerrandoMenu();
				break;

		}
	}while(opcion!=7);

	return EXIT_SUCCESS;
}
