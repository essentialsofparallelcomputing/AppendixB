#include <stdio.h>
#include <float.h>
#include "timer.h"

// large enough to force into main memory
#define ARRAY_SIZE 80000000
static double a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];

double array_max(double *a, int n);

int main(int argc, char *argv[]){
   struct timespec tstart;
   double time_sum = 0.0;
   for (int i=0; i<ARRAY_SIZE; i++) {
      a[i] = 1.0;
   }
   a[ARRAY_SIZE/2] = 2.0;

   cpu_timer_start(&tstart);
   double xmax = array_max(a,ARRAY_SIZE);
   time_sum += cpu_timer_stop(tstart);

   printf("Maximum value is %lf\n", xmax);
   printf("Runtime is %lf msecs\n", time_sum);
}

double array_max(double* restrict var, int ncells)
{
   double xmax = DBL_MIN;
   #pragma omp parallel for reduction(max:xmax)
   for (int i = 0; i < ncells; i++){
      if (var[i] > xmax) xmax = var[i];
   }
}


