#ifndef _T_ARESTA_
#define _T_ARESTA_

typedef struct aresta tAresta;

/// @brief cria uma aresta
/// @param destino o no ao qual se destina a aresta
/// @param peso o peso da aresta
/// @return a aresta criada
tAresta *criaAresta(int destino, int peso);

#endif