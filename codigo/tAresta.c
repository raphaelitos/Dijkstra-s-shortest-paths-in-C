/**
 * @file    tAresta.c
 * @brief   Implementa funcoes referentes a aresta de um grafo
 * dirigido ponderado
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAresta.h"

/// @brief Representa uma aresta de um
/// grafo dirigido ponderado
struct aresta{
    // onde a aresta incide
    tVertice* destino;
    // custo para chegar ao destino 
    // saindo do vertice que possui a aresta
    // em sua lista de adjacencias
    double peso;      
};

tAresta *criaAresta(tVertice* destino, double peso){
    tAresta *aresta = (tAresta *)calloc(1, sizeof(tAresta));
    if (!aresta) exit(EXIT_FAILURE);
    
    aresta->destino = destino;
    aresta->peso = peso;

    return aresta;
}

void apagaAresta(void* a) {
    tAresta* aresta = (tAresta*) a;
    if(aresta != NULL) free(a);
}

double getPesoAresta(tAresta *a) {
    return a->peso; 
}
tVertice* getDestinoAresta(tAresta *a) {
    return a->destino;
}