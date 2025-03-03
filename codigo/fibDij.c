#include <stdio.h>
#include <stdlib.h>
#include "tGrafo.h"
#include "tAresta.h"
#include "fibHeap.h"


void fhInsereVertices(tGrafo* grafo, tFH* fh) {
    if(!grafo || !fh){
        printf("dados invalidos em insereverticesPQ\n");
        exit(EXIT_FAILURE);
    }
    tVertice **vet = getVerticesGrafo(grafo);
    int tam = getNumVerticesGrafo(grafo);
    for(int i = 0; i < tam; i++)
        fhInsert(fh, vet[i]);
}

void Dijkstra(tGrafo *g, tVertice *source) {
    if(!g || !source){
        printf("Dados invalidos para Dijkstra!");
        return;
    }
    
    // A fonte tem distancia 0
    setAccVert(source, 0);

    tFH *fh = fhInit();

    fhInsereVertices(g, fh);
    

    while (!fhIsEmpty(fh)) {
        // vertice com menor dist (acc)
        tVertice *u = fhExtractMin(fh);

        // Percorre lista de adjacencias de u
        tListaGen *adj = getAdjVert(u);
        for (tListaGen *aux = adj; aux != NULL; aux = getProxListaGen(aux)) {
            tAresta *aresta = (tAresta*) getInfoListaGen(aux);
            tVertice *v = getDestinoAresta(aresta); 
            
            float peso = getPesoAresta(aresta);
            float alt = getAccVert(u) + peso; 
            
            if (alt < getAccVert(v)) {
                //Atualiza o pai e a fh
                setPaiVert(v, u);
                fhDecreaseKey(fh, getNodeFHVert(v), alt);
            }

        }
    }

    fhDestroy(fh); //libera estrutura
}