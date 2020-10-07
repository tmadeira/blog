---
title: O Jogo do Sete
date: 2005-02-13T19:08:01+00:00
excerpt: Meu professor de matemática Vavá me passou dois desafios lógicos. Um deles é muito interessante depois de se entender a lógica. Resolvi implementá-lo em C.
url: /2005/02/o-jogo-do-sete/
tags:
  - c
  - códigos
  - jogos
  - lógica
  - matemática
  - programação
---

Meu professor de matemática Vavá (não é o Fabiano, que me dá aula de manhã e também é muito bom mas explica as coisas muito devagar para toda a sala entender; mas o que eu me refiro é o que me ajuda a aprender coisas lógicas e quem geralmente me ensina coisas mais interessantes como números binários e números complexos no treinamento para olimpíadas de matemática – e, consequentemente, de informática) me passou dois desafios lógicos pelo MSN. Um deles é um problema muito interessante que, depois de entender a lógica (o algoritmo), resolvi implementar num programa em C (as cores só funcionam em bash :) E, pelo amor de Deus, espero que alguém que programe e se interesse por isso use Linux!).

```c
//Jogo do 7

#include <stdio.h>

int main() {
	int total, total2, recebido, enviado, i;

	total=0;
	i=1;
	printf("\n*** info: Jogo do Sete\n");
	printf("*** info: Desafio sugerido por Vavá.\n");
	printf("*** info: Algoritmo criado/implementado por Tiago Madeira.[0m\n\n");
	printf("*** info: REGRAS DO JOGO\n");
	printf("1. Na primeira jogada, o primeiro jogador escolhe um número no conjunto A={1,2,3,4,5,6,7} e diz.\n");
	printf("2. As pessoas jogam alternadamente.\n");
	printf("3. Cada pessoa ao jogar, escolhe um elemento de A, soma-o ao número dito pela pessoa anterior e diz.\n");
	printf("4. Ganha quem disser o número 63.\n\n");
	printf("Tiago fala: Você pode começar, mas se fizer besteira pode ter certeza de que eu ganharei! =)\n");
	printf("\n*** info: Início de jogo.\n");
	while (total<63) {
		printf("Você fala: ");
		scanf("%d", &total2);
		recebido=total2-total;
		if (recebido>7||recebido<1) {
			printf("Tiago fala: Seu ladrão! Não quero mais jogar com você! =(\n");
			break;
		}
		total=total2;
		if (total==63) {
			printf("*** info: Fim de jogo.\n*** info: Você ganhou.\n");
			printf("\nTiago fala: Muito bem. Apelou pois contra meu algoritmo é necessário, mas\nTiago fala: pelo menos parece ter entendido a lógica do jogo.\n");
			break;
		} else {
			enviado=(total+1)%8;
			if (enviado!=0) {
				total+=8-enviado;
			} else {
				if (i>7) {
					i=1;
				}
				total+=i;
				i+=2;
			}
			printf("Tiago fala: %d\n", total);
			if (total==63) {
				printf("*** info: Fim de jogo.\n*** info: Você perdeu.\n");
				printf("\nTiago fala: Eu já sabia... =D\n");
			}
		}
	}
	printf("\n");
}
```

Hmmm… O robô que joga contra a pessoa (Tiago) é como eu jogaria contra alguém que tivesse que ganhar. Se o cara vacilar, o Tiago ganha; mas se o cara entender a lógica (na verdade, dá pra não entender a lógica e ir somente indo de 8 em 8, mas vale a pena perder um tempinho entendendo a lógica) ele ganha facilmente pois é ele que começa. Assim como existe esse “Jogo do Sete”, estive pensando que pode dar certo com todos os números (alterando algumas coisas, é claro). Não vou explicar tudo aqui, mas não é muito difícil de entender; aliás, é bem simples. No começo tem as regras.

#### Google

Tenho olhado as estatísticas do site e tem cada vez mais pessoas entrando no Google (graças a Deus ele indexou minhas páginas internas – mas ainda não meus scripts lógicos), mas geralmente de assuntos que meu site não trata! Tipo, tem umas coisas que até tudo bem, como “problemas lógicos” (meu site é o primeiro da lista ao procurar por essas palavras – E, aliás, se você tá aqui por causa disso, sugiro a lista **maratona** do YahooGrupos!), mas algumas que aparecem porque possuem as palavras soltas no texto, como:

- **símbolo anéis de formatura** – Aparece meu site porque tem um post que tem “Senhor dos Anéis”, “Formatura” (da minha oitava série) e “Símbolos Matemáticos”
- **winrar código livre** – Hmmm… Código livre eu já citei várias vezes e Winrar eu falei para quem quiser descompactar o zip do Shortstat.
- **biografia de kevin mitnick** – Porque na minha biografia eu cito Kevin Mitnick

#### Início das Aulas

Hoje as aulas começaram. Minha banda tocou e foi legal (aula sem ter aula é legal! :D). Vou colocar umas fotos no Flickr…
