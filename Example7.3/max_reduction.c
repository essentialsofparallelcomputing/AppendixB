#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <omp.h>
#include "timer.h"

// large enough to force into main memory
#define ARRAY_SIZE 80000000
static double var[ARRAY_SIZE];

double array_max(double* restrict var, int n);

int main(int argc, char *argv[]){
   struct timespec tstart;
   double time_sum = 0.0;
   for (int i=0; i<ARRAY_SIZE; i++) {
      var[i] = 1.0;
   }
   var[ARRAY_SIZE/2] = 2.0;

   double var_max;
   cpu_timer_start(&tstart);
#pragma omp  parallel
   {
      var_max = array_max(var,ARRAY_SIZE);
   }
   time_sum += cpu_timer_stop(tstart);

   printf("Maximum value is %lf\n", var_max);
   printf("Runtime is %lf msecs\n", time_sum);
}

double array_max(double* restrict var, int ncells)
{
   int nthreads = omp_get_num_threads();
   int thread_id = omp_get_thread_num();
   int tbegin = ncells * ( thread_id     ) / nthreads;
   int tend   = ncells * ( thread_id + 1 ) / nthreads;
   static double xmax;
   static double *xmax_thread;
   if (thread_id == 0){
      xmax_thread = malloc(nthreads*sizeof(double));
      xmax = DBL_MIN;
   }

   double xmax_thread_private = DBL_MIN;
   for (int i = tbegin; i < tend; i++){
      if (var[i] > xmax_thread_private) xmax_thread_private = var[i];
   }
   xmax_thread[thread_id] = xmax_thread_private;

#pragma omp barrier

#pragma omp master
   {
      for (int tid=0; tid < nthreads; tid++){
         if (xmax_thread[tid] > xmax) xmax = xmax_thread[tid];
      }
   }

#pragma omp barrier

   if (thread_id == 0){
      free(xmax_thread);
   }
   return(xmax);
}
