---
title: Função para MMC e Gerador de Gráficos em Setores
type: post
date: 2005-03-15T19:34:00+00:00
excerpt: Novos programinhas lógicos simples...
url: /2005/03/funcao-para-mmc-e-gerador-de-graficos-em-setores/
categorias:
  - Cotidiano
tags:
  - c
  - códigos
  - computação
  - gcd
  - gráficos
  - lcm
  - Matemática
  - mdc
  - mmc
  - programação

---
Baseando-me no programa **KBruch** (um joguinho educativo do KDE que serve pra somar e subtrair duas frações) resolvi fazer uma função que calculasse MMC (pra dar o resultado do KBruch bem rápido! Hehehe). A função recebe _dois argumentos_: o número de termos e os termos (num vetor) e ficou bem simpes (e eu até comentei). Vejam:

```c
//Função para calcular o MMC

#include <stdio.h>

int mmc(int *num, int ntermos) {
	int i, maior=0, a, j, c;

	//Descobrindo o maior número
	for (i=0; i<ntermos; i++) {
		if (num[i]>maior) {
			maior=num[i];
		}
	}

	for (i=1; c!=1; i++) {
		c=1;
		a=maior*i;
		//Verificando se o maior número vezes o i atual é divisível por todos números do conjunto
		for (j=0; j<ntermos; j++) {
			if (a%num[j]) {
				c=0;
			}
		}
	}

	return maior*(i-1); //Retornando resultado
}

int main() {
	int n[1001], nt, i;

	//Recebe número de termos
	printf("Quantos termos? ");
	scanf("%d", &nt);

	//Recebe números
	for (i=0; i<nt; i++) {
		printf("%d: ", i+1);
		scanf("%d", &n[i]);
	}

	//Chama a função e imprime o resultado
	printf("\nResultado: %d\n", mmc(n, nt));

	return 0;
}
```

Depois eu fiquei pensando que eu não estou calculando MMC como as pessoas calculam, então depois vou desenvolver uma outra função que calcule o MMC como as pessoas geralmente fazem, tipo assim:

<div>
  <h4>
    MMC como as pessoas fazem
  </h4>

  <ul>
    <li>
      4, 5 | 2
    </li>
    <li>
      2, 5 | 2
    </li>
    <li>
      1, 5 | 5
    </li>
    <li>
      1, 1 | /
    </li>
    <li>
      2 . 2 . 5 = 20
    </li>
  </ul>
</div>

**[update]** Já criei esse programa agora:

```c
//MMC do jeito que as pessoas tiram geralmente

#include <stdio.h>
int res[10000], co=0;

int mmc(int *n, int nt) {
	int i, k, dv, at;

	for (i=0; i<nt-1; i++) {
		printf("%d, ", n[i]);
	}
	printf("%d | ", n[nt-1]);

	dv=0;
	for (i=2; !dv&&at!=nt; i++) {
		dv=0;
		at=0;
		for (k=0; k<nt; k++) {
			if (!(n[k]%i)) {
				dv=1;
				n[k]/=i;
			} else if (n[k]==1) {
				at+=1;
			}
		}
		if (dv) {
			printf("%d\n", i);
			res[co++]=i--;
		}
	}

	if (at==nt) {
		return 1;
	} else {
		return i*mmc(n, nt);
	}
}

int main(void) {
	int n[1001], nt, i, resultado;

	printf("MMC - Mínimo Múltiplo Comum\n");
	printf("http://tableless.tiagomadeira.net/script/mmc-comum.c\n\n");

	printf("Este programa calcula o MMC de vários termos inteiros que você especifica.\n");
	printf("Foi criado por Tiago Madeira usando um algoritmo semelhante ao que os professores\n");
	printf("de matemática ensinam nas escolas.\n\n");

	printf("De quantos números você quer calcular o MMC? ");
	scanf("%d", &nt);
	for (i=0; i<nt; i++) {
		printf("Digite o %d. número: ", i+1);
		scanf("%d", &n[i]);
	}
	printf("\n");

	printf("Para você calcular o MMC de vários termos, basta você ir dividindo eles por primos\n");
	printf("até todos se tornarem o número 1 (um). O programa faz isto exatamente como você\n");
	printf("faria. Acompanhe o cálculo abaixo:\n\n");

	resultado=mmc(n, nt);
	printf("X\n\n", resultado);
	for (i=0; i<co-1; i++) {
		printf("%d . ", res[i]);
	}
	printf("%d = %d\n", res[co-1], resultado);

	printf("Ou seja, o menor número que é divisível por todos os números que você colocou é\n");
	printf("este. Isto tem grandes utilidades e uma delas (talvez a mais utilizada) é fazer\n");
	printf("cálculos com frações de denominadores diferentes.\n\n");

	printf("Observação: Este cálculo é a maneira com que as pessoas costumam aprender, mas\n");
	printf("desenvolvi um outro programa que (além de falar menos) tem um custo menor\n");
	printf("(calcula de forma mais rápida). Ele está disponível em\n");
	printf("http://tableless.tiagomadeira.net/script/mmc.c\n");

	return 0;
}
```

