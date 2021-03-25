#!/bin/bash

#git pull
rm -r obj/*.o
make TARGET="micro-vec"$1"-fma"$2 VEC_WIDTH=$1 N_CHAINED_FMAS=$2
