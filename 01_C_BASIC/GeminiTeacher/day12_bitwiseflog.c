#include <stdio.h>
#include <stdlib.h>

#define IS_POSISONED (1 << 0) // bit 0 , value 1
#define IS_BURNING   (1 << 1) // bit 1 , value 2
#define HAS_SHIELD   (1 << 2) // bit 2 , value 4
int main(){

    unsigned char status = 0;
    status |= IS_BURNING;
    (status & IS_BURNING) ? printf("IS_BURNING\n") : printf("Not BURNING\n");
    status |= HAS_SHIELD;
    status ^= IS_BURNING;
    ( ((status & IS_BURNING) ==0) && ((status & HAS_SHIELD) != 0 ) )?  printf("IS_BURNING & HAS_SHIELD\n") : printf("Not IS_BURNING & HAS_SHIELD\n") ;

    return 0 ;
}