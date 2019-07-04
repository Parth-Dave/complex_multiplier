#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



struct complex_int
{
	int real;
	int complex;
};
struct complex_int *data_readfile(FILE *input_file){
	int N;
	fscanf(input_file,"%d",N);
	struct complex_int C_array[N]; 
	char *temp=malloc(10*sizeof(char));
	int j;
	char c;
	for(int i=0;i<N;i++){
		fgets(temp,10,input_file);
		j=0;
		while(temp[j]!='\0'){
			if(temp[j]>='0'&& temp[j]<='9'){

			}
		}
	}
}
int main(int argc,char **argv){
	FILE *input_file;

	if(argc==0){
		input_file=fopen("input.txt","r");
	}
	else if(argc==1){
		input_file=fopen(argv[0],"r");
	}
	else{
		printf("you can only pass one or less file name \n");
		return 1;
	}

	data_readfile(input_file);

}