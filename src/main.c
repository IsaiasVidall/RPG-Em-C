#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "personagens/personagens.h"
#include "monstros/monstros.h"
#include "combate/combate.h"
#include "fases/fases.h"
#include "utils/utils.h"

int main() {
    srand(time(NULL)); // Inicializa a semente de aleatoriedade dos dados

    Personagem heroi;

    printf("============================================================\n");
    printf("              BEM-VINDO AO RPG DE TABULEIRO                 \n");
    printf("============================================================\n\n");

    // Passo 1 do Fluxograma: Escolher o personagem
    escolherPersonagem(&heroi);
    mostrarStatus(&heroi);
    pausar();

    // Passos 2 a 8 do Fluxograma: Iniciar Fases, Tabuleiro e Combates
    iniciarCampanha(&heroi);

    return 0;
}