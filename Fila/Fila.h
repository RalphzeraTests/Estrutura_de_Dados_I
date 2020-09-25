#ifndef FILA_H
#define FILA_H

#include "Elemento.h"
#include <stdbool.h>
#include <exception>
#include <new>

class fila_vazia_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Fila vazia";
    }
};

typedef struct
{
    Elemento *_primeiro;
    Elemento *_ultimo;
    int _quantidade;
} Fila;

Fila *iniciaFila()
{
    Fila *newF = (Fila *)calloc(1, sizeof(Fila));
    newF->_primeiro = nullptr;
    newF->_ultimo = nullptr;
    newF->_quantidade = 0;
    return newF;
}
bool filaVazia(Fila *umaFila) { return umaFila->_quantidade == 0; }
void destroiFila(Fila *umaFila)
{
    if (filaVazia(umaFila))
    {
        free(umaFila);
    }
    else
    {
        Elemento *temp = umaFila->_primeiro;
        Elemento *prox;
        for (int pos = 1; pos <= umaFila->_quantidade; pos++)
        {
            prox = temp->_proximo;
            free(temp);
            if (prox != nullptr)
                temp = prox;
        }
        free(umaFila);
    }
}

bool contem(Fila *umaFila, void *umDado)
{
    bool achou = false;
    Elemento *aux = umaFila->_primeiro;
    if (!(filaVazia(umaFila)))
    {
        for (int i = 0; i < umaFila->_quantidade; i++)
        {

            if (i == 0)
            {
                aux = umaFila->_primeiro;
            }
            else
            {
                if ((aux->_proximo != nullptr))
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
                return achou;
            }
        }
    }

    return achou;
}
int posicao(Fila *umaFila, void *umDado)
{

    int i = 0;
    bool achou = true;
    Elemento *elaux;
    if (contem(umaFila, umDado))
    {
        elaux = umaFila->_primeiro;
        while (achou)
        {
            i++;
            if (elaux->_dado == umDado)
            {
                achou = false;
            }
            else
            {
                if (elaux->_proximo == nullptr)
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
void enqueue(Fila *umaFila, void *umDado)
{

    Elemento *el = (Elemento *)calloc(1, sizeof(Elemento));
    el->_dado = umDado;
    if (filaVazia(umaFila))
    {
        umaFila->_primeiro = el;
    }
    else
    {
        umaFila->_ultimo->_proximo = el;
    }

    umaFila->_ultimo = el;
    umaFila->_quantidade = umaFila->_quantidade + 1;

    return;
}
void *dequeue(Fila *umaFila)
{
    Elemento *aux;
    void *retorno;
    if (filaVazia(umaFila))
    {
        throw fila_vazia_exception();
    }
    else
    {
        aux = umaFila->_primeiro;
        retorno = aux->_dado;
        umaFila->_primeiro = aux->_proximo;
        umaFila->_quantidade = umaFila->_quantidade - 1;
        free(aux);
        return retorno;
    }
    return nullptr;
}

#endif /* FILA_H */