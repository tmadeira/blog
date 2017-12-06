---
title: Estatísticas, Programação Dinâmica, OBI Programação Nível 2
type: post
date: 2005-05-22T17:36:19+00:00
excerpt: Visitas do site crescendo, mas IE ainda na liderança; Solução dos problemas da OBI2005 Programação Nível 2 e comentários.
url: /2005/05/estatisticas-programacao-dinamica-obi-programacao-nivel-2/
categories:
  - Cotidiano
tags:
  - algoritmos
  - c
  - códigos
  - computação
  - estatiśtica
  - obi
  - obi 2005
  - programação
  - programação dinâmica

---
Em primeiro lugar, quero dar a notícia de que as visitas do site só tem crescido. Nesse mês, o site tem recebido 100 ips únicos por dia e uns 500 hits. Para um pequeno blog, são estatísticas boas. As palavras-chave mais procuradas e a posição do meu site na procura por ela no Google (somente em português) são:

  * **tableless** – sétima posição
  * **qemu** – décima-primeira posição
  * **problemas lógicos** – quarta posição
  * **dobradura** – décima-sexta posição
  * **gráfico de setores** – décima-oitava posição
  * **permutação** – sexta posição
  * **obi2005** – nona posição E **“obi 2005”** – terceira posição
  * **biografia de linus torvalds** – sexta posição emoticon

Ainda tem outras procuras interessantes e outras nada a ver, mas essas são as mais procuradas. É incrível como as pessoas clicam na minha biografia quando procuram pela biografia do criador do Linux! :blink: Acho legal as pessoas acharem meu site procurando por tableless, problemas lógicos, algoritmos, OBI2005 e nomes de problemas lógicos que eu fiz (também tem muita gente que procura por [MMC e MDC][1]).

Quanto a navegadores, o IE6 ainda tá dominando tudo. É uma pena que o pessoal use esse navegador pra entrar no meu site cujo um dos principais objetivos é apresentar os padrões web, tableless e faço de tudo pra acabar com o monopólio desse péssimo navegador e incentivar o software livre.

Por causa dos trabalhos, tenho programado muito em PHP, feito muitos designs no Fireworks (tô tendo que rebootar direto, porque desenho lá e depois venho pro Linux programar) e escrito XHTML/CSS. Alterei um pouco o programa ouvir (agora versão 1.1!). Ele já tá bem mais legalzinho do que aquela primeira versão que eu tinha postado e depois eu posto ele aqui.

Hmmm… Estive procurando umas coisas no **livro vermelho** (Algoritmos: Teoria e Prática) e descobri duas coisas desse livro.

  1. Ele tem tudo. É um livro completo, procura qualquer coisa de algoritmos ali que se acha tudo.
  2. É ilegível. :blink:

É muito complicado entender as coisas contidas nele, então tenho estudado um pouco por materiais na internet mais simples e só depois que peguei mesmo a coisa que leio no livro. Mas mesmo assim, bóio um pouco quanto a custos.

