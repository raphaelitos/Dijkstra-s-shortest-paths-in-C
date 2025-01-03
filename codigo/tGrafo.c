#include "tGrafo.h"

struct grafo
{
    tVertice **vertices;
    int origem;
    int numVertices;
};

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