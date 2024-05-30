#!/bin/bash

cp bintocsv.c $1
cp structs.h  $1
cp types.h    $1

cd $1

gcc -o out bintocsv.c

n=0

mkdir temp_csv

for binaries in *
do
	if [ -f $binaries ] && [[ $binaries == *.bin ]]
	then
		./out $binaries $(printf 'temp_csv/%s.csv' "$n")
		n=$((n+1))
	fi
done

cd temp_csv

cat *.csv >> $3

mv $3 $2 

cd ..

rm -r temp_csv

rm bintocsv.c

rm structs.h

rm types.h

rm out

