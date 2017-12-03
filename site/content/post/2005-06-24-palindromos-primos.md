---
title: Palíndromos Primos
type: post
date: 2005-06-24T18:45:50+00:00
excerpt: Fiquei um bom tempo sem fazer o treinamento da USACO porque há algum tempo tinha parado no programa "Prime Palindromes", cujo objetivo é listar todos os palíndromos primos entre dois números (limites 5, 10.000.000). Agora consegui prosseguir com o treinamento!
url: /2005/06/palindromos-primos/
categories:
  - Cotidiano
tags:
  - algoritmos
  - c
  - códigos
  - computação
  - crivo de eratóstenes
  - palíndromos
  - primos
  - problemas
  - programação
  - usaco

---
Fiquei um bom tempo sem fazer o treinamento da USACO, porque há algum tempo tinha parado no programa **Prime Palindromes**, cujo objetivo é listar todos os palíndromos primos entre dois números (limites: 5, 10.000.000).

Esta demora aconteceu porque eu, além de ter ficado muito tempo sem entrar na USACO e já ter me esquecido do problema, estava testando todos os números, vendo se eles eram palíndromos, depois primos e então imprimia. Quando eu entrei na USACO essa semana (idéia do César Kawakami, que também vai pra UNICAMP mês que vem e foi um cara que também me ajudou nesse problema) vi que tinham **Hints** que eu nunca tinha visto antes. E elas diziam que eu devia **gerar** palíndromos. Com isso ficou fácil…

Eu ainda boiei um pouco, porque só depois eu descobri uma coisa lógica e muito simples (que eu nunca tinha pensado antes): **Para descobrir se um número N qualquer é primo, basta ver se ele é divisível pelos primos (no caso, eu usei todos os números, não só primos) de 2 a raiz de N.** Bom, isso é bem óbvio… Mas ninguém nunca tinha me dito e eu nunca tinha visto em lugar nenhum! Então tive que pensar (descobrir sozinho mesmo).

[<img src="https://i0.wp.com/farm1.staticflickr.com/15/21431632_24e1b61281.jpg?resize=500%2C282&ssl=1" alt="Prime Palindromes" data-recalc-dims="1" />][1]

Por preguiça de só fazer alguns **for** caso o mínimo fosse menor que X e maior que Y, meu programa, para qualquer caso, pega todos os palíndromos primos de 5 a 10000000! :blink: Eu não sabia se o tempo disso ia ser suficiente, então resolvi testar assim antes de fazer esses ifs antes do for e deu certo! Logo, nem precisa mais de nada… O tempo do meu programa para qualquer teste, no meu Linux, é 0,032 segundos. Na USACO apareceu como 0,05 segundos.

### Código-fonte

```c
//Prime Palindromes - USACO Training Gateway
//Tiago Madeira (c)

//Agora eu sei que dá pra fazer com custo bem menor,
//mas esse aí rolou na boa com 0.05 segundos.

/*
ID: contato1
PROG: pprime
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int eh_primo(long int num) {
	int i;

	for (i=3; i*i<=num; i+=2) {
		if (!(num%i)) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int i, j, k, l, cont=0;
	long int numero, min, max, v[10000];

	FILE *in=fopen("pprime.in", "r");
	FILE *out=fopen("pprime.out", "w");
	fscanf(in, "%d %d", &min, &max);
	fclose(in);

	v[cont++]=5;
	v[cont++]=7;
	for (i=1; i<=9; i+=2) {
		numero=i*10+i;
		if (eh_primo(numero)) {
			v[cont++]=numero;
		}
	}
	for (i=1; i<=9; i+=2) {
		for (j=0; j<=9; j++) {
			numero=i*100+j*10+i;
			if (eh_primo(numero)) {
				v[cont++]=numero;
			}
		}
	}
	for (i=1; i<=9; i+=2) {
		for (j=0; j<=9; j++) {
			for (k=0; k<=9; k++) {
				numero=i*10000+j*1000+k*100+j*10+i;
				if (eh_primo(numero)) {
					v[cont++]=numero;
				}
			}
		}
	}
	for (i=1; i<=9; i+=2) {
		if (i==5) {
			i=7;
		}
		for (j=0; j<=9; j++) {
			for (k=0; k<=9; k++) {
				for (l=0; l<=9; l++) {
					numero=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
					if (eh_primo(numero)) {
						v[cont++]=numero;
					}
				}
			}
		}
	}
	for (i=0; i<cont; i++) {
		if (v[i]>=min&&v[i]<=max) {
			fprintf(out, "%d\n", v[i]);
		} else if (v[i]>max) {
			fclose(out);
			return 0;
		}
	}
	fclose(out);
	return 0;
}
```

Agora vou prosseguir com o treinamento do USACO Training Gateway na seção 1.3, a começar pelo problema **Mixing Milk**.

[<img src="https://i2.wp.com/farm1.staticflickr.com/17/21435715_88e18b6959.jpg?resize=279%2C330&ssl=1" alt="O Homem que Calculava" data-recalc-dims="1" />][2]

Nos últimos dias não aconteceu nada demais. Só fiquei emocionado por ter recebido um 9,1 em biologia… :lol: E outra coisa legal também é que eu reli **O Homem que Calculava** e achei muito legal. Eu tinha lido na sexta série e acho que não tinha entendido direito tudo. O livro é muito bom e não é muito complicado não. O próximo que eu quero reler é **O Diabo dos Números**. Esse é mais “avançado” que o primeiro. Tô fazendo um trabalho de escola (de história) sobre (o filósofo) Pitágoras. É bem legal, o cara era muito bom. Na verdade, o trabalho tá virando de matemática, mas é bem interessante. É legal ter um professor de história que dá aula… ;) Não é igual ano passado, né? Tô achando bem legal os períodos da Grécia Antiga.

Ah, e vou finalizar citando um trecho d’**O Homem que Calculava** em homenagem ao Vavá, que não respira oxigênio… :D

<q>Conta-se que o famoso rei Salomão, para demonstrar a finura e a sabedoria de seu espírito, deu à sua noiva, a rainha de Sabá – a famosa Belquiss – uma caixa com 529 pérolas. Por que 529? <strong>Sabe-se</strong> que 529 é o quadrado de 23, isto é, 529 é igual a 23 multiplicado por 23. E 23 era, exatamente, a idade da rainha.</q>

 [1]: http://www.flickr.com/photos/tiago/21431632/ "Prime Palindromes por Tiago Madeira, no Flickr"
 [2]: http://www.flickr.com/photos/tiago/21435715/ "O Homem que Calculava por Tiago Madeira, no Flickr"
