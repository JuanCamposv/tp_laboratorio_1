#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Suma de los dos operandos.
float sumarValores (float op1, float op2)
{
    float rdo;
    rdo= op1+op2;
    printf("La suma entre %.2f y %.2f es %.2f.\n", op1, op2, rdo);
    return rdo;
}

//Resta de los dos operandos.
float restarValores(float op1, float op2)
{
    float rdo;
    rdo= op1-op2;
    printf("La resta entre %.2f y %.2f es %.2f.\n", op1, op2, rdo);
    return rdo;
}

//Division de los dos operandos.
float divValores(float op1, float op2)
{
    float rdo;
    while(op2==0)
    {
        printf("No se puede dividir un numero por 0, eingrese. ");
    }
    rdo= op1/op2;
    printf("La division entre %.2f y %.2f es %.2f.\n", op1, op2, rdo);
    return rdo;
}

//Multiplicacion de los dos operandos.
float multValores(float op1, float op2)
{
    float rdo;
    rdo= op1*op2;
    printf("La multiplicacion entre %.2f y %.2f es %.2f.\n", op1, op2, rdo);
    return rdo;
}

//Calcular el factorial del primer operando.
float factValores(float op1)
{
   int i;
   double fact=1;


   while(op1<=0)
   {
     printf("\nError, no se puede calcular el factorial de 0 o de numeros negativos.\n\nReingrese el primer operando: ");
     scanf("%f", &op1);
   }

  for(i=1;i<=op1;i++)
  {
      fact= fact*i;
  }

  printf("El factorial del numero %.2f es: %.0f\n", op1, fact);

  return fact;

}

//Realizar todas las operaciones.
float todasValores(float op1, float op2)
{
     sumarValores (op1, op2);
     restarValores(op1, op2);
     divValores(op1, op2);
     multValores(op1, op2);
     factValores(op1);

     return 0;

}

//Validacion de la opcion seguir s/n.

int validarSeguir(char seguir)
{
    int esValido = 1;
    if(seguir != 's' && seguir!='n' && seguir != 'S' && seguir!='N')
    {
        esValido =0;
    }

    return esValido;
}