**[/update]**

Mas meu programa faz assim:

<div>
  <h4>
    MMC pelo meu programa
  </h4>

  <ul>
    <li>
      4, 5 - qual o maior? 5.
    </li>
    <li>
      5*2 é múltiplo de 4? Não.
    </li>
    <li>
      5*3 é múltiplo de 4? Não.
    </li>
    <li>
      5*4 é múltiplo de 4? Sim.
    </li>
    <li>
      MMC encontrado: 5*4=20.
    </li>
  </ul>
</div>

Mas com dois termos é bem simples (tem uma função para dois termos no programa do KBruch). O legal é que a minha função funciona com o número de termos que eu quiser. Vou demonstrar como ela funciona para três termos.

<div>
  <h4>
    MMC com três termos no meu programa
  </h4>

  <ul>
    <li>
      4, 5, 6 - qual é o maior? 6.
    </li>
    <li>
      6*2 é múltiplo de 4? Sim. Segue. É múltiplo de 5? Não. Para.
    </li>
    <li>
      6*3 é múltiplo de 4? Não. Para tudo.
    </li>
    <li>
      6*4 é múltiplo de 4? Sim. Segue. É múltiplo de 5? Não. Para.
    </li>
    <li>
      ...
    </li>
    <li>
      6*10 é múltiplo de 4? Sim. Segue. É múltiplo de 5? Sim.
    </li>
    <li>
      MMC encontrado: 6*10=60.
    </li>
  </ul>
</div>

Acho que fica mais simples de entender no método convencional mesmo...

<div>
  <h4>
    Método convencional - MMC de três termos
  </h4>

  <ul>
    <li>
      4, 5, 6 | 2
    </li>
    <li>
      2, 5, 3 | 2
    </li>
    <li>
      1, 5, 3 | 3
    </li>
    <li>
      1, 5, 1 | 5
    </li>
    <li>
      1, 1, 1 | /
    </li>
    <li>
      2 . 2 . 3 . 5 = 60
    </li>
  </ul>
</div>

E por causa disso, desenvolvi um programa que calcula da forma tradicional o MMC. É uma função recursiva. Ele é bem didático e mostra todo o raciocínio e algumas observações, porém o seu custo é maior (é mais demorado) que o primeiro.

Bom, nas aulas de matemática, andei desenvolvendo uns scripts muito úteis pra não precisar ficar calculando muito. Fiz um que calcula juros compostos, mas não publiquei. O que eu publiquei foi o que você digita o rótulo e o valor de cada pedaço de um gráfico de setores e ele devolve o número de graus que cada um deve ter (é uma simples regra de três, mas mesmo assim fiz pra brincar mesmo). Veja:

```c
//Gerador de Gráficos em Setores
#include <stdio.h>
#define NMAX 1001

int main() {
	int n, i;
	float valor[NMAX], vt;
	char rotulo[NMAX][50];

	printf("Qual o número de valores? ");
	scanf("%d", &n);

	vt=0;
	for (i=1; i<=n; i++) {
		printf("Rótulo (%2d): ", i);
		scanf("%s", rotulo[i]);
		printf("Valor  (%2d): ", i);
		scanf("%f", &valor[i]);
		vt+=valor[i];
	}

	printf("\nResultados:\n(graus que devem ser usados na confecção do gráfico)\n");
	for (i=1; i<=n; i++) {
		printf("%s: %.2f graus\n", rotulo[i], valor[i]*360/vt);
	}
}
```

Hmmm... Tirei um 5,8 em biologia numa prova sobre biomas (minha menor nota em três anos) :blink: e errei uma questão numa prova de física, justamente aquilo que eu tinha feito um programa, a força gravitacional. Eu esqueci de elevar a notação científica da distância ao quadrado e com isto, meu resultado na prova foi 1,27 . 10^22 ao invés de 1,27 . 10^32. Mas tudo bem...

