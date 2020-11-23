#include "gtest/gtest.h"
#include "Nodo.h"
#include <mutex>

//std::mutex g_singleThread;

TEST(ArvoreBinariaBuscaTest, PreOrdem)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int> *raiz = (Nodo<int> *)calloc(1, sizeof(Nodo<int>));
    adiciona(raiz, &e5);
    adiciona(raiz, &e3);
    adiciona(raiz, &e7);
    adiciona(raiz, &e2);
    adiciona(raiz, &e4);
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);

    ListaEncadeada *lista = iniciaListaEncadeada();
    preOrdem(raiz, lista);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e5);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e3);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e2);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e4);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e7);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e6);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e9);

    destruir(raiz);
    free(lista);
}

TEST(ArvoreBinariaBuscaTest, EmOrdem)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int> *raiz = (Nodo<int> *)calloc(1, sizeof(Nodo<int>));
    adiciona(raiz, &e5);
    adiciona(raiz, &e3);
    adiciona(raiz, &e7);
    adiciona(raiz, &e2);
    adiciona(raiz, &e4);
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);

    ListaEncadeada *lista = iniciaListaEncadeada();
    emOrdem(raiz, lista);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e2);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e3);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e4);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e5);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e6);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e7);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e9);

    destruir(raiz);
    free(lista);
}

TEST(ArvoreBinariaBuscaTest, PosOrdem)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int> *raiz = (Nodo<int> *)calloc(1, sizeof(Nodo<int>));
    adiciona(raiz, &e5);
    adiciona(raiz, &e3);
    adiciona(raiz, &e7);
    adiciona(raiz, &e2);
    adiciona(raiz, &e4);
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);

    ListaEncadeada *lista = iniciaListaEncadeada();
    posOrdem(raiz, lista);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e2);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e4);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e3);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e6);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e9);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e7);
    ASSERT_EQ(*(int *)retiraDoInicio(lista), e5);

    destruir(raiz);
    free(lista);
}

TEST(ArvoreBinariaBuscaTest, GetNodo)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    Nodo<int> *raiz = (Nodo<int> *)calloc(1, sizeof(Nodo<int>));
    adiciona(raiz, &e5);
    adiciona(raiz, &e3);
    adiciona(raiz, &e7);
    adiciona(raiz, &e2);
    adiciona(raiz, &e4);
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);

    Nodo<int> *nodo;

    nodo = getNodo(raiz, 9);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);
    ASSERT_EQ(*nodo->_dado, 9);

    nodo = getNodo(raiz, 7);
    ASSERT_NE(nodo->_filhoEsquerda, nullptr);
    ASSERT_NE(nodo->_filhoDireita, nullptr);
    ASSERT_EQ(*nodo->_dado, 7);
    destruir(raiz);
}

TEST(ArvoreBinariaBuscaTest, Remover)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;
    int *dadoRemovido;

    Nodo<int> *raiz = (Nodo<int> *)calloc(1, sizeof(Nodo<int>));
    adiciona(raiz, &e5);
    adiciona(raiz, &e3);
    adiciona(raiz, &e7);
    adiciona(raiz, &e2);
    adiciona(raiz, &e4);
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);

    Nodo<int> *nodo;

    //Testa remover chave inexistente
    dadoRemovido = remover(raiz, 10);
    ASSERT_EQ(dadoRemovido, nullptr);

    //Testa remover folha
    dadoRemovido = remover(raiz, 9);

    ASSERT_EQ(*dadoRemovido, 9);

    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);

    //Testa remover folha
    dadoRemovido = remover(raiz, 6);
    ASSERT_EQ(*dadoRemovido, 6);
    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);

    //Testa remover raiz
    adiciona(raiz, &e6);
    adiciona(raiz, &e9);
    dadoRemovido = remover(raiz, 5);
    ASSERT_EQ(*dadoRemovido, 5);
    nodo = getNodo(raiz, 6);
    ASSERT_EQ(nodo->_filhoDireita, getNodo(raiz, 7));

    //Testa remover nodo com filhoDireita sem descendente a direita
    adiciona(raiz, &e5);
    nodo = getNodo(raiz, 4);
    ASSERT_EQ(nodo->_filhoDireita, getNodo(raiz, 5));
    dadoRemovido = remover(raiz, 3);
    ASSERT_EQ(*dadoRemovido, 3);
    ASSERT_EQ(*raiz->_filhoEsquerda->_dado, 4);
    ASSERT_EQ(*raiz->_filhoEsquerda->_filhoDireita->_dado, 5);
    ASSERT_EQ(raiz->_filhoEsquerda->_filhoDireita->_filhoDireita, nullptr);
    ASSERT_EQ(raiz->_filhoEsquerda->_filhoDireita->_filhoEsquerda, nullptr);
    ASSERT_EQ(*raiz->_filhoEsquerda->_filhoEsquerda->_dado, 2);

    destruir(raiz);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}