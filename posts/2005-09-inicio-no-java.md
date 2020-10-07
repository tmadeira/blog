---
title: Início no Java
date: 2005-09-27T19:26:03+00:00
excerpt: Nesse final de semana, comecei a estudar Programação Orientada a Objetos. Agora, seguindo o conselho do Zé, comecei a aprender Java.
url: /2005/09/inicio-no-java/
tags:
  - c
  - computação
  - java
  - programação
  - programação orientada a objetos
  - swing
---

Nesse final de semana, comecei a estudar **Programação Orientada a Objetos**. Eu nunca tinha experimentado essa maneira de programar e venho gostando bastante. :)

No início, fiz alguma coisa em C++; Depois mudei todo o sistema do meu blog para usar classes (ou “bibliotecas”, como o **hlegius** prefere, não sei porquê…) e agora então, por sugestão do **Zé**, comecei a aprender Java.

Acho que é uma excelente maneira de me aprofundar na orientação a objetos. Desde o início da minha apostila, estou me deparando com a POO; o Java é uma linguagem completamente orientada a objetos (tanto que é sempre o exemplo quando alguém fala dela).

Pelo pouco que programei até agora (comecei hoje), percebi quatro vantagens legais que o C não tinha:

1. Declaração de variáveis em qualquer lugar do documento. <small>O C++, o PHP e várias outras linguagens permitem isso também…</small>
2. Multi-plataforma. Linux, Windows, Mac, Solaris… O mesmo código roda em tudo! :) <small>C também roda em tudo, mas não exatamente da mesma maneira como o Java</small>
3. Desenvolvimento para web via applets.
4. Parece muito fácil criar interfaces gráficas. <small>Não sei se é mesmo, mas parece.</small>

Bom… Não entendi direito o negócio de **plataforma** Java, pra ser sincero… Mas ainda tô iniciando aí nesse mundo do Java e da POO. :)

E então, para finalizar fica um código de um exercício que eu fiz; o primeiro da primeira apostila (que inclusive eu já concluí a leitura):

#### Calcular a soma e a média de vários números, e ver o maior e o menor

```java
import javax.swing.JOptionPane;

/* Eu não precisava de array para esse programa, só usei porque
 * estou aprendendo Java então preciso me acostumar com arrays... */

class Exercicio {
import javax.swing.JOptionPane;

/* Eu não precisava de array para esse programa, só usei porque
 * estou aprendendo Java então preciso me acostumar com arrays... */

class Exercicio {
        public static void main(String args[]) {
                int n;
                String string;

                JOptionPane.showMessageDialog(null, "Olá. Esse programa serve pra calcular a soma e a média entre vários números, além de definir o maior e o menor deles.");
                JOptionPane.showMessageDialog(null, "Restrições:nn1. Só funciona com números entre -1.000.000 e 1.000.000.n2. Só funciona (a entrada e a saída) com números inteiros.");
                string=JOptionPane.showInputDialog("Você quer calcular a média entre quantos termos?");
                n=Integer.parseInt(string);

                int array[] = new int[n];
                int i, m, soma=0, maior=-1000000, menor=1000000;

                for (i=0; i<n; i++) {
                        m=i+1;
                        string=JOptionPane.showInputDialog("Digite o "+m+"o. número:");
                        array[i]=Integer.parseInt(string);
                        soma+=array[i];
                        if (array[i]>maior) {
                                maior=array[i];
                        }
                        if (array[i]<menor) {
                                menor=array[i];
                        }
                }

                int media=soma/n;

                JOptionPane.showMessageDialog(null, "A soma de todos os números é "+soma+".");
                JOptionPane.showMessageDialog(null, "A média de todos os números é "+media+".");
                JOptionPane.showMessageDialog(null, "O maior dos números é "+maior+".");
                JOptionPane.showMessageDialog(null, "O menor dos números é "+menor+".");
        }
}
```

No mais, nada de novo. Só pra registrar a data de meu início no Java. :D
