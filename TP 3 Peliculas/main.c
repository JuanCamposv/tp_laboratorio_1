#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "funciones.h"

int main()
{
    EMovie movie;
    char seguir='s';
    char movieTitulo[20];

    do
    {

        switch(menu())
        {
            case 1:

                printf("\n-----------------------------------------------------\n\n");

                if(agregarPelicula(&movie) == 1)
                {
                    printf("\nPelicula agregada exitosamente.\n\n");
                }

                break;

            case 2:

                printf("\n-----------------------------------------------------\n\n");

                printf("\nIngrese titulo de la pelicula a eliminar: ");

                fflush(stdin);

                gets(movieTitulo);

                if(eliminarPelicula(movieTitulo) == 1)
                {
                    printf("\nPelicula eliminada exitosamente.\n\n");
                }

                break;

            case 3:

                printf("\n-----------------------------------------------------\n\n");

                printf("\nIngrese titulo de la pelicula a modificar: ");

                fflush(stdin);

                gets(movieTitulo);

                if(modificarPelicula(movieTitulo) == 1)
                {
                    printf("\nPelicula modificada exitosamente.\n\n");
                }

                break;

            case 4:

                printf("\n-----------------------------------------------------\n\n");

                if(generarPagina())
                {
                    printf("\nPagina generada exitosamente.\n\n");
                }

                break;

            case 5:

                printf("\n-----------------------------------------------------\n\n");

                mostrarPeliculas();

                break;

            case 6:

                seguir = 'n';

                break;
        }

        system("pause");

    }while(seguir=='s');

    return 0;
}
