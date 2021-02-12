## Como fazer funcionar o gtest (Exemplo da Lista encadeada)

> Tudo aqui é feito no bash do linux, caso esteja no windows: https://www.youtube.com/watch?time_continue=1&v=xzgwDbe7foQ&feature=emb_title</br>
> Primeiro instale o libgtest-dev, siga as instruções neste vídeo: https://www.youtube.com/watch?v=kuglfQf17SA&ab_channel=srcmake</br>
> Caso apenas compile o programa usando a flag -lgtest não irá funcionar</br>

É possivel tabém compilar a partir dos arquivos baixados do moodle (que então vão conter mais de um arquivo .c ou .cpp). Neste caso faça o seguinte:

- $ `g++ *.c* -lgtest -lpthread -o out`
- $ ./out

---

# Sobre o WSL

Caso instale o WSL, em vez de abrir um prompt novo para cada coisa, recomendo usar o app da microsft Windows Terminal (https://www.microsoft.com/pt-br/p/windows-terminal/9n0dx20hk701?activetab=pivot:overviewtab).

## Modificando a aparência

Para usar o color scheme do Dracula substitua os trechos do seu arquivo de configuração do windows terminal pelos seguintes termos:

```javascript

"profiles": {
        "defaults": {
            "colorScheme": "Dracula"
        }


```

```javascript

"schemes": [
        {
          "name": "Dracula",
          "background": "#272935",
          "black": "#21222C",
          "blue": "#BD93F9",
          "cyan": "#8BE9FD",
          "foreground": "#F8F8F2",
          "green": "#50FA7B",
          "purple": "#FF79C6",
          "red": "#FF5555",
          "white": "#F8F8F2",
          "yellow": "#FFB86C",
          "brightBlack": "#6272A4",
          "brightBlue": "#D6ACFF",
          "brightCyan": "#A4FFFF",
          "brightGreen": "#69FF94",
          "brightPurple": "#FF92DF",
          "brightRed": "#FF6E6E",
          "brightWhite": "#F8F8F2",
          "brightYellow": "#FFFFA5"
        }
      ]

```

## Alias úteis

Primeiro entre no arquivo bashrc com o seguinte comando: `$ sudo nano /etc/bash.bashrc`.

Cole os aliases no FIM do arquivo

#### 1 - Usando diretórios do Windows

Como o wsl usa o bash do ubunto, ao tentar dar cd em um diretório do windows, irá dar errado por conta das barras invertidas, a função a seguir contorna este problema:

```bash

wincd()
{
        base=${PWD##Users/}
        dira=${1##$base}
        dira=${dira#/}
        cam="$(wslpath "$dira")"
        cam=${cam,,}
        base=${base,,}
        cam=${cam##$base/}
        cam=${cam##*mnt/c/}
        cd "$cam"
}

```

> Está um pouco feio e mal otimizado, mas quebra o galho kkkk

Para usar: `$ wincd "<CAMINHO>"`

#### 2 - Clear

Só porque eu tenho preguiça de digitar clear toda hora e fiquei mal acostumado com o cmd e powershel...

`alias cls="clear"`

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
