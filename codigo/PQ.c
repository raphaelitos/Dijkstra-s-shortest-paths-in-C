#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

#define exch(A, B) {tVertice* t = A; A = B; B = t;}

struct pq{
    tVertice** vet;
    int max_N;
    int atual_N;
};

/*
 * Compara dois vértices pelos os seus valores acumulados (referente ao peso do caminho).
 * Retorna um valor negativo se v1.acc < v2.acc.
 * Retorna um valor positivo se v1.acc > v2.acc.
 * Retorna zero se v1.acc == v2.acc.
 */
static float ComparaVertice(tVertice *v1, tVertice *v2) {
    return getAccVert(v1) - getAccVert(v2);
}

static void Fix_down(PQ* fila, int pos_i) {
    while (2*pos_i <= fila->atual_N) {
        int menor = 2*pos_i;
        if (menor < fila->atual_N && ComparaVertice(fila->vet[menor], fila->vet[menor+1]) > 0) {
            menor++;
        }
        if (ComparaVertice(fila->vet[pos_i], fila->vet[menor]) <= 0) break;

        exch(fila->vet[pos_i], fila->vet[menor]);
        pos_i = menor;
    }
}

static void Fix_up(PQ* fila, int pos_i) {
    if(fila ==  NULL) return;

    while (pos_i > 1 && ComparaVertice(fila->vet[pos_i/2], fila->vet[pos_i]) > 0) {
        exch(fila->vet[pos_i], fila->vet[pos_i/2]);
        pos_i = pos_i/2;
    }

}

PQ* PQ_create(int max_N) {
    PQ* fila = malloc(sizeof(PQ));
    if(fila == NULL) {
        printf("Erro ao alocar a fila dinamicamente\n");
        return NULL;
    }

    fila->vet = malloc(sizeof(tVertice*) * (max_N + 1));
    if(fila->vet == NULL) {
        printf("Erro ao alocar dinamicamente o vetor de vertices da fila\n");
        return NULL;
    }

    fila->max_N = max_N;
    fila->atual_N = 0;

    return fila;
}

void PQ_destroy(PQ *pq) {
    if(pq != NULL) {
        if(pq->vet != NULL) {
            free(pq->vet);
        }
        free(pq);
    }
}

void PQ_insert(PQ *pq, tVertice *e) {
    if(pq == NULL || e == NULL) return;

    if (pq->atual_N >= pq->max_N) {
        printf("Erro: fila cheia, não é possível inserir mais vertices.\n");
        return;
    }

    (pq->atual_N)++;
    pq->vet[pq->atual_N] = e;
    Fix_up(pq, pq->atual_N);
}

tVertice* PQ_delmin(PQ *pq) {
    if(pq == NULL || pq->atual_N == 0) return NULL;

    tVertice* aux = pq->vet[1];
    exch(pq->vet[1], pq->vet[pq->atual_N]);
    (pq->atual_N)--;
    Fix_down(pq, 1);

    return aux;
}

bool PQ_is_empty(PQ *pq) {
    if(pq->atual_N == 0) return true;
    return false;
}

int PQ_size(PQ *pq) {
    return pq->atual_N;
}
