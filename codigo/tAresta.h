#ifndef _T_ARESTA_
#define _T_ARESTA_

#include "tVertice.h"

typedef struct aresta tAresta;

/// @brief cria uma aresta
/// @param destino o no ao qual se destina a aresta
/// @param peso o peso da aresta
/// @return a aresta criada
tAresta *criaAresta(tVertice* destino, float peso);

void apagaAresta(void* a);

int ImprimeAresta(void* a, void* b);

float getPesoAresta(tAresta *a);

tVertice* getDestinoAresta(tAresta *a);

#endif