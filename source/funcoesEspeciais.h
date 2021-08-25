#ifndef FUNCOES_ESPECIAIS
#define FUNCOES_ESPECIAIS

#include "listaUsuario.h"

// --------- FUNCOES ESPECIAIS ---------

/* Reestrutura a organizacao das playlists de cada usuario e separa elas por nome do cantor/banda
 * inputs: ponteiro para ListUsuario
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e lista de playlists já deve ter sido preenchida
 * pos-condicao: lista de playlist agora possui playlists separadas por cantor/banda
 */
void criaListPlaylistPorCantor(ListUsuario *usuario);//ok

/* Cria os arquivos de playlist de cada usuario
 * inputs: ponteiro para ListUsuario
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e lista de playlists já deve ter sido preenchida
 * pos-condicao: lista de usuarios e de playlists nao sao modificadas
 */
void criaArquivoPlayEDRefatorada(ListUsuario *usuario);

/* Cria arquivo indicando a quantidade de gostos semelhantes entre os amigos
 * inputs: ponteiro para ListUsuario
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e lista de playlists já deve ter sido preenchida
 * pos-condicao: lista de usuarios e de playlists nao sao modificadas
 */
void criaArquivoPlayEDPorGosto(ListUsuario *usuario);

/* Mescla as playlists de mesmo nome entre amigos
 * inputs: ponteiro para ListUsuario
 * output: nenhum
 * pre-condicao: lista de usuarios precisa existir e lista de playlists já deve ter sido preenchida
 * pos-condicao: lista de usuarios nao e modificada, mas lista de playlists pode possuir novas musicas
 */
void mergePlaylistAmigos(ListUsuario *usuario);


#endif //FUNCOES_ESPECIAIS