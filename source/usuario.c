#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuario.h"

struct usuario{ 
  char *nome;
  ListPlaylist *playlist;
  ListAmigos *amigos;
};

Usuario* criaUsuario(char *nome){
  Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));
  usuario->nome = strdup(nome);
  usuario->playlist = inicializaPlaylist();
  usuario->amigos = inicializaListaAmigo();

  return usuario;
}

char *retornaNomeUsuario(Usuario *usuario){
  return usuario->nome;
}

ListAmigos *retornaListAmigosUsuario(Usuario *usuario){
  return usuario->amigos;
}

ListPlaylist *retornaListPlaylist(Usuario *usuario){
  return usuario->playlist;
}

void destroiUsuario(Usuario *usuario){
  free(usuario->nome);
  destroiListPlaylist(usuario->playlist);
  destroiListaAmigos(usuario->amigos);
    
  free(usuario);
}

void imprimeUsuario(Usuario* usuario){
  printf("Nome: %s\n", usuario->nome);
  imprimeListPlaylist(usuario->playlist);
  imprimeListAmigos(usuario->amigos);
}




   

