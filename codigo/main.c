#include <stdio.h>
#include <stdlib.h>
#include "tGrafo.h"
#include "PQ.h"

int main(int argc, char *argv[])
{
    tGrafo *grafo = GrafoInit(argv[1]);
    
    tVertice *src = getOrigemGrafo(grafo);
    
    if(!src){
        printf("viixiiii :((");
        DesalocaGrafo(grafo);
        return 0;
    }

    Dijkstra(grafo, src);

    ImprimeCaminhosMenorCusto(grafo, src, argv[1]);

    DesalocaGrafo(grafo);

    return 0;
}
