//
// Created by jorge on 2/16/23.
//

#ifndef TAREA_01_IA_FUNCIONESVECTORES_H
#define TAREA_01_IA_FUNCIONESVECTORES_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void imprimirVectores(int *vector1,int *vector2,int cantidad){
    printf("\nVector 1: ");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vector1[i]);
    }
    printf(")\n");

    printf("Vector 2: ");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vector2[i]);
    }
    printf(")\n");

}

void sumaVectores(int *vectorResultado,const int *vector1,const int *vector2,int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] + vector2[i];
    }
    printf("El resultado de tu vector es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vectorResultado[i]);
    }
    printf(")");
}

void restaVectores(int *vectorResultado,const int *vector1,const int *vector2,int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] - vector2[i];
    }
    printf("El resultado de restar vector1 menos vector2 es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vectorResultado[i]);
    }
    printf(")");
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector2[i] - vector1[i];
    }
    printf("\nEl resultado de restar vector2 menos vector1  es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vectorResultado[i]);
    }
    printf(")");
}

void productoPorUnEscalar(int *vectorResultado,const int *vector1,const int *vector2,int cantidad) {
    char input[10];
    int escalar;
    printf("Dame el valor del escalar por el que quieres multiplicar a los vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    escalar = (int) strtol(input, NULL, 10);
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] * escalar;
    }
    printf("El valor del vector 1 Multiplicado por el escalar es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vectorResultado[i]);
    }
    printf(")\n");
    printf("El valor del vector 2 Multiplicado por el escalar es:\n");
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector2[i] * escalar;
    }
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %d, ", vectorResultado[i]);
    }
    printf(")\n");
}

void llenarVectores(int *vector1,int *vector2,int cantidad) {
    char input[10];
    for (int i = 0; i < cantidad; ++i) {
        printf("Ingresa el valor del vector 1 en el indice [%d]", i);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector1[i] = (int)strtol(input, NULL, 10);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }

        printf("Ingresa el valor del vector 2 en el indice [%d]", i);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector2[i] = (int)strtol(input, NULL, 10);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }
    }


}


#endif //TAREA_01_IA_FUNCIONESVECTORES_H
