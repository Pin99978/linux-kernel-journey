#include <stdio.h>



int main(){ 
    int freq[128] = {0}; 
    int c ;

    while ( (c = getchar()) != EOF ){
        ++freq[c] ;
    }

    for ( int i = 1 ; i <= 128 ; ++i ){
        if(freq[i]){
            printf("%2d (%c)" , i , i );
            for ( int j = 0 ; j < freq[i] ; ++j)
                putchar('*');
            putchar('\n');
        }
    }
    return 0 ;
}
