#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tIterator.h"


typedef struct Iterator {
    tNodeFH *inicio;    // Ponteiro para o nó inicial (cabeça) da lista circular
    tNodeFH *atual;     // Ponteiro para o nó atual na iteração
    int comecou;        // Flag para indicar se a iteração já começou
} Iterator;

// Cria e inicializa o iterador para a lista circular com o nó inicio.
Iterator* createIterator(tNodeFH *inicio) {
    Iterator *it = malloc(sizeof(Iterator));
    if (it == NULL) {
        printf("erro na alocacao de tIterator!\n");
        exit(EXIT_FAILURE);
    }
    it->inicio = inicio;
    it->atual = inicio;
    it->comecou = 0;
    return it;
}

// Verifica se ainda há um próximo elemento na iteração.
bool iteratorHasNext(Iterator *it) {
    if (it->inicio == NULL) {
        return false;
    }
    // Se não iniciou, temos ao menos o inicio; depois, verificamos se voltou ao início.
    return !it->comecou || (it->atual != it->inicio);
}

// Retorna o próximo nó da iteração e avança o ponteiro.
tNodeFH* iteratorNext(Iterator *it) {
    if (!iteratorHasNext(it)) {
        return NULL;  // Final da iteração
    }
    tNodeFH *node = it->atual;
    it->atual = ndFHgetRight(it->atual);
    it->comecou = 1;  // Marca que a iteração já começou
    return node;
}

// Libera a memória do iterador.
void destroyIterator(Iterator *it) {
    free(it);
}