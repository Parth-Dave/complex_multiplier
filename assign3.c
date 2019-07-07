#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
	long int real;
	long int complex;
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
	
	long int j;
	char c;
	int sum=0;
	int flag=0;
	
	for(int i=0;i<N;i++){
		scanf("%ld",&j);
		C_array[i].real=j;
		scanf("%c",&c);
		scanf("%c",&c);
		scanf("%ld",&j);
		C_array[i].complex=j;
		
	}
	return C_array;
}

int main(int argc,char **argv){
	

	D = data_readfile();	
	int t;
	
	temp=(complex_int *)malloc(((N/2)+1)*sizeof(complex_int));
	while(N>1){	
		main_i=0;
		pthread_t threads[N/2];
		printf("creating %d threads\n",N/2 );
		for(t=0;t<N/2;t++){//making threads
			
			pthread_create(&threads[t],NULL,comp_multiply,(void *)D);
		}
		for(t=0;t<(N/2);t++){
			pthread_join(threads[t], NULL);//joining threads
		}
		if(N%2!=0){
		//	printf("main_i is %d\n",main_i);
			temp[main_i]=D[(main_i)*2];//adding the remaining complex number
			N++;

		}
		//printf("N/2 after adding remainder complex is %d\n",N/2 );
		for(t=0;t<(N/2);t++){
			D[t]=temp[t];//preparing data for next round;
		}
		N=N/2;//next round of multiplication
	//	printf("N at end of loop is %d\n",N );
		//printf(" multiplication is %ld + i%ld \n",D[0].real,D[0].complex );
	}
	printf("Final multiplication is %ld + i%ld \n",D[0].real,D[0].complex );
	

}