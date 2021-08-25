#ifndef LISTAMUSICA_H_
#define LISTAMUSICA_H_

typedef struct listMusica ListMusica;
typedef struct celMusica CelMusica;

#include "usuario.h"
#include "musica.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Inicializa a lista de musicas de uma playlist
 * inputs: nenhum
 * output: ponteiro para a struct ListMusica
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
ListMusica *inicializaListMusica(void); 

/* Libera memória alocada para a lista de musicas
 * inputs: ponteiro para a struct ListMusica
 * output: nenhum
 * pre-condicao: lista de musica precisa existir
 * pos-condicao: toda a memória alocada para ListMusica foi liberada
 */
void destroiListMusica(ListMusica *listMusica);

/* Preenche a lista de musica
 * inputs: lista de musica e string que eh o nome do arquivo
 * output: nenhum
 * pre-condicao: lista de musicas precisa existir e playlist precisa existir 
 * pos-condicao: lista de musicas continua existindo, agora com musicas inseridas
 */
void criaListaMusica(ListMusica *listMusicas, char *arquivo);

/* Insere nova musica no final da lista de musica
 * inputs: lista de musica e musica
 * output: nenhum
 * pre-condicao: lista de musicas precisa existir e musica precisa existir 
 * pos-condicao: lista de musicas continua existindo, agora com nova musica inserida
 */
void insereMusicaNaLista(ListMusica *lista, Musica *musica); 

/* Retira a musica da lista de musica
 * inputs: lista de musica e nome da musica a ser retirada
 * output: nenhum
 * pre-condicao: lista de musicas precisa existir e musica precisa existir 
 * pos-condicao: lista de musicas continua existindo, agora com uma musica retirada
 */
void retiraMusica(ListMusica* lista, char *nome);

// -------- FUNCOES DE RETORNO -------

/* Retorna primeira celula da lista
 * inputs: ponteiro para ListMusica
 * output: ponteiro para CelMusica
 * pre-condicao: lista de musicas precisa existir
 * pos-condicao: lista de musicas nao eh modificada
 */
CelMusica *retornaPrimeiroListMusica(ListMusica* p);

/* Retorna proxima celula
 * inputs: ponteiro para CelMusica
 * output: ponteiro para CelMusica 
 * pre-condicao: lista de musica precisa existir
 * pos-condicao: lista de musica nao eh modificada
 */
CelMusica *retornaProximaCelMusica(CelMusica *p);

/* Retorna a musica da celula
 * inputs: ponteiro para celula de musica
 * output: ponteiro para musica
 * pre-condicao: celula precisa existir
 * pos-condicao: celula nao eh modificada
 */
Musica *retornaMusicaDaCelula(CelMusica *p);

/* Retorna musica com o nome especificado
 * inputs: ponteiro para ListMusica e ponteiro para char
 * output: ponteiro para musica
 * pre-condicao: lista de musica precisa existir
 * pos-condicao: lista de musica nao eh modificada
 */
Musica* buscaMusicaPorNome(ListMusica* lista, char* nome);

// --------- PARA TESTE ---------

/* Imprime lista de musicas
 * inputs: ponteiro para ListMusica
 * output: nenhum
 * pre-condicao: lista de musicas precisa existir
 * pos-condicao: lista de musicas nao eh alterada
 */
void imprimeListMusica(ListMusica* lista);

#endif