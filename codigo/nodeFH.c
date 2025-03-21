/**
 * @file    nodeFH.c
 * @brief   Implementa funcoes referentes ao no de uma heap fibonacci
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFH.h"

/// @brief representa o no' de uma
/// heap fibonacci
struct fibHeapNode
{
    // vertice representado
    tVertice *vert; 
    
    // lista circular de irmaos
    tNodeFH *left, *right;
    
    // predecessor na fib heap
    tNodeFH *pai;
    
    //pode ter mais de um, mas so aponta p um
    tNodeFH *filho; 

    //auxiliar para corte em cascata
    bool marcado; 
    
    //n de filhos
    int grau; 
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
    
    //criando a via de mao dupla
    setNodeFHVert(v, newNode);

    newNode->vert = v;
    newNode->pai = newNode->filho = NULL;
    newNode->left = newNode->right = newNode;

    return newNode;
}

void ndFHdestroy(tNodeFH* nodeFH){
    if(!nodeFH) return;

    if(nodeFH->right != nodeFH){
        tNodeFH *irmao = nodeFH->right;
        ndFHremove(nodeFH);
        
        ndFHdestroy(irmao);
        
        ndFHdestroy(nodeFH);
    }

    else if(nodeFH->filho){
        ndFHdestroy(nodeFH->filho);
    }

    else{//sem filho e sem irmao
        tNodeFH *pai = nodeFH->pai;
        
        free(nodeFH);
        
        ndFHdestroy(pai);//subindo na arvore
    }
    
}

void ndFHinsert(tNodeFH *lista, tNodeFH *novo){
    if(!lista || !novo){
        printf("Dados invalidos em ndFHinsert!\n");
        exit(EXIT_FAILURE);
    }
    
    if((novo->right) != novo){
        printf("insercao problematica! No ja pertence a uma lista!\n");
        printf("no %s seria inserido em %s\n", 
        getNomeVert(novo->vert), getNomeVert(lista->vert));
        return;
    }

    novo->right = lista;
    novo->left = lista->left;
    lista->left->right = novo;
    lista->left = novo;
}

void ndFHremove(tNodeFH *node){
    if(!node){
        printf("dados invalidos em ndfhInsertFilho!\n");
        exit(EXIT_FAILURE);
    }
    
    if(node->right == node) return;

    node->left->right = node->right;
    node->right->left = node->left;    

    node->right = node->left = node;
}

void ndFHinsertFilho(tNodeFH *pai, tNodeFH *filho){
    if(!pai || !filho){
        printf("dados invalidos em ndfhInsertFilho!\n");
        exit(EXIT_FAILURE);
    }
    if(!(pai->filho)){
        pai->filho = filho;
        filho->right = filho;
        filho->left = filho;
    }
    else{
        ndFHinsert(pai->filho, filho);
    }
    (pai->grau)++;
    filho->pai = pai;
}

tNodeFH* ndFHremoveFilho(tNodeFH *lista, tNodeFH *filho){
    if(!lista || !filho || (filho->pai != lista)){
        printf("dados invalidos em ndFHremove!\n");
        exit(EXIT_FAILURE);
    }
    if(lista->filho == filho) {
        if (filho->right == filho) { //Filho unico
            lista->filho = NULL;
        }
        else {
            lista->filho = filho->right;//novo filho
        }
    }
    
    filho->left->right = filho->right;
    filho->right->left = filho->left;
    filho->right = filho->left = filho;
   
    filho->pai = NULL;
    filho->marcado = false;

    (lista->grau)--;

    return filho;
}

double ndFHgetKey(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("Dados invalidos em ndFHgetKey!\n");
        exit(EXIT_FAILURE);
    }
    return getAccVert(nodeFH->vert);
}

void ndFHsetKey(tNodeFH *nodeFH, double newKey){
    if(!nodeFH){
        printf("dado invalido em ndFHsetKey!\n");
        exit(EXIT_FAILURE);
    }
    setAccVert(nodeFH->vert, newKey);
}

tVertice* ndFHgetVert(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("dado invalido em ndFHgetVert!\n");
        exit(EXIT_FAILURE);
    }
    return nodeFH->vert;
}

void ndFHsetVert(tNodeFH *nodeFH, tVertice *vert){
    if(!nodeFH){
        printf("dado invalido em ndFHsetVert!\n");
        exit(EXIT_FAILURE);
    }
    nodeFH->vert = vert;
}

tNodeFH* ndFHgetLeft(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("dado invalido em ndFHgetLeft!\n");
        exit(EXIT_FAILURE);
    }
    return nodeFH->left;
}

void ndFHsetLeft(tNodeFH *nodeFH, tNodeFH *left){
    if(!nodeFH){
        printf("dado invalido em ndFHsetLeft!\n");
        exit(EXIT_FAILURE);
    }
    nodeFH->left = left;
}

tNodeFH* ndFHgetRight(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("dado invalido em ndFHgetRight!\n");
        exit(EXIT_FAILURE);
    }
    return nodeFH->right;
}

void ndFHsetRight(tNodeFH *nodeFH, tNodeFH *right){
    if(!nodeFH){
        printf("dado invalido em ndFHsetRight!\n");
        exit(EXIT_FAILURE);
    }
    nodeFH->right = right;
}

tNodeFH* ndFHgetPai(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("dado invalido em ndFHgetPai!\n");
        exit(EXIT_FAILURE);
    }
    return nodeFH->pai;
}

void ndFHsetPai(tNodeFH *nodeFH, tNodeFH *pai){
    if(!nodeFH){
        printf("dado invalido em ndFHsetPai!\n");
        exit(EXIT_FAILURE);
    }
    nodeFH->pai = pai;
}

tNodeFH* ndFHgetFilho(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("dado invalido em ndFHgetFilho!\n");
        exit(EXIT_FAILURE);
    }
    return nodeFH->filho;
}

int ndFHgetGrau(tNodeFH *node){
    if(!node){
        printf("dado invalido em ndFHgetGrau!\n");
        exit(EXIT_FAILURE);
    }
    return node->grau;
}

bool ndFHgetMarcado(tNodeFH *node){
    if(!node){
        printf("dado invalido em ndFHgetMarcado!\n");
        exit(EXIT_FAILURE);
    }
    return node->marcado;
}

void ndFHsetMarcado(tNodeFH *node, bool valor){
    if(!node){
        printf("dado invalido em ndFHsetMarcado!\n");
        exit(EXIT_FAILURE);
    }
    node->marcado = valor;
}