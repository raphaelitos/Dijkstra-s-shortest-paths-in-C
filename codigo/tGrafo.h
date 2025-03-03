#ifndef _TGRAFO_H_
#define _TGRAFO_H_

#include "tVertice.h"

typedef struct grafo tGrafo;

tGrafo* GrafoInit(char* path);

void DesalocaGrafo(tGrafo* grafo);

void ImprimeGrafo(tGrafo* grafo);

int GetSizeGrafo(tGrafo* grafo);

tVertice *getOrigemGrafo(tGrafo *g);

tVertice **getVerticesGrafo(tGrafo *g);

int getNumVerticesGrafo(tGrafo *g);

void Dijkstra(tGrafo *g, tVertice *source);

void ImprimeCaminhosMenorCusto(tGrafo *grafo, tVertice *source, char *path);

#endif