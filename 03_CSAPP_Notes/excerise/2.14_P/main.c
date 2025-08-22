/*
Suppose that a and b have byte value 0x55 and 0x46 , fill in the following table indicating the byte values of the different C expressions
*/


#include <stdio.h>
int main(){

    int a = 0x55;
    int b = 0x46;

    printf("%x \n", a & b);
    printf("%x \n" ,a | b);
    printf("%x \n" , ~a | ~b); 
    printf("%x \n" , a & !b); // 0

}