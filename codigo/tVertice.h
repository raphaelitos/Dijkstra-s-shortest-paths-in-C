#ifndef _TVERT_
#define _TVERT_

#include "listaGen.h"

typedef struct vertice tVertice;

#include "nodeFH.h"

/// @brief cria um vertice
/// @param nome o nome do novo vertice
/// @return o vertice criado
tVertice *criaVertice(const char *nome);

/// @brief libera a memoria usada por v
/// @param v um vertice valido
void apagaVertice(tVertice* v);

/// @brief obtem a lista de adjascencias de v
/// @param v um vertice valido
/// @return uma lista generica com os vertices
/// adjascentes a v
tListaGen *getAdjVert(tVertice *v);

/// @brief obtem o nome de v
/// @param v um no valido
/// @return a string que representa o
/// rotulo de v
char *getNomeVert(tVertice *v);

/// @brief adiciona um vizinho a v
/// @param v um vertice valido
/// @param dado o conteudo do novo 
/// vizinho de v (em nossa aplicacao,
/// e' a aresta)
void addVizinhoVert(tVertice *v, void *dado);

/// @brief Define o vértice pai como antecedente do vértice v, criando uma conexão
/// @param v o vértice cujo pai será definido
/// @param pai o vértice pai
void setPaiVert(tVertice* v, tVertice* pai);

/// @brief retorna o ponteiro para o pai de um vértice dado
/// @param v o vértice que terá seu pai retornado
/// @return o vertice pai correspondente
tVertice* getPaiVert(tVertice* v);

/// @brief Define o valor acumulado para o vértice v
/// @param v o vértice cujo valor será definido
/// @param acc o valor acumulador
void setAccVert(tVertice* v, float acc);

/// @brief Obtem o valor acumulado de v
/// @param v o vértice que terá seu valor retornado
/// @return o valor correspondente 'a distancia
/// de v ao vertice fonte
float getAccVert(tVertice* v);

/// @brief Define a posicao de v na heap binaria
/// @param v um vertice valido
/// @param posHeap a nova posivao de v na heap,
/// necessario para otimizacao de decreaseKey
void setPosHeapVert(tVertice* v, int posHeap);

/// @brief Obtem a posicao de v na heap binaria
/// @param v um vertice valido
/// @return o inteiro correspondente 'a posicao
/// de v na heap binaria
int getPosHeapVert(tVertice* v);

/// @brief Obtem o no da heap fibonacci que 
/// contem v
/// @param v um no valido 
/// @return um ponteiro para o no que representa
/// v na heap fibonacci
tNodeFH *getNodeFHVert(tVertice *v);

/// @brief Define nodeFH como representante
/// de v na heap fibonacci
/// @param v um vertice valido
/// @param nodeFH um no valido da heap fibonacci
void setNodeFHVert(tVertice *v, tNodeFH *nodeFH);

/// @brief Imprime um vertice, exibindo
/// seu pai, seu rotulo e seu acc
/// @param v um vertice valido
void imprimeVert(tVertice* v);

#endif