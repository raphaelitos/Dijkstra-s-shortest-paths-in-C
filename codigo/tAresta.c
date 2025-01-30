#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAresta.h"

struct aresta{
    tVertice* destino;
    float peso;      
};

tAresta *criaAresta(tVertice* destino, float peso){
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

int ImprimeAresta(void* a, void* b) {
    tAresta* aresta = (tAresta*) a;
    printf("%s [%.2f], ", getNomeVert(aresta->destino), aresta->peso);

    return 1;
}

float getPesoAresta(tAresta *a) {
    return a->peso; 
}
tVertice* getDestinoAresta(tAresta *a) {
    return a->destino;
}