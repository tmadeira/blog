---
title: Dump email addresses from files
type: post
date: 2012-05-03T06:58:38+00:00
url: /2012/05/dump-email-addresses-from-files/
categorias:
  - Códigos aleatórios
tags:
  - antiword
  - bash
  - catopenxml
  - códigos
  - doc
  - docx
  - emails
  - expressões regulares
  - linux
  - pdf
  - pdftotext
  - regex
  - scripts
  - shell
  - unix
---

Suppose you have a lot of .doc, .docx, .xls, .xlsx, .gz, .bz2, .pdf and text in general (.csv, .txt etc.) files and want to dump all the (unique) email addresses from them. How would you do it? Here is a simple solution I’ve just implemented (and probably didn’t test enough, so tell me if you find any bug):

```bash
#!/bin/sh
tmp=$(tempfile)
while [ $# -gt 0 ]; do
    if [ -r "$1" ]; then
        ext=$(echo ${1#*.} | tr [A-Z] [a-z])
        case $ext in
            docx | xlsx)
                # requires: http://blog.kiddaland.net/2009/07/antiword-for-office-2007/
                cat_open_xml "$1" >> $tmp
                ;;
            doc)
                # requires: antiword
                antiword "$1" >> $tmp
                ;;
            xls)
                # requires: catdoc
                xls2csv "$1" >> $tmp
                ;;
            gz)
                cat "$1" | gunzip >> $tmp
                ;;
            bz2)
                cat "$1" | bunzip2 >> $tmp
                ;;
            zip)
                unzip -p "$1" >> $tmp
                ;;
            pdf)
                # requires: xpdf-utils
                t=$(tempfile)
                pdftotext "$1" $t
                cat $t >> $tmp
                rm $t
                ;;
            *)
                text=$(file -b --mime-type "$1" | sed -e 's//.*//')
                if [ "z$text" = "ztext" ]; then
                    cat "$1" >> $tmp
                fi
                ;;
        esac
    fi
    shift
done
cat $tmp | grep -o -E '\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+.[A-Za-z]{2,4}\b'
         | tr [A-Z] [a-z] | sort -u
rm $tmp
```

(the email regexp is explained here: [regular-expressions.info/email.html][1])

[1]: http://www.regular-expressions.info/email.html
