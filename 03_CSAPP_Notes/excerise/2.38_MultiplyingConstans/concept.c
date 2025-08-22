#include <stdio.h>
#include <time.h>

int main(){

    int iterations = 200000000;
    int x = 100;
    int result;

    clock_t start = clock();

    for (int i = 0 ; i < iterations ; i++){
        result = x * 6;
    }

    clock_t end = clock();

    double time_spent = (double)(end-start) / CLOCKS_PER_SEC;
    
    printf("Time for multiplication %f seconds\n" , time_spent);

    start = clock();

    for (int i = 0; i < iterations ; i++){
        result = (x<<2) + (x << 1);
        // x * 6 = x * (4+2) = x *4 + x *2 = (x<<2) + (x<<1)
    }

    end = clock();
    time_spent = (double)(end-start) / CLOCKS_PER_SEC;

    printf("Time for shift/add:      %f seconds\n", time_spent);

    return 0 ;

}