#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
	int real;
	int complex;
}complex_int;

typedef struct {
	int i;
	complex_int *arr_pointer;

}program_var;

int N;
complex_int *D;
complex_int *temp;
int main_i=0;

void* comp_multiply(void *arg){
	int i =main_i;
	main_i++;
	complex_int *arr_pointer= (complex_int *)arg;
	//printf("arg recieved is %d\n",i );
	//int val=*i;
	//printf("val is %d\n",val);
	//printf("D %d has real %d and complex %d \n",val,D[val].real,D[val].complex);
	complex_int a=arr_pointer[i*2];
	//printf("A has real %d and complex %d \n",a.real,a.complex);
	complex_int b=arr_pointer[(i*2)+1];
	//printf("B has real %d and complex %d \n",b.real,b.complex);
	complex_int c;
	c.real=(a.real*b.real) -(a.complex*b.complex);
	c.complex=(a.complex*b.real)+(a.real*b.complex);
	printf("C has real %d and complex %d \n",c.real,c.complex);
	temp[i]=c;

}

complex_int *data_readfile(){
	
	scanf("%d", &N);
	//fscanf(input_file," %d ", &N);
	//printf("after fscanf and N is %d\n",N);
	complex_int *C_array=(complex_int *)malloc(N*sizeof(complex_int));
	//printf("after complex C_array\n"); 

	//char *temp=malloc(100*sizeof(char));
	int j;
	char c;
	int sum=0;
	int flag=0;
	//printf("inside data_readfile\n");
	for(int i=0;i<N;i++){
		scanf("%d",&j);
		C_array[i].real=j;
		scanf("%c",&c);
		scanf("%c",&c);
		scanf("%d",&j);
		C_array[i].complex=j;
		//printf("i is %d and real is %d and complex is %d \n",i,C_array[i].real,C_array[i].complex);
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

	D = data_readfile();	
	int t;
	// program_var main_struct;
	while(N>1){	
		main_i=0;
		pthread_t threads[N/2];
		printf("creating %d threads\n",N/2 );
		temp=(complex_int *)malloc((N/2)*sizeof(complex_int));
		for(t=0;t<N/2;t++){
			//printf("arg sent is %d\n",t );
			pthread_create(&threads[t],NULL,comp_multiply,(void *)D);
		}
		for(t=0;t<(N/2);t++){
			pthread_join(threads[t], NULL);
		}
		for(t=0;t<(N/2);t++){
			D[t]=temp[t];
		}
		N=N/2;
	}
	printf("Final multiplication is %d + i %d \n",D[0].real,D[0].complex );
	// for(int i=0;i<(N/2);i++){
	// 	printf("i is %d and real is %d and complex is %d \n",i,temp[i].real,temp[i].complex);
	// }

}