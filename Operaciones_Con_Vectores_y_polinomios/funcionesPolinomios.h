//
// Created by ohcho on 2/17/2023.
//

#ifndef TAREA_01_IA_FUNCIONESPOLINOMIOS_H
#define TAREA_01_IA_FUNCIONESPOLINOMIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función que que recibe los coeficientes del polinomio y lo imprime
void printPolynomial(float *coefficients, int degree){
    printf("\nPolinomio: ");
    for (int i = 0; i <= degree; ++i) {
        printf(" %.2fx^%d +", coefficients[i], i);
    }

}

// Función que recibe los coeficientes del polinomio
void fillPolynomial(float *coefficients, int degree){
    for (int i = 0; i <= degree; ++i) {
        printf("\nDame el coeficiente de x^%d: ",i);
        char input[10];
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        coefficients[i] = (float)strtof(input, NULL);
        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        }
    }

}

// Función que realiza la operación de evaluación en un punto dado
void evaluateAtAPoint(const float *coefficients, int degree){
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
    for (int i = 0; i <= degree; ++i) {
        p += coefficients[i] * pow(x, i);
    }
    printf("El valor del polinomio evaluado en %.2f es: %.2f\n",x,p);

}

// Funcion que realiza la suma entre dos polinomios
void sumOfAPolynomial(const float *coefficients1, const float *coefficients2, int degree){
    float *sum = (float *)calloc(degree, sizeof(float));
    for (int i = 0; i <= degree; ++i) {
        sum[i] = coefficients1[i] + coefficients2[i];
    }
    printPolynomial(sum, degree);
}

// Función que realiza la resta entre dos polinomios 
void subtractionOfAPolynomial(const float *coefficients1, const float *coefficients2, int degree){
    float *subtraction1 = (float *)calloc(degree, sizeof(float));
    float *subtraction2 = (float *)calloc(degree, sizeof(float));

    for (int i = 0; i <= degree; ++i) {
        subtraction1[i] = coefficients1[i] - coefficients2[i];
    }
    for (int i = 0; i <= degree; ++i) {
        subtraction2[i] = coefficients2[i] - coefficients1[i];
    }

    printf("\nResta del polinomio 1 menos el polinomio 2 \n");
    printPolynomial(subtraction1, degree);

    printf("\nResta del polinomio 2 menos el polinomio 1 \n");
    printPolynomial(subtraction2, degree);

}


// Función que realiza la multiplicación 
void multiplicationOfAPolynomial(const float *coefficients1, const float *coefficients2, int degree) {
    float *multiplication = (float *)calloc(degree * 2, sizeof(float));

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= degree; ++j) {
            multiplication[i + j] += coefficients1[i] * coefficients2[j];
        }
    }

    printPolynomial(multiplication, degree * 2);
}

// Función que calcula la derivada del polinomio 
void derivativeOfAPolynomial(const float *coefficients, int degree){
    float *derivative = (float *)calloc(degree, sizeof(float));
    for (int i = 0; i <= degree; ++i) {
        derivative[i] = coefficients[i] * (float)(i);
    }
    for (int i = degree; i >= 0; --i) {
        printf("%.2fx^%d + ", derivative[i], i - 1);
    }

}

// Función que calcula la integral del polinomio 
void integralOfAPolynomial(const float *coefficients, int degree){
    float *integral = (float *)calloc(degree + 2, sizeof(float));
    printf("C");
    for (int i = 0; i <= degree; ++i) {
        integral[i]= coefficients[i] / (float)(i + 1);
        printf(" + %.2fx^%d",integral[i],i+1);
    }
}

#endif //TAREA_01_IA_FUNCIONESPOLINOMIOS_H
