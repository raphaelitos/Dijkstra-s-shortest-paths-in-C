/**
 * @file    main.c
 * @brief   Arquivo principal, que constroi um grafo a partir de um
 * arquivo de entrada fornecido em argv[1] e imprime o resultado do algoritmo de 
 * Dijkstra num outro de saida, fornecido em argv[2].
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#include <stdio.h>
#include "tGrafo.h"

int main(int argc, char *argv[])
{

    if(argc <= 2){
        printf("Forneca um caminho valido para o arquivo de entrada e outro para o de saida!\n");
        return 0;
    }
    
    tGrafo *grafo = GrafoInit(argv[1]);
    
    tVertice *src = getOrigemGrafo(grafo);
    
    if(!src){
        printf("src nulo :(");
        DesalocaGrafo(grafo);
        return 0;
    }

    Dijkstra(grafo, src);

    ImprimeCaminhosMenorCusto(grafo, src, argv[2]);

    DesalocaGrafo(grafo);
    return 0;
}
