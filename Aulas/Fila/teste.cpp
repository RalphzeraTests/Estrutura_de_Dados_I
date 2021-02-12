#include "gtest/gtest.h"
#include "Fila.h"

//extern "C" {
//#include "stack.h"
//}

TEST(FilaTest, Init)
{
	Fila *p = iniciaFila();
	ASSERT_NE(p, nullptr);
	ASSERT_EQ(filaVazia(p), true);
	destroiFila(p);
}

TEST(FilaTest, Enqueue)
{
	Fila *p = iniciaFila();
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;

	enqueue(p, &d1);
	ASSERT_EQ(p->_quantidade, 1);
	ASSERT_EQ(filaVazia(p), false);
	ASSERT_EQ(contem(p, &d1), true);
	ASSERT_EQ(posicao(p, &d1), 1);

	enqueue(p, &d2);
	ASSERT_EQ(p->_quantidade, 2);
	ASSERT_EQ(filaVazia(p), false);
	ASSERT_EQ(contem(p, &d2), true);
	ASSERT_EQ(posicao(p, &d2), 2);
	ASSERT_EQ(posicao(p, &d1), 1);

	enqueue(p, &d3);
	ASSERT_EQ(p->_quantidade, 3);
	ASSERT_EQ(filaVazia(p), false);
	ASSERT_EQ(contem(p, &d3), true);
	ASSERT_EQ(posicao(p, &d3), 3);
	ASSERT_EQ(posicao(p, &d2), 2);
	ASSERT_EQ(posicao(p, &d1), 1);

	destroiFila(p);
}

TEST(FilaTest, Dequeue)
{
	Fila *p = iniciaFila();
	int d1 = 10;
	int d2 = 20;
	int d3 = 30;

	int *r;

	EXPECT_THROW(dequeue(p), fila_vazia_exception);

	enqueue(p, &d1);
	enqueue(p, &d2);
	enqueue(p, &d3);

	r = (int *)dequeue(p);
	ASSERT_EQ(*r, d1);
	ASSERT_EQ(p->_quantidade, 2);
	ASSERT_EQ(posicao(p, &d2), 1);
	ASSERT_EQ(posicao(p, &d3), 2);

	r = (int *)dequeue(p);
	ASSERT_EQ(*r, d2);
	ASSERT_EQ(p->_quantidade, 1);
	ASSERT_EQ(posicao(p, &d3), 1);

	r = (int *)dequeue(p);
	ASSERT_EQ(*r, d3);
	ASSERT_EQ(p->_quantidade, 0);
	ASSERT_EQ(filaVazia(p), true);

	EXPECT_THROW(dequeue(p), fila_vazia_exception);

	destroiFila(p);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}