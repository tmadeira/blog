---
title: Coordenadas homogêneas
type: post
date: 2010-04-24T03:49:43+00:00
url: /2010/04/coordenadas-homogeneas/
categories:
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

**Coordenadas homogêneas?** A ideia parece simples (até demais) pra ser poderosa. Basicamente você representa uma coordenada em  <img src='https://s0.wp.com/latex.php?latex=%28X%2C+Y%29+%5Cin+%5Cmathbb%7BR%7D%5E2&bg=T&fg=000000&s=0' alt='(X, Y) \in \mathbb{R}^2' title='(X, Y) \in \mathbb{R}^2' class='latex' />com uma tripla ordenada  <img src='https://s0.wp.com/latex.php?latex=%5Bw%2C+x%2C+y%5D&bg=T&fg=000000&s=0' alt='[w, x, y]' title='[w, x, y]' class='latex' />tal que  <img src='https://s0.wp.com/latex.php?latex=x+%3D+%5Cfrac%7BX%7D%7Bw%7D&bg=T&fg=000000&s=0' alt='x = \frac{X}{w}' title='x = \frac{X}{w}' class='latex' />e <img src='https://s0.wp.com/latex.php?latex=y+%3D+%5Cfrac%7BY%7D%7Bw%7D&bg=T&fg=000000&s=0' alt='y = \frac{Y}{w}' title='y = \frac{Y}{w}' class='latex' />. A reta tem a mesma representação.

<pre lang="cpp" line="1">struct ponto {
	int w, x, y;
};

typedef ponto reta;
```

**E o que isso tem demais?** Você deixa de precisar de pontos flutuantes pra maioria das operações geométricas; ganha pontos no infinito (eles são a interseção entre retas paralelas!) que permitem fazer fórmulas sem preocupação com casos especiais, usar a mesma fórmula pra determinar uma reta gerada por dois pontos ou por um ponto e um vetor etc.; tem representações iguais (e dualidade) entre pontos e retas (e.g. interseção entre retas p e q = reta determinada por pontos p e q); e mais um monte de outras coisas.

**Uau! Como eu não ouvi falar disso antes?** Eu não sei a razão, mas, embora tenham várias vantagens, as coordenadas homogêneas não são muito populares na universidade, nem entre os maratonistas. No entanto, são usadas em projetos grandes que usam muita geometria (e.g. OpenGL).

**Quero código!** Vou mostrar como resolvi o problema _Symmetry_ ([2002 TopCoder Inv Round 4 – Division I, Level Three][2]).

_O enunciado é simples:_ Dados n (2  <img src='https://s0.wp.com/latex.php?latex=%5Cleq&bg=T&fg=000000&s=0' alt='\leq' title='\leq' class='latex' />n  <img src='https://s0.wp.com/latex.php?latex=%5Cleq&bg=T&fg=000000&s=0' alt='\leq' title='\leq' class='latex' />200) pontos inteiros (com coordenadas de -10000 a 10000) determinar quantas linhas de simetria existem entre eles.

Dá pra fazer em  <img src='https://s0.wp.com/latex.php?latex=O%28n%5E3%29&bg=T&fg=000000&s=0' alt='O(n^3)' title='O(n^3)' class='latex' />com a seguinte ideia:

  1. Crie uma árvore binária balanceada indexada por retas. (em C++, _map <reta,int>_)
  2. Para cada par de pontos, determine a reta de simetria entre eles e adicione 2 a essa reta na árvore binária. (<img src='https://s0.wp.com/latex.php?latex=O%28n%5E2+log+n%29&bg=T&fg=000000&s=0' alt='O(n^2 log n)' title='O(n^2 log n)' class='latex' />)
  3. Para cada reta na árvore binária, adicione 1 para cada ponto que pertence a essa reta. (<img src='https://s0.wp.com/latex.php?latex=O%28n%5E3%29&bg=T&fg=000000&s=0' alt='O(n^3)' title='O(n^3)' class='latex' />)
  4. É fácil ver que a reta é uma reta de simetria do conjunto de pontos se e somente se seu valor na árvore binária for <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />.

O problema geométrico está no segundo passo: determinar a reta de simetria entre dois pontos. Sejam esses pontos _p_ e _q_. É preciso:

  1. Determinar o ponto médio entre _p_ e _q_.
  2. Determinar a reta que passa por _p_ e _q_ (o enunciado garante que _p != q_).
  3. Determinar uma reta (ou um vetor) perpendicular à reta do passo acima.
  4. Determinar a reta que passa pelo ponto médio e tem a direção do vetor perpendicular do passo 3.

Determinar o ponto médio sem usar ponto flutuante seria trivial de qualquer forma (basta multiplicar todas as coordenadas por dois), mas com coordenadas homogêneas isso é desnecessário. É fácil ver que o ponto médio  <img src='https://s0.wp.com/latex.php?latex=m&bg=T&fg=000000&s=0' alt='m' title='m' class='latex' />entre  <img src='https://s0.wp.com/latex.php?latex=p+%3D+%5Bw_0%2C+x_0%2C+y_0%5D&bg=T&fg=000000&s=0' alt='p = [w_0, x_0, y_0]' title='p = [w_0, x_0, y_0]' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=q+%3D+%5Bw_1%2C+x_1%2C+y_1%5D&bg=T&fg=000000&s=0' alt='q = [w_1, x_1, y_1]' title='q = [w_1, x_1, y_1]' class='latex' />é:

<p style="text-align:center;">
  <img src='https://s0.wp.com/latex.php?latex=m+%3D+%5B+2+w_0+w_1+%2C+w_1+x_0+%2B+w_0+x_1+%2C+w_1+y_0+%2B+w_0+q_1+%5D&bg=T&fg=000000&s=0' alt='m = [ 2 w_0 w_1 , w_1 x_0 + w_0 x_1 , w_1 y_0 + w_0 q_1 ]' title='m = [ 2 w_0 w_1 , w_1 x_0 + w_0 x_1 , w_1 y_0 + w_0 q_1 ]' class='latex' />
</p>

<pre lang="cpp" line="1">ponto ponto_medio(ponto p, ponto q) {
	return (ponto) { 2*p.w*q.w, q.w*p.x+q.x*p.w, q.w*p.y+q.y*p.w };
}
```

