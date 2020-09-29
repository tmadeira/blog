---
title: "for (d=hoje; d<=17/03; d++) { Estude – OBI }"
type: post
date: 2007-01-24T13:33:13+00:00
url: /2007/01/for-arrays-c-obi/
categorias:
  - Cotidiano
tags:
  - c
  - computação
  - estudo
  - obi
  - obi 2007
  - olimpíadas
  - problemas
  - programação
  - treino
---

**IMPORTANTE:** Esse post não é recomendado pra quem nunca programou. Escrevi sem pensar neles… :-)

Bom… Existem pessoas que sabem programar e não programam. O difícil na arte de programar é pensar, porque o resto é escrever em inglês e se acostumar com uma sintaxe rigorosa.

Comecei ontem a ensinar um amigo a programar em C para participar da [OBI 2007][1], que foi anunciada nessa semana. Eu poderia ensinar Pascal, que é mais que suficiente para olimpíadas (quem conhece o André Linhares entende o que eu quero dizer…), mas resolvi ensinar C porque eu me embabacaria no Pascal e no C eu vejo os blocos mais “definidos” com as chaves; aqueles _begin_s e \_end_s “sujam” o código. E como diz o lema do [sistema desse blog][2], \_code is poetry_.

O [reverendo][3] e meus leitores mais novos devem estar se perguntando: como o Tiago é capaz de fazer essas loucuras? É verdade que fiquei um bom tempo sem escrever sobre programação, mas adoro isso! É lazer pra mim e essa também é a minha profissão, já que eu não consigo viver desse blog (por culpa sua que não clica nos meus anúncios…). Só quando começo a brincar é que lembro como é divertido e acho que é porque eu me sinto “no poder”. :-)

Mas voltando ao assunto… Esse meu colega é campeão regional de matemática e tem uma facilidade incrível para matérias exatas (e pras humanas mais ainda, eu acho). Eu estava sem nada pra escrever aqui no blog e resolvi escrever sobre o que eu vou ensinar pra ele amanhã: **arrays e for**.

Meu aluno está resolvendo a prova da Programação Nível 1 da OBI2005. Ele já resolveu a **Frota de Táxi** e agora precisa resolver o problema **Campos de Minhoca**.

O problema é que, pela primeira vez, ele se depara com uma situação em que tem que receber como entrada uma tabela completa! Sugeri que ele usasse dois _while_, um dentro do outro. Ele pensou um pouco e conseguiu fazer o seguinte código:

```c
scanf("%d %d", &n, &m);

natual=1;
while (natual<=n) {
	matual=1;
	while (matual<=m) {
		scanf("%d", &valor);
		matual=matual+1;
	}
	natual=natual+1;
}
```

Perfeito. Era o que eu queria que ele fizesse. Mas agora entenda sua situação: como armazenar todos esses números pra depois trabalhar com eles?

Dessa maneira, cada vez que recebemos um novo elemento da tabela, colocamos numa variável _valor_ e ao final do recebimento da entrada ficaremos apenas com o último elemento da tabela.

### E então entram os arrays...

Arrays são matrizes de matemática ou, numa língua muito mais fácil, _tabelas_. Vamos supôr que eu receba 1000 valores e queira saber qual é o maior deles. Imaginem como seria para declarar suas variáveis, recebê-los e tratá-los:

```c
int var1, var2, var3, var4, ..., var1000;

scanf("%d", &var1);
scanf("%d", &var2);
scanf("%d", &var3);
scanf("%d", &var4);
...
scanf("%d", &var1000);

if (var1>maior) {
	maior=var1;
}

if (var2>maior) {
	maior=var2;
}

if (var3>maior) {
	maior=var3;
}

...
```

Impossível! Totalmente inviável. Então alguém teve a brilhante idéia de criar um elemento que guarda várias variáveis de uma vez. Então surgiram os arrays. Você cria uma só variável e na sua declaração coloca o número de elementos que ele tem dentro de chaves.

```c
int var[1001];
```

Depois para receber os valores você pode então simplesmente usar o _while_ como usou no exemplo do **Campos de Minhoca**:

```c
int var[1001], indice;

indice=1;
while (indice<=1000) {
	scanf("%d", &var[indice]);
	indice=indice+1;
}
```

E para ver qual é o maior deles basta usar mais um **while**:

```c
indice=1;
while (indice<=1000) {
	if (var[indice]>maior) {
		maior=var[indice];
	}
}
```

Mas peraí... Então como faríamos no **Campos de Minhoca**? Lá não temos só uma lista de N números, mas uma tabela mesmo, com altura e largura. É simples, basta fazer com que cada índice dessa lista seja outra lista.

```c
int tabela[1001][1001];
```

Assim, podemos acessar todos os elementos e pra saber o elemento da coordenada **5, 23** basta usar a variável **tabela\[5\]\[23\]**.

Aí aquele primeiro código do **Campos de Minhoca** torna-se:

```c
scanf("%d %d", &n, &m);

natual=1;
while (natual<=n) {
	matual=1;
	while (matual<=m) {
		scanf("%d", &valor[natual][matual]);
		matual=matual+1;
	}
	natual=natual+1;
}
```

As variáveis [n,m]atual vão crescendo e preenchendo a tabela. :)

Só que acontece que se programássemos dessa maneira gastaríamos uma porção de códigos e ficaríamos confusos pra trabalhar com arrays, tendo que sempre verificar os índices e acabaríamos errando bastante. Então criou-se o **for**. O **for** é uma simplificação desse tipo de **while**. Você diz que:

```
para todo natual de 1 a n, faça:
	alguma coisa
fim-para
```

Escrever _for_ em Pascal é super divertido, porque você se sente falando com o computador:

```pascal
for i:=1 to 100, do begin
	código aqui
end;
```

No C existe uma sintaxe mais versátil, mas que pode ser um pouquinho mais difícil de entender no início:

```c
for (atribuição; condição; incremento)
```

A atribuição é onde você coloca o primeiro valor do índice. A condição é a condição para que o **enquanto** continue funcionando. O incremento é o que ele deve fazer ao final de cada _loop_ (geralmente é aumentar um).

Então, ao invés de fazer esse while:

```c
indice=1;
while (indice<=1000) {
	scanf("%d", &var[indice]);
	indice=indice+1;
}
```

Você pode escrever:

```c
for (indice=1; indice<=1000; indice=indice+1) {
	scanf("%d", &var[indice]);
}
```

E como resolver a parte da entrada do **Campos de Minhoca** sabendo disso?

Simples... Basta colocar um **for** dentro do outro:

```c
scanf("%d %d", &n, &m);

for (i=1; i<=n; i++) {
	for (j=1; j<=m; j++) {
		scanf("%d", &matriz[i][j]);
	}
}
```

**Observação 1:** Escrever **variavel++** é a mesma coisa que escrever **variavel=variavel+1**.

**Observação 2:** Geralmente utiliza-se **i** para o primeiro **for**, depois **j**, **k**, **l** e eu nunca tive que passar do **l**. :)

**Observação 3:** Se eu queria um vetor de 1000 posições lá em cima, por que eu declarei 1001? Bom... O C conta a partir de 0. Quando eu peço 1000, ele vai me dar um vetor de 0 a 999. Já que eu queria ter o var[1000] eu precisei declarar de 1000+1=1001.

Ficou claro ou muito confuso? Se deu pra entender isso aí, agora é só mandar a ver no resto do problema! :)

[1]: http://olimpiada.ic.unicamp.br/
[2]: http://wordpress.org/
[3]: http://1001gatos.org/
