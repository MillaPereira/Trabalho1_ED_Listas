/*
Alunas: Lara Tagarro e Milla Pereira
Disciplina: Estrutura de Dados

OBS: Estamos contando que os arquivos de entrada estarao dentro de uma pasta "Saida"
*/

#include <stdio.h>

#include "listaUsuario.h"
#include "funcoesEspeciais.h"


int main(void) {
  printf("Criando lista de usuarios...\n");

  ListUsuario *lista = inicializaListUsuario("../Entrada/amizade.txt");

  printf("Preenchendo listas de playlists...\n");

  preencheListPlaylist(lista, "../Entrada/playlists.txt");

  printf("Refatorando as playlists...\n");

  criaListPlaylistPorCantor(lista);

  printf("Criando arquivos com playlists refatoradas...\n");

  criaArquivoPlayEDRefatorada(lista);

  printf("Criando arquivos com similaridades...\n");

  criaArquivoPlayEDPorGosto(lista);

  printf("Fazendo o merge de playlists com o mesmo nome...\n");

  mergePlaylistAmigos(lista);

  //printf("Criando arquivos com playlists refatoradas...\n");

  //criaArquivoPlayEDRefatorada(lista);

  printf("Liberando memoria alocada...\n");

  destroiListUsuario(lista);

  return 0;
}