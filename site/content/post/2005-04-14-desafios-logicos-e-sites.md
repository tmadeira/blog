---
title: Desafios Lógicos e Sites
type: post
date: 2005-04-14T21:55:52+00:00
excerpt: Nessa semana aconteceram tantas coisas que nem deu tempo de postar! Resumão...
url: /2005/04/desafios-logicos-e-sites/
categories:
  - Cotidiano
tags:
  - códigos
  - computação
  - desafios
  - gcd
  - lcm
  - lógica
  - Matemática
  - mdc
  - mmc
  - programação
  - sites
  - web

---
No Orkut, adicionei alguns caras que manjam de algoritmos, lógica, informática, Linux, ER, etc., como por exemplo [Aurélio Marinho Jargas][1], [Piter Punk][2] (Roberto Freires Batista), [Fábio Dias Moreira][3] e Helder Suzuki. E com isso, pra minha felicidade total, recebi dois desafios lógicos! (destes últimos dois) :D

#### Permutação

O primeiro é sobre permutação. O Helder leu meu post sobre permutações e sugeriu a criação de um programa que, sem fazer as operações anteriores, determinasse o n-ésimo elemento de uma permutação. Ainda não fiz porque tô atolado de coisas pra fazer, mas pensei que posso descobrir cada letra a partir do seguinte…

Vou supôr que tenho uma cadeia ABC, tamanho=3, letras=3

As permutações seriam feitas na seguinte ordem:

  1. a a a
  2. a a b
  3. a a c
  4. a b a
  5. a b b
  6. a b c
  7. a c a
  8. a c b
  9. a c c
 10. b a a
 11. b a b
 12. b a c
 13. b b a
 14. b b b
 15. b b c
 16. b c a
 17. b c b
 18. b c c
 19. c a a
 20. c a b
 21. c a c
 22. c b a
 23. c b b
 24. c b c
 25. c c a
 26. c c b
 27. c c c

A primeira letra se alterna a cada 9 (3^2) vezes. A segunda a cada 3 (3^1). A terceira 1 (3^0). Portanto, eu acho que consigo descobrir cada uma das letras! Vamos supor que quero o décimo primeiro elemento.

<div>
  <h4>
    11o. elemento
  </h4>

  <p>
    Está entre 10 e 18 – portanto a primeira letra é B
  </p>

  <p>
    Está entre 10 e 12 – portanto a segunda letra é A
  </p>

  <p>
    É 11 – A B C, A B C, A B C, A B!
  </p>
</div>

**BAB!**

Sabendo disso fica fácil… Demorei pra pensar nisso, mas agora vou escrever o algoritmo, implementar e vencer o desafio! :)

Bom, e além do desafio, o Helder me falou uma coisa que eu achei muito legal! O vestibular do ITA só tem português, inglês, matemática, física e química. Ou seja, as matérias que mais precisaria estudar (biologia principalmente e história e geografia) não existem! emoticon Ultimamente, estive pensando em que universidade vou entrar. Estou na dúvida entre ITA e Unicamp, mas acho que prestarei vestibular para as duas.

#### MMC/MDC

O segundo desafio foi do Fábio Dias Moreira. Na verdade, não foi bem um desafio, foi uma idéia sobre o post do MMC.

<div>
  <h4>
    E-mail dele
  </h4>

  <p>
    Eu li o seu post sobre cálculo de MMCs, e acho que você deveria tentar explorar as identidades a seguir:
  </p>

  <ul>
    <li>
      mmc(x, y) * mdc(x, y) = x * y
    </li>
    <li>
      mmc(mmc(x, y), z) = mmc(x, y, z)
    </li>
  </ul>

  <p>
    Como calcular mdc é uma tarefa simples (já que mdc(x, y) = mdc(x, y % x)), que leva tempo O(log x), a conta mdc(x_1, x_2, …, x_n) deve levar tempo O(n log x).
  </p>
</div>

Ainda não implementei tudo completamente, mas fiz alguns testes, que publiquei na seção de scripts.

### Calcula o Máximo Divisor Comum (MDC) de vários termos

