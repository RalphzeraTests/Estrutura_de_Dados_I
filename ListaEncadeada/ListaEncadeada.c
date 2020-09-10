#ifndef ELEMENTO_H
#define ELEMENTO_H
#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <exception>
//#include <new>

typedef struct Elemento
{
    struct Elemento *_proximo;
    void *_dado;
} Elemento;
typedef struct
{
    Elemento *_primeiro;
    int _quantidade;
} ListaEncadeada;

ListaEncadeada *iniciaListaEncadeada()
{

    ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    lista->_primeiro = NULL;
    lista->_quantidade = 0;

    return (lista);
}

void adicionaNoInicio(ListaEncadeada *umaLista, void *umDado)
{
    printf("adicionando no inicio    |  ");
    printf("umDado: %p\n", umDado);
    Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
    el->_dado = umDado;

    if (umaLista->_quantidade == 0)
    {
        umaLista->_primeiro = el;
        el->_proximo = NULL;
    }
    else
    {
        Elemento *antigo = umaLista->_primeiro;
        umaLista->_primeiro = el;
        el->_proximo = antigo;
    }
    umaLista->_quantidade = umaLista->_quantidade + 1;

    return;
}
bool listaVazia(ListaEncadeada *umaLista)
{
    return umaLista->_primeiro == NULL;
}
void destroiListaEncadeada(ListaEncadeada *umaLista)
{
    free(umaLista);
    return;
}
int posicao(ListaEncadeada *umaLista, void *umDado)
{
    return 1;
}
bool contem(ListaEncadeada *umaLista, void *umDado)
{
    bool achou = false;
    printf("procurando\n");
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    for (int i = 0; i < umaLista->_quantidade; i++)
    {
        if (!(umaLista->_primeiro == NULL))
        {
            if (i == 0)
            {
                el = umaLista->_primeiro;
            }
            else
            {
                if (!(el->_proximo == NULL))
                {
                    el = el->_proximo;
                }
                else
                {
                    return achou;
                }
            }
            if (el->_dado == umDado)
            {
                achou = true;
                printf("opa, achei\n");
            }
            else
            {
                printf("ainda não achei\n");
            }
        }
    }
    free(el);
    return achou;
}
void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
{
    return;
}
void adicionaNoFim(ListaEncadeada *umaLista, void *umDado)
{
    return;
}
void *retiraDoInicio(ListaEncadeada *umaLista)
{
    return NULL;
}
void *retiraDaPosicao(ListaEncadeada *umaLista, int umaPosicao)
{
    return NULL;
}
void *retiraDoFim(ListaEncadeada *umaLista)
{
    return NULL;
}
void *retiraEspecifico(ListaEncadeada *umaLista, void *umDado)
{
    return NULL;
}

#endif /* LISTAENCADEADA_H */

#endif /* ELEMENTO_H */

//implemente as funcoes da lista encadeada neste arquivo

int main()
{
    printf("Inicio\n");
    ListaEncadeada *p = iniciaListaEncadeada();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;
    printf("Quantidade: %d || primeiro: %p\n", p->_quantidade, p->_primeiro);
    adicionaNoInicio(p, &d1);
    printf("Quantidade: %d || primeiro: %p\n", p->_quantidade, p->_primeiro);
    if (listaVazia(p))
    {
        printf("Lista esta vazia\n");
    }
    else
    {
        printf("Lista não esta Vazia\n");
        printf("d1: %p\n", &d1);
        printf("Dado1: %p || proximo: %p\n", p->_primeiro->_dado, p->_primeiro->_proximo);
        contem(p, &d1);
    }
    destroiListaEncadeada(p);

    return 1;
}