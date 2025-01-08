#ifndef _TVERT_
#define _TVERT_

#include "listaGen.h"

typedef struct vertice tVertice;

/// @brief cria um vertice
/// @param nome o nome do novo vertice
/// @return o vertice criado
tVertice *criaVertice(const char *nome);

/// @brief cria a "aresta" de v ao vizinho
/// @param v o vertice cuja lista esta sendo feita
/// @param id_vizinho o outro vertice que se relaciona com v ( a outra ponta da aresta)
/// @param peso  peso da aresta
void adicionaLista(tVertice *v, int id_vizinho, int peso);

tListaGen *getAdjVert(tVertice *v);

tListaGen *getNomeVert(tVertice *v);

void addVizinhoVert(tVertice *v, void *dado);

#endif