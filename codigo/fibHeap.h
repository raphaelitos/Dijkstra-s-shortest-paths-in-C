#ifndef _FIB_HEAP_
#define _FIB_HEAP_

#include "nodeFH.h"
#include "circList.h"

typedef struct fibHeap tFH;


tFH *fhInit();

void fhDestroy(tFH *fh);

void fhInsert(tFH *fh, tNodeFH *node);

int fhMinimum(tFH *fh);

tNodeFH* fhExtractMin(tFH *fh);

void fhUnion(tFH *fh);

#endif