#include <stdio.h>
#include <stdlib.h>


int main(){
    

    int result ;
    unsigned int num = 10;
    unsigned int num2 = 160;

    result = (num << 3);
    printf("result left shift 3 times eqaul to result *= 2^3  : %d\n" ,result );

    result = (num2 >> 2);
    printf("result right shift 2 times eqaul to result /= 2^2  : %d\n" ,result );  


    return 0 ;
}