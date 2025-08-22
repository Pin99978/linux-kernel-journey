#include <stdio.h>

#include <string.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start , size_t len){
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void print_binary(unsigned int n){
    // A 32-bit integer has bits from position 31
    // down to 0, we loop backward to print the bits in the correct order

    for (int i = 31 ; i >= 0 ; i--){
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

    short x = 12345;
    short mx = -x; 
    show_bytes((byte_pointer) &x ,sizeof(short));
    show_bytes((byte_pointer) &mx , sizeof(short));

    // result : 6d 6e 6f 70 71 72
}