#!/bin/bash
#SBATCH --job-name=hw1
#SBATCH --partition=Centaurus
#SBATCH --time=00:01:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1

module load gcc

# Compile the C++ program
g++ -O3 hw1.cpp -o hw1

#clear output file before running
> results.csv

# Run the benchmark for sizes 10^1 to 10^9
for size in 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000; do
    echo "Running merge sort of size $size"
    ./hw1 $size >> results.csv
done
