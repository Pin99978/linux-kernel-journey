#include <stdio.h>
#include <stdlib.h>

int add(int a , int b){
    int sum = a + b;
    return sum;
}

int subtract(int a , int b){
    int sub = a - b;
    return sub;
}

void calculator(int a, int b, int (*op_ptr)(int , int)){
    int result;
    result = op_ptr(a,b);
    printf("Result: %d\n" , result);
}


int main(){

       
    calculator(10, 5, &add);
    calculator(10, 5, &subtract);
    return 0 ;
}

