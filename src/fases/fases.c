#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fases.h"
#include "../combate/combate.h"
#include "../utils/utils.h"

void inicializarFase(Fase *f, int numeroFase) {
    f->numeroFase = numeroFase;
    f->casasExploradas = 0;
    f->itemMissaoColetado = 0;
    f->chefeDerrotado = 0;

    if (numeroFase == 1) {
        strcpy(f->nomeFase, "Floresta das Almas da Aura");
        strcpy(f->descricaoMissao, "Encontrar o Grimorio Perdido e Derrotar Aura, a Guilhotina!");
        f->fatorDificuldade = 1.0;
    } else if (numeroFase == 2) {
        strcpy(f->nomeFase, "A cidade Dourada de El Dorado");
        strcpy(f->descricaoMissao, "Quebrar a Maldição de Ouro e Derrotar Macht de El Dorado!");
        f->fatorDificuldade = 1.25;
    } else if (numeroFase == 3) {
        strcpy(f->nomeFase, "Castelo do Rei Demonio (Ende)");
        strcpy(f->descricaoMissao, "Recuperar a Espada do Heroi e Derrotar o Rei Demonio!");
        f->fatorDificuldade = 1.5;
    }

    // Configura as 12 casas
    TipoCasa layout[TAM_TABULEIRO] = {
        CASA_INICIO,    // Casa 1
        CASA_VAZIA,     // Casa 2
        CASA_COMBATE,   // Casa 3
        CASA_TESOURO,   // Casa 4
        CASA_COMBATE,   // Casa 5
        CASA_CURA,      // Casa 6
        CASA_ARMADILHA, // Casa 7
        CASA_COMBATE,   // Casa 8
        CASA_VAZIA,     // Casa 9
        CASA_TESOURO,   // Casa 10
        CASA_MISSAO,    // Casa 11
        CASA_CHEFE      // Casa 12
    };

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        f->tabuleiro[i].numero = i + 1;
        f->tabuleiro[i].tipo = layout[i];
        f->tabuleiro[i].visitada = 0;
    }
}

void mostrarTabuleiro(const Fase *f, int posicaoHeroi) {
    printf("\n=================== TABULEIRO DA FASE %d ===================\n", f->numeroFase);
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        char simbolo = ' ';
        switch (f->tabuleiro[i].tipo) {
            case CASA_INICIO:    simbolo = 'I'; break;
            case CASA_VAZIA:     simbolo = '.'; break;
            case CASA_COMBATE:   simbolo = 'X'; break;
            case CASA_TESOURO:   simbolo = '$'; break;
            case CASA_CURA:      simbolo = '+'; break;
            case CASA_ARMADILHA: simbolo = '!'; break;
            case CASA_MISSAO:    simbolo = 'M'; break;
            case CASA_CHEFE:     simbolo = 'C'; break;
        }

        if (i == posicaoHeroi) {
            printf("[H:%d] ", i + 1); // Mostra onde o heroi esta
        } else {
            printf("[%c:%d] ", simbolo, i + 1);
        }
    }
    printf("\nLegenda: [H]=Heroi | [X]=Combate | [$]=Tesouro | [+]=Cura | [!]=Armadilha | [M]=Missao | [C]=Chefe\n");
    printf("============================================================\n");
}

void moverJogador(int *posicao, int passos, Fase *f) {
    *posicao += passos;

    if (f->casasExploradas >= META_EXPLORACAO) {
        // Chefe LIBERADO! Se passar do fim, estaciona na Casa 12 (indice 11)
        if (*posicao >= TAM_TABULEIRO - 1) {
            *posicao = TAM_TABULEIRO - 1;
        }
    } else {
        // Chefe BLOQUEADO! Se alcancar a Casa 12 (indice 11) antes de explorar 5 casas,
        // da a volta pela trilha (Casas 2 a 11) para continuar explorando e evoluindo!
        if (*posicao >= TAM_TABULEIRO - 1) {
            printf("\n[!] O Portao do Chefe ainda esta selado (Exploracao: %d/%d)!\n", 
                   f->casasExploradas, META_EXPLORACAO);
            printf("[!] Voce deu a volta pela trilha para explorar mais a regiao!\n");
            *posicao = (*posicao % (TAM_TABULEIRO - 1));
            if (*posicao == 0) {
                *posicao = 1; // Cai na Casa 2 em vez de voltar para a Casa 1 (Inicio)
            }
        }
    }
}

int missaoCumprida(const Fase *f) {
    return (f->itemMissaoColetado == 1 && f->chefeDerrotado == 1);
}

