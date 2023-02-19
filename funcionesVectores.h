//
// Created by jorge on 2/16/23.
//

#ifndef TAREA_01_IA_FUNCIONESVECTORES_H
#define TAREA_01_IA_FUNCIONESVECTORES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void printVectors(float *vector1, float *vector2, int quantity){
    printf("\nVector 1: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", vector1[i]);
    }
    printf(")\n");

    printf("Vector 2: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", vector2[i]);
    }
    printf(")\n");

}

void sumVectors(float *resultantVector, const float *vector1, const float *vector2, int quantity) {
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i] + vector2[i];
    }
    printf("El resultado de tu vector es:\n");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", resultantVector[i]);
    }
    printf(")");
}

void subtractVectors(float *resultantVector, const float *vector1, const float *vector2, int quantity) {
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i] - vector2[i];
    }
    printf("El resultado de restar vector1 menos vector2 es:\n");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", resultantVector[i]);
    }
    printf(")");
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector2[i] - vector1[i];
    }
    printf("\nEl resultado de restar vector2 menos vector1  es:\n");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", resultantVector[i]);
    }
    printf(")");
}

void scalarMultiplication(float *resultantVector, const float *vector1, const float *vector2, int quantity) {
    char input[10];
    float scalar;
    printf("Dame el valor del escalar por el que quieres multiplicar a los vectores\n");
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    scalar = strtof(input, NULL);
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i] * scalar;
    }
    printf("El valor del vector 1 multiplicado por el escalar es:\n");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", resultantVector[i]);
    }
    printf(")\n");
    printf("El valor del vector 2 multiplicado por el escalar es:\n");
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector2[i] * scalar;
    }
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf(" %.2f, ", resultantVector[i]);
    }
    printf(")\n");
}

float sumVectorComponents(const float *vector1, int quantity){
    float sum = 0;
    for (int i = 0; i < quantity; ++i) {
        sum += vector1[i];
    }
    return sum;
}

void normOfAVector(const float *vector1, const float *vector2, int quantity) {
    float *newVector1 = (float *)calloc(quantity, sizeof(float));
    float *newVector2 = (float *)calloc(quantity, sizeof(float));
    float sumVector1;
    float sumVector2;

    for (int i = 0; i < quantity; ++i) {
        newVector1[i] = vector1[i] * vector1[i];
        newVector2[i] = vector2[i] * vector2[i];
    }
    sumVector1= sumVectorComponents(newVector1, quantity);
    sumVector2= sumVectorComponents(newVector2, quantity);
    printf("La norma del vector 1 es: %.2f\n", sqrtf(sumVector1));
    printf("La norma del vector 2 es: %.2f\n", sqrtf(sumVector2));

}

float normUniqueVector(const float *vector, int quantity) {
        float *newVector = (float *)calloc(quantity, sizeof(float));
        float sumVector;

        for (int i = 0; i < quantity; ++i) {
            newVector[i] = vector[i] * vector[i];
        }
    sumVector = sumVectorComponents(newVector, quantity);
        return sqrtf(sumVector);

}

void fillVectors(float *vector1, float *vector2, int quantity) {
    char input[10];
    for (int i = 0; i < quantity; ++i) {
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

float dotProduct(const float *vector1, const float *vector2, int quantity) {
    float sum = 0;
    for (int i = 0; i < quantity; ++i) {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}

void angleBetweenVectors(float *vector1, float *vector2, int quantity) {
    float sum = dotProduct(vector1, vector2, quantity);
    float norm1 = normUniqueVector(vector1, quantity);
    float norm2 = normUniqueVector(vector2, quantity);
    float degree = (sum / (norm1 * norm2));
    float result  = acosf(degree);
    double resultDegrees = result * (180 / M_PI);
    printf("El grado entre los vectores es: %.2f radianes\n", result);
    printf("El grado entre los vectores es: %.2f%c\n", resultDegrees, 167);
}


#endif //TAREA_01_IA_FUNCIONESVECTORES_H
