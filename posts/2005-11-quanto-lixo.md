---
title: Quanto lixo!
date: 2005-11-29T13:27:11+00:00
excerpt: Impressionante a quantidade de besteiras que todo programador faz... Às vezes, uma semana depois de fazer um programa ou um site, eu já sinto raiva do script que acabei de fazer e me sinto obrigado a refazê-lo.
url: /2005/11/quanto-lixo/
tags:
  - aeroporto
  - batuíra
  - computação
  - dengue
  - grafos
  - obi
  - olimpíadas
  - problemas
  - programação
---

Impressionante a quantidade de besteiras que todo programador faz… Às vezes, uma semana depois de fazer um programa ou um site, eu já sinto raiva do script que acabei de fazer e me sinto obrigado a refazê-lo. Brincando um pouco nas férias, estou refazendo vários problemas da [OBI][1] e cada vez mais percebo a quantidade de lixo que achamos nos nossos scripts. E o pior é perceber o tempo que eu levava pra fazer aqueles problemas que podiam ser resolvidos de maneira tão simples (e eu pensava que tinha uma solução muito boa)… Estou resolvendo a lista de tarefas da modalidade **Programação Nível 2**, mas apenas os problemas de grafos (todos eles eu já tinha resolvido, mas estou agora programando-os melhor). Confiram as besteiras que eu fiz nos primeiros deles:

#### Aeroporto

[[enunciado]][2]

Um problema de grafos? **Não!** Mas parece muito. Na verdade, se ele pedisse qualquer coisa mais do que o grau de cada vértice eu precisaria de representar usando grafos, mas a única coisa que ele quer é que eu conte a quantidade de vezes que cada número aparece na entrada.

A primeira solução deste problema, que agora já não está mais entre nós, foi feita no curso de programação básica da OBI 2004, em Campinas, quando começava a aprender grafos. Pra vocês terem uma idéia do drama, eu fiz uma busca em profundidade pra contar o número de arestas que cada vértice tem (pra medir o grau de cada vértice).

Confiram a básica solução que fiz ontem: (e que daqui a algum tempo posso vir a achar ridícula também… hehehe)

```c
#include <stdio.h>
#define AMAX 101

int main() {
	int a, v, x, y, t[AMAX]; // t = tráfego, grau dos vértices
	int i, maior, teste=1;

	while (scanf("%d %d", &a, &v)&&a&&v) {
		maior=0;
		for (i=1; i<=a; i++) {
			t[i]=0;
		}
		for (i=0; i<v; i++) {
			scanf("%d %d", &x, &y);
			t[x]++;
			t[y]++;
			if (t[x]>maior) {
				maior=t[x];
			}
			if (t[y]>maior) {
				maior=t[y];
			}
		}
		printf("Teste %dn", teste++);
		for (i=1; i<=a; i++) {
			if (t[i]==maior) {
				printf("%d ", i);
			}
		}
		printf("bnn");
	}

	return 0;
}
```

#### Batuíra

[[enunciado]][3]

O objetivo é achar o caminho mínimo de peso de 1 a N. Uma simples busca em profundidade resolve o problema. Agora vejam a busca em profundidade que eu faria em 2004, que ainda não tirei da minha galeria de códigos: [batuira.c][4] e comparem com a que eu fiz ontem (e que ainda poderia ser melhorada):

```c
#include <stdio.h>
#include <values.h>
#define NMAX 101

int n, marc[NMAX], g[NMAX][NMAX];
int resultado;

void buscaemprofundidade(int v, int soma) {
	int w;

	if (v==n) {
		if (soma<resultado) {
			resultado=soma;
		}
	} else {
		marc[v]=1;
		for (w=1; w<=n; w++) {
			if (g[v][w]&&!marc[w]) {
				buscaemprofundidade(w, soma+g[v][w]);
			}
		}
	}
}

int main() {
	int x, y, xy;
	int i, j, teste=1;

	while (scanf("%d", &n)&&n) {
		resultado=MAXINT;
		for (i=1; i<=n; i++) {
			marc[i]=0;
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}
		while (scanf("%d %d %d", &x, &y, &xy)&&x&&y&&xy) {
			g[x][y]=xy;
			g[y][x]=xy;
		}
		buscaemprofundidade(1, 0);
		printf("Teste %dn%dnn", teste++, resultado);
	}

	return 0;
}
```

