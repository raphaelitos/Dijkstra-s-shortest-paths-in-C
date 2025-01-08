#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tVertice.h"
#include "tAresta.h"
#include "tGrafo.h"
#include "listaGen.h"

struct grafo
{
    tVertice **vertices;
    int origem;
    int numVertices;
};

#define MAX_TAM_LINHA 1024

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
