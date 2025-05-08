#!/usr/bin/env bash

if [[ -z "$1" || -z "$2" ]]; then
  echo "Both arguments not supplied"
  exit 1
fi

mkdir -p "$(dirname "$1")" && touch "$1"
echo $2 >$1
