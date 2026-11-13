# Compilador e flags exigidas pelo documento (padrao C99 e avisos ativos)
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Nome do executavel final
TARGET = jogo

# Todos os arquivos-fonte da estrutura modular
SRCS = src/main.c \
       src/personagens/personagens.c \
       src/monstros/monstros.c \
       src/combate/combate.c \
       src/fases/fases.c \
       src/utils/utils.c

# Regra padrao: compila o projeto ao digitar "make"
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Compila (se necessario) e ja inicia o jogo com "make run"
run: $(TARGET)
	./$(TARGET)

# Remove o executavel compilado com "make clean"
clean:
	rm -f $(TARGET)

.PHONY: all run clean
