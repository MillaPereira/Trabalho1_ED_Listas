#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct usuario Usuario;

#include "listaAmigos.h"
#include "listaPlaylist.h"
#include "listaMusica.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/*Cria estrutura usuario inicializando as sua listas
 * inputs: nome do usuario
 * output: ponteiro para a struct Usuario
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado 
 */
Usuario *criaUsuario(char *nome);

/*Libera memória alocada para o usuario
 * inputs: ponteiro para a struct Usuario
 * output: nenhum
 * pre-condicao: Usuario precisa existir
 * pos-condicao: toda a memória alocada para Usuario foi liberada
 */
void destroiUsuario(Usuario *usuario);

// -------- FUNCOES DE RETORNO -------

/*Retorna o nome do usuario
 * inputs: ponteiro para a struct Usuario
 * output: nenhum
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh modificado
 */
char *retornaNomeUsuario(Usuario *usuario);

/*Retona a lista de playlist do usuario
 * inputs: ponteiro para a struct Usuario
 * output: ponteiro para a struct ListPlaylist
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh modificado
 */
ListPlaylist *retornaListPlaylist(Usuario *usuario);

/*Retorna Lista de amigos do Usuario
 * inputs: ponteiro para struct Usuario
 * output: ponteiro para struct ListAmigos
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh alterado
 */
ListAmigos *retornaListAmigosUsuario(Usuario *usuario);

/*Retorna Lista de musicas do Usuario
 * inputs: ponteiro para struct Usuario
 * output: ponteiro para struct ListMusic
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh alterado
 */
ListMusica *retornaPlaylistUsuario(Usuario *usuario);

// ---- PARA TESTE -----

/*Imprime Usuario
 * inputs: ponteiro para Usuario
 * output: nenhum
 * pre-condicao: Usuario precisa existir
 * pos-condicao: Usuario nao eh alterado
 */
void imprimeUsuario(Usuario* usuario);

#endif