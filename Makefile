CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
TARGET = jogo
SRCS = src/main.c src/personagens/personagens.c src/monstros/monstros.c src/combate/combate.c src/fases/fases.c src/utils/utils.c src/historia/historia.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
