#include <stdio.h>

int lower(int c){
    return (c >='A' &&  c <='Z') ? c +'a'-'A' : c ; 
}

int main(){
    int uppercase = 'C';
    int lowercase = lower(uppercase);

    printf("the original upper is %c (ASCII:%d) , lowercase is %c\n (ASCII:%d)" , uppercase,uppercase,lowercase,lowercase);
}