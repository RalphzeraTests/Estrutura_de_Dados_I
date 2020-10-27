#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
#include <exception>
#include <stdlib.h>

class posicao_invalida_exception : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Posicao invalida na heap";
    }
};

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
void max_heapify(Elemento **umVetor, int quantidadeDeElementos, int i)
{
    if (quantidadeDeElementos <= i || i < 0)
    {
        throw posicao_invalida_exception();
    }
    //printf("max_heapify\n");
    //printf("i: %d\n", i);
    int a = (i * 2) + 1;
    int b = (i * 2) + 2;
    int max = i;
    //printf("esq: %d\ndir: %d\nmax: %d\n", a, b, max);

    //printf("a\n");
    if (a < quantidadeDeElementos && umVetor[a]->_chave > umVetor[max]->_chave)
    {
        max = a;
    }
    //printf("b\n");
    if (b < quantidadeDeElementos && umVetor[b]->_chave > umVetor[max]->_chave)
    {
        max = b;
    }
    //printf("c\n");
    if (max != i)
    {
        //printf("max!=i -> max: %d\n", max);
        swap(i, max, umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
        //printf("d\n");
    }

    //printf("f\n");
}

void construirHeapMax(Elemento **umVetor, int tamanho)
{
    //printf("\nconstruirHeapMax\n");
    for (int i = (tamanho / 2) - 1; i >= 0; i--)
    {
        max_heapify(umVetor, tamanho, i);
    }
}
void sort(Elemento **umVetor, int quantidadeDeElementos)
{
    //printf("\nSORT\n");
    construirHeapMax(umVetor, quantidadeDeElementos);
    for (int k = quantidadeDeElementos - 1; k > 0; k--)
    {
        //printf("swaps:%d\n\n", getSwapsCount());
        swap(0, k, umVetor);
        max_heapify(umVetor, k, 0);
    }
}

#endif /* ABSTRACTSORT_H */
