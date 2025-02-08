#include "tVertice.h"
#include "PQ.h"

typedef struct grafo tGrafo;

tGrafo* GrafoInit(char* path);

void DesalocaGrafo(tGrafo* grafo);

void ImprimeGrafo(tGrafo* grafo);

int GetSizeGrafo(tGrafo* grafo);

tVertice *getOrigemGrafo(tGrafo *g);

void InsereVerticesPQ(tGrafo* grafo, PQ* pq);

void Dijkstra(tGrafo *g, tVertice *source);

void ImprimeCaminhosMenorCusto(tGrafo *grafo, tVertice *source, char *path);