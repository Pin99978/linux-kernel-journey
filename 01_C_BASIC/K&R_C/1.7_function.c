#include <stdio.h>


int power(int base , int n){

    int i , ori;
    ori =  1; 
    for ( i = 0 ; i < n ; ++i){
        ori = ori * base;
    }
    return ori;

}

int main(){
    int i ;
    for ( i = 0 ; i < 10 ;  ++i)
    {
        printf("%d %d \n", i , power(2,i));
    }
    return 0 ;

}


