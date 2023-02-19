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
        printf("\nDame el coeficiente de x^%d: ",i);
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

void sumaDePolinomio(const float *coeficientes1, const float *coeficientes2, int grado){
    float *suma = (float *)calloc(grado, sizeof(float));
    for (int i = 0; i <= grado; ++i) {
        suma[i] = coeficientes1[i] + coeficientes2[i];
    }
    imprimirPolinomio(suma,grado);
}

void restaDePolinomio(const float *coeficientes1,const float *coeficientes2,int grado){
    float *resta1 = (float *)calloc(grado, sizeof(float));
    float *resta2 = (float *)calloc(grado, sizeof(float));

    for (int i = 0; i <= grado; ++i) {
        resta1[i] = coeficientes1[i] - coeficientes2[i];
    }
    for (int i = 0; i <= grado; ++i) {
        resta2[i] = coeficientes2[i] - coeficientes1[i];
    }

    printf("\nResta del polinomio 1 menos el polinomio 2 \n");
    imprimirPolinomio(resta1, grado);

    printf("\nResta del polinomio 2 menos el polinomio 1 \n");
    imprimirPolinomio(resta2, grado);

}

void multiplicacionDePolinomio(const float *coeficientes1,const float *coeficientes2,int grado) {
    float *multiplicacion = (float *)calloc(grado*2, sizeof(float));

    for (int i = 0; i <= grado; ++i) {
        for (int j = 0; j <= grado; ++j) {
            multiplicacion[i + j] += coeficientes1[i] * coeficientes2[j];
        }
    }

    imprimirPolinomio(multiplicacion, grado*2);
}
void derivadaDePolinomio(const float *coeficientes, int grado){
    float *derivada = (float *)calloc(grado, sizeof(float));
    for (int i = 0; i <= grado; ++i) {
        derivada[i] = coeficientes[i]*(float)(i);
    }
    for (int i = grado; i >= 0; --i) {
        printf("%.2fx^%d + ",derivada[i],i-1);
    }

}

void integralDePolinomio(const float *coeficientes, int grado){
    float *integral = (float *)calloc(grado+2, sizeof(float));
    printf("C");
    for (int i = 0; i <= grado; ++i) {
        integral[i]= coeficientes[i]/(float)(i+1);
        printf(" + %.2fx^%d",integral[i],i+1);
    }
}

#endif //TAREA_01_IA_FUNCIONESPOLINOMIOS_H