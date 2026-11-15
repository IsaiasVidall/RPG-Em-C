# Jornada Além do Fim: RPG de Tabuleiro em C

**Aluno:** Isaias Vidal Medeiros  
**Matrícula:** 20260051831  
**Disciplina:** DCT1106 - Programação (BSI - UFRN)  
**Período Letivo:** 2026.2  
**Professor:** Thommas K. S. Flores  

---

## 📖 História e Ambientação

Inspirado no universo de fantasia de *Sousou no Frieren* (*Frieren e a Jornada para o Além*), o mundo encontra-se sob o domínio sombrio das forças demoníacas lideradas pelo tirânico **Rei Demônio** a partir de seu castelo em **Ende**, no extremo norte do continente.

O jogo conta com uma camada narrativa interativa dividida em um prólogo, três atos e um epílogo:
1. **Ato I — Floresta das Almas da Aura:** O herói desperta sem memórias em um bosque enfeitiçado e é guiado por uma *Alma Perdida*. Para libertar os espíritos aprisionados, deve explorar a floresta e derrotar *Aura, a Guilhotina*, uma dos Sete Sábios da Destruição.
2. **Ato II — A Cidade Dourada de El Dorado:** Após o alerta de um camponês na estrada sobre a maldição *Diagoldze*, o herói adentra a metrópole transformada em ouro maciço para enfrentar o elegante e letal *Macht de El Dorado*, o mais poderoso dos Sete Sábios da Destruição.
3. **Ato III — As Cinzas do Norte e o Castelo de Ende:** Marchando por vilarejos carbonizados no extremo norte, o herói divide seus suprimentos com uma mãe e seu filho sobreviventes, firmando a promessa de derrotar o *Rei Demônio* na batalha final em Ende.

O objetivo final do jogador é explorar cada região, quebrar o selo mágico dos chefes cumprindo a meta de exploração e derrotar o Rei Demônio para restaurar a paz no reino.

---

## 🧙‍♂️ Personagens Jogáveis

O jogador pode escolher entre **3 classes distintas**, cada uma com atributos iniciais balanceados, equipamentos próprios, artes em ASCII e uma **Habilidade Especial** exclusiva:

| Classe | Vida (HP) | Força | Defesa | Agilidade | Inteligência | Arma Inicial | Armadura Inicial | Habilidade Especial |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- | :--- | :--- |
| **Guerreiro** | 120 | 15 | 16 | 6 | 4 | Machado Pesado | Armadura de Aço | **Golpe Relâmpago** *(Foco em Força)* |
| **Mago** | 80 | 5 | 12 | 8 | 16 | Cajado Arcano | Manto Místico | **Zoltraak** *(Foco em Inteligência)* |
| **Arqueiro** | 100 | 10 | 10 | 15 | 8 | Arco Élfico | Armadura de Couro | **Disparo Preciso** *(Foco em Agilidade)* |

---

## 👹 Fases, Missões e Monstros

O jogo possui **3 fases com dificuldade progressiva**. Os atributos base dos monstros são multiplicados pelo `fatorDificuldade` da fase utilizando arredondamento para cima (`ceil` da biblioteca `<math.h>`):

### Fase 1: Floresta das Almas da Aura (`Fator de Escala: 1.0x`)
- **Missão Principal:** Explorar a floresta (5/5), encontrar o Grimório Perdido e derrotar *Aura, a Guilhotina*.

| Monstro | Tipo | Vida | Força | Defesa | Recompensa (XP) | Descrição |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Goblin** | Comum | 30 | 5 | 4 | 20 XP | Pequeno, verde e traiçoeiro. Anda em bando e adora saquear viajantes. |
| **Goblin Lanceiro** | Comum | 25 | 7 | 3 | 20 XP | A lança é mais pesada do que ele, mas mesmo assim tome cuidado! |
| **Aura, a Guilhotina** | **Chefe** | 90 | 14 | 7 | 40 XP | Fria e perversa, uma dos Sete Sábios da Destruição. Leal ao Rei Demônio. |

### Fase 2: A Cidade Dourada de El Dorado (`Fator de Escala: 1.25x`)
- **Missão Principal:** Explorar as ruínas douradas (5/5), quebrar a Maldição de Ouro e derrotar *Macht de El Dorado*.

