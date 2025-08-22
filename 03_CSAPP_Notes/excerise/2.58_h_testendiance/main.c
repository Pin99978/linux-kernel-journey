#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian(){
    int x = 0xff;
    byte_pointer first_byte = (byte_pointer) &x;
    int mask = 0xFF;
    return  first_byte[0] == 0xff ? 1 : 0 ;
}

int main(){
    
    printf( "%d\n" ,is_little_endian());
}

