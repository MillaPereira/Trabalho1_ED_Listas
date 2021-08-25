#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "playlist.h"

struct playlist{
  char *nome;
  ListMusica *musicas;
};

Playlist* criaPlaylist(char* nome){
  Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
  playlist->nome = strdup(nome);
  playlist->musicas = inicializaListMusica();

  return playlist;
}

char* retornaNomePlaylist(Playlist* playlist){
  return playlist->nome;
}

ListMusica* retornaListMusica(Playlist* playlist){
  return playlist->musicas;
}

void destroiPlaylist(Playlist* playlist){
  destroiListMusica(playlist->musicas);
  free(playlist->nome);
  free(playlist);
}

void imprimePlaylist(Playlist* playlist){
  printf("Nome: %s\n", playlist->nome);
  imprimeListMusica(playlist->musicas);
}