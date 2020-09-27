#include <float.h>
double array_max(double* restrict var, int ncells)
{
   double xmax = DBL_MIN;
   #pragma omp parallel for reduction(max:xmax)
   for (int i = 0; i < ncells; i++){
      if (var[i] > xmax) xmax = var[i];
   }
}
