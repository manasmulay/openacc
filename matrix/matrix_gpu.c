#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "timer.h"

int main(int argc, char** argv){
  int m, n, p, q, sum=0;
  int i=0, j=0, k=0;

  scanf("%d%d", &m, &n);
  scanf("%d%d", &p, &q);

  int first[m][n], second[p][q], multiply[m][q];

  memset(first, 0, m*n);
  memset(second, 0, p*q);
  memset(multiply, 0, m*q);

  if(n != p){
    return -1;
  }

  //Take Input
  for(i=0 ; i<m ; i++){
    for(j=0 ; j<n ; j++){
      scanf("%d", &first[i][j]);
      // printf("%d ", first[i][j]);
    }
  }

  for(i=0 ; i<p ; i++){
    for(j=0 ; j<q ; j++){
      scanf("%d", &second[i][j]);
      // printf("%d ", second[i][j]);
    }
  }


  //Multiply and Parallelise
#pragma acc kernel
#pragma acc copyin(first[0:m*n], second[0:p*q]) copyout(multiply[0,m*q])
  StartTimer();
#pragma acc loop
  for (i = 0; i < m; i++) {
  #pragma acc loop
      for (j = 0; j < q; j++) {
          for (k = 0; k < p; k++) {
            sum = sum + first[i][k]*second[k][j];
          }

    multiply[i][j] = sum;
    sum = 0;
    }
  }
  //print matrix

  double runtime = GetTimer();
  printf("Timer=%f s\n", runtime / 1000.f);

  // for(i=0 ; i<m ; i++){
  //   for(j=0 ; j<q ; j++){
  //     printf("%d\t", multiply[i][j]);
  //   }
  //   printf("\n");
  //  }


//com[re]
  return 0;
}
