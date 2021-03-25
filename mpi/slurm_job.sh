#!/bin/bash


#SBATCH --job-name=MPI_FMA_Skylake # Job name
#SBATCH --partition=Orion
# Number of MPI tasks
#SBATCH -n 36
#SBATCH --nodes=1                    # Run all processes on a single node
#SBATCH --ntasks=36                   # Run a single task
#SBATCH --constraint=skylake
#SBATCH --mem=150gb                  # Total memory limit
#SBATCH --time=30:00:00              # Time limit hrs:min:sec
#SBATCH --output=mpi_fma_skylake_%j.log     # Standard output and error log

# Clear the environment from any previously loaded modules
#export KMP_HW_SUBSET=1t
#export KMP_AFFINITY=compact,1
#module purge > /dev/null 2>&1
#module load openmpi/4.0.3
#module load intel/19.0.0
#module load gcc/8.2.0

#lscpu
processor=1
target="micro-vec"$1"-fma"$2
mpirun ./$target $processor

