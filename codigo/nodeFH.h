/**
 * @file    nodeFH.h
 * @brief   Implementa funcoes referentes ao no de uma heap fibonacci
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#ifndef _FIB_HEAP_NODE_H_
#define _FIB_HEAP_NODE_H_

#include <stdbool.h>

typedef struct fibHeapNode tNodeFH;

#include "tVertice.h"

/// @brief inicializa um no da fib heap
/// @param v um vertice valido
/// @return um  no devidamente inicializado
/// e alocado dinamicamente
tNodeFH *ndFHInit(tVertice *v);

/// @brief libera a memoria usada por nodeFH
/// @param nodeFH um no valido na heap fibonacci
void ndFHdestroy(tNodeFH* nodeFH);

/// @brief promove novo 'a irmao de lista
/// @param lista um no valido na fib heap
/// @param novo um no da fib heap que nao deve
/// ter irmaos
void ndFHinsert(tNodeFH *lista, tNodeFH *novo);

/// @brief remove o no da sua lista de irmaos
/// o deixando isolado
/// @param node um no valido da fib heap
void ndFHremove(tNodeFH *node);

/// @brief promove filho 'a filho de nodeFH
/// @param nodeFH um no valido na fib heap
/// @param filho um no da fib heap que nao deve
/// ter irmaos 
void ndFHinsertFilho(tNodeFH *nodeFH, tNodeFH *filho);

/// @brief promove filho 'a orfao
/// @param pai um no valido da fib heap
/// que deve ser pai de filho
/// @param filho um no valido da fib heap
/// que deve ter pai como pai
/// @return 
tNodeFH* ndFHremoveFilho(tNodeFH *pai, tNodeFH *filho);


//getters e setters

double ndFHgetKey(tNodeFH *nodeFH);

void ndFHsetKey(tNodeFH *nodeFH, double newKey);

tVertice* ndFHgetVert(tNodeFH *nodeFH);

void ndFHsetVert(tNodeFH *nodeFH, tVertice *vert);

tNodeFH* ndFHgetLeft(tNodeFH *nodeFH);

void ndFHsetLeft(tNodeFH *nodeFH, tNodeFH *left);

tNodeFH* ndFHgetRight(tNodeFH *nodeFH);

void ndFHsetRight(tNodeFH *nodeFH, tNodeFH *right);

tNodeFH* ndFHgetPai(tNodeFH *nodeFH);

void ndFHsetPai(tNodeFH *nodeFH, tNodeFH *pai);

tNodeFH* ndFHgetFilho(tNodeFH *nodeFH);

int ndFHgetGrau(tNodeFH *node);

bool ndFHgetMarcado(tNodeFH *node);

void ndFHsetMarcado(tNodeFH *node, bool valor);

#endif