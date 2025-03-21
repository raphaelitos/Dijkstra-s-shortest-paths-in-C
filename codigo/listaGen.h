/**
 * @file    listaGen.h
 * @brief   definicao de funcoes referentes a uma lista encadeada generica
 * @author  Conrado Antoniazi dos Santos (conrado.santos@edu.ufes.br)
 * @author  Raphael Correia Dornelas (raphael.dornelas@edu.ufes.br)
 * @author  Victor Augusto Fernandes Rangel (victor.a.rangel@edu.ufes.br)
*/

#ifndef LISTAGEN_H_
#define LISTAGEN_H_

typedef struct listagen tListaGen;

/// @brief inicializa uma lista generica
/// @return uma variavel do tipo tListaGen
/// devidamente alocada
tListaGen *criaListaGen(void *info);

/// @brief libera a memoria utilizada por l
/// @param l uma lista generica valida
/// @param liberaCelula callback para funcao que
/// libera uma celula de l
void liberaListaGen(tListaGen *l, void(*liberaCelula)(void *dado));

/// @brief imsere dado como primeira celula de l
/// @param l uma lista generica valida
/// @param dado um dado valido
/// @return a nova lista generica, com dado 
/// na primeira celula
tListaGen *insereListaGen(tListaGen *l, tListaGen *dado);

/// @brief retira uma celula de l com base
/// na comparacao feita por cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return a lista sem o elemento procurado
tListaGen *retiraListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado, void(*liberaCelula)(void *dado));

/// @brief busca uma celula de l com base
/// na comparacao feita por cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return o dado procurado (ou null caso
/// ele nao exista)
tListaGen *buscaListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

/// @brief percorre l executando cb
/// @param l uma lista generica valida
/// @param cb uma funcao de comparacao
/// @param dado um dado valido
/// @return 0, caso cb retorne 0 para alguma
/// celula; 1 caso contrario
int percorreListaGen(tListaGen *l, int(*cb)(void*, void*), void *dado);

/// @brief itera numa lista
/// @param iterador a lista que sera percorrida
/// @return null caso o elemento seja invalido, 
/// o valor de info em iterador caso contrario 
void *iteraListaGen(tListaGen **iterador);

tListaGen *getProxListaGen(tListaGen *l);

void *getInfoListaGen(tListaGen *l);

#endif