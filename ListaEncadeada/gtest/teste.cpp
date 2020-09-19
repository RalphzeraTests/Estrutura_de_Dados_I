#include "gtest/gtest.h"
#include "ListaEncadeada.h"
#include "Elemento.h"

//extern "C" {
//#include "stack.h"
//}

TEST(ListaEncadeadaTest, Init)
{
    ListaEncadeada *p = iniciaListaEncadeada();
    ASSERT_NE(p, nullptr);
    ASSERT_EQ(listaVazia(p), true);
    //EXPECT_THROW(top(p),empty_stack_exception);
    destroiListaEncadeada(p);
}

TEST(ListaEncadeadaTest, ListaVazia)
{
    ListaEncadeada *p = iniciaListaEncadeada();
    int d1 = 10;

    ASSERT_EQ(listaVazia(p), true);

    adicionaNoInicio(p, &d1);

    ASSERT_EQ(listaVazia(p), false);

    destroiListaEncadeada(p);
}

TEST(ListaEncadeadaTest, AdicionaNoInicio)
{
    ListaEncadeada *p = iniciaListaEncadeada();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;

    adicionaNoInicio(p, &d1);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(contem(p, &d1), true);
    ASSERT_EQ(posicao(p, &d1), 1);

    adicionaNoInicio(p, &d2);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(contem(p, &d2), true);
    ASSERT_EQ(posicao(p, &d2), 1);
    ASSERT_EQ(posicao(p, &d1), 2);

    adicionaNoInicio(p, &d3);
    ASSERT_EQ(p->_quantidade, 3);
    ASSERT_EQ(contem(p, &d3), true);
    ASSERT_EQ(posicao(p, &d3), 1);
    ASSERT_EQ(posicao(p, &d2), 2);
    ASSERT_EQ(posicao(p, &d1), 3);

    destroiListaEncadeada(p);
}

TEST(ListaEncadeadaTest, AdicionaNaPosicao)
{
    ListaEncadeada *p = iniciaListaEncadeada();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;
    int d4 = 40;

    EXPECT_THROW(adicionaNaPosicao(p, &d1, -1), posicao_invalida_exception);
    EXPECT_THROW(adicionaNaPosicao(p, &d1, 0), posicao_invalida_exception);
    EXPECT_THROW(adicionaNaPosicao(p, &d1, 2), posicao_invalida_exception);
    EXPECT_THROW(adicionaNaPosicao(p, &d1, 100), posicao_invalida_exception);

    adicionaNaPosicao(p, &d1, 1);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(posicao(p, &d1), 1);

    adicionaNaPosicao(p, &d2, 2);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(posicao(p, &d2), 2);
    ASSERT_EQ(posicao(p, &d1), 1);

    adicionaNaPosicao(p, &d3, 2);
    ASSERT_EQ(p->_quantidade, 3);
    ASSERT_EQ(posicao(p, &d3), 2);
    ASSERT_EQ(posicao(p, &d2), 3);
    ASSERT_EQ(posicao(p, &d1), 1);

    adicionaNaPosicao(p, &d4, 3);
    ASSERT_EQ(p->_quantidade, 4);
    ASSERT_EQ(posicao(p, &d4), 3);
    ASSERT_EQ(posicao(p, &d3), 2);
    ASSERT_EQ(posicao(p, &d2), 4);
    ASSERT_EQ(posicao(p, &d1), 1);

    destroiListaEncadeada(p);
}

TEST(ListaEncadeadaTest, RetiraDoInicio)
{
    ListaEncadeada *p = iniciaListaEncadeada();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;

    int *r;

    adicionaNoInicio(p, &d3);
    adicionaNoInicio(p, &d2);
    adicionaNoInicio(p, &d1);

    r = (int *)retiraDoInicio(p);
    ASSERT_EQ(*r, d1);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(posicao(p, &d2), 1);
    ASSERT_EQ(posicao(p, &d3), 2);

    r = (int *)retiraDoInicio(p);
    ASSERT_EQ(*r, d2);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(posicao(p, &d3), 1);

    r = (int *)retiraDoInicio(p);
    ASSERT_EQ(*r, d3);
    ASSERT_EQ(p->_quantidade, 0);

    EXPECT_THROW(retiraDoInicio(p), lista_encadeada_vazia_exception);

    destroiListaEncadeada(p);
}

TEST(ListaEncadeadaTest, RetiraDaPosicao)
{

    ListaEncadeada *p = iniciaListaEncadeada();

    int d5 = 50;
    int d4 = 40;
    int d3 = 30;
    int d2 = 20;
    int d1 = 10;
    int *r;

    adicionaNoInicio(p, &d5);
    adicionaNoInicio(p, &d4);
    adicionaNoInicio(p, &d3);
    adicionaNoInicio(p, &d2);
    adicionaNoInicio(p, &d1);
    printaTudo(p);
    EXPECT_THROW(retiraDaPosicao(p, -1), posicao_invalida_exception);
    EXPECT_THROW(retiraDaPosicao(p, 0), posicao_invalida_exception);
    EXPECT_THROW(retiraDaPosicao(p, 6), posicao_invalida_exception);
    EXPECT_THROW(retiraDaPosicao(p, 7), posicao_invalida_exception);

    r = (int *)retiraDaPosicao(p, 5);
    printaTudo(p);
    ASSERT_EQ(*r, d5);
    ASSERT_EQ(p->_quantidade, 4);
    ASSERT_EQ(posicao(p, &d2), 2);

    r = (int *)retiraDaPosicao(p, 3);
    printaTudo(p);
    ASSERT_EQ(*r, d3);
    ASSERT_EQ(p->_quantidade, 3);
    ASSERT_EQ(posicao(p, &d4), 3);
    /*
    r = (int *)retiraDaPosicao(p, 2);
    ASSERT_EQ(*r, d2);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(posicao(p, &d4), 2);

    r = (int *)retiraDaPosicao(p, 1);
    ASSERT_EQ(*r, d1);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(posicao(p, &d4), 1);

    r = (int *)retiraDaPosicao(p, 1);
    ASSERT_EQ(*r, d4);
    ASSERT_EQ(p->_quantidade, 0);
    ASSERT_EQ(contem(p, &d4), false);

    destroiListaEncadeada(p);*/
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}