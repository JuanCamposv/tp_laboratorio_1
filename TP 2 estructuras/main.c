#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>


int main()
{
     ePersona personas[20];
     inicializar(personas, 20);

     char seguir = 's';

   do
    {

        switch(menu())
        {
            case 1:

                printf("\n-----------------------------------------------------\n\n");

                alta(personas, 20);

                system("pause");

                break;
            case 2:

                printf("\n-----------------------------------------------------\n\n");

                baja(personas, 20);

                break;
            case 3:

                printf("\n-----------------------------------------------------\n\n");

                ordenar(personas);

                mostrarPersonas(personas);

                system("pause");

                break;
            case 4:

                printf("\n-----------------------------------------------------\n\n");

                grafico(personas);

                break;
            case 5:

                printf("\n-----------------------------------------------------\n\n");

                seguir = 'n';

                break;
        }
    }while(seguir=='s');

    return 0;
}
