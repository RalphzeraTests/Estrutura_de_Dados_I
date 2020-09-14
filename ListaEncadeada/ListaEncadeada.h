#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "gtest/gtest.h"
#include "Elemento.h"
#include <stdbool.h>
//#include <exception>
//#include <new>

class posicao_invalida_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Posicao invalida na lista encadeada";
    }
};

class lista_encadeada_vazia_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Lista encadeada vazia";
    }
};

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
    //printf("   - adicionando no inicio    |  endereço da Lista: %p\n", umaLista);
    //printf("   umDado: %p\n", umDado);
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    //printf("   endereço do novo elemento: %p\n", el);
    el->_dado = umDado;
    el->_proximo = umaLista->_primeiro;
    umaLista->_primeiro = el;

    umaLista->_quantidade = umaLista->_quantidade + 1;

    return;
}
bool listaVazia(ListaEncadeada *umaLista)
{
    return umaLista->_quantidade == 0;
}
void destroiListaEncadeada(ListaEncadeada *umaLista)
{
    printf("   | Destruindo lista encadeada |\n");
    printf("   | Percorrendo toda a lista |\n");

    if (listaVazia(umaLista))
    {
        free(umaLista);
    }
    else
    {
        bool ultimo = true;
        Elemento *percorre = (Elemento *)malloc(sizeof(Elemento));
        Elemento *deleta = (Elemento *)malloc(sizeof(Elemento));
        percorre = umaLista->_primeiro;
        while (ultimo)
        {
            printf("   O elemento é %p", percorre);
            if (percorre->_proximo == NULL)
            {
                ultimo = false;
            }
            deleta = percorre;
            percorre = percorre->_proximo;
            free(deleta);
        }
        free(percorre);
        free(umaLista);
    }

    return;
}
bool contem(ListaEncadeada *umaLista, void *umDado)
{
    bool achou = false;
    printf("      - procurando se existe\n");
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));

    el = umaLista->_primeiro;
    for (int i = 0; i < umaLista->_quantidade; i++)
    {
        if (!(listaVazia(umaLista)))
        {
            if (i == 0)
            {
                el = umaLista->_primeiro;
            }
            else
            {
                if ((el->_proximo != NULL))
                {
                    el = el->_proximo;
                }
                else
                {

                    return achou;
                }
            }
            //printf("      el: %p / el.dado: %p\n", el, el->_dado);
            if (el->_dado == umDado)
            {
                achou = true;
                printf("      opa, achei\n");

                return achou;
            }
            else
            {
                //printf("      ainda não achei\n");
            }
        }
    }
    free(el);

    return achou;
}
int posicao(ListaEncadeada *umaLista, void *umDado)
{
    //printf("   - Verficando Posicao | \n");
    //printf("\n");
    int i = 0;
    bool achou = true;
    Elemento *elaux = (Elemento *)malloc(sizeof(Elemento));
    if (contem(umaLista, umDado))
    {
        //printf("\n");
        elaux = umaLista->_primeiro;
        while (achou)
        {
            i++;
            //printf("   el: %p / el.dado: %p\n", elaux, elaux->_dado);
            if (elaux->_dado == umDado)
            {
                achou = false;
                //printf("   opa, achei a posicao\n");
            }
            else
            {
                //printf("   ainda não achei a posicao\n");
                if (elaux->_proximo == NULL)
                {
                    achou = false;
                }
                else
                {
                    elaux = elaux->_proximo;
                }
            }
        }
    }

    free(elaux);

    return i;
}
void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
{
    if (umaPosicao == 1)
    {
        adicionaNoInicio(umaLista, umDado);
    }
    else
    {
        adicionaNoInicio(umaLista, umDado);
    }
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
