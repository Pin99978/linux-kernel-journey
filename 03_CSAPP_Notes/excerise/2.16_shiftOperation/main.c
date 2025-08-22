#include <stdio.h>

void print_byte(unsigned int n){
    for (int i = 7 ; i >= 0 ; i--){
        unsigned int mask = 1 << i;
        if ((n & mask) != 0 ){
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
    unsigned int a = 0xD4;
    unsigned int b = 0x64;
    unsigned int c = 0x72;
    unsigned int d = 0x44;

    print_byte(a);
    print_byte(b);
    print_byte(c);
    print_byte(d);

    printf("====== left shift 2 ======\n");
    print_byte((a << 2) & 0xFF);
    print_byte((b << 2) & 0xFF);
    print_byte((c << 2) & 0xFF);
    print_byte((d << 2) & 0xFF);

    printf("====== Logical right shift 3 ======\n");
    print_byte((a >> 3) & 0xFF);
    print_byte((b >> 3) & 0xFF);
    print_byte((c >> 3) & 0xFF);
    print_byte((d >> 3) & 0xFF);


    return 0;
}

