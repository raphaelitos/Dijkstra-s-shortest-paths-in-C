#ifndef _T_ARESTA_
#define _T_ARESTA_

#include "tVertice.h"

typedef struct aresta tAresta;

/// @brief cria uma aresta
/// @param destino o no ao qual se destina a aresta
/// @param peso o peso da aresta
/// @return a aresta criada
tAresta *criaAresta(tVertice* destino, float peso);

/// @brief libera a memoria utilizada por a
/// @param a uma aresta valida
void apagaAresta(void* a);

/// @brief exibe o conteudo de a no terminal
/// @param a uma aresta 
/// @param b um dado qualquer
/// @return 1
int ImprimeAresta(void* a, void* b);

/// @brief obtem o peso de a
/// @param a uma aresta valida
/// @return o valor do custo para
/// chegar ao destino de a
float getPesoAresta(tAresta *a);

/// @brief obtem o destino de a 
/// @param a uma aresta valida
/// @return o vertice onde a incide
tVertice* getDestinoAresta(tAresta *a);

#endif