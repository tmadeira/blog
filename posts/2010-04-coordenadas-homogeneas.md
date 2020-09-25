---
title: Coordenadas homogêneas
type: post
date: 2010-04-24T03:49:43+00:00
url: /2010/04/coordenadas-homogeneas/
categorias:
  - Algoritmos geométricos
tags:
  - acm icpc
  - computação
  - coordenadas homogêneas
  - geometria
  - maratona
  - Matemática

---
Conheci as coordenadas homogêneas por acaso. Era 2004, ganhei a modalidade iniciação da Olimpíada Brasileira de Informática e passei o inverno estudando C, acho que por dois motivos: interesse pelos problemas da modalidade programação e desejo de aproveitar bem o curso que os medalhistas fazem na UNICAMP; ou talvez fosse apenas falta do que fazer ou curiosidade mesmo. Não importa.

Confundo os cursos de 2004, 2005 e 2006, mas lembro que no primeiro aprendi com um monitor sobre recursão, representação de grafos e busca em profundidade. Lembro também que foi em 2004 que conheci o <acronym title="Cormen, Leiserson, Rivest, Stein - Introduction to Algorithms">CLRS</acronym> (livro que comprei alguns meses depois e tenho na cabeceira até hoje). Esse post, porém, é sobre um acontecimento mais aleatório relacionado a esse curso e, ouso afirmar, digno de figurar n’**O Andar do Bêbado** do Mlodinow.

O pessoal da modalidade programação ia tirar cópias de um livro do Stolfi e do Rezende, chamado “Fundamentos de Geometria Computacional” ([dá pra baixar aqui][1]). Nem sabia do que estavam tirando xerox, mas vi que era barato e que todos os mais velhos estavam querendo, então também pedi.

Folheei o livro, não entendi nada, deixei num canto e voltei a abrir alguns anos depois, não lembro exatamente quando. E foi aí que fez-se a luz. A primeira parte é sobre coordenadas homogêneas.

**Coordenadas homogêneas?** A ideia parece simples (até demais) pra ser poderosa. Basicamente você representa uma coordenada em $(X, Y) \in \mathbb{R}^2$ com uma tripla ordenada $[w, x, y]$ tal que $x = \frac{X}{w}$ e $y = \frac{Y}{w}$. A reta tem a mesma representação.

```cpp
struct ponto {
	int w, x, y;
};

typedef ponto reta;
```

**E o que isso tem demais?** Você deixa de precisar de pontos flutuantes pra maioria das operações geométricas; ganha pontos no infinito (eles são a interseção entre retas paralelas!) que permitem fazer fórmulas sem preocupação com casos especiais, usar a mesma fórmula pra determinar uma reta gerada por dois pontos ou por um ponto e um vetor etc.; tem representações iguais (e dualidade) entre pontos e retas (e.g. interseção entre retas p e q = reta determinada por pontos p e q); e mais um monte de outras coisas.

**Uau! Como eu não ouvi falar disso antes?** Eu não sei a razão, mas, embora tenham várias vantagens, as coordenadas homogêneas não são muito populares na universidade, nem entre os maratonistas. No entanto, são usadas em projetos grandes que usam muita geometria (e.g. OpenGL).

**Quero código!** Vou mostrar como resolvi o problema _Symmetry_ ([2002 TopCoder Inv Round 4 – Division I, Level Three][2]).

_O enunciado é simples:_ Dados n ($2 \leq n \leq 200$) pontos inteiros (com coordenadas de -10000 a 10000) determinar quantas linhas de simetria existem entre eles.

Dá pra fazer em $O(n^3)$ com a seguinte ideia:

  1. Crie uma árvore binária balanceada indexada por retas. (em C++, _map <reta,int>_)
  2. Para cada par de pontos, determine a reta de simetria entre eles e adicione 2 a essa reta na árvore binária. ($O(n^2 log n)$)
  3. Para cada reta na árvore binária, adicione 1 para cada ponto que pertence a essa reta. ($O(n^3)$)
  4. É fácil ver que a reta é uma reta de simetria do conjunto de pontos se e somente se seu valor na árvore binária for $n$.

O problema geométrico está no segundo passo: determinar a reta de simetria entre dois pontos. Sejam esses pontos _p_ e _q_. É preciso:

  1. Determinar o ponto médio entre _p_ e _q_.
  2. Determinar a reta que passa por _p_ e _q_ (o enunciado garante que _p != q_).
  3. Determinar uma reta (ou um vetor) perpendicular à reta do passo acima.
  4. Determinar a reta que passa pelo ponto médio e tem a direção do vetor perpendicular do passo 3.

