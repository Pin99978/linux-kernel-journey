#include <stdio.h>


unsigned wordlength(void);
unsigned rightrot(unsigned x , int n);


int main(){
    unsigned x = 0xD2; // 11010010 in binary (210 in decimal)
    int n = 3;
    
    printf("Word length: %u bits\n", wordlength());
    printf("Original value: 0x%X (%u)\n", x, x);
    printf("Right rotate by %d bits: 0x%X (%u)\n", n, rightrot(x, n), rightrot(x, n));
    
    // Test with different values
    x = 0xAB; // 10101011
    n = 4;
    printf("\nOriginal value: 0x%X (%u)\n", x, x);
    printf("Right rotate by %d bits: 0x%X (%u)\n", n, rightrot(x, n), rightrot(x, n));
    
    return 0;
}

unsigned wordlength(void){
    unsigned x = ~0 ;
    int count =0;
    while ( x !=0 ){
        x = x >> 1;
        count ++;
    }
    return count;
}

unsigned rightrot(unsigned x ,int n){

    // our target , if n = 3 
    // 1101 0010
    // 0001 1010  shift 3
    // 0101 1010  
 
    
    // step 1.  , determine the word length
    unsigned bit_length = wordlength();

    // Handle edge case: ensure n is within valid range
    n = n % bit_length;

    // step 2.1 , extract the Extract the rightmost n bits from x
    unsigned mask =  (1 << n) - 1 ;
    // 0000 0111

    // step 2.2 extract rightmost n bits
    unsigned ext_bits =  x & mask ;

    // step 3: right shift the x with n bits
    unsigned x_shift = x >> n;

    // step 4: Shift those dropped bits (ext_bits) into the leftmost n positions
    unsigned final_bit = x_shift | (ext_bits << (bit_length - n));
    
    return final_bit;
}