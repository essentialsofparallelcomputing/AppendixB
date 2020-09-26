#!/bin/sh
#SBATCH -N 1
#SBATCH -n 4
#SBATCH -t 01:00:00

mpirun -n 4 ./testapp &> run.out || rm -f simulation_database
