#ifndef TVERT
#define TVERT


typedef struct vertice tVertice;


/// @brief essa funcao precisa criar a "aresta" de v ao vizinho
/// @param v o vertice cuja lista esta sendo feita
/// @param id_vizinho o outro vertice que se relaciona com v ( a outra ponta da aresta)
/// @param peso  peso da aresta
void adicionaLista(tVertice *v, int id_vizinho, int peso);
#endif