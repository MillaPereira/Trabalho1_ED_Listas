#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio

#include "listaPlaylist.h"

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist *prox;
};

struct listPlaylist{
    CelPlaylist *prim;
    CelPlaylist *ult;
};

ListPlaylist* inicializaPlaylist(){
  ListPlaylist* lista = (ListPlaylist*)malloc(sizeof(ListPlaylist));

  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}

void preencheListPlaylist(ListUsuario* listaUsuarios, char* arquivo){
  CelPlaylist* p;

  // ------ Leitura do arquivo ------

  char *diretorio = '\0';

  FILE *fp = fopen(arquivo, "r");
  char conteudo[10000] = "\0";

   if (fp == NULL){
    printf("Erro\n");
  }

  fscanf(fp, "%[^EOF]", conteudo);

  char* test = NULL; 
  char* linha;
  int i = 0, j = 0, k = 0;
  char nome[20];
  char num[10];
  char musica[50];
  int qtd = 0;

 // ------ Coleta de informacao de cada linha ------

  for (linha = strtok_r(conteudo, "\n", &test); linha != NULL; linha = strtok_r(NULL, "\n", &test)){
    
        for(i = 0; linha[i] != ';'; i++){
          nome[i] = linha[i];
        }
        nome[i] = '\0';

        for(i += 1, j = 0; linha[i] != ';'; i++, j++){
          num[j] = linha[i];
        }
        num[j] = '\0';
        
        qtd = atof(num);

        for (j = 0; j < atof(num); j++){
          for(i += 1, k = 0; linha[i] != ';' && linha[i] != '\0'; i++, k++){
            musica[k] = linha[i];
          }
          musica[k] = '\0';

          // ------ Insercao nas listas ------

          p = inserePlaylist(retornaListPlaylist(buscaUsuario(listaUsuarios,nome)), musica);
          
          criaListaMusica(retornaListMusica(retornaPlaylistaDaCelula(p)), musica);
        }
  }
  fclose(fp);
}

Playlist* retornaPlaylistaDaCelula(CelPlaylist* p){
  return p->playlist;
}

CelPlaylist *retornaProximoListPlaylist(CelPlaylist *p){
  return p->prox;
}

CelPlaylist *retornaPrimeiroListPlaylist(ListPlaylist *lista){
  return lista->prim;
}

CelPlaylist* inserePlaylist (ListPlaylist* lista, char* nome){ 
  CelPlaylist* nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));
  nova->playlist = criaPlaylist(nome);
  nova->prox = NULL;

  if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
  else{
    CelPlaylist *p = lista->prim;
    while(p->prox != NULL){
      p = p->prox;
    }
    p->prox = nova;
    lista->ult = nova;
  }

  return nova;
}

void insereNovaPlaylist(ListPlaylist* lista, Playlist *playlist){
    CelPlaylist* nova = (CelPlaylist*)malloc(sizeof(CelPlaylist));
    nova->playlist = playlist;
    nova->prox = lista->prim;

    lista->prim = nova;
    
    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void retiraPlaylistDaLista(ListPlaylist* lista, CelPlaylist* playlist){
  CelPlaylist* p = lista->prim;
  CelPlaylist* anterior = NULL;

    while (p != NULL && p != playlist){
        anterior = p;
        p = p->prox;
    }

    if(p == NULL){
      printf("Item não encontrado\n");
      exit(1);
    }

    if (p == lista->prim && p == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }
    else if (p == lista->prim){
        lista->prim = p->prox;
    }
    else if (p == lista->ult){
        lista->ult = anterior;
        lista->ult->prox = NULL;
    }
    else{
        anterior->prox = p->prox;
    }
    
    destroiPlaylist(p->playlist);

    free(p);
}

Playlist* buscaPlaylist(ListPlaylist* lista, char* nome){
  CelPlaylist* p = lista->prim;
    while (p != NULL && strcmp(retornaNomePlaylist(p->playlist), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->playlist;
    }
    return NULL;
}

CelPlaylist* buscaPlaylistERetornaCelula(ListPlaylist* lista, char* nome){
  CelPlaylist* p = lista->prim;
    while (p != NULL && strcmp(retornaNomePlaylist(p->playlist), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p;
    }
    return NULL;
}

void destroiListPlaylist(ListPlaylist *lista){
  CelPlaylist* p;
  CelPlaylist* t;
  
  p = lista->prim;
  while(p != NULL){
        t = p->prox;
        destroiPlaylist(p->playlist);
        free(p);        
        p = t;
    }
  
  free(lista);
}

void imprimeListPlaylist(ListPlaylist* lista){
  CelPlaylist* p;
  int i = 1;
  printf("LISTA DE PLAYLISTS:\n");
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf("Playlist %d\n", i);
    imprimePlaylist(p->playlist);
  }
}
