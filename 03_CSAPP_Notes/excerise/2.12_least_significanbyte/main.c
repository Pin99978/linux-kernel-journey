// write C expressions ,in termo of variable x for the following values , your code should work for any word size w>= 8 , for reference , we show the result of evaluating the expressions for x = 0x87654321 with w = 32

#include <stdio.h>

void print_byte(unsigned int n){
    for ( int i = 31 ; i >= 0 ; i--){
        unsigned int mask = 1 << i;
        if ((n & mask ) != 0 ){
            printf("1");
        }else{
            printf("0");
        }
        if (i % 4 == 0 && i != 0){
            printf(" ");
        }
    }
    printf("\n");
}


int main(){

    unsigned int mask = 0xff ; 
    unsigned int q1 = 0x00000021 ;

    // again , in little endiance , the least byte is first store in the memory
    // Q1 : the least significant byte of x , with all other bits set to 0 
    printf("The least significant byte of x is %d\n" , q1 & mask );
    // Q2: All but the least significant byte of x complmented , with the least significate byte left unchanged (0x789ABC21)

    unsigned int q2 = 0x789ABC21;
    print_byte(q2);
    print_byte(q2 ^ (~mask));

    unsigned int q3 = 0x876543ff;
    print_byte(q3);
    print_byte( q3 | mask );
    return 0;
}