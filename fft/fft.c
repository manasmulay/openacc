#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timer.h"

void swap(double *a, double *b){
    double tmp = *b;
    *b = *a;
    *a = tmp; 
}



int main(int argc, char const *argv[])
{
    unsigned long counter = 10;
    double *data;
    float totalTime = 0.0;
    for(counter ; counter < 400 ; counter = counter + 10){
        unsigned long N = counter;
        printf("\tArray size %lu x %lu\n", N,N);

        data = (double *)malloc(sizeof(double) * 2 * N);

        int loop;

        
        for(loop=0; loop<2*N; loop+=2) {
            data[loop] = loop/2.0;
            data[loop+1] = 0.0;
        }
        

        unsigned long n, mmax, m, j, istep, i;
        double wtemp, wr, wpr, wpi, wi, theta;
        double tempr, tempi;
     
        // reverse-binary reindexing
        n = N<<1;
        j=1;

        for (i=1; i<n; i+=2) {
            if (j>i) {
                swap(&data[j-1], &data[i-1]);
                swap(&data[j], &data[i]);
            }
            m = N;
            while (m>=2 && j>m) {
                j -= m;
                m >>= 1;
            }
            j += m;
        };
     
        // here begins the Danielson-Lanczos section
        mmax=2;
        StartTimer();
        while (n>mmax) {
            istep = mmax<<1;
            theta = -(2*M_PI/mmax);
            wtemp = sin(0.5*theta);
            wpr = -2.0*wtemp*wtemp;
            wpi = sin(theta);
            wr = 1.0;
            wi = 0.0;
            for (m=1; m < mmax; m += 2) {
                for (i=m; i <= n; i += istep) {
                    j=i+mmax;
                    tempr = wr*data[j-1] - wi*data[j];
                    tempi = wr * data[j] + wi*data[j-1];
     
                    data[j-1] = data[i-1] - tempr;
                    data[j] = data[i] - tempi;
                    data[i-1] += tempr;
                    data[i] += tempi;
                }
                wtemp=wr;
                wr += wr*wpr - wi*wpi;
                wi += wi*wpr + wtemp*wpi;
            }
            mmax=istep;
        }
        float f = GetTimer();
        totalTime += f;
        // for(loop=0; loop<2*N; loop+=2) {
        //     printf("(%f, %f)\n", data[loop],data[loop+1]);
        // }
        // acc_free(data);  
    }
    printf("%fs\n", totalTime/1000);


    return 0;
}