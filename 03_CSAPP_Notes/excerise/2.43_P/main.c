#include <stdio.h>

#define M /* Mystery number1 */
#define N /* Mystery number2 */

int arith(int x , int y){
    int result = 0; 
    result = x*M + y/N   ; 
    return result;
}


int optarith(int x , int y){
    int temp = x;  
    // like x * n = x * 2^(n+1) - x
    x <<= 5;
    x -= temp;

    
    // like x / 2^k = (x<0 ? x + (1<<k)-1 : x) 
    // k = 3 
    if (y < 0) y +=7;
    y >>=3;
    return x + y;
}

// answer M = 2^5 ,  N = 2^3