Determinar o ponto médio sem usar ponto flutuante seria trivial de qualquer forma (basta multiplicar todas as coordenadas por dois), mas com coordenadas homogêneas isso é desnecessário. É fácil ver que o ponto médio $m$ entre $p = [w_0, x_0, y_0]$ e $q = [w_1, x_1, y_1]$ é:

$$m = [ 2 w_0 w_1 , w_1 x_0 + w_0 x_1 , w_1 y_0 + w_0 q_1 ]$$

```cpp
ponto ponto_medio(ponto p, ponto q) {
	return (ponto) { 2*p.w*q.w, q.w*p.x+q.x*p.w, q.w*p.y+q.y*p.w };
}
```

Três pontos $[w_0, x_0, y_0]$, $[w_1, x_1, y_1]$, $[w_2, x_2, y_2]$ são colineares se

$$\left| \begin{array}{ccc} w_0 & x_0 & y_0 \\ w_1 & x_1 & y_1 \\ w_2 & x_2 & y_2 \end{array} \right| = 0$$

, o que nos permite concluir que a reta $r = \langle W, X, Y \rangle$ que passa por $p = [ w_0, x_0, y_0 ]$ e $q = [ w_1, x_1, y_1 ]$ é:

$$r = \langle +x_0 y_1 - y_0 x_1, -w_0 y_1 + w_1 y_0, w_0 x_1 - w_1 x_0\rangle$$

Logo:

```cpp
ponto reta_determinada_por(ponto p, ponto q) {
	return (reta) { +p.x*q.y-q.x*p.y, -p.w*q.y+q.w*p.y, +p.w*q.x-q.w*p.x };
}
```

(um ponto $[w, x, y]$ pertence a $r$ se $Ww + Xx + Yy = 0$)

```cpp
int ponto_na_reta(ponto p, reta r) {
	return p.w*r.w + p.x*r.x + p.y*r.y == 0;
}
```

Agora a parte mais legal: a fórmula para determinar uma reta que passa por dois pontos funciona com pontos no infinito (pensemos em pontos no infinito como vetores, porque eles tem direção mas tem $w = 0$): o resultado é a reta determinada por um ponto e uma direção. O vetor perpendicular à reta $\langle W, X, Y \rangle$ é $[ 0, X, Y ]$.

```cpp
ponto ponto_infinito_na_reta_perpendicular(reta r) {
	return (reta) { 0, r.x, r.y };
}
```

E isso é tudo. Agora basta criar uma representação única da reta pra guardar na árvore binária.

```cpp
reta reformata_reta(reta r) {
	if (r.w < 0) {
		r.w = -r.w;
		r.x = -r.x;
		r.y = -r.y;
	} else if (r.w == 0) {
		if (r.x < 0) {
			r.x = -r.x;
			r.y = -r.y;
		} else if (r.x == 0 && r.y < 0) {
			r.y = -r.y;
		}
	}
	int d = gcd(r.w, gcd(abs(r.x), abs(r.y)));
	return (reta) { r.w/d, r.x/d, r.y/d };
}
```

Usando essas funções, primeiro e segundo passos da solução são:

```cpp
map <reta,int> M;
for (int i = 0; i < n; i++) {
	for (int j = i+1; j < n; j++) {
		reta s = reformata_reta(reta_determinada_por(P[i], P[j]));
		ponto pm = ponto_medio(P[i], P[j]);
		ponto dir = ponto_infinito_na_reta_perpendicular(s);
		reta r = reformata_reta(reta_determinada_por(pm, dir));
		if (M.find(s) == M.end())
			M[s] = 0;
		if (M.find(r) == M.end())
			M[r] = 0;
		M[r]+= 2;
	}
}
```

Terceiro e o quarto são:

```cpp
int output = 0;
for (map <reta,int>::iterator i = M.begin(); i != M.end(); i++) {
	for (int j = 0; j < n; j++)
		if (ponto_na_reta(P[j], i->first))
			i->second++;
	if (i->second == n)
		output++;
}
```

O código completo ficou com umas 90 linhas com comentários e linhas em branco e foi aceito na primeira submissão (ok, na verdade na segunda, mas não foi devido à geometria muito menos à precisão): ~~symmetry.cpp~~ (infelizmente, esse arquivo foi perdido com o tempo). Não é lindo?

 [1]: http://www.ic.unicamp.br/~stolfi/EXPORT/bibliography/stolfi.html
 [2]: http://www.topcoder.com/stat?c=problem_statement&pm=924

