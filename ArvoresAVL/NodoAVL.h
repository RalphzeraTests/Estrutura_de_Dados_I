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
void printNodo(NodoAVL<T> *nodo)
{
    if (nodo)
    {
        printf("----------\nend: %p\nnodo.dado: %d\nnodo.altura: %d\nnodo.esq: %p\nnodo.dir: %p\n----------\n", nodo, *nodo->_dado, nodo->_altura, nodo->_filhoEsquerda, nodo->_filhoDireita);
        return;
    }
    printf("NODO NULO\n");
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
    //printf("        rotDireita\n");
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
    //printf("        rotEsquerda\n");
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
NodoAVL<T> *balancearNodo(NodoAVL<T> *raiz, T dadoF, int fb)
{

    if (fb == 2 || fb == -2)
    {
        if (dadoF < *raiz->_dado)
        {
            if (dadoF < *raiz->_filhoEsquerda->_dado)
            {
                raiz = rotDireita(raiz);
            }
            else
            {
                raiz = rotEsquerdaDireita(raiz);
            }
        }
        else
        {
            if (dadoF > *raiz->_filhoDireita->_dado)
            {
                raiz = rotEsquerda(raiz);
            }
            else
            {
                raiz = rotDireitaEsquerda(raiz);
            }
        }
    }
    return raiz;
}
template <typename T>
int getFB(NodoAVL<T> *raiz)
{
    return (getHigh(raiz->_filhoEsquerda) - getHigh(raiz->_filhoDireita));
}
template <typename T>
NodoAVL<T> *insere(NodoAVL<T> *raiz, T *dado)
{
    //printf("    Entrando no insere Insere\n");
    if (raiz == nullptr)
    {
        //printf("    Raiz nula\n");
        //printf("    Fim Insere\n");
        return criaNodo(dado);
    }
    if (*dado < *raiz->_dado)
    {
        //printf("    dado<raiz.dado\n");
        raiz->_filhoEsquerda = insere(raiz->_filhoEsquerda, dado);
        int fb = getFB(raiz);
        //printf("fb = %d\n", fb);
        raiz = balancearNodo(raiz, *dado, fb);
    }
    else
    {

        if (*dado > *raiz->_dado)
        {
            //printf("    dado>raiz.dado\n");
            raiz->_filhoDireita = insere(raiz->_filhoDireita, dado);
            int fb = getFB(raiz);
            //printf("fb = %d\n", fb);
            raiz = balancearNodo(raiz, *dado, fb);
        }
    }
    raiz->_altura = maxEntre(getHigh(raiz->_filhoEsquerda), getHigh(raiz->_filhoDireita)) + 1;
    //printf("    Fim Insere\n");
    return raiz;
}
template <typename T>
NodoAVL<T> *adicionar(NodoAVL<T> *raiz, T *dado)
{
    //printf("Entando no adicionar Adicionar (dado: %d)\n", *dado);
    if (raiz->_dado == nullptr)
    {
        raiz->_filhoEsquerda = nullptr;
        raiz->_filhoDireita = nullptr;
        raiz->_dado = dado;
        raiz->_altura = 0;
    }
    else
    {
        //printf("Dados da raiz(antes da insersão):\nraiz.dado: %d\nraiz.altura: %d\nraiz.filhoEsq: %p\nraiz.filhoDir: %p\n\n", *raiz->_dado, raiz->_altura, raiz->_filhoEsquerda, raiz->_filhoDireita);
        raiz = insere(raiz, dado);
    }
    //printf("---------------\nDados da raiz(apos a insersão):\nraiz.dado: %d\nraiz.altura: %d\nraiz.filhoEsq: %p\nraiz.filhoDir: %p\n", *raiz->_dado, raiz->_altura, raiz->_filhoEsquerda, raiz->_filhoDireita);
    //printf("Fim Adicionar\n\n");
    return raiz;
}

template <typename T>
NodoAVL<T> *getNodo(NodoAVL<T> *raiz, T dado)
{
    //printf("getNodo\n");
    //printf("raiz.dado: %d\nraiz.altura: %d\nraiz.filhoEsq: %p\nraiz.filhoDir: %p\n\n", *raiz->_dado, raiz->_altura, raiz->_filhoEsquerda, raiz->_filhoDireita);

    while (raiz != nullptr && dado != *raiz->_dado)
    {
        //printf("loop\n");
        if (dado < *raiz->_dado)
        {
            raiz = raiz->_filhoEsquerda;
        }
        else
        {
            raiz = raiz->_filhoDireita;
        }
    }
    //printf("fim getNodo\n");
    return raiz;
}
template <typename T>
NodoAVL<T> *getFatherNodo(NodoAVL<T> *raiz, T dado)
{
    //printf("raizD: %d\n", *raiz->_dado);
    if (dado == *raiz->_dado)
        return nullptr;
    NodoAVL<T> *ant;
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
NodoAVL<T> *getMin(NodoAVL<T> *raiz)
{

    while (raiz->_filhoEsquerda != NULL)
    {
        raiz = raiz->_filhoEsquerda;
    }
    return raiz;
}
template <typename T>
NodoAVL<T> *getMax(NodoAVL<T> *raiz)
{

    while (raiz->_filhoDireita != NULL)
    {

        raiz = raiz->_filhoDireita;
    }
    return raiz;
}
template <typename T>
NodoAVL<T> *remover(NodoAVL<T> *raiz, T dado)
{

    printf("\n\n    Entrando em Remover - %d\n", dado);
    printf("Raiz dada\n");
    printNodo(raiz);
    if (raiz == nullptr)
    {
        printf("RAIZ NULA\n");
        return nullptr;
    }
    printf("a\n");
    NodoAVL<T> *response = nullptr;
    if (dado < *raiz->_dado)
        printf("        Dado Menor\n");
    {
        response = remover(raiz->_filhoEsquerda, dado);
        printf("RESPONSE\n");
        printNodo(response);
        if (response)
        {
            if (*response->_dado == dado)
            {
                int fb = getFB(raiz);
                if (fb >= 2 || fb <= -2)
                {
                    if (getHigh(raiz->_filhoDireita->_filhoEsquerda) <= getHigh(raiz->_filhoDireita->_filhoDireita))
                    {
                        raiz = rotDireita(raiz);
                    }
                    else
                    {
                        raiz = rotDireitaEsquerda(raiz);
                    }
                }
            }
        }
    }
    if (dado > *raiz->_dado)
    {
        printf("        Dado Maior\n");
        response = remover(raiz->_filhoDireita, dado);
        printf("RESPONSE\n");
        printNodo(response);
        if (response)
        {
            if (*response->_dado == dado)
            {
                int fb = getFB(raiz);
                if (fb >= 2 || fb <= -2)
                {
                    if (getHigh(raiz->_filhoEsquerda->_filhoDireita) <= getHigh(raiz->_filhoEsquerda->_filhoEsquerda))
                    {
                        raiz = rotEsquerda(raiz);
                    }
                    else
                    {
                        raiz = rotEsquerdaDireita(raiz);
                    }
                }
            }
        }
    }
    if (dado == *raiz->_dado)
    {
        printf("        Achei\n");
        NodoAVL<T> *old = raiz;
        if (raiz->_filhoEsquerda == nullptr || raiz->_filhoDireita == nullptr)
        {

            if (raiz->_filhoEsquerda != nullptr)
            {
                raiz = raiz->_filhoEsquerda;
            }
            else
            {
                raiz = raiz->_filhoDireita;
            }
            //free(old);
        }
        else
        {
            NodoAVL<T> *aux = getMin(raiz->_filhoDireita);
            raiz->_dado = aux->_dado;
            remover(raiz->_filhoDireita, *raiz->_dado);
            int fb = getFB(raiz);
            if (fb >= 2 || fb <= -2)
            {
                if (getHigh(raiz->_filhoEsquerda->_filhoDireita) <= getHigh(raiz->_filhoEsquerda->_filhoEsquerda))
                {
                    raiz = rotEsquerda(raiz);
                }
                else
                {
                    raiz = rotEsquerdaDireita(raiz);
                }
            }
        }
        printf("    Saindo Remover (raiz.dado == dado)\n");
        return old;
    }
    printf("    Saindo Remover\n");
    return nullptr;
}
template <typename T>
void destruir(NodoAVL<T> *raiz)
{
    //IMPLEMENTE AQUI
}

#endif /* NODOAVL_H */
