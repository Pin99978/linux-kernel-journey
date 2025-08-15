#include <stdio.h>

long mult2(long, long);

void multstore(long x , long y , long *dest){
    long t = mult2(x , y);
    *dest = t;
}

long mult2(long a , long b){
    long s = a * b;
    return s;
}