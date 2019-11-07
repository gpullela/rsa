#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * bigint(char ints[]){
	char temp = '0';
	int i = 0;
	int length = sizeof(ints *) - 1;
	int j = length-1;
	int out[length];
	for(i = 0; i < length; i++){
		char in = ints[j];
		out[i] = in - temp;
		j--;
	}
	return out;
}


int main(){
	char arr[] = {'1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9'};
	int returned[] = bigint(arr);
	int length = sizeof(returned) - 1;
	int i = 0;
	for(i = 0; i < length; i++){
		printf("%s",returned[i]);
	}
	return 0;
}
