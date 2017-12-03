---
title: Algoritmo de Permutação e Expressões Regulares
type: post
date: 2005-04-04T23:52:07+00:00
excerpt: Entre os problemas da minha lista de pendências, estava um algoritmo de permutação usando uma função recursiva...
url: /2005/04/algoritmo-de-permutacao-e-expressoes-regulares/
categories:
  - Cotidiano
tags:
  - algoritmos
  - computação
  - permutação
  - programação
  - regex

---
> #### permutar (dicionário Priberam)
>
> **permutar** | v. tr. | v. tr. e int.
>
> Conjugar

> do Lat. permutare
>
> v. tr.,

> dar reciprocamente;
>
> trocar uma coisa por outra;

> cambiar;
>
> v. tr. e int.,

> trocar reciprocamente os lugares.

Em matemática, estuda-se a análise combinatória apenas no segundo ano do Ensino Médio (sinceramente, acho isso tão errado quanto não ensinarem a fórmula de Heron ao invés de b.h/2), mas por ser muito útil nas olimpíadas de matemática, acabei aprendendo antes. A permutação que o meu programa faz é com elementos repetidos. Dando a ele um limite de números (naturais) e o número de algarismos de cada saída, ele imprime todas as possibilidades na tela.

#### Permutação

```c
#include <stdio .h>

#define NMAX 101 //Esta é uma constante que define o tamanho do vetor
#define NIVELMAX 5 //Esta constante define o número de níveis (número de caracteres numa permutação)
#define NUMEROS 2 //Esta constante define o número de números pelo qual a permutação passa.

int n[NMAX]; //Define o vetor "n" que contém os números pelo qual a permutação vai passando.

void permuta(int nivel) { //Inicia função que faz a permutação
        int i; //Define a variável i (contadora)

        if (nivel< =NIVELMAX) { //Se o nível for menor ou igual o nível
                for (i=1; i<=NUMEROS; i++) { //Laço para chamar uma função para cada valor diferente desse.
                        n[nivel]=i; //Define o número atual para i (o valor do laço)
                        permuta(nivel+1); //Chama a função (continua a recursão)
                } //Fim-para
        } else { //Senão
                //Imprime todas os números
                for (i=1; i<=NIVELMAX; i++) { //Laço para pegar os números de todas as funções
                        printf("%d", n[i]);
                } //Fim-para
                printf("n"); //Pula uma linha
        } //Fim-se
} //Fim da função

int main(void) { //Começa a função "main"
        int i; //Define a variável i (contadora)

        //Primeiro, zeramos o vetor "n" que contém os números que vão ser escritos.
        for (i=1; i<=NIVELMAX; i++) { //Laço
                n[i]=1;
        } //Fim-para

        //Chama a função com nível 1.
        permuta(1);
} //Fim-função
```

_Esse código tá tão comentado que tá até difícil de entender..._

O que você dá para o programa são as três constantes nas linhas 3, 4 e 5.

Gostei de fazer esse programa. Eu tive que pensar um pouco até na hora de escolher trabalhar com vetores, pois fazer permutações parece uma coisa mais simples mas é difícil. Fiz vários rascunhos de algoritmos no papel, mas aí só tá implementado em C. (eu nunca digito meus algoritmos... :blink: )

Comecei a estudar mais expressões regulares (para desenvolver um novo sistema de bbcodes e sintaxe colorida) e estou achando super legal. É um pouco complicado, mas tem muita lógica e tem muitas coisas úteis que dá pra fazer com elas, principalmente na construção de sites interativos em PHP. Estou lendo o livro do [Aurélio][1] que está disponível em [guia-er.sourceforge.net][2]. É muito bom! :)

Esse cara é um pouco maluco, mas o que ele faz com expressões regulares é muito legal! Desde setembro/2004, eu utilizo um programa em Bash dele chamado Funções ZZ. As funções ZZ são vários aplicativos simples que utilizam expressões regulares para facilitar tarefas do dia-a-dia. Por exemplo, o conceito de permutação que eu utilizei acima foi de um dicionário on-line das funções ZZ.

Consultando as estatísticas hoje, fiquei feliz ao ver meu blog citado em projetando.blogspot.com. Nunca sei se meus textos estão sendo compreendidos e por isso acho legal quando vejo que alguém _linkou_ para meu site.

 [1]: http://www.aurelio.net
 [2]: http://guia-er.sourceforge.net

