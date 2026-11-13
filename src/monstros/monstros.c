#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "monstros.h"
#include "../utils/utils.h"

void inicializarMonstro(Monstro *m, ClasseMonstro classe, double fatorFase){
    m->classe = classe;

    switch (classe){
        case GOBLIN:
            strcpy(m->nome, "Goblin Sorrateiro");
            strcpy(m->descricao, "Um monstro fraco, mas sorrateiro!");
            m->nivel = 1;
            m->tipoMonstro = 0;

            m->xpRecompensa = (int)ceil(20 * fatorFase);
            m->vidaMax = (int)ceil(30 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(6 * fatorFase);
            m->defesa = (int)ceil(3 * fatorFase);
            break;
        case GOBLIN_LANCEIRO:
            strcpy(m->nome, "Goblin Lanceiro");
            strcpy(m->descricao, "A lança é mais pesada do que ele, mas mesmo assim tome cuidado!");
            m->nivel = 1;
            m->tipoMonstro = 0;

            m->xpRecompensa = (int)ceil(20 * fatorFase);
            m->vidaMax = (int)ceil(25 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(7 * fatorFase);
            m->defesa = (int)ceil(3 * fatorFase);
            break;
        case AURA_CHEFE:
            strcpy(m->nome, "Aura, a Guilhotina");
            strcpy(m->descricao, "Fria e pervesa, uma dos Sete Sábios da Destruição. Leal ao rei demônio, mata por prazer.");
            m->nivel = 1;
            m->tipoMonstro = 1;
            m->xpRecompensa = (int)ceil(40 * fatorFase);
            m->vidaMax = (int)ceil(90 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(14 * fatorFase);
            m->defesa = (int)ceil(7 * fatorFase);
            break;
        case GARGULA:
            strcpy(m->nome, "Gargula");
            strcpy(m->descricao, "Uma estátua de pedra sombria animada por magia residual, projetada para esmagar invasores");
            m->nivel = 2;
            m->tipoMonstro = 0;
            m->xpRecompensa = (int)ceil(25 * fatorFase);
            m->vidaMax = (int)ceil(40 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(10 * fatorFase);
            m->defesa = (int)ceil(9 * fatorFase);
            break;
        case MIMICO:
            strcpy(m->nome, "Mimico");
            strcpy(m->descricao, "O pesadelo de aventureiros e elfas curiosas. Um monstro disfarçado de baú de tesouro com dentes afiados");
            m->nivel = 2;
            m->tipoMonstro = 0;
            m->xpRecompensa = (int)ceil(25 * fatorFase);
            m->vidaMax = (int)ceil(30 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(8 * fatorFase);
            m->defesa = (int)ceil(12 * fatorFase);
            break;
        case MACHT_CHEFE:
            strcpy(m->nome, "Macht, de El Dorado");
            strcpy(m->descricao, "Calmo e elegante, o mais forte dos Sete Sábios da Destruição. Busca compreender os sentimentos humanos");
            m->nivel = 2;
            m->tipoMonstro = 1;
            m->xpRecompensa = (int)ceil(60 * fatorFase);
            m->vidaMax = (int)ceil(150 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(21 * fatorFase);
            m->defesa = (int)ceil(17 * fatorFase);
            break;
        case GUARDA_DEMONIO:
            strcpy(m->nome, "Guarda");
            strcpy(m->descricao, "Um demônio de baixo escalão vestido com armadura escura, patrulhando os arredores gélidos de Ende.");
            m->nivel = 3;
            m->tipoMonstro = 0;
            m->xpRecompensa = (int)ceil(30 * fatorFase);
            m->vidaMax = (int)ceil(45 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(12 * fatorFase);
            m->defesa = (int)ceil(16 * fatorFase);
            break;
        case GENERAL_DEMONIO:
            strcpy(m->nome, "General Demônio");
            strcpy(m->descricao, "Comandante implacável das tropas demoníacas, ostentando cicatrizes de batalhas antigas.");
            m->nivel = 3;
            m->tipoMonstro = 0;
            m->xpRecompensa = (int)ceil(30 * fatorFase);
            m->vidaMax = (int)ceil(60 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(17 * fatorFase);
            m->defesa = (int)ceil(20 * fatorFase);
            break;
        case REI_DEMONIO_CHEFE:
            strcpy(m->nome, "Rei Demônio");
            strcpy(m->descricao, "O governante absoluto de Ende. Uma entidade tiranica que assombra o mundo ha milenios.");
            m->nivel = 3;
            m->tipoMonstro = 1;
            m->xpRecompensa = (int)ceil(100 * fatorFase);
            m->vidaMax = (int)ceil(250 * fatorFase);
            m->vida = m->vidaMax;
            m->forca = (int)ceil(30 * fatorFase);
            m->defesa = (int)ceil(25 * fatorFase);
            break;
    }
}

void mostrarMonstro(const Monstro *m){
    printf("\n===== STATUS DO Monstro =====\n");
    printf("Nome do Monstro: %s\n", m->nome);
    printf("Descrição: %s\n", m->descricao);
    if (m->tipoMonstro == 0){
        printf("Classe: Comum\n");
    }
    else{
        printf("Classe: Chefe\n");
    }
    printf("Nível do Monstro: %d\n", m->nivel);
    printf("Vida: %d/%d\n", m->vida, m->vidaMax);
    printf("Força: %d\n", m->forca);
    printf("Defesa: %d\n", m->defesa);
    printf("Recompensa: %dxp\n", m->xpRecompensa);
    printf("================================\n");
}

void danoNoMonstro(Monstro *m, int dano){
    m->vida -= dano;
    if (m->vida < 0) {
        m->vida = 0;
    }
}