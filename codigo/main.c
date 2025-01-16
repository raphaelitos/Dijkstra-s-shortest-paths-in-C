#include <stdio.h>
#include <stdlib.h>
#include "tGrafo.h"
#include "PQ.h"

int main(int argc, char *argv[])
{
    tGrafo *grafo = GrafoInit(argv[1]);
    PQ* pq = PQ_create(GetSizeGrafo(grafo));

    InsereVerticesPQ(grafo, pq);

    PQ_destroy(pq);
    DesalocaGrafo(grafo);

    return 0;
}
