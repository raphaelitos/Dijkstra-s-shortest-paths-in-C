#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFH.h"
#include "tIterator.h"

struct fibHeapNode
{
    tVertice *vert;
    
    tNodeFH *left, *right;//lista circular
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

void ndFHdestroy(tNodeFH* nodeFH){
    if(!nodeFH) return;
    
    //chegando na folha (indo pra ponta da arvore)
    ndFHdestroy(nodeFH->filho);

    tNodeFH *pop, *aux = nodeFH->right;

    do{//indo em largura (olhando os irmaos)
        pop = aux;
        aux = aux->right;
        free(pop);
    }while(aux != nodeFH);
}

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
//Na verdade acho que so existe removeFliho
void ndHFremove(tNodeFH *lista, tNodeFH *alvo){
    if(!lista || !alvo){
        printf("dados invalidos em ndFHremove!\n");
        exit(EXIT_FAILURE);
    }
    if(lista->filho == lista->filho->right){
        lista->filho = NULL;
    }//pai c um filho so'
    else if(lista->filho == alvo){
        lista->filho = alvo->right;
        alvo->right->pai = lista;
    }
    alvo->left->right = alvo->right;
    alvo->right->left = alvo->left;
}

int ndFHgetKey(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("Dados invalidos em ndFHgetKey!\n");
        exit(EXIT_FAILURE);
    }
    return getAccVert(nodeFH->vert);
}

