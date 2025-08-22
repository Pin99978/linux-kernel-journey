/* write a function div16 that returns the value x/16 for integer argument x, your function should not use division , modulus , nultiplication , any conditionals(if or ?:) ,any comparsion operators(e.g <,> or == , or any loops) */

#include <stdio.h>

int div16(int x){
    /* compute bias to be eitehr 0 (x >= 0) or 15 (x < 0) */
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;    
}

