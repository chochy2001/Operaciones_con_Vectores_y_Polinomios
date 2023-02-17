//
// Created by ohcho on 2/17/2023.
//

#ifndef TAREA_01_IA_POLINOMIOS_H
#define TAREA_01_IA_POLINOMIOS_H

#include "funcionesPolinomios.h"

void polinomios() {
    int grado,opcion,opcionWhile=1;
    float x,polinomio=0.0,*coeficientes;

    printf("Programa que realiza operaciones con polinomios de n dimensiones\nDime de que grado ser%c el polinomio\n",160);
    char input[10];
    if (fgets(input, 10, stdin) == NULL) {
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    grado = (int)strtol(input, NULL, 10);
    if (errno == ERANGE) {
        printf("Error: Número fuera del rango.\n");
        exit(1);
    } else if (grado <= 0) {
        printf("Error: La cantidad debe ser mayor que cero.\n");
        exit(1);
    }
    coeficientes = (float *)calloc(grado+1, sizeof(float));
    llenarPolinomio(coeficientes,grado);

    do {
        printf("\nQue operacion le gustaria realizar con el polinomio\n");

        printf("0) Salir\n1) Suma\n2) Resta\n3) Valor en Un Punto\n4) Multiplicacion\n5) Derivada\n6) Integral\n");
        if (fgets(input, 10, stdin) == NULL) {
            printf("Error: No se pudo leer la entrada.\n");
            exit(1);
        }
        opcion = (int)strtol(input, NULL, 10);

        if(opcion == 0){
            opcionWhile = opcion;
        }

        if (errno == ERANGE) {
            printf("Error: Número fuera del rango.\n");
            exit(1);
        } else if (opcion < 0 || opcion > 6) {
            printf("Numero fuera de rango\n");
            exit(1);
        }

        switch (opcion) {
            case 0:
                printf("\nGracias por usar el programa\n");
                break;
            case 1:
                printf("\nSeleccionaste Suma\n");
                break;
            case 2:
                printf("\nSeleccionaste Resta\n");
                break;
            case 3:
                imprimirPolinomio(coeficientes,grado);
                printf("\nSeleccionaste Valor en Un Punto\n");
                evaluarEnUnPunto(coeficientes,grado);
                break;
            case 4:
                printf("\nSeleccionaste Multiplicacion\n");
                break;
            case 5:
                printf("\nSeleccionaste Derivada\n");
                break;
            case 6:
                printf("\nSeleccionaste Integral\n");
                break;
            default:
                printf("Opcion no disponible\n");
                break;

        }
    }while(opcionWhile!=0);


}

#endif //TAREA_01_IA_POLINOMIOS_H
