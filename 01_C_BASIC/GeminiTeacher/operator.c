#include <stdio.h>


void check_number(int num) {
    if (num % 2 == 0) 
        printf("the number is even");
    else
        printf("the number is odd");

    if (num > 0 && num <= 50)
        printf("the number is in range");
    else
        printf("not in range");
        
}

int main(void) {

    check_number(37);
    check_number(44);
    check_number(51);
    return 0;
}