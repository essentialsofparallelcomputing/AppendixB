#!/bin/sh
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 01:00:00

sbatch --dependency=afterok:${SLURM_JOB_ID} <batch_restart.sh

mpirun -n 4 ./preprocess &> preprocess.out
