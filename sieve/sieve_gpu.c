#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
 
#define limit 1000000000 /*size of integers array*/
 
int main(){
    unsigned long long int i,j;
    int *primes;
    int z = 1;
 
    primes = malloc(sizeof(int) * limit);
 
    for (i = 2;i < limit; i++)
        primes[i] = 1;
    
    StartTimer();
    #pragma acc kernel
    #pragma acc parallel loop
    for (i = 2;i < limit; i++)
        if (primes[i])
            #pragma acc parallel
            for (j = i;i * j < limit; j++)
                primes[i * j] = 0;
    float f = GetTimer();
    // printf("\nPrime numbers in range 1 to 100 are: \n");
    // for (i = 2;i < limit; i++)
    //     if (primes[i])
    //         printf("%llu\n", i);
    printf("%f\n", f/1000);
return 0;
}