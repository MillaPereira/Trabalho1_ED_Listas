# MAKEFILE
#gcc -g -o exect *.c

# Nome do compilador
CC = gcc

# Opcoes de compilacao
CFLAGS = -Wall -gcc

# Ligacao com as bibliotecas
LDFLAGS = -lm

# Wildcards eh utilizado para listar os arquivos fonte no diretorio atual
FONTES = $(wildcard *.c)

# Gera a lista dos arquivos objeto usando a lista de arquivo fonte
OBJETOS = $(FONTES: .c=.o)

# Nome do arquivo executavel
EXECUTAVEL = prog

# all: prog
all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(CC) -g -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf prog

rmproper: clean
	rm -rf $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

valgrind: $(EXECUTAVEL)
	valgrind ./$(EXECUTAVEL)
