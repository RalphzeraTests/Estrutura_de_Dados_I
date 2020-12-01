#ifndef NODOAVL_H
#define NODOAVL_H

#include "ListaEncadeada.h"
#include <stdlib.h>

template <typename T>
struct NodoAVL
{
    NodoAVL *_filhoEsquerda;
    NodoAVL *_filhoDireita;
    T *_dado;
    int _altura;
};

/**
 * @brief Adiciona um dado à árvore AVL
 * @param raiz ponteiro para raiz da árvore
 * @param dado ponteiro para dado a ser inserido
 * @return a raiz da árvore passada como parâmetro ou uma nova raiz caso houve rotação na raiz
 */
template <typename T>
NodoAVL<T> *adicionar(NodoAVL<T> *raiz, T *dado)
{
    //IMPLEMENTE AQUI
    return nullptr; //remova esta linha
}

/**
 * @brief Percorre árvore AVL em pré-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pré-ordem
 */
template <typename T>
void preOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    //IMPLEMENTE AQUI
}

/**
 * @brief Percorre árvore AVL em ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em ordem
 */
template <typename T>
void emOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    //IMPLEMENTE AQUI
}

/**
 * @brief Percorre árvore AVL em pós-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pós-ordem
 */
template <typename T>
void posOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    //IMPLEMENTE AQUI
}

//NAO MODIFIQUE A FUNCAO ABAIXO
template <typename T>
NodoAVL<T> *getNodo(NodoAVL<T> *raiz, T dado)
{
    while (raiz != NULL && dado != *raiz->_dado)
    {
        if (dado < *raiz->_dado)
        {
            raiz = raiz->_filhoEsquerda;
        }
        else
        {
            raiz = raiz->_filhoDireita;
        }
    }
    return raiz;
}

/**
 * @brief Remove um dado à árvore AVL
 * @param raiz ponteiro para raiz da árvore
 * @param dado dado a ser inserido
 * @return a raiz da árvore passada como parâmetro ou uma nova raiz caso houve rotação na raiz
 */
template <typename T>
NodoAVL<T> *remover(NodoAVL<T> *raiz, T dado)
{
    //IMPLEMENTE AQUI
    return nullptr;
}

/**
 * @brief Desaloca todos os nodos de uma árvore. Os dados não são desalocados.
 * @param raiz ponteiro para raiz da árvore
 */
template <typename T>
void destruir(NodoAVL<T> *raiz)
{
    //IMPLEMENTE AQUI
}

#endif /* NODOAVL_H */
