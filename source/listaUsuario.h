#ifndef LISTAUSUARIO_H_
#define LISTAUSUARIO_H_

typedef struct celUsuario CelUsuario;
typedef struct listUsuario ListUsuario;

#include "usuario.h"

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Inicializa a lista de usuario 
 * inputs: string que eh o nome do arquivo
 * output: ponteiro para a struct ListUsuario
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
ListUsuario* inicializaListUsuario(char* arquivo);

/* Libera memória alocada para a ListUsuario
 * inputs: ponteiro para a struct ListUsuario
 * output: nenhum
 * pre-condicao: ListUsuario precisa existir
 * pos-condicao: toda a memória alocada para ListUsuario foi liberada
 */
void destroiListUsuario(ListUsuario* lista);

// -------- FUNCOES DE INSERCAO E RETIRADA DE ELEMENTOS -------

/* Insere o usuario no final da lista de usuarios 
 * inputs: ponteiro para a struct ListUsuario e o ponteiro para o usuario
 * output: nenhum
 * pre-condicao: lista de usuario precisa existir e usuario precisa existir
 * pos-condicao: lista continua existindo, agora com usuarios inseridos
 */
void insereUsuario(ListUsuario* lista, Usuario *usuario);

/* Retira o usuario da lista de usuarios 
 * inputs: ponteiro para struct listUsuario e string do nome do usuario 
 * output: nenhum
 * pre-condicao: lista de usuario precisa existir
 * pos-condicao: lista continua existindo, agora com usuarios em questao retirado
 */
void retiraUsuario(ListUsuario* lista, char *nome);

// -------- FUNCOES DE RETORNO -------

/* Retorna usuario com o nome especificado
 * inputs: ponteiro para ListaUsuario e ponteiro para char
 * output: ponteiro para usuario 
 * pre-condicao: lista de usuarios precisa existir
 * pos-condicao: lista de usuarios nao eh modificada
 */
Usuario *buscaUsuario(ListUsuario *lista, char *nome);

/* Retorna primeira celula da lista
 * inputs: ponteiro para ListaUsuario
 * output: ponteiro para CelUsuario 
 * pre-condicao: lista de usuarios precisa existir
 * pos-condicao: lista de usuarios nao eh modificada
 */
CelUsuario *retornaPrimeiro(ListUsuario* lista);

/* Retorna ultima celula da lista
 * inputs: ponteiro para ListaUsuario
 * output: ponteiro para CelUsuario 
 * pre-condicao: lista de usuarios precisa existir
 * pos-condicao: lista de usuarios nao eh modificada
 */
CelUsuario *retornaUltimo(ListUsuario* lista);

/* Retorna proxima celula
 * inputs: ponteiro para CelUsuario
 * output: ponteiro para CelUsuario 
 * pre-condicao: lista de usuarios precisa existir
 * pos-condicao: lista de usuarios nao eh modificada
 */
CelUsuario *retornaProximo(CelUsuario* p);

/* Retorna o usuario da celula
 * inputs: ponteiro para celula de usuario
 * output: ponteiro para usuario 
 * pre-condicao: celula precisa existir
 * pos-condicao: celula nao eh modificada
 */
Usuario *retornaUsuarioCelula(CelUsuario* p);

// ---- PARA TESTE -----

/* Imprime lista usuario
 * inputs: ponteiro para lista de usuarios
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir
 * pos-condicao: lista de usuarios nao eh alterado
 */
void imprimeListUsuario(ListUsuario* lista);//ok

#endif