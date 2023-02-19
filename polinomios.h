//
// Created by ohcho on 2/17/2023.
//

#ifndef TAREA_01_IA_POLINOMIOS_H
#define TAREA_01_IA_POLINOMIOS_H

#include "funcionesPolinomios.h"

void polynomials() {
    int degree,option,optionWhile=1;
    float *coefficients1,*coefficients2;

    printf("Programa que realiza operaciones con polinomios de n dimensiones\nDime de que grado ser%c el polinomios\n",160);
    char input[10];
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    degree = (int)strtol(input, NULL, 10);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (degree <= 0) {
        printf("Error: La cantidad debe ser mayor que cero.\n");
        exit(1);
    }
    coefficients1 = (float *)calloc(degree + 1, sizeof(float));
    coefficients2 = (float *)calloc(degree + 1, sizeof(float));
    fillPolynomial(coefficients1, degree);

    do {
        printf("\nQue operacion le gustaria realizar con el polinomio\n");

        printf("0) Salir\n1) Suma\n2) Resta\n3) Valor en Un Punto\n4) Multiplicacion\n5) Derivada\n6) Integral\n");
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        option = (int)strtol(input, NULL, 10);

        if(option == 0){
            optionWhile = option;
        }

        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        } else if (option < 0 || option > 6) {
            printf("Numero fuera de rango\n");
            exit(1);
        }

        switch (option) {
            case 0:
                printf("\nGracias por usar el programa\n");
                break;
            case 1:
                printf("\nSeleccionaste Suma\n");
                printPolynomial(coefficients1, degree);
                fillPolynomial(coefficients2, degree);
                sumOfAPolynomial(coefficients1, coefficients2, degree);
                break;
            case 2:
                printf("\nSeleccionaste Resta\n");
                printPolynomial(coefficients1, degree);
                fillPolynomial(coefficients2, degree);
                subtractionOfAPolynomial(coefficients1, coefficients2, degree);
                break;
            case 3:
                printPolynomial(coefficients1, degree);
                printf("\nSeleccionaste Valor en Un Punto\n");
                evaluateAtAPoint(coefficients1, degree);
                break;
            case 4:
                printPolynomial(coefficients1, degree);
                printf("\nSeleccionaste Multiplicacion\n");
                fillPolynomial(coefficients2, degree);
                multiplicationOfAPolynomial(coefficients1, coefficients2, degree);
                break;
            case 5:
                printPolynomial(coefficients1, degree);
                printf("\nSeleccionaste Derivada\n");
                derivativeOfAPolynomial(coefficients1, degree);
                break;
            case 6:
                printPolynomial(coefficients1, degree);
                printf("\nSeleccionaste Integral\n");
                integralOfAPolynomial(coefficients1, degree);
                break;
            default:
                printf("Opcion no disponible\n");
                break;

        }
    }while(optionWhile != 0);


}

#endif //TAREA_01_IA_POLINOMIOS_H
