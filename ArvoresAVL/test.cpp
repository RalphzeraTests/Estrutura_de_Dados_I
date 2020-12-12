#include "gtest/gtest.h"
#include "NodoAVLPerna.h"
#include <mutex>

//std::mutex g_singleThread;

TEST(ArvoreAVLTest, RotacaoDireitaSimples)
{
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));

    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e1);

    ASSERT_EQ(getNodo(raiz, e3)->_altura, 2);
    ASSERT_EQ(getNodo(raiz, e3)->_filhoEsquerda, getNodo(raiz, 2));
    ASSERT_EQ(getNodo(raiz, e3)->_filhoDireita, getNodo(raiz, 4));

    ASSERT_EQ(getNodo(raiz, e2)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e2)->_filhoEsquerda, getNodo(raiz, 1));
    ASSERT_EQ(getNodo(raiz, e2)->_filhoDireita, nullptr);

    ASSERT_EQ(getNodo(raiz, e1)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e1)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e1)->_filhoDireita, nullptr);

    ASSERT_EQ(getNodo(raiz, e4)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e4)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e4)->_filhoDireita, nullptr);

    destruir(raiz);
}

TEST(ArvoreAVLTest, RotacaoEsquerdaSimples)
{
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));

    raiz = adicionar(raiz, &e1);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e4);

    ASSERT_EQ(getNodo(raiz, e3)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e3)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e3)->_filhoDireita, getNodo(raiz, 4));

    ASSERT_EQ(getNodo(raiz, e2)->_altura, 2);
    ASSERT_EQ(getNodo(raiz, e2)->_filhoEsquerda, getNodo(raiz, 1));
    ASSERT_EQ(getNodo(raiz, e2)->_filhoDireita, getNodo(raiz, 3));

    ASSERT_EQ(getNodo(raiz, e1)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e1)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e1)->_filhoDireita, nullptr);

    ASSERT_EQ(getNodo(raiz, e4)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e4)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e4)->_filhoDireita, nullptr);

    destruir(raiz);
}

TEST(ArvoreAVLTest, RotacaoEsquerdaDireita)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e6 = 6;
    int e7 = 7;
    int e8 = 8;
    int e9 = 9;
    int e;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));

    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e8);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e9);
    raiz = adicionar(raiz, &e3);

    e = 2;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 3;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 2));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 4));

    e = 4;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 6;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 2);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 3));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 8));

    e = 8;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 7));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 9));

    e = 7;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 9;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);
    destruir(raiz);
}

TEST(ArvoreAVLTest, RotacaoDireitaEsquerda)
{
    int e1 = 1;
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e15 = 15;
    int e16 = 16;
    int e;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));

    raiz = adicionar(raiz, &e1);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e5);
    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e16);
    raiz = adicionar(raiz, &e15);

    e = 1;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 2;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 1));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 3));

    e = 3;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 4;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 3);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 2));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 6));

    e = 5;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 6;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 2);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 5));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 15));

    e = 7;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    e = 15;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 1);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, getNodo(raiz, 7));
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, getNodo(raiz, 16));

    e = 16;
    ASSERT_EQ(getNodo(raiz, e)->_altura, 0);
    ASSERT_EQ(getNodo(raiz, e)->_filhoEsquerda, nullptr);
    ASSERT_EQ(getNodo(raiz, e)->_filhoDireita, nullptr);

    destruir(raiz);
}

TEST(ArvoreAVLTest, EmOrdem)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));
    raiz = adicionar(raiz, &e5);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e9);

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

TEST(ArvoreAVLTest, PosOrdem)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));
    raiz = adicionar(raiz, &e5);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e9);

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

TEST(ArvoreAVLTest, GetNodo)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));
    raiz = adicionar(raiz, &e5);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e9);

    NodoAVL<int> *nodo;

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

TEST(ArvoreAVLTest, Remover)
{
    int e2 = 2;
    int e3 = 3;
    int e4 = 4;
    int e5 = 5;
    int e6 = 6;
    int e7 = 7;
    int e9 = 9;
    NodoAVL<int> *nodo;

    NodoAVL<int> *raiz = (NodoAVL<int> *)calloc(1, sizeof(NodoAVL<int>));
    raiz = adicionar(raiz, &e5);
    raiz = adicionar(raiz, &e3);
    raiz = adicionar(raiz, &e7);
    raiz = adicionar(raiz, &e2);
    raiz = adicionar(raiz, &e4);
    raiz = adicionar(raiz, &e6);
    raiz = adicionar(raiz, &e9);

    //Testa remover chave inexistente
    nodo = remover(raiz, 10);
    ASSERT_EQ(nodo, raiz);

    //Testa remover folha
    nodo = remover(raiz, 9);
    ASSERT_EQ(nodo, raiz);
    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);

    //Testa remover folha
    nodo = remover(raiz, 6);
    ASSERT_EQ(nodo, raiz);
    nodo = getNodo(raiz, 7);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, nullptr);

    //Testa remover raiz (**use a estratégia de menor chave na subárvore à direita**)
    adicionar(raiz, &e6);
    adicionar(raiz, &e9);
    raiz = remover(raiz, e5);
    ASSERT_EQ(*raiz->_dado, e6);
    nodo = getNodo(raiz, e7);
    ASSERT_EQ(nodo->_filhoEsquerda, nullptr);
    ASSERT_EQ(nodo->_filhoDireita, getNodo(raiz, e9));

    //Testar remover nodo apenas subarvore direita
    nodo = remover(raiz, e7);
    ASSERT_EQ(nodo, raiz);
    raiz = nodo;
    nodo = getNodo(raiz, e9);
    ASSERT_EQ(raiz->_filhoDireita, nodo);
    destruir(raiz);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}