Três pontos <img src='https://s0.wp.com/latex.php?latex=%5Bw_0%2C+x_0%2C+y_0%5D&bg=T&fg=000000&s=0' alt='[w_0, x_0, y_0]' title='[w_0, x_0, y_0]' class='latex' />, <img src='https://s0.wp.com/latex.php?latex=%5Bw_1%2C+x_1%2C+y_1%5D&bg=T&fg=000000&s=0' alt='[w_1, x_1, y_1]' title='[w_1, x_1, y_1]' class='latex' />,  <img src='https://s0.wp.com/latex.php?latex=%5Bw_2%2C+x_2%2C+y_2%5D&bg=T&fg=000000&s=0' alt='[w_2, x_2, y_2]' title='[w_2, x_2, y_2]' class='latex' />são colineares se

<p style="text-align:center;">
  <img src='https://s0.wp.com/latex.php?latex=+%5Cleft%7C+%5Cbegin%7Barray%7D%7Bccc%7D+w_0+%26+x_0+%26+y_0+%5C%5C+w_1+%26+x_1+%26+y_1+%5C%5C+w_2+%26+x_2+%26+y_2+%5Cend%7Barray%7D+%5Cright%7C+%3D+0+&bg=T&fg=000000&s=0' alt=' \left| \begin{array}{ccc} w_0 & x_0 & y_0 \\ w_1 & x_1 & y_1 \\ w_2 & x_2 & y_2 \end{array} \right| = 0 ' title=' \left| \begin{array}{ccc} w_0 & x_0 & y_0 \\ w_1 & x_1 & y_1 \\ w_2 & x_2 & y_2 \end{array} \right| = 0 ' class='latex' />,
</p>

o que nos permite concluir que a reta  <img src='https://s0.wp.com/latex.php?latex=r+%3D+%5Clangle+W%2C+X%2C+Y+%5Crangle&bg=T&fg=000000&s=0' alt='r = \langle W, X, Y \rangle' title='r = \langle W, X, Y \rangle' class='latex' />que passa por  <img src='https://s0.wp.com/latex.php?latex=p+%3D+%5B+w_0%2C+x_0%2C+y_0+%5D&bg=T&fg=000000&s=0' alt='p = [ w_0, x_0, y_0 ]' title='p = [ w_0, x_0, y_0 ]' class='latex' />e  <img src='https://s0.wp.com/latex.php?latex=q+%3D+%5B+w_1%2C+x_1%2C+y_1+%5D&bg=T&fg=000000&s=0' alt='q = [ w_1, x_1, y_1 ]' title='q = [ w_1, x_1, y_1 ]' class='latex' />é:

