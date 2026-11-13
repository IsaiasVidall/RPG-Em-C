#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int rolarDado(int lados){
    return rand() % lados + 1;
}

void pausar(void){
    printf("Pressione ENTER para continuar...\n");
    limparEntrada();
}