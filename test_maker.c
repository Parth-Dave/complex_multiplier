#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char **argv){
	int N;
	FILE *file_ptr=fopen("input.txt","a");
	int real;
	int complex;

	scanf("%d",&N);
	fprintf(file_ptr, "%d\n",N);
	for(int i=0;i<N;i++){
		real=1000000000-rand();
		real=real/100000000;
		fprintf(file_ptr, "%d",real);
		fprintf(file_ptr, "%s","+i");
		complex=1000000000-rand();
		complex=complex/100000000;
		fprintf(file_ptr, "%d\n",complex);
	}
	fclose(file_ptr);
}