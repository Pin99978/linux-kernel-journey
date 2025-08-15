#include <stdio.h>
void function_a(){
    int a = 50;
    printf("function_a: entered\n");
    function_b();
    printf("function_a: existed\n");
}

void function_b(){
    int b = 0;
    printf("function_b: entered\n");
    printf("function_b: existed\n");
}



int main(void){
    int i_main = 100;
    printf("main enter\n");
    function_a();
    printf("main existing\n");
    return 0;
}
