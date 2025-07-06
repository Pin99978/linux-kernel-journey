#include <stdio.h>


int main(){

    unsigned short us = ~0;
    signed short sc = us >> 1;

    printf("unsigned short: %u to %u\n", 0, us);
    printf("signed short: %d to %d\n", -sc - 1, sc);

    unsigned int ui = ~0;
    signed int si = ui >> 1;

    printf("unsigned int : %u to %u\n" , 0, ui);
    printf("signed int : %d to %d\n", -si - 1, si);

    unsigned char uc = ~0;
    signed char sch = uc >> 1;

    printf("unsigned char: %u to %u\n", 0, uc);
    printf("signed char: %d to %d\n", -sch- 1 , sch);


    return 0;
}
