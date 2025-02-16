#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibHeap.h"

struct fibHeap
{
    int qtdNos;
    
    tNodeFH *min;
    
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

tNodeFH* fhInsert(tFH *fh, tVertice *vert){
    if(!fh || !vert){
        printf("ERRO - tentativa de insercao com dados invalidos\n");
        exit(EXIT_FAILURE);
    }
    tNodeFH *newNode = ndFHInit(vert);
    
    //inserindo o novo no na raiz
    if(!fh->raiz) fh->raiz = newNode;
    else ndHFinsert(fh->raiz, newNode);
    
    if(!fh->min || getAccVert(vert) < getAccVert(fh->min)){
        fh->min = vert;
    }//setando novo minimo se necessario
    
    (fh->qtdNos)++;
    return newNode;
}

tNodeFH* fhMinimum(tFH *fh){
    if(!fh){
        printf("dados invalidos em fhMinimum\n");
        exit(EXIT_FAILURE);
    }
    return fh->min;
}

tNodeFH* fhExtractMin(tFH *fh){
    tNodeFH *v = fh->min;

    if(v){
        //Isso aqui vou ter que conferir direito
        //como fazer em C...
        if(ndFHgetFilho(v)){

        }
    }

    return v;
}

static tNodeFH* getUltimoFH(tFH *fh){
    if(!fh){
        printf("dados invalidos em getUltimoFH!\n");
        exit(EXIT_FAILURE);
    }
    return ndFHgetLeft(fh->raiz);
}

void fhUnion(tFH *fh, tFH *outra){
    if(!fh || !outra){
        printf("Dados invalidos em fhUnion!\n");
        exit(1);
    }
    tFH *nova = fhInit();
    nova->raiz = fh->raiz;

    //min de nova sera o menor entre min de fh e outra
    (ndFHgetKey(fh->min) < ndFHgetKey(outra->min)) ? 
    (nova->min = fh->min) : 
    (nova->min = outra->min);
    
    tNodeFH *ultimo = getUltimoFH(outra);
    
    ndFHsetLeft(outra->raiz, ndFHgetLeft(nova->raiz));
    ndFHsetRight(ndFHgetLeft(nova->raiz), outra->raiz);

    ndFHsetLeft(nova->raiz, ultimo);
    ndFHsetRight(ndFHgetLeft(nova->raiz), nova->raiz);

    nova->qtdNos = fh->qtdNos + outra->qtdNos;

    return nova;
}

void fhLink(tFH *fh, tNodeFH *y, tNodeFH *x){
    if(!fh || !y || !x){
        printf("dados invalidos em fhLink");
        exit(1);
    }
    
    ndFHremove(fh->raiz, y);
    
    ndFHsetLeft(y, y);
    ndFHsetRight(y, y);

    //mergechildList

    //INCOMPLETO
}