Por causa do problema **Mochila** (Pedido de Desculpas da OBI2005), acabei tentando aprender alguma coisa sobre **programação dinâmica**, mas não tô entendendo NADA! Só entendi o conceito e pra que serve, mas como fazer não sei. Não entendo como fazer as **recorrências** (e daí de repente, abro o índice do livro vermelho e acho lá um capítulo só sobre como fazer recorrências! – mas não entendo nada… :( )

Mas os outros problemas da OBI2005 Programação Nível 2 estão todos resolvidos! São bem fáceis. O único problema difícil do nível 2 da programação era esse de programação dinâmica mesmo… Publiquei eles na seção de scripts e vou fazer um pequeno comentário sobre cada um deles. Ah… E já que eu não peguei a prova de verdade (o Paulo Victor me passou um resumo dos problemas), não coloquei limites e saídas corretos.

### Bafo

Um programa ridículo, igual o Cofrinhos da Vó Vitória (que foi o primeiro programa da OBI que eu fiz, quando tava começando a aprender C).

**Solução:**

```c
//Bafo - OBI2005
#include <stdio.h>

int main() {
	int n, j1, j2, t1=0, t2=0, i, teste=1;

	while (scanf("%d", &n)&&n) {
		printf("Teste %d\n", teste++);
		t1=0;
		t2=0;
		for (i=1; i<=n; i++) {
			scanf("%d %d", &j1, &j2);
			t1+=j1;
			t2+=j2;
		}
		if (t1>t2) {
			printf("Aldo");
		} else {
			printf("Beto");
		}
		printf("\n\n");
	}
	return 0;
}
```

### Transmissão de Energia

Um programa de grafos que busca ver se o grafo é conexo ou não. Uma simples busca de profundidade resolve.

**Solução:**

```c
//Transmissão de Energia - OBI2005
#include <stdio.h>
#define NMAX 101

int g[NMAX][NMAX], achou[NMAX], n, achados;

void acha(int x) {
	int i;

	achou[x]=1;
	achados++;
	for (i=1; i<=n; i++) {
		if (g[x][i]&&!achou[i]) {
			g[x][i]=0;
			g[i][x]=0;
			acha(i);
		}
	}
}

int main() {
	int e, i, j, x, y, teste=1;

	while (scanf("%d %d", &n, &e)&&n) {
		achados=0;
		for (i=1; i<=n; i++) {
			achou[i]=0;
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}

		for (i=1; i<=e; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}

		acha(1);

		printf("Teste %d\n", teste++);
		if (achados==n) {
			printf("normal");
		} else {
			printf("falha");
		}
		printf("\n\n");
	}

	return 0;
}
```

### Vivo ou Morto

Um jogo de Vivo ou Morto bem fácil de fazer mas difícil de explicar.

**Solução:**

```c
//Vivo ou Morto - OBI2005
#include <stdio.h>
//Não sei qual o número máximo de jogadores!
#define NMAX 101

int main() {
	int jogador[NMAX], njogadores, nrodadas, i, j, k, vivos, ordem, fez;

	scanf("%d %d", &njogadores, &nrodadas);
	for (i=1; i<=njogadores; i++) {
		scanf("%d", &jogador[i]);
	}
	for (i=1; i<=nrodadas; i++) {
		scanf("%d %d", &vivos, &ordem);
		for (j=1; j<=vivos; j++) {
			scanf("%d", &fez);
			if (fez!=ordem) {
				jogador[j]=0;
			}
		}
		for (j=1; j<=vivos; j++) {
			if (!jogador[j]) {
				for (k=j; k<vivos; k++) {
					jogador[k]=jogador[k+1];
				}
			}
		}
	}
	printf("%d\n", jogador[1]);
}
```

### Mini-poker

Um jogo chato... :lol: Uma baita falta de criatividade. Um programa não-lógico onde são dadas cinco cartas e eu devo determinar a pontuação do cara...

**Solução:**

```c
//Mini-poker - OBI2005
#include <stdio.h>

int pontuacao(int c[]) {
	//Regra I
	if (c[1]==c[2]-1&&c[2]==c[3]-1&&c[3]==c[4]-1&&c[4]==c[5]-1) {
		return 200+c[1];
	}

	//Regra II
	if (c[1]==c[4]||c[2]==c[5]) {
		return 180+c[2];
	}

	//Regra III
	if ((c[1]==c[3]&&c[4]==c[5])||(c[3]==c[5]&&c[1]==c[2])) {
		return 160+c[3];
	}

	//Regra IV
	if (c[1]==c[3]||c[2]==c[4]||c[3]==c[5]) {
		return 140+c[3];
	}

	//Regra V
	if ((c[1]==c[2]&&c[4]==c[5])) {
		if (c[1]>c[4]) {
			return 3*c[1]+2*c[4]+20;
		} else {
			return 3*c[4]+2*c[1]+20;
		}
	}
	if ((c[1]==c[2]&&c[3]==c[4])) {
		if (c[1]>c[3]) {
			return 3*c[1]+2*c[3]+20;
		} else {
			return 3*c[3]+2*c[1]+20;
		}
	}
	if ((c[2]==c[3]&&c[4]==c[5])) {
		if (c[2]>c[4]) {
			return 3*c[2]+2*c[4]+20;
		} else {
			return 3*c[4]+2*c[2]+20;
		}
	}

	//Regra VI
	if (c[1]==c[2]||c[2]==c[3]) {
		return c[2];
	}
	if (c[3]==c[4]||c[4]==c[5]) {
		return c[4];
	}

	//Regra VII
	return 0;
}

int main() {
	int n, teste, c[6], carta, i, j;

	scanf("%d", &n);
	for (teste=1; teste<=n; teste++) {
		//Pega os valores e faz um Insertion Sort
		for (i=1; i<=5; i++) {
			scanf("%d", &carta);
			for (j=i-1; j>0&&c[j]>carta; j--) {
				c[j+1]=c[j];
			}
			c[j+1]=carta;
		}

		printf("Teste %d\n%d\n\n", teste, pontuacao(c));
	}

	return 0;
}
```

Saiu o gabarito da iniciação... Meu irmão, Lucas, acertou 14 no nível de quintas e sextas séries (ele tá na quinta) e ganhou **Menção Honrosa**. E o nosso, não vai sair não?

 [1]: /2005/04/desafios-logicos-e-sites/
