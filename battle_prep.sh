#!/bin/bash

xIFS=$IFS
IFS=$'\n'
f_tocheck='output.csv'

if [ -f $f_tocheck]; then
    rm $f_tocheck
fi

./a.out 'units/Unit1.json' 'units/Unit2.json' >> $f_tocheck
./a.out 'units/Unit1.json' 'units/Unit3.json' >> $f_tocheck
./a.out 'units/Unit2.json' 'units/Unit1.json' >> $f_tocheck
./a.out 'units/Unit2.json' 'units/Unit3.json' >> $f_tocheck
./a.out 'units/Unit3.json' 'units/Unit2.json' >> $f_tocheck
./a.out 'units/Unit3.json' 'units/Unit1.json' >> $f_tocheck
