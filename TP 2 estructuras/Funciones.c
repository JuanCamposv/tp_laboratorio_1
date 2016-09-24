#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

/** \brief obtiene el primer indice disponible de un array.
 *
 * \param array donde buscar el indice disponible.
 * \param tamaño de dicho array.
 * \return devuelve el primer indice disponible encontrado.
 *
 */

int buscarLibre(ePersona personas[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i<tam ; i++)
    {
        if(personas[i].estado == 0)
        {
            indice = i;

            break;
        }
    }
    return indice;
}

/** \brief busca un DNI que coincida con el ingresado.
 *
 * \param array donde buscar un DNI que coincida.
 * \param tamaño de dicho array.
 * \param DNI a ser buscado en el array.
 * \return Devuelve el indice del DNI que coincida con el ingresado.
 *
 */

int buscarDNI(ePersona personas[], int tam, int DNI)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(personas[i].DNI == DNI)
        {
            indice = i;

            break;
        }
    }
    return indice;
}

/** \brief muestra un menu con las opciones a elegir.
 *
 * \return devuelve la opcion elegida por el usuario.
 *
 */

int menu()
{
        int opcion;

        system("cls");

        printf("\n1- Agregar persona.\n\n");

        printf("2- Borrar persona.\n\n");

        printf("3- Imprimir lista ordenada por  nombre.\n\n");

        printf("4- Imprimir grafico de edades.\n\n");

        printf("5- Salir.\n");


        printf("\nElija opcion: ");

        scanf("%d", &opcion);

        while(opcion>5 || opcion<1)
        {
            printf("\nError, opcion no valida. Reingrese opcion: ");
            scanf("%d", &opcion);
        }

        return opcion;

}

/** \brief agrega una persona a la lista.
 *
 * \param array a usar como parametro.
 * \param cantidad de elementos en el array.
 *
 */

void alta(ePersona persona[], int tam)
{
    int indice;
    int DNI;
    int esta;

    indice = buscarLibre(persona, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible\n");
    }
    else
    {
        printf("\nIngrese DNI de la persona: ");
        scanf("%d", &DNI);

        while(DNI<00000001 || DNI>99999999)
        {
            printf("\nError, el DNI ingresado no es valido. Reingrese: ");
            scanf("%d", &DNI);
        }

        esta = buscarDNI(persona, tam, DNI);

        if(esta != -1)
        {
            printf("\nLa persona ya esta dada de alta en el sistema\n");
        }
        else
        {
            persona[indice].DNI = DNI;

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(persona[indice].nombre);


            printf("\nIngrese edad: ");
            scanf("%d", &persona[indice].edad);

            persona[indice].estado = 1;

            printf("\nPersona agregada con exito!!!\n\n");

        }
    }
}

/** \brief inicializa el estado de todas las personas a 0(espacio disponible para el ingreso de datos).
 *
 * \param array de personas a inicializar.
 * \param tamaño de dicho array.
 *
 */

void inicializar(ePersona personas[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
       personas[i].estado = 0;
    }

}

/** \brief Cambia el estado de una persona de 1 a 2(inactivo).
 *
 * \param array usado como parametro.
 * \param tamaño de dicho array.
 *
 */

void baja(ePersona personas[], int tam)
{
    int indice;
    int DNI;
    char baja;

    printf("\nIngrese el DNI de la persona a dar de baja: ");
    scanf("%d", &DNI);

    indice = buscarDNI(personas, tam, DNI);

    if(indice == -1)
    {
        printf("\nLa persona de DNI %d no se encuentra en el sistema.\n\n", DNI);
    }
    else
    {
        printf("\nDatos de la persona\n\n");

        printf("Nombre  edad  DNI\n\n");

        mostrar(personas[indice]);

        printf("\n\nConfirma la baja de la persona? /s");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            personas[indice].estado = 2;
            printf("\nBaja efectuada con exito.\n");
        }
        else
        {
            printf("\n\nLa baja se ha cancelado.\n\n");
        }

    }

      system("pause");
}

/** \brief muestra los datos de una persona ingresada.
 *
 * \param estructura de la persona a mostrar los datos.
 *
 */

void mostrar(ePersona unaPersona)
{
    printf("\n\nNombre  Edad  DNI\n\n");

    printf("%s\t%d   %d\n", unaPersona.nombre, unaPersona.edad, unaPersona.DNI);

}

/** \brief muestra los datos ingresados de varias personas.
 *
 * \param array de personas a mostrar los datos.
 *
 */

void mostrarPersonas(ePersona VariasPersonas[])
{
    int i;

    for(i=0; i<19; i++)
    {
        if(VariasPersonas[i].estado == 1)
        {
            mostrar(VariasPersonas[i]);
        }
    }
    printf("\n\n");
}

/** \brief ordena todas las personas por nombre.
 *
 * \param array de personas a ordenar.
 *
 */

void ordenar (ePersona x[])
{
    int i;
    int j;
    ePersona auxPersona;

    for (i=0; i<19; i++)
        {
            for (j=i+1; j<20; j++)
            {
                if (strcmp(x[i].nombre, x[j].nombre)>0)
                {
                    auxPersona = x[i];
                    x[i] = x[j];
                    x[j] = auxPersona;
                }

            }

        }

}

/** \brief muestra un grafico de edades, dividido entre menores de 18, de edad entre 19 a 35, y mayores a 35.
 *
 * \param array de personas que forman parte del grafico.
 *
 */

void grafico(ePersona personas[])
{

    int i;
    int cont18 = 0;
    int cont19a35 = 0;
    int cont35 = 0;
    int flag=0;
    int mayor;

    for(i=0; i<20; i++)
    {
        if(personas[i].estado==1 && personas[i].edad < 19)
        {
            cont18++;
        }
        if(personas[i].estado==1 && personas[i].edad > 18 && personas[i].edad < 36)
        {
            cont19a35++;
        }
        if(personas[i].estado==1 && personas[i].edad > 35)
        {
            cont35++;
        }

    }


    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {

        if(cont19a35 >= cont18 && cont19a35 >= cont35)
            {

            mayor = cont19a35;

            }

        else
            {

            mayor = cont35;

            }
    }

    printf("\n--+-----------------\n");

    for(i=mayor; i>0; i--)
    {
        if(i<20)
        {
            printf("%02d|",i);
        }

        else
            printf("%02d|",i);

        if(i<= cont18)
        {
            printf("*");
        }

        if(i<= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--+-----------------");

    printf("\n  |<18\t19-35\t>35");

    printf("\n   %d\t%d\t%d\n", cont18, cont19a35, cont35);

    system("pause");


}
