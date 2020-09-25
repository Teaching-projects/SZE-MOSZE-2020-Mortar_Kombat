#!/bin/bash

xIFS=$IFS
IFS=$'\n'
rm output.csv

./a.out units/Unit1.json units/Unit2.json >> output.csv
./a.out units/Unit1.json units/Unit3.json >> output.csv
./a.out units/Unit2.json units/Unit1.json >> output.csv
./a.out units/Unit2.json units/Unit3.json >> output.csv
./a.out units/Unit3.json units/Unit2.json >> output.csv
./a.out units/Unit3.json units/Unit1.json >> output.csv
