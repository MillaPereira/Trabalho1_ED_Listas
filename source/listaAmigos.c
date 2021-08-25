#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaAmigos.h"

typedef struct celAmigos CelAmigos;

struct celAmigos{
  Usuario *usuario;
  CelAmigos *prox;
};

struct listAmigos{
  CelAmigos *prim;
  CelAmigos *ult;
};

ListAmigos *inicializaListaAmigo(void){
  ListAmigos *listAmigos = (ListAmigos*) malloc(sizeof(ListAmigos));
  listAmigos->prim = NULL;
  listAmigos->ult = NULL;
  return listAmigos;
}

void insereAmigoNaLista(ListAmigos *lista, Usuario *amigo){
  CelAmigos* nova = (CelAmigos*)malloc(sizeof(CelAmigos));
    nova->usuario = amigo;
    nova->prox = NULL;
    
    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      CelAmigos *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}

void insereAmizade(ListUsuario *listUsuario, char* amigo1, char* amigo2){
  Usuario *usuario1, *usuario2;
  ListAmigos *listAmigos1, *listAmigos2;
  
  usuario1 = buscaUsuario(listUsuario, amigo1);
  usuario2 = buscaUsuario(listUsuario, amigo2);
  
  listAmigos1 = retornaListAmigosUsuario(usuario1);
  listAmigos2 = retornaListAmigosUsuario(usuario2);

  insereAmigoNaLista(listAmigos1, usuario2);
  insereAmigoNaLista(listAmigos2, usuario1);

}

Usuario* buscaAmigoPorNome(ListAmigos* lista, char* nome){
  CelAmigos* p = lista->prim;
    while (p != NULL && strcmp(retornaNomeUsuario(p->usuario), nome)){
        p = p->prox;
    }
    if(p != NULL){
      return p->usuario;
    }
    return NULL;
}

void imprimeListAmigos(ListAmigos *listAmigos){
  CelAmigos* p;
  int i = 1;
  printf("LISTA DE AMIGOS:\n");
  for (p = listAmigos->prim; p != NULL; p = p->prox, i++){
    printf("Amigo %d: ", i);
    printf("%s\n", retornaNomeUsuario(p->usuario));
  }
}

void destroiListaAmigos(ListAmigos *listAmigos){
  CelAmigos* p;
  CelAmigos* t;
  
  p = listAmigos->prim;
  while(p != NULL){
    t = p->prox;
    free(p);        
    p = t;
  }
  
  free(listAmigos);
}