| Monstro | Tipo | Vida (Escalada) | Força (Escalada) | Defesa (Escalada) | Recompensa (XP) | Descrição |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Mímico** | Comum | 38 | 10 | 15 | 32 XP | O pesadelo de aventureiros e elfas curiosas. Um monstro disfarçado de baú. |
| **Gárgula** | Comum | 50 | 13 | 12 | 32 XP | Estátua de pedra sombria animada por magia residual para esmagar invasores. |
| **Macht, de El Dorado** | **Chefe** | 188 | 27 | 22 | 75 XP | Calmo e elegante, o mais forte dos Sete Sábios da Destruição. |

### Fase 3: Castelo do Rei Demônio - Ende (`Fator de Escala: 1.50x`)
- **Missão Principal:** Explorar os arredores de Ende (5/5), recuperar a Espada do Herói e derrotar o *Rei Demônio*.

| Monstro | Tipo | Vida (Escalada) | Força (Escalada) | Defesa (Escalada) | Recompensa (XP) | Descrição |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Guarda Demônio** | Comum | 68 | 18 | 24 | 45 XP | Demônio de baixo escalão em armadura escura patrulhando Ende. |
| **General Demônio** | Comum | 90 | 26 | 30 | 45 XP | Comandante implacável das tropas demoníacas com cicatrizes de batalhas. |
| **Rei Demônio** | **Chefe Final** | 375 | 45 | 38 | 150 XP | O governante absoluto de Ende. Uma entidade tirânica milenar. |

---

## 🎲 Dinâmica do Jogo e Regras

### 1. Tabuleiro e Sistema de Exploração (Selo do Chefe)
Cada fase possui um tabuleiro de **12 casas** representado por um vetor de estruturas `Casa`:
`[I:1] [.:2] [X:3] [$:4] [X:5] [+:6] [!:7] [X:8] [.:9] [$:10] [M:11] [C:12]`

- **Movimentação (`d6`):** A cada rodada, o jogador lança um dado de 6 faces (`rolarDado(6)`) e avança pelo tabuleiro.
- **Mecânica do Selo do Chefe (`META_EXPLORACAO = 5`):** Para evitar que o jogador alcance o Chefe no Nível 1 apenas tirando números altos no dado, o Portão do Chefe (Casa 12) inicia **selado**. Cada casa visitada aumenta o contador de exploração em `+1` (a Casa 11 de Missão concede `+2` de avanço). Enquanto a exploração for menor que `5/5`, caso o jogador alcance o final do tabuleiro, ele dá a volta pela trilha (Casas 2 a 11) para continuar explorando, enfrentando monstros e fortalecendo seu herói. Ao atingir `5/5`, o selo se rompe e a Casa 12 (`[C]`) é liberada!

### 2. Tipos de Casas (`enum TipoCasa`)
- `[I]` **Início (Casa 1):** Ponto de partida da fase.
- `[.]` **Vazia (Casas 2 e 9):** Caminho calmo, nenhum evento punitivo ocorre.
- `[X]` **Combate (Casas 3, 5 e 8):** Sorteia um dos monstros comuns da fase e inicia o combate por turnos.
- `[$]` **Tesouro (Casas 4 e 10):** Concede `+15 XP` e um **Bônus Aleatório de Atributo** (`+2` em Força, Defesa, Agilidade, Inteligência ou `+10` de Vida Máxima).
- `[+]` **Cura (Casa 6):** Fonte/Poção de cura que restaura `+40 HP` (respeitando o limite de `vidaMax`).
- `[!]` **Armadilha (Casa 7):** Espinhos causam `d10 + 5` de dano direto ao herói.
- `[M]` **Missão (Casa 11):** Concede `+20 XP` e avança o contador de exploração em dobro (`+2`).
- `[C]` **Chefe (Casa 12):** Inicia o diálogo de confronto e a batalha decisiva contra o Chefe da Fase.

### 3. Combate por Turnos e Fórmulas (`d20`)
Nos combates, o jogador escolhe entre 4 ações a cada turno:
1. **Atacar:** Rola um `d20`.
   * Se `d20 == 1`: **Erro Crítico** (causa `0` de dano).
   * Se `d20 == 20`: **Acerto Crítico** (dobra o ataque base + dado antes de subtrair a defesa do monstro).
   * Ataque Normal: `Dano = max(1, AtributoPrincipal + d20 - DefesaMonstro)`. *(O atributo principal é Força para o Guerreiro, Inteligência para o Mago e Agilidade para o Arqueiro).*
