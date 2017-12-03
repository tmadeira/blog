---
title: Script para baixar documentos do Issuu no GNU/Linux
type: post
date: 2014-09-26T15:50:33+00:00
url: /2014/09/script-para-baixar-documentos-do-issuu-no-gnulinux/
categories:
  - Códigos aleatórios
  - Dicas
  - Futilidades
  - Software Livre
tags:
  - bash
  - download
  - issuu
  - pdf
  - script
  - shell

---
Tive necessidade de baixar um documento do Issuu. Segue um _script_ simples que escrevi para baixar as páginas, convertê-las para PDF e mesclá-las. Ele não tem checagem de erros, mas pode ser útil para mais pessoas:

```bash
#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Uso: $0 <endereco_do_documento_no_issuu>"
    exit
fi

tmp=$(mktemp -d)

echo "Baixando pagina HTML..."
wget -q "$1" -O $tmp/html

pageCount=$(cat $tmp/html | grep -o '"pageCount":[0-9]*' | sed 's/.*://')
model=$(cat $tmp/html | grep 'image_src' | sed 's/.*href="//; s/".*//')
title=$(cat $tmp/html | grep '

<title>
  ' | sed 's/.*

  <title>
    //; s/<\/title>.*//')

    echo "-> Encontrado documento de $pageCount paginas"
    echo "-> Primeira pagina: $model"

    for i in $(seq 1 $pageCount); do
        download=$(echo $model | sed "s/page_1/page_$i/")
        echo "Baixando pagina ${i}..."
        wget -q "$download" -O "$tmp/page_${i}.jpg"
    done

    echo "Convertendo paginas JPG -> PDF..."
    for i in $(ls $tmp/*.jpg); do
        convert "$i" "${i}.pdf"
    done

    echo "Mesclando paginas..."
    gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile="${title}.pdf" $tmp/page_*.pdf
    rm -rf $tmp

    echo "-> Pronto: '${title}.pdf'"
```


    <p>
      O script requer Bash, wget, GhostScript e ImageMagick. A maioria das distribuições de Linux já tem esses aplicativos, mas por via das dúvidas cheque se você tem o ImageMagick instalado.
    </p>


    <p>
      <strong>Download do script:</strong> <a href="http://tiagomadeira.com/wp-content/uploads/2014/09/issuu_download.sh">issuu_download.sh</a> (932 bytes)
    </p>


    <p>
      Para instalar, é só baixar o arquivo, torná-lo executável e movê-lo para alguma pasta do seu $PATH:
    </p>


    ```
$ wget http://tiagomadeira.com/wp-content/uploads/2014/09/issuu_download.sh
$ chmod +x issuu_download.sh
$ sudo mv issuu_download.sh /bin
```


    <p>
      Para usar, é só digitar:
    </p>


    ```
$ issuu_download.sh <endereco_do_documento>
```

