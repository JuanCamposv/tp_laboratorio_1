#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define WEB_ENCABEZADO "<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n<meta name='viewport' content='width=device-width, initial-scale=1'>\n<title>Lista peliculas</title>\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n<link href='css/custom.css' rel='stylesheet'>\n</head>\n<body>\n<div class='container'>\n<div class='row'>"
#define WEB_REPETIR "\n<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='[[URL_IMG]]' alt=''>\n</a>\n<h3>\n<a href='#'>[[TITULO]]</a>\n</h3>\n<ul>\n<li>Genero:[[GENERO]]</li>\n<li>Puntaje:[[PUNTAJE]]</li>\n<li>Duracion:[[DURACION]]</li>\n</ul>\n<p>[[DESCRIPCION]]</p>\n</article>"
#define WEB_PIE "\n</div>\n</div>\n<script src='js/jquery-1.11.3.min.js'></script>\n<script src='js/bootstrap.min.js'></script>\n<script src='js/ie10-viewport-bug-workaround.js'></script>\n<script src='js/holder.min.js'></script>\n</body>\n</html>"

typedef struct EMovie
{
    char titulo[100];

    char genero[100];

    int duracion;

    char descripcion[2000];

    int puntaje;

    char linkImagen[200];

}EMovie;

int menu();

int agregarPelicula(EMovie* movie);

int guardarPelicula(EMovie* movie);

int eliminarPelicula(char* movieTitulo);

int modificarPelicula(char* movieTitulo);

void mostrarPeliculas();

EMovie* buscarPelicula(char* movieTitulo);


int generarPagina();

#endif // FUNCIONES_H_INCLUDED
