#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start , size_t len){
    int i;
    for (i = 0 ; i < len ; i++){
        printf("%.1x",start[i]);
    }
    printf("\n");
    
    
}

void show_int(int x){
    show_bytes((byte_pointer) &x , sizeof(int));
}


int main(){
    int x = 0x12345678; 
    byte_pointer ap = (byte_pointer) &x;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);

    return 0;
}