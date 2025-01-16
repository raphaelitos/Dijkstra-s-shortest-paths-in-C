#include "tVertice.h"
#include "PQ.h"

typedef struct grafo tGrafo;

tGrafo* GrafoInit(char* path);

void DesalocaGrafo(tGrafo* grafo);

void ImprimeGrafo(tGrafo* grafo);

int GetSizeGrafo(tGrafo* grafo);

void InsereVerticesPQ(tGrafo* grafo, PQ* pq);