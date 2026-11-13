#include <stdio.h>
#include "combate.h"
#include "../utils/utils.h"

int iniciarCombate(Personagem *p,  Monstro *m){
    int turno = 1;
    int opcao;
    int dado;
    int habilidadeEspecial = 1; //Em cada combate o seu personagem iniciará com 1 ataque especial disponível.
    int recargaUlt = 0; //Cada ação irá aumentar em 1 a recargaUlt, e quando chegar em 5 vc ganha mais um ataque especial no turno para ajudar em batalhas mais longas

    printf("\n========================================\n");
    if (m->tipoMonstro == 1){
        printf("!!!   CHEFE DA FASE ENCONTRADO   !!!\n");
    }
    else{
        printf("!!!   COMBATE INICIADO   !!!\n");
    }
    mostrarMonstro(m);

    while (p->vida > 0 && m->vida > 0){
        int bonusDefesa = 0;

        printf("\n--- TURNO %d ---\n", turno);
        printf("%s (HP: %d/%d) X %s (HP: %d/%d)\n", p->nome, p->vida, p->vidaMax, m->nome, m->vida, m->vidaMax);
        printf("[Cargas Especial: %d | Recarga Ult: %d/5]\n", habilidadeEspecial, recargaUlt);

        //Menu de ações
        printf("\nESCOLHA UMA ACÃO:\n");
        printf("1 - Atacar\n");
        printf("2 - Defender\n");
        printf("3 - Habilidade Especial (%s)\n", p->habilidadeEspecial);
        printf("4 - Fugir\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0; // Força cair no default se digitar letra
        }
        limparEntrada();

        switch(opcao){
            case ATAQUE_BASICO:
                dado = rolarDado(20);
                int ataque;

                if (p->classe == GUERREIRO) {
                    ataque = p->forca;
                }
                else if (p->classe == MAGO){
                    ataque = p->inteligencia;
                }
                else if (p->classe == ARQUEIRO){
                    ataque = p->agilidade;
                }

                printf("\nVocê atacou!!\n");
                printf("Rolou o dado e caiu em... %d!!\n", dado);

                if (dado == 1){
                    printf("ERRO CRITICO! Você errou o golpe!!\n");
                }
                else{
                    int ataqueTotal = ataque + dado;
                    int dano = ataqueTotal - m->defesa;

                    if (dano <= 0){
                        dano = 1;
                    }
                    if (dado == 20){
                        printf("ACERTO CRITICO!!\n");
                        dano *= 2;
                    }
                    danoNoMonstro(m, dano);
                    printf("Voce causou %d de dano em %s!\n", dano, m->nome);
                }
                recargaUlt++;
                break;

            case DEFENDER: 
                dado = rolarDado(20);
                bonusDefesa = dado; // Guarda o valor do dado para somar na defesa quando o monstro atacar!
                
                printf("\nVoce ergueu a guarda!!\n");
                printf("Rolou o dado de defesa e ganhou +%d de Defesa neste turno!\n", bonusDefesa);
                
                recargaUlt++;
                break;
                
            case HABILIDADE_ESPECIAL:
                if (habilidadeEspecial <= 0) {
                    printf("\nSem cargas de Habilidade Especial! (Recarga: %d/5). Perdeu o turno!\n", recargaUlt);
                    break;
                }
                habilidadeEspecial--; // Gasta 1 carga
                dado = rolarDado(20);
                printf("\n>>> %s usou %s!! (Dado: %d) <<<\n", p->nome, p->habilidadeEspecial, dado);

                int dano = 0;
                if (p->classe == GUERREIRO) {
                    dano = ((p->forca * 2) + (p->inteligencia + p->agilidade) / 2 + dado) - m->defesa;
                } else if (p->classe == MAGO) {
                    dano = ((p->inteligencia * 2) + (p->forca + p->agilidade) / 2) + dado; // Zoltraak ignora a defesa!
                } else if (p->classe == ARQUEIRO) {
                    dano = ((p->agilidade * 2) + (p->forca + p->inteligencia) / 2 + dado) - (m->defesa / 2); // Ignora metade da defesa!
                }

                // Recupera 20% do HP maximo e aumenta +1 em todos os atributos
                curarPersonagem(p, p->vidaMax / 5);
                p->forca += 1;
                p->defesa += 1;
                p->agilidade += 1;
                p->inteligencia += 1;

                if (dano <= 0) {
                    dano = 5;
                }
                danoNoMonstro(m, dano);
                printf("Ataque Devastador! Voce Causou %d de dano em %s!\n", dano, m->nome);
                printf("Efeito Especial: +1 em TODOS os atributos (Forca, Defesa, Agilidade e Inteligencia)!\n");
                break;
                
            case FUGIR:
            if (m->tipoMonstro == 1){
                printf("\n Você Nao Pode Fugir em Batalhas Contra Chefes!!\n");
            }
            else{
                dado = rolarDado(20);
                printf("Tentando Fugir... Rolou %d (Necessário: 6 ou 7)\n", dado);
                if (dado == 6 || dado == 7){
                    printf("Escapou com Sucesso!!\n");
                    return 2; // 2 = Fugir
                }
                else{
                    printf("Falha na Fuga. O inimigo te impediu!!\n");
                }
            }
                break;  
            default:
                printf("Opção Inválida!! Perdeu o Turno!\n");
                break;
        }

        //Verifica se a RecargaUlt completou as 5 cargas
        if (recargaUlt >= 5){
            habilidadeEspecial++;
            recargaUlt = 0;
            printf("\n[!] HABILIDADE ESPECIAL RECARREGADA [!]\n");
            printf("Voce Ganhou +1 Uso de %s!\n", p->habilidadeEspecial);
        }

        //Turno do Monstro

        if (m->vida > 0){
            int dadoMonstro = rolarDado(20);
            int defesaTotalHeroi = p->defesa + bonusDefesa;

            printf("\n>>> Turno de %s!! (Rolou: %d) <<<\n", m->nome, dadoMonstro);

            if (dadoMonstro == 1){
                printf("%s ERROU o Ataque!!\n", m->nome);
            }
            else{
                int danoMonstro = (m->forca + dadoMonstro) - defesaTotalHeroi;

                if (danoMonstro <= 0){
                    danoMonstro = 0;
                    printf("Defesa PERFEITA!! Voce nao Sofreu Danos do Monstro!!\n");
                }
                else {
                    if (dadoMonstro == 20) {
                        printf("ATAQUE CRITICO DO INIMIGO!!\n");
                        danoMonstro *= 2;
                    }
                    danoPersonagem(p, danoMonstro); 
                    printf("%s causou %d de dano em voce!\n", m->nome, danoMonstro);
                }
            }

        }
        pausar();
        turno++;
    }
    // Fim da Luta
    printf("\n========================================\n");
    if (p->vida > 0) {
        printf("VITORIA! Voce derrotou %s!\n", m->nome);
        ganharXP(p, m->xpRecompensa);
        aplicarBonusAleatorio(p);
        return 1; // 1 = Vitoria
    } else {
        printf("DERROTA... %s tombou em combate.\n", p->nome);
        return 0; // 0 = Derrota
    }
}