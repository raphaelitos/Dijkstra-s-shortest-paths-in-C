#ifndef _FIB_HEAP_NODE_H_
#define _FIB_HEAP_NODE_H_

#include "tVertice.h"
#include <stdbool.h>

typedef struct fibHeapNode tNodeFH;


tNodeFH *ndFHInit(tVertice *v);

void ndFHdestroy(tNodeFH* nodeFH);

void ndFHinsert(tNodeFH *lista, tNodeFH *novo);

//Essa funcao basicamente isola um no
void ndFHremove(tNodeFH *node);

void ndFHinsertFilho(tNodeFH *nodeFH, tNodeFH *filho);

void ndFHremoveFilho(tNodeFH *pai, tNodeFH *filho);

//getters e setters

int ndFHgetKey(tNodeFH *nodeFH);

void ndFHsetKey(tNodeFH *nodeFH, int newKey);

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

void ndFHsetGrau(tNodeFH *node, int grauNovo);

void ndFHincGrau(tNodeFH *node);

bool ndFHgetMarcado(tNodeFH *node);

void ndFHsetMarcado(tNodeFH *node, bool valor);

#endif