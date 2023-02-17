//
// Created by jorge on 2/16/23.
//

#ifndef TAREA_01_IA_FUNCIONESVECTORES_H
#define TAREA_01_IA_FUNCIONESVECTORES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void imprimirVectores(float *vector1, float *vector2, int cantidad){
    printf("\nVector 1: ");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vector1[i]);
    }
    printf(")\n");

    printf("Vector 2: ");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vector2[i]);
    }
    printf(")\n");

}

void sumaVectores(float *vectorResultado, const float *vector1, const float *vector2, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] + vector2[i];
    }
    printf("El resultado de tu vector es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vectorResultado[i]);
    }
    printf(")");
}

void restaVectores(float *vectorResultado, const float *vector1, const float *vector2, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] - vector2[i];
    }
    printf("El resultado de restar vector1 menos vector2 es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vectorResultado[i]);
    }
    printf(")");
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector2[i] - vector1[i];
    }
    printf("\nEl resultado de restar vector2 menos vector1  es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vectorResultado[i]);
    }
    printf(")");
}

void productoPorUnEscalar(float *vectorResultado, const float *vector1, const float *vector2, int cantidad) {
    char input[10];
    float escalar;
    printf("Dame el valor del escalar por el que quieres multiplicar a los vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    escalar = strtof(input, NULL);
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector1[i] * escalar;
    }
    printf("El valor del vector 1 multiplicado por el escalar es:\n");
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vectorResultado[i]);
    }
    printf(")\n");
    printf("El valor del vector 2 multiplicado por el escalar es:\n");
    for (int i = 0; i < cantidad; ++i) {
        vectorResultado[i] = vector2[i] * escalar;
    }
    printf("(");
    for (int i = 0; i < cantidad; ++i) {
        printf(" %.2f, ", vectorResultado[i]);
    }
    printf(")\n");
}

float sumarComponentesVector(const float *vector1,int cantidad){
    float suma = 0;
    for (int i = 0; i < cantidad; ++i) {
        suma += vector1[i];
    }
    return suma;
}

void normaDeUnVector(const float *vector1, const float *vector2, int cantidad) {
    float *newVector1 = (float *)calloc(cantidad, sizeof(float));
    float *newVector2 = (float *)calloc(cantidad, sizeof(float));
    float sumaVector1;
    float sumaVector2;

    for (int i = 0; i < cantidad; ++i) {
        newVector1[i] = vector1[i] * vector1[i];
        newVector2[i] = vector2[i] * vector2[i];
    }
    sumaVector1=  sumarComponentesVector(newVector1, cantidad);
    sumaVector2=  sumarComponentesVector(newVector2, cantidad);
    printf("La norma del vector 1 es: %.2f\n", sqrtf(sumaVector1));
    printf("La norma del vector 2 es: %.2f\n", sqrtf(sumaVector2));

}
float normaVectorUnico(const float *vector, int cantidad) {
        float *newVector = (float *)calloc(cantidad, sizeof(float));
        float sumaVector;

        for (int i = 0; i < cantidad; ++i) {
            newVector[i] = vector[i] * vector[i];
        }
        sumaVector =  sumarComponentesVector(newVector, cantidad);
        return sqrtf(sumaVector);

}



void llenarVectores(float *vector1, float *vector2, int cantidad) {
    char input[10];
    for (int i = 0; i < cantidad; ++i) {
        printf("Ingresa el valor del vector 1 en el indice [%d]\n", i + 1);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector1[i] = strtof(input, NULL);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }

        printf("Ingresa el valor del vector 2 en el indice [%d]\n", i + 1);
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        vector2[i] = strtof(input, NULL);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }
    }
}

float productoPunto(const float *vector1, const float *vector2, int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; ++i) {
        suma += vector1[i] * vector2[i];
    }
    return suma;
}

void anguloEntreVectores(float *vector1, float *vector2, int cantidad) {
    float suma = productoPunto(vector1, vector2, cantidad);
    float norma1 = normaVectorUnico(vector1, cantidad);
    float norma2 = normaVectorUnico(vector2, cantidad);
    float angulo = (suma / (norma1 * norma2));
    float resultado  = acosf(angulo);
    double resultadoGrados = resultado * (180 / M_PI);
    printf("El angulo entre los vectores es: %.2f radianes\n", resultado);
    printf("El angulo entre los vectores es: %.2f%c\n", resultadoGrados,167);
}


#endif //TAREA_01_IA_FUNCIONESVECTORES_H
