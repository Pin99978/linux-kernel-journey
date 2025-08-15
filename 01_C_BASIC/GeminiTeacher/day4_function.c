#include <stdio.h>


void add_five(int *n){
    *n += 5;
}


int main(void){
    int x = 10;
    printf("In main , x is initially : %d\n" , x); 
    printf("Calling add_five");
    add_five(&x);
    printf("In main, x is now: %d\n", x);  // 10

    return 0;
}