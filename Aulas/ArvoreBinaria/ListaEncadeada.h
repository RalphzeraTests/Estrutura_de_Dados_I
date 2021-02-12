#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Elemento.h"
#include <stdbool.h>
#include <exception>
#include <new>
#include <stdio.h>
#include <stdlib.h>

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

    Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
    el->_dado = umDado;
    el->_proximo = umaLista->_primeiro;

    umaLista->_primeiro = el;

    umaLista->_quantidade = umaLista->_quantidade + 1;
}
bool listaVazia(ListaEncadeada *umaLista)
{
    return umaLista->_quantidade == 0;
}
void destroiListaEncadeada(ListaEncadeada *umaLista)
{

    if (listaVazia(umaLista))
    {
        free(umaLista);
    }
    else
    {
        Elemento *temp = umaLista->_primeiro;
        Elemento *prox;
        for (int pos = 1; pos <= umaLista->_quantidade; pos++)
        {
            prox = temp->_proximo;
            free(temp);
            if (prox != NULL)
                temp = prox;
        }
        free(umaLista);
    }

    return;
}
bool contem(ListaEncadeada *umaLista, void *umDado)
{
    bool achou = false;
    Elemento *aux = umaLista->_primeiro;
    for (int i = 0; i < umaLista->_quantidade; i++)
    {
        if (!(listaVazia(umaLista)))
        {
            if (i == 0)
            {
                aux = umaLista->_primeiro;
            }
            else
            {
                if ((aux->_proximo != NULL))
                {
                    aux = aux->_proximo;
                }
                else
                {

                    return achou;
                }
            }
            if (aux->_dado == umDado)
            {
                achou = true;
                return achou;
            }
        }
    }

    return achou;
}
int posicao(ListaEncadeada *umaLista, void *umDado)
{
    int i = 0;
    bool achou = true;
    Elemento *elaux = (Elemento *)malloc(sizeof(Elemento));
    if (contem(umaLista, umDado))
    {
        elaux = umaLista->_primeiro;
        while (achou)
        {
            i++;
            if (elaux->_dado == umDado)
            {
                achou = false;
            }
            else
            {
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

    return i;
}
Elemento *achaEndereco(int pos, ListaEncadeada *lista)
{
    Elemento *elemento = lista->_primeiro;
    for (int aux = 1; aux < pos - 1; aux++)
    {
        elemento = elemento->_proximo;
    }
    return elemento;
}
void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
{

    if (umaLista->_quantidade + 1 >= umaPosicao && umaPosicao > 0)
    {

        if (umaPosicao == 1)
        {
            adicionaNoInicio(umaLista, umDado);
        }
        else
        {
            Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
            Elemento *aux = achaEndereco(umaPosicao, umaLista);
            el->_dado = umDado;
            el->_proximo = aux->_proximo;

            aux->_proximo = el;

            umaLista->_quantidade = umaLista->_quantidade + 1;
        }
    }
    else
    {
        throw posicao_invalida_exception();
    }

    return;
}
void adicionaNoFim(ListaEncadeada *umaLista, void *umDado)
{
    adicionaNaPosicao(umaLista, umDado, umaLista->_quantidade + 1);
}
void *retiraDoInicio(ListaEncadeada *umaLista)
{
    Elemento *aux;
    void *retorno;
    if (listaVazia(umaLista))
    {
        throw lista_encadeada_vazia_exception();
    }
    else
    {
        aux = umaLista->_primeiro;
        retorno = aux->_dado;
        umaLista->_primeiro = aux->_proximo;
        umaLista->_quantidade = umaLista->_quantidade - 1;
        free(aux);
        return retorno;
    }
    return NULL;
}
void *retiraDaPosicao(ListaEncadeada *umaLista, int umaPosicao)
{
    Elemento *aux, *elemento;
    void *retorno;
    if (umaLista->_quantidade >= umaPosicao && umaPosicao > 0)
    {
        if (listaVazia(umaLista))
        {
            throw lista_encadeada_vazia_exception();
        }
        else
        {
            if (umaPosicao == 1)
            {
                return retiraDoInicio(umaLista);
            }
            else
            {
                aux = umaLista->_primeiro;
                for (int i = 1; i < umaPosicao - 1; i++)
                {
                    aux = aux->_proximo;
                }
                elemento = aux->_proximo;
                retorno = elemento->_dado;
                aux->_proximo = elemento->_proximo;
                umaLista->_quantidade = umaLista->_quantidade - 1;
                free(elemento);
                return retorno;
            }
        }
    }
    else
    {
        throw posicao_invalida_exception();
    }

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
