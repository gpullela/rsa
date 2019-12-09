#!/bin/bash

echo "RSA ENCRYPTION"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> results_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost2.txt >> results_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost4.txt >> results_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost8.txt >> results_strong.dat

echo "COMPLETED SIMULATION"
