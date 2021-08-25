#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaMusica.h"

typedef struct celMusica CelMusica;

struct celMusica{
  Musica *musica;
  CelMusica *prox;
};

struct listMusica{
  CelMusica *prim;
  CelMusica *ult;
};

ListMusica *inicializaListMusica(void){
  ListMusica *listMusica = (ListMusica*) malloc(sizeof(ListMusica));

  listMusica->prim = NULL;
  listMusica->ult = NULL;

  return listMusica;
}

void criaListaMusica(ListMusica *listMusicas, char *playlist){ 
  char aux1[100], aux2[100];
  int i, j;
  char linha[10000] = "\0";

  // ------ Leitura do arquivo ------
  
  char *diretorio = (char*)malloc(100*sizeof(char));
  strcpy(diretorio, "../Entrada/");
  strcat(diretorio, playlist);
  
  FILE *fp = fopen(diretorio, "r");

  free(diretorio);

  if(fp == NULL){
    printf("Nao foi possivel abrir o arquivo %s\n", playlist);
    exit (1);
  }

  char c = fgetc(fp);
  for(int i = 0; c != EOF; i++){
    linha[i] = c;
    c = fgetc(fp);
  }

  char *p = strtok(linha, "\n");

  // ------ Coleta de informacao de cada linha ------

  while(p != NULL){
    for(i = 0; p[i] != '-'; i++){
      aux1[i] = p[i];
    }
    aux1[i-1] = '\0';

    for(i++, j = 0; p[i] != '\0' && p[i] != '\n'; i++, j++){
      aux2[j] = p[i+1];
    }
    aux2[j-1] = '\0';

    // ------ Criação de uma nova celula e insercao na lista ------
    
    CelMusica *novaCelMusica = (CelMusica*) malloc(sizeof(CelMusica));

    Musica *musica = criaMusica(aux2, aux1);

    novaCelMusica->musica = musica;
    novaCelMusica->prox = listMusicas->prim;
    listMusicas->prim = novaCelMusica;
      
    if(listMusicas->ult == NULL){
      listMusicas->ult = novaCelMusica;
    }

    p = strtok(NULL, "\n");
  }
  fclose(fp);
}

CelMusica *retornaPrimeiroListMusica(ListMusica* p){
  return p->prim;
}

CelMusica *retornaProximaCelMusica(CelMusica *p){
  return p->prox;
}

Musica *retornaMusicaDaCelula(CelMusica *p){
  return p->musica;
}

Musica* buscaMusicaPorNome(ListMusica* lista, char* nome){
  CelMusica* p = lista->prim;

    while (p != NULL && strcmp(retornaNomeMusica(p->musica), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->musica;
    }
    return NULL;
}

void insereMusicaNaLista(ListMusica* lista, Musica* musica){
    CelMusica* nova = (CelMusica*)malloc(sizeof(CelMusica));
    nova->musica = musica;
    nova->prox = NULL;
    
    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      CelMusica *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}

void destroiListMusica(ListMusica *listMusica){
    CelMusica *p = listMusica->prim;
    CelMusica *t;

    while(p != NULL){
        t = p->prox;
        destroiMusica(p->musica);
        free(p);
        p = t;
    }
    free(listMusica);
}

void imprimeListMusica(ListMusica* lista){
  CelMusica* p;
  int i = 1;
  printf("LISTA DE MUSICA:\n");
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Musica %d:\n", i);
    imprimeMusica(p->musica);
  }
}