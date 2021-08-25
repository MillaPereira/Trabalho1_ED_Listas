#ifndef MUSICA_H_
#define MUSICA_H_

typedef struct musica Musica;

// -------- FUNCOES DE CRIACAO E DESTRUICAO -------

/* Cria a struct musica
 * inputs: nome da musica e nome do cantor 
 * output: ponteiro para a struct Musica
 * pre-condicao: nenhuma
 * pos-condicao: ponteiro de retorno existe e esta alocado
 */
Musica *criaMusica(char *nome, char *cantor);

/* Libera memória alocada para a playlist
 * inputs: ponteiro para a struct Musica
 * output: nenhum
 * pre-condicao: musica precisa existir
 * pos-condicao: toda a memória alocada para musica foi liberada
 */
void destroiMusica(Musica *musica);

// -------- FUNCOES DE RETORNO -------

/* Retorna o nome da musica
 * inputs: ponteiro para a struct musica
 * output: ponteiro para char que e o nome da musica
 * pre-condicao: musica precisa existir
 * pos-condicao: musica nao eh modificada
 */
char *retornaNomeMusica(Musica *musica);

/* Retorna o nome do cantor da musica
 * inputs: ponteiro para a struct musica
 * output: ponteiro para char que eh o nome do cantor 
 * pre-condicao: musica precisa existir
 * pos-condicao: musica nao eh modificada
 */
char *retornaCantorMusica(Musica *musica);

/*Cria uma copia da musica
 * inputs: ponteiro para struct musica
 * output: ponteiro para struct musica
 * pre-condicao: musica precisa existir
 * pos-condicao: Musica nao eh alterada e uma nova copia existe
 */
Musica *criaCopiaMusica(Musica* musica);

// -------- PARA TESTE -------

/*Imprime Musica
 * inputs: ponteiro para struct musica
 * output: nenhum
 * pre-condicao: Musica precisa existir
 * pos-condicao: Musica nao eh alterado
 */
void imprimeMusica(Musica *musica);

#endif