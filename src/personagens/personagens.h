#ifndef PERSONAGENS_H
#define PERSONAGENS_H

typedef enum {
    GUERREIRO = 1,
    MAGO,
    ARQUEIRO
} ClassePersonagem;

typedef struct {
    char nome[30];
    ClassePersonagem classe;

    int vida;
    int vidaMax;
    int forca;
    int defesa;
    int agilidade;
    int inteligencia;

    int xp;
    int nivel;

    char arma[50];
    char armadura[50];
    char habilidadeEspecial[50]; // Novo: exigido pelo requisito 1 do PDF

} Personagem;

// Funções de criação e exibição
void inicializarPersonagem(Personagem *p, ClassePersonagem classe);
void mostrarStatus(const Personagem *p);
void escolherPersonagem(Personagem *p);

// Funções de atualização de status via ponteiro (Requisito 6 do PDF)
void danoPersonagem(Personagem *p, int dano);
void curarPersonagem(Personagem *p, int cura);
void ganharXP(Personagem *p, int xpGanho);
void aplicarBonusAleatorio(Personagem *p);
int heroiVivo(const Personagem *p);

#endif