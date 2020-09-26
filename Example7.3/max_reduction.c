#include <stdlib.h>
#include <float.h>
#include <omp.h>
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
#pragma omp barrier

   double xmax_thread_private = DBL_MIN;
   for (int i = tbegin; i < tend; i++){
      if (var[i] > xmax_thread_private) xmax_thread_private = var[i];
   }
   xmax_thread[thread_id] = xmax_thread_private;

#pragma omp barrier

   if (thread_id == 0){
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
