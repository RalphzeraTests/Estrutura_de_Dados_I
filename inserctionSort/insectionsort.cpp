#include "AbstractSort.h"
#include <stdio.h>
#include <stdlib.h>
//implemente AQUI a funcao sort do Insertion Sort
//você DEVE utilizar a função swap para trocar dois elementos de posição - UÉ KKKKKKK

void sort(Elemento** umVetor, int quantidadeDeElementos){
    /*for(int a = 0; a<quantidadeDeElementos; a++){
        printf("%d\n",umVetor[a]->_chave);
    }
    printf("\n\n");*/
    for(int i = 1;i<quantidadeDeElementos;i++){
        int aux = umVetor[i]->_chave;
        int j = i-1;
        /*
        printf("aux: %d || v[j]: %d\n",aux,umVetor[j]->_chave);
        printf("j: %d\n",j);
        printf("\n");
        for(int a = 0; a<quantidadeDeElementos; a++){
            printf("%d\n",umVetor[a]->_chave);
        }
        printf("\n");
        */
        while( j>=0 && umVetor[j]->_chave>aux){
            umVetor[j+1]->_chave = umVetor[j]->_chave;
            /*
            printf("\n");
             for(int a = 0; a<quantidadeDeElementos; a++){
                printf("%d\n",umVetor[a]->_chave);
            }
            */
            j = j-1;
            //printf("j: %d\n",j);
        }
        umVetor[j+1]->_chave = aux;
        /*
        printf("\n");
        for(int a = 0; a<quantidadeDeElementos; a++){
            printf("%d\n",umVetor[a]->_chave);
        }
        printf("\n");
        */
    }/*
    printf("\n\n");
     for(int a = 0; a<quantidadeDeElementos; a++){
        printf("%d\n",umVetor[a]->_chave);
    }
    printf("\n\n");
    */
}