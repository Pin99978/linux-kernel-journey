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
    const char *m = "mnopqr";
    // ASCII a = 0x61 -> z= 0x7A
    // s t u v w x y z 
    // 73  74  76  76  77  78  79  7A
    // m n o p q r
    // 6D  6E  6F  70   71  72


    // expect : 72 71 70 6F 6E 6D

    show_bytes((byte_pointer) m , strlen(m));

    // result : 6d 6e 6f 70 71 72
}