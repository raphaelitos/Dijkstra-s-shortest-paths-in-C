#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "tGrafo.h"
#include "PQ.h"
#include "tVertice.h"
#include "tAresta.h"
#include "listaGen.h"

#ifndef INF
#define INF INT_MAX
#endif

struct grafo
{
    tVertice **vertices;
    tVertice* origem;
    int numVertices;
};

#define MAX_TAM_LINHA 1024
/*

tGrafo *LeGrafo(char *path)
{
    // manipulacao de IO
    char final_path[200];
    sprintf(final_path, "casos_teste_v2/%s", path);

    FILE *file = fopen(final_path, "r");
    if (!file)
    {
        perror("Nao foi possivel localizar arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    tGrafo *grafo = calloc(1, sizeof(tGrafo));

    // ler primeira linha
    fscanf(file, "node_%d\n", &grafo->origem);

    // ler os vertices
    char line[1024];
    int indice_vertice = 0;
    while (fgets(line, sizeof(line), file))
    {
        // pula a primeira linha
        if (!indice_vertice)
        {
            indice_vertice++;
            continue;
        }

        tVertice *v = criaVertice(indice_vertice);

        // pega o "node_n"
        char *token = strtok(line, ",");

        // pega os vizinhos

        // a partir daqui, token contem os pesos
        token = strtok(NULL, ",");

        int qual_vertice = 0;
        while (token)
        {
            // pula o indice caso seja o mesmo vertice
            if (qual_vertice == indice_vertice)
            {
                qual_vertice++;
            }
            // adiciona "qual vertice" no vertice v, com peso token
            adicionaLista(v, qual_vertice, token);
            token = strtok(NULL, ",");
            qual_vertice++;
        }
        grafo->numVertices = qual_vertice;
    }

    fclose(file);
}

tListaGen *constroiGrafo(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    tListaGen *grafo = NULL; // Lista principal do grafo
    char linha[MAX_TAM_LINHA];
    int indiceVertice = 0; // Índice do vértice atual

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), file)) {
        // Criar o vértice com o índice atual
        char *nome = strtok(linha, ","); // Extrai o nome (e.g., "node_0")
        tVertice *vertice = criaVertice(nome);

        // Criar a lista para o vértice e adicioná-la ao grafo
        tListaGen *l = criaListaGen(vertice);
        grafo = insereListaGen(grafo, l);

        // Processar os pesos das arestas
        char *pesoStr = strtok(NULL, ",");
        int qualVertice = 0; // Índice do destino

        while (pesoStr) {
            int peso = atoi(pesoStr);

            // Ignorar o índice atual (sem aresta para o mesmo vértice)
            if (qualVertice != indiceVertice && peso > 0) {
                // Criar a aresta com o índice do nó de destino e o peso
                tAresta *aresta = criaAresta(qualVertice, peso);
                addVizinhoVert(vertice, aresta); // Adiciona a aresta ao vértice
            }

            // Próximo peso
            pesoStr = strtok(NULL, ",");
            qualVertice++;
        }

        indiceVertice++; // Incrementar o índice do vértice atual
    }

    fclose(file);
    return grafo;
}

*/
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

void Dijkstra(tGrafo *g, tVertice *source) {
    if(!g || !source){
        printf("Dados invalidos para Dijkstra!");
        return;
    }
    
    int numVertices = GetSizeGrafo(g);
    PQ *pq = PQ_create(numVertices);
    
    // A fonte tem distancia 0
    setAccVert(source, 0);

    // 3) Insere todos os vértices na fila
    InsereVerticesPQ(g, pq);

    while (!PQ_is_empty(pq)) {
        // vertice com menor dist (acc)
        tVertice *u = PQ_delmin(pq);

        // Percorre lista de adjacencias de u
        tListaGen *adj = getAdjVert(u);
        for (tListaGen *aux = adj; aux != NULL; aux = getProxListaGen(aux)) {
            tAresta *aresta = (tAresta*) getInfoListaGen(aux);
            tVertice *v = getDestinoAresta(aresta); 
            
            float peso = getPesoAresta(aresta);
            float alt = getAccVert(u) + peso; 
            
            if (alt < getAccVert(v)) {
                //Atualiza o pai e a PQ
                setPaiVert(v, u);
                PQ_decrementaChave(pq, v, alt);
            }

        }
    }

    PQ_destroy(pq);

    qsort(g->vertices, g->numVertices, sizeof(tVertice*), cmpVertice);
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

void ImprimeCaminhoRec(FILE *arquivo, tVertice *v) {
    if (v == NULL) return;

    if (getPaiVert(v) != NULL) {
        ImprimeCaminhoRec(arquivo, getPaiVert(v));
        fprintf(arquivo, " <- ");
    }
    fprintf(arquivo, "%s", getNomeVert(v));
}

void ImprimeCaminhosMenorCusto(tGrafo *grafo, tVertice *source, char *path) {
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
