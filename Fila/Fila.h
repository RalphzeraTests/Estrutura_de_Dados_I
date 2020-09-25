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
void destroiFila(Fila *umaFila) {}
bool filaVazia(Fila *umaFila) { return umaFila->_quantidade == 0; }
bool contem(Fila *umaFila, void *umDado) { return true; }
int posicao(Fila *umaFila, void *umDado) { return 0; }
void enqueue(Fila *umaFila, void *umDado) {}
void *dequeue(Fila *umaFila) { return nullptr; }

#endif /* FILA_H */