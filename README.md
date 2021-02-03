

## Como fazer funcionar o gtest (Exemplo da Lista encadeada)

> Tudo aqui é feito no bash do linux, caso esteja no windows: https://www.youtube.com/watch?time_continue=1&v=xzgwDbe7foQ&feature=emb_title</br>
> Primeiro instale o libgtest-dev, siga as instruções neste vídeo: https://www.youtube.com/watch?v=kuglfQf17SA&ab_channel=srcmake</br>
> Caso apenas compile o programa usando a flag -lgtest não irá funcionar</br>

A biblioteca "gtest/gtest.h" tem que ser incluida em TODOS os arquivos (e só pode ter um .c ou .cpp, os seus codigos DEVEM estar em .h)
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


