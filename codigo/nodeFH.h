#ifndef _FIB_HEAP_NODE_H_
#define _FIB_HEAP_NODE_H_

#include "tVertice.h"
#include <stdbool.h>

typedef struct fibHeapNode tNodeFH;


tNodeFH *ndFHInit(tVertice *v);

void ndFHdestroy(tNodeFH* nodeFH);

void ndFHinsert(tNodeFH *lista, tNodeFH *novo);

void ndFHremove(tNodeFH *lista, tNodeFH *alvo);

void ndFHiterator(tNodeFH *lista, tNodeFH *head);

//getters e setters

int ndFHgetKey(tNodeFH *nodeFH);

tVertice* ndFHgetVert(tNodeFH *nodeFH);

void ndFHsetVert(tNodeFH *nodeFH, tVertice *vert);

tNodeFH* ndFHgetLeft(tNodeFH *nodeFH);

void ndFHsetLeft(tNodeFH *nodeFH, tNodeFH *left);

tNodeFH* ndFHgetRight(tNodeFH *nodeFH);

void ndFHsetRight(tNodeFH *nodeFH, tNodeFH *right);

tNodeFH* ndFHgetPai(tNodeFH *nodeFH);

void ndFHsetPai(tNodeFH *nodeFH, tNodeFH *pai);

tNodeFH* ndFHgetFilho(tNodeFH *nodeFH);

void ndFHsetFilho(tNodeFH *nodeFH, tNodeFH *filho);

#endif