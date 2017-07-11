/**
Generate 2 matrices m X n and p X q
*/
#include <stdio.h>
#include <stdlib.h>
 

int main() {
	
	int N = 768;
	int c;
	FILE* fp;
	fp = fopen("inp", "w");

	fprintf(fp, "%d ", N);
	fprintf(fp, "1 ");
	for (c = 1; c <= N*N; c++) {
    		//n = rand();
  		fprintf(fp, "%d ", rand()%10000);
		//printf("%d ", rand());
	}


	fclose(fp);
 
  	return 0;
}
