#include <stdio.h>
#include <stdlib.h>
#include "power.c"
#include "mod.c"

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

int privatekeygen(e,p,q){

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
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}



int encrypt(int m, int e, int n){

  	int counter = 0;
        int* result;
        result = power(m,e,&counter);
        printf("\n");
        int cnum = modrev(result,counter,n);
        printf("CipherText in Int Form: %d\n",cnum);
        free(result);
	return cnum;

}

int decrypt(int cnum, int d, int n){

	int* result2;
        int counter2 = 0;
        result2 = power(cnum,d,&counter2);
        int m = modrev(result2,counter2,n);
        printf("\nMessage Decrypted = %d",(char)m);
        free(result2);
	return m;
}


int main(){

	int input[] = {65,66,67,68,69,70,71,72};
	int output[8];
	int i = 0;
	for(i = 0; i < 8; i++){
		
		int p = primegen(70);
		printf("p = %d\n",p);
		int q = primegen(50);
		printf("q = %d\n",q);
		int n = p * q;
		char m = 'H';
		int message = (int)m;
		int e = publickeygen(p,q);
	/*
	int counter = 0;
	int* result;
	result = power(message,e,&counter);
	printf("\n");
	int cnum = modrev(result,counter,n);
	printf("CipherText in Int Form: %d\n",cnum);
	free(result);
	*/
		int cnum = encrypt(input[i],e,n);
		output[i] = cnum;
	}
	/*int* result2;
	int counter2 = 0;*/
	int tem = (p-1)*(q-1);
	int d = modInverse(e,tem);
	/*result2 = power(cnum,d,&counter2);
	message = modrev(result2,counter2,n);
	printf("\nMessage Decrypted = %d",(char)message);
	free(result2);*/
	int tempor = decrypt(cnum,d,n);
	return 0;


}
