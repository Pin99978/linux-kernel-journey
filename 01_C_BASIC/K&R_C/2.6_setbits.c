#include <stdio.h>

unsigned setbits(unsigned x , int p, int n , int y);

int main(){
    
    unsigned x = 0b11110000;  
    unsigned y = 0b00000101;  
    int p = 6;                
    int n = 3;                

    unsigned result = setbits(x, p, n, y);
    
    return 0 ;
}

unsigned setbits(unsigned x , int p, int n , int y){

    // step 1 : create the mask which extract the n-bit from rightmost 
    unsigned mask = (1 << n) - 1;

    // step 2 : attach mask to y than move the y_mask to x p( target position)
    unsigned y_bits = (y & mask) << (p + 1 -n);

    // step 3 : clear n bits at position p in x , set other x unchanged
    unsigned x_clean = x & ~(mask << (p + 1 - n));

    // step 4 : 
    return x_clean | y_bits; 

}