#ifndef MONSTROS_H
#define MONSTROS_H

typedef enum {
    // Fase 1
    GOBLIN = 1,
    GOBLIN_LANCEIRO,
    AURA_CHEFE,

    // Fase 2
    MIMICO,
    GARGULA,
    MACHT_CHEFE,

    // Fase 3
    GUARDA_DEMONIO,
    GENERAL_DEMONIO,
    REI_DEMONIO_CHEFE
} ClasseMonstro;

typedef struct {
    char nome[30];
    ClasseMonstro classe;
    char descricao[150];
    int vida;
    int vidaMax;
    int forca;
    int defesa;
    int nivel;
    int xpRecompensa;
    int tipoMonstro; // 0 para monstro comum e 1 para chefe
} Monstro;

void inicializarMonstro(Monstro *m, ClasseMonstro classe, double fatorFase);
void mostrarMonstro(const Monstro *m);
void danoNoMonstro(Monstro *m, int dano);

#endif