---
title: Ordenação por Inserção
type: post
date: 2006-01-11T21:32:04+00:00
excerpt: Também conhecida como Insertion Sort, a Ordenação por Inserção consiste em inserir um elemento N num vetor já ordenado de N-1 elementos. Neste artigo, apresento-lhes este simples algoritmo para ordenação de vetores.
url: /2006/01/ordenacao-por-insercao/
ordem:
  - eeekk
categories:
  - Ordenação
tags:
  - algoritmos
  - análise de algoritmos
  - insertion sort
  - ordenação
  - ordenação por inserção
  - pior caso
  - pseudocódigos
  - vetores

---
Também conhecida como _Insertion Sort_, a **Ordenação por Inserção** consiste em inserir um elemento  <img src='https://s0.wp.com/latex.php?latex=n&bg=T&fg=000000&s=0' alt='n' title='n' class='latex' />num vetor já ordenado de  <img src='https://s0.wp.com/latex.php?latex=n-1&bg=T&fg=000000&s=0' alt='n-1' title='n-1' class='latex' />elementos. Neste artigo, apresento-lhes este simples algoritmo para **ordenação de vetores**.

O pseudocódigo da **ordenação por inserção** é o seguinte:

```
1. <strong>para</strong> <em>j</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> 2 <strong>até</strong> <em>comprimento do vetor</em>, <strong>faça</strong>
2.  <em>elemento</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[j]</em>
3.  <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>j</em> - 1
4.  <strong>enquanto</strong> <em>i</em> > 0 e <em>vetor[i]</em> > <em>elemento</em>, <strong>faça</strong>
5.      <em>vetor[i + 1]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>vetor[i]</em>
6.      <em>i</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>i</em> - 1
7.  <strong>fim-enquanto</strong>
8.  <em>vetor[i + 1]</em> <img src='https://s0.wp.com/latex.php?latex=%5Cleftarrow%7B%7D&bg=T&fg=000000&s=0' alt='\leftarrow{}' title='\leftarrow{}' class='latex' /> <em>elemento</em>
9. <strong>fim-para</strong>
```

Para explicar eu vou fazer uma coisa que sempre faço para corrigir meus algoritmos, fingir que sou o programa, executando cada passo manualmente (claro que geralmente faço mais rápido, porque não preciso escrever tudo que faço). Vamos iniciar com o seguinte vetor **v**.

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td class="preto">
      5
    </td>

    <td class="preto">
      3
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

Aí o código me manda começar com  <img src='https://s0.wp.com/latex.php?latex=j%3D2&bg=T&fg=000000&s=0' alt='j=2' title='j=2' class='latex' />e iterar até o comprimento do vetor (6). A primeira ordem que ele me dá é para armazenar o elemento  <img src='https://s0.wp.com/latex.php?latex=a%5Bj%5D&bg=T&fg=000000&s=0' alt='a[j]' title='a[j]' class='latex' />(<img src='https://s0.wp.com/latex.php?latex=a%5B2%5D&bg=T&fg=000000&s=0' alt='a[2]' title='a[2]' class='latex' />) na variável **elemento**. Para facilitar toda a explicação eu vou sempre pintar de cinza o  <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D&bg=T&fg=000000&s=0' alt='v[j]' title='v[j]' class='latex' />onde eu estou (no caso, o segundo elemento do vetor, 3) e de preto o vetor ainda não ordenado (elementos <img src='https://s0.wp.com/latex.php?latex=%5Cgeq%7B%7Dj&bg=T&fg=000000&s=0' alt='\geq{}j' title='\geq{}j' class='latex' />).

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td>
      5
    </td>

    <td class="cinza">
      3
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

Então ele me diz que <img src='https://s0.wp.com/latex.php?latex=i+%5Cleftarrow%7B%7D+j-1&bg=T&fg=000000&s=0' alt='i \leftarrow{} j-1' title='i \leftarrow{} j-1' class='latex' />. Portanto, <img src='https://s0.wp.com/latex.php?latex=i%3D1&bg=T&fg=000000&s=0' alt='i=1' title='i=1' class='latex' />. E agora ele me faz um **enquanto** (que poderia ser substituído por **para**) onde meu **i** deverá ir diminuindo. Vamos entrar no loop…

