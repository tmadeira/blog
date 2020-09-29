---
title: Windows no Linux (Qemu e Wine)
type: post
date: 2005-03-12T18:10:44+00:00
excerpt: Neste fim de semana, andei tentando utilizar o QEMU e o Wine para usar aplicativos Windows no meu Slack 10.1 (que diga-se de passagem, é um sistema muiiiiiito melhor que esse troço que eu tive tanto trabalho pra emular). Qual a utilidade disso? Praticamente nenhuma, só pra aprender mesmo e "mesmo sem se livrar das drogas, pelo menos não precisar sair de casa pra usá-las".
url: /2005/03/windows-no-linux-qemu-e-wine/
categorias:
  - Cotidiano
tags:
  - c
  - códigos
  - emulação
  - linux
  - programação
  - qemu
  - virtualização
  - windows
  - wine
---

Neste fim de semana, andei tentando utilizar o QEMU e o Wine para usar aplicativos Windows no meu Slack 10.1 (que diga-se de passagem, é um sistema muiiiiiito melhor que esse troço que eu tive tanto trabalho pra emular). Qual a utilidade disso? Praticamente nenhuma, só pra aprender mesmo e poder ajudar novatos que não conseguem viver sem essa porcaria de sistema… Consegui instalar o Windows 98 numa partição virtual do QEMU e estou conseguindo rodar ele (e até compartilhei a internet). Já o Windows XP dá uns problemas (ele instala e roda perfeitamente mas depois quando eu vou bootar pela segunda vez dá problema). O ideal é o Windows 2000 que eu vou procurar pra instalar e vou ver o que tá acontecendo com o XP.

Coloquei vários screenshots no [Flickr][1].

No meio de tudo isso, ainda instalei o Wine e o Winetools e instalei algumas coisas como eMule, IE6, DOS, etc. O DOS não tem utilidade nenhuma, mas tudo bem… O IE6 é bom pra testar as páginas num browser ruim pra testar e o eMule é ótimo pra compartilhar arquivos.

O segundo “tópico” do final de semana são scripts bestas. Durante a semana (na verdade, durante as aulas) estou fazendo alguns scripts para facilitar fórmulas simples e coisas semelhantes. Criei um programa que faz a regra de três, mmc, etc. mas os únicos que achei dignos de colocar aqui são KBruch (calcula adição e subtração de frações, dá o resultado em fração mesmo perfeitamente):

```c
//Resolvendo o KBruch
//Termos: 2, Máximo denominador comum: 10, Operações: Adição/Subtração

#include <stdio.h>

int mmc(int a, int b) {
	int i, t, c=1;

	if (a>b) {
		t=b;
		b=a;
		a=t;
	}

	i=b;

	while (i%a) {
		i=b*c;
		c++;
	}

	return i;
}

int main() {
	int n1, d1, n2, d2, rn1, rn2, d, res, i;
	char sinal;

	while (scanf("%d/%d%c%d/%d", &n1, &d1, &sinal, &n2, &d2)) {
		//determinando denominador comum
		if (d1==d2) {
			rn1=n1;
			rn2=n2;
			if (n1==n2&&sinal=='-') {
				d=1;
			} else {
				d=d1;
			}
		} else {
			d=mmc(d1, d2);
			rn1=d/d1*n1;
			rn2=d/d2*n2;
		}
		//fazendo a conta
		if (sinal=='+') {
			res=rn1+rn2;
		} else {
			res=rn1-rn2;
		}

		//simplificando a fração
		for (i=2; i<=d; i++) {
			if (!(res%i)&&!(d%i)) {
				res/=i;
				d/=i;
				i=2;
			}
		}
		printf("Resultado: %d/%d\n\n", res, d);
	}
}
```

e Cálculo da Força da Gravidade, um programa muito útil pras aulas de física que economiza a mão calculando (já em notação científica) a fórmula F = G \* m1\*m2/d12^2:

```c
//Cálculo da Força da Gravidade

#include <stdio.h>

long double potencia(float base, int expoente) {
	long double res;
	int i;

	res=base;
	if (expoente==0) {
		return 1;
	} else {
		if (expoente>0) {
			for (i=1; i<expoente; i++) {
				res*=base;
			}
		} else {
			for (i=1; i>expoente; i--) {
				res/=base;
			}
		}
	}
	return res;
}

int main() {
	long double m1, m2, d12, resultado, g=6.7;
	int expoente;

	printf("---\n");
	printf("Cálculo da Força da Gravidade\n");
	printf("Programa escrito por Tiago Madeira para facilitar as aulas de física\n");
	printf("---\n\n");
	printf("m1\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &m1);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	m1*=potencia(10, expoente);
	printf("m2\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &m2);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	printf("%d\n", expoente);
	m2*=potencia(10, expoente);
	printf("d12\n");
	printf("Valor sem notação: ");
	scanf("%Lf", &d12);
	printf("Expoente do 10: ");
	scanf("%d", &expoente);
	d12*=potencia(10, expoente);

	resultado=g*((m1*m2)/(d12*d12));
	expoente=-11;

	while (resultado>10) {
		resultado/=10;
		expoente++;
	}

	while (resultado<0) {
		resultado*=10;
		expoente--;
	}
	printf("\n---\nResultado: %.2Lf . 10 ^ %d\n", resultado, expoente);

	return 0;
}
```

Esses programas são simples, mas exercitam um pouco a lógica (a função do MMC ficou bem legal no programa do kbruch, assim como a de potência pois o math.h não funciona aqui e também de notação científica no programa da gravidade. A coisa mais legal desses programas é que eu (e quem lê eles) percebe como eu penso pra fazer essas operações relativamente simples no dia-a-dia... :)

O programa do cálculo da força de gravidade é a primeira vez em que eu uso um double (é porque tem uns números muito grandes). ;)

Tá difícil programar e ler porque os livros da rede salesiana são bem puxados (na verdade, só o de biologia, mas os professores passam muita tarefa. Isso é um absurdo!), mas acabei de ler o "Capitães de Areia", que tava ótimo. Acho que durante as aulas, até tudo se regularizar, só vai dar pra postar final de semana mesmo... :lol:

[1]: http://www.flickr.com/photos/tiago
