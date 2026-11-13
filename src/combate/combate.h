#ifndef COMBATE_H
#define COMBATE_H
#include "../personagens/personagens.h"
#include "../monstros/monstros.h"


typedef enum{
    ATAQUE_BASICO = 1,
    DEFENDER,
    HABILIDADE_ESPECIAL,
    FUGIR
} AcoesCombate;

int iniciarCombate(Personagem *p, Monstro *m);

#endif