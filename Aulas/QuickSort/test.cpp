#include "gtest/gtest.h"
#include "AbstractSort.h"
#include <mutex>

//std::mutex g_singleThread;

TEST(InsertionSortTest, MelhorCaso)
{
  Elemento e0, e1, e2;
  e0._chave = 0;
  e1._chave = 1;
  e2._chave = 2;

  Elemento **vetor = inicializa(3);
  vetor[0] = &e0;
  vetor[1] = &e1;
  vetor[2] = &e2;

  //g_singleThread.lock();
  sort(vetor, 3);
  ASSERT_EQ(vetor[0]->_chave, 0);
  ASSERT_EQ(vetor[1]->_chave, 1);
  ASSERT_EQ(vetor[2]->_chave, 2);
  //g_singleThread.unlock();

  free(vetor);
}

TEST(InsertionSortTest, PiorCaso)
{
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
  ASSERT_EQ(vetor[0]->_chave, 1);
  ASSERT_EQ(vetor[1]->_chave, 2);
  ASSERT_EQ(vetor[2]->_chave, 3);
  ASSERT_EQ(vetor[3]->_chave, 4);
  ASSERT_EQ(vetor[4]->_chave, 5);
  //g_singleThread.unlock();

  free(vetor);
}

TEST(InsertionSortTest, CasoMedio)
{
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
  sort(vetor, 6);
  ASSERT_EQ(vetor[0]->_chave, 0);
  ASSERT_EQ(vetor[1]->_chave, 1);
  ASSERT_EQ(vetor[2]->_chave, 2);
  ASSERT_EQ(vetor[3]->_chave, 3);
  ASSERT_EQ(vetor[4]->_chave, 4);
  ASSERT_EQ(vetor[5]->_chave, 5);
  //g_singleThread.unlock();

  free(vetor);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}