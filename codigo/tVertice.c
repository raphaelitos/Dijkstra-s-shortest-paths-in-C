#include "tVertice.h"
#include "tLista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vertice
{
    int id;
    tLista * adj; 
};



tVertice * criaVertice(int id){
    tVertice * v = calloc(1,sizeof(tVertice));
}