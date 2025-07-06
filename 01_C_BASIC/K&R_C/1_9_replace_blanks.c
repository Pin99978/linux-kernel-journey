#include <stdio.h>


int main(){

    int c ;
    int is_blank = 0 ;
    
    while (( c = getchar() ) != EOF)
        if ( c == ' '){
	    if (!is_blank) {
	        putchar(c);
                is_blank = 1;	
	    }
	} else{
          putchar(c);
          is_blank = 0;
        }

    return 0;
}
