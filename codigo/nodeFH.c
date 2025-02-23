#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFH.h"

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
    
    //criando a via de mao dupla
    setNodeFHVert(v, newNode);

    newNode->vert = v;
    newNode->pai = newNode->filho = NULL;
    newNode->left = newNode->right = newNode;

    return newNode;
}


/**
 * Isso aqui parece estar certo
 * Nao sei se e' possivel otimizar as 
 * chamadas de recursao
 * mas parece estar certo :)
 */
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
//insere no final ('a esquerda de lista)
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
    if(!lista || !filho){
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

float ndFHgetKey(tNodeFH *nodeFH){
    if(!nodeFH){
        printf("Dados invalidos em ndFHgetKey!\n");
        exit(EXIT_FAILURE);
    }
    return getAccVert(nodeFH->vert);
}

void ndFHsetKey(tNodeFH *nodeFH, float newKey){
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

void ndFHsetGrau(tNodeFH *node, int grauNovo){
    if(!node){
        printf("dado invalido em ndFHsetGrau!\n");
        exit(EXIT_FAILURE);
    }
    node->grau = grauNovo;
}

void ndFHincGrau(tNodeFH *node){
    if(!node){
        printf("dado invalido em ndFHincGrau!\n");
        exit(EXIT_FAILURE);
    }
    (node->grau)++;
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