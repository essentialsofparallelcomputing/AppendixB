#include <stdlib.h>
#include "malloc2Dtri.h"

double **malloc2Dtri(int jmax, int imax)
{
   double **x = (double **)malloc(jmax*sizeof(double *) + 
                jmax*(imax+1)/2*sizeof(double));

   x[0] = (double *)(x + jmax);

   for (int j = 1; j < jmax; j++, imax--) {
     x[j] = x[j-1] + imax;
   }

   return(x);
}
