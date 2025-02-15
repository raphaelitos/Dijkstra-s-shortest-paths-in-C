#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibHeap.h"

struct fibHeap
{
    int qtdNos;
    
    tVertice *min;
    
    tNodeFH *raiz;
};


tFH *fhInit(){
    tFH *fh = calloc(1, sizeof(tFH));
    if(!fh){
        printf("Falha na alocacao de FH!\n");
        exit(EXIT_FAILURE);
    }
    fh->min = NULL;
    fh->raiz = NULL;

    return fh;
}

void fhDestroy(tFH *fh);

void fhInsert(tFH *fh, tNodeFH *node);

int fhMinimum(tFH *fh){
    if(!fh){
        printf("ERRO - tentativa de min em FH nula\n");
        exit(EXIT_FAILURE);
    }
    return fh->min;
}

tNodeFH* fhExtractMin(tFH *fh);

void fhUnion(tFH *fh);