2. **Defender:** O herói ergue a guarda, rola um `d20` e soma esse valor como bônus temporário de Defesa durante o turno atual.
3. **Habilidade Especial (Ultimate):** Inicia cada combate com `1 carga` e recarrega `+1 carga` a cada 5 turnos de combate.
   * **Fórmula de Dano:** `((AtributoPrincipal * 2) + (Secundario1 + Secundario2) / 2 + d20) - (DefesaMonstro / 2)` (ignora 50% da defesa inimiga, com dano mínimo garantido de 5).
   * **Efeito Estratégico:** Recupera `vidaMax / 4` de HP do herói e concede permanentemente **`+1` em TODOS os atributos** (Força, Defesa, Agilidade e Inteligência).
4. **Fugir:** Rola um `d20`. Se o resultado for `6` ou `7`, o herói escapa do combate contra monstros comuns sem receber recompensas. Em batalhas contra **Chefes**, a fuga é bloqueada.

- **Turno do Monstro:** Se o monstro sobreviver, ele rola um `d20`. Tirando `1`, erra o ataque; tirando `20`, aplica dano crítico. Caso a defesa total do herói no turno supere o ataque do monstro, ocorre uma **Defesa Perfeita** (`0` de dano sofrido).

### 4. Evolução (XP e Nível) e Condições de Fim de Jogo
- **Recompensas:** Vencer qualquer monstro concede seu XP de recompensa e um **Bônus Aleatório de Atributo**.
- **Level Up:** A cada **50 XP** acumulados, o herói sobe 1 Nível, restaura 100% da vida e recebe permanentemente: `+15 Vida Máxima`, `+2 Força`, `+2 Defesa`, `+2 Agilidade` e `+2 Inteligência`.
- **Acampamento entre Fases:** Ao concluir uma fase, o herói descansa e recupera `50%` de sua Vida Máxima antes da próxima jornada.
- **Vitória e Derrota:** O jogo termina em **Game Over** se a vida do herói chegar a `0` (em combate ou armadilha). O jogador **Vence o Jogo** ao cumprir a missão e derrotar o Rei Demônio na Fase 3, desbloqueando o epílogo da campanha.

---

## 🛠️ Estrutura do Código e Modularização

O projeto foi desenvolvido seguindo o padrão **C99** (`-std=c99`), utilizando apenas bibliotecas padrão (`stdio.h`, `stdlib.h`, `string.h`, `time.h` e `math.h`) e organizado de forma modular:

    ├── README.md
    ├── Makefile
    └── src/
        ├── main.c                        # Ponto de entrada enxuto (exibe prologo e inicia menu/campanha)
        ├── personagens/
        │   ├── personagens.h             # Struct Personagem, Enum ClassePersonagem e prototipos
        │   └── personagens.c             # Criacao, exibicao, ganho de XP/Nivel, cura, dano e bonus via ponteiros
        ├── monstros/
        │   ├── monstros.h                # Struct Monstro, Enum ClasseMonstro e TipoMonstro
        │   └── monstros.c                # Inicializacao dos 9 monstros com escala progressiva (ceil) e dano via ponteiro
        ├── combate/
        │   ├── combate.h                 # Enum AcaoCombate e prototipo do sistema de batalha
        │   └── combate.c                 # Loop de combate por turnos, rolagens de d20, criticos e Habilidade Especial
        ├── fases/
        │   ├── fases.h                   # Structs Fase e Casa, Enum TipoCasa e prototipos do tabuleiro
        │   └── fases.c                   # Tabuleiro de 12 casas, movimentacao (d6), contador de exploracao e eventos
        ├── historia/
        │   ├── historia.h                # Prototipos das cenas narrativas e dialogos da campanha
        │   └── historia.c                # Textos do prologo, dialogos dos 3 atos, pre/pos-chefes e epilogo
        └── utils/
            ├── utils.h                   # Funcoes utilitarias de suporte
            └── utils.c                   # Rolagem de dados (rand), limpeza de buffer (stdin) e pausas de tela

### Principais `struct`, `enum` e Funções
* **Estruturas (`struct`):**
  * `Personagem`: armazena nome, classe, atributos (`vida`, `vidaMax`, `forca`, `defesa`, `agilidade`, `inteligencia`), `xp`, `nivel`, equipamentos e nome da habilidade especial.
  * `Monstro`: armazena nome, descrição, classe/tipo (`comum` ou `chefe`), atributos escalados e `xpRecompensa`.
  * `Casa` e `Fase`: modelam as 12 posições do tabuleiro, o fator de dificuldade (`1.0x`, `1.25x`, `1.50x`), o progresso de exploração e o status do chefe da região.
