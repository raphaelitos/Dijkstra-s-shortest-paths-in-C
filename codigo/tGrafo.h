/**
 * @file    tGrafo.h
 * @brief   Define funcoes referentes a um grafo
 * dirigido ponderado
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#ifndef _TGRAFO_H_
#define _TGRAFO_H_

#include "tVertice.h"

typedef struct grafo tGrafo;

/// @brief Inicializa um grafo com as
/// informacoes contidas no arquivo em path
/// @param path um caminho valido para o
/// contendo informacoes sobre os vertices
/// @return uma estrutura grafo devidamente 
/// inicializada e alocada dinamicamente
tGrafo* GrafoInit(char* path);

/// @brief Libera a memoria usada por grafo
/// @param grafo um grafo valido
void DesalocaGrafo(tGrafo* grafo);

/// @brief Exibe as informacoes de grafo no terminal
/// @param grafo um grafo valido
void ImprimeGrafo(tGrafo* grafo);

/// @brief Obtem o vertice origem de g
/// @param g um grafo valido
/// @return o vertice de origem do caminho
/// minimo calculado por Dijkstra
tVertice *getOrigemGrafo(tGrafo *g);

/// @brief Obtem os vertices de g
/// @param g um grafo valido
/// @return o vetor de vertices de g
tVertice **getVerticesGrafo(tGrafo *g);

/// @brief Obtem o tamanho de grafo
/// @param grafo um grafo valido
/// @return o numero de vertices de grafo
int getNumVerticesGrafo(tGrafo *g);

/// @brief Calcula o menor caminho partindo de
/// source ate' os outros vertices de g
/// @param g um grafo valido
/// @param source um vertice valido existente em g
void Dijkstra(tGrafo *g, tVertice *source);

/// @brief imprime os caminhos de menor custo de
/// source ate' os outros vertices de grafo
/// no arquivo indicado por path
/// @param grafo um grafo valido 
/// @param source um vertice valido existente em grafo
/// @param path um caminho valido para o arquivo onde
/// os caminhos serao impressos
void ImprimeCaminhosMenorCusto(tGrafo *grafo, tVertice *source, char *path);

#endif