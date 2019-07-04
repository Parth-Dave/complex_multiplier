#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



typedef struct {
	int real;
	int complex;
}complex_int;

int N;

complex_int *data_readfile(){
	
	scanf("%d", &N);
	//fscanf(input_file," %d ", &N);
	printf("after fscanf and N is %d\n",N);
	complex_int *C_array=malloc(N*sizeof(complex_int));
	printf("after complex C_array\n"); 

	char *temp=malloc(100*sizeof(char));
	int j;
	char c;
	int sum=0;
	int flag=0;
	printf("inside data_readfile\n");
	for(int i=0;i<N;i++){
		scanf("%d",&j);
		C_array[i].real=j;
		scanf("%c",&c);
		scanf("%c",&c);
		scanf("%d",&j);
		C_array[i].complex=j;
		printf("i is %d and real is %d and complex is %d \n",i,C_array[i].real,C_array[i].complex);
	}
	return C_array;
}

int main(int argc,char **argv){
	//FILE *input_file;

	// if(argc==0){
	// 	input_file=fopen("input.txt","r");
	// }
	// else if(argc==1){
	// 	input_file=fopen(argv[0],"r");
	// }
	// else{
	// 	printf("you can only pass one or less file name \n");
	// 	return 1;
	// }

	complex_int *D = data_readfile();	
	

}