<p style="text-align:center;">
  <img src='https://s0.wp.com/latex.php?latex=r+%3D+%5Clangle+%2Bx_0+y_1+-+y_0+x_1%2C+-w_0+y_1+%2B+w_1+y_0%2C+w_0+x_1+-+w_1+x_0%5Crangle&bg=T&fg=000000&s=0' alt='r = \langle +x_0 y_1 - y_0 x_1, -w_0 y_1 + w_1 y_0, w_0 x_1 - w_1 x_0\rangle' title='r = \langle +x_0 y_1 - y_0 x_1, -w_0 y_1 + w_1 y_0, w_0 x_1 - w_1 x_0\rangle' class='latex' />.
</p>

<pre lang="cpp" line="1">ponto reta_determinada_por(ponto p, ponto q) {
	return (reta) { +p.x*q.y-q.x*p.y, -p.w*q.y+q.w*p.y, +p.w*q.x-q.w*p.x };
}
```

(um ponto  <img src='https://s0.wp.com/latex.php?latex=%5Bw%2C+x%2C+y%5D&bg=T&fg=000000&s=0' alt='[w, x, y]' title='[w, x, y]' class='latex' />pertence a  <img src='https://s0.wp.com/latex.php?latex=r&bg=T&fg=000000&s=0' alt='r' title='r' class='latex' />se <img src='https://s0.wp.com/latex.php?latex=Ww+%2B+Xx+%2B+Yy+%3D+0&bg=T&fg=000000&s=0' alt='Ww + Xx + Yy = 0' title='Ww + Xx + Yy = 0' class='latex' />)

<pre lang="cpp" line="1">int ponto_na_reta(ponto p, reta r) {
	return p.w*r.w + p.x*r.x + p.y*r.y == 0;
}
```

Agora a parte mais legal: a fórmula para determinar uma reta que passa por dois pontos funciona com pontos no infinito (pensemos em pontos no infinito como vetores, porque eles tem direção mas tem <img src='https://s0.wp.com/latex.php?latex=w+%3D+0&bg=T&fg=000000&s=0' alt='w = 0' title='w = 0' class='latex' />): o resultado é a reta determinada por um ponto e uma direção. O vetor perpendicular à reta  <img src='https://s0.wp.com/latex.php?latex=%5Clangle+W%2C+X%2C+Y+%5Crangle&bg=T&fg=000000&s=0' alt='\langle W, X, Y \rangle' title='\langle W, X, Y \rangle' class='latex' />é <img src='https://s0.wp.com/latex.php?latex=%5B+0%2C+X%2C+Y+%5D&bg=T&fg=000000&s=0' alt='[ 0, X, Y ]' title='[ 0, X, Y ]' class='latex' />.

<pre lang="cpp" line="1">ponto ponto_infinito_na_reta_perpendicular(reta r) {
	return (reta) { 0, r.x, r.y };
}
```

E isso é tudo. Agora basta criar uma representação única da reta pra guardar na árvore binária.

<pre lang="cpp" line="1">reta reformata_reta(reta r) {
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

<pre lang="cpp" line="1">int output = 0;
for (map <reta,int>::iterator i = M.begin(); i != M.end(); i++) {
	for (int j = 0; j < n; j++)
		if (ponto_na_reta(P[j], i->first))
			i->second++;
	if (i->second == n)
		output++;
}
```

O código completo ficou com umas 90 linhas com comentários e linhas em branco e foi aceito na primeira submissão (ok, na verdade na segunda, mas não foi devido à geometria muito menos à precisão): [symmetry.cpp][3]. Não é lindo?

 [1]: http://www.ic.unicamp.br/~stolfi/EXPORT/bibliography/stolfi.html
 [2]: http://www.topcoder.com/stat?c=problem_statement&pm=924
 [3]: http://blog.tiagomadeira.com/wp-content/uploads/2010/04/symmetry.cpp

