#include <stdio.h>
#include <omp.h>

#define N 100

int main(){


	#pragma omp parallel
	{
		int i = 0;
		int product = 1;
		#pragma omp for
		for(i = 1; i < N; i++){
			product *= i;
			printf("%d\n",product);
		}

		printf("\nHello World");
	}

}
