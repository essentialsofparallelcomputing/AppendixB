#include <stdio.h>
#include "malloc2Dfort.h"
#define xfort(j,i) x[i-1][j-1]
#define afort(j,i) a[i-1][j-1]

int main(int argc, char *argv[]){

  int imax = 4, jmax = 10;

  printf("\nIn both C and Fortran, access should use j as the inner loop\n");
  printf("\n      C loop ordering\n");
  printf("for (int i = 1; i<=imax; i++){\n");
  printf("  for (int j = 1; j<=jmax; j++){\n");
  printf("    x[i][j] = ...  \n");
  printf("  }\n");
  printf("}\n");

  printf("\n     Fortran loop ordering\n");
  printf("for (int i = 1; i<=imax; i++){\n");
  printf("  for (int j = 1; j<=jmax; j++){\n");
  printf("    x(j,i) = ...  \n");
  printf("  }\n");
  printf("}\n");

  double **x = (double **)malloc2Dfort_dbl(jmax,imax);

  double *xfort1D = (double *) &x[0][0];

  for (int i=0; i<jmax*imax; i++){
     xfort1D[i] = (double)i;
  }

  printf("\n C layout with x[i][j]\n\n");
  printf("col   : ");
  for (int i = 0; i<imax; i++){
     printf("%4d ",i);
  }
  printf("\n");
  for (int j = 0; j<jmax; j++){
     printf("row %2d:",j);
     for (int i = 0; i<imax; i++){
        printf(" %4.1lf",x[i][j]);
     }
     printf("\n");
  }

  printf("\n Fortran layout with x(j,i)\n\n");
  printf("col    : ");
  for (int i = 1; i<=imax; i++){
     printf("%4d ",i);
  }
  printf("\n");
  for (int j = 1; j<=jmax; j++){
     printf("row %2d :",j);
     for (int i = 1; i<=imax; i++){
        printf(" %4.1lf",xfort(j,i));
     }
     printf("\n");
  }

  int **a = (int **)malloc2Dfort_int(jmax,imax);

  int *afort1D = (int *) &a[0][0];

  for (int i=0; i<jmax*imax; i++){
     afort1D[i] = i;
  }

  printf("\n C layout with a[i][j]\n\n");
  printf("col   : ");
  for (int i = 0; i<imax; i++){
     printf("%4d ",i);
  }
  printf("\n");
  for (int j = 0; j<jmax; j++){
     printf("row %2d:",j);
     for (int i = 0; i<imax; i++){
        printf(" %4d",a[i][j]);
     }
     printf("\n");
  }

  printf("\n Fortran layout with x(j,i)\n\n");
  printf("col    : ");
  for (int i = 1; i<=imax; i++){
     printf("%4d ",i);
  }
  printf("\n");
  for (int j = 1; j<=jmax; j++){
     printf("row %2d :",j);
     for (int i = 1; i<=imax; i++){
        printf(" %4d",afort(j,i));
     }
     printf("\n");
  }
}
