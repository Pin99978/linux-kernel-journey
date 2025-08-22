#include <stdio.h>

void show_bytes(unsigned int n){
    for (int i = 7 ; i >= 0 ; i--){
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

    unsigned char a = 0b01001110; // 78
    unsigned char b = 0b11100001; // 225

    show_bytes(~a);
    show_bytes(~b);
    show_bytes(a & b);
    show_bytes(a | b);
    show_bytes(a ^ b);

    return 0;
}