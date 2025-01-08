#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAresta.h"

struct aresta{
    int destino;
    int peso;      
};

tAresta *criaAresta(int destino, int peso){
    tAresta *aresta = (tAresta *)calloc(1, sizeof(tAresta));
    if (!aresta) exit(EXIT_FAILURE);
    
    aresta->destino = destino;
    aresta->peso = peso;

    return aresta;
}