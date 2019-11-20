// C++ program to compute mod of a big number represented 
// as string 
#include <stdio.h>
  
// Function to compute num (mod a) 
int mod(int* num, int length, int a) 
{ 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    int i;
    for (i = 0; i < length; i++) 
         res = (res*10 + num[i]) %a; 
  
    return res; 
} 

int modrev(int* num, int length, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    int i;
    for (i = length-1; i >= 0; i--)
         res = (res*10 + num[i]) %a;

    return res;
}

 /* 
// Driver program 
int main() 
{ 
    //int num[] = {1,2,3,1,6,7,6,7,6,7,8,6,7,8};
    int num[] = {8,7,6,8,7,8,7,6,7,6,1,3,2,1};
    //int i = mod(num,14,10);
    int i = modrev(num,14,10); 
    printf("%d",i); 
    return 0; 
} */
