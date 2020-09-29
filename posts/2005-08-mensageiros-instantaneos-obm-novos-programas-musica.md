---
title: Mensageiros Instantâneos, OBM, Novos Programas, Música
type: post
date: 2005-08-26T18:51:52+00:00
excerpt: "Em primeiro lugar, venho comunicar que não uso mais MSN Messenger. Cheguei a conclusão de quem quer falar comigo deve usar o que eu uso e não ao contrário, por um motivo óbvio: o meu é melhor que o deles."
url: /2005/08/mensageiros-instantaneos-obm-novos-programas-musica/
categorias:
  - Cotidiano
tags:
  - algoritmos
  - c
  - centericq
  - centerim
  - códigos
  - computação
  - googletalk
  - icq
  - im
  - jabber
  - lcs
  - longest common subsequence
  - Matemática
  - obm
  - olimpíadas
  - pa
  - programação
  - programação dinâmica
  - sequências
---

Em primeiro lugar, venho por meio deste post comunicar que não uso mais **MSN Messenger**. O mensageiro instantâneo da Microsoft saiu da minha lista de contas do CenterICQ para a entrada de dois novos e melhores: IRC e GoogleTalk/Jabber. Cheguei a conclusão de que quem quer falar comigo deve usar o que eu uso e não ao contrário, por um motivo óbvio: o meu é melhor que o deles.

Esta decisão fez com que eu perdesse centenas de contatos, mas acho que foi a decisão certa a ser tomada. Quem quiser me contatar agora, pode me adicionar no ICQ como 147330555, GoogleTalk como tmadeira em gmail.com e no IRC/Freenode, como tiagomadeira.

O segundo ponto importante deste post é o _anúncio_ da OBM, Segunda Fase. A prova acontecerá no sábado que vem, dia 03 de setembro. Acho difícil eu conseguir medalha nesse ano (Terceira Fase é difícil!), mas vou tentar me esforçar o máximo possível… Esta semana tivemos o treino para olimpíadas com o Vavá, aprendi algumas coisas úteis. E ontem conversei com o César Kawakami no ICQ que me deu umas dicas interessantes também sobre **Teoria dos Números**. Vou tentar aprender alguma coisa sobre isso nos próximos dias…

As aulas de matemática dessa semana foram pouco produtivas porque eu andei faltando algumas para a divulgação do fórum do colégio. Então, só deu pra fazer dois problemas: a implementação da Máxima Subcadeia Comum (LCS/Programação Dinâmica):

```c
//LCS - Longest Common Subsequence
//Programação Dinâmica - MSC - Maior Subcadeia Comum

#include <stdio.h>
#define SMAX 1001
#define DIAGONAL 1
#define LADO 2
#define CIMA 3


//n = tamanho de x
//m = tamanho de y

int c[SMAX][SMAX], b[SMAX][SMAX], n, m;
char x[SMAX], y[SMAX];

int lcs_recupera(int i, int j) {
	if (i==0||j==0) {
		return 0;
	}
	if (b[i][j]==DIAGONAL) {
		lcs_recupera(i-1, j-1);
		printf("%c", x[i]);
	} else if (b[i][j]==CIMA) {
		lcs_recupera(i-1, j);
	} else {
		lcs_recupera(i, j-1);
	}
}

int main() {
	int i, j;


	printf("LCS - Longest Common Subsequence\nPor Tiago Madeira\n\n");
	printf("Digite o tamanho da string X: ");
	scanf("%d", &m);
	printf("Digite o tamanho da string Y: ");
	scanf("%d", &n);

	scanf("%*c");
	printf("Digite a string X: ");
	for (i=1; i<=m; i++) {
		scanf("%c", &x[i]);
		c[i][0]=0;
	}
	scanf("%*c");
	printf("Digite a string Y: ");
	for (i=1; i<=n; i++) {
		scanf("%c", &y[i]);
		c[0][i]=0;
	}

	printf("\nPrograma raciocinando...\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			if (x[i]==y[j]) {
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=DIAGONAL;
			} else {
				if (c[i][j-1]>c[i-1][j]) {
					c[i][j]=c[i][j-1];
					b[i][j]=LADO;
				} else {
					c[i][j]=c[i-1][j];
					b[i][j]=CIMA;
				}
			}
		}
	}

/*	printf("\nMATRIX C\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	printf("\nMATRIX B\n");
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
*/

	lcs_recupera(m, n);
	printf("\n");
}
```

e um programa bem ridículo para [calcular os termos e a soma de uma PA][1] (é o que o prof. tá ensinando, aí achei bom pra fazer os exercícios mais rápido...):

```c
//Aplicar as fórmulas das PAs

//Progressão Aritmética
//Programa desenvolvido por Tiago Madeira (c) 2005.

#include <stdio.h>
#define MAX 1000001

long double a[MAX], s[MAX];

int main() {
	long double r;
	int n;

	printf("Primeiro termo da PA: ");
	scanf("%Lf", &a[1]);
	printf("Razão da PA: ");
	scanf("%Lf", &r);

	//Eu podia fazer só pros que vão ser usados, mas não sei porquê, deu vontade de fazer assim... =)
	printf("\nAguarde o problema raciocinar tudo que ele tem para raciocinar...\n");
	for (n=2; n<MAX; n++) {
		a[n]=a[1]+r*(n-1);
		s[n]=(a[1]+a[n])*n/2;
	}

	printf("\nE agora, digite números para o programa dizer A e S dele.\n");
	do {
		printf("Número: ");
		scanf("%d", &n);
		if (!n) {
			break;
		}
		printf("Número na posição N = %.Lf\nSoma de 1 a N = %.Lf\n\n", a[n], s[n]);
	} while (n);

}
```

No começo do mês que vem é o Festival de Música de Itajaí. Acho que vou fazer oficina de Piano Popular avançado com o Prof. Michel Freidenson, que foi quem me deu aulas numa oficina semelhante há dois anos. A semana da música vai contar também com uns shows bem legais e o site oficial é [este aqui][2].

[1]: /script/pa.c
[2]: http://www.fundacaoculturaldeitajai.com.br
