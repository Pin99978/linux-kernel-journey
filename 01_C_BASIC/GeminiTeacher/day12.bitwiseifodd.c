#include <stdio.h>
#include <stdlib.h>

int main(){

    int num = 42;

    if ((num & 1) == 1)
        printf("%d is an odd number\n" , num );
    else
        printf("%d is an even number\n" , num );
    return 0 ;

    
}
