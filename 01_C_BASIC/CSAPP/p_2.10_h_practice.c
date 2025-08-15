#include <stdio.h>
#include <stdlib.h>

void inplace_swap( int *x , int *y){
    *y = *x ^ *y; // x = a y = a ^ b
    *x = *x ^ *y; // x = a ^ (a ^ b) = (a ^ a) ^ b  = b , y = a ^ b
    *y = *x ^ *y; // x = b y = b ^ (a^b)  = a  
}


void reverse_arr(int a[] , int cnt){
    int first , last ;
    for ( first = 0 , last = cnt - 1; first < last ; first ++ , last --)
        inplace_swap(&a[first] , &a[last]);
}

int main(){
    
    int a[5] = {1,2,3,4,5};
    reverse_arr( a , 5);
    for (int i = 0 ; i < 5 ; i++){
        printf("%d " , a[i]);
    }
}