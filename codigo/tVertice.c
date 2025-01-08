#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tVertice.h"
#include "tLista.h"

#define TAM_MAX_NOME 101

struct vertice{
    char nome[TAM_MAX_NOME];
    tListaGen *adjacencias; // Lista genérica contendo arestas
};

tVertice *criaVertice(const char *nome){
    tVertice *no = (tVertice *)calloc(1, sizeof(tVertice));
    if (!no) exit(EXIT_FAILURE);
    strcpy(no->nome, nome);
    no->adjacencias = NULL;  
    return no;
}

tListaGen *getAdjVert(tVertice *v){
    if(!v) return NULL;
    return v->adjacencias;
}

char *getNomeVert(tVertice *v){
    if(!v) return NULL;
    return v->nome;
}

void addVizinhoVert(tVertice *v, void *dado){
    if(!v) return;
    tListaGen *l = criaListaGen(dado);
    v->adjacencias = insereListaGen(v->adjacencias, l);
}