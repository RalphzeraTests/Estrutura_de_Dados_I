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
void printaVetor(Elemento **umVetor, int quantidadeDeElementos)
{
    for (int cont = 0; cont < quantidadeDeElementos; cont++)
    {
        printf("%d\n", umVetor[cont]->_chave);
    }
}

void max_heapify(Elemento **umVetor, int quantidadeDeElementos, int i)
{
    if (quantidadeDeElementos <= i || i < 0)
    {
        //throw posicao_invalida_exception();
    }
    printf("max_heapify\n");
    printf("i: %d\n", i);
    printaVetor(umVetor, quantidadeDeElementos);
    int a = (i + 1) * 2;
    int b = (i + 1) * 2 + 1;
    int max = i + 1;
    printf("esq: %d\ndir: %d\nmax: %d\n", a - 1, b - 1, max - 1);

    printf("a\n");
    if (a <= quantidadeDeElementos && umVetor[a - 1]->_chave > umVetor[i]->_chave)
    {
        max = a;
    }
    printf("b\n");
    if (b <= quantidadeDeElementos && umVetor[b - 1]->_chave > umVetor[max - 1]->_chave)
    {
        max = b;
    }
    printf("c\n");
    if (max != i)
    {
        printf("max!=i -> max: %d\n", max);
        swap(i - 1, max - 1, umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
        printf("d\n");
    }

    printf("f\n");
}

void construirHeapMax(Elemento **umVetor, int tamanho)
{
    printf("\nconstruirHeapMax\n");
    printaVetor(umVetor, tamanho);
    for (int i = (tamanho / 2); i > 0; i--)
    {
        max_heapify(umVetor, tamanho, i - 1);
    }
}
void sort(Elemento **umVetor, int quantidadeDeElementos)
{
    printf("\nSORT\n");
    printaVetor(umVetor, quantidadeDeElementos);
    construirHeapMax(umVetor, quantidadeDeElementos);
    for (int k = quantidadeDeElementos; k > 1; k--)
    {
        printf("swaps:%d\n\n", getSwapsCount());
        swap(0, k - 1, umVetor);
        max_heapify(umVetor, k - 1, 0);
    }

    printaVetor(umVetor, quantidadeDeElementos);
}

#endif /* ABSTRACTSORT_H */
