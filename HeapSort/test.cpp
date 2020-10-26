#include "gtest/gtest.h"
#include "AbstractSort.h"
#include <mutex>

//std::mutex g_singleThread;

TEST(HeapSortTest, MelhorCaso)
{
    Elemento e0, e1, e2;
    e0._chave = 0;
    e1._chave = 1;
    e2._chave = 2;

    Elemento **vetor = inicializa(3);
    vetor[0] = &e0;
    vetor[1] = &e1;
    vetor[2] = &e2;
    construirHeapMax(vetor, 3);
    sort(vetor, 3);
    ASSERT_EQ(getSwapsCount(), 4);

    free(vetor);
}

TEST(HeapSortTest, PiorCaso)
{ /*
    Elemento e0, e1, e2, e3, e4;
    e0._chave = 5;
    e1._chave = 4;
    e2._chave = 3;
    e3._chave = 1;
    e4._chave = 2;

    Elemento **vetor = inicializa(5);
    vetor[0] = &e0;
    vetor[1] = &e1;
    vetor[2] = &e2;
    vetor[3] = &e3;
    vetor[4] = &e4;

    //g_singleThread.lock();
    sort(vetor, 5);
    ASSERT_EQ(getSwapsCount(), 7);
    //g_singleThread.unlock();

    free(vetor);*/
}

TEST(HeapSortTest, CasoMedio)
{ /*
    Elemento e0, e1, e2, e3, e4, e5;
    e0._chave = 0;
    e1._chave = 1;
    e2._chave = 2;
    e3._chave = 5;
    e4._chave = 3;
    e5._chave = 4;

    Elemento **vetor = inicializa(6);
    vetor[0] = &e0;
    vetor[1] = &e1;
    vetor[2] = &e2;
    vetor[3] = &e3;
    vetor[4] = &e4;
    vetor[5] = &e5;

    //g_singleThread.lock();
    construirHeapMax(vetor, 6);
    sort(vetor, 6);
    ASSERT_EQ(getSwapsCount(), 14);
    //g_singleThread.unlock();

    free(vetor);*/
}

TEST(HeapSortTest, TesteLimites)
{ /*
    Elemento e0, e1, e2, e3, e4, e5;
    e0._chave = 0;
    e1._chave = 1;
    e2._chave = 2;
    e3._chave = 5;
    e4._chave = 3;
    e5._chave = 4;

    Elemento **vetor = inicializa(6);
    vetor[0] = &e0;
    vetor[1] = &e1;
    vetor[2] = &e2;
    vetor[3] = &e3;
    vetor[4] = &e4;
    vetor[5] = &e5;
    construirHeapMax(vetor, 6);

    EXPECT_THROW(max_heapify(vetor, 5, 5), posicao_invalida_exception);
    EXPECT_THROW(max_heapify(vetor, 5, 6), posicao_invalida_exception);
    EXPECT_THROW(max_heapify(vetor, 5, -1), posicao_invalida_exception);

    //ASSERT_EQ((sizeof(vetor)/sizeof(Elemento)),6);

    free(vetor);*/
}

TEST(HeapSortTest, testeTroca)
{ /*
    Elemento e0, e1, e2, e3, e4, e5, e6, e7, e8, e9;
    e0._chave = -1;
    e1._chave = 12;
    e2._chave = 11;
    e3._chave = 10;
    e4._chave = 1;
    e5._chave = 2;
    e6._chave = 9;
    e7._chave = 8;
    e8._chave = 7;
    e9._chave = 6;

    Elemento **vetor = inicializa(10);
    vetor[0] = &e0;
    vetor[1] = &e1;
    vetor[2] = &e2;
    vetor[3] = &e3;
    vetor[4] = &e4;
    vetor[5] = &e5;
    vetor[6] = &e6;
    vetor[7] = &e7;
    vetor[8] = &e8;
    vetor[9] = &e9;

    max_heapify(vetor, 10, 0);
    ASSERT_EQ(vetor[7]->_chave, -1);
    ASSERT_EQ(getSwapsCount(), 7);

    //g_singleThread.lock();
    //aplicando max heap no primeiro elemento

    //g_singleThread.unlock();

    free(vetor);*/
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}