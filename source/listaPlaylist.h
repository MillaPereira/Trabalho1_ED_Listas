#ifndef LISTAPLAYLIST_H_
#define LISTAPLAYLIST_H_

typedef struct celPlaylist CelPlaylist;
typedef struct listPlaylist ListPlaylist;

#include "listaUsuario.h"
#include "listaMusica.h"
#include "playlist.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Inicializa a lista de usuario 
 * inputs: string que eh o nome do arquivo
 * output: ponteiro para a struct ListUsuario
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
ListPlaylist* inicializaPlaylist(void);

/* Libera memória alocada para a lista de playlist
 * inputs: ponteiro para a struct ListPlaylist
 * output: nenhum
 * pre-condicao: ListPlaylist precisa existir
 * pos-condicao: toda a memória alocada para ListPlaylist foi liberada
 */
void destroiListPlaylist(ListPlaylist *lista);

/* Preenche a lista de playlist
 * inputs: lista de usuarios e string que eh o nome do arquivo
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e a lista de playlist ja deve ter sido inicializada 
 * pos-condicao: lista de playlist continua existindo, agora com usuarios inseridos
 */
void preencheListPlaylist(ListUsuario* listaUsuarios, char* arquivo);

// -------- FUNCOES DE INSERCAO E RETIRADA DE ELEMENTOS -------

/* Cria e insere a playlist NO FINAL da lista 
 * inputs: ponteiro para a struct ListPlaylist e o ponteiro para char
 * output: ponteiro para a playlist criada
 * pre-condicao: lista de playlist precisa existir 
 * pos-condicao: lista de playlist continua existindo, agora com uma nova playlist
 */
CelPlaylist *inserePlaylist(ListPlaylist* lista, char* nome);

/* Insere uma playlist que ja existe NO INICIO da lista 
 * inputs: ponteiro para a struct ListPlaylist e o ponteiro para Playlist
 * output: nenhum
 * pre-condicao: lista de playlist e playlist precisam existir
 * pos-condicao: lista de playlist continua existindo, agora com uma nova playlist 
 */
void insereNovaPlaylist(ListPlaylist* lista, Playlist *playlist);

/* Retira playlist da lista de playlist 
 * inputs: ponteiro para a struct ListPlaylist e o ponteiro para CelPlaylist
 * output: nenhum
 * pre-condicao: lista de playlist precisa existir 
 * pos-condicao: lista de playlist continua existindo, agora com determinada playlist retirada 
 */
void retiraPlaylistDaLista(ListPlaylist *listPlaylist, CelPlaylist* playlist);

// -------- FUNCOES DE RETORNO -------

/* Retorna a playlist da celula
 * inputs: ponteiro para celula de playlist
 * output: ponteiro para playlist 
 * pre-condicao: celula precisa existir
 * pos-condicao: celula nao eh modificada
 */
Playlist* retornaPlaylistaDaCelula(CelPlaylist* p);

/* Retorna proxima celula
 * inputs: ponteiro para CelPlaylist
 * output: ponteiro para CelPlaylist 
 * pre-condicao: lista de plylists precisa existir
 * pos-condicao: lista de playlists nao eh modificada
 */
CelPlaylist *retornaProximoListPlaylist(CelPlaylist *p);

/* Retorna primeira celula
 * inputs: ponteiro para ListPlaylist
 * output: ponteiro para CelPlaylist 
 * pre-condicao: lista de plylists precisa existir
 * pos-condicao: lista de playlists nao eh modificada
 */
CelPlaylist *retornaPrimeiroListPlaylist(ListPlaylist *lista);

/* Retorna playlist com o nome especificado
 * inputs: ponteiro para ListPLaylist e ponteiro para char
 * output: ponteiro para playlist
 * pre-condicao: lista de playlist precisa existir
 * pos-condicao: lista de playlist nao eh modificada
 */
Playlist* buscaPlaylist(ListPlaylist* lista, char* nome);

/* Retorna a celula que contem a playlist com o nome especificado
 * inputs: ponteiro para ListPLaylist e ponteiro para char
 * output: ponteiro para CelPlaylist
 * pre-condicao: lista de playlist precisa existir
 * pos-condicao: lista de playlist nao eh modificada
 */
CelPlaylist* buscaPlaylistERetornaCelula(ListPlaylist* lista, char* nome);

// --------- PARA TESTE ---------

/* Imprime lista de playlists
 * inputs: ponteiro para ListPlaylist
 * output: nenhum
 * pre-condicao: lista de playlists precisa existir
 * pos-condicao: lista de playlists nao eh alterada
 */
void imprimeListPlaylist(ListPlaylist* lista);

#endif