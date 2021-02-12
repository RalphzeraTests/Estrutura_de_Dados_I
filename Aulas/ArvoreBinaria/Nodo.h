#ifndef NODO_H
#define NODO_H

#include "ListaEncadeada.h"
#include <stdlib.h>

template <typename T>
struct Nodo
{
    Nodo *_filhoEsquerda;
    Nodo *_filhoDireita;
    T *_dado;
};
//NAO MODIFIQUE ESTA FUNCAO
template <typename T>
Nodo<T> *getNodo(Nodo<T> *raiz, T dado)
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
template <typename T>
Nodo<T> *getFatherNodo(Nodo<T> *raiz, T dado)
{
    //printf("raizD: %d\n", *raiz->_dado);
    if (dado == *raiz->_dado)
        return nullptr;
    Nodo<T> *ant;
    while (raiz != NULL && dado != *raiz->_dado)
    {
        if (dado < *raiz->_dado)
        {
            ant = raiz;
            raiz = raiz->_filhoEsquerda;
        }
        else
        {
            ant = raiz;
            raiz = raiz->_filhoDireita;
        }
    }
    return ant;
}

template <typename T>
Nodo<T> *getMinDIr(Nodo<T> *raiz)
{

    while (raiz->_filhoEsquerda != NULL)
    {
        raiz = raiz->_filhoEsquerda;
    }
    return raiz;
}
template <typename T>
Nodo<T> *getMaxEsq(Nodo<T> *raiz)
{

    while (raiz->_filhoDireita != NULL)
    {

        raiz = raiz->_filhoDireita;
    }
    return raiz;
}
//adiciona dado na arvore binaria de busca
template <typename T>
void adiciona(Nodo<T> *raiz, T *dado)
{
    if (raiz->_dado == nullptr)
    {
        raiz->_dado = dado;
        raiz->_filhoDireita = nullptr;
        raiz->_filhoEsquerda = nullptr;
    }
    else
    {
        if (dado < raiz->_dado)
        {
            if (raiz->_filhoEsquerda == nullptr)
            {
                Nodo<T> *aux = (Nodo<T> *)malloc(sizeof(Nodo<T>));
                aux->_dado = dado;
                aux->_filhoEsquerda = nullptr;
                aux->_filhoDireita = nullptr;
                raiz->_filhoEsquerda = aux;
            }
            else
            {
                adiciona(raiz->_filhoEsquerda, dado);
            }
        }
        else
        {
            if (raiz->_filhoDireita == nullptr)
            {
                Nodo<T> *aux = (Nodo<T> *)malloc(sizeof(Nodo<T>));
                aux->_dado = dado;
                aux->_filhoEsquerda = nullptr;
                aux->_filhoDireita = nullptr;
                raiz->_filhoDireita = aux;
            }
            else
            {
                adiciona(raiz->_filhoDireita, dado);
            }
        }
    }
}

//cria uma lista com os nodos da arvore em preordem
template <typename T>
void preOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        adicionaNoFim(lista, raiz->_dado);
        preOrdem(raiz->_filhoEsquerda, lista);
        preOrdem(raiz->_filhoDireita, lista);
    }
}

//cria uma lista com os nodos da arvore em emOrdem
template <typename T>
void emOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        emOrdem(raiz->_filhoEsquerda, lista);
        adicionaNoFim(lista, raiz->_dado);
        emOrdem(raiz->_filhoDireita, lista);
    }
}

//cria uma lista com os nodos da arvore em posordem
template <typename T>
void posOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        posOrdem(raiz->_filhoEsquerda, lista);
        posOrdem(raiz->_filhoDireita, lista);
        adicionaNoFim(lista, raiz->_dado);
    }
}

//remove o *proximo* nodo que contem um ponteiro para dado
template <typename T>
T *remover(Nodo<T> *raiz, T dado)
{
    T *auxD;

    bool dir = true;
    Nodo<T> *remP = getFatherNodo(raiz, dado);
    Nodo<T> *rem;
    if (remP == nullptr || remP->_dado == nullptr)
    {

        if (dado == *raiz->_dado)
        {
            auxD = raiz->_dado;
            if (raiz->_filhoDireita != nullptr)
            {
                Nodo<T> *auxx = getMinDIr(raiz->_filhoDireita);
                Nodo<T> *auxP = getFatherNodo(raiz, *auxx->_dado);
                raiz->_dado = auxx->_dado;
                auxP->_filhoEsquerda = nullptr;
                free(auxx);
            }
            else
            {
                Nodo<T> *auxx = getMaxEsq(raiz->_filhoEsquerda);
                Nodo<T> *auxP = getFatherNodo(raiz, *auxx->_dado);
                raiz->_dado = auxx->_dado;
                auxP->_filhoDireita = nullptr;
                free(auxx);
            }
            return auxD;
        }
        return nullptr;
    }
    else
    {
        if (dado > *remP->_dado)
        {
            if (remP->_filhoDireita == nullptr)
            {
                return nullptr;
            }
            rem = remP->_filhoDireita;
        }
        else
        {
            if (remP->_filhoEsquerda == nullptr)
            {
                return nullptr;
            }
            rem = remP->_filhoEsquerda;
            dir = false;
        }
    }
    auxD = rem->_dado;
    if (rem->_filhoEsquerda == nullptr && rem->_filhoDireita == nullptr)
    {
        free(rem);
        if (dir)
        {
            remP->_filhoDireita = nullptr;
        }
        else
        {
            remP->_filhoEsquerda = nullptr;
        }
    }
    else
    {
        getMinDIr(rem->_filhoDireita)->_filhoEsquerda = rem->_filhoEsquerda;
        remP->_filhoEsquerda = rem->_filhoDireita;
        free(rem);
    }

    return auxD;
}

//desaloca todos os nodos da arvore
template <typename T>
void destruir(Nodo<T> *raiz)
{
    if (raiz->_filhoEsquerda != nullptr)
    {
        destruir(raiz->_filhoEsquerda);
    }
    if (raiz->_filhoDireita != nullptr)
    {
        destruir(raiz->_filhoDireita);
    }
    free(raiz);
}

#endif /* NODO_H */