* **Enumerações (`enum`):**
  * `ClassePersonagem` (`GUERREIRO`, `MAGO`, `ARQUEIRO`), `ClasseMonstro` (os 9 inimigos do jogo), `TipoCasa` (`CASA_INICIO`, `CASA_VAZIA`, `CASA_COMBATE`, `CASA_TESOURO`, `CASA_CURA`, `CASA_ARMADILHA`, `CASA_MISSAO`, `CASA_CHEFE`) e `AcaoCombate` (`ATACAR`, `DEFENDER`, `HABILIDADE_ESPECIAL`, `FUGIR`).
* **Manipulação via Ponteiros:**
  * Todas as atualizações de estado e atributos (`receberDanoPersonagem`, `curarPersonagem`, `ganharXP`, `aplicarBonusAleatorio`, `receberDanoMonstro`, `moverJogador` e `executarEventoCasa`) recebem ponteiros (`Personagem *p`, `Monstro *m`, `Fase *f`) para modificar as estruturas diretamente na memória.

---

## 💻 Tutorial de Compilação e Execução

### Pré-requisitos
- Compilador **GCC** (`gcc`) instalado:
  - No Linux (Ubuntu/Debian): `sudo apt update && sudo apt install build-essential`
- Utilitário **Make** (opcional, para compilação automatizada).

### Opção 1: Usando o `Makefile` (Linux / macOS)
No terminal, dentro da pasta raiz do projeto, execute:
1. Para compilar o projeto: `make`
2. Para compilar e iniciar o jogo imediatamente: `make run`
3. Para remover o executável gerado: `make clean`

### Opção 2: Compilação Manual Direta com `gcc` (Linux / macOS / Windows)
Caso prefira compilar sem utilizar o `make`, execute na raiz do projeto:

- **No Linux / macOS:**
  `gcc -Wall -Wextra -std=c99 src/main.c src/personagens/personagens.c src/monstros/monstros.c src/combate/combate.c src/fases/fases.c src/utils/utils.c src/historia/historia.c -o jogo -lm && ./jogo`

- **No Windows (CMD / PowerShell com MinGW):**
  `gcc -Wall -Wextra -std=c99 src/main.c src/personagens/personagens.c src/monstros/monstros.c src/combate/combate.c src/fases/fases.c src/utils/utils.c src/historia/historia.c -o jogo.exe -lm` e depois `jogo.exe`

---

## 🎮 Como Jogar (Passo a Passo no Terminal)

O jogo funciona inteiramente pelo teclado no terminal:

1. **Avançar Diálogos e Eventos:** Sempre que o jogo exibir um trecho da história ou o resultado de um evento, pressione **`ENTER`** para avançar.
2. **Criação do Herói:** No início da partida, digite o **nome do seu personagem** e pressione `ENTER`. Em seguida, digite o número da classe desejada (`1` para Guerreiro, `2` para Mago ou `3` para Arqueiro) e confirme com `ENTER`.
3. **Movimentação no Tabuleiro:** A cada rodada na fase, pressione **`ENTER`** para lançar o dado de 6 faces (`d6`). O herói avançará automaticamente pelas casas do tabuleiro `[1 a 12]` e ativará o evento da casa onde cair.
4. **Menu de Combate:** Ao encontrar um monstro ou Chefe, escolha sua ação no turno digitando o número correspondente e pressionando `ENTER`:
   - Digite **`1`** para **Atacar** (ataque básico com rolagem de `d20`);
   - Digite **`2`** para **Defender** (aumenta sua defesa no turno atual com rolagem de `d20`);
   - Digite **`3`** para usar a **Habilidade Especial** (causa dano elevado ignorando metade da defesa inimiga, cura vida e aumenta atributos — consome 1 carga);
   - Digite **`4`** para tentar **Fugir** (disponível apenas contra monstros comuns).
5. **Objetivo de Cada Fase:** Continue lançando o dado e explorando o tabuleiro até atingir a meta de exploração (`5/5`). Quando o selo se romper, alcance a **Casa 12 (`[C]`)** e vença o Chefe da região para avançar ao próximo Ato!

---

## 🎥 Vídeo de Demonstração (Gameplay)

* **Assista à Gameplay e Explicação do Projeto:** [Clique aqui para assistir ao vídeo no YouTube / Google Drive](https://drive.google.com/file/d/1BXojRjgmxKhDnEKikwKqElVuHGaOsf-c/view?usp=drive_link)
