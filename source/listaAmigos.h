#ifndef AMIGOS_H_
#define AMIGOS_H_

typedef struct listAmigos ListAmigos;
typedef struct celAmigos CelAmigos;

#include "listaUsuario.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Inicializa a lista de amigos de um usuario
 * inputs: nenhum
 * output: ponteiro para a struct ListAmigos
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
ListAmigos *inicializaListaAmigo(void);

/* Libera memória alocada para a lista de amigos
 * inputs: ponteiro para a struct ListAmigos
 * output: nenhum
 * pre-condicao: lista de amigos precisa existir
 * pos-condicao: toda a memória alocada para ListAmigos foi liberada
 */
void destroiListaAmigos(ListAmigos *listAmigos);

// -------- FUNCOES DE INSERCAO E RETIRADA DE ELEMENTOS -------

/* Insere o usuario no final da lista de amigos 
 * inputs: ponteiro para ListAmigos e ponteiro para o usuario
 * output: nenhum
 * pre-condicao: lista de amigos precisa existir e usuario precisa existir
 * pos-condicao: lista de amigos continua existindo, agora com um novo usuario
 */
void insereAmigoNaLista(ListAmigos *lista, Usuario *amigo); 

/* Insere os dois usuarios como amigo um do outro em suas respectivas listas de amigos 
 * inputs: ponteiro para ListUsuario e dois ponteiros para char
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e usuarios precisam existir
 * pos-condicao: lista de usuarios não é modificada e as listas de amigos de cada usuario sao modificadas
 */
void insereAmizade(ListUsuario *usuario, char* amigo1, char* amigo2);

/* Retira o amigo da lista de amigos
 * inputs: lista de amigos e nome do amigo a ser retirado
 * output: nenhum
 * pre-condicao: lista de amigos precisa existir e usuario do amigo precisa existir 
 * pos-condicao: lista de amigos continua existindo, agora com um amigo retirado
 */
void retiraAmigo(ListAmigos* lista, char *nome);

// -------- FUNCOES DE RETORNO -------

/* Busca amigo com o nome especificado
 * inputs: ponteiro para ListAmigos e ponteiro para char
 * output: ponteiro para usuario
 * pre-condicao: lista de amigos precisa existir
 * pos-condicao: lista de amigos nao eh modificada
 */
Usuario* buscaAmigoPorNome(ListAmigos* lista, char* nome);

// --------- PARA TESTE ---------

/* Imprime lista de amigos
 * inputs: ponteiro para ListAmigos
 * output: nenhum
 * pre-condicao: lista de amigos precisa existir
 * pos-condicao: lista de amigos nao eh alterada
 */
void imprimeListAmigos(ListAmigos *listAmigos);

#endif