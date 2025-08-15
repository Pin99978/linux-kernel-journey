#include <stdio.h>

int main(){

    int num = 42;
    int *p_num = NULL;

    p_num = &num;

    printf("Value of the original variable 'num': %d\n", num);
    printf("Memory address of 'num' using '&num': %p\n", (void *)&num);
    printf("Value of the pointer 'p_num' itself (it holds an address): %p\n", (void *)p_num);
    printf("Value at the address the pointer points to, using '*p_num': %d\n", *p_num);    

    // --- Now, let's modify the original variable THROUGH the pointer ---
    printf("\n--- Modifying num using the pointer ---\n");
    *p_num = 100; // Go to the address in p_num and store the value 100 there.

    printf("The value of the original variable 'num' is now: %d\n", num); 


    return 0;

}