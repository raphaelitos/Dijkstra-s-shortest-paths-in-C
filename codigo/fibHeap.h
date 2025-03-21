/**
 * @file    fibHeap.h
 * @brief   Define as funcoes referentes a uma heap fibonacci
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
 * 
 * A implementacao da estrutura foi inspirada no codigo em python disponivel em:
 * https://github.com/msambol/dsa/blob/master/data_structures/fibonacci_heap.py
*/

#ifndef _FIB_HEAP_
#define _FIB_HEAP_

typedef struct fibHeap tFH;

#include "nodeFH.h"

/*
 Existem funcoes aqui que nao sao utilizadas no projeto,
 elas foram mantidas para manter uma
 implementacao mais ampla de heap fibonacci
*/

/// @brief inicializa uma heap fibonacci
/// @return uma heap fibonacci 
/// devidamente alocada na memoria
tFH *fhInit();

/// @brief libera a memoria usada por fh
/// @param fh uma heap fibonacci valida
void fhDestroy(tFH *fh);

/// @brief insere vert na raiz de fh
/// @param fh uma fib heap valida
/// @param vert um vertice valido
/// @return o no inserido criado 
/// a partir de vert
tNodeFH* fhInsert(tFH *fh, tVertice *vert);

/// @brief obtem o no com menor valor em fh
/// @param fh uma fib heap valida
/// @return o no que representa o vertice
/// com menor valor de acc
tNodeFH* fhMinimum(tFH *fh);

/// @brief retira de fh o no
/// com menor da origem do grafo
/// rearranjando toda a estrutura
/// de forma que na raiz nao exista dois 
/// nos com mesmo grau
/// @param fh uma fib heap valida
/// @return o vertice representado
/// pelo no retirado
tVertice* fhExtractMin(tFH *fh);

/// @brief funde outra 'a fh
/// @param fh uma fib heap valida
/// @param outra uma fib heap valida
/// @return 
tFH* fhUnion(tFH *fh, tFH *outra);

/// @brief altera a chave de node caso newKey
/// seja menor que a chave atual e o coloca num
/// local adequado em fh
/// @param fh uma fib heap valida
/// @param node um no valido existente em fh
/// @param newKey candidato a nova distancia de 
/// node 'a origem
void fhDecreaseKey(tFH *fh, tNodeFH *node, double newKey);

/// @brief verifica se fh esta vazia
/// @param fh uma fib heap valida
/// @return true se fh estiver vazia,
/// false caso contrario
bool fhIsEmpty(tFH *fh);

#endif