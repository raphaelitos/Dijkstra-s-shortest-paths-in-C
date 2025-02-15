#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeFH.h"

struct heapNode
{
    tVertice *vert;
    
    tNodeFH *left, *right;// uma lista circular
    tNodeFH *pai;
    tNodeFH *filho; //pode ter mais de um, mas so aponta p um

    bool marcado; //auxiliar para algumas funcoes
    int grau; //n de filhos
};
