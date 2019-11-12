#include <stdio.h>
#include <stdlib.h>


#define MAX 10000


int modrev(int* num, int length, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = length-1; i >= 0; i--)
         res = (res*10 + num[i]) %a;

    return res;
}



int multiply(int x, int res[], int res_size) {

// Initialize carry
int carry = 0;

// One by one multiply n with
// individual digits of res[]
for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;

    // Store last digit of
    // 'prod' in res[]
    res[i] = prod % 10;

    // Put rest in carry
    carry = prod / 10;
}

// Put carry in res and
// increase result size
while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}

// This function finds
// power of a number x
int* power(int x, int n, int* counter)
{
int* res = malloc(sizeof(int)*MAX); //<-- heap
//printing value "1" for power = 0
if(n == 0){
    printf("1");
    return res;
}



int res_size = 0;
int temp = x;

// Initialize result
while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
}

// Multiply x n times
// (x^n = x*x*x....n times)
for (int i = 2; i <= n; i++)
    res_size = multiply(x, res, res_size);

printf("%d ^ %d = ",x,n);

/*
for (int i = res_size - 1; i >= 0; i--)
    printf("%d", res[i]);
*/
*counter = res_size;

return res;

}

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



int main(){
	int p = primegen(70);
	printf("%d\n",p);
	int q = primegen(50);
	printf("%d\n",q);
	int n = p * q;
	char m = 'H';
	int message = (int)m;
	int e = publickeygen(p,q);
	int counter = 0;
	int* result;
	result = power(message,e,&counter);
	printf("\n");
	int cnum = modrev(result,counter,n);
	printf("%d",cnum);
	free(result);
	int* result2;
	int counter2 = 0;
	int tem = (p-1)*(q-1);
	int d = modInverse(e,tem);
	result2 = power(cnum,d,&counter2);
	message = modrev(result2,counter2,n);
	printf("\n%d",message);
	free(result2);
	return 0;


}