#### Dengue

[[enunciado]][5]

Esse foi com certeza meu maior susto. Foi por causa desse problema que eu resolvi escrever este artigo... Dá até vergonha de mostrar a [busca em profundidade][6] que usei para resolver o problema anteriormente. O objetivo do problema é descobrir partindo de que vértice do grafo o vértice que se encontra mais longe tem custo menor. Ou seja, é só fazer uma busca em largura com todos os vértices. Mas antigamente eu não simpatizava muito com a busca em largura, então fiz aquela besteira. E imaginem quanto tempo eu não levei pra fazer aquela joça... Bom... Pelo menos deve ter servido pra eu quebrar a cabeça naquela época! Vejam o código novo (sujeito a mudanças, é claro!):

```c
#include <stdio.h>
#include <values.h>
#define NMAX 101

int main() {
	int w, i, j, x, y, teste=1, g[NMAX][NMAX], n, d[NMAX], fim, ini, fila[NMAX], v, a, md[NMAX], c;

	while (scanf("%d", &n)&&n) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++) {
				g[i][j]=0;
			}
		}
		for (i=1; i<n; i++) {
			scanf("%d %d", &x, &y);
			g[x][y]=1;
			g[y][x]=1;
		}
		c=0;
		md[0]=MAXINT;
		for (v=1; v<=n; v++) {
			for (i=1; i<=n; i++) {
				d[i]=n;
			}
			md[v]=0;
			d[v]=0;
			ini=0;
			fim=0;
			fila[fim++]=v;
			while (ini!=fim) {
				a=fila[ini++];
				if (d[a]>md[v]) {
					md[v]=d[a];
				}
				for (w=1; w<=n; w++) {
					if (g[a][w]&&d[w]==n) {
						d[w]=d[a]+1;
						fila[fim++]=w;
					}
				}
			}
			if (md[v]<md[c]) {
				c=v;
			}
		}
		printf("Teste %dn%dnn", teste++, c);
	}

	return 0;
}
```

Bom... Simplificando... Se você não é programador, não seja; você vai ficar louco! :lol: Este problema que citei aqui não acontece só com esses problemas de olimpíadas mas também com vários scripts, principalmente os que vamos alterando com o tempo e adicionando novas _features_. Já recomecei do zero muitos sites para deixá-los decentes e muitos programas também (essa versão do aeroporto.c já é a terceira!) e não só esses de olimpíadas (o meu programa de ouvir música, em Bash, eu já fiz umas 10 vezes).

Quando eu acabar de re-resolver todos os problemas da seção de [códigos lógicos][7] eu vou publicar todos juntos. Por enquanto, vou deixar tudo do jeito que tá pra vocês apreciarem meus scripts mal-feitos. ;)

---

Quem costuma visitar meu blog perceberá que apareceu um ícone lá no canto inferior direito, escrito **Bom Demais para o IE**. A imagem, posicionada lá embaixo usando um _position:fixed;_ (que o IE não suporta) é de uma campanha muito legal que você pode conhecer clicando no link. Participem e tenham um site _"bom demais para o Internet Explorer"_! :)

[1]: http://olimpiada.ic.unicamp.br
[2]: http://olimpiada.ic.unicamp.br/programacao/tarefas/aeroporto
[3]: http://olimpiada.ic.unicamp.br/programacao/tarefas/batuira
[4]: /wp-content/uploads/c/batuira.c
[5]: http://olimpiada.ic.unicamp.br/programacao/tarefas/dengue
[6]: /wp-content/uploads/c/dengue.c
[7]: /wp-content/uploads/c/
