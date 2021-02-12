#include "gtest/gtest.h"
#include "Pilha.h"

//extern "C" {
//#include "stack.h"
//}

TEST(PilhaTest, Init)
{
    Pilha *p = iniciaPilha();
    ASSERT_NE(p, nullptr);
    ASSERT_EQ(pilhaVazia(p), true);
    destroiPilha(p);
}

TEST(PilhaTest, PilhaVazia)
{
    Pilha *p = iniciaPilha();
    int d1 = 10;

    ASSERT_EQ(pilhaVazia(p), true);

    push(p, &d1);

    ASSERT_EQ(pilhaVazia(p), false);

    destroiPilha(p);
}

TEST(PilhaTest, Push)
{
    Pilha *p = iniciaPilha();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;

    push(p, &d1);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(contem(p, &d1), true);
    ASSERT_EQ(posicao(p, &d1), 1);

    push(p, &d2);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(contem(p, &d2), true);
    ASSERT_EQ(posicao(p, &d2), 1);
    ASSERT_EQ(posicao(p, &d1), 2);

    push(p, &d3);
    ASSERT_EQ(p->_quantidade, 3);
    ASSERT_EQ(contem(p, &d3), true);
    ASSERT_EQ(posicao(p, &d3), 1);
    ASSERT_EQ(posicao(p, &d2), 2);
    ASSERT_EQ(posicao(p, &d1), 3);

    destroiPilha(p);
}

TEST(PilhaTest, Pop)
{
    Pilha *p = iniciaPilha();
    int d1 = 10;
    int d2 = 20;
    int d3 = 30;

    int *r;

    push(p, &d3);
    push(p, &d2);
    push(p, &d1);

    r = (int *)pop(p);
    ASSERT_EQ(*r, d1);
    ASSERT_EQ(p->_quantidade, 2);
    ASSERT_EQ(posicao(p, &d2), 1);
    ASSERT_EQ(posicao(p, &d3), 2);

    r = (int *)pop(p);
    ASSERT_EQ(*r, d2);
    ASSERT_EQ(p->_quantidade, 1);
    ASSERT_EQ(posicao(p, &d3), 1);

    r = (int *)pop(p);
    ASSERT_EQ(*r, d3);
    ASSERT_EQ(p->_quantidade, 0);

    EXPECT_THROW(pop(p), lista_encadeada_vazia_exception);

    destroiPilha(p);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}