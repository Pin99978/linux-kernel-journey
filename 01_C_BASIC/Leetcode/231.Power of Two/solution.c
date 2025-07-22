#include <stdio.h>
#include <stdbool.h>


bool isPowerOfTwo(int n) {
    if (n == 0 || n < 0){
        return false;
    }

    if (n == 1){
        return true;
    }

    // only shift till 1 , 
    while ( n > 1 ){
        
        if ( ( n & 1 ) == 1){
            return false;
        }
        n >>= 1;

    }
    return true;
}

