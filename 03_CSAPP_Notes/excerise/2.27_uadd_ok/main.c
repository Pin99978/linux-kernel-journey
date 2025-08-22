#include <stdio.h>

int uadd_ok(unsigned x , unsigned y){

    unsigned sum = x + y;
    return sum >= x;
}