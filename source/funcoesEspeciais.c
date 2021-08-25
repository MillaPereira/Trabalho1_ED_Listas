#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio

#include "funcoesEspeciais.h"

void criaListPlaylistPorCantor(ListUsuario *listaUsuarios){
  // --------- Variaveis de retorno --------
  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  Usuario *usuario;

  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist;
  CelPlaylist *t;

  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;
  char* cantor;

  Playlist* novaPlaylist;
  ListMusica *novaListMusica;

  // --------- Percorrendo lista de usuarios --------

  while(p != NULL){
        usuario = retornaUsuarioCelula(p);
        listPlaylist = retornaListPlaylist(usuario);
        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);
        
        // --------- Percorrendo lista de playlistsa --------

        while(celPlaylist != NULL){
          listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
          celMusica = retornaPrimeiroListMusica(listMusica);

          // --------- Percorrendo lista de musicas --------

          while(celMusica != NULL){
            musica = retornaMusicaDaCelula(celMusica);
            
            cantor = strdup(retornaCantorMusica(musica));
            
            novaPlaylist = buscaPlaylist(listPlaylist, cantor);
            
            // --------- Checa se já existe uma playlist com o nome cantor --------

            if(novaPlaylist == NULL){
               // --------- Cria nova playlist por cantore insere a musica na playlist  --------
              novaPlaylist = criaPlaylist(cantor);
              novaListMusica = retornaListMusica(novaPlaylist);

              insereMusicaNaLista(novaListMusica, criaCopiaMusica(musica));
              insereNovaPlaylist(listPlaylist, novaPlaylist);
            }         
            else{
              // --------- Insere a musica na playlist --------
              novaListMusica = retornaListMusica(novaPlaylist);
              insereMusicaNaLista(novaListMusica, criaCopiaMusica(musica));
            }

            celMusica = retornaProximaCelMusica(celMusica);
            free(cantor);
          }
          t = retornaProximoListPlaylist(celPlaylist);

          retiraPlaylistDaLista(listPlaylist, celPlaylist);

          celPlaylist = t;
        }
        p = retornaProximo(p);
    }  
}

