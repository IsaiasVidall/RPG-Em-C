#ifndef HISTORIA_H
#define HISTORIA_H

#include "../personagens/personagens.h"

// Prologo do mundo antes do menu principal
void exibirPrologo(void);

// Ato I: Floresta das Almas (Aura)
void exibirDialogoAto1(const Personagem *p);
void exibirDialogoPreAura(const Personagem *p);
void exibirDialogoPosAura(const Personagem *p);

// Ato II: Cidade Dourada de El Dorado (Macht)
void exibirDialogoAto2(const Personagem *p);
void exibirDialogoPreMacht(const Personagem *p);
void exibirDialogoPosMacht(const Personagem *p);

// Ato III: Terras do Norte e Castelo de Ende (Rei Demonio)
void exibirDialogoAto3(const Personagem *p);
void exibirDialogoPreReiDemonio(const Personagem *p);
void exibirDialogoFinal(const Personagem *p);

#endif