Bom, meu  <img src='https://s0.wp.com/latex.php?latex=i+%3D1&bg=T&fg=000000&s=0' alt='i =1' title='i =1' class='latex' />é maior que 0.  <img src='https://s0.wp.com/latex.php?latex=v%5B1%5D%3D5&bg=T&fg=000000&s=0' alt='v[1]=5' title='v[1]=5' class='latex' />é maior que o <img src='https://s0.wp.com/latex.php?latex=elemento%3D3&bg=T&fg=000000&s=0' alt='elemento=3' title='elemento=3' class='latex' />? Sim, então vamos entrar no corpo do **enquanto**… Aqui ele me manda fazer um <img src='https://s0.wp.com/latex.php?latex=vetor%5Bi%2B1%5D+%3D+vetor%5Bi%5D&bg=T&fg=000000&s=0' alt='vetor[i+1] = vetor[i]' title='vetor[i+1] = vetor[i]' class='latex' />, que nesse caso é fazer um <img src='https://s0.wp.com/latex.php?latex=v%5B2%5D%3Dv%5B1%5D%3D5&bg=T&fg=000000&s=0' alt='v[2]=v[1]=5' title='v[2]=v[1]=5' class='latex' />.

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td>
      5
    </td>

    <td class="cinza">
      5
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

E agora subtrae de **i** um valor. Portanto, <img src='https://s0.wp.com/latex.php?latex=i%3D0&bg=T&fg=000000&s=0' alt='i=0' title='i=0' class='latex' />. Ele retorna ao **enquanto**, mas agora não satisfazemos a condição <img src='https://s0.wp.com/latex.php?latex=i%3E0&bg=T&fg=000000&s=0' alt='i>0' title='i>0' class='latex' />, por isso saímos do **enquanto**. Então ele pede para  <img src='https://s0.wp.com/latex.php?latex=vetor%5Bi%2B1%5D%3Delemento&bg=T&fg=000000&s=0' alt='vetor[i+1]=elemento' title='vetor[i+1]=elemento' class='latex' />(<img src='https://s0.wp.com/latex.php?latex=v%5B1%5D%3Delemento&bg=T&fg=000000&s=0' alt='v[1]=elemento' title='v[1]=elemento' class='latex' />). Portanto, o vetor fica assim:

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td>
      3
    </td>

    <td>
      5
    </td>

    <td class="preto">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>

E incrementamos o **j**, agora <img src='https://s0.wp.com/latex.php?latex=j%3D3&bg=T&fg=000000&s=0' alt='j=3' title='j=3' class='latex' />.

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td>
      3
    </td>

    <td>
      5
    </td>

    <td class="cinza">
      7
    </td>

    <td class="preto">
      8
    </td>

    <td class="preto">
      2
    </td>

    <td class="preto">
      5
    </td>
  </tr>
</table>


<img src='https://s0.wp.com/latex.php?latex=elemento+%3D+7&bg=T&fg=000000&s=0' alt='elemento = 7' title='elemento = 7' class='latex' />
<img src='https://s0.wp.com/latex.php?latex=i+%3D+3-1+%3D+2&bg=T&fg=000000&s=0' alt='i = 3-1 = 2' title='i = 3-1 = 2' class='latex' />

 <img src='https://s0.wp.com/latex.php?latex=i+%3E+0&bg=T&fg=000000&s=0' alt='i > 0' title='i > 0' class='latex' />… E <img src='https://s0.wp.com/latex.php?latex=5+%3E+7&bg=T&fg=000000&s=0' alt='5 > 7' title='5 > 7' class='latex' />? Não! Portanto, não entramos no **enquanto**.

 <img src='https://s0.wp.com/latex.php?latex=v%5B3%5D+%3D+elemento&bg=T&fg=000000&s=0' alt='v[3] = elemento' title='v[3] = elemento' class='latex' />(nenhuma mudança)

E lá vamos para  <img src='https://s0.wp.com/latex.php?latex=j%3D4&bg=T&fg=000000&s=0' alt='j=4' title='j=4' class='latex' />e continuando até que vamos ter o vetor ordenado:

<table>
  <tr>
    <td>
      v[1]
    </td>

    <td>
      v[2]
    </td>

    <td>
      v[3]
    </td>

    <td>
      v[4]
    </td>

    <td>
      v[5]
    </td>

    <td>
      v[6]
    </td>
  </tr>

  <tr>
    <td>
      2
    </td>

    <td>
      3
    </td>

    <td>
      5
    </td>

    <td>
      5
    </td>

    <td>
      7
    </td>

    <td>
      8
    </td>
  </tr>
</table>

### Qual a lógica?

