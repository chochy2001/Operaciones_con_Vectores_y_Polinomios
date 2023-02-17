#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "funcionesVectores.h"


int main() {
    int cantidad,opcion,opcionWhile=1;

    printf("Programa que realiza operaciones con vectores de n dimensiones\nDime que cuantas dimensiones serán los vectores\n");
    char input[10];
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    cantidad = (int)strtol(input, NULL, 10);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (cantidad <= 0) {
        printf("Error: La cantidad debe ser mayor que cero.\n");
        exit(1);
    }

    int *vector1 = (int *)calloc(cantidad, sizeof(int));
    int *vector2 = (int *)calloc(cantidad, sizeof(int));
    int *vectorResultado = (int *)calloc(cantidad, sizeof(int));

    llenarVectores(vector1,vector2,cantidad);

    do {
    printf("\nQue operacion le gustaria realizar con los vectores\n");

    printf("0) Salir\n1) Suma\n2) Resta\n3) Producto por un escalar\n4) Norma\n5) Angulo entre dos vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    opcion = (int)strtol(input, NULL, 10);

    if(opcion == 0){
        opcionWhile = opcion;
        opcion = opcionWhile;
    }
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (opcion < 1 || opcion > 5) {
        printf("Saliste del programa");
        exit(1);
    }

        switch (opcion) {
            case 1:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Suma\n");
                sumaVectores(vectorResultado,vector1,vector2,cantidad);
                break;
            case 2:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Resta\n");
                restaVectores(vectorResultado,vector1,vector2,cantidad);
                break;
            case 3:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Producto por un Escalar\n");
                productoPorUnEscalar(vectorResultado,vector1,vector2,cantidad);

                break;
            case 4:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Norma\n");
                break;
            case 5:
                imprimirVectores(vector1,vector2,cantidad);
                printf("Seleccionaste Angulo entre 2 vectores\n");
                break;
            default:
                printf("Opcion no disponible\n");
                break;

        }
    }while(opcionWhile!=0);

    return 0;
}

