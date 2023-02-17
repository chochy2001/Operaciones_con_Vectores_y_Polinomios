//
// Created by ohcho on 2/17/2023.
//

#ifndef TAREA_01_IA_FUNCIONESPOLINOMIOS_H
#define TAREA_01_IA_FUNCIONESPOLINOMIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void imprimirPolinomio(float *coeficientes, int grado){
    printf("\nPolinomio: ");
    for (int i = 0; i <= grado; ++i) {
        printf(" %.2fx^%d +", coeficientes[i],i);
    }

}

void llenarPolinomio(float *coeficientes,int grado){
    for (int i = 0; i <= grado; ++i) {
        printf("Dame el coeficiente de x^%d: ",i);
        char input[10];
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        coeficientes[i] = (float)strtof(input, NULL);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }
    }

}

void evaluarEnUnPunto(const float *coeficientes, int grado){
    double p = 0.0;
    printf("Dame el valor en donde quieres evaluar al polinomio\n");
    char input[10];
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    float x = (float)strtof(input, NULL);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    }
    for (int i = 0; i <= grado; ++i) {
        p += coeficientes[i]*pow(x,i);
    }
    printf("El valor del polinomio evaluado en %.2f es: %.2f\n",x,p);

}

#endif //TAREA_01_IA_FUNCIONESPOLINOMIOS_H
