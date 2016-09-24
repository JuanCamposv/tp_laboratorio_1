#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[21];
    int edad;
    int DNI;
    int estado;

}ePersona;

int buscarLibre(ePersona[], int);

int buscarDNI(ePersona[], int, int);

int menu();

void alta(ePersona[], int);

void inicializar(ePersona[], int);

void baja(ePersona[], int);

void mostrar(ePersona);

void mostrarPersonas(ePersona[]);

void ordenar (ePersona[]);

void grafico(ePersona[]);

#endif // FUNCIONES_H_INCLUDED
