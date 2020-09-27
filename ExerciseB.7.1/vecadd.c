#include <stdio.h>
#include <omp.h>
#include "timer.h"

// large enough to force into main memory
#define ARRAY_SIZE 80000000
static double a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];

void vector_add(double *c, double *a, double *b, int n);

int main(int argc, char *argv[]){
   #pragma omp parallel
   {
      double time_sum;
      struct timespec tstart;
      int thread_id = omp_get_thread_num();
      int nthreads  = omp_get_num_threads();
      if (thread_id == 0){
         printf("Running with %d thread(s)\n",nthreads);
      }
      int tbegin = ARRAY_SIZE * ( thread_id     ) / nthreads;
      int tend   = ARRAY_SIZE * ( thread_id + 1 ) / nthreads;

      for (int i=tbegin; i<tend; i++) {
         a[i] = 1.0;
         b[i] = 2.0;
      }

      if (thread_id == 0) cpu_timer_start(&tstart);
      vector_add(c, a, b, ARRAY_SIZE);
      if (thread_id == 0) {
         time_sum += cpu_timer_stop(tstart);
         printf("Runtime is %lf msecs\n", time_sum);
      }
   }
}

void vector_add(double *c, double *a, double *b, int n)
{
   int thread_id = omp_get_thread_num();
   int nthreads = omp_get_num_threads();
   int tbegin = n * ( thread_id     ) / nthreads;
   int tend   = n * ( thread_id + 1 ) / nthreads;
   for (int i=tbegin; i < tend; i++){
      c[i] = a[i] + b[i];
   }
}
