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
    //printf("Antigo primeiro da lista: %p\n", umaLista->_primeiro);
    if (umaLista->_primeiro != NULL)
    {
        //printf("umaLista->_primeiro->dado: %p\n", elemento->_dado);
    }
    Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
    //printf("     Endereço do novo elemento: %p\n", el);
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
    //printf("   | Destruindo lista encadeada |\n");
    //printf("   | Percorrendo toda a lista |\n");
    //free(umaLista);
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
    //printf("      - procurando se existe\n");
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
            //printf("      aux: %p / aux.dado: %p\n", aux, aux->_dado);
            if (aux->_dado == umDado)
            {
                achou = true;
                // printf("      opa, achei\n");

                return achou;
            }
            else
            {
                //printf("      ainda não achei\n");
            }
        }
    }

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

    return i;
}
Elemento *achaEndereco(int pos, ListaEncadeada *lista)
{
    //printf("\n\n   Lista: %p, qtd: %d, primeiro: %p", umaLista, umaLista->_quantidade, umaLista->_primeiro);
    Elemento *elemento = lista->_primeiro;
    for (int aux = 1; aux < pos - 1; aux++)
    {
        elemento = elemento->_proximo;
    }
    return elemento;
}
void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
{
    if (umaPosicao == 1)
    {
        adicionaNoInicio(umaLista, umDado);
    }
    else
    {
        if (umaLista->_quantidade <= umaPosicao && umaPosicao > 0 && !(listaVazia(umaLista)))
        {
            Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
            Elemento *aux = achaEndereco(umaPosicao, umaLista);
            el->_dado = umDado;
            el->_proximo = aux->_proximo;

            aux->_proximo = el;

            umaLista->_quantidade = umaLista->_quantidade + 1;
        }
        else
        {
            throw posicao_invalida_exception();
        }
        //adicionaNoInicio(umaLista, umDado);
    }
    return;
}
void adicionaNoFim(ListaEncadeada *umaLista, void *umDado)
{
    return;
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
    if (listaVazia(umaLista))
    {
        throw lista_encadeada_vazia_exception();
    }
    else
    {
        if (umaLista->_quantidade <= umaPosicao && umaPosicao > 0)
        {
            if (umaPosicao == 1)
            {
                return retiraDoInicio(umaLista);
            }
        }
        else
        {
            throw posicao_invalida_exception();
        }
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
