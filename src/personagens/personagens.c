#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagens.h"
#include "../utils/utils.h"

void inicializarPersonagem(Personagem *p, ClassePersonagem classe) {
    // Inicializa qualquer classe no nivel 1 e xp 0
    p->xp = 0;
    p->nivel = 1;

    switch (classe) {
        case GUERREIRO:
            p->classe = GUERREIRO;
            p->vida = 120;
            p->vidaMax = 120;
            p->forca = 15;
            p->defesa = 16;
            p->agilidade = 6;
            p->inteligencia = 4;
            strcpy(p->arma, "Machado Pesado");
            strcpy(p->armadura, "Armadura de Aço");
            strcpy(p->habilidadeEspecial, "Golpe Relâmpago (2x Força)");
            break;

        case MAGO:
            p->classe = MAGO;
            p->vida = 80;
            p->vidaMax = 80;
            p->forca = 5;
            p->defesa = 12;
            p->agilidade = 8;
            p->inteligencia = 16;
            strcpy(p->arma, "Cajado Arcano");
            strcpy(p->armadura, "Manto Místico");
            strcpy(p->habilidadeEspecial, "Zoltraak (2x Inteligência)");
            break;

        case ARQUEIRO:
            p->classe = ARQUEIRO;
            p->vida = 100;
            p->vidaMax = 100;
            p->forca = 10;
            p->defesa = 10;
            p->agilidade = 15;
            p->inteligencia = 8;
            strcpy(p->arma, "Arco Élfico");
            strcpy(p->armadura, "Armadura de Couro");
            strcpy(p->habilidadeEspecial, "Disparo Preciso (Agi + Força)");
            break;

        default:
            printf("Classe invalida!\n");
            break;
    }
}

void mostrarStatus(const Personagem *p) {
    printf("\n===== STATUS DO PERSONAGEM =====\n");
    printf("Nome do Personagem: %s\n", p->nome);
    
    if (p->classe == GUERREIRO) printf("Classe: Guerreiro\n");
    else if (p->classe == MAGO) printf("Classe: Mago\n");
    else if (p->classe == ARQUEIRO) printf("Classe: Arqueiro\n");

    printf("Nível do Personagem: %d (XP: %d/50)\n", p->nivel, p->xp);
    printf("Vida: %d/%d\n", p->vida, p->vidaMax);
    printf("Força: %d\n", p->forca);
    printf("Defesa: %d\n", p->defesa);
    printf("Agilidade: %d\n", p->agilidade);
    printf("Inteligência: %d\n", p->inteligencia);
    printf("Arma: %s\n", p->arma);
    printf("Armadura: %s\n", p->armadura);
    printf("Habilidade Especial: %s\n", p->habilidadeEspecial);
    printf("================================\n");
}

void escolherPersonagem(Personagem *p) {
    int opcao;
    int resultado;

    printf("===== ESCOLHA SEU PERSONAGEM =====\n");
    printf("1 - Guerreiro\n");
    printf("2 - Mago\n");
    printf("3 - Arqueiro\n");

    do {
        printf("Escolha uma classe: ");
        resultado = scanf("%d", &opcao);

        if (resultado == EOF) {
            printf("Entrada encerrada!\n");
            return;
        }

        limparEntrada();

        if (resultado != 1) {
            printf("Digite um numero inteiro!\n");
            opcao = 0;
        } else if (opcao < 1 || opcao > 3) {
            printf("Classe invalida! Tente novamente.\n");
        }
    } while (opcao < 1 || opcao > 3);

    switch (opcao) {
        case 1:
            inicializarPersonagem(p, GUERREIRO);
            break;
        case 2:
            inicializarPersonagem(p, MAGO);
            break;
        case 3:
            inicializarPersonagem(p, ARQUEIRO);
            break;
        default:
            printf("Classe invalida!\n");
            return;
    }

    do {
        printf("Informe o nome do personagem: ");
        if (fgets(p->nome, sizeof(p->nome), stdin) == NULL) {
            printf("Erro ao ler o nome!\n");
            return;
        }
        if (strchr(p->nome, '\n') == NULL) {
            limparEntrada();
        }
        p->nome[strcspn(p->nome, "\n")] = '\0';
        if (p->nome[0] == '\0') {
            printf("Nome invalido!\nTente novamente!\n");
        }
    } while (p->nome[0] == '\0');
}

// --- FUNÇÕES DE ATUALIZAÇÃO VIA PONTEIRO ---

void danoPersonagem(Personagem *p, int dano) {
    p->vida -= dano;
    if (p->vida < 0) {
        p->vida = 0;
    }
}

void curarPersonagem(Personagem *p, int cura) {
    p->vida += cura;
    if (p->vida > p->vidaMax) {
        p->vida = p->vidaMax;
    }
    printf("%s recuperou vida! Vida atual: %d/%d\n", p->nome, p->vida, p->vidaMax);
}

void ganharXP(Personagem *p, int xpGanho) {
    p->xp += xpGanho;
    printf("%s ganhou +%d de XP!\n", p->nome, xpGanho);

    // Sobe de nível a cada 50 de XP acumulado
    while (p->xp >= 50) {
        p->xp -= 50;
        p->nivel++;
        p->vidaMax += 15; 
        p->vida = p->vidaMax; // Cura totalmente ao subir de nível
        p->forca += 2;        
        p->defesa += 2;       
        p->agilidade += 2;    
        p->inteligencia += 2; 
        printf("\n*** LEVEL UP! %s subiu para o Nível %d! Todos os atributos aumentaram! ***\n", p->nome, p->nivel);
        printf("Novo HP: %d/%d | XP restante para o proximo nivel: %d/50\n", p->vida, p->vidaMax, p->xp);
    }
}

void aplicarBonusAleatorio(Personagem *p) {
    int sorteio = rand() % 5;
    switch (sorteio) {
        case 0:
            p->forca += 2;
            printf("Bônus Aleatório: +2 de Força!\n");
            break;
        case 1:
            p->defesa += 2;
            printf("Bônus Aleatório: +2 de Defesa!\n");
            break;
        case 2:
            p->agilidade += 2;
            printf("Bônus Aleatório: +2 de Agilidade!\n");
            break;
        case 3:
            p->inteligencia += 2;
            printf("Bônus Aleatório: +2 de Inteligência!\n");
            break;
        default:
            p->vidaMax += 10;
            p->vida += 10;
            printf("Bônus Aleatório: +10 de Vida Máxima!\n");
            break;
    }
}

int heroiVivo(const Personagem *p) {
    return (p->vida > 0);
}