void criaArquivoPlayEDRefatorada(ListUsuario *listaUsuarios){
  // --------- Ponteiros para os arquivos que seroa criados --------

  FILE *fp, *fd;
  fp = fopen("../Saida/played-refatorada.txt", "w");

  char *diretorio = (char*)malloc(100*sizeof(char)), *nomePasta = (char*)malloc(100*sizeof(char));

  // --------- Variaveis de retorno --------

  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  Usuario *usuario;

  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist;

  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;

  int qtd = 0; //conta quantas playlists existem na lista de playlists

  // --------- Percorrendo lista de usuarios --------

  while(p != NULL){
        usuario = retornaUsuarioCelula(p);
        listPlaylist = retornaListPlaylist(usuario);
        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);;
        
        // --------- Criando a pasta do usuario --------

        strcpy(nomePasta, "../Saida/");
        strcat(nomePasta, retornaNomeUsuario(usuario));
        mkdir(nomePasta, 0777);

        fprintf(fp, "%s;",retornaNomeUsuario(usuario));

        // --------- Checando a quantidade de playlists --------

        if (qtd == 0){
          while(celPlaylist != NULL){
            celPlaylist = retornaProximoListPlaylist(celPlaylist);
            qtd++;
          }
        }

        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);

        fprintf(fp, "%d;", qtd);

        // --------- Percorrendo lista de playlists --------

        while(celPlaylist != NULL){
          listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
          celMusica = retornaPrimeiroListMusica(listMusica);

          
            if (retornaProximoListPlaylist(celPlaylist) != NULL){
              fprintf(fp, "%s.txt;", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
            }
            else{
              if (retornaProximo(p) == NULL){
                fprintf(fp, "%s.txt", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
              }
              else{
                fprintf(fp, "%s.txt\n", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
              }
            }
          
          // --------- Criando nome e endereco para a pasta --------
          
          strcpy(diretorio, "../Saida/");
          strcat(diretorio, retornaNomeUsuario(usuario));
          strcat(diretorio, "/");
          strcat(diretorio, retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
          strcat(diretorio, ".txt");

          fd = fopen(diretorio, "w");

            // --------- Percorrendo lista de musicas e imprindo as musicas no arquivo --------

            while(celMusica != NULL){
              musica = retornaMusicaDaCelula(celMusica);
              
              if (retornaProximaCelMusica(celMusica) != NULL){
                fprintf(fd, "%s - %s\n", retornaCantorMusica(musica), retornaNomeMusica(musica));
              }
              else{
                fprintf(fd, "%s - %s", retornaCantorMusica(musica), retornaNomeMusica(musica));
              }

              celMusica = retornaProximaCelMusica(celMusica);
            }

          fclose(fd);
          
          celPlaylist = retornaProximoListPlaylist(celPlaylist);
        }
        p = retornaProximo(p);
        qtd = 0;
    }

  fclose(fp);
  free(diretorio);
  free(nomePasta);
}

void criaArquivoPlayEDPorGosto(ListUsuario *listaUsuarios){
  // --------- Variaveis de retorno --------

                // Usuario 1 

  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  CelUsuario *t = retornaProximo(p);
  Usuario *usuario1;

  ListPlaylist *listPlaylist1;
  CelPlaylist *celPlaylist1;

  ListMusica *listMusica1; 
  CelMusica *celMusica1; 
  Musica *musica1;

                // Usuario 2 
  
  Usuario *usuario2;

  ListPlaylist *listPlaylist2;
  CelPlaylist *celPlaylist2;
  Playlist *playlist2;

  ListMusica *listMusica2; 
  CelMusica *celMusica2; 
  Musica *musica2;

  // --------- Variaveis de auxiliares --------

  CelPlaylist *auxiliar;
  char* nomePlaylist1;
  char* nomePlaylist2;
  int qtd = 0; //Conta as similaridades

  // --------- Abrindo o arquivo --------

  FILE *fp;

  fp = fopen("../Saida/similaridades.txt", "w");

  // --------- Percorrendo lista de usuarios --------

  while(p != NULL){
    usuario1 = retornaUsuarioCelula(p);
    listPlaylist1 = retornaListPlaylist(usuario1);
    celPlaylist1 = retornaPrimeiroListPlaylist(listPlaylist1);

    auxiliar = celPlaylist1;

    // --------- Percorrendo usuarios posteriores ao usuario 1 --------

    while(t != NULL){
      usuario2 = retornaUsuarioCelula(t);
      listPlaylist2 = retornaListPlaylist(usuario2);
      celPlaylist2 = retornaPrimeiroListPlaylist(listPlaylist2);

      // --------- Checa se os usuarios 1 e 2 sao amigos --------
      
      if(buscaAmigoPorNome(retornaListAmigosUsuario(usuario1),retornaNomeUsuario(usuario2)) != NULL){

        // --------- Percorrendo lista de playlists do usuario 1 --------

        while(celPlaylist1 != NULL){
          nomePlaylist1 = retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist1));

          // --------- Checa se o usuario 2 tem alguma playlist com o mesmo nome --------

          if(buscaPlaylist(listPlaylist2, nomePlaylist1) != NULL){

            listMusica1 = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist1));
            celMusica1 = retornaPrimeiroListMusica(listMusica1);

            listMusica2 = retornaListMusica(buscaPlaylist(listPlaylist2, nomePlaylist1));
            celMusica2 = retornaPrimeiroListMusica(listMusica2);

            // --------- Percorrendo lista de musicas do usuario 1 --------

            while(celMusica1 != NULL){
              musica1 = retornaMusicaDaCelula(celMusica1);

                // --------- Checa se o usuario 2 tem alguma musica com o mesmo nome --------

                if(buscaMusicaPorNome(listMusica2, retornaNomeMusica(musica1)) != NULL){
                  qtd++;
                }

              celMusica1 = retornaProximaCelMusica(celMusica1);
            }
          }  

          celPlaylist1 = retornaProximoListPlaylist(celPlaylist1);
        } 
        // --------- Imprime as informacoes no arquivo --------

        fprintf(fp, "%s;%s;%d\n", retornaNomeUsuario(usuario1), retornaNomeUsuario(usuario2), qtd);
      }

    celPlaylist1 = retornaProximoListPlaylist(auxiliar);
    auxiliar = celPlaylist1;
    t = retornaProximo(t);
    qtd = 0;
    }
    
    p = retornaProximo(p);
    if(p != retornaUltimo(listaUsuarios)){
      t = retornaProximo(p);
    }
    else{
      p = NULL;
    }
  }

  fclose(fp);
}

