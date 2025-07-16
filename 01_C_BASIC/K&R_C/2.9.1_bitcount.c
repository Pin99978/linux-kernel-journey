#include <stdio.h>


/* count 1 bits in x*/

int bitcount(unsigned x ){
    int b ;
    for ( b = 0; x != 0; x >>= 1){
        if (x & 01){
            b ++ ;
        }
    }
    return b;
}


int main(){
    //test
    unsigned x = 077;
    int counts = bitcount(x);

    printf("Original: %u (Binary: ", x);
    for(int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }

    printf(")\n");
    printf("Number of 1 bits: %d\n", counts);
    
    return 0;
}