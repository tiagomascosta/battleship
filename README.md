# Battleship

Projeto em C desenvolvido para a unidade curricular de Programacao, inspirado no jogo Battleship.

Este repositorio inclui duas variantes do programa:

- `wargame.c`: versao orientada a linha de comandos, com opcoes passadas por argumentos.
- `projeto.c`: versao interativa, criada como submissao adicional, em que o programa apresenta menus e pede as opcoes ao utilizador.

## Objetivo

O programa gera e/ou resolve tabuleiros de jogo com base em diferentes modos de jogo, posicionamento e disparo.

## Estrutura

- `wargame.c`: implementacao principal baseada em argumentos de consola.
- `projeto.c`: versao com interface textual interativa.
- `Guia de implementação.pdf`: descricao tecnica da logica interna e das principais decisoes de implementacao.
- `readme.txt`: nota curta que acompanha a submissao original.

## Compilacao

Pode compilar qualquer uma das variantes com `gcc`:

```bash
gcc -o wargame wargame.c
gcc -o projeto projeto.c -lm
```

## Como executar

### Variante por argumentos

```bash
./wargame -h
```

Opcoes principais:

- `-t`: dimensao do tabuleiro no formato `linhasxcolunas`
- `-j`: modo de jogo (`0`, `1` ou `2`)
- `-p`: modo de posicionamento (`1` ou `2`)
- `-d`: modo de disparo (`1` a `3`, usado no modo de jogo `2`)
- `-1` a `-8`: quantidade de pecas de cada tipo

Exemplos:

```bash
./wargame -t 9x9 -j 0 -p 1
./wargame -t 12x12 -j 1 -p 2 -1 2 -2 1 -3 1
./wargame -t 9x9 -j 2 -d 3 -1 1 -2 1 -3 1
```

### Variante interativa

```bash
./projeto
```

Nesta versao, o programa apresenta menus e pede ao utilizador a dimensao do tabuleiro e os modos pretendidos, sem obrigar ao uso de argumentos na linha de comandos.

## Modos de jogo

- `Modo 0`: gera e mostra o tabuleiro com as pecas posicionadas.
- `Modo 1`: permite ao jogador introduzir coordenadas e tentar descobrir todas as pecas.
- `Modo 2`: o computador executa disparos automaticamente segundo o modo de disparo escolhido.

## Modos de posicionamento e disparo

- `Posicionamento 1`: colocacao automatica das pecas segundo a logica definida no projeto.
- `Posicionamento 2`: colocacao automatica com escolha das quantidades de pecas por tipo.
- `Disparo 1`: selecao aleatoria de coordenadas sem repeticao.
- `Disparo 2` e `3`: percorrem submatrizes `3x3` segundo uma sequencia predefinida; o modo `3` marca zonas adjacentes a pecas descobertas para evitar tiros redundantes.

## Resumo tecnico

O programa trabalha sobre matrizes em memoria, sendo a principal indexada como `yx[y][x]`. A implementacao organiza o tabuleiro em blocos `3x3`, ideia que estrutura tanto o posicionamento de pecas como os modos de disparo automatico. O `Guia de implementação.pdf` detalha esta logica interna, incluindo o uso de matrizes auxiliares e flags para controlo de tentativas, repeticoes e validacao de jogadas.

## Notas

- As dimensoes validas do tabuleiro respeitam multiplos de `3`, com limites definidos no codigo.
- Existe uma nota na submissao original sobre uma restricao no uso do modo de disparo com os modos de jogo `0` e `1`, por potencial conflito com o script fornecido no contexto da disciplina.
- `projeto.c` inclui pequenos melhoramentos de apresentacao relativamente a `wargame.c`, mantendo a mesma base funcional.
