#include <stdio.h>
#include "historia.h"
#include "../utils/utils.h"

void exibirPrologo(void) {
    printf("============================================================\n");
    printf("                 CRONICAS DE ENDE: O DESPERTAR              \n");
    printf("============================================================\n\n");
    printf("Em um reino distante, onde a paz e a magia floresciam em\n");
    printf("harmonia, uma sombra milenar ergueu-se das terras gelidas\n");
    printf("do extremo Norte.\n\n");
    printf("O Rei Demonio, governante absoluto do Castelo de Ende, marchou\n");
    printf("com suas legioes e seus crueis Sabios da Destruicao — Aura, a\n");
    printf("Guilhotina, e Macht de El Dorado — devastando cidades inteiras\n");
    printf("e espalhando o caos pelo continente.\n\n");
    printf("Quando os exercitos reais tombaram e toda a esperanca parecia\n");
    printf("perdida, uma antiga lenda comecou a se cumprir: no meio da\n");
    printf("escuridao, surgiria um HEROI capaz de desafiar o destino...\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoAto1(const Personagem *p) {
    printf("\n============================================================\n");
    printf("              ATO I: O DESPERTAR NA FLORESTA                \n");
    printf("============================================================\n\n");
    printf("Voce abre os olhos lentamente. Sua cabeca doi e uma nevoa densa\n");
    printf("cobre as arvores retorcidas ao seu redor. Voce esta confuso e\n");
    printf("nao faz ideia de como veio parar naquele lugar sombrio...\n\n");
    printf("De repente, uma pequena luz azulada se aproxima flutuando.\n\n");
    printf("[Alma Perdida]: \"Ei... voce ai caido no chao! Consegue me ouvir?\n");
    printf("                 Voce esta bem?!\"\n");
    pausar();

    printf("\n[%s]: \"Argh... minha cabeca... Onde eu estou? Como vim parar\n", p->nome);
    printf("       nesta floresta?\"\n\n");
    printf("[Alma Perdida]: \"Gracas aos ceus voce acordou! Voce esta na\n");
    printf("                 Floresta das Almas. O nosso reino foi invadido\n");
    printf("                 e esta sendo devastado pelas forcas do Rei Demonio!\"\n\n");
    printf("[Alma Perdida]: \"Eu tentei lutar para proteger nossa terra, mas\n");
    printf("                 fui derrotado por Aura, a Guilhotina... Agora sou\n");
    printf("                 apenas uma alma presa neste bosque amaldicoado.\"\n");
    pausar();

    printf("\n[%s]: \"Espera um pouco... Rei o que?! Do que voce esta falando?\"\n\n", p->nome);
    printf("[Alma Perdida]: \"Voce perdeu a memoria?! O Rei Demonio e um ser\n");
    printf("                 maligno milenar que governa o Castelo de Ende, no\n");
    printf("                 extremo Norte! Ele quer extinguir toda a humanidade\n");
    printf("                 e espalhou seus monstros e generais pelo mundo.\"\n");
    pausar();

    printf("\n[%s]: \"Bom... se as coisas estao assim, parece que tenho que\n", p->nome);
    printf("       dete-lo. Por onde eu comeco?\"\n\n");
    printf("[Alma Perdida]: \"Para chegar ao Castelo de Ende, voce precisara\n");
    printf("                 primeiro derrotar os subordinados diretos dele:\n");
    printf("                 Aura, nesta floresta, e Macht, na Cidade Dourada!\"\n\n");
    printf("[Alma Perdida]: \"Mas cuidado: os portoes dos chefes estao selados!\n");
    printf("                 Explore ao menos 5 areas em cada regiao para\n");
    printf("                 quebrar o selo magico e ficar forte o bastante.\n");
    printf("                 Por favor, %s... derrote o Rei Demonio e\n", p->nome);
    printf("                 liberte a todos nos desse mal!\"\n\n");
    printf("A alma brilhante desaparece na nevoa. Voce se levanta, empunha\n");
    printf("seu equipamento e inicia sua jornada!\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoPreAura(const Personagem *p) {
    printf("\n============================================================\n");
    printf("          CONFRONTO: CLAREIRA DA BALANCA DA OBEDIENCIA      \n");
    printf("============================================================\n\n");
    printf("Ao cruzar o portao selado da floresta, a nevoa se abre em uma\n");
    printf("clareira silenciosa, cercada por centenas de guerreiros\n");
    printf("decapitados que ainda caminham como marionetes sem vida.\n\n");
    printf("No centro, uma demonia de chifres curvos segura uma balanca\n");
    printf("dourada e sorri friamente ao notar sua presenca.\n\n");
    printf("[Aura, a Guilhotina]: \"Ora, ora... Entao foi voce quem andou\n");
    printf("                       destruindo meus servos pela floresta?\n");
    printf("                       Mais um tolo para minha colecao!\"\n");
    pausar();

    printf("\n[%s]: \"Voce e Aura?! Liberte as almas que voce prendeu neste\n", p->nome);
    printf("       lugar agora mesmo!\"\n\n");
    printf("[Aura, a Guilhotina]: \"Liberar? Hahaha! Em breve, a sua cabeca\n");
    printf("                       tambem me obedecera... MORRA!\"\n\n");
    printf("Sem aviso, um guerreiro da armadura negra salta das sombras\n");
    printf("desferindo um golpe mortal pelas suas costas!\n\n");
    printf("Por puro instinto, %s se esquiva no ultimo segundo! A lamina\n", p->nome);
    printf("corta o ar, destruindo o chao onde voce estava!\n\n");
    printf("[%s]: \"Um ataque covarde?! Isso acaba aqui, Aura!\"\n", p->nome);
    printf("============================================================\n");
    pausar();
}

void exibirDialogoPosAura(const Personagem *p) {
    printf("\n============================================================\n");
    printf("                  A LIBERTACAO DAS ALMAS                    \n");
    printf("============================================================\n\n");
    printf("Com a queda de Aura, a Guilhotina, sua balanca amaldicoada se\n");
    printf("despedaca no chao. As armaduras vazias caem inertes e centenas\n");
    printf("de luzes azuladas comecam a subir suavemente em direcao ao ceu.\n\n");
    printf("Diante de voce, aquela mesma Alma Perdida do inicio da floresta\n");
    printf("surge brilhando intensamente pela ultima vez.\n\n");
    printf("[Alma Perdida]: \"Voce conseguiu, %s! O feiticco de Aura foi\n", p->nome);
    printf("                 desfeito... Finalmente, eu e todas as almas\n");
    printf("                 desta floresta podemos descansar em paz!\"\n");
    pausar();

    printf("\n[%s]: \"Fico feliz que estejam livres. Agora preciso seguir\n", p->nome);
    printf("       em frente para deter os outros.\"\n\n");
    printf("Enquanto o espirito comeca a desaparecer em particulas de luz,\n");
    printf("ele observa a sua postura de combate e abre um sorriso sereno:\n\n");
    printf("[Alma Perdida]: \"Esse seu jeito de lutar... Heh, eu sabia...\n");
    printf("                 Eu sabia que era voce o tempo todo...\"\n\n");
    printf("A luz se dissipa completamente no vento antes de terminar a frase.\n\n");
    printf("[%s]: \"Ei, espere! Sabia o que?! ...Quem sou eu de verdade?\"\n\n", p->nome);
    printf("Apenas o silencio da floresta responde. Com essa duvida ecoando\n");
    printf("em sua mente, voce parte rumo a Cidade Dourada de El Dorado...\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoAto2(const Personagem *p) {
    printf("\n============================================================\n");
    printf("           ATO II: A ESTRADA PARA A CIDADE DOURADA          \n");
    printf("============================================================\n\n");
    printf("Apos deixar a Floresta das Almas para tras, voce segue por uma\n");
    printf("estrada arida. Ao longe, o horizonte reflete um brilho amarelo\n");
    printf("ofuscante que parece tocar as nuvens.\n\n");
    printf("No caminho, um velho campones puxando uma carroca carregada\n");
    printf("de mantimentos para ao ver voce marchar na direcao oposta.\n\n");
    printf("[Campones]: \"Alto la, viajante! Pelas suas armas, vejo que veio\n");
    printf("             do sul... Para onde pensa que esta indo por esta\n");
    printf("             estrada abandonada?\"\n");
    pausar();

    printf("\n[%s]: \"Estou indo para El Dorado. Preciso encontrar e derrotar\n", p->nome);
    printf("       o general Macht para abrir caminho ate o Norte.\"\n\n");
    printf("O velho arregala os olhos, solta as redeas da carroca e da\n");
    printf("um passo para tras, completamente espantado.\n\n");
    printf("[Campones]: \"E-El Dorado?! Voce perdeu o juizo?! Nao de mais\n");
    printf("             nenhum passo! Se entrar naquela cidade, voce vai\n");
    printf("             morrer — ou pior, virar uma estatua para sempre!\"\n");
    pausar();

    printf("\n[%s]: \"Virar uma estatua? Do que voce esta falando?\"\n\n", p->nome);
    printf("[Campones]: \"Macht e o mais poderoso dos Sabios da Destruicao!\n");
    printf("             A maldicao dele, Diagoldze, transforma tudo o que\n");
    printf("             toca em ouro macico... Casas, arvores, guerreiros...\n");
    printf("             Inumeros herois entraram la e nenhum jamais voltou!\"\n\n");
    printf("[Campones]: \"Volte enquanto ainda respira, jovem! Nao ha como\n");
    printf("             vencer um monstro que transforma ate o ar em ouro!\"\n");
    pausar();

    printf("\n[%s]: \"Obrigado pelo aviso, senhor. Mas fiz uma promessa as\n", p->nome);
    printf("       almas daquela floresta... Nao posso recuar agora.\"\n\n");
    printf("[Campones]: \"Entao que os deuses tenham piedade de voce...\"\n\n");
    printf("O campones segue apressado pela estrada. Diante de voce, os\n");
    printf("portoes reluzentes e silenciosos de El Dorado aguardam...\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoPreMacht(const Personagem *p) {
    printf("\n============================================================\n");
    printf("          CONFRONTO: O SALAO RELUZENTE DE EL DORADO         \n");
    printf("============================================================\n\n");
    printf("Voce adentra a praca central da Cidade Dourada. Sob a luz do\n");
    printf("sol, centenas de cidadaos permanecem congelados em ouro macico.\n\n");
    printf("No centro do jardim petrificado, sentado diante de uma mesa\n");
    printf("impecavel, um demonio de manto nobre aprecia calmamente uma\n");
    printf("xicara de cha, com a postura elegante de um aristocrata.\n\n");
    printf("[Macht de El Dorado]: \"Que surpresa agradavel. Raras sao as\n");
    printf("                       visitas que chegam tao longe sem se\n");
    printf("                       tornarem parte da decoracao.\"\n");
    pausar();

    printf("\n[%s]: \"Macht! Desfaca agora mesmo essa maldicao e devolva a\n", p->nome);
    printf("       vida ao povo desta cidade!\"\n\n");
    printf("Macht pousa a xicara no pires com delicadeza e suspira.\n\n");
    printf("[Macht de El Dorado]: \"Receio que isso nao seja possivel.\n");
    printf("                       Diagoldze nao e uma simples magia que\n");
    printf("                       pode ser revertida... E, mesmo que\n");
    printf("                       fosse, eu nao tenho intencao de parar.\"\n");
    pausar();

    printf("\n[%s]: \"Por que fazer isso com inocentes?! Qual e o sentido de\n", p->nome);
    printf("       tanta crueldade?!\"\n\n");
    printf("[Macht de El Dorado]: \"Crueldade? Voces humanos usam palavras\n");
    printf("                       fascinantes. Eu nao sinto odio, culpa ou\n");
    printf("                       malicia... Fiz tudo isso apenas porque\n");
    printf("                       desejo compreender os sentimentos humanos.\"\n\n");
    printf("Macht se levanta lentamente, e o chao ao redor de seus pes\n");
    printf("comeca a reluzir em ouro puro.\n\n");
    printf("[Macht de El Dorado]: \"Mostre-me, %s... Sera que, ao matar\n", p->nome);
    printf("                       voce, finalmente entenderei o que voces\n");
    printf("                       chamam de pesar?\"\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoPosMacht(const Personagem *p) {
    printf("\n============================================================\n");
    printf("                 O DESPERTAR DA CIDADE DOURADA              \n");
    printf("============================================================\n\n");
    printf("Com o golpe final, Macht cai de joelhos sobre o piso dourado.\n");
    printf("Enquanto seu corpo comeca a se desfazer em particulas de mana,\n");
    printf("sua mente mergulha em um silencio profundo...\n\n");
    printf("[Subconsciente de Macht]: (Entao este e o meu fim... Que\n");
    printf("   sensacao estranha e esta que aperta o meu peito agora?\n");
    printf("   Seria isso o medo da morte? Ou seria... felicidade por\n");
    printf("   finalmente alcancar o fim da minha busca?)\n\n");
    printf("[Subconsciente de Macht]: (Nao importa... No fim das contas,\n");
    printf("   parece que eu finalmente consegui sentir alguma coisa...)\n");
    pausar();

    printf("\nO Sabio da Destruicao desaparece no ar. No mesmo instante, o\n");
    printf("brilho metalico que cobria El Dorado se estilhaca como vidro!\n\n");
    printf("O ouro se desfaz das ruas, das arvores e das pessoas. Aos\n");
    printf("poucos, os moradores piscam confusos, olhando para as proprias\n");
    printf("maos, ate que seus olhares se voltam para voce no centro da praca.\n\n");
    printf("[Moradores]: \"O ouro sumiu! Nos estamos vivos! Olhem la...\n");
    printf("              Foi ele! Ele derrotou o demonio! O nosso HEROI!\"\n\n");
    printf("Os gritos de alegria e gratidao ecoam por toda a cidade,\n");
    printf("chamando seu nome. %s nao diz uma unica palavra; apenas\n", p->nome);
    printf("observa o povo livre, esboca um leve sorriso de satisfacao\n");
    printf("e vira as costas, seguindo rumo ao norte gelido de Ende...\n");
    printf("============================================================\n");
    pausar();
}
void exibirDialogoAto3(const Personagem *p) {
    printf("\n============================================================\n");
    printf("          ATO III: AS CINZAS DO NORTE E A PROMESSA          \n");
    printf("============================================================\n\n");
    printf("Deixando El Dorado para tras, voce marcha em direcao ao extremo\n");
    printf("Norte. O cenario muda drasticamente: nao ha mais arvores nem\n");
    printf("brilho, apenas destruicao absoluta.\n\n");
    printf("Pelo caminho, voce ve vilas inteiras carbonizadas e carcacas de\n");
    printf("animais espalhadas pelo chao congelado. O ar e pesado, denso\n");
    printf("pela fuligem negra que cai do ceu como neve.\n\n");
    printf("Ao atravessar os escombros de um vilarejo silencioso, onde\n");
    printf("corpos jazem sem vida sob os destrocos, voce escuta um choro\n");
    printf("fraco vindo do que restou de uma cabana.\n");
    pausar();

    printf("\nEncolhidos no canto, uma mae e seu filho pequeno tremem de frio.\n");
    printf("Eles estao famintos, exaustos, sem forcas sequer para se levantar.\n\n");
    printf("[Mae]: \"Por favor... piedade... Nos nao temos mais nada... Todo\n");
    printf("        o vilarejo se foi... Por favor, ajude o meu filho...\"\n\n");
    printf("Sem hesitar, %s se ajoelha ao lado deles, abre sua bolsa de\n", p->nome);
    printf("viagem e entrega seus proprios suprimentos e agua para os dois.\n");
    pausar();

    printf("\nApos comerem um pouco, a crianca olha para suas armas, ainda\n");
    printf("assustada com a escuridao la fora.\n\n");
    printf("[%s]: \"Nao precisa mais chorar, pequeno. Eu prometo a voce:\n", p->nome);
    printf("       tudo isso vai passar. Eu vou ate aquele castelo e vou\n");
    printf("       acabar com todo esse mal de uma vez por todas.\"\n\n");
    printf("Com o olhar tomado por uma determinacao implacavel, voce se\n");
    printf("levanta e segue em direcao a silhueta sombria do Castelo de Ende.\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoPreReiDemonio(const Personagem *p) {
    printf("\n============================================================\n");
    printf("           CONFRONTO FINAL: O TRONO DO REI DEMONIO          \n");
    printf("============================================================\n\n");
    printf("As pesadas portas da sala do trono se abrem com um estrondo.\n");
    printf("No alto da escadaria de pedra negra, cercado por uma pressao\n");
    printf("magica sufocante, esta o soberano de toda a destruicao.\n\n");
    printf("O Rei Demonio ergue o olhar lentamente ao ver voce entrar:\n\n");
    printf("[Rei Demonio]: \"Ora... Entao voce realmente existe. O tal her—\"\n\n");
    printf("ZAS!\n\n");
    printf("Antes que ele termine a frase, %s avanca em velocidade maxima\n", p->nome);
    printf("e desfere um golpe devastador direto contra o pescoco do Rei!\n");
    pausar();

    printf("\nNo ultimo milesimo de segundo, o Rei Demonio ergue o braco e\n");
    printf("bloqueia o impacto! A onda de choque racha as colunas do salao!\n\n");
    printf("[Rei Demonio]: \"...Que falta de modos. Atacar sem sequer ouvir\n");
    printf("                minhas palavras?\"\n\n");
    printf("[%s]: \"Eu ja vi o suficiente nas vilas que voce queimou! Nao\n", p->nome);
    printf("       estou aqui para conversar, monstro... Eu vim para acabar\n");
    printf("       com a sua existencia!\"\n\n");
    printf("[Rei Demonio]: \"Tolo insolente... Venha e conheca o desespero!\"\n");
    printf("============================================================\n");
    pausar();
}

void exibirDialogoFinal(const Personagem *p) {
    printf("\n============================================================\n");
    printf("              EPILOGO: A LENDA DO GRANDE HEROI              \n");
    printf("============================================================\n\n");
    printf("Com um ultimo golpe carregado de toda a sua forca, a defesa do\n");
    printf("Rei Demonio finalmente cede! O soberano de Ende tomba no chao\n");
    printf("e seu corpo comeca a se desintegrar em cinzas negras.\n\n");
    printf("Ao redor de todo o continente, os exercitos de monstros e os\n");
    printf("suditos restantes do Rei Demonio desaparecem no ar como fumaca.\n");
    printf("A escuridao que cobria o ceu se abre, revelando a luz do sol.\n");
    printf("O mal finalmente acabou.\n");
    pausar();

    printf("\nNo centro do salao em ruinas, %s tenta dar um passo, mas seu\n", p->nome);
    printf("corpo chegou ao limite. A batalha foi brutal e seus ferimentos\n");
    printf("sao graves demais. Sem forcas, voce cai de joelhos...\n\n");
    printf("Sua respiracao fica lenta e sua visao comeca a escurecer...\n");
    printf("...\n");
    printf("......\n");
    pausar();

    printf("\nVoce abre os olhos devagar. O cheiro de cinzas deu lugar a uma\n");
    printf("brisa suave e ao calor de um quarto iluminado.\n\n");
    printf("Seus ferimentos estao enfaixados. Pela janela, voce escuta o\n");
    printf("som de sinos e comemoracoes: os cidadaos de El Dorado e os\n");
    printf("sobreviventes das vilas marcharam ate o Norte para resgata-lo\n");
    printf("dos escombros do castelo!\n\n");
    printf("La fora, aquela crianca da vila acena sorrindo ao ver voce\n");
    printf("despertar. A promessa foi cumprida.\n\n");
    printf("A paz retornou ao reino, e a partir daquele dia, os ventos\n");
    printf("ecoaram por todas as geracoes a lenda do grande heroi: %s!\n", p->nome);
    printf("============================================================\n");
    pausar();
}