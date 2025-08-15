#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b)? (a):(b))

int main(){
    int x = 5;
    int y = 10;
    int z = 0;
    z = MAX(x++ , y++);
    printf("x: %d , y: %d , z: %d" , x, y, z); // 6 11 11
}