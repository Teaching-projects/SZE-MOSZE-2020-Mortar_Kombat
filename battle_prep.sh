#!/bin/bash

IFS = $'\n'

rm output.csv

for i in `cat input.csv`; do
    echo "$i" >> output.csv;
done