void executarEventoCasa(Personagem *p, Fase *f, int *posicao) {
    Casa *casaAtual = &f->tabuleiro[*posicao];
    casaAtual->visitada = 1;
    printf("\n>>>   Voce Chegou na Casa %d   <<<\n", casaAtual->numero);

    switch (casaAtual->tipo) {
        case CASA_INICIO:
        case CASA_VAZIA:
            printf("O Caminho Está Calmo Por Aqui, Mas Não Baixe Sua Guarda!!\n");
            break;

        case CASA_COMBATE: {
            printf("[!] INIMIGO AVISTADO [!]\n");
            Monstro inimigo;
            ClasseMonstro sorteio;

            int sortearMonstro = rolarDado(2);

            if (f->numeroFase == 1) {
                sorteio = (sortearMonstro == 1) ? GOBLIN : GOBLIN_LANCEIRO;
            } else if (f->numeroFase == 2) {
                sorteio = (sortearMonstro == 1) ? MIMICO : GARGULA;
            } else {
                sorteio = (sortearMonstro == 1) ? GUARDA_DEMONIO : GENERAL_DEMONIO;
            }

            inicializarMonstro(&inimigo, sorteio, f->fatorDificuldade);
            iniciarCombate(p, &inimigo);
            break;
        }

        case CASA_TESOURO:
            printf(">>>   BAU DO TESOURO ENCONTRADO!!   <<<\n");
            ganharXP(p, 15);
            aplicarBonusAleatorio(p);
            break;

        case CASA_CURA:
            printf("POCAO DE CURA ENCONTRADA!!\n");
            printf("40 de HP Restaurado!!\n");
            curarPersonagem(p, 40);
            break;

        case CASA_ARMADILHA: {
            int danoArmadilha = rolarDado(10) + 5;
            printf("[!]   ARMADILHA   [!]\n");
            printf("Voce caiu nas armadilhas de espinhos! (-%d HP)\n", danoArmadilha);
            danoPersonagem(p, danoArmadilha);
            printf("Vida atual de %s: %d/%d\n", p->nome, p->vida, p->vidaMax);
            break;
        }

        case CASA_MISSAO:
            printf("OBJETIVO ENCONTRADO! Voce descobriu uma pista importante da missao! (+1 Exploracao Extra)\n");
            f->casasExploradas++; // Casa de missao da avanco duplo no contador!
            ganharXP(p, 20);
            break;

        case CASA_CHEFE: {
            Monstro chefe;
            ClasseMonstro tipoChefe;
            if (f->numeroFase == 1) {
                tipoChefe = AURA_CHEFE;
            } else if (f->numeroFase == 2) {
                tipoChefe = MACHT_CHEFE;
            } else {
                tipoChefe = REI_DEMONIO_CHEFE;
            }
            inicializarMonstro(&chefe, tipoChefe, f->fatorDificuldade);
            int resultado = iniciarCombate(p, &chefe);

            if (resultado == 1) {
                f->chefeDerrotado = 1;
            } else if (resultado == 2) {
                printf("Voce recuou estrategicamente da sala do Chefe para a Casa 10!\n");
                *posicao = 9; // Recua para a Casa 10 se fugir do chefe
            }
            break;
        }
    }

    // Incrementa o contador a cada casa visitada (exceto na casa do chefe)
    if (casaAtual->tipo != CASA_CHEFE && heroiVivo(p)) {
        f->casasExploradas++;
        if (f->casasExploradas >= META_EXPLORACAO && f->itemMissaoColetado == 0) {
            f->itemMissaoColetado = 1;
            printf("\n************************************************************\n");
            printf(" [!] EXPLORACAO COMPLETA (%d/%d)! O SELO DO CHEFE SE ROMPEU!\n", 
                   f->casasExploradas, META_EXPLORACAO);
            printf("     Alcance a Casa 12 [C] para enfrentar o Chefe da Fase!\n");
            printf("************************************************************\n");
        }
    }
}

int jogarFase(Personagem *p, int numeroFase) {
    Fase faseAtual;
    inicializarFase(&faseAtual, numeroFase);
    int posicaoHeroi = 0; // Comeca na Casa 1 (indice 0)

    printf("\n************************************************************\n");
    printf("  %s\n", faseAtual.nomeFase);
    printf("  MISSAO: %s\n", faseAtual.descricaoMissao);
    printf("************************************************************\n");
    pausar();

    while (heroiVivo(p) && !missaoCumprida(&faseAtual)) {
        mostrarTabuleiro(&faseAtual, posicaoHeroi);
        printf("Heroi: %s | HP: %d/%d | Nivel: %d (XP: %d/50) | Exploracao p/ Chefe: %d/%d\n", 
               p->nome, p->vida, p->vidaMax, p->nivel, p->xp, 
               faseAtual.casasExploradas, META_EXPLORACAO);

        printf("\nPressione ENTER para lancar o dado de movimento (d6)...");
        getchar();

        int dadoMovimento = rolarDado(6);
        printf("Voce lancou o d6 e tirou: %d! Avancando %d casas...\n", dadoMovimento, dadoMovimento);

        moverJogador(&posicaoHeroi, dadoMovimento, &faseAtual);
        executarEventoCasa(p, &faseAtual, &posicaoHeroi);

        if (heroiVivo(p) && !missaoCumprida(&faseAtual)) {
            pausar();
        }
    }

    if (heroiVivo(p)) {
        printf("\n============================================================\n");
        printf("  FASE %d CONCLUIDA! Missao cumprida com sucesso!\n", numeroFase);
        printf("  Voce descansou no acampamento antes da proxima jornada!\n");
        curarPersonagem(p, p->vidaMax / 2); // Recupera metade da vida maxima entre as fases!
        printf("============================================================\n");
        pausar();
        return 1;
    } else {
        return 0; // Heroi morreu na fase (em combate ou armadilha)
    }
}

void iniciarCampanha(Personagem *p) {
    for (int etapa = 1; etapa <= 3; etapa++) {
        int venceuFase = jogarFase(p, etapa);
        if (!venceuFase) {
            printf("\n============================================================\n");
            printf("                         GAME OVER                          \n");
            printf("       %s tombou na Fase %d... O mal prevaleceu.            \n", p->nome, etapa);
            printf("============================================================\n");
            mostrarStatus(p);
            return;
        }
    }

    printf("\n************************************************************\n");
    printf("             VITORIA EPICA! VOCE ZEROU O JOGO!              \n");
    printf("   O Rei Demonio foi derrotado e o mundo esta em paz!       \n");
    printf("************************************************************\n");
    mostrarStatus(p);
}