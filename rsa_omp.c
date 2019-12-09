#include <stdio.h>
#include <stdlib.h>
#include "power.c"
#include "mod.c"

#include <omp.h>
#include <sys/time.h>

#define DEBUG 0
#define MAX 10000
int isprime(int input){
        if(input == 2){
                return input;
        }
        else{
                int i,j = 0;
                for(i = 2; i < input; i++){
                        if((i == (input-1))&&((input%i)!=0)){
                                return input;
                        }
                        else if((input % i)==0){
                                return 0;
                        }else{
                                continue;
                        }
                }
                return 0;
        }
        return 0;
}


int primegen(int input){
        int i = 0;
        int x = 0;
        for(i = input; i >= 2; i--){
                x = isprime(i);
                if(x==0){
                        continue;
                }
                else if(x!=0){
                        return i;
                }
        }
        return 2;
}

int gcd(int x, int y){
        int out = 1;
        int i = 1;
        for(i = 1; i <= x && i <= y; i++){
                if((x%i)==0 && (y%i)==0){
                        out = i;
                }
        }
        return out;
}

int publickeygen(int p, int q){
        int e = ((p-1)*(q-1))-1;
        int i = 0;
        for(i = 0; e >= 1; i++){
                if(gcd(e,(p-1)*(q-1)) != 1){
                        e--;
                        continue;
                }else{
                        return e;
                }
        }
        return e;
}

int privatekeygen(int e, int p, int q){

	int psub = p-1;
	int qsub = q-1;
	int prosub = psub*qsub;
	int lcm = prosub/gcd(psub,qsub);
	int d = 1;
	for(d= 1;d < p*q; d++){
		int temp = (d*e)%lcm;
		if(lcm == 1){
			return d;
		}
	}

}



int modInverse(int a, int m)
{
    a = a%m;
	int x;
    for (x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}



int encrypt(int m, int e, int n){

  	int counter = 0;
        int* result;
        result = power(m,e,&counter);
        //printf("\n");
        int cnum = modrev(result,counter,n);
      //  printf("CipherText in Int Form: %d\n",cnum);
        free(result);
	return cnum;

}

int decrypt(int cnum, int d, int n){

	int* result2;
        int counter2 = 0;
        result2 = power(cnum,d,&counter2);
        int m = modrev(result2,counter2,n);
       if(DEBUG){ 
		printf("\nMessage Decrypted = %d",m);
       } 
	free(result2);
	return m;
}


int main(int argv, char** argc){

  //TODO: provide filing to read text to be encrypted


  //TODO: provide OpenMP parallelism


  //TODO: put timing to find where time is taken?

  //TODO: find large interesting text files, preferably Novel etc
  //      use it to do the final benchmarking and poster presentation


  //TODO: Auto-testing to check for correct execution


struct timeval begin, end;

//struct timeval affine_begin, affine_end;
struct timeval affst,affend;
struct timeval encrypst, encrypend;
struct timeval decrypst, decrypend;
struct timeval filst, filend;

//TIC
gettimeofday(&begin, 0);
//compute 
gettimeofday(&filst,0);
  char ch, file_name[25];
  FILE *fp;
  int input_size = 0;

	//int input[] = {65,66,67,68,69,70,71,72};
  int input[MAX];
	int output[MAX];
  int decrypted_output[MAX];


	int i = 0;
	int p,q,n;
	char m;
	int message;
	int e;

  // read from file....
  fp = fopen(argc[1], "r"); // read mode
  while((ch = fgetc(fp)) != EOF){
     input[input_size] = (int) ch;
     input_size++; 
  }

	fclose(fp);
gettimeofday(&filend,0);
				
		gettimeofday(&affst, 0);	
		p = primegen(70);
	//	printf("p = %d\n",p);
		q = primegen(50);
	//	printf("q = %d\n",q);
		n = p * q;
		//m = 'H';
		//message = (int)m;
		e = publickeygen(p,q);
		int tem = (p-1)*(q-1);
	        int d = modInverse(e,tem);
		gettimeofday(&affend, 0);

	/*
	int counter = 0;
	int* result;
	result = power(message,e,&counter);
	printf("\n");
	int cnum = modrev(result,counter,n);
	printf("CipherText in Int Form: %d\n",cnum);
	free(result);
	*/
  

  gettimeofday(&encrypst,0); //encryption start time recorded

  printf("starting encryption\n");
  #pragma omp parallel for
  for(i = 0; i < input_size; i++){

		int cnum = encrypt(input[i],e,n);
		output[i] = cnum;
    if(DEBUG){
    	printf("TID: %d. Encryption of %d is %d\n", omp_get_thread_num(), input[i], output[i]); 
    }
  }
	/*int* result2;
	int counter2 = 0;*/
	//printf("\n\n\n%d",d);	
  gettimeofday(&encrypend,0);

  gettimeofday(&decrypst,0); //decryption time start

  printf("starting decryp\n");
  #pragma omp parallel for
	for(i =0; i < input_size; i++){
	/*result2 = power(cnum,d,&counter2);
	message = modrev(result2,counter2,n);
	printf("\nMessage Decrypted = %d",(char)message);
	free(result2);*/
		int cnum = output[i];
		int tempor = decrypt(cnum,d,n);
    decrypted_output[i] = tempor;
		//printf("%d",tempor);
    if(DEBUG){
	printf("TID: %d. Decryption of %d is %d\n", omp_get_thread_num(), output[i], tempor);
    }
   if(input[i] != tempor)
    printf("ERROR at ieration %d\n",i);
	}

  gettimeofday(&decrypend,0);
// timing
//TOC
  gettimeofday(&end, 0);
 
	double affelaps = (affend.tv_sec - affst.tv_sec) + ((affend.tv_usec - affst.tv_usec) / 1000000.0); 
	double elapsed = (end.tv_sec - begin.tv_sec) +
              ((end.tv_usec - begin.tv_usec)/1000000.0);
	double encrypelapsed = (encrypend.tv_sec - encrypst.tv_sec) + ((encrypend.tv_usec - encrypst.tv_usec) / 1000000.0);
	double decrypelapsed = (decrypend.tv_sec - decrypst.tv_sec) + ((decrypend.tv_usec - decrypst.tv_usec) / 1000000.0);
	double filingelapsed = (filend.tv_sec - filst.tv_sec) + ((filend.tv_usec - filst.tv_usec) / 1000000.0);
	
	int num_threads = omp_get_num_threads();
	
	printf("Threads\tFiling\tAffine\tEncrypt\tDecrypt\tTotal\n");

	printf("%d\t%lg\t%lg\t%lg\t%lg\t%lg",num_threads,filingelapsed,affelaps,encrypelapsed,decrypelapsed,elapsed);

	




	
printf("\n\n");
if(DEBUG){
  for(i=0;i<input_size;i++){
    printf("%c", decrypted_output[i]);
  }

  printf("\n");
}




	return 0;


}
