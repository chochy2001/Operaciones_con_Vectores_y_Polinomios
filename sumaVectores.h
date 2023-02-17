//
// Created by jorge on 2/16/23.
//

#ifndef TAREA_01_IA_SUMAVECTORES_H
#define TAREA_01_IA_SUMAVECTORES_H
#include <stdio.h>

void sumaVectores(int *vectorResultado,int *vector1,int *vector2,int cantidad) {
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
#endif //TAREA_01_IA_SUMAVECTORES_H
