#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
#include <stdlib.h>
#include <stdio.h>
typedef struct Elemento
{
    int _chave;
    void *_dado;
} Elemento;

int swapsCount = 0;

void swap(int indiceDeUmElemento, int indiceDeOutroElemento, Elemento **umVetor)
{
    swapsCount++;
    Elemento *tmp = umVetor[indiceDeUmElemento];
    umVetor[indiceDeUmElemento] = umVetor[indiceDeOutroElemento];
    umVetor[indiceDeOutroElemento] = tmp;
}

int getSwapsCount()
{
    int ret = swapsCount;
    swapsCount = 0;
    return ret;
}

Elemento **inicializa(int QuantidadeDeElementos)
{
    Elemento **umVetor = (Elemento **)calloc(QuantidadeDeElementos, sizeof(Elemento *));
    return umVetor;
}

void destroi(Elemento **umVetor, int quantidadeDeElementos)
{
    //for(int i=0 ; i < quantidadeDeElementos; i++){
    //    free(umVetor[i]);
    //}

    free(umVetor);
}
int particiona(Elemento **umVet, int ini, int fim)
{
    //printf("partic\n");
    int esq, dir, piv, aux;
    esq = ini;
    dir = fim;
    piv = umVet[ini]->_chave;
    //printf("esq: %d\ndir: %d\npiv: %d\n", esq, dir, piv);
    while (esq < dir)
    {
        //printf("while 1\n");
        while (umVet[esq]->_chave <= piv)
        {
            printf("while 2\n");
            esq++;
            printf("  esq: %d\n", esq);
            if (esq > fim)
            {
                break;
            }
        }
        while (umVet[dir]->_chave > piv)
        {
            printf("while 3\n");
            dir--;
            printf("  dir: %d\n", dir);
            if (dir < ini)
            {
                break;
            }
        }
        if (esq < dir)
        {
            swap(esq, dir, umVet);
        }
    }
    swap(ini, dir, umVet);
    return dir;
}
void quickSort(Elemento **umVet, int ini, int fim)
{
    //printf("quick\n");
    int piv;
    if (fim > ini)
    {
        piv = particiona(umVet, ini, fim);
        quickSort(umVet, ini, piv - 1);
        quickSort(umVet, piv + 1, fim);
    }
}

void sort(Elemento **umVetor, int quantidadeDeElementos)
{
    quickSort(umVetor, 0, quantidadeDeElementos - 1);
}

#endif /* ABSTRACTSORT_H */
