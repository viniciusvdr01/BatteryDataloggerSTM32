#!/bin/bash

## verificar se o GCC esta instalado
## receber a pasta com os binários como argumento
## fonecer o nome do arquivo csv de saída


echo $BASH_VERSION

cp bintocsv.c logs
cp structs.h logs
cp types.h logs

cd logs

gcc -o out bintocsv.c

n=0

mkdir csvs

for item in *
do
	if [ -f $item ] && [[ $item == *.bin ]]
	then
		echo $item
		./out $item $(printf 'csvs/ronaldo%s.csv' "$n")
		n=$((n+1))
		echo $n
	fi
done


 
