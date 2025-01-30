#ifndef _TVERT_
#define _TVERT_

#include "listaGen.h"

typedef struct vertice tVertice;

/// @brief cria um vertice
/// @param nome o nome do novo vertice
/// @return o vertice criado
tVertice *criaVertice(const char *nome);

void apagaVertice(tVertice* v);

/// @brief cria a "aresta" de v ao vizinho
/// @param v o vertice cuja lista esta sendo feita
/// @param id_vizinho o outro vertice que se relaciona com v ( a outra ponta da aresta)
/// @param peso  peso da aresta
void adicionaLista(tVertice *v, int id_vizinho, int peso);

tListaGen *getAdjVert(tVertice *v);

char *getNomeVert(tVertice *v);

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
void setAccVert(tVertice* v, int acc);

/// @brief retorna o inteiro correspondente ao valor acumulado de v
/// @param v o vértice que terá seu valor retornado
/// @return o inteiro correspondente
int getAccVert(tVertice* v);

void setPosHeapVert(tVertice* v, int posHeap);

int getPosHeapVert(tVertice* v);

void imprimeVert(tVertice* v);

#endif