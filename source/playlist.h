#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

#include "listaMusica.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Cria a struct playlist
 * inputs: nome da playlist
 * output: ponteiro para a struct Playlist
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
Playlist* criaPlaylist(char* nome);

/* Libera memória alocada para a playlist
 * inputs: ponteiro para a struct playlist
 * output: nenhum
 * pre-condicao: Playlist precisa existir
 * pos-condicao: toda a memória alocada para playlist foi liberada
 */
void destroiPlaylist(Playlist* playlist);

// -------- FUNCOES DE RETORNO -------

/* Retorna o nome da playlist
 * inputs: ponteiro para a struct playlist
 * output: ponteiro para char
 * pre-condicao: playlist precisa existir
 * pos-condicao: playlist nao eh modificada
 */
char* retornaNomePlaylist(Playlist* playlist);

/* Retorna a lista de musica da playlist
 * inputs: ponteiro para a struct playlist
 * output: ponteiro para ListMusica
 * pre-condicao: playlist precisa existir
 * pos-condicao: playlist nao eh modificada
 */
ListMusica* retornaListMusica(Playlist* playlist);

// -------- PARA TESTE -------

/* Imprime playlist
 * inputs: ponteiro para playlist
 * output: nenhum
 * pre-condicao: playlist precisa existir
 * pos-condicao: playlist nao eh alterada
 */
void imprimePlaylist(Playlist* playlist);

#endif 