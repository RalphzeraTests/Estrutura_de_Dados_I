#include "AbstractSort.h"
#include "gtest/gtest.h"
//implemente AQUI as funcoes sort e max_heapify do HeapSort
//você DEVE utilizar a função swap para trocar dois elementos de posição

void sort(Elemento **umVetor, int quantidadeDeElementos)
{
    for (int i = quantidadeDeElementos / 2; i > 0; i--)
    {
        max_heapify(umVetor, quantidadeDeElementos, i);
    }
    for (int k = quantidadeDeElementos; k > 1; k--)
    {
        swap(0, k, umVetor);
        quantidadeDeElementos--;
        max_heapify(umVetor, quantidadeDeElementos, 0);
    }
}

void max_heapify(Elemento **umVetor, int quantidadeDeElementos, int i)
{
    int a = i * 2;
    int b = i * 2 + 1;
    int max = i;
    if (a <= quantidadeDeElementos && umVetor[a]->_chave > umVetor[i]->_chave)
    {
        max = a;
    }
    if (b <= quantidadeDeElementos && umVetor[b]->_chave > umVetor[max]->_chave)
    {
        max = b;
    }
    if (max != i)
    {
        swap(i, max, umVetor);
        max_heapify(umVetor, quantidadeDeElementos, max);
    }
}