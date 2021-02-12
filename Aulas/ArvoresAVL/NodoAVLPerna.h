#ifndef NODOAVL_H
#define NODOAVL_H

#include "ListaEncadeada.h"
#include <stdlib.h>

template <typename T>
struct NodoAVL
{
	NodoAVL *_filhoEsquerda;
	NodoAVL *_filhoDireita;
	T *_dado;
	int _altura;
};

template <typename T>
int altura(NodoAVL<T> *subraiz)
{
	if (subraiz == nullptr)
		return -1;
	else
		return subraiz->_altura;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

template <typename T>
NodoAVL<T> *direita(NodoAVL<T> *raiz)
{
	NodoAVL<T> *filho;
	filho = raiz->_filhoEsquerda;
	raiz->_filhoEsquerda = filho->_filhoDireita;
	filho->_filhoDireita = raiz;
	raiz->_altura = max(altura(raiz->_filhoEsquerda), altura(raiz->_filhoDireita)) + 1;
	filho->_altura = max(altura(filho->_filhoEsquerda), raiz->_altura) + 1;
	return filho;
}

template <typename T>
NodoAVL<T> *esquerda(NodoAVL<T> *raiz)
{
	NodoAVL<T> *filho;
	filho = raiz->_filhoDireita;
	raiz->_filhoDireita = filho->_filhoEsquerda;
	filho->_filhoEsquerda = raiz;
	raiz->_altura = max(altura(raiz->_filhoDireita), altura(raiz->_filhoEsquerda)) + 1;
	filho->_altura = max(altura(filho->_filhoDireita), raiz->_altura) + 1;
	return filho;
}

template <typename T>
NodoAVL<T> *direitaEsquerda(NodoAVL<T> *raiz)
{
	raiz->_filhoDireita = direita(raiz->_filhoDireita);
	return (esquerda(raiz));
}

template <typename T>
NodoAVL<T> *esquerdaDireita(NodoAVL<T> *raiz)
{
	raiz->_filhoEsquerda = esquerda(raiz->_filhoEsquerda);
	return (direita(raiz));
}

template <typename T>
NodoAVL<T> *balancear(NodoAVL<T> *raiz, T *dado)
{
	int a = (altura(raiz->_filhoEsquerda) - altura(raiz->_filhoDireita));
	if (a > 1 || a < -1)
	{
		if (*dado < *raiz->_dado)
		{
			if (*dado < *raiz->_filhoEsquerda->_dado)
			{
				raiz = direita(raiz);
			}
			else
			{
				raiz = esquerdaDireita(raiz);
			}
		}
		else
		{
			if (*dado > *raiz->_filhoDireita->_dado)
			{
				raiz = esquerda(raiz);
			}
			else
			{
				raiz = direitaEsquerda(raiz);
			}
		}
	}
	return raiz;
}

template <typename T>
NodoAVL<T> *inserir(NodoAVL<T> *raiz, T *dado)
{
	if (raiz == nullptr)
	{
		raiz = (NodoAVL<T> *)calloc(1, sizeof(NodoAVL<T>));
		raiz->_dado = dado;
		raiz->_altura = 0;
		raiz->_filhoDireita = nullptr;
		raiz->_filhoEsquerda = nullptr;
		return raiz;
	}
	if (*dado < *raiz->_dado)
		raiz->_filhoEsquerda = inserir(raiz->_filhoEsquerda, dado);
	else
		raiz->_filhoDireita = inserir(raiz->_filhoDireita, dado);
	raiz = balancear(raiz, dado);
	raiz->_altura = max(altura(raiz->_filhoEsquerda), altura(raiz->_filhoDireita)) + 1;
	return raiz;
}

/**
 * @brief Adiciona um dado à árvore AVL
 * @param raiz ponteiro para raiz da árvore
 * @param dado ponteiro para dado a ser inserido
 * @return a raiz da árvore passada como parâmetro ou uma nova raiz caso houve rotação na raiz
 */
template <typename T>
NodoAVL<T> *adicionar(NodoAVL<T> *raiz, T *dado)
{
	if (raiz->_dado == nullptr)
	{
		raiz->_dado = dado;
		raiz->_altura = 0;
		raiz->_filhoDireita = nullptr;
		raiz->_filhoEsquerda = nullptr;
	}
	else
		raiz = inserir(raiz, dado);
	return raiz;
}

/**
 * @brief Percorre árvore AVL em pré-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pré-ordem
 */
template <typename T>
void preOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
	if (raiz != nullptr && raiz->_dado != nullptr)
	{
		adicionaNoFim(lista, raiz->_dado);
		preOrdem(raiz->_filhoEsquerda, lista);
		preOrdem(raiz->_filhoDireita, lista);
	}
}

