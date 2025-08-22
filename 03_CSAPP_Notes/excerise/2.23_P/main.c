#include <stdio.h>


void print_bit(unsigned int n){
    for (int i = 31 ; i >= 0 ; i --){
        unsigned int mask =  1 << i;
        if ( (mask & n) !=0 ){
            printf("1");
        } else{
            printf("0");
        }
    }
}



int func1(unsigned word){
    return (int) ((word << 24) >> 24);
}
int func2(unsigned word){
    return ((int) word << 24) >> 24;
}

int main(){
    unsigned int word= 0x000000C9;
    printf("func1 result: %#010x\n", func1(word)); // Prints 0x000000c9
    printf("func2 result: %#010x\n", func2(word)); // Prints 0xffffffc9
}
