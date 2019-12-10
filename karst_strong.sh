#PBS -S /bin/bash
#PBS -k o
#PBS -l nodes=1:ppn=16,walltime=2:00:00
#PBS -l mem=16GB
#PBS -M gpullela@iu.edu
#PBS -m abe
#PBS -N RSA-HPC

cd /N/u/gpullela/Karst/rsa

echo "RSA ENCRYPTION"
echo "Commencing Data Collection"


echo "Run 1"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=16
./a.out robert_frost1.txt >> karst_strong.dat


echo "Run 2"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=16
./a.out robert_frost1.txt >> karst_strong.dat


echo "Run 3"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=16
./a.out robert_frost1.txt >> karst_strong.dat


echo "Run 4"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=16
./a.out robert_frost1.txt >> karst_strong.dat


echo "Run 5"

export OMP_NUM_THREADS=1
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=2
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=4
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=8
./a.out robert_frost1.txt >> karst_strong.dat

export OMP_NUM_THREADS=16
./a.out robert_frost1.txt >> karst_strong.dat


echo "Completed Data Collection"
echo "COMPLETED SIMULATION"