/**
 * @brief Percorre árvore AVL em ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em ordem
 */
template <typename T>
void emOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
	if (raiz)
	{
		emOrdem(raiz->_filhoEsquerda, lista);
		adicionaNoFim(lista, raiz->_dado);
		emOrdem(raiz->_filhoDireita, lista);
	}
}

/**
 * @brief Percorre árvore AVL em pós-ordem
 * @param raiz ponteiro para raiz da árvore
 * @param lista lista onde os nodos da árvore serão inseridos em pós-ordem
 */
template <typename T>
void posOrdem(NodoAVL<T> *raiz, ListaEncadeada *lista)
{
	if (raiz)
	{
		posOrdem(raiz->_filhoEsquerda, lista);
		posOrdem(raiz->_filhoDireita, lista);
		adicionaNoFim(lista, raiz->_dado);
	}
}

//NAO MODIFIQUE A FUNCAO ABAIXO
template <typename T>
NodoAVL<T> *getNodo(NodoAVL<T> *raiz, T dado)
{
	while (raiz != NULL && dado != *raiz->_dado)
	{
		if (dado < *raiz->_dado)
		{
			raiz = raiz->_filhoEsquerda;
		}
		else
		{
			raiz = raiz->_filhoDireita;
		}
	}
	return raiz;
}

/**
 * @brief Remove um dado à árvore AVL
 * @param raiz ponteiro para raiz da árvore
 * @param dado dado a ser inserido
 * @return a raiz da árvore passada como parâmetro ou uma nova raiz caso houve rotação na raiz
 */
template <typename T>
NodoAVL<T> *remover(NodoAVL<T> *raiz, T dado)
{
	if (raiz == nullptr)
		return nullptr;
	NodoAVL<T> *lixo;
	if (dado < *raiz->_dado)
	{
		raiz->_filhoEsquerda = remover(raiz->_filhoEsquerda, dado);
	}
	else
	{
		if (dado > *raiz->_dado)
		{
			raiz->_filhoDireita = remover(raiz->_filhoDireita, dado);
		}
		else
		{
			if (raiz->_filhoDireita == nullptr || raiz->_filhoEsquerda == nullptr)
			{
				NodoAVL<T> *temp;
				if (raiz->_filhoDireita != nullptr)
					temp = raiz->_filhoDireita;
				else
				{
					temp = raiz->_filhoEsquerda;
				}
				if (temp == nullptr)
				{
					temp = raiz;
					raiz = nullptr;
				}
				else
					*raiz = *temp;
				free(temp);
			}
			else
			{
				NodoAVL<T> *temp;
				temp = raiz->_filhoDireita;
				while (temp->_filhoEsquerda != nullptr)
				{
					temp = temp->_filhoEsquerda;
				}
				raiz->_dado = temp->_dado;

				raiz->_filhoDireita = remover(raiz->_filhoDireita, *temp->_dado);
			}
		}
	}
	if (raiz == nullptr)
		return raiz;
	raiz->_altura = max(altura(raiz->_filhoEsquerda), altura(raiz->_filhoDireita)) + 1;
	raiz = balancear(raiz, &dado);
	return raiz;
}

/**
 * @brief Desaloca todos os nodos de uma árvore. Os dados não são desalocados.
 * @param raiz ponteiro para raiz da árvore
 */
template <typename T>
void destruir(NodoAVL<T> *raiz)
{
	if (raiz->_filhoEsquerda)
		destruir(raiz->_filhoEsquerda);
	if (raiz->_filhoDireita)
		destruir(raiz->_filhoDireita);
	free(raiz);
}

#endif /* NODOAVL_H */
