#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "UTN.h"
#include "funciones.h"

/** \brief Menu de opciones a elegir.
 *
 * \return retorna la opcion elegida por el usuario.
 *
 */

int menu()
{
    int opcion;

        system("cls");

        printf(":: MENU DE OPCIONES ::\n");

        printf("1- Agregar pelicula.\n");

        printf("2- Borrar pelicula.\n");

        printf("3- Modificar pelicula.\n");

        printf("4- Generar pagina web.\n");

        printf("5- Visualizar peliculas.\n");

        printf("6- Salir.\n");

        printf("\nElija una opcion: ");

        scanf("%d",&opcion);

         while(opcion>6 || opcion<1)
        {
            printf("\nError, opcion no valida. Reingrese opcion: ");

            scanf("%d", &opcion);
        }

        return opcion;
}

/** \brief Agrega una pelicula.
 *
 * \param  la estructura a ser agregada al archivo.
 * \return 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 *
 */


int agregarPelicula(EMovie* movie)
{
    printf("\nIngrese titulo: ");

	fflush(stdin);

	gets(movie->titulo);

    printf("\nIngrese genero: ");

	fflush(stdin);

	gets(movie->genero);

    movie->duracion=getInt("\nIngrese duracion: ");

    printf("\nIngrese la descripcion: ");

	fflush(stdin);

	gets(movie->descripcion);

    movie->puntaje=getInt("\nIngrese puntaje: ");

    getString("\nIngrese url imagen: ", movie->linkImagen);

    fflush(stdin);

    return guardarPelicula(movie);
}

/** \brief Guarda una pelicula.
 *
 * \param movie la estructura a ser agregada al archivo.
 * \return retorna 1 o 0 de acuerdo a si pudo guardar la pelicula o no.
 *
 */

int guardarPelicula(EMovie* movie)
{
    FILE* fp;

    fp=fopen("movies.dat","ab+");

    if(fp==NULL)
    {
        printf("Error opening file");

        return 0;
    }

    fwrite(movie,sizeof(EMovie),1,fp);

    fclose(fp);

    return 1;
}

/** \brief Borra una pelicula.
 *
 * \param titulo de la pelicula a eliminar.
 * \return retorna 1 para luego confirmar si se borro la pelicula.
 *
 */

int eliminarPelicula(char* movieTitulo)
{
    FILE *file, *fileAux;

    EMovie* movieFind = buscarPelicula(movieTitulo);

    if(movieFind!=NULL)
    {
        fileAux=fopen("moviesAux.dat","wb+");

        file=fopen("movies.dat","rb");

        EMovie movie;

        while(fread(&movie, sizeof(EMovie),1, file) != 0)
        {
            if (strcmp(movieTitulo, movie.titulo))
            {
                fwrite(&movie, sizeof(EMovie),1, fileAux);
            }
        }
        fclose(file);

        fclose(fileAux);

        fileAux=fopen("moviesAux.dat","rb");

        file=fopen("movies.dat","wb");

        while(fread(&movie, sizeof(EMovie),1, fileAux))
        {
            fwrite(&movie, sizeof(EMovie),1, file);
        }

        fclose(file);

        fclose(fileAux);
    }
    else
    {
        printf("El titulo de la pelicula no fue encontrado\n\n");
    }

    return 1;
}

/** \brief Modifica los datos de una pelicula.
 *
 * \param titulo de la pelicula a modificar.
 * \return retorna una variable de confirmacion.
 *
 */

int modificarPelicula(char* movieTitulo)
{
    int modificacion = 0;

    EMovie* movieFind = buscarPelicula(movieTitulo);

    if(movieFind!=NULL)
    {
        char seguir='s';

        int opcion;

        while(seguir=='s')
        {
            system("cls");

            printf(":: MODIFICAR PELICULA ::\n");

            printf("1- Titulo: %s\n", movieFind->titulo);

            printf("2- Genero: %s\n", movieFind->genero);

            printf("3- Duracion: %d minutos\n", movieFind->duracion);

            printf("4- Descripcion: %s\n", movieFind->descripcion);

            printf("5- Puntaje: %d\n", movieFind->puntaje);

            printf("6- Imagen URL: %s\n\n", movieFind->linkImagen);

            printf("7- Salir (Perdera las modificaciones)\n");

            printf("8- Guardar y Salir\n\n");


            printf("Seleccione la propiedad: ");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:

                    getString("Ingrese titulo:", movieFind->titulo);

                    break;

                case 2:

                    getString("Ingrese genero:", movieFind->genero);

                    break;

                case 3:

                    movieFind->duracion=getInt("Ingrese duracion (minutos):");

                    break;

                case 4:

                    getString("Ingrese descripcion:", movieFind->descripcion);

                    break;

                case 5:

                    movieFind->puntaje=getInt("Ingrese puntaje:");

                    break;

                case 6:

                    getString("Ingrese URL imagen:", movieFind->linkImagen);

                    break;

                case 7:

                    seguir = 'n';

                    break;
                case 8:

                    seguir = 'n';

                    eliminarPelicula(movieTitulo);

                    guardarPelicula(movieFind);

                    modificacion = 1;

                    break;
            }
        }
    }
    else
    {
        printf("El titulo de la pelicula no fue encontrado\n\n");
    }

    return modificacion;
}

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 */

int generarPagina()
{
    FILE *file, *fileWeb;

    file = fopen("movies.dat","rb");

    fileWeb = fopen("index.html","w+");

    if(file==NULL || fileWeb == NULL)
    {
        printf("Error abriendo o creando los archivos.");

        return 0;
    }

    fprintf(fileWeb, "%s", WEB_ENCABEZADO);

    EMovie movie;

    while(fread(&movie, sizeof(EMovie),1, file) != 0)
    {
        char* article = WEB_REPETIR;

        char pts[5], time[5];

        sprintf(pts, "%d", movie.puntaje);

        sprintf(time, "%d", movie.duracion);

        article = str_replace(article, "[[URL_IMG]]", movie.linkImagen);

        article = str_replace(article, "[[TITULO]]", movie.titulo);

        article = str_replace(article, "[[GENERO]]", movie.genero);

        article = str_replace(article, "[[PUNTAJE]]", pts);

        article = str_replace(article, "[[DURACION]]", time);

        article = str_replace(article, "[[DESCRIPCION]]", movie.descripcion);

        fprintf(fileWeb, "%s", article);
    }

    fprintf(fileWeb, "%s", WEB_PIE);

    fclose(fileWeb);

    fclose(file);

    return 1;
}

EMovie* buscarPelicula(char* movieTitulo)
{
    FILE* file;

    file=fopen("movies.dat","rb");

    int encontrado = 0;

    if(file==NULL)
    {
        printf("Error opening file");

        return NULL;
    }

    struct EMovie* movie = malloc(sizeof(EMovie));

    while(fread(movie, sizeof(EMovie),1, file) != 0)
    {
        if (strcmp(movieTitulo, movie->titulo) == 0)
        {
            encontrado = 1;

            break;
        }
    }

    fclose(file);

    if(encontrado == 1)

    return movie;

    free(movie);

    return NULL;
}

void mostrarPeliculas()
{
    FILE* fp;

    fp=fopen("movies.dat","rb");

    if(fp==NULL)
    {
        printf("Error opening file");
    }

    EMovie* movieRet = malloc(sizeof(EMovie));

    while(fread(movieRet,sizeof(EMovie),1,fp)!=0)
    {
        printf("%s %s %d\r\n",movieRet->titulo,movieRet->genero,movieRet->duracion);
    }

    fclose(fp);

    free(movieRet);
}
