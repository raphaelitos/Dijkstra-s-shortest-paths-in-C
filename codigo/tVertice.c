/**
 * @file    tVertice.c
 * @brief   Implementa funcoes referentes a um vertice
 * de um grafo dirigido ponderado
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tAresta.h"
#include "tVertice.h"
#include <limits.h>    // para INT_MAX

#define TAM_MAX_NOME 101

/// @brief Representa o vertice de um grafo
/// dirigido ponderado
struct vertice{
    char nome[TAM_MAX_NOME]; // Rotulo
    tListaGen *adjacencias; // Lista genérica contendo arestas
    tVertice* pai; // predecessor no caminho minimo
    double acc; // distancia ate o vertice fonte
    int posHeap; // posicao na heap binaria
    tNodeFH *nodeFH; // representante na heap fibonacci
};

tVertice *criaVertice(const char *nome){
    tVertice *no = (tVertice *)calloc(1, sizeof(tVertice));
    if (!no) exit(EXIT_FAILURE);
    strcpy(no->nome, nome);
    no->adjacencias = NULL;
    no->acc = INT_MAX; //valor infinito, padrão para vértices não visitados
    no->pai = NULL;
    no->nodeFH = NULL;
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

void setAccVert(tVertice* v, double acc) {
    if(v == NULL) return;
    v->acc = acc;
}

double getAccVert(tVertice* v) {
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

tNodeFH *getNodeFHVert(tVertice *v){
    if(!v){
        printf("dados invalidos em getNodeFHVert!\n");
        exit(EXIT_FAILURE);
    }
    return v->nodeFH;
}

void setNodeFHVert(tVertice *v, tNodeFH *nodeFH){
    if(!v){
        printf("dados invalidos em setNodeFHVert!\n");
        exit(EXIT_FAILURE);
    }
    v->nodeFH = nodeFH;
}

void imprimeVert(tVertice* v) {
    if(!v){
        printf("vertice invalido em imprime!\n");
        exit(EXIT_FAILURE);
    }
    printf("%s [%s] %.2f", v->nome, getNomeVert(v->pai), v->acc);
}