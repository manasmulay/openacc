#include <stdio.h>
#include <stdlib.h>
#define n 7

int main() {
	
	int c;
 	
	FILE* fp;
	fp = fopen("inp", "w");

	fprintf(fp, "%d ", n);
	for (c = 1; c <= n*n; c++) {
      		fprintf(fp, "%d ", rand()%10000);
	}

	fclose(fp);
 
  	return 0;
}
