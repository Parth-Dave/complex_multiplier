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
	
	complex_int a=arr_pointer[i*2];
	
	complex_int b=arr_pointer[(i*2)+1];
	
	complex_int c;
	c.real=(a.real*b.real) -(a.complex*b.complex);
	c.complex=(a.complex*b.real)+(a.real*b.complex);
	
	temp[i]=c;

}

complex_int *data_readfile(){
	
	scanf("%d", &N);
	
	complex_int *C_array=(complex_int *)malloc(N*sizeof(complex_int));
	
	int j;
	char c;
	int sum=0;
	int flag=0;
	
	for(int i=0;i<N;i++){
		scanf("%d",&j);
		C_array[i].real=j;
		scanf("%c",&c);
		scanf("%c",&c);
		scanf("%d",&j);
		C_array[i].complex=j;
		
	}
	return C_array;
}

int main(int argc,char **argv){
	

	D = data_readfile();	
	int t;
	
	temp=(complex_int *)malloc((N/2)*sizeof(complex_int));
	while(N>1){	
		main_i=0;
		pthread_t threads[N/2];
		printf("creating %d threads\n",N/2 );
		for(t=0;t<N/2;t++){
			
			pthread_create(&threads[t],NULL,comp_multiply,(void *)D);
		}
		for(t=0;t<(N/2);t++){
			pthread_join(threads[t], NULL);
		}
		if((N/2)%2!=0){
			temp[main_i]=D[main_i*2];
			N++;

		}
		for(t=0;t<(N/2);t++){
			D[t]=temp[t];
		}
		N=N/2;
	}
	printf("Final multiplication is %d + i %d \n",D[0].real,D[0].complex );
	

}