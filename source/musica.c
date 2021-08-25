#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica{
  char *nome;
  char *cantor;
};

Musica *criaMusica(char *nome, char *cantor){
  Musica *musica = (Musica*) malloc(sizeof(Musica));
  musica->nome = strdup(nome);
  musica->cantor = strdup(cantor);
  return musica;
}

char *retornaNomeMusica(Musica *musica){
  return musica->nome;
}

char *retornaCantorMusica(Musica *musica){
  return musica->cantor;
}

Musica *criaCopiaMusica(Musica* musica){
  Musica* nova = criaMusica(musica->nome, musica->cantor);
  return nova;
}

void imprimeMusica(Musica *musica){
  printf("Nome: %s\n", musica->nome);
  printf("Cantor: %s\n\n", musica->cantor);
}

void destroiMusica(Musica *musica){
  free(musica->nome);
  free(musica->cantor);
  free(musica);
}