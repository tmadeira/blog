---
title: Publicidade gratuita
type: post
date: 2007-02-08T13:50:39+00:00
url: /2007/02/publicidade-gratuita/
categorias:
  - Cotidiano
tags:
  - enem
  - expressões regulares
  - itajaí
  - lynx
  - mysql
  - php
  - salesiano
  - scripts
  - spider
  - web

---
Alguém _quase sem nada pra fazer_ resolveu mandar o Lynx baixar todas as médias do ENEM, rodou um programa em PHP com expressões regulares para separar os valores e agora apresenta-lhes a escola com a melhor média de Santa Catarina:

```
mysql> select id, nome, media from enem where estado='sc' order by media desc limit 40;
+-----+-------------------------------------------+-------+
| id  | nome                                      | media |
+-----+-------------------------------------------+-------+
| 185 | COLEGIO SALESIANO ITAJAI                  |  6456 |
| 821 | INST SUP E CENTRO EDUC LUTERANO BOM JESUS |  6435 |
| 140 | COLEGIO ENERGIA                           |  6295 |
|  49 | CENTRO EDUC ENERGIA TUBARAO SC LTDA       |  6209 |
|  87 | COLEGIO BOM JESUS DIOCESANO               |  6167 |
| 154 | COLEGIO HENRY FORD                        |  6144 |
| 193 | COLEGIO SAO BENTO                         |  6144 |
| 834 | SOCIEDADE EDUC POSIVILLE LTDA             |  6085 |
| 166 | COLEGIO MARISTA SAO LUIS                  |  6073 |
| 142 | COLEGIO ENERGIA                           |  6060 |
| 813 | EXATHUM CURSO E COLEGIO                   |  6034 |
| 116 | COLEGIO CORACAO DE JESUS                  |  5984 |
|  48 | CENTRO EDUC ENERGIA SC LTDA               |  5959 |
|  68 | CENTRO FEDERAL DE ED TECNOLOGICA DE SC    |  5936 |
| 173 | COLEGIO MURIALDO                          |  5909 |
| 115 | COLEGIO CONSUL CARLOS RENAUX              |  5899 |
| 206 | COLEGIO TENDENCIA                         |  5885 |
| 128 | COLEGIO DEHON                             |  5872 |
|  76 | COLEGIO ALTO VALE LTDA                    |  5861 |
|  88 | COLEGIO BOM JESUS STO ANTONIO             |  5852 |
| 365 | EEB FELICIANO NUNES PIRES                 |  5843 |
| 119 | COLEGIO DE APLICACAO DA UNC CACADOR       |  5831 |
| 150 | COLEGIO EXPONENCIAL                       |  5811 |
| 182 | COLEGIO RAINHA DO MUNDO                   |  5796 |
| 183 | COLEGIO SAGRADA FAMILIA                   |  5788 |
| 160 | COLEGIO MAFRENSE                          |  5779 |
|  96 | COLEGIO CENECISTA DR JULIO CESAR R NEVES  |  5777 |
| 210 | CONJ EDUC DR BLUMENAU                     |  5761 |
|  51 | CENTRO EDUC FRAIBURGO CEFRAI              |  5746 |
| 184 | COLEGIO SAGRADA FAMILIA                   |  5746 |
| 164 | COLEGIO MARISTA FREI ROGERIO              |  5724 |
|  69 | COLEGIO ADV DE  INDAIAL                   |  5721 |
| 196 | COLEGIO SAO LUIZ                          |  5720 |
| 159 | COLEGIO MADRE TERESA MICHEL               |  5719 |
| 801 | ESC BARAO DO RIO BRANCO                   |  5717 |
| 835 | SOCIEDADE EDUC VERDES MARES               |  5696 |
| 211 | COOPERATIVA EDUCACIONAL MAGNA             |  5688 |
| 133 | COLEGIO DOM JAIME CAMARA                  |  5683 |
| 139 | COLEGIO ELISA ANDREOLI                    |  5681 |
| 134 | COLEGIO DOS SANTOS ANJOS                  |  5673 |
+-----+-------------------------------------------+-------+
40 rows in set (0,00 sec)
```

A [melhor escola][1] possui também o melhor site, que deve ter sido feito por alguém **realmente muito bom**. ;)

 [1]: http://www.salesianoitajai.g12.br/

