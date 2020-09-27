#include <stdio.h>
#include <stdlib.h>
#include "malloc2Dfort.h"

double **malloc2Dfort_dbl(int jmax, int imax)
{
   double **x = (double **)malloc(imax*sizeof(double *) + 
                imax*jmax*sizeof(double));

   x[0] = (double *)(x + imax);

   for (int i = 1; i < imax; i++) {
      x[i] = x[i-1] + jmax;
   }

   return(x);
}

int **malloc2Dfort_int(int jmax, int imax)
{
   int **a = (int **)malloc(imax*sizeof(int *) + 
             imax*jmax*sizeof(int));

   a[0] = (int *)(a + imax);

   for (int i = 1; i < imax; i++) {
      a[i] = a[i-1] + jmax;
   }

   return(a);
}
