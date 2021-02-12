#ifndef NODO_H
#define NODO_H

#include "ListaEncadeada.h"
#include <stdlib.h>

template <typename T>
struct Nodo
{
	Nodo *_filhoEsquerda;
	Nodo *_filhoDireita;
	T *_dado;
};

//adiciona dado na arvore binaria de busca
template <typename T>
void adiciona(Nodo<T> *raiz, T *dado)
{
	Nodo<T> *novo = (Nodo<T> *)calloc(1, sizeof(Nodo<T>));
	novo->_dado = dado;
	if (raiz != NULL)
	{
		if (raiz->_dado == NULL)
			raiz->_dado = dado;
		else if (*dado < *raiz->_dado)
		{
			if (raiz->_filhoEsquerda == NULL)
				raiz->_filhoEsquerda = novo;
			else
				adiciona(raiz->_filhoEsquerda, dado);
		}
		else
		{
			if (raiz->_filhoDireita == NULL)
				raiz->_filhoDireita = novo;
			else
				adiciona(raiz->_filhoDireita, dado);
		}
	}
}

//cria uma lista com os nodos da arvore em preordem
template <typename T>
void preOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
	if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
	{
		adicionaNoFim(lista, raiz->_dado);
		preOrdem(raiz->_filhoEsquerda, lista);
		preOrdem(raiz->_filhoDireita, lista);
	}
}

//cria uma lista com os nodos da arvore em emOrdem
template <typename T>
void emOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
	if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
	{
		emOrdem(raiz->_filhoEsquerda, lista);
		adicionaNoFim(lista, raiz->_dado);
		emOrdem(raiz->_filhoDireita, lista);
	}
}

//cria uma lista com os nodos da arvore em posordem
template <typename T>
void posOrdem(Nodo<T> *raiz, ListaEncadeada *lista)
{
	if ((raiz != NULL || raiz != nullptr) && raiz->_dado != nullptr)
	{
		posOrdem(raiz->_filhoEsquerda, lista);
		posOrdem(raiz->_filhoDireita, lista);
		adicionaNoFim(lista, raiz->_dado);
	}
}

//NAO MODIFIQUE ESTA FUNCAO
template <typename T>
Nodo<T> *getNodo(Nodo<T> *raiz, T dado)
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

//remove o *proximo* nodo que contem um ponteiro para dado
template <typename T>
T *remover(Nodo<T> *raiz, T dado)
{

	Nodo<T> *deletar = getNodo(raiz, dado);
	if (deletar == nullptr)
	{
		printf("inexistente\n");
		return nullptr;
	}
	Nodo<T> *deletarPai = raiz;
	Nodo<T> *filho;
	Nodo<T> *pai;
	T *aux = deletar->_dado;

	while (deletar != nullptr && dado != *deletar->_dado)
	{
		deletarPai = deletar;
		if (dado < *deletar->_dado)
		{
			deletar = deletar->_filhoEsquerda;
		}
		else
		{
			deletar = deletar->_filhoDireita;
		}
	}
	printf("Achei o PAI\n");
	if (deletar->_filhoEsquerda != nullptr || deletar->_filhoDireita != nullptr)
	{
		printf("NAO E FOLHA\n");
		if (deletar->_filhoEsquerda == nullptr)
			filho = deletar->_filhoDireita;
		else
			filho = deletar->_filhoEsquerda;
	}
	else
	{
		pai = deletar;
		filho = deletar->_filhoDireita;
		while (filho->_filhoDireita != nullptr)
		{
			pai = filho;
			filho = filho->_filhoEsquerda;
		}
		if (pai != deletar)
		{
			pai->_filhoDireita = filho->_filhoEsquerda;
			filho->_filhoEsquerda = deletar->_filhoEsquerda;
		}
		filho->_filhoEsquerda = deletar->_filhoEsquerda;
	}
	if (!deletarPai)
	{
		free(deletar);
		return aux;
	}
	if (dado > *deletarPai->_dado)
		deletarPai->_filhoDireita = filho;
	else
		deletarPai->_filhoEsquerda = filho;
	free(deletar);
	return aux;
}

//desaloca todos os nodos da arvore
template <typename T>
void destruir(Nodo<T> *raiz)
{
	if (raiz->_filhoDireita != NULL)
		destruir(raiz->_filhoDireita);
	if (raiz->_filhoEsquerda != NULL)
		destruir(raiz->_filhoEsquerda);
	free(raiz);
}

#endif /* NODO_H */