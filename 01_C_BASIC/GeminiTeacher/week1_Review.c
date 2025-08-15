#include <stdlib.h>
#include <stdio.h>

int main(int argc , char *argv[]){
    
    int max = atoi(argv[1]);
    
    if (argc < 2) {
        printf("Usage ./findmax <num1> <num2> .....<numn>");}
    
    for (int i = 2 ; i < argc ; i++){
        int num = atoi(argv[i]);
        if (num >= max){
            max = num;
        }
    }
    printf("The maxinun number is %d\n" , max);
    return 0 ;
}