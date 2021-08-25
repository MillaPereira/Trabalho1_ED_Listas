#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUsuario.h"

struct celUsuario{
  Usuario *usuario;
  CelUsuario *prox;
};

struct listUsuario{
  CelUsuario *prim;
  CelUsuario *ult;
};

ListUsuario* inicializaListUsuario(char* arquivo){
  ListUsuario* lista = (ListUsuario*)malloc(sizeof(ListUsuario));
  lista->prim = NULL;
  lista->ult = NULL;

  CelUsuario* p = lista->prim;

  // -------- Abrindo o arquivo ---------

  FILE *fp = fopen(arquivo, "r");
  char conteudo[70];

   if (fp == NULL){
    printf("Nao foi possivel abrir o arquivo %s\n", arquivo);
  }

  // -------- Pegando as informacoes da primeira linha ---------

  fscanf(fp, "%[^\n]\n", conteudo);

  char* nome = strtok(conteudo, ";");

  while( nome != NULL ) {
        insereUsuario(lista, criaUsuario(nome));

        nome = strtok(NULL, ";");
  }

  // -------- Pegando as informacoes do restante das linhas ---------

  char aux1[20], aux2[20];

  fscanf(fp, "%[^EOF]", conteudo);
  int i = 0;
  int j = 0;
  nome = strtok(conteudo, "\n");

  while (nome != NULL){
          for (i = 0; nome[i] != ';'; i++){
              aux1[i] = nome[i];
          }
          aux1[i] = '\0';
          for (i += 1, j = 0; nome[i] != '\0'; i++, j++){
            aux2[j] = nome[i];
          }
          aux2[j] = '\0';
          
      insereAmizade(lista, aux1, aux2);
      nome = strtok(NULL, "\n");
  }

  fclose(fp);

  lista->ult->prox = NULL;

  return lista;
}

void insereUsuario(ListUsuario* lista, Usuario *usuario){
    CelUsuario* nova = (CelUsuario*)malloc(sizeof(CelUsuario));
    nova->usuario = usuario;
    nova->prox = NULL;
    
    if(lista->prim == NULL){
      lista->prim = nova;
      lista->ult = nova;
    }
    else{
      CelUsuario *p = lista->prim;

      while(p->prox != NULL){
        p = p->prox;
      }
      p->prox = nova;
      lista->ult = nova;
    }
}

void retiraUsuario(ListUsuario* lista, char *nome){
  CelUsuario* p = lista->prim;
  CelUsuario* anterior = NULL;

    while (p != NULL && strcmp(retornaNomeUsuario(p->usuario), nome)){
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

    destroiUsuario(p->usuario);
    free(p);

}

Usuario *buscaUsuario(ListUsuario *lista, char *nome){
    CelUsuario* p = lista->prim;
    while (p != NULL && strcmp(retornaNomeUsuario(p->usuario), nome)){
        p = p->prox;
    }
    return p->usuario; 
}

CelUsuario *retornaPrimeiro(ListUsuario* lista){
  return lista->prim;
}

CelUsuario *retornaUltimo(ListUsuario* lista){
  return lista->ult;
}

CelUsuario *retornaProximo(CelUsuario* p){
  return p->prox;
}

Usuario *retornaUsuarioCelula(CelUsuario* p){
  return p->usuario;
}

void destroiListUsuario(ListUsuario* lista){
  CelUsuario* p;
  CelUsuario* t;
  
  p = lista->prim;
  while(p != NULL){
        t = p->prox;
        destroiUsuario(p->usuario);
        free(p);        
        p = t;
    }
  
  free(lista);
}

void imprimeListUsuario(ListUsuario* lista){
  CelUsuario* p;
  int i = 1;
  for (p = lista->prim; p != NULL; p = p->prox, i++){
    printf ("Usuario %d:\n", i);
    imprimeUsuario(p->usuario);
    printf("\n");
  }
}