Como eu já disse na introdução, mas lá sem grandes explicações, a _Ordenação por Inserção_ divide o vetor em dois. O primeiro (de elementos  <img src='https://s0.wp.com/latex.php?latex=%3Cj%26%2391%3B%2Flatex%26%2393%3B%29+cont%C3%A9m+todos+seus+valores+ordenados+e+o+segundo+%28de+elementos+%26%2391%3Blatex%26%2393%3B%5Cgeq%7B%7Dj%26%2391%3B%2Flatex%26%2393%3B%29+cont%C3%A9m+os+valores+que+devem+ser+%3Cstrong%3Einseridos%3C%2Fstrong%3E+no+%3Cem%3Eprimeiro%3C%2Fem%3E+vetor+j%C3%A1+ordenado+%28por+isso+ele+se+chama+%3Cstrong%3EAlgoritmo+de+Inser%C3%A7%C3%A3o%3C%2Fstrong%3E%29.+++A+chave+do+algoritmo+%C3%A9+o+%3Cstrong%3Eenquanto%3C%2Fstrong%3E+que+acontece+para+ir+deslocando+todos+os+elementos+para+seu+%C3%ADndice+%5Blatex%5D%2B1&bg=T&fg=000000&s=0' alt='<j[/latex]) contém todos seus valores ordenados e o segundo (de elementos [latex]\geq{}j[/latex]) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>).   A chave do algoritmo é o <strong>enquanto</strong> que acontece para ir deslocando todos os elementos para seu índice [latex]+1' title='<j[/latex]) contém todos seus valores ordenados e o segundo (de elementos [latex]\geq{}j[/latex]) contém os valores que devem ser <strong>inseridos</strong> no <em>primeiro</em> vetor já ordenado (por isso ele se chama <strong>Algoritmo de Inserção</strong>).   A chave do algoritmo é o <strong>enquanto</strong> que acontece para ir deslocando todos os elementos para seu índice [latex]+1' class='latex' />enquanto o **elemento** for menor que eles (para depois o **elemento** ser colocado onde parou).

A variável **elemento** só serve para não perdermos o valor de  <img src='https://s0.wp.com/latex.php?latex=v%5Bj%5D&bg=T&fg=000000&s=0' alt='v[j]' title='v[j]' class='latex' />(porque depois fazemos  <img src='https://s0.wp.com/latex.php?latex=v%5Bi%2B1%5D%3Dv%5Bi%5D&bg=T&fg=000000&s=0' alt='v[i+1]=v[i]' title='v[i+1]=v[i]' class='latex' />quando <img src='https://s0.wp.com/latex.php?latex=i%3Dj-1&bg=T&fg=000000&s=0' alt='i=j-1' title='i=j-1' class='latex' />)

Acredito que não tenham restado dúvidas. Dê mais uma olhada no algoritmo e tente implementar. Se tiver dificulade, coloque mensagens de debug estratégicas para entender o algoritmo. (ex.: no início do **para** coloque para imprimir o valor de _j_ e no início de cada **enquanto** coloque para imprimir os valores **elemento**, **i** e **v[i]**)

### Custo

Você deve ter percebido que este algoritmo não tem um custo fixo. Se todo o vetor estiver ordenado, ele nunca precisará iterar o  <img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />e portanto será executado bem mais rápido do que se o vetor estiver inteiro em ordem decrescente (quando ele sempre precisará iterar  <img src='https://s0.wp.com/latex.php?latex=i&bg=T&fg=000000&s=0' alt='i' title='i' class='latex' />até o fim - 0). Então, neste artigo, gostaria-lhes de apresentar a análise de algoritmos baseada em casos. Para este programa, dizemos que:

  * **Melhor caso** é quando todos os elementos já estão ordenados. Custo: <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%29&bg=T&fg=000000&s=0' alt='\Theta{}(n)' title='\Theta{}(n)' class='latex' />
  * **Pior caso** é quando os elementos estão em ordem decrescente. Custo: <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2})' title='\Theta{}(n^{2})' class='latex' />

Em alguns programas o _caso médio_ é importante também, mas não é o caso da **ordenação por inserção**. Vemos que há uma diferença bem grande entre o custo dos dois casos. Por isso, precisamos conhecer onde que nosso algoritmo será implementado e quais as chances de ele ser o melhor ou pior caso. Em geral, o **pior caso** é o mais comum... Por isso, diremos que o custo deste algoritmo é <img src='https://s0.wp.com/latex.php?latex=%5CTheta%7B%7D%28n%5E%7B2%7D%29&bg=T&fg=000000&s=0' alt='\Theta{}(n^{2})' title='\Theta{}(n^{2})' class='latex' />.

