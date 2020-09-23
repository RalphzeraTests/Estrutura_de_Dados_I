#ifndef PILHA_H
#define PILHA_H

#include "ListaEncadeada.h"

typedef ListaEncadeada Pilha;

Pilha *iniciaPilha()
{
    return nullptr;
}
void destroiPilha(Pilha *umaPilha) {}
bool pilhaVazia(Pilha *umaPilha)
{
    return true;
}
void *pop(Pilha *umaPilha)
{
    return nullptr;
}
void push(Pilha *umaPilha, void *umDado) {}

#endif /* PILHA_H */