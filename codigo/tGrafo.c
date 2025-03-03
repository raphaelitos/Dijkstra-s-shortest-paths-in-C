#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "tGrafo.h"
#include "tAresta.h"
#include "fibHeap.h"
#include "PQ.h"


struct grafo
{
    tVertice **vertices;
    tVertice* origem;
    int numVertices;
};

#define MAX_TAM_LINHA 1024

tGrafo* GrafoInit(char* path) {
    FILE *file = fopen(path, "r");
    int origem;

    if (!file) {
        perror("Nao foi possivel localizar arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }

    tGrafo *grafo = malloc(sizeof(tGrafo));
    if(!grafo) {
        perror("Nao foi possivel alocar dinamicamente o grafo.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "node_%d\n", &origem);

    long checkpoint = ftell(file); // Salva a posicao atual no arquivo
    if (checkpoint == -1L) {
        perror("Erro ao obter a posição inicial");
        fclose(file);
        return NULL;
    }

    int numNodes = 0;
    char parada;
    while(fscanf(file, "%*[^,\n]") != EOF) { //conta o numero de vertices na primeira linha
        numNodes++;
        fscanf(file, "%c", &parada);
        if(parada == '\n') break;
    }

    grafo->numVertices = numNodes;
    grafo->vertices = malloc(numNodes * sizeof(tVertice*)); //alocando vetor principal de vertices
    for(int i = 0; i < numNodes; i++) {
        char nome[100];
        sprintf(nome, "node_%d", i);
        grafo->vertices[i] = criaVertice(nome);
    }

    if (fseek(file, checkpoint, SEEK_SET) != 0) { //volta ao checkpoint no arquivo
        perror("Erro ao voltar para o checkpoint");
        fclose(file);
        return NULL;
    }

    for(int i = 0; i < numNodes; i++) {
        fscanf(file, "%*[^,\n],");

        for(int j = 0; j < numNodes; j++) {
            if(j == i) continue; //pula para nao atribuir peso a uma aresta para o proprio vertice analisado
            float peso = 0;

            if(fscanf(file, "%f", &peso) == 1 && peso > 0) {
                addVizinhoVert(grafo->vertices[i], criaAresta(grafo->vertices[j], peso));
                fscanf(file, "%*c");
            }
            else {
                fscanf(file, "%*[^,\n]"); //necessario para evitar conflito com as palavras "bomba"
                fscanf(file, "%*c");
            }
        }
    }

    //Set da origem
    grafo->origem = grafo->vertices[origem];

    fclose(file);
    return grafo;
}

void DesalocaGrafo(tGrafo* grafo) {
    if(grafo == NULL) return;
    if(grafo->vertices != NULL) {
        for(int i = 0; i < grafo->numVertices; i++) {
            apagaVertice(grafo->vertices[i]);
        }
        free(grafo->vertices);
    }
    free(grafo);
}

void ImprimeGrafo(tGrafo* grafo) {
    printf("%s\n", getNomeVert(grafo->origem));

    for(int i = 0; i < grafo->numVertices; i++) {
        printf("%s, ", getNomeVert(grafo->vertices[i]));
        percorreListaGen(getAdjVert(grafo->vertices[i]), ImprimeAresta, NULL);
        printf("\n");
    }
}

int GetSizeGrafo(tGrafo* grafo) {
    return grafo->numVertices;
}

tVertice *getOrigemGrafo(tGrafo *g){
    if(!g) return NULL;
    return g->origem;
}

void InsereVerticesPQ(tGrafo* grafo, PQ* pq) {
    for(int i = 0; i < grafo->numVertices; i++)
        PQ_insert(pq, grafo->vertices[i]);
}

// Função de comparação para o qsort
static int cmpVertice(const void *v1, const void *v2) {
    tVertice *vert1 = *(tVertice **)v1;
    tVertice *vert2 = *(tVertice **)v2;
    float accV1 = getAccVert(vert1);
    float accV2 = getAccVert(vert2);
    
    if (accV1 < accV2)
        return -1;
    else if (accV1 > accV2)
        return 1;
    else
        return strcmp(getNomeVert(vert1), getNomeVert(vert2));
}

void ImprimeCaminho(FILE* arquivo, tVertice* v, tVertice* src) {
    if(v == NULL) return;
    else if(v == src) {
        fprintf(arquivo, "%s", getNomeVert(v));
        fprintf(arquivo, " <- ");
    }

    tVertice* aux = v;
    while (aux != src) {
        fprintf(arquivo, "%s", getNomeVert(aux));
        fprintf(arquivo, " <- ");
        aux = getPaiVert(aux);
    }
    fprintf(arquivo, "%s", getNomeVert(src));
}

void ImprimeCaminhosMenorCusto(tGrafo *grafo, tVertice *source, char *path) {
    if(!grafo || !source){
        printf("dados invalidos em imprimeCaminhos\n");
        exit(EXIT_FAILURE);
    }

    qsort(grafo->vertices, grafo->numVertices, sizeof(tVertice*), cmpVertice);

    FILE *arquivo = fopen(path, "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    int numVertices = GetSizeGrafo(grafo);

    for (int i = 0; i < numVertices; i++) {
        tVertice *v = grafo->vertices[i];
        float dist = getAccVert(v);  // dist

        // Confere se o vertice e' alcancavel
        if (dist == INT_MAX) {
            continue; 
        }

        fprintf(arquivo, "SHORTEST PATH TO %s: ", getNomeVert(v));

        ImprimeCaminho(arquivo, v, getOrigemGrafo(grafo));

        fprintf(arquivo, " (Distance: %.2f)\n", dist);
    }

    fclose(arquivo);
}

/**
 * teste teste
 * @param grafo um grafo lol
 */
void fhInsereVertices(tGrafo* grafo, tFH* fh) {
    for(int i = 0; i < grafo->numVertices; i++){
        fhInsert(fh, grafo->vertices[i]);
    }
}