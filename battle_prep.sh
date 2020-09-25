#!/bin/bash

xIFS=$IFS
IFS=$'\n'
rm output.csv

for i in `cat input.csv`; do
    echo "$i" | ./a.out >> output.csv;
done
