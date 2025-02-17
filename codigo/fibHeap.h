#ifndef _FIB_HEAP_
#define _FIB_HEAP_

#include "nodeFH.h"

typedef struct fibHeap tFH;

tFH *fhInit();

void fhDestroy(tFH *fh);

tNodeFH* fhInsert(tFH *fh, tVertice *vert);

tNodeFH* fhMinimum(tFH *fh);

tNodeFH* fhExtractMin(tFH *fh);

void fhUnion(tFH *fh, tFH *nova);

void fhLink(tFH *fh, tNodeFH *y, tNodeFH *x);

void fhConsolidate(tFH *fh);

//Vale refletir se sera necessario criar um ponteiro
//fibnode em vertice para essa parte aqui
void fhDecreaseKey(tFH *fh, tNodeFH *node);


/*
PESQUISAR O ITERATE E ENTAO CONFERIR A TRADUCAO DO 
CONSOLIDATE
EXTRACTMIN
*/
#endif