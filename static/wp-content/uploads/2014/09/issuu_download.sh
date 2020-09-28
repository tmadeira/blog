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
title=$(cat $tmp/html | grep '<title>' | sed 's/.*<title>//; s/<\/title>.*//')

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

