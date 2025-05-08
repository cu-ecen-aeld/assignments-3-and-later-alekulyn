#!/usr/bin/env bash

if [[ -z "$1" || -z "$2" ]]; then
  echo "Both arguments not supplied"
  exit 1
fi

dir=$1
string=$2

if [ ! -d "$1" ]; then
  echo "$1 does not exist."
  exit 1
fi

filenum=$(grep -lR $string $dir | wc -l)
linenum=$(grep -R $string $dir | wc -l)

echo "The number of files are $filenum and the number of matching lines are $linenum"
