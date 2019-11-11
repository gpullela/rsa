#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXCHAR 10000

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


int main(){
	int p = primegen(6);
	int q = primegen(4);
	int n = p*q;
	double m = 3;
	double e =(double)publickeygen(p,q);
	double out;
	out = pow(m,e);
	int outint = (int)out;
	int ctext = outint%n;
	printf("%d",ctext);

	return 0;

}
