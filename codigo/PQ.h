/**
 * @file    PQ.h
 * @brief   Define funcoes referentes a uma fila de prioridades
 * com heap binaria
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
 * 
 * O codigo foi adaptado do exemplo dado em aula e presente nos materiais
 * disponibilizados pelo professor
*/

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

void PQ_decrementaChave(PQ *pq, tVertice *v, double novaDist);

#endif
