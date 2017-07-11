/**
Generate 2 matrices m X n and p X q
*/
#include <stdio.h>
#include <stdlib.h>
 
int c;
int m=1000;
int n=500;
int p=500;
int q=800;
int main() {
	if(n != p){
		return -1;	
	}
 	char ch=' ';
	FILE* fp;
	fp = fopen("inp", "w");

	fprintf(fp, "%d ", m);
	fprintf(fp, "%d ", n);
	fprintf(fp, "%d ", p);
	fprintf(fp, "%d ", q);

	for (c = 1; c <= n*m; c++) {
    		//n = rand();
  		fprintf(fp, "%d ", rand()%10000);
		//printf("%d ", rand());
	}

	for (c = 1; c <= p*q; c++) {
    		//n = rand();
  		fprintf(fp, "%d ", rand()%10000);
		//printf("%d ", rand());
	}
	fclose(fp);
 
  	return 0;
}
