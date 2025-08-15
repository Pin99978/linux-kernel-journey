#include <stdio.h>
#include <stdlib.h>

int (*fp)(int a , int b);
int add(int a , int b){
        return a + b;
    }

int main(){

    fp = &add; // 對函式取址的 '&' 是可選的 ，寫fp = &add; 也可以
    int result = fp(10 , 5);
    printf("result: %d\n" , result);

    return 0;
}
