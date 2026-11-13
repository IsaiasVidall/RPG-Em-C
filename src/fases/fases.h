#ifndef FASES_H
#define FASES_H

#include "../personagens/personagens.h"
#include "../monstros/monstros.h"

#define TAM_TABULEIRO 12
#define META_EXPLORACAO 5

typedef enum {
    CASA_INICIO = 0,
    CASA_VAZIA,
    CASA_COMBATE,
    CASA_TESOURO,
    CASA_CURA,
    CASA_ARMADILHA,
    CASA_MISSAO,
    CASA_CHEFE
} TipoCasa;

// Struct para representar cada casa do tabuleiro
typedef struct {
    int numero;
    TipoCasa tipo;
    int visitada; // Para registrar se o heroi ja passou por aqui
} Casa;

// Struct para representar a Fase e sua Missao
typedef struct {
    int numeroFase;
    char nomeFase[50];
    char descricaoMissao[150];
    double fatorDificuldade;
    int casasExploradas;    // Contador de casas visitadas (meta: 5 para liberar o Chefe)
    int itemMissaoColetado; // 0 = Chefe bloqueado, 1 = Chefe liberado
    int chefeDerrotado;     // 0 = Nao, 1 = Sim
    Casa tabuleiro[TAM_TABULEIRO];
} Fase;

// Funcoes de inicializacao e exibicao
void inicializarFase(Fase *f, int numeroFase);
void mostrarTabuleiro(const Fase *f, int posicaoHeroi);

// Funcoes de movimentacao e eventos (com ponteiros!)
void moverJogador(int *posicao, int passos, Fase *f);
void executarEventoCasa(Personagem *p, Fase *f, int *posicao);
int missaoCumprida(const Fase *f);

// Loop principal da fase e da campanha
int jogarFase(Personagem *p, int numeroFase);
void iniciarCampanha(Personagem *p);

#endif