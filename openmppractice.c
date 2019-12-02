#include <stdio.h>
#include <omp.h>

#define N 10

int main(){


	#pragma omp parallel
	{
		int i = 0;
    int tid = omp_get_thread_num();
	  printf("Hello World from %d\n", tid);	
   
//int product = 1;
		#pragma omp for
		for(i = 1; i < N; i++){
      
			//int product = i+1;
			printf("tid %d shares iteration %d\n",omp_get_thread_num(), i);
		}

	}

}
