#ifndef PILHA_H
#define PILHA_H
#include "gtest/gtest.h"
#include "ListaEncadeada.h"
#include "Elemento.h"

typedef ListaEncadeada Pilha;

Pilha *iniciaPilha()
{
    return iniciaListaEncadeada();
}
bool pilhaVazia(Pilha *umaPilha)
{
    return umaPilha->_quantidade == 0;
}
void destroiPilha(Pilha *umaPilha)
{
    destroiListaEncadeada(umaPilha);
}

void *pop(Pilha *umaPilha)
{
    return retiraDoInicio(umaPilha);
}
void push(Pilha *umaPilha, void *umDado)
{
    adicionaNoInicio(umaPilha, umDado);
}

#endif /* PILHA_H */