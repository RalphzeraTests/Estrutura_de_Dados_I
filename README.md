

## Como fazer funcionar o gtest (Exemplo da Lista encadeada)

> Tudo aqui é feito no bash do linux, caso esteja no windows: https://www.youtube.com/watch?time_continue=1&v=xzgwDbe7foQ&feature=emb_title</br>
> Primeiro instale o libgtest-dev, siga as instruções neste vídeo: https://www.youtube.com/watch?v=kuglfQf17SA&ab_channel=srcmake</br>
> Caso apenas compile o programa usando a flag -lgtest não irá funcionar</br>

A biblioteca "gtest/gtest.h" tem que ser incluida em TODOS os arquivos
- $ g++ teste.cpp -lgtest -lpthread -o out</br>
- $ ./out</br>


    Assim o seu programa será compilado e será possivel rodá-lo.
    Contudo, não consegui manter a implementação dos métodos da ListaEncadeada em um arquivo separado, por isso mantive dentro do ListaEncadeada.h, mas para questões de testes funciona, já que no moodle é possível matê-las separadas.

---
# Exercícios Feitos

## Racionais

Criei pra testar o gtest, mas não funcionou então eu desisti. (consegui na lista)
    
   
## Lista Encadeada

    Código para fazer os testes, ja que no moodle é impossivel...

### Arquivos

.</br>
├── ListaEncadeada</br>
│   ├── Elemento.h</br>
│   ├── ListaEncadeada.h</br>
│   ├── ListaEncadeadaTeste.cpp</br>
│   ├── lista.exe</br>
│   └── teste.cpp</br>

### Observação

eu estava tendo um erro no qual quando eu criava um novo ponteiro, ele era igual a outro .sim isso não faz sentido, mas observe :

```
void adicionaNoInicio(ListaEncadeada *umaLista, void *umDado)
{
    printf("   - adicionando no inicio    |  endereço da Lista: %p\n", umaLista);
    printf("   umDado: %p\n", umDado);
    printf("Antigo primeiro da lista: %p\n", umaLista->_primeiro);
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    printf("Endereço do novo elemento: %p\n", el);
    el->_dado = umDado;
    el->_proximo = umaLista->_primeiro;
    umaLista->_primeiro = el;

    umaLista->_quantidade = umaLista->_quantidade + 1;
}
```

Este é o código do adiciona no inicio, e como pode ver, ele printa o valor do endereço de memória da lista, do antigo primeiro da lista, o dado ser alocaado no elemento e do novo elemento que eu criei.

MAS, quando eu rodo recebo isso:

![alt text](https://cdn.discordapp.com/attachments/704406974175117344/755171077449318400/unknown.png)
    
O endereço da lista, o primeiro elemento dele E O NOVO ELEMENTO QUE EU CRIEI estão com o MESMO endereço de memória, o que simplesmente não faz sentido...

Depois de dias inteiros depurando o código, pedi para um amigo compilar na máquina dele:

![alt text](https://cdn.discordapp.com/attachments/704406974175117344/755169090871492639/unknown.png)
E como pode ver, funcionou... Qual o sentido disso? eu não sei.
