// two instrciont bis(bit set) and bic(bit clear) . 
// Both instructions take a data word x , and a mask word m -> generate a result z consisting of the bits of x modified according to the bits of m 



#include <stdio.h>
#include <string.h>

int bis(int x, int m){
// the modification involves setting z to 1 at each bit position where m is 1
    int z = x | m;
    return z;
}
int bic(int x, int m){
// the modification involves setting z to 0 at each bit position where m is 1
    int z = x & ~m;  
}

int bool_or(int x , int y){
    
    return bis(x ,y);
}


int bool_xor(int x , int y){
    return bic(bis(x,y), bis(y,x)); 
}