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
template <typename T>
NodoAVL<T> *criaNodo(T *dado)
{
    NodoAVL<T> *newNodo = (NodoAVL<T> *)malloc(sizeof(NodoAVL<T>));
    newNodo->_filhoEsquerda = nullptr;
    newNodo->_filhoDireita = nullptr;
    newNodo->_dado = dado;
    newNodo->_altura = 0;
    return newNodo;
}
template <typename T>
int getHigh(NodoAVL<T> *raiz)
{
    if (raiz == nullptr)
    {
        return -1;
    }
    return raiz->_altura;
}
int maxEntre(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
template <typename T>
NodoAVL<T> *rotDireita(NodoAVL<T> *raiz)
{
    NodoAVL<T> *aux = raiz->_filhoEsquerda;
    raiz->_filhoEsquerda = aux->_filhoDireita;
    aux->_filhoDireita = raiz;
    raiz->_altura = maxEntre(getHigh(raiz->_filhoDireita), getHigh(raiz->_filhoEsquerda)) + 1;
    aux->_altura = maxEntre(getHigh(aux->_filhoEsquerda), raiz->_altura) + 1;
    return aux;
}
template <typename T>
NodoAVL<T> *rotEsquerda(NodoAVL<T> *raiz)
{
    NodoAVL<T> *aux = raiz->_filhoDireita;
    raiz->_filhoDireita = aux->_filhoEsquerda;
    aux->_filhoEsquerda = raiz;
    raiz->_altura = maxEntre(getHigh(raiz->_filhoDireita), getHigh(raiz->_filhoEsquerda)) + 1;
    aux->_altura = maxEntre(getHigh(aux->_filhoEsquerda), raiz->_altura) + 1;
    return aux;
}
template <typename T>
NodoAVL<T> *rotEsquerdaDireita(NodoAVL<T> *raiz)
{
    raiz->_filhoEsquerda = rotEsquerda(raiz->_filhoEsquerda);
    return rotDireita(raiz);
}
template <typename T>
NodoAVL<T> *rotDireitaEsquerda(NodoAVL<T> *raiz)
{
    raiz->_filhoDireita = rotDireita(raiz->_filhoDireita);
    return rotEsquerda(raiz);
}

template <typename T>
NodoAVL<T> *insere(NodoAVL<T> *raiz, T *dado)
{
    printf("sexo\n");
    if (raiz == nullptr)
    {
        printf("Raiz nula\n");
        return criaNodo(dado);
    }
    if (*dado < *raiz->_dado)
    {
        printf("b\n");
        raiz->_filhoEsquerda = insere(raiz->_filhoEsquerda, dado);
        if ((getHigh(raiz->_filhoEsquerda) - getHigh(raiz->_filhoDireita)) == 2)
        {
            if (*dado < *raiz->_filhoEsquerda->_dado)
            {
                raiz = rotDireita(raiz);
            }
            else
            {
                raiz = rotDireitaEsquerda(raiz);
            }
        }
    }
    else
    {
        printf("c\n");
        if (*dado > *raiz->_dado)
        {
            raiz->_filhoDireita = insere(raiz->_filhoDireita, dado);
            if ((getHigh(raiz->_filhoEsquerda) - getHigh(raiz->_filhoDireita)) == 2)
            {
                if (*dado > *raiz->_filhoDireita->_dado)
                {
                    raiz = rotEsquerda(raiz);
                }
                else
                {
                    raiz = rotDireitaEsquerda(raiz);
                }
            }
        }
    }

    raiz->_altura = maxEntre(getHigh(raiz->_filhoEsquerda), getHigh(raiz->_filhoDireita)) + 1;
    return raiz;
}
template <typename T>
NodoAVL<T> *adicionar(NodoAVL<T> *raiz, T *dado)
{
    printf("pinto\n");
    if (raiz->_dado == nullptr)
    {
        raiz->_filhoEsquerda = nullptr;
        raiz->_filhoDireita = nullptr;
        raiz->_dado = dado;
        raiz->_altura = 0;
    }
    else
    {
        raiz = insere(raiz, dado);
    }

    //raiz->_dado = dado;
    printf("raiz.dado: %d\nraiz.altura: %d\nraiz.filhoEsq: %p\nraiz.filhoDir: %p\n\n", *raiz->_dado, raiz->_altura, raiz->_filhoEsquerda, raiz->_filhoDireita);
    return raiz;
}

template <typename T>
void preOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        adicionaNoFim(lista, raiz->_dado);
        preOrdem(raiz->_filhoEsquerda, lista);
        preOrdem(raiz->_filhoDireita, lista);
    }
}
template <typename T>
void emOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        emOrdem(raiz->_filhoEsquerda, lista);
        adicionaNoFim(lista, raiz->_dado);
        emOrdem(raiz->_filhoDireita, lista);
    }
}

template <typename T>
void posOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
    if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
    {
        posOrdem(raiz->_filhoEsquerda, lista);
        posOrdem(raiz->_filhoDireita, lista);
        adicionaNoFim(lista, raiz->_dado);
    }
}

template <typename T>
NodoAVL<T> *getNodo(NodoAVL<T> *raiz, T dado)
{
    printf("getNodo\n");
    printf("raiz.dado: %d\nraiz.altura: %d\nraiz.filhoEsq: %p\nraiz.filhoDir: %p\n\n", *raiz->_dado, raiz->_altura, raiz->_filhoEsquerda, raiz->_filhoDireita);
    /*
    while (raiz != NULL && dado != *raiz->_dado)
    {
        printf("loop\n");
        if (dado < *raiz->_dado)
        {
            raiz = raiz->_filhoEsquerda;
        }
        else
        {
            raiz = raiz->_filhoDireita;
        }
    }*/
    printf("fim getNodo\n");
    return raiz;
}

template <typename T>
NodoAVL<T> *remover(NodoAVL<T> *raiz, T dado)
{
    //IMPLEMENTE AQUI
    return nullptr;
}
template <typename T>
void destruir(NodoAVL<T> *raiz)
{
    //IMPLEMENTE AQUI
}

#endif /* NODOAVL_H */