void mergePlaylistAmigos(ListUsuario *listaUsuarios){
  // --------- Variaveis de retorno --------

  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  CelUsuario *t = retornaProximo(p);

                // Usuario 1  

  Usuario *usuario1;
  ListPlaylist *listPlaylist1;
  CelPlaylist *celPlaylist1;

  ListMusica *listMusica1; 
  CelMusica *celMusica1; 
  Musica *musica1;

                  // Usuario 2
  
  Usuario *usuario2;

  ListPlaylist *listPlaylist2;
  CelPlaylist *celPlaylist2;

  ListMusica *listMusica2; 
  CelMusica *celMusica2;

  // --------- Variaveis de auxiliares --------

  CelPlaylist *auxiliar1, *auxiliar2;
  char* nomePlaylist;

  Playlist* novaPlaylist1, *novaPlaylist2;
  ListMusica* listMusicaNova1, *listMusicaNova2;

  int quant = 0; //sera usado para percorrer a lista de usuarios 

  // --------- Percorrendo lista de usuarios --------

  while(p != NULL){
    usuario1 = retornaUsuarioCelula(p);
    listPlaylist1 = retornaListPlaylist(usuario1);
    celPlaylist1 = retornaPrimeiroListPlaylist(listPlaylist1);

    // --------- Percorrendo usuarios posteriores ao usuario 1 --------

    while(t != NULL){
      usuario2 = retornaUsuarioCelula(t);
      listPlaylist2 = retornaListPlaylist(usuario2);

      // --------- Checa se os usuarios 1 e 2 sao amigos --------
      
      if(buscaAmigoPorNome(retornaListAmigosUsuario(usuario1),retornaNomeUsuario(usuario2)) != NULL){

        // --------- Percorrendo lista de playlists do usuario 1 --------

        while(celPlaylist1 != NULL){
          
          nomePlaylist = strdup(retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist1)));

          // --------- Checa se o usuario 2 tem alguma playlist com o mesmo nome --------

          if(buscaPlaylist(listPlaylist2, nomePlaylist) != NULL){
            celPlaylist2 = buscaPlaylistERetornaCelula(listPlaylist2, nomePlaylist);

            listMusica1 = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist1));
            celMusica1 = retornaPrimeiroListMusica(listMusica1);

            listMusica2 = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist2));
            celMusica2 = retornaPrimeiroListMusica(listMusica2);

            // --------- Cria novas playlists --------

            novaPlaylist1 = criaPlaylist(nomePlaylist);
            novaPlaylist2 = criaPlaylist(nomePlaylist);

            listMusicaNova1 = retornaListMusica(novaPlaylist1);
            listMusicaNova2 = retornaListMusica(novaPlaylist2);

            // --------- Percorre lista de musicas do usuario 1 e insere as musicas nas novas playlists --------

            while(celMusica1 != NULL){
              musica1 = retornaMusicaDaCelula(celMusica1);
              insereMusicaNaLista(listMusicaNova1, criaCopiaMusica(musica1));
              insereMusicaNaLista(listMusicaNova2, criaCopiaMusica(musica1));

              celMusica1 = retornaProximaCelMusica(celMusica1);
            }

            // --------- Percorre lista de musicas do usuario 2 e insere as 
            // musicas que sao diferentes das já existentes nas duas listas --------

            while(celMusica2 != NULL){
              musica1 = retornaMusicaDaCelula(celMusica2);

                if(buscaMusicaPorNome(listMusicaNova1, retornaNomeMusica(musica1)) == NULL){
                  insereMusicaNaLista(listMusicaNova1, criaCopiaMusica(musica1));
                  insereMusicaNaLista(listMusicaNova2, criaCopiaMusica(musica1));
                }

              celMusica2 = retornaProximaCelMusica(celMusica2);
            }

            auxiliar2 = retornaProximoListPlaylist(celPlaylist1);

            // --------- Retira as playlists antigas das listas dos usuarios --------
            
            retiraPlaylistDaLista(listPlaylist1, celPlaylist1);
            retiraPlaylistDaLista(listPlaylist2, celPlaylist2); 

            // --------- Insere as novas playlists --------

            insereNovaPlaylist(listPlaylist1, novaPlaylist1);
            insereNovaPlaylist(listPlaylist2, novaPlaylist2);

            celPlaylist1 = auxiliar2;
          }  
          else{
            celPlaylist1 = retornaProximoListPlaylist(celPlaylist1);
          }

          free(nomePlaylist);
        } 
      }

    celPlaylist1 = retornaPrimeiroListPlaylist(listPlaylist1);

    // --------- Como algumas playlists estao sendo excluidas nos processos anteriores, 
    // utilizamos um contador para percorrer as listas de playlists --------

    for (int i = 0; i < quant && retornaProximoListPlaylist(celPlaylist1) != NULL; i++){
      celPlaylist1 = retornaProximoListPlaylist(celPlaylist1);
    }
    
    t = retornaProximo(t);
    }
    
    p = retornaProximo(p);
    if(p != retornaUltimo(listaUsuarios)){
      t = retornaProximo(p);
    }
    else{
      p = NULL;
    }
    quant = 0;
  }
}