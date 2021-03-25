#!/bin/bash

make main TAILLE=2048 MODE=0 && echo -e '\n' && for i in {1..2048} ; do (cat /dev/random | head -c 200 | tr -dc '0-9'| head -c 8 && echo) ; done | ./main
