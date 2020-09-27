#!/bin/sh
#SBATCH -N 1
#SBATCH -n 4
#SBATCH --signal=23@160
#SBATCH -t 00:08:00

# Do not place bash commands before the last SBATCH directive
# Behavior can be unreliable

NUM_CPUS=4
OUTPUT_FILE=run.out
EXEC_NAME=./testapp
MAX_RESTARTS=4

if [ -z ${COUNT} ]; then
   export COUNT=0
fi

((COUNT++))
echo "Restart COUNT is ${COUNT}"

if [ ! -e DONE ]; then
   if [ -e RESTART ]; then
      echo "=== Restarting ${EXEC_NAME} ==="             >> ${OUTPUT_FILE}
      cycle=`cat RESTART`
      rm -f RESTART
   elif [ -e PREPROCESS_DONE ]; then
      echo "=== Starting problem ==="                    >> ${OUTPUT_FILE}
      cycle=""
   else
      echo "=== Preprocessing data for problem ==="      >> ${OUTPUT_FILE}
      mpirun -n ${NUM_CPUS} ./preprocess_data           &>> ${OUTPUT_FILE}
      date > PREPROCESS_DONE
      sbatch --dependency=afterok:${SLURM_JOB_ID} <preprocess_then_restart.sh
      exit
   fi

   echo "=== Submitting restart script ==="              >> ${OUTPUT_FILE}
   sbatch --dependency=afterok:${SLURM_JOB_ID} <preprocess_then_restart.sh

   mpirun -n ${NUM_CPUS} ${EXEC_NAME} ${cycle}          &>> ${OUTPUT_FILE}
   echo "Finished mpirun"                                >> ${OUTPUT_FILE}

   if [ ${COUNT} -ge ${MAX_RESTARTS} ]; then
      echo "=== Reached maximum number of restarts ==="  >> ${OUTPUT_FILE}
      date > DONE
   fi
fi
