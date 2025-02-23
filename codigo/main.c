#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tGrafo.h"
#include "PQ.h"
#include "fibHeap.h"

int main(int argc, char *argv[])
{
    
    if(argc <= 2){
        printf("eh");
        return 0;
    }
    
    tGrafo *grafo = GrafoInit(argv[1]);
    
    tVertice *src = getOrigemGrafo(grafo);
    
    if(!src){
        printf("viixiiii :((");
        DesalocaGrafo(grafo);
        return 0;
    }

    Dijkstra(grafo, src);

    ImprimeCaminhosMenorCusto(grafo, src, argv[2]);

    DesalocaGrafo(grafo);

    return 0;
}
