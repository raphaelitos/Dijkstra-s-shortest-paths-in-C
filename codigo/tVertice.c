#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tAresta.h"
#include "tVertice.h"
#include <limits.h>    // para INT_MAX

#define TAM_MAX_NOME 101

struct vertice{
    char nome[TAM_MAX_NOME];
    tListaGen *adjacencias; // Lista genérica contendo arestas
    tVertice* pai;
    float acc;
    int posHeap;
};

tVertice *criaVertice(const char *nome){
    tVertice *no = (tVertice *)calloc(1, sizeof(tVertice));
    if (!no) exit(EXIT_FAILURE);
    strcpy(no->nome, nome);
    no->adjacencias = NULL;
    no->acc = INT_MAX; //valor infinito, padrão para vértices não visitados
    no->pai = NULL;
    return no;
}

void apagaVertice(tVertice* v) {
    if(v != NULL) {
        liberaListaGen(v->adjacencias, apagaAresta);
        free(v);
    }
}

tListaGen *getAdjVert(tVertice *v){
    if(!v) return NULL;
    return v->adjacencias;
}

char *getNomeVert(tVertice *v){
    if(!v) return "";
    return v->nome;
}

void addVizinhoVert(tVertice *v, void *dado){
    if(!v) return;
    tListaGen *l = criaListaGen(dado);
    v->adjacencias = insereListaGen(v->adjacencias, l);
}

void setPaiVert(tVertice* v, tVertice* pai) {
    if(v == NULL) {
        printf("Tentativa invalida: definir pai de vértice nulo\n");
        return;
    }
    v->pai = pai;
}

tVertice* getPaiVert(tVertice* v) {
    if(v == NULL) return NULL;
    return v->pai;
}

void setAccVert(tVertice* v, int acc) {
    if(v == NULL) return;
    v->acc = acc;
}

float getAccVert(tVertice* v) {
    if(v == NULL) return -1;
    return v->acc;
}

void setPosHeapVert(tVertice* v, int posHeap) {
    if(v == NULL) return;
    v->posHeap = posHeap;
}

int getPosHeapVert(tVertice* v) {
    if(v == NULL) return -1;
    return v->posHeap;
}

void imprimeVert(tVertice* v) {
    printf("%s [%s] %.2f\n", v->nome, getNomeVert(v->pai), v->acc);
}