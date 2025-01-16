#ifndef PQ_H
#define PQ_H

#include "tVertice.h"
#include <stdbool.h>

typedef struct pq PQ;

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N);

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq);

/*
 * Insere o vertice na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, tVertice* v);

/*
 * Remove e retorna o vertice mais próximo.
 */
tVertice* PQ_delmin(PQ *pq);

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq);
/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq);

#endif