```c
//MDC (Máximo Divisor Comum)
#include <stdio.h>
#include <values.h>

#define NMAX 101

int mdc(int *n, int tam) {
	int i, menor, desista, j;

	menor=MAXINT;
	for (i=0; i<tam; i++) {
		if (n[i]<menor) {
			menor=n[i];
		}
	}

	for (i=menor; i>=1; i--) {
		desista=0;
		for (j=0; j<tam; j++) {
			if (n[j]%i) {
				desista=1;
				j=tam;
			}
		}
		if (!desista) {
			return i;
		}
	}

}

int main() {
	int n[NMAX], tam, i;

	printf("Digite o número de termos: ");
	scanf("%d", &tam);
	for (i=0; i<tam; i++) {
		printf("%do. número: ", i+1);
		scanf("%d", &n[i]);
	}

	printf("MDC = %d\n", mdc(n,tam));
}
```

### Calcula o Máximo Divisor Comum (MDC) entre 2 termos

```c
//MDC (Máximo Divisor Comum) entre dois números
#include <stdio.h>

int mdc(int x, int y) {
	int i, menor;

	if (x<y) {
		menor=x;
	} else {
		menor=y;
	}

	for (i=menor; i>=1; i--) {
		if (!(x%i)&&!(y%i)) {
			return i;
		}
	}

	return 0;
}

int main() {
	int x, y;

	printf("Digite o primeiro número: ");
	scanf("%d", &x);
	printf("Digite o segundo número: ");
	scanf("%d", &y);

	printf("MDC ( %d , %d ) = %d\n", x, y, mdc(x,y));
}
```

### Calcula o Mínimo Múltiplo Comum (MMC) entre 2 termos

```c
//MMC - Mínimo Múltiplo Comum, para dois números

int mdc(int x, int y) {
	int i, menor;

	if (x<y) {
		menor=x;
	} else {
		menor=y;
	}

	for (i=menor; i>=1; i--) {
		if (!(x%i)&&!(y%i)) {
			return i;
		}
	}

	return 0;
}

int mmc(int x, int y) {
	return x*y/mdc(x,y);
}

int main() {
	int x, y;

	printf("Primeiro número: ");
	scanf("%d", &x);
	printf("Segundo número: ");
	scanf("%d", &y);

	printf("MMC (%d, %d): %d\n", x, y, mmc(x,y));
}
```

Tô chegando lá... Só falta fazer uma função que calcule o MMC dividindo em várias partes e fazendo vários MDCs. :p

#### Frações Egípcias

Bom, pra fazer eu pensar mais ainda, uma garota de 19 anos chamada Tatiane, que também leu o script do MMC, me enviou alguns e-mails sobre um algoritmo pra transformar frações próprias em frações egípcias. Só que o problema é que não pode usar funções, vetores, quase nada! Só pode usar os tipos char e int, e tem bastante regras que não deixam a pessoa sonhar muito. No fim, não consegui fazer, mas ela fez e parece que funcionou tudo certo. Em outro post, falarei mais sobre isso (depois que entender o algoritmo dela).

#### Meetweb

Hmmm... Uma empresa de construção de sites chamada MeetWeb me contratou pra programar para um site com um design já construído no Dreamwaver. Estou programando (PHP + Banco de dados MySql) e pretendo acabar em menos de 20 dias. Achei uma boa oferta, mesmo com uma pequena falta de tempo e o site exigir bastante coisinha de JavaScript (que eu não gosto muito - mas tô aproveitando pra aprender mais) e muita coisa repetida (o site é 100% administrável). É sempre bom pegar sites pra fazer, sempre acabo aprendendo mais alguma coisinha e um dinheirinho a mais sempre é bom também!

#### Site novo do Colégio

Esta semana comecei a fazer um site novo para o Colégio (o Salesiano, onde que eu estudo e trabalho), totalmente administrável também, com código válido e tableless, Flash... Uma coisa bem linda, leve e simples de administrar.

#### SOSPHP

Pra finalizar, o "meu" fórum, a SOSPHP tá com um movimento um pouco baixo e por isso tô fazendo um movimento para reanimá-lo. Então participem também! Entrem em www.sosphp.com.br e ajudem o fórum a crescer! Estou mandando mensagens para moderadores que estão sem visitar ultimamente, chamando mais gente e pedindo opiniões dos membros para melhorar o fórum (e é claro, pondo as opiniões em prática).

 [1]: http://aurelio.net
 [2]: http://piterpunk.hpg.ig.com.br
 [3]: http://dias.moreira.nom.br

