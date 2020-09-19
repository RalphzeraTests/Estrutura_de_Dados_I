

#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <exception>
//#include <new>

typedef struct Elemento
{
    struct Elemento *_proximo;
    void *_dado;
} Elemento;
typedef struct
{
    Elemento *_primeiro;
    int _quantidade;
} ListaEncadeada;
void printaTudo(ListaEncadeada *umaLista)
{
    //printf("\n\n   Lista: %p, qtd: %d, primeiro: %p", umaLista, umaLista->_quantidade, umaLista->_primeiro);
    Elemento *elemento = umaLista->_primeiro;
    for (int pos = 1; pos <= umaLista->_quantidade; pos++)
    {
        //printf("\n   Elemento: %p, dado: %p, proximo: %p", elemento, elemento->_dado, elemento->_proximo);
        elemento = elemento->_proximo;
    }

    //printf("\n\n");
}
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
    Elemento *elemento = umaLista->_primeiro;
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
    free(umaLista);
    /*if (listaVazia(umaLista))
    {
        free(umaLista);
    }
    else
    {
        bool ultimo = true;
        Elemento *percorre = (Elemento *)malloc(sizeof(Elemento));
        Elemento *deleta = (Elemento *)malloc(sizeof(Elemento));
        percorre = umaLista->_primeiro;
        while (ultimo)
        {
            //printf("   O elemento é %p", percorre);
            if (percorre->_proximo == NULL)
            {
                ultimo = false;
            }
            deleta = percorre;
            percorre = percorre->_proximo;
            free(deleta);
        }
        free(percorre);
        free(umaLista);
    }*/

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
            //printf("    umDado: %p\n", umDado);
            //printf("    aux: %p\n", aux);
            el->_dado = umDado;
            el->_proximo = aux->_proximo;

            aux->_proximo = el;

            umaLista->_quantidade = umaLista->_quantidade + 1;
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
    return NULL;
}
void *retiraDaPosicao(ListaEncadeada *umaLista, int umaPosicao)
{
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

//implemente as funcoes da lista encadeada neste arquivo

int main()
{
    printf("\nInicio do Teste iniciaListaEncadeada\n");
    ListaEncadeada *p = iniciaListaEncadeada();
    printf("Lista é nula?                -  %d\n", (p != NULL));
    printf("Lista está vazia?            -  %d\n", listaVazia(p));
    //printf("   Destruindo lista\n");
    destroiListaEncadeada(p);

    printf("\nInicio do Teste listaVazia\n");
    p = iniciaListaEncadeada();
    int d1 = 10;
    printf("A lista esta vazia?          -  %d\n", listaVazia(p));
    adicionaNoInicio(p, &d1);
    printf("A lista NAO está vazia?      -  %d\n", !listaVazia(p));
    //printaTudo(p);
    destroiListaEncadeada(p);

    printf("\n\n\n");
    printf("\nInicio do Teste adicionaNoInicio\n");
    p = iniciaListaEncadeada();
    int d2 = 20;
    int d3 = 30;
    adicionaNoInicio(p, &d1);
    //printaTudo(p);
    printf("O tamanho da Lista é 1?      -  %d\n", p->_quantidade == 1);
    printf("A lista contem d1?           -  %d\n", contem(p, &d1) == true);
    printf("A posicao do d1 é 1?         -  %d\n", posicao(p, &d1) == 1);
    adicionaNoInicio(p, &d2);
    //printaTudo(p);
    printf("O tamanho da lista é 2?      -  %d\n", p->_quantidade == 2);
    printf("A lista contem d2?           -  %d\n", contem(p, &d2) == true);
    printf("A posicao de d2 é 1?         -  %d\n", posicao(p, &d2) == 1);
    printf("A posicao de d1 é 2?         -  %d\n", posicao(p, &d1) == 2);
    adicionaNoInicio(p, &d3);
    printf("O tamanho da lista é 3?      -  %d\n", p->_quantidade == 3);
    printf("A lista contem d3?           -  %d\n", contem(p, &d3) == true);
    printf("A posicao de d3 é 1?         -  %d\n", posicao(p, &d3) == 1);
    printf("A posicao de d2 é 2?         -  %d\n", posicao(p, &d2) == 2);
    printf("A posicao de d1 é 3?         -  %d\n", posicao(p, &d1) == 3);
    destroiListaEncadeada(p);
    printf("\n\n\n");

    printf("\nInicio do Teste AdicionaNaPosicao\n");
    p = iniciaListaEncadeada();
    int d4 = 40;
    adicionaNaPosicao(p, &d1, 1);
    printaTudo(p);
    printf("O tamanho da lista é 1?      -  %d\n", p->_quantidade == 1);
    printf("A posicção do d1 é 1?        -  %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d2, 2);
    printaTudo(p);
    printf("O tamanho da lista é 2?      -  %d\n", p->_quantidade == 2);
    printf("A posicao do d2 é 2?         -  %d\n", posicao(p, &d2) == 2);
    printf("A posicao do d1 é 1?         -  %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d3, 2);
    printaTudo(p);
    printf("O tamanho da lista é 3?      -  %d\n", p->_quantidade == 3);
    printf("A posicao do d3 é 2?         -  %d\n", posicao(p, &d3) == 2);
    printf("A posicao do d2 é 3?         -  %d\n", posicao(p, &d2) == 3);
    printf("A posicao do d1 é 1?         -  %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d4, 3);
    printaTudo(p);
    printf("O tamanho da lista é 4?      -  %d\n", p->_quantidade == 4);
    printf("A posicao do d4 é 3?         -  %d\n", posicao(p, &d4) == 3);
    printf("A posicao do d3 é 2?         -  %d\n", posicao(p, &d3) == 2);
    printf("A posicao d2 é 4?            -  %d\n", posicao(p, &d2) == 4);
    printf("A posicao do d1 é 1?         -  %d\n", posicao(p, &d1) == 1);
    destroiListaEncadeada(p);
    printf("\n\n\n");

    printf("\nInicio do Teste retiraDoInicio\n");
    //printf("q");
    p = iniciaListaEncadeada();
    //printf("a");
    int *r;
    //printf("b");
    adicionaNoInicio(p, &d3);
    //printf("c");
    adicionaNoInicio(p, &d2);
    //printf("d");
    adicionaNoInicio(p, &d1);
    //printf("e");
    r = (int *)retiraDoInicio(p);
    printf("f");
    printf("Quem foi removido foi o d1?  -  %d\n", *r == d1);
    printf("O tamanho da lista é 2?      -  %d\n", p->_quantidade == 2);
    printf("A posicao do d2 é 1?         -  %d\n", posicao(p, &d2) == 1);
    printf("A posicao do d3 é 2?         -  %d\n", posicao(p, &d3) == 2);
    r = (int *)retiraDoInicio(p);
    printf("Quem foi removido foi o d2?  -  %d\n", *r == d2);
    printf("O tamanho da lista é 1?      -  %d\n", p->_quantidade == 1);
    printf("A posicao do d3 é 1?         -  %d\n", posicao(p, &d3) == 1);
    r = (int *)retiraDoInicio(p);
    printf("Quem foi removido foi o d3?  -  %d\n", *r == d3);
    printf("O tamanho da lista é 0?      -  %d\n", p->_quantidade == 0);
    destroiListaEncadeada(p);

    printf("\n\n\n");
    printf("\nInicio do Teste retiraDaPosicao\n");
    p = iniciaListaEncadeada();
    int d5 = 50;
    adicionaNoInicio(p, &d5);
    adicionaNoInicio(p, &d4);
    adicionaNoInicio(p, &d3);
    adicionaNoInicio(p, &d2);
    adicionaNoInicio(p, &d1);
    r = (int *)retiraDaPosicao(p, 5);
    printf("Quem foi removido foi o d5?  -  %d\n", *r == d5);
    printf("O tamanho da lista é 4?      -  %d\n", p->_quantidade == 4);
    printf("A posicao do d2 é 2?         -  %d\n", posicao(p, &d2) == 2);
    r = (int *)retiraDaPosicao(p, 3);
    printf("Quem foi removido foi o d3?  -  %d\n", *r == d3);
    printf("O tamanho da lista é 3?      -  %d\n", p->_quantidade == 3);
    printf("A posicao do d4 é 3?         -  %d\n", posicao(p, &d4) == 3);
    r = (int *)retiraDaPosicao(p, 2);
    printf("Quem foi removido foi o d2?  -  %d\n", *r == d2);
    printf("O tamanho da lista é 2?      -  %d\n", p->_quantidade == 2);
    printf("A posicao do d4 é 2?         -  %d\n", posicao(p, &d4) == 2);
    r = (int *)retiraDaPosicao(p, 1);
    printf("%d\n", *r == d1);
    printf("O tamanho da lista é 1?      -  %d\n", p->_quantidade == 1);
    printf("A posicao do d4 é 1?         -  %d\n", posicao(p, &d4) == 1);
    r = (int *)retiraDaPosicao(p, 1);
    printf("quem foi removido foi o d4?  -  %d\n", *r == d4);
    printf("O tamanho da lista é 0?      -  %d\n", p->_quantidade == 0);
    printf("A lista contem  d4?          -  %d\n", contem(p, &d4) == false);
    destroiListaEncadeada(p);
}