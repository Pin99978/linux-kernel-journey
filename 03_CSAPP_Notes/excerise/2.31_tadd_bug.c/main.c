#include <stdio.h>

/* this is the bug code can't detect the overflow problem*/
/* explain the reason in README */

int tadd_ok(int x , int y){
    int sum = x + y;
    return (sum - x == y) && (sum - y) == x;
}