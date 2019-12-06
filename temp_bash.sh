#!/bin/bash

echo "RSA ENCRYPTION"

export OMP_NUM_THREADS=1
./a.out robert_frost.txt >> results.dat

export OMP_NUM_THREADS=2
./a.out robert_frost.txt >> results.dat

export OMP_NUM_THREADS=4
./a.out robert_frost.txt >> results.dat

export OMP_NUM_THREADS=8
./a.out robert_frost.txt >> results.dat

echo "COMPLETED SIMULATION"