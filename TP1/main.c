#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

int main()
{
    char seguir='s';
    int opcion=0;
    float op1=0;
    float op2=0;
    int confirm;
    int flag=0;
    char auxChar;

    do
    {
        if(flag==0)
        {
            printf("Ingrese el primer operando: ");
            scanf("%f", &op1);

            printf("\n");

            printf("Ingrese el segundo operando: ");
            scanf("%f", &op2);

            flag=1;
        }
        printf("\n:: C A L C U L A D O R A ::\n\n");
        printf("1- Ingresar 1er operando (%.2f)\n", op1);
        printf("2- Ingresar 2do operando (%.2f)\n", op2);
        printf("3- Calcular la suma.(%.2f+%.2f)\n", op1, op2);
        printf("4- Calcular la resta.(%.2f-%.2f)\n", op1, op2);
        printf("5- Calcular la division.(%.2f/%.2f)\n", op1, op2);
        printf("6- Calcular la multiplicacion.(%.2f*%.2f)\n", op1, op2);
        printf("7- Calcular el factorial.(%.2f!)\n", op1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");

        scanf("%d",&opcion);

        while(opcion<1 || opcion>9)
        {
            printf("\nError, la opcion ingresada debe ser entre 1 y 9. Reingrese: ");
            scanf("%d", &opcion);
        }

         switch(opcion)
         {
            case 1:
                printf("Ingrese 1er operando: ");
                scanf("%f", &op1);

                break;
            case 2:
                printf("Ingrese 2do operando: ");
                scanf("%f", &op2);

                break;

            case 3:
                sumarValores(op1, op2);

                system("pause");

                break;
            case 4:
                restarValores(op1, op2);

                system("pause");

                break;
            case 5:
                divValores(op1, op2);

                system("pause");

                break;
            case 6:
                multValores(op1, op2);

                system("pause");

                break;
            case 7:
                factValores(op1);
                system("pause");
                break;
            case 8:
                todasValores(op1, op2);

                system("pause");

                break;
            case 9:
                printf("Confirma que desea salir? s/n: ");
                fflush(stdin);
                scanf("%c", &auxChar);

                while(!validarSeguir(auxChar))
                {
                    printf("\nError, ingrese s/n: ");
                    fflush(stdin);
                    scanf("%c", &auxChar);
                }

                confirm=auxChar;

                if(confirm=='s')
                {
                    seguir = 'n';
                }
                break;
         }

        } while(seguir=='s');

return 0;
}
