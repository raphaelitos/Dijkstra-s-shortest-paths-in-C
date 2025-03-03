#include <stdio.h>
#include <stdlib.h>
#include "tGrafo.h"
#include "tAresta.h"
#include "PQ.h"


void InsereVerticesPQ(tGrafo* grafo, PQ* pq) {
    if(!grafo || !pq){
        printf("dados invalidos em insereverticesPQ\n");
        exit(EXIT_FAILURE);
    }
    tVertice **vet = getVerticesGrafo(grafo);
    int tam = getNumVerticesGrafo(grafo);
    for(int i = 0; i < tam; i++)
        PQ_insert(pq, vet[i]);
}

void Dijkstra(tGrafo *g, tVertice *source) {
    if(!g || !source){
        printf("Dados invalidos para Dijkstra!");
        return;
    }
    
    int numVertices = GetSizeGrafo(g);
    PQ *pq = PQ_create(numVertices);
    
    // A fonte tem distancia 0
    setAccVert(source, 0);

    // Insere todos os vértices na fila
    InsereVerticesPQ(g, pq);

    while (!PQ_is_empty(pq)) {
        // vertice com menor dist (acc)
        tVertice *u = PQ_delmin(pq);

        // Percorre lista de adjacencias de u
        tListaGen *adj = getAdjVert(u);
        for (tListaGen *aux = adj; aux != NULL; aux = getProxListaGen(aux)) {
            tAresta *aresta = (tAresta*) getInfoListaGen(aux);
            tVertice *v = getDestinoAresta(aresta); 
            
            float peso = getPesoAresta(aresta);
            float alt = getAccVert(u) + peso; 
            
            if (alt < getAccVert(v)) {
                //Atualiza o pai e a PQ
                setPaiVert(v, u);
                PQ_decrementaChave(pq, v, alt);
            }

        }
    }

    PQ_destroy(pq); //libera fila

}