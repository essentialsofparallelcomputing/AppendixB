#include <stdio.h>
#include "malloc2Dtri.h"

int main(int argc, char *argv[]){

  int imax = 10, jmax = 10;

  double **xtriangular = (double **)malloc2Dtri(jmax,imax);

  double *xtriangular1D = (double *) &xtriangular[0][0];

  for (int i=0; i<jmax*(imax+1)/2; i++){
     xtriangular1D[i] = (double)i;
  }

  for (int j = 0; j<jmax; j++){
     printf("Start of row %d is %4.0lf\n",j,xtriangular[j][0]);
  }

}
