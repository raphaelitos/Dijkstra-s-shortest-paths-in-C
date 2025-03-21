/**
 * @file    tAresta.h
 * @brief   Define funcoes referentes a aresta de um grafo
 * dirigido ponderado
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#ifndef _T_ARESTA_
#define _T_ARESTA_

#include "tVertice.h"

typedef struct aresta tAresta;

/// @brief cria uma aresta
/// @param destino o no ao qual se destina a aresta
/// @param peso o peso da aresta
/// @return a aresta criada
tAresta *criaAresta(tVertice* destino, double peso);

/// @brief libera a memoria utilizada por a
/// @param a uma aresta valida
void apagaAresta(void* a);

/// @brief obtem o peso de a
/// @param a uma aresta valida
/// @return o valor do custo para
/// chegar ao destino de a
double getPesoAresta(tAresta *a);

/// @brief obtem o destino de a 
/// @param a uma aresta valida
/// @return o vertice onde a incide
tVertice* getDestinoAresta(tAresta *a);

#endif