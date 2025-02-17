#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFH.h"

struct fibHeapNode
{
    tVertice *vert;
    
    tNodeFH *left, *right;// uma lista circular
    tNodeFH *pai;
    tNodeFH *filho; //pode ter mais de um, mas so aponta p um

    bool marcado; //auxiliar para FibHeap
    int grau; //n de filhos
};

tNodeFH *ndFHInit(tVertice *v){
    if(!v){
        printf("Dado invalido em ndFHInit!\n");
        exit(EXIT_FAILURE);
    }
    tNodeFH *newNode = calloc(1, sizeof(tNodeFH));
    if(!newNode){
        printf("Falha na alocacao de tNodeFH!\n");
        exit(EXIT_FAILURE);
    }
    newNode->vert = v;
    newNode->pai = newNode->filho = NULL;
    newNode->left = newNode->right = newNode;

    return newNode;
}

void ndFHdestroy(tNodeFH* nodeFH);

void ndHFinsert(tNodeFH *lista, tNodeFH *novo){
    if(!lista || !novo){
        printf("Dados invalidos em ndFHinsert!\n");
        exit(EXIT_FAILURE);
    }
    novo->right = lista->right;
    novo->left = lista->left;
    lista->left->right = novo;
    lista->left = novo;
}

void ndHFremove(tNodeFH *lista, tNodeFH *alvo);

void ndHFiterator(tNodeFH *lista, tNodeFH *head);

int ndFHgetKey(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("Dados invalidos em ndFHgetKey!\n");
        exit(EXIT_FAILURE);
    }
    return getAccVert(nodeFH->vert);
}

void ndFHinsertFilho(tNodeFH *pai, tNodeFH *filho){
    if(!pai || !filho){
        printf("dados invalidos em ndfhInsertFilho!\n");
        exit(EXIT_FAILURE);
    }
    if(!(pai->filho)){
        pai->filho = filho;
        return;
    }
    filho->right = pai->filho->right;
    filho->left = pai->filho;
    pai->filho->right->left = filho;
    pai->filho->right = filho;

    (pai->grau)++;
    